#include "data_sort_order.h"
#include "../sorting/heapsort.h"

// ======== GENERATOR DANYCH ========
template<>
inline void fill_random<int>(int* arr, int size) {
    for (int i = 0; i < size; ++i)
        arr[i] = rand() % 100000;
}

template<>
inline void fill_random<float>(float* arr, int size) {
    for (int i = 0; i < size; ++i)
        arr[i] = static_cast<float>(rand()) / RAND_MAX * 1000.0f;
}

template<typename T>
void fill_data(T* arr, int size, DataOrder order) {
    fill_random<T>(arr, size);

    switch (order) {
        case DataOrder::Sorted:
            heap_sort(arr, size);
        break;
        /*case DataOrder::Reversed:
            std::sort(arr, arr + size, std::greater<T>());
        break;
        case DataOrder::Partial33:
            std::sort(arr, arr + size * 0.33);
        break;
        case DataOrder::Partial66:
            std::sort(arr, arr + size * 0.66);
        break;*/
        case DataOrder::Random:
            default:
                break;
    }
}