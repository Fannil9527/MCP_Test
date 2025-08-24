#ifndef QUICKSORT_H
#define QUICKSORT_H

/**
 * @brief 快速排序函数接口
 * 
 * @param arr 待排序的数组
 * @param low 起始索引
 * @param high 结束索引
 */
void quick_sort(int arr[], int low, int high);

/**
 * @brief 打印数组内容
 * 
 * @param arr 要打印的数组
 * @param size 数组大小
 */
void print_array(int arr[], int size);

/**
 * @brief 交换两个整数的值
 * 
 * @param a 第一个整数的指针
 * @param b 第二个整数的指针
 */
void swap(int* a, int* b);

/**
 * @brief 分区函数，用于快速排序
 * 
 * @param arr 待分区的数组
 * @param low 起始索引
 * @param high 结束索引
 * @return int 分区点的索引
 */
int partition(int arr[], int low, int high);

#endif // QUICKSORT_H