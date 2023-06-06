// LinkedList: Inserting a node at the beginning

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* head;  // global variable

void Insert(int x){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x; // or (*temp).data = x;
	temp->next = head;
	head = temp;
}

void Print(){
	struct Node* temp = head;
	printf("List is: ");
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(void) {

	head = NULL; // empty list;

	printf("How many numbers to insert?  \n");
	int n, i, x;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		printf("Enter the number:  ");
		scanf("%d", &x);
		Insert(x);
		Print();
	}

	return 0;
}
