@echo off
echo 正在编译快速排序项目...

REM 编译快速排序实现文件
gcc -c quicksort.c -o quicksort.o

REM 编译测试文件
gcc -c test_quicksort.c -o test_quicksort.o

REM 链接生成可执行文件
gcc quicksort.o test_quicksort.o -o test_quicksort.exe

REM 检查是否编译成功
if exist test_quicksort.exe (
    echo 编译成功！
    echo.
    echo 运行测试...
    echo.
    test_quicksort.exe
) else (
    echo 编译失败！
    exit /b 1
)

echo.
echo 测试完成！
pause