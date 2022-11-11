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
	head = insert_beg(head, val);
	return head;
	} else {
	while(count < pos - 1) {
	temp_1 = temp_1 -> next;
	count++;
	}
	
	temp -> next = temp_1 -> next;
	temp_1 -> next = temp;

	return head;
	}

}

void print_list(struct node *head)

{
	struct node *temp;
	temp = head;

	while (temp  != NULL) {
	printf("%d ->", temp -> data);
	temp = temp->next;

	}
	printf("NULL\n");
}

struct node* copy_list(struct node* head) {
	struct node* temp = head;
	struct node* ptr;
	if(head == NULL) {
		return NULL;
	} else {
		temp = (struct node*)malloc(sizeof(struct node));
		temp -> data = head -> data;
		temp -> next = copy_list(head -> next);
	}
	return temp;

}

int main()
{	
	struct node *head = NULL;
	struct node* temp;
	int pos, val;
	struct node *arr[4];
	//head = create_list(5, head);
	temp = head;
	head = create_list(4,head);
	for(int i = 0; i < 5; i++) {
		arr[i] = copy_list(head);  
	
	}
	for (int i = 0; i < 5; i++) {
		print_list(arr[i]);
	}
	
	//printf("%d", head -> data);
	//print_list(head);
	
	printf("after insertion at beginning");
	arr[1] = insert_beg(arr[1] , 6);
	print_list(arr[1]);
	printf ("after ending");
	arr[2] = insert_end(arr[2]);
	print_list(arr[2]);

	for(int i = 0; i < 4; i++) {
	printf("after kth insertion");
	scanf("%d %d", &pos, &val);
	arr[3]  = insert_at_k(arr[3], pos, val);
	print_list(arr[3]);
	}
}
