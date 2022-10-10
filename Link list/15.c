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
struct node* delete_max_to_right(struct node* head) 
{
	struct node *temp = head;
	struct node* ptr = head;
	struct node* link = temp -> next;

	while(link != NULL) {
		if(temp -> data < link -> data) {
			temp -> data = link -> data;
		       temp -> next = link -> next;
	       		link -> next = NULL;
		 	link = temp -> next;	
		} else {
		link = link -> next;
		temp = temp -> next;
		//ptr = ptr->next;
		}
	}
	return head;
}

void print_list(struct node *head)

{
	struct node *temp;
	temp = head;

	while (temp != NULL) {
	printf("%d ->", temp -> data);
	temp = temp->next;

	}
	printf("NULL\n ");
}
int main()
{
	struct node* head = NULL;
	head = create_list(8, head);
	print_list(head);
	head = delete_max_to_right(head);
	print_list(head);
}
