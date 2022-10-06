#ifndef _NUMLISTS_H
#define _NUMLISTS_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct numlists
{
    int data;
    struct numlists *next;
} Lists;

/* 初始化函数 */
Lists* Init(const int data);

/* 添加函数 */
bool Add(Lists *lists, const int data);

/* 插入函数 */
bool Insert(Lists *lists, const int pos, const int data);

/* 显示函数 */
void Show(Lists *lists);

/* 迭代函数 */
int Pair(Lists *lists);

/* 删除函数 基于位置 */
bool Delete_pos(Lists *lists, const int pos);

/* 删除函数 基于内容 */
bool Delete_data(Lists *lists, const int data);

/* 筛选函数 基于内容保留 */
Lists* Filter_data(Lists *lists, const int min, const int max);

/* 筛选函数 基于内容显示 */
bool Filter_print(Lists *lists, const int min, const int max);

/* 释放函数 */
void Free(Lists *lists);

#endif
