# A Doubly Linked List Library Written in C
 Allows for dynamic use of integers only(for now)

### The following is a list of all supported functions:
__node* createList(int data):__ <br> &emsp;             returns a pointer to the first node(head) of a new list containing the supplied data\
__void pushToList(node* head, int data):__ <br> &emsp;  adds a new node to the end of the given list containing the supplied data\
__void printList(node* head):__ <br> &emsp;             prints the given list\
__void printListReverse(node* head):__ <br> &emsp;      prints the given list in reverse(strating from the tail)\
__void popFromList(node* head):__ <br> &emsp;           removes the last node from the list(the tail)\
__int getListLength(node* head):__ <br> &emsp;          returns the length of the list(starts counting from 1 not 0)\
__bool searchList(node* head, int data):__ <br> &emsp;  searches in the given list and returns true if a match is found\
__void pushToListAt(node* head, int data, int index):__ <br> &emsp;  adds a node containing the new data to the given list, the new node is added before the node at the given index\
__int* copyListToArray(node* head):__ <br> &emsp;     copies the entire list to an array and returns the the pointer to the start of the integer array\
__void sortListAscending(node* head):__ <br> &emsp;   sorts the given list in ascending order\
__void deleteList(node* head, node** headPtr):__ <br> &emsp;  deallocates every node in the list\
__void popFromListAt(node* head, int index):__ <br> &emsp;    removes the node in the list corresponging to the given index\
__void mergeLists(node* head1, node* head2):__ <br> &emsp;    appends list2 to the tail of list1
