#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/* 初始化函数 */
Lists* Init(const int data)
{
    Lists *lists = NULL;
    lists = (Lists*)malloc(sizeof(Lists));

    lists->next = NULL;
    lists->data = data;

    return lists;
}

/* 添加函数 */
bool Add(Lists *lists, int data)
{
    Lists *new = NULL;
    Lists *plist = lists;

    /* 查找到链表最后一位 */
    while(NULL != plist->next)
    {
        plist = plist->next;
    }

    new = (Lists*)malloc(sizeof(Lists));

    plist->next = new;
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
bool Insert(Lists *lists, const int pos, const int data)
{
    Lists *plist = lists;
    Lists *new = NULL;

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

    new = (Lists*)malloc(sizeof(Lists));

    /* 进行插入操作 */
    new->next = plist->next;
    plist->next = new;

    new->data = data;

    return true;
}

/* 显示函数 */
void Show(Lists *lists)
{
    Lists *plist = lists;
    int count = 1;

    while(NULL != plist)
    {
        printf("NO:%d\t%d\n", count, plist->data);
        count++;
        plist = plist->next;
    }
}

/* 迭代函数 */
int Pair(Lists *lists)
{
    static int n = 1;
    Lists *plist = lists;

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
bool Delete_pos(Lists *lists, const int pos)
{
    Lists *temp = lists;
    Lists *plist = NULL;

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
bool Delete_data(Lists *lists, const int data)
{
    Lists *temp = lists;
    Lists *plist = NULL;

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
Lists* Filter_data(Lists *lists, const int min, const int max)
{
    Lists *plist = NULL;
    Lists *temp = lists;

    while(NULL != temp)
    {
        if((temp->data < min)||(temp->data > max))
        {
            if(NULL == plist)
            {
                lists = lists->next;    
                temp = lists;
                plist = NULL;
            }
            else
            {
                plist->next = temp->next;
                free(temp);
                temp = plist->next;
            }
        }
        else
        {
            plist = temp;
            temp = temp->next;
        }
    }

    return lists;
}

/* 筛选函数 基于内容显示 */
bool Filter_print(Lists *lists, const int min, const int max)
{
    Lists *plist = lists;
    int count = 1;

    while(NULL != plist)
    {
        if((plist->data > min)&&(plist->data < max))
        {
            printf("NO:%d\t%d\n", count, plist->data);
        }
        plist = plist->next;
    }
}

/* 释放函数 */
void Free(Lists *lists)
{
    Lists *plist = lists;

    while(NULL != plist->next)
    {
        Lists *temp = plist;
        plist = plist->next;
        free(temp);
    }
}
