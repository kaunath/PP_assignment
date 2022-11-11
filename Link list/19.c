/*Check whether a given singly linked list is palindrome or not.
Input:
a -> b -> NULL
a -> b -> a -> NULL
s -> a -> g -> a -> r -> NULL
r -> a -> d -> a -> r -> NULL
Output:
not palindrome
palindrome
not palindrome
palindrome
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node {
        char data;
        struct node* link;
};
struct node* create_list(int val, struct node* head) {

        struct node* temp;
        struct node* temp_1;
        temp_1 = head;

        for(int i = 0; i< val; i++) {
        temp = (struct node*)malloc(sizeof(struct node));
        scanf("%c%*c",&(temp -> data));
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
void print_list(struct node* head)
{
        struct node* temp = head;
	int count = 0;
printf("printing\n");

        while(temp != NULL) {
                printf("%c -> ", temp -> data);
                temp = temp -> link;
		count++;
        }
// printf("%d\", count);
        printf("NULL\n");
}
struct node* reverse(struct node* head)
{
	struct node* prev = NULL;
       struct node* curr = head; 
       struct node*  next = head;
	while(curr != NULL) {
		next = curr -> link;
		curr -> link = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
	return head;
}
bool is_palindrome(struct node* head) 
{
	struct node* slow;
       struct node* fast;
      struct node* dummy;
	
	slow = head;
	fast = head;
	dummy = head;
	while(fast != NULL && fast -> link != NULL) {
		slow = slow -> link;
		fast = fast ->link -> link;
	}
	slow -> link = reverse(slow -> link);

	slow = slow -> link;
	while(slow != NULL) {
		if (dummy -> link ->link == NULL)
		{
			if(slow -> data != dummy -> data) {
				return false;
			}
			else{
				return true;
			}
		} else if(dummy -> data != slow -> data) {
			return false;
		}
		dummy = dummy -> link;
		slow = slow -> link;

	}
	return true;

}
int main()
{
	struct node* head = NULL;
	struct node *arr[4];
	bool check;
	arr[0] = create_list(2,head);
	arr[1] = create_list(3,head);
	arr[2] = create_list(4,head);
	arr[3] = create_list(5,head);
	
	for(int i = 0; i < 4; i++) {
		print_list(arr[i]);
	}
	for(int i = 0; i < 4; i++) {
		check = is_palindrome(arr[i]);
		if(check == true) {
			printf("palindrome\n");
		}
		else {
			printf("not plaindorme\n");
		}
	}

}
