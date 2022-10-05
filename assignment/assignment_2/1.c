/*
 *1. For a given singly linked list insert a node:
a. at the beginning
b. at the end
c. at a given position k
Input:
value=8, k=4
1 -> 2 -> 5 -> 7 -> 4 -> NULL
Output:
8 -> 1 -> 2 -> 5 -> 7 -> 4 -> NULL
1 -> 2 -> 5 -> 7 -> 4 -> 8 -> NULL
1 -> 2 -> 5 -> 8 -> 7 -> 4 -> NULL
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

struct node* insert_beg(struct node* head, int val) {

	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp -> data = val;	
	temp -> next = head;
	head = temp;

	return head;
}


struct node* insert_end(struct node* head) {

	struct node *temp = (struct node *)malloc(sizeof(struct node));
	struct node *temp_1;
	
	temp_1 = head;
	scanf("%d", &(temp -> data));
	
	while((temp_1 -> next) != NULL) {
	temp_1 = temp_1 -> next;
	}
	
	temp_1 -> next = temp;
	temp -> next = NULL;

	return head;

}



struct node* insert_at_k(struct node* head, int pos, int val) {
	
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	struct node *temp_1;
	int count = 1;
	temp_1 = head;
	temp -> data = val;
	
	if(pos == 1) {
	insert_beg(head, val);
	}
	while(count < pos - 1) {
	temp_1 = temp_1 -> next;
	count++;
	}
	
	temp -> next = temp_1 -> next;
	temp_1 -> next = temp;

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

int main()
{	
	struct node *head = NULL;
	int pos, val;
	head = create_list(5, head);
	//printf("%d", head -> data);
	print_list(head);
	printf("after insertion at beginning");
	head = insert_beg(head , 6);
	print_list(head);
	printf ("after ending");
	head = insert_end(head);
	print_list(head);

	for(int i = 0; i < 4; i++) {
	printf("after kth insertion");
	scanf("%d %d", &pos, &val);
	head  = insert_at_k(head, pos, val);
	print_list(head);
	}
}
