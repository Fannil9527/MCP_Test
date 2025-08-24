#include <stdio.h>
#include "quicksort.h"

/**
 * @brief 交换两个整数的值
 */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief 分区函数，用于快速排序
 * 选择最后一个元素作为基准，将数组分为两部分
 */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // 选择最后一个元素作为基准
    int i = (low - 1);      // 较小元素的索引

    for (int j = low; j <= high - 1; j++) {
        // 如果当前元素小于或等于基准
        if (arr[j] <= pivot) {
            i++;            // 增加较小元素的索引
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/**
 * @brief 快速排序主函数
 */
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        // pi 是分区索引，arr[pi] 现在在正确的位置
        int pi = partition(arr, low, high);

        // 分别对分区前后的元素进行排序
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

/**
 * @brief 打印数组内容
 */
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}