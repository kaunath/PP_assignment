/*
 *18. Find the middle element of a given linked list. In case of tie print the second one.
Input:
5 -> 7 -> NULL
5 -> 7 -> 17 -> NULL
5 -> 7 -> 17 -> 13 -> NULL
5 -> 7 -> 17 -> 13 -> 11 -> NULL
Output:
7
7
17
17
 * */


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
void find_middle(struct node* head) 
{
	struct node* temp = head;
	int count = 0, pos = 1;

	while(temp != NULL) {
		count++;
		temp = temp -> link;

	}
	count = (count/2) + 1;
	temp = head;
	while(pos < count) {
		temp = temp -> link;
		pos++;
	}
	printf("%d\n", temp -> data);

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
	struct node* arr[4];
	
	arr[0] = create_list(2,head);
	arr[1] = create_list(3,head);
	arr[2] = create_list(4,head);
	arr[3] = create_list(5,head);
	
	for(int i = 0; i < 4; i++) {
		print_list(arr[i]);
	}
	for(int i = 0; i < 4; i++) {
	find_middle(arr[i]);
	}

}
