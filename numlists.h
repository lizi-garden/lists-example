#ifndef _NUMLISTS_H
#define _NUMLISTS_H

#include <stdlib.h>

typedef struct numlists
{
    int num;
    int data;
    struct numlists *next;
} NumLists;

/* 初始化函数 */
NumLists* initNumLists(const int data);

/* 添加函数 */
void addNumLists(NumLists *head, const int data);

/* 插入函数 */
void insertNumLists(NumLists *head, const int data, const int pos);

/* 迭代函数 */
int pairNumLists(NumLists *head);

/* 删除函数 */
void deleteNumLists(NumLists *head);

/* 释放函数 */
void freeNumLists(NumLists *head);

#endif
