#include <numa.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    // 初始化NUMA库
    numa_available();
    
    // 指定要分配内存的NUMA节点
    int node = 0; // 假设要分配到NUMA节点0上

    // 在指定的NUMA节点上分配内存
    void *ptr = numa_alloc_onnode(sizeof(int) * 100, node);
    
    if (ptr != NULL) {
        // 使用malloc在已分配的内存上进行子分配
        int *sub_ptr = (int *)ptr; // 假设以整数为单位进行子分配
        // 使用sub_ptr进行内存操作
        *sub_ptr = 1024;
        printf("初始指针的地址: %p\n", (void *)ptr); // 输出指针的地址
        printf("初始指针所指向的内容: %d\n", *((int *)ptr)); // 输出指针所指向的内容
        printf("sub指针的地址: %p\n", (void *)sub_ptr); // 输出指针的地址
        printf("sub指针所指向的内容: %d\n", *sub_ptr); // 输出指针所指向的内容

        // 释放已分配的内存
        numa_free(ptr, sizeof(int) * 100);
    } else {
        printf("内存分配失败。\n");
    }

    return 0;
}
