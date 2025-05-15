#include "benchmark.h"

template<typename T>
void benchmark_algorithms(int size, SortType chosen_sort, DataOrder dataOrder) {
    std::cout << "\n--- Test (" << typeid(T).name() << "), n = " << size << ", ";

    switch (dataOrder) {
        case DataOrder::Sorted: std::cout << "Sorted"; break;
        case DataOrder::Reversed: std::cout << "Reversed"; break;
        case DataOrder::Partial33: std::cout << "33% Sorted"; break;
        case DataOrder::Partial66: std::cout << "66% Sorted"; break;
        case DataOrder::Random: std::cout << "Random"; break;
    }

    std::cout << " ---\n";

    T* arr = new T[size];
    fill_data<T>(arr, size, dataOrder);
    if (size == 10) print_array(arr, size);
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();

    switch (chosen_sort) {
        case SortType::Insertion:
            std::cout << "Insertion sort \n";
            start = std::chrono::high_resolution_clock::now();
            insertion_sort(arr, size);
            end = std::chrono::high_resolution_clock::now();
            break;
        case SortType::QuickMiddle:
            std::cout << "Quick middle pivot sort \n";
            start = std::chrono::high_resolution_clock::now();
            quick_sort_middle_pivot(arr, 0, size - 1);
            end = std::chrono::high_resolution_clock::now();
            break;
        case SortType::QuickLeft:
            std::cout << "Quick left pivot sort \n";
            start = std::chrono::high_resolution_clock::now();
            quick_sort_left_pivot(arr, 0, size - 1);
            end = std::chrono::high_resolution_clock::now();
            break;
        case SortType::QuickRight:
            std::cout << "Quick right pivot sort \n";
            start = std::chrono::high_resolution_clock::now();
            quick_sort_right_pivot(arr, 0, size - 1);
            end = std::chrono::high_resolution_clock::now();
            break;
        case SortType::Heap:
            std::cout << "Heap sort \n";
            start = std::chrono::high_resolution_clock::now();
            heap_sort(arr, size);
            end = std::chrono::high_resolution_clock::now();
            break;
        case SortType::Shell:
            std::cout << "Shell sort \n";
            start = std::chrono::high_resolution_clock::now();
            shell_sort(arr, size);
            end = std::chrono::high_resolution_clock::now();
            break;
        case SortType::ShellCiura:
            std::cout << "Shell ciura sort \n";
            start = std::chrono::high_resolution_clock::now();
            shell_ciura_sort(arr, size);
            end = std::chrono::high_resolution_clock::now();
            break;
    }

    std::chrono::duration<double, std::milli> elapsed = end - start;

    std::cout << "Time: " << elapsed.count() << " ms | Posortowana? "
              << (is_sorted<T>(arr, size) ? "TAK" : "NIE") << "\n";
    if (size < 30) print_array(arr, size);

    delete[] arr;
}