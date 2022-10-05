/*
 *5. Write a program for printing the following in a given linked list:
a. maximum
b. minimum
c. maximum – minimum
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

int find_max(struct node* head) {
	struct node* temp;
	int value;

	temp = head;
	value = temp -> data;
	while(temp != NULL) {		
		if((temp -> data) > value) {
			value = temp -> data;	
		}
		temp = temp -> next;
	}

	return value;
}

int main()
{      
       	struct node* head = NULL;
	int max_value;
        head = create_list(4, head);
        print_list(head);
        max_value = find_max(head);
        printf("%d", max_value);

}

