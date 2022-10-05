/*
Take N numbers as input from the user and create a doubly linked list
*/


#include<stdio.h>
#include<stdlib.h>

struct node {
        int data;
        struct node* next;
	struct node* prev;
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
			head -> prev = NULL;

                } else {
                        temp_1 -> next = temp;
                        temp -> prev = temp_1;
			temp_1 = temp;
                        temp -> next = NULL;
                }
        }

        return head;
}

int find_smallest(struct node* head)
{	
	struct node* temp = head;
	int smallest = temp -> data;

	while(temp != NULL) {
		if(smallest > temp -> data) {
			smallest = temp -> data;
		}
		temp = temp -> next;
	}
	return smallest;
}

struct node* delete_smallest(int val, struct node* head)
{
	struct node* temp = head;
	struct node* ptr;
	while(temp != NULL) {
		if(temp -> data == val) {
			if(temp -> prev == NULL) {
				ptr = temp -> next;
				head = temp -> next;
				ptr -> prev = NULL;
				temp -> next = NULL;
				temp -> prev = NULL;
//				free(temp);
				break;
			}
			else if(temp -> next == NULL) {
				ptr = temp -> prev;
				ptr -> next = NULL;
				temp -> prev = NULL;
				temp -> next = NULL;
				break;
				//free(temp);
			} else {
				ptr = temp -> next;
			ptr -> prev  = temp -> prev;
			ptr = temp -> prev;
			ptr -> next = temp -> next;
			temp -> prev = NULL;
			temp -> next = NULL;
			break;
//			free(temp);
			}
		}
		temp = temp -> next;
	}

	free(temp);
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
	
//check if it is doubly link list or not	
       /* temp = head;
	while(temp -> next != NULL) {
		if ((temp -> prev) == NULL) {
			printf("%d %d\n", temp -> data, temp -> next -> data);
	} 	else {
        		printf("%d %d %d", temp -> data, temp -> prev -> data, temp -> next -> data);
        		printf("\n");
	}
	temp = temp -> next;
	}
        printf("%d %d", temp -> data, temp -> prev -> data);
        printf("\n");
	*/
}



int main()
{      
       	struct node* head = NULL;
	int smallest;
	head = create_list(4, head);
        print_list(head);

	smallest = find_smallest(head);
	printf("smallest is %d\n", smallest);
	head = delete_smallest(smallest, head);
	print_list(head);
}

