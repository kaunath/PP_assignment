<<<<<<< HEAD
/**
 *15. Remove in a linked list all the nodes that have a greater value to their right.
Input:
10 -> 12 -> 15 -> 20 -> 5 -> 16 -> 25 -> 8 -> NULL
10 -> 12 -> 15 -> 20 -> 25 -> 26 -> 30 -> 40 -> NULL
20 -> 18 -> 15 -> 10 -> 8 -> 6 -> 5 -> 3 -> NULL
Output:
20 -> 25 -> 8 -> NULL
40 -> NULL
20 -> 18 -> 15 -> 10 -> 8 -> 6 -> 5 -> 3 -> NULL
 * */
#include<stdio.h>
#include<stdlib.h>
struct node {
        int data;
        struct node *next;
};

struct node* create_list(int elem, struct node* head) {
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


=======
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
>>>>>>> be9a0e83a4839d57944906febc9bbdbb8f96066d

void print_list(struct node *head)

{
<<<<<<< HEAD
        struct node *temp;
        temp = head;

        while (temp != NULL) {
        printf("%d -> ", temp -> data);
        temp = temp->next;

        }
        printf("NULL\n");
}

struct node* copy_list(struct node* head) {

	struct node* temp;
	if(head == NULL) {
		return NULL;
	} else {
		struct node* temp = (struct node*)malloc(sizeof(struct node));
		temp -> data = head -> data;
		temp -> next = copy_list(head-> next);

	}
	return temp;

}
struct node* remove_greater_node(struct node* head) {
	struct node* prev = head;
	struct node* link = head -> next;
	struct node* ptr;

		while(link != NULL) {
			printf("inside while");

			if(prev -> data < link -> data) {
				if(prev == head) {
					prev -> next = NULL;
					prev = link;
					head = link;
					link = link -> next;
				printf("inside if");

				} else {
				prev ->data = link -> data;
				prev -> next = link -> next;
				link -> next = NULL;
				// prev = prev ->next;
				link = prev -> next;
				 
				printf("inside else");
				}
			} else {
				prev = prev -> next;
				link = link -> next;
			}
		}
	
	return head;
=======
	struct node *temp;
	temp = head;

	while (temp != NULL) {
	printf("%d ->", temp -> data);
	temp = temp->next;

	}
	printf("NULL\n ");
>>>>>>> be9a0e83a4839d57944906febc9bbdbb8f96066d
}
int main()
{
	struct node* head = NULL;
<<<<<<< HEAD
	struct node* arr[3];
	for(int i = 0; i < 1; i++) {
		arr[i] = create_list(8,head);
	}

	for(int i = 0; i < 1; i++) {
		print_list(arr[i]);
	}

	for(int i = 0; i < 1; i++) {
		struct node* temp;
		arr[i] = remove_greater_node(arr[i]);
		print_list(arr[i]);
				
	}	
=======
	head = create_list(8, head);
	print_list(head);
	head = delete_max_to_right(head);
	print_list(head);
>>>>>>> be9a0e83a4839d57944906febc9bbdbb8f96066d
}
