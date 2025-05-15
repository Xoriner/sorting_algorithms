#include "quicksort.h"
#include <stack>
#include <cstdlib> // rand()

// ======== QUICKSORT IMPLEMENTACJA ========
template<typename T>
void quick_sort_recursion(T* arr, int low, int high) {
    if (low < high) {
        T pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (arr[j] < pivot) {
                ++i;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        int pi = i + 1;
        quick_sort_recursion(arr, low, pi - 1);
        quick_sort_recursion(arr, pi + 1, high);
    }
}

template<typename T>
void quick_sort_left_pivot(T* arr, int low, int high) {
    std::stack<std::pair<int, int>> stack;
    stack.push({low, high});

    while (!stack.empty()) {
        auto [l, h] = stack.top();
        stack.pop();
        if (l >= h) continue;

        T pivot = arr[l];  // Skrajny lewy
        int i = l;

        for (int j = l + 1; j <= h; ++j) {
            if (arr[j] < pivot) {
                ++i;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[l], arr[i]);

        stack.push({l, i - 1});
        stack.push({i + 1, h});
    }
}


template<typename T>
void quick_sort_right_pivot(T* arr, int low, int high) {
    std::stack<std::pair<int, int>> stack;
    stack.push({low, high});

    while (!stack.empty()) {
        auto [l, h] = stack.top();
        stack.pop();
        if (l >= h) continue;

        T pivot = arr[h];  // Skrajny prawy
        int i = l - 1;

        for (int j = l; j < h; ++j) {
            if (arr[j] < pivot) {
                ++i;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[h]);
        int pi = i + 1;

        stack.push({l, pi - 1});
        stack.push({pi + 1, h});
    }
}

template<typename T>
void quick_sort_middle_pivot(T* arr, int low, int high) {
    std::stack<std::pair<int, int>> stack;
    stack.push({low, high});

    while (!stack.empty()) {
        auto [l, h] = stack.top();
        stack.pop();
        if (l >= h) continue;

        int mid = l + (h - l) / 2;
        std::swap(arr[mid], arr[h]);  // Przenieś środkowy na koniec
        T pivot = arr[h];
        int i = l - 1;

        for (int j = l; j < h; ++j) {
            if (arr[j] < pivot) {
                ++i;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[h]);
        int pi = i + 1;

        stack.push({l, pi - 1});
        stack.push({pi + 1, h});
    }
}

template<typename T>
void quick_sort_random_pivot(T* arr, int low, int high) {
    std::stack<std::pair<int, int>> stack;
    stack.push({low, high});

    while (!stack.empty()) {
        auto [l, h] = stack.top();
        stack.pop();
        if (l >= h) continue;

        int rand_index = l + rand() % (h - l + 1);
        std::swap(arr[rand_index], arr[h]);  // Przenieś losowy na koniec
        T pivot = arr[h];
        int i = l - 1;

        for (int j = l; j < h; ++j) {
            if (arr[j] < pivot) {
                ++i;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[h]);
        int pi = i + 1;

        stack.push({l, pi - 1});
        stack.push({pi + 1, h});
    }
}

