#include <stdio.h>
#include <stdlib.h>
#include "numlists.h"

int main(int argc, char *argv[])
{
    NumLists *list = NULL;
    int n = 0;
    int input = 0;

    int min = 0;
    int max = 0;

    printf("请输入需要的链表长度n：\n");
    scanf("%d", &n);

    printf("请输入链表中的%d个数据，用空格隔开：\n", n);

    scanf("%d", &input);
    list = Init(input);

    for(int i = 1; i < n; i++)
    {
        scanf("%d", &input);
        Add(list, input);
    }

    printf("这是当前的链表：\n");
    Show(list);
    printf("\n");

    printf("输入筛选条件的最小值和最大值：\n");
    scanf("%d", &min);
    scanf("%d", &max);
    Filter_data(list, min, max);

    Check(list);

    printf("这是筛选后的链表：\n");
    Show(list);

    Free(list);

    return 0;
}
