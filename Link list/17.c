/**
 * 17. Perform pair-wise swapping of nodes of a given linked list.
Input:
20 -> 18 -> 15 -> 10 -> 8 -> 6 -> 5 -> 3 -> 7 -> NULL
Output:
18 -> 20 -> 10 -> 15 -> 6 -> 8 -> 3 -> 5 -> 7 -> NULL
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

struct node* pair_swap(struct node* head) 
{
	struct node* prev = head;
	struct node* next = head -> link;
	int data;

	while(prev != NULL && next != NULL) {
		data = prev -> data;
	       prev -> data = next -> data;
	       next -> data = data;
	       prev = next -> link;
	       if(prev != NULL) {
	       		next = prev ->link;
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

        head = create_list(2,head);
        print_list(head);
	head = pair_swap(head);
	print_list(head);
     

}

