#include "numlists.h"
#include <stdio.h>
#include <stdlib.h>

/* 初始化函数 */
NumLists* initNumLists(const int data)
{
    NumLists *head = NULL;
    head = (NumLists*)malloc(sizeof(NumLists));

    head->num = 1;
    head->next = NULL;
    head->data = data;
}

/* 添加函数 */
void addNumLists(NumLists *head, const int data)
{
    if(NULL == head)
    {
        printf("You must init lists in advance\n");
        exit(-2);
    }
    else
    {
        NumLists *list = NULL;
        NumLists *plist = head;
        int i = 2;

        /* 查找到链表最后一位 */
        while(NULL != plist->next)
        {
            plist = plist->next;
            i++;
        }

        list = (NumLists*)malloc(sizeof(NumLists));

        plist->next = list;
        list->num = i;
        list->data = data;      /* 添加数据 */
        list->next = NULL;      /* 以NULL作为链表结尾 */
    }
}

/* 插入函数 */
void insertNumLists(NumLists *head, const int data, int pos)
{
    int i = 2;
    NumLists *plist = head;
    NumLists *list = NULL;

    while (i < pos && plist != NULL)
    {
        plist = plist->next;
        i++;
    }

    list = (NumLists*)malloc(sizeof(NumLists));

    list->num = pos;
    list->data = data;
    list->next = plist->next;
    plist->next = list;

    plist = list->next;
    while(NULL != plist)
    {
        plist->num++;
        plist = plist->next;
    }

}

/* 迭代函数 */
int pairNumLists(NumLists *head)
{
    static int n = 1;
    NumLists *plist = head;

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
void deleteNumLists(NumLists *head);

/* 释放函数 */
void freeNumLists(NumLists *head)
{
    NumLists *temp = head;

    while(NULL != temp->next)
    {
        ;
    }
}

