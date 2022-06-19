#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct ListNode ListNode;

struct ListNode
{
    int data;
    ListNode *next;

    /**
     * @brief Reverse the linked list node
     *
     * @param  ListNode
     */
    void (*reverse)(ListNode *listNode);

    /**
     * @brief Append a new list node on the end node in a list
     *
     * @param  ListNode
     * @param  value
     */
    void (*appendLast)(ListNode *listNode, int value);

    /**
     * @brief Append a new list node on the first node in a list
     *
     * @param  ListNode
     * @param  value
     */
    void (*appendFirst)(ListNode *listNode, int value);

    /**
     * @brief Remove last node in a list
     *
     * @param ListNode
     */
    void (*removeLast)(ListNode *listNode);

    /**
     * @brief Remove first node in a list
     *
     * @param ListNode
     */
    void (*removeFirst)(ListNode *listNode);

    /**
     * @brief Print the list
     *
     * @param ListNode
     */
    void (*print)(ListNode *listNode);

    /**
     * @brief Find and return a node in the list
     *
     * @param ListNode
     * @param key
     */
    ListNode *(*findNode)(ListNode *listNode, int key);
};

/**
 * @brief Create a ListNode object
 *
 * @param initialValue
 * @return ListNode*
 */
ListNode *createList(int initialValue);

#endif