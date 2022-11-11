/* Sample Input
 * 10
 * 0 1 2 3 4 5 6 7 8 9
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	int rank;
	struct node *parent;
};

struct node ** make_set(int);
struct node * create_node(int);
void print_set(struct node **, int);
struct node * find_node_parent(struct node **set, int data, int n);
struct node * find_parent(struct node *);
void union_by_rank(struct node **, int, int, int);
void path_compression(struct node **, int);

int main() {
	int n;
	scanf("%d", &n);
	struct node **set;
	set = make_set(n);
	print_set(set, n);
	union_by_rank(set, 1, 5, n);
	union_by_rank(set, 3, 7, n);
	union_by_rank(set, 1, 4, n);
	union_by_rank(set, 5, 7, n);
	union_by_rank(set, 0, 8, n);
	union_by_rank(set, 6, 9, n);
	union_by_rank(set, 3, 9, n);
	path_compression(set, n);
	print_set(set, n);
}

struct node ** make_set(int n) {
	struct node **set = (struct node **)malloc(n * sizeof(struct node *));
	// printf("Creating Set:\n");
	int data;
	for(int i = 0; i < n; i++) {
		scanf("%d", &data);
		struct node *temp = create_node(data);
		// printf("data: %d\n", data);
		set[i] = temp;
	}

	// printf("Set created succesfully.\n");
	return set;
}

struct node * create_node(int data) {
	// printf("Creating Node.\n");
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->rank = 0;
	temp->parent = temp;
	// printf("Node created successfully.\n");
	return temp;
}

void print_set(struct node **set, int n){
	struct node * temp;
	for(int i = 0; i < n; i++) {
		temp = set[i];
		printf("data: %d, rank: %d, parent: %d\n", temp->data, temp->rank, temp->parent->data);
	}
	printf("\n");
}

struct node * find_node_parent(struct node **set, int data, int n) {
	for (int i = 0; i < n; i++) {
		if (set[i]->data == data) {
			return find_parent(set[i]->parent);
		}
	}
}

struct node * find_parent(struct node *temp) {
	if (temp->data == temp->parent->data) {
		return temp;
	}
	return find_parent(temp->parent);
}

void union_by_rank(struct node **set, int a, int b, int n) {
	struct node *atemp, *btemp;

	// printf("Trying to find parent of %d.\n", a);
	atemp = find_node_parent(set, a, n);
	// printf("Parent of a found successfully: %d\n", atemp->data);

	// printf("Trying to find parent of %d.\n", b);
	btemp = find_node_parent(set, b, n);
	// printf("Parent of a found successfully: %d\n", btemp->data);

	if (atemp->rank >= btemp->rank) {
		btemp->parent = atemp;
		(atemp->rank)++;
	} else {
		atemp->parent = btemp;
		(btemp->rank)++;
	}
}

void path_compression(struct node **set, int n) {
	for (int i = 0; i < n; i++) {
		// printf("In path compression method:\n");
		set[i]->parent = find_parent(set[i]->parent);
	}
}
