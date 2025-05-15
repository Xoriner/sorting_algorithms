#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
#include <iomanip>
#include <cstring>  // dla memcpy

#include "sorting/insertionsort.h"
#include "sorting/heapsort.h"
//#include "sorting/shellsort.h"
#include "sorting/quicksort.h"


// ======== WYPISANIE TABLICY ========
template<typename T>
void print_array(const T* arr, int size) {
    for (int i = 0; i < size; ++i)
        std::cout << std::fixed << std::setprecision(2) << arr[i] << " ";
    std::cout << "\n";
}


// ======== SPRAWDZANIE CZY POSORTOWANE ========
template<typename T>
bool is_sorted(T* arr, int size) {
    for (int i = 1; i < size; ++i)
        if (arr[i - 1] > arr[i])
            return false;
    return true;
}


// ======== GENERATOR DANYCH ========
template<typename T>
void fill_random(T* arr, int size);

template<>
void fill_random<int>(int* arr, int size) {
    for (int i = 0; i < size; ++i)
        arr[i] = rand() % 100000;
}

template<>
void fill_random<float>(float* arr, int size) {
    for (int i = 0; i < size; ++i)
        arr[i] = static_cast<float>(rand()) / RAND_MAX * 1000.0f;
}

// ======== FUNKCJA POMIARU CZASU I PORÓWNANIA ALGORYTMÓW ========
template<typename T>
void benchmark_algorithms(int size) {
    std::cout << "\n--- Test (" << typeid(T).name() << "), n = " << size << " ---\n";

    // Tworzymy oryginalną tablicę i wypełniamy losowymi danymi
    T* original = new T[size];
    fill_random<T>(original, size);
    if (size == 10) {
        print_array<T>(original, size);
    }

    // Insertion Sort
    T* arr1 = new T[size];
    std::memcpy(arr1, original, sizeof(T) * size);
    auto start1 = std::chrono::high_resolution_clock::now();
    insertion_sort<T>(arr1, size);
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed1 = end1 - start1;
    std::cout << "Insertion Sort: " << elapsed1.count() << " ms | Posortowana? "
              << (is_sorted<T>(arr1, size) ? "TAK" : "NIE") << "\n";

    //TYMCZASOWE
    if (size == 10) {
        print_array<T>(arr1, size);
    }
    delete[] arr1;

    // Quick Sort
    T* arr2 = new T[size];
    std::memcpy(arr2, original, sizeof(T) * size);
    auto start2 = std::chrono::high_resolution_clock::now();
    quick_sort_middle_pivot<T>(arr2, 0, size - 1);
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed2 = end2 - start2;
    std::cout << "Quick Sort:     " << elapsed2.count() << " ms | Posortowana? "
              << (is_sorted<T>(arr2, size) ? "TAK" : "NIE") << "\n";
    if (size == 10) {
        print_array<T>(arr2, size);
    }
    delete[] arr2;

    // Heap Sort
    T* arr3 = new T[size];
    std::memcpy(arr3, original, sizeof(T) * size);
    auto start3 = std::chrono::high_resolution_clock::now();
    heap_sort<T>(arr3, size);
    auto end3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed3 = end3 - start3;
    std::cout << "Heap sort:     " << elapsed3.count() << " ms | Posortowana? "
              << (is_sorted<T>(arr3, size) ? "TAK" : "NIE") << "\n";
    if (size == 10) {
        print_array<T>(arr3, size);
    }
    delete[] arr3;

    delete[] original;
}

// ======== MAIN ========
int main() {
    // generator
    srand(static_cast<unsigned>(time(nullptr)));

    int sizes[] = {10, 10000, 20000, 40000, 80000, 100000, 150000, 200000};

    for (int size : sizes) {
        benchmark_algorithms<int>(size);
        benchmark_algorithms<float>(size);
    }

    return 0;
}
