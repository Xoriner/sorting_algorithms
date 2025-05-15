#include "shellsort.h"

template<typename T>
void shell_sort(T* arr, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            T temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

template<typename T>
void shell_ciura_sort(T* arr, int n) {
    // Ulepszona praktyczna sekwencja (zbliżona do Ciura)
    int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};
    int num_gaps = sizeof(gaps) / sizeof(gaps[0]);

    for (int g = 0; g < num_gaps; ++g) {
        int gap = gaps[g];
        if (gap >= n) continue; // pomijamy zbyt duże odstępy

        for (int i = gap; i < n; ++i) {
            T temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}