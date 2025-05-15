#include "print_check_array.h"

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