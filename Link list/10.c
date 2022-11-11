/**
 *
 *10. Reverse a doubly linked list.
 * /

#include<stdio.h>
#include<stdlib.h>

struct node {
        int data;
        struct node* next;
	struct node* prev;
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
			head -> prev = NULL;

                } else {
                        temp_1 -> next = temp;
                        temp -> prev = temp_1;
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
        printf("\n");
}

struct node* reverse(struct node* head) 
{
	struct node* curr = head;
	struct node* temp = NULL;

	while(curr != NULL) {
		temp = curr -> prev;
		curr -> prev = curr -> next;
		curr -> next = temp;
		curr = curr -> prev;
	}
	head = temp -> prev;

}
int main()
{
	struct node* head = NULL;
	head = create_list(4,head);
	
	print_list(head);
	
	head = reverse(head);	
	printf("after reverse\n");
	print_list(head);
}
