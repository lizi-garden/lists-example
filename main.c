#include <stdio.h>
#include <stdlib.h>
#include "numlists.h"

int main(int argc, char *argv[])
{
    NumLists *head = NULL;
    NumLists *plist = NULL;
    int i = 1;

    head = initNumLists(8);

    addNumLists(head, 6);
    addNumLists(head, 14);

    printf("这是原链表的数据\n");

    /* 输出链表内容 */
    for(plist = head; NULL != plist; plist = plist->next)
    {
        printf("%d:\t%d\n", plist->num, plist->data);
    }

    int num, input;
    printf("输入需要插入的整数：");
    scanf("%d", &input);

    printf("输入需要插入的位置：");
    scanf("%d", &num);

    insertNumLists(head, input, num);

    printf("\n");
    printf("这是修改后的链表数据\n");

    for(plist = head; NULL != plist; plist = plist->next)
    {
        printf("%d:\t%d\n", plist->num, plist->data);
    }

    return 0;
}
