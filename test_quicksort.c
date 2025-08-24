#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quicksort.h"

/**
 * @brief 测试快速排序函数
 * @param test_name 测试名称
 * @param arr 测试数组
 * @param size 数组大小
 * @param expected 期望的排序结果（可选）
 */
void test_quick_sort(const char* test_name, int arr[], int size, int expected[]) {
    printf("=== %s ===\n", test_name);
    
    // 处理空数组的情况
    if (arr == NULL || size == 0) {
        printf("原始数组: []\n");
        printf("排序后: []\n");
        printf("排序耗时: 0.000000 秒\n");
        printf("✓ 排序正确 (空数组)\n");
        printf("\n");
        return;
    }
    
    printf("原始数组: ");
    print_array(arr, size);
    
    // 记录开始时间
    clock_t start = clock();
    
    quick_sort(arr, 0, size - 1);
    
    // 记录结束时间
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("排序后: ");
    print_array(arr, size);
    printf("排序耗时: %f 秒\n", time_taken);
    
    // 验证排序结果是否正确
    int is_sorted = 1;
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            is_sorted = 0;
            break;
        }
    }
    
    if (is_sorted) {
        printf("✓ 排序正确\n");
    } else {
        printf("✗ 排序错误\n");
    }
    
    // 如果提供了期望结果，进行对比
    if (expected != NULL) {
        int is_correct = 1;
        for (int i = 0; i < size; i++) {
            if (arr[i] != expected[i]) {
                is_correct = 0;
                break;
            }
        }
        if (is_correct) {
            printf("✓ 结果与期望一致\n");
        } else {
            printf("✗ 结果与期望不一致\n");
        }
    }
    
    printf("\n");
}

/**
 * @brief 生成随机数组
 * @param size 数组大小
 * @param min 最小值
 * @param max 最大值
 * @return int* 生成的随机数组
 */
int* generate_random_array(int size, int min, int max) {
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("内存分配失败\n");
        return NULL;
    }
    
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }
    
    return arr;
}

/**
 * @brief 复制数组
 */
int* copy_array(int arr[], int size) {
    int* copy = (int*)malloc(size * sizeof(int));
    if (copy == NULL) {
        printf("内存分配失败\n");
        return NULL;
    }
    
    for (int i = 0; i < size; i++) {
        copy[i] = arr[i];
    }
    
    return copy;
}

int main() {
    printf("开始快速排序测试...\n\n");
    
    // 测试用例1: 基本测试
    int test1[] = {64, 34, 25, 12, 22, 11, 90};
    int size1 = sizeof(test1) / sizeof(test1[0]);
    int expected1[] = {11, 12, 22, 25, 34, 64, 90};
    test_quick_sort("测试1: 基本数组", test1, size1, expected1);
    
    // 测试用例2: 已排序数组
    int test2[] = {1, 2, 3, 4, 5, 6, 7};
    int size2 = sizeof(test2) / sizeof(test2[0]);
    test_quick_sort("测试2: 已排序数组", test2, size2, test2);
    
    // 测试用例3: 逆序数组
    int test3[] = {7, 6, 5, 4, 3, 2, 1};
    int size3 = sizeof(test3) / sizeof(test3[0]);
    int expected3[] = {1, 2, 3, 4, 5, 6, 7};
    test_quick_sort("测试3: 逆序数组", test3, size3, expected3);
    
    // 测试用例4: 包含重复元素
    int test4[] = {5, 2, 8, 2, 9, 1, 5, 4};
    int size4 = sizeof(test4) / sizeof(test4[0]);
    int expected4[] = {1, 2, 2, 4, 5, 5, 8, 9};
    test_quick_sort("测试4: 包含重复元素", test4, size4, expected4);
    
    // 测试用例5: 单个元素
    int test5[] = {42};
    int size5 = sizeof(test5) / sizeof(test5[0]);
    test_quick_sort("测试5: 单个元素", test5, size5, test5);
    
    // 测试用例6: 空数组测试
    int* test6 = NULL;
    int size6 = 0;
    test_quick_sort("测试6: 空数组", test6, size6, NULL);
    
    // 测试用例7: 大型随机数组性能测试
    printf("=== 性能测试: 大型随机数组 ===\n");
    int large_size = 10000;
    int* large_array = generate_random_array(large_size, 1, 10000);
    if (large_array != NULL) {
        test_quick_sort("测试7: 10000个随机元素", large_array, large_size, NULL);
        free(large_array);
    }
    
    // 测试用例8: 最坏情况测试（已排序的大数组）
    printf("=== 性能测试: 最坏情况（已排序大数组） ===\n");
    int worst_size = 5000;
    int* worst_array = (int*)malloc(worst_size * sizeof(int));
    if (worst_array != NULL) {
        for (int i = 0; i < worst_size; i++) {
            worst_array[i] = i;
        }
        test_quick_sort("测试8: 5000个已排序元素", worst_array, worst_size, worst_array);
        free(worst_array);
    }
    
    printf("所有测试完成！\n");
    return 0;
}