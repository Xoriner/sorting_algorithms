#include "heapsort.h"
// ======== HEAP SORT ========

template<typename T>
void heapify(T* arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1; // lewe dziecko
    int r = 2 * i + 2; // prawe dziecko

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

template<typename T>
void heap_sort(T* arr, int n) {
    // Budowa kopca (heapify)
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);

    // Sortowanie
    for (int i = n - 1; i > 0; --i) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}