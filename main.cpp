#include "list.h"

int main()
{
    list list1 = createList(100);
    list list2 = createList(90);

    pushToList(list1,80);
    pushToList(list2,70);

    mergeLists(list1, list2);
    printList(list1);
    printf("\n---------------");
    sortListAscending(list1);
    printList(list1);
    printf("\n----------------");

    popFromList(list1);
    pushToList(list1, 69);
    printList(list1);
    printf("\nLength:\t%d", getListLength(list1));

    return 0;
}

