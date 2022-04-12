#include "list.h"

int main()
{
    list list = createList(69);
    pushToList(list,70);
    pushToList(list, 71);
    pushToList(list, 72);
    pushToList(list, 73);
    pushToList(list, 74);
    pushToList(list, 75);

    pushToListAt(list, 100, 3);
    printList(list);

    return 0;
}

