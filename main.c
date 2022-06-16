#include <stdio.h>
#include "LinkedList.h"

int main()
{
    ListNode *root = createList(10);

    root->appendLast(root, 20);
    root->appendLast(root, 30);
    root->appendFirst(root, 0);

    root->print(root);

    return 0;
}