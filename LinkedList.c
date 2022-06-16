#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

#define true 1
#define false 0

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
    newList->print = &print;

    return newList;
}