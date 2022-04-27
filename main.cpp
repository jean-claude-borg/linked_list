#include "list.h"

int main()
{
    list list = createList(69);
    pushToList(list,70);
    pushToList(list, 71);
    pushToList(list, 72);

    pushToListAt(list,100,0);
    printList(list);
    printf("\n--------------------------");
    printListReverse(list);

    return 0;
}

