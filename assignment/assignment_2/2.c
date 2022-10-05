/*
2. For a given singly linked list delete a node:
a. at the beginning
b. at the end
c. at a given position k
Input:
k = 3
1 -> 2 -> 5 -> 7 -> 4 -> NULL
Output:
2 -> 5 -> 7 -> 4 -> NULL
1 -> 2 -> 5 -> 7 -> NULL
1 -> 2 -> 7 -> 4 -> NULL 

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

struct node* delete_beg(struct node* head) {
	
	struct node* temp;
	temp = head;
	if(head == NULL){
	 	printf("can't delete");
	} else if ((head -> next) == NULL) {
		free(head);
		return NULL;
	} else {
	head = temp -> next;
	temp -> next =  NULL;
	free(temp);
	
	return head;
	}

}


struct node* delete_end(struct node* head) {

	struct node *temp;
	struct node *temp_1;
	temp = head;
	
	if(head == NULL) {
		printf("Can't delete");
	}

	while((temp -> next) != NULL) {
	temp_1 = temp;
	temp = temp -> next;
	}
	temp_1 -> next = NULL;
	free(temp);

	return head;

}



struct node* delete_at_k(struct node* head, int pos) {
	
	struct node* temp_1;
	struct node* temp;
	int count = 1;
	temp_1 = head;
	temp = head;
	
	if(pos == 1) {
		delete_beg(head);
	} else {

	while(count < pos - 1) {
		temp_1 = temp_1 -> next;
		count++;
	}

	temp = temp_1 -> next;

	if((temp_1 -> next -> next) != NULL) {
		temp_1 -> next = temp_1 -> next -> next;
		temp -> next = NULL;
		free(temp);
	} else {
		temp_1 -> next = NULL;
		free(temp);
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

int main()
{	
	struct node *head = NULL;
	int pos, val;
	head = create_list(5, head);
	//printf("%d", head -> data);
	print_list(head);
	printf("after deletion at beginning");
	head = delete_beg(head);
	print_list(head);
	printf ("after ending");
	head = delete_end(head);
	print_list(head);

	for(int i = 0; i < 3; i++) {
	printf("after kth deletion");
	scanf("%d", &pos);
	head  = delete_at_k(head, pos);

	//head  = delete_beg(head);
	if(head == NULL) {
		break;
	}
	print_list(head);
	}
}
