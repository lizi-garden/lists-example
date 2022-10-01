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

/* 检查链表，并重新编号 */
bool Check(NumLists *lists)
{
    NumLists *plist = lists;
    int num = 1;

    if(NULL == plist)
    {
        printf("Your list is emtry!\n");
    }

    while(NULL != plist)
    {
        plist->num = num;
        num++;
        plist = plist->next;
    }

    return true;
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

/* 删除函数 基于位置 */
bool Delete_pos(NumLists *lists, const int pos)
{
    NumLists *temp = lists;
    NumLists *plist = NULL;

    /* 从1开始计数 */
    for(int i = 1; i < pos; i++)
    {
        if(NULL == temp)
        {
            printf("May be you should set a smaller pos number\n");
            return false;
        }
        else
        {
            plist = temp;
            temp = temp->next;
        }
    }

    plist->next = temp->next;
    free(temp);
}

/* 删除函数 基于内容 */
bool Delete_data(NumLists *lists, const int data)
{
    NumLists *temp = lists;
    NumLists *plist = NULL;

    while(temp->data != data)
    {
        if(NULL == temp)
        {
            printf("Fall to search\n");
            return false;
        }
        else
        {
            plist = temp;
            temp = temp->next;
        }
    }

    plist->next = temp->next;
    free(temp);
}

/* 筛选函数 基于内容保留 */
bool Filter_data(NumLists *lists, const int min, const int max)
{
    NumLists *plist = lists;
    NumLists *temp = plist->next;

    while(NULL != temp)
    {
        if((temp->data < min)||(temp->data > max))
        {
            plist->next = temp->next;
            free(temp);
            temp = plist->next;
        }
        else
        {
            plist = temp;
            temp = temp->next;
        }
    }

    return true;
}

/* 筛选函数 基于内容显示 */
bool Filter_print(NumLists *lists, const int min, const int max)
{
    NumLists *plist = lists;

    while(NULL != plist)
    {
        if((plist->data > min)&&(plist->data < max))
        {
            printf("NO:%d\t%d\n", plist->num, plist->data);
        }
        plist = plist->next;
    }
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
