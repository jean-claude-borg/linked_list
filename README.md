A Linked List Library Written in C\

Allows for dynamic use of integers only(for now)\

The following is a list of all supported functions:\
node* createList(int data): returns a pointer to the first node(head) of a new list containing the supplied data\
void pushToList(node* head, int data): adds a new node to the end of the given list containing the supplied data\
void printList(node* head): prints the given list\
void printListReverse(node* head) prints the given list in reverse(strating from the tail)\
void popFromList(node* head): removes the last node from the list(the tail)\
int getListLength(node* head): returns the length of the list(starts counting from 1 not 0)\
bool searchList(node* head, int data): searches in the given list and returns true if a match is found\
void pushToListAt(node* head, int data, int index): adds a node containing the new data to the given list, the new node is added before the node at the given index\
int* copyListToArray(node* head): copies the entire list to an array and returns the the pointer to the start of the integer array\
void sortListAscending(node* head): sorts the given list in ascending order\
void deleteList(node* head, node** headPtr): deallocates every node in the list\
void popFromListAt(node* head, int index): removes the node in the list corresponging to the given index\
void mergeLists(node* head1, node* head2): appends list2 to the tail of list1\
