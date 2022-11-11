/**
 *12. Extend the above solution assuming that the list is circular and the N-th index is the same as 0-th
index. You may need multiple passes. However, every number should be printed only once during its
first selection.
Input:
k=3
12 -> 15 -> 18 -> 17 -> 19 -> 20 -> 22 -> NULL
Output:
12 -> 17 -> 22 -> 18 -> 20 -> 15 -> 19 -> NULL
 */

#include<stdio.h>
#include<stdlib.h>

struct node {
        int data;
        struct node* next;
};

struct node* create_list(int elem, struct node *head) {
        struct node *temp = NULL;
        struct node *temp_1 = NULL;
        for (int i = 0; i < elem; i++) {
                temp = (struct node*) malloc(sizeof(struct node));
                scanf("%d", &(temp->data));
                if(head == NULL) {
                        head = temp;
                        temp_1 = temp;
                        head -> next = head;

                } else {
                        temp_1 -> next = temp;
                        temp_1 = temp;
                        temp -> next = head;
                }
        }

        return head;
}

void print_list(struct node *head)
{
        struct node *temp;
        temp = head;

        while ((temp -> next) != head) {
        printf("%d ", temp -> data);
        temp = temp->next;

        }
        printf("%d ", temp -> data);
        printf("\n");
}


