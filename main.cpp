#include "list.h"

int main()
{
    list list = createList(69);
    pushToList(list,68);
    pushToList(list, 67);
    pushToList(list, 66);
    pushToList(list, 65);

    //pushToListAt(list,100,0);
    printList(list);
    sortListAscending(list);
    printf("\n--------------------------");
    printList(list);

    return 0;
}

