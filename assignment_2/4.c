/*
 *Reverse a singly linked list.
Input:
1 -> 2 -> 5 -> 7 -> 4 -> NULL
Output:
4 -> 7 -> 5 -> 2 -> 1 -> NULL
 * */

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
                        head -> next = NULL;

                } else {
                        temp_1 -> next = temp;
                        temp_1 = temp;
                        temp -> next = NULL;
                }
        }

        return head;
}
struct node* reverse_list(struct node* head) {
	struct node* curr = head;
	struct node* prev = NULL;
	struct node* next_link = head;
	
	if ((head -> next) == NULL) {
		printf("Already reversed");
	} else {
		while(curr != NULL) {
			next_link = curr -> next;
			curr -> next = prev;
			prev = curr;
			curr = next_link;
		}
		head = prev;
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


int main() 
{	struct node* head = NULL;
	head = create_list(4, head);
	print_list(head);
	head = reverse_list(head);
	print_list(head);

}
