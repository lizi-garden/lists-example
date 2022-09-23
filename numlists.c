#include "numlists.h"
#include <stdio.h>
#include <stdlib.h>

/* 初始化函数 */
NumLists* Init(const int data)
{
    NumLists *lists = NULL;
    lists = (NumLists*)malloc(sizeof(NumLists));

    lists->num = 1;
    lists->next = NULL;
    lists->data = data;

    return lists;
}

/* 添加函数 */
bool Add(NumLists *lists, int data)
{
    NumLists *new = NULL;
    NumLists *plist = lists;
    int count = 2;

    /* 查找到链表最后一位 */
    while(NULL != plist->next)
    {
        plist = plist->next;
        count++;
    }

    new = (NumLists*)malloc(sizeof(NumLists));

    plist->next = new;
    new->num = count;
    new->data = data;   /* 添加数据 */
    new->next = NULL;   /* 以NULL作为链表结尾 */

    if(NULL == plist)
        return false;
    else
    {
        return true;
    }
}

/* 插入函数 */
bool Insert(NumLists *lists, const int pos, const int data)
{
    NumLists *plist = lists;
    NumLists *new = NULL;

    for(int i = 1; i < pos - 1; i++)
    {
        if(plist == NULL)
        {
            return false;
        }
        else
        {
            plist = plist->next;
        }
    }

    new = (NumLists*)malloc(sizeof(NumLists));

    /* 进行插入操作 */
    new->next = plist->next;
    plist->next = new;

    new->num = pos;
    new->data = data;

    /* 重新对后面的数进行编号 */
    plist = new->next;
    while(NULL != plist)
    {
        plist->num++;
        plist = plist->next;
    }

    return true;
}

/* 显示函数 */
void Show(NumLists *lists)
{
    NumLists *plist = lists;

    while(NULL != plist)
    {
        printf("NO:%d\t%d\n", plist->num, plist->data);
        plist = plist->next;
    }
}

bool Check(NumLists *lists)
{
    ;
}

/* 迭代函数 */
int Pair(NumLists *lists)
{
    static int n = 1;
    NumLists *plist = lists;

    if(NULL == plist->next)
    {
        return plist->data;
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            plist = plist->next;
        }
        n++;
        return plist->data;
    }
}

/* 删除函数 */
bool Delete(NumLists *head, const int pos)
{
    ;
}

/* 释放函数 */
void Free(NumLists *lists)
{
    NumLists *plist = lists;

    while(NULL != plist->next)
    {
        NumLists *temp = plist;
        plist = plist->next;
        free(temp);
    }
}
