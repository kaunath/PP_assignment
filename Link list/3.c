#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node* head = NULL;
struct node* sorted = NULL;

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

void sortedInsert(struct node* newnode)
{
    /* Special case for the head end */
    if (sorted == NULL || sorted->data >= newnode->data) {
        newnode->next = sorted;
        sorted = newnode;
    }
    else {
        struct node* current = sorted;
        /* Locate the node before the point of insertion
         */
        while (current->next != NULL
               && current->next->data < newnode->data) {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
}

void insertionsort()
{
  
    struct node* current = head;
  
    // Traverse the given linked list and insert every
    // node to sorted
    while (current != NULL) {
  
        // Store next for next iteration
        struct node* next = current->next;
  
        // insert current in sorted linked list
        sortedInsert(current);
  
        // Update current
        current = next;
    }
    // Update head to point to sorted linked list
    head = sorted;
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
}

int main()
{
  
    printf("Linked List before sorting:\n");
    head = create_list(5, head);
    print_list(head);
    printf("\n");
  
    insertionsort(head);
  
    printf("Linked List after sorting:\n");
    print_list(head);
}