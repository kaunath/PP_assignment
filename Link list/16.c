/**
 *16. Remove alternate nodes from a given linked list.
Input:
20 -> 18 -> 15 -> 10 -> 8 -> 6 -> 5 -> 3 -> NULL
Output:
20 -> 15 -> 8 -> 5 -> NULL
 */


#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* link;
};
struct node* create_list(int val, struct node* head) {
	
	struct node* temp;
	struct node* temp_1;
	temp_1 = head;
	
	for(int i = 0; i< val; i++) {
	temp = (struct node*)malloc(sizeof(struct node));
	scanf("%d",&(temp -> data));
	if(head == NULL) {
		head = temp;
		temp_1 = temp;
		temp -> link = NULL;
	}
	else {
		temp_1 -> link = temp;
		temp -> link = NULL;
		temp_1 = temp;
	}
	}

	return head;
}
struct node* delete_alt_nodes(struct node* head)
{
	struct node* prev = head;
	struct node* next = head -> link;

	while(prev != NULL && next != NULL) {
		prev -> link = next -> link;
		next -> link = NULL;
		free(next);
		prev = prev -> link;

		if(prev != NULL) {
			next = prev -> link;
		}	
	}
	return head;
}
void print_list(struct node* head) 
{
	struct node* temp = head;

	while(temp != NULL) {
		printf("%d -> ", temp -> data);
		temp = temp -> link;
	}
	printf("NULL\n");
}

int main()
{
	struct node* head = NULL;

	head = create_list(5,head);
	print_list(head);
	head = delete_alt_nodes(head);
	print_list(head);
}
