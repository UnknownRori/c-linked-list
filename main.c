#include <stdio.h>
#include "LinkedList.h"

int main()
{
    ListNode *root = createList(10);

    root->appendLast(root, 20);
    root->appendLast(root, 30);

    root->print(root);

    return 0;
}