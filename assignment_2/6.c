/*
6. Print the sum of all even numbers stored in a circular linked list.
*/


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
                        head -> next = head;

                } else {
                        temp_1 -> next = temp;
                        temp_1 = temp;
                        temp -> next = head;
                }
        }

        return head;
}

void print_list(struct node *head)
{
        struct node *temp;
        temp = head;

        while ((temp -> next) != head) {
        printf("%d ", temp -> data);
        temp = temp->next;

        }
        printf("%d ", temp -> data);
        printf("\n");
}

int sum_of_even(struct node* head)
{	
	struct node* temp;
	int sum = 0;
	temp = head;

	
	while((temp -> next) != head) {
		if(((temp -> data) % 2) == 0) {
			sum += temp -> data;	
		}
		temp = temp -> next;
	}

	if (((temp -> data) % 2) == 0) {
		sum += temp -> data;
	}

	return sum;
}

int main()
{      
       	struct node* head = NULL;
	int max_value;
        int sum;
	head = create_list(4, head);
        print_list(head);
	sum = sum_of_even(head);
	printf("%d", sum);

}

