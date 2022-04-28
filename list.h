#pragma once
#include <cstdlib>
#include <cstdio>

//int array null terminator = maximum integer value(arbitrary)
#define NULL_TERMINATOR 2147483647;

typedef struct node{
    node* previousNode;
    node* nextNode;
    int data;
    bool isHead;
    bool isTail;
}node;

typedef node* list;

node* createList(int data)
{
    node* startNode = (node*)malloc(sizeof(node));
    startNode->isHead = true;
    startNode->isTail = true;
    startNode->previousNode = nullptr;
    startNode->nextNode = nullptr;
    startNode->data = data;
    return startNode;
}

void pushToList(node* head, int data)
{
    if(head == nullptr)
    {
        fprintf(stderr, "\nError: Given list does not exist");
        return;
    }

    node* newNode = createList(data);
    newNode->isHead = false;
    newNode->isTail = true;

    node* currentNode = head;

    while(currentNode->isTail == false)
    {
        currentNode = currentNode->nextNode;
    }
    if(currentNode->isTail == true)
    {
        currentNode->isTail = false;
        newNode->previousNode = currentNode;
        currentNode->nextNode = newNode;
    }
}

void printList(node* head)
{
    if(head == nullptr)
    {
        fprintf(stderr, "\nError: Given list does not exist");
        return;
    }

    node* currentNode = head;
    while(currentNode->isTail == false)
    {
        printf("\n%d", currentNode->data);
        currentNode = currentNode->nextNode;
    }
    if(currentNode->isTail == true)
        printf("\n%d", currentNode->data);
}

void printListReverse(node*head)
{
    if(head == nullptr)
    {
        fprintf(stderr, "\nError: Given list does not exist");
        return;
    }

    node* currentNode = head;
    while(currentNode->isTail == false)
    {
        currentNode = currentNode->nextNode;
    }
    while(currentNode->isHead == false)
    {
        printf("\n%d", currentNode->data);
        currentNode = currentNode->previousNode;
    }
    if(currentNode->isHead == true)
    {
        printf("\n%d", currentNode->data);
    }
}

void popFromList(node* head)
{
    if(head == nullptr)
    {
        fprintf(stderr, "\nError: Given list does not exist");
        return;
    }

    node* currentNode = head;
    while(currentNode->isTail == false)
    {
        currentNode = currentNode->nextNode;
    }
    if(currentNode->isTail == true)
    {
        currentNode = currentNode->previousNode;
        currentNode->nextNode = nullptr;
        currentNode->isTail = true;
    }
}

int getListLength(node* head)
{
    if(head == nullptr)
    {
        fprintf(stderr, "\nError: Given list does not exist");
        return 0;
    }

    int length = 0;
    node* currentNode = head;
    while(currentNode->isTail == false)
    {
        length++;
        currentNode = currentNode->nextNode;
    }
    if(currentNode->isTail == true)
        length++;

    return length;
}

bool searchList(node* head, int data)
{
    if(head == nullptr)
    {
        fprintf(stderr, "\nError: Given list does not exist");
        return false;
    }

    node* currentNode = head;
    while(currentNode->isTail == false)
    {
        if(currentNode->data == data)
            return true;
        currentNode = currentNode->nextNode;
    }
    if(currentNode->isTail == true)
    {
        if(currentNode->data == data)
            return true;
    }
    return false;
}

void pushToListAt(node* head, int data, int index)
{
    if(head == nullptr)
    {
        fprintf(stderr, "\nError: Given list does not exist");
        return;
    }

    node* currentNode = head;
    node* newNode = createList(data);
    newNode->isHead = false;
    newNode->isTail = false;

    int position = 0;

    if(index > getListLength(head) || index < 0)
        return;
    //last node in list
    else if(index == getListLength(head))
    {
        pushToList(head, data);
        return;
    }

    while(position <= index)
    {
        if(position == index)
        {
            newNode->nextNode = currentNode;
            //currentNode->previousNode = newNode;
            if(currentNode->isHead == false)
            {
                newNode->previousNode = currentNode->previousNode;
                newNode->previousNode->nextNode = newNode;
                newNode->nextNode->previousNode = newNode;
            }
            // if a new node is added at the start of the list, the new node is added right after the head, and its data is swapped with the head,
            // this gets the same result as adding the node before the head while avoiding a few bugs
            else if(currentNode->isHead == true)
            {
                newNode->nextNode = currentNode->nextNode;
                currentNode->nextNode->previousNode = newNode;
                currentNode->nextNode = newNode;
                newNode->previousNode = currentNode;
                int tempData = currentNode->data;
                currentNode->data = newNode->data;
                newNode->data = tempData;
            }
            return;
        }
        position++;
        currentNode = currentNode->nextNode;
    }
}

int* copyListToArray(node* head)
{
    if(head == nullptr)
    {
        fprintf(stderr, "\nError: Given list does not exist");
        return nullptr;
    }

    int listLength = getListLength(head);
    int* array = (int*)malloc(sizeof(int) * (listLength +1));

    node* currentNode = head;

    for(int i = 0; i < listLength; i++)
    {
        array[i] = currentNode->data;
        currentNode = currentNode->nextNode;
    }
    //array[listLength+1] = NULL_TERMINATOR;
    array[listLength] = NULL_TERMINATOR;
    return array;
}

//function for qsort
int comp (const void * elem1, const void * elem2)
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

void sortListAscending(node* head)
{
    if(head == nullptr)
    {
        fprintf(stderr, "\nError: Given list does not exist");
        return;
    }

    //this function copies the list to an array,
    //sorts the array using qsort,
    //then copies the array values back to the list, thus sorting the list
    node* currentNode = head;

    int* array = copyListToArray(head);
    int sizeOfArray = 0;
    int i = 0;
    while(true)
    {
        //nullTerminator value has to be set to NULL_TERMINATOR value,
        // because a compiler error occurs if NULL_TERMINATOR is used directly in the if statement
        int nullTerminator = NULL_TERMINATOR;
        if(array[i] == nullTerminator){ break; }
        i++;
        sizeOfArray++;
    }
    //printf("\nSize:\t%d", sizeOfArray);

    //sort array
    qsort(array, sizeOfArray, sizeof(int), comp);

    //write sorted array values back to list
    int counter = 0;
    while(currentNode->isTail == false)
    {
        currentNode->data = array[counter];
        counter++;
        currentNode = currentNode->nextNode;
    }
    if(currentNode->isTail == true)
    {
        currentNode->data = array[counter];
    }
    //printf("\nLength:\t%d", getListLength(head));
    free(array);
}

//TODO Add sortListDescending, popFromListAt, mergeLists, mergeListsAt, check for empty list(nullptr) before executing any functions

void deleteList(node* head, node** headPtr)
{
    node* currentNode = head;
    while(currentNode->isTail == false)
    {
        node* next = currentNode->nextNode;
        free(currentNode);
        currentNode = next;
    }
    *headPtr = nullptr;
}