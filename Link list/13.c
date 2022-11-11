/*
*
*13. Delete duplicate elements from a given linked list. Retain the earliest entries.
Input:
20 -> 18 -> 15 -> 20 -> 6 -> 18 -> 5 -> 3 -> NULL
Output:
20 -> 18 -> 15 -> 6 -> 5 -> 3 -> NULL
* */

#include<stdio.h>
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

	while (temp != NULL) {
	printf("%d -> ", temp -> data);
	temp = temp->next;

	}
	printf("NULL\n");
}

struct node* delete_duplicate(struct node* head)
{
	struct node* temp;
	struct node* link;
	temp = head;
	link = head -> next;
	while (temp != NULL) {
		link = temp -> next;
		while(link != NULL) {
		if ((link -> data) == temp -> data) {
			temp -> next = link -> next;
			link -> next = NULL;
			link = temp -> next;
		} else {
			link = link -> next;
		}
		}
		temp = temp -> next;
	}
	return head;
}

int main()
{	
	struct node *head = NULL;
	head = create_list(5, head);
	print_list(head);
	head = delete_duplicate(head);
	print_list(head);

}
