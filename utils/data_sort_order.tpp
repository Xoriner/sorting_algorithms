#include "data_sort_order.h"

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
// ======= SORTOWANIE % TABLICY =======
template<typename T>
void sort_prefix(T* arr, int size, double fraction) {
    int part = static_cast<int>(size * fraction);
    if (part > 1) {
        quick_sort_middle_pivot(arr, 0, part - 1);
    }
}

// ======= SORTOWANIE ODWROTNE =======
template<typename T>
void reverse_sort(T* arr, int size) {
    if (size > 1) {
        quick_sort_middle_pivot(arr, 0, size - 1);
        // ręczne odwracanie
        for (int i = 0; i < size / 2; ++i) {
            T tmp = arr[i];
            arr[i] = arr[size - 1 - i];
            arr[size - 1 - i] = tmp;
        }
    }
}


template<typename T>
void fill_data(T* arr, int size, DataOrder order) {
    fill_random<T>(arr, size);

    switch (order) {
        case DataOrder::Sorted:
            quick_sort_middle_pivot(arr, 0, size - 1);
        break;
        case DataOrder::Reversed:
            reverse_sort(arr, size);
        break;
        case DataOrder::Partial33:
            sort_prefix(arr, size, 0.33);
        break;
        case DataOrder::Partial66:
            sort_prefix(arr, size, 0.66);
        break;
        case DataOrder::Random:
            default:
                break;
    }
}

template<typename T>
T* read_file(const std::string& filename, int& sizeOut) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error: Cannot open file.\n";
        sizeOut = 0;
        return nullptr;
    }

    int count = 0;
    T temp;
    while (inFile >> temp)
        ++count;

    if (count == 0) {
        std::cerr << "Error: File is empty or invalid.\n";
        sizeOut = 0;
        return nullptr;
    }

    inFile.clear();
    inFile.seekg(0);

    T* arr = new T[count];
    for (int i = 0; i < count; ++i)
        inFile >> arr[i];

    sizeOut = count;
    return arr;
}