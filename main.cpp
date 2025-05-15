#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cstring>  // dla memcpy

#include "utils/benchmark.h"

// ======== MAIN ========
int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int sizes[] = {10, 10000};
    SortType algorithms[] = {//SortType::Insertion,
                        //SortType::QuickMiddle, SortType::QuickLeft, SortType::QuickRight,
                        //SortType::Heap,
                        SortType::Shell, SortType::ShellCiura};
    DataOrder orders[] = {DataOrder::Random, DataOrder::Sorted, DataOrder::Reversed, DataOrder::Partial33, DataOrder::Partial66};

    for (int size : sizes) {
        for (auto order : orders) {
            for (auto algo : algorithms) {
                benchmark_algorithms<int>(size, algo, order);
                //benchmark_algorithms<float>(size, algo, order);
            }
        }
    }

    return 0;
}
