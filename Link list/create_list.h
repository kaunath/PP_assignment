
#include<stdlib.h>
struct node {
        int data;
        struct node *next;
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
                        head -> next = NULL;

                } else {
                        temp_1 -> next = temp;
                        temp_1 = temp;
                        temp -> next = NULL;
                }
        }

        return head;
}

void print_list(struct node *head)

{
        struct node *temp;
        temp = head;

        while ((temp -> next) != NULL) {
        printf("%d ", temp -> data);
        temp = temp->next;

        }
        printf("%d ", temp -> data);
}


