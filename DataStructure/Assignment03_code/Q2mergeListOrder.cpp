#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element value) {
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->data = value;
    new_node->link = head;
    head = new_node;
    return head;
}

void print_list(ListNode* head) {
    for (ListNode* p = head; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL \n");
}

ListNode* reverseList(ListNode* head)
{
    ListNode* p, * q, * r;
    p = head;
    q = NULL;
    while (p != NULL) {
        r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
    return q;
}


// Given two non-empty linked lists 'a' and 'b'
ListNode* sortedMerge(ListNode* a, ListNode* b)
{
    // Reverse Linked List 'a'
    a = reverseList(a);
    // Reverse Linked List 'b'
    b = reverseList(b);
    // Initialize head of resultant list
    ListNode* head = NULL;
    ListNode* temp;
    // Traverse both lists while both of them
    // have nodes.
    while (a != NULL && b != NULL) {
        // If a's current value is greater than or equal to
        // b's current value.
        if (a->data >= b->data) {
            // Store next of current Node in first list
            temp = a->link;
            // Add 'a' at the front of resultant list
            a->link = head;
            // Make 'a' - head of the result list
            head = a;
            // Move ahead in first list
            a = temp;
        }

        // If b's value is greater. Below steps are similar
        // to above (Only 'a' is replaced with 'b')
        else {
            temp = b->link;
            b->link = head;
            head = b;
            b = temp;
        }
    }

    // If second list reached end, but first list has
    // nodes. Add remaining nodes of first list at the
    // beginning of result list
    while (a != NULL) {
        temp = a->link;
        a->link = head;
        head = a;
        a = temp;
    }

    // If first list reached end, but second list has
    // nodes. Add remaining nodes of second list at the
    // beginning of result list
    while (b != NULL) {
        temp = b->link;
        b->link = head;
        head = b;
        b = temp;
    }
    // Return the head of the result list
    return head;
}

int main() {
    ListNode* a = NULL;
    ListNode* b = NULL;

    a = insert_first(a, 25);
    a = insert_first(a, 20);
    a = insert_first(a, 15);
    a = insert_first(a, 10);
    a = insert_first(a, 5);
    a = insert_first(a, 2);
    a = insert_first(a, 1);
    printf("list a: \n");
    print_list(a);

    b = insert_first(b, 30);
    b = insert_first(b, 18);
    b = insert_first(b, 15);
    b = insert_first(b, 8);
    b = insert_first(b, 7);
    b = insert_first(b, 3);
    printf("list b: \n");
    print_list(b);

    ListNode* c = sortedMerge(a, b);
    printf("list c: \n");
    print_list(c);
    return 0;
}