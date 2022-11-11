 /*
  *11. Print all the elements at the index of multiples of k with the first element assumed to have an index of
0. Do this for a single pass of the linked list.
Input:
k=3
12 -> 15 -> 18 -> 17 -> 19 -> 20 -> 22 -> NULL
Output:
12 -> 17 -> 22 -> NULL
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


void print_list(struct node* head, int pos)
{
	struct node* temp;
	temp = head;
	int i = 0;

	while (temp != NULL) {
		if( i % pos == 0) {
			printf("%d -> ", temp -> data);
		}
		temp = temp->next;
		i++;

	}
	printf("NULL");
}

int main()
{	
	struct node *head = NULL;
	int pos;

	head = create_list(5, head);
	scanf("%d", &pos);	
	print_list(head, pos);
}

