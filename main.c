#include <stdio.h>
#include <stdlib.h>
#include "numlists.h"

int main(int argc, char *argv[])
{
    NumLists *list = NULL;

    list = Init(8);

    Add(list, 14);
    Add(list, 16);

    Insert(list, 2, 4);

    Show(list);

    Free(list);

    return 0;
}
