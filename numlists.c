#include "numlists.h"
#include <stdio.h>
#include <stdlib.h>

/* 初始化函数 */
void initNumLists(NumLists *head, const int data)
{
    if(NULL != head)
    {
        printf("Init lists fail\n");
        exit(-1);
    }
    else
    {
        head = (NumLists*)malloc(sizeof(NumLists));

        head->num = 1;
        head->next = NULL;
        head->data = data;
    }
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

        head->next = list;
        list->num = i;
        list->data = data;      /* 添加数据 */
        list->next = NULL;      /* 以NULL作为链表结尾 */
    }
}

/* 插入函数 */
void insertNumLists(NumLists *head, const int data, int pos)
{
    ;
}

/* 迭代函数 */
int pairNumLists(const NumLists *head)
{
    static int n = 0;
    if(head->next == NULL)
    {
        return head->data;
    }
    else
    {
        int rdata;
        n++;
        return rdata;
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

