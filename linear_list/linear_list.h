#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_CAPACITY 100 // 设置初始容量为100

typedef struct
{
    int length;
    int capacity;
    int* elem;
} linear_list;

/**
 * @brief 初始化线性表L，将其长度设置为0，容量设置为初始容量，元素全部初始化为0
 * 
 * @param L 线性表指针
 * @return linear_list* 初始化完成的线性表指针
 */
linear_list* InitLinearList(linear_list* L);

/**
 * @brief 输出线性表L的所有元素
 * 
 * @param L 线性表指针
 */
void Display(linear_list* L);

/**
 * @brief 为线性表L的元素重新分配内存空间
 * 
 * @param L 线性表指针
 * @return int* 分配好空间并初始化的线性表元素指针
 */
int* AllocListElem(linear_list* L);

/**
 * @brief 当线性表L的长度大于3/4容量或者小于1/4容量时重新分配线性表的容量
 * 
 * @param L 线性表指针 
 * @return linear_list* 重新分配容量的线性表指针
 */
linear_list* Resize(linear_list* L);

/**
 * @brief 在线性表L的P位置插入元素E
 * 
 * @param E 需要插入的元素E
 * @param P 元素插入的位置P
 * @param L 将要被插入元素E的线性表L
 * @return int 被插入的元素
 */
int Insert(int E, int P, linear_list* L);

/**
 * @brief 删除线性表中范围为(lo,hi]的元素
 * 
 * @param lo 线性表中的较低元素位置
 * @param hi 线性表中的较高元素位置
 * @param L 将要被删除元素的线性表的指针
 * @return int 被删除的元素值
 */
int Remove(int lo, int hi, linear_list* L);

/**
 * @brief 二分查找[lo,hi)区间内的元素E，如果没有找到则返回最初区间的最后一个值。使用前需要将线性表升序排列
 * 
 * @param E 需要查找的元素
 * @param lo 线性表中较低元素的位置
 * @param hi 线性表中较高元素的位置
 * @param L 需要被查找的线性表指针L
 * @return int 需要查找元素的位置
 */
int BinSearch(int E, int lo, int hi, linear_list* L);

/**
 * @brief 比较a，b两个值的大小，并根据大于、等于、小于分别返回大于0，等于0，小于0
 * 本函数用于qsort()函数的使用
 * 
 * @param a 比较元素a
 * @param b 比较元素b
 * @return int 比较结果
 */
int Cmp(const void* a,const void *b);