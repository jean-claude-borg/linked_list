#pragma once
#include <cstdlib>
#include <cstdio>

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
    node* currentNode = head;
    while(currentNode->isTail == false)
    {
        printf("\n%d", currentNode->data);
        currentNode = currentNode->nextNode;
    }
    if(currentNode->isTail == true)
        printf("\n%d", currentNode->data);
}

void popFromList(node* head)
{
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
    //TODO link previous node pointers, currently newNode is only attached in the forward direction

    node* currentNode = head;
    node* newNode = createList(data);
    newNode->isHead = false;
    newNode->isTail = false;

    int position = 0;

    if(index+1 >= getListLength(head))
        return;

    while(currentNode->isTail == false)
    {
        if(position == index)
        {
            newNode->nextNode = currentNode;
            currentNode->previousNode = newNode;
            if(currentNode->isHead == false)
            {
                //currentNode->previousNode->nextNode = newNode;
                currentNode = currentNode->previousNode;
                currentNode->nextNode = newNode;
                //newNode->previousNode = currentNode->previousNode;
            }
            return;
        }
        position++;
        currentNode = currentNode->nextNode;
    }
    //last node in list
    if(position == index)
    {
        newNode->nextNode = currentNode;
        currentNode->previousNode = newNode;
        if(currentNode->isHead != true)
        {
            currentNode = currentNode->previousNode;
            currentNode->nextNode = newNode;
        }
    }
}

