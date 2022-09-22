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
bool Add(NumLists *head, const int data);

/* 插入函数 */
bool Insert(NumLists *lists, const int pos, const int data);

/* 显示函数 */
void Show(NumLists *lists);

/* 检查函数 */
bool Check(NumLists *lists);

/* 迭代函数 */
int Pair(NumLists *head);

/* 删除函数 */
bool Delete(NumLists *head, const int pos);

/* 释放函数 */
void Free(NumLists *head);

#endif
