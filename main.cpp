#include <iostream>
#include <cstdlib>
#include <ctime>

#include "utils/benchmark.h"

void test_everything() {
    int sizes[] = {10, 10000, 20000, 40000, 80000, 100000, 150000, 200000};
    SortType algorithms[] = {SortType::Insertion,
        SortType::QuickMiddle, SortType::QuickLeft, SortType::QuickRight, SortType::QuickRandom,
        SortType::Heap,
        SortType::Shell, SortType::ShellCiura};
    DataOrder orders[] = {DataOrder::Random, DataOrder::Sorted, DataOrder::Reversed, DataOrder::Partial33, DataOrder::Partial66};


    for (auto algo : algorithms) {
        for (auto order : orders) {
            for (int size : sizes) {
                benchmark_algorithms<int>(size, algo, order);
                benchmark_algorithms<float>(size, algo, order);
            }
        }
    }
}

// ======== MAIN ========
int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    while (true) {
        std::cout << "\n==== SORT BENCHMARK MENU ====\n";
        std::cout << "\n Choose testing mode \n";
        std::cout << "1. automatic (test every case for every algorithm)\n";
        std::cout << "2. manual (choose parameters)\n";

        std::cout << "Choose testing mode (1-2, 0 to exit):";
        int testChoice;
        std::cin >> testChoice;
        if (testChoice == 1) {
            test_everything();
            break;
        }

        std::cout << "1. int\n";
        std::cout << "2. float\n";
        std::cout << "Choose data type (1-2, 0 to exit): ";
        int typeChoice;
        std::cin >> typeChoice;
        if (typeChoice == 0) break;

        std::cout << "\nAvailable sorting algorithms:\n";
        std::cout << "1. Insertion Sort\n";
        std::cout << "2. Quick Sort (Middle Pivot)\n";
        std::cout << "3. Quick Sort (Left Pivot)\n";
        std::cout << "4. Quick Sort (Right Pivot)\n";
        std::cout << "5. Quick Sort (Random Pivot)\n";
        std::cout << "6. Heap Sort\n";
        std::cout << "7. Shell Sort (Classic)\n";
        std::cout << "8. Shell Sort (Ciura sequence)\n";
        std::cout << "Choose sorting algorithm (1-7): ";
        int algoChoice;
        std::cin >> algoChoice;

        SortType algorithm;
        switch (algoChoice) {
            case 1: algorithm = SortType::Insertion; break;
            case 2: algorithm = SortType::QuickMiddle; break;
            case 3: algorithm = SortType::QuickLeft; break;
            case 4: algorithm = SortType::QuickRight; break;
            case 5: algorithm = SortType::QuickRandom; break;
            case 6: algorithm = SortType::Heap; break;
            case 7: algorithm = SortType::Shell; break;
            case 8: algorithm = SortType::ShellCiura; break;
            default:
                std::cout << "Invalid sorting algorithm.\n";
                continue;
        }

        std::cout << "\nInitial data ordering:\n";
        std::cout << "1. Random\n";
        std::cout << "2. Sorted\n";
        std::cout << "3. Reversed\n";
        std::cout << "4. 33% Sorted\n";
        std::cout << "5. 66% Sorted\n";
        std::cout << "Choose data order (1-5): ";
        int orderChoice;
        std::cin >> orderChoice;

        DataOrder order;
        switch (orderChoice) {
            case 1: order = DataOrder::Random; break;
            case 2: order = DataOrder::Sorted; break;
            case 3: order = DataOrder::Reversed; break;
            case 4: order = DataOrder::Partial33; break;
            case 5: order = DataOrder::Partial66; break;
            default:
                std::cout << "Invalid data order.\n";
                continue;
        }

        std::cout << "\nEnter array size: ";
        int size;
        std::cin >> size;
        if (size <= 0) {
            std::cout << "Invalid size.\n";
            continue;
        }

        std::cout << "\n--- Running Benchmark ---\n";

        if (typeChoice == 1) {
            benchmark_algorithms<int>(size, algorithm, order);
        } else if (typeChoice == 2) {
            benchmark_algorithms<float>(size, algorithm, order);
        } else {
            std::cout << "Invalid type.\n";
            continue;
        }

        std::cout << "\nRun another test? (y/n): ";
        char again;
        std::cin >> again;
        if (again != 'y' && again != 'Y') break;
    }

    std::cout << "Exiting program.\n";
    return 0;
}
