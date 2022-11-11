/*
14. Reverse a linked list in groups of given size.
Input:
k=4
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 12 -> 7 -> NULL
Output:
4 -> 3 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5 -> 7 -> 12 -> NULL
*/

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

struct node* reverse_in_groups(struct node* head, int size)
{
	struct node* prev = NULL;
	struct node* curr = head;
	struct node* link = head;
	int count;
	count = 0;
	
	while (curr != NULL && count < size) {
		link = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = link;
		count++;

	}
	
	if(link != NULL) {
	head -> next = reverse_in_groups(link, size);
	}

	return prev;

}

int main()
{	
	struct node *head = NULL;
	int size;
	head = create_list(5, head);
	print_list(head);
	scanf("%d", & size);
	head = reverse_in_groups(head, size);
	print_list(head);

}
