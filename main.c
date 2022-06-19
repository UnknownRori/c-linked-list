#include <stdio.h>
#include "LinkedList.h"

int main()
{
    ListNode *root = createList(10);

    root->appendLast(root, 20);
    root->appendLast(root, 30);
    root->appendFirst(root, 0);
    root->removeLast(root);

    root->print(root);

    root->appendLast(root, 40);
    root->appendLast(root, 50);

    root->print(root);

    root->appendLast(root, 60);
    root->removeFirst(root);

    root->print(root);

    root->reverse(root);

    root->print(root);

    return 0;
}