#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

#define true 1
#define false 0

void empty(ListNode *listNode)
{
    ListNode *Node = listNode->next;
    listNode->next = NULL;

    while (true)
    {
        ListNode *nextNode = Node->next;

        free(Node);

        if (nextNode != NULL)
        {
            Node = malloc(sizeof(ListNode));

            *Node = *nextNode;
        }
        else
            break;
    }
}

void reverse(ListNode *listNode)
{
    ListNode *newRoot = listNode->next;
    ListNode *nextNode = listNode->next->next;
    ListNode *tempNode = createList(listNode->data);

    while (true)
    {
        newRoot->next = tempNode;
        *listNode = *newRoot;

        if (nextNode == NULL)
            break;
        else
        {
            newRoot = nextNode;
            nextNode = nextNode->next;
            tempNode = createList(listNode->data);
            tempNode->next = listNode->next;
        }
    }
}

void removeFirst(ListNode *listNode)
{
    ListNode *nextNode = listNode->next;
    free(listNode);
    listNode = malloc(sizeof(ListNode));
    *listNode = *nextNode;
}

void removeLast(ListNode *listNode)
{
    while (true)
    {
        if (listNode->next->next == NULL)
        {
            free(listNode->next->next);
            listNode->next = NULL;
            break;
        }

        listNode = listNode->next;
    }
}

void appendFirst(ListNode *listNode, int value)
{
    ListNode *oldNode = createList(listNode->data);
    oldNode->next = listNode->next;

    ListNode *newNode = createList(value);

    newNode->next = oldNode;

    *listNode = *newNode;
}

void appendLast(ListNode *listNode, int value)
{
    ListNode *newNode = createList(value);

    while (true)
    {
        if (listNode->next == NULL)
        {
            listNode->next = newNode;
            break;
        }

        listNode = listNode->next;
    }
}

void print(ListNode *listNode)
{
    if (listNode->next == NULL)
        printf("%d \n", listNode->data);
    else
        printf("%d, ", listNode->data);

    if (listNode->next != NULL)
        listNode->print(listNode->next);
}

/**
 * @brief Create a List object
 *
 * @param initialValue
 * @return ListNode*
 */
ListNode *createList(int initialValue)
{
    ListNode *newList;

    newList = malloc(sizeof(ListNode));
    newList->data = initialValue;
    newList->next = NULL;
    newList->appendLast = &appendLast;
    newList->appendFirst = &appendFirst;
    newList->removeLast = &removeLast;
    newList->removeFirst = &removeFirst;
    newList->empty = &empty;
    newList->reverse = &reverse;
    newList->print = &print;

    return newList;
}