#include "list.h"

int main()
{
    list list = createList(10);
    pushToList(list,11);
    pushToList(list, 12);
    pushToList(list, 13);
    pushToList(list, 14);

    //pushToListAt(list,100,0);
    printList(list);
    popFromListAt(list, 0);
    popFromListAt(list, 0);
    popFromListAt(list, 0);
    popFromListAt(list, 0);
    popFromListAt(list, 0);

    printf("\n--------------------------");
    printf("\nLength:\t%d", getListLength(list));
    printList(list);

    return 0;
}

