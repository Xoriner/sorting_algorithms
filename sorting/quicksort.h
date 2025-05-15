#ifndef QUICKSORT_H
#define QUICKSORT_H

template<typename T>
void quick_sort_recursion(T* arr, int low, int high); // deklaracje
void quick_sort_pivot_left(T* arr, int low, int high);
void quick_sort_pivot_right(T* arr, int low, int high);
void quick_sort_pivot_middle(T* arr, int low, int high);
void quick_sort_pivot_random(T* arr, int low, int high); // deklaracja

#include "quicksort.tpp" //implementacja

#endif // QUICKSORT_H