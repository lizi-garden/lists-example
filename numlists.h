#ifndef _NUMLISTS_H
#define _NUMLISTS_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct numlists
{
    int num;
    int data;
    struct numlists *next;
} NumLists;

/* 初始化函数 */
NumLists* Init(const int data);

/* 添加函数 */
bool Add(NumLists *lists, const int data);

/* 插入函数 */
bool Insert(NumLists *lists, const int pos, const int data);

/* 显示函数 */
void Show(NumLists *lists);

/* 检查函数 */
bool Check(NumLists *lists);

/* 迭代函数 */
int Pair(NumLists *lists);

/* 删除函数 基于位置 */
bool Delete_pos(NumLists *lists, const int pos);

/* 删除函数 基于内容 */
bool Delete_data(NumLists *lists, const int data);

/* 筛选函数 基于内容保留 */
bool Filter_data(NumLists *lists, const int min, const int max);

/* 筛选函数 基于内容显示 */
bool Filter_print(NumLists *lists, const int min, const int max);

/* 释放函数 */
void Free(NumLists *lists);

#endif
