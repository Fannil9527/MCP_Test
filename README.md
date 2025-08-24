# 快速排序算法实现

这是一个使用C语言实现的快速排序算法项目，包含完整的接口函数和自动化测试。

## 项目结构

```
.
├── quicksort.h      # 头文件，包含函数声明和接口定义
├── quicksort.c      # 快速排序算法的具体实现
├── test_quicksort.c # 自动化测试用例
├── build.bat        # Windows构建脚本
└── README.md        # 项目说明文档
```

## 功能特性

### 接口函数

- `void quick_sort(int arr[], int low, int high)` - 快速排序主函数
- `void print_array(int arr[], int size)` - 打印数组内容
- `void swap(int* a, int* b)` - 交换两个整数的值
- `int partition(int arr[], int low, int high)` - 分区函数

### 算法特点

- **时间复杂度**: 
  - 平均情况: O(n log n)
  - 最坏情况: O(n²) - 当数组已排序时
  - 最好情况: O(n log n)
- **空间复杂度**: O(log n) - 递归调用栈
- **稳定性**: 不稳定排序算法
- **原地排序**: 是

### 测试用例

项目包含8个全面的测试用例：

1. **基本数组测试** - 普通无序数组
2. **已排序数组测试** - 验证算法对已排序数组的处理
3. **逆序数组测试** - 完全逆序的数组
4. **重复元素测试** - 包含重复元素的数组
5. **单个元素测试** - 只有一个元素的数组
6. **空数组测试** - 边界情况测试
7. **性能测试** - 10000个随机元素的性能测试
8. **最坏情况测试** - 已排序大数组的性能测试

## 构建和运行

### Windows环境

1. 确保已安装GCC编译器（如MinGW）
2. 双击运行 `build.bat` 文件
3. 脚本会自动编译并运行所有测试

### 手动编译

```bash
# 编译
gcc -c quicksort.c -o quicksort.o
gcc -c test_quicksort.c -o test_quicksort.o
gcc quicksort.o test_quocksort.o -o test_quicksort.exe

# 运行测试
test_quicksort.exe
```

## 使用示例

```c
#include "quicksort.h"

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("排序前: ");
    print_array(arr, size);
    
    quick_sort(arr, 0, size - 1);
    
    printf("排序后: ");
    print_array(arr, size);
    
    return 0;
}
```

## 测试结果

运行测试后将显示：
- 每个测试用例的原始数组和排序后数组
- 排序耗时统计
- 排序正确性验证
- 与期望结果的对比

## 注意事项

- 确保系统中已安装GCC编译器
- 项目针对Windows环境优化，但代码本身是跨平台的
- 测试用例包含性能测试，可能需要几秒钟完成

## 扩展建议

1. 可以添加更多排序算法的实现进行比较
2. 可以增加图形化界面显示排序过程
3. 可以添加更详细的时间复杂度分析
4. 可以支持更多数据类型（如浮点数、字符串等）