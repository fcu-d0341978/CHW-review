#include<stdio.h>
#include<stdlib.h>

struct Node  {
	int data;
	int current;
	struct Node* next;
	struct Node* prev;
};

struct Node* head; 
struct Node* tail;
int NodeCount = 1;


struct Node* GetNewNode(int x) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->current = 0;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

void deleteFromBeginning(){
    struct Node * toDelete;

    if(head == NULL){
        printf("Unable to delete. List is empty.\n");
    }
    else{
        toDelete = head;

        head = head->next; // Move head pointer to 2 node
        head->prev = NULL; // Remove the link to previous node

        free(toDelete); // Delete the first node from memory
        printf("Success.\n");
    }
}

void deleteFromEnd(){
    struct Node * toDelete;

    if(tail == NULL){
        printf("Unable to delete. List is empty.\n");
    }
    else{
        toDelete = tail;

        tail = tail->prev; // Move last pointer to 2nd last node
        tail->next = NULL; // Remove link to of 2nd last node with last node

        free(toDelete);       // Delete the last node
        printf("Success.\n");
    }
}

void deleteFromN(int position){
    struct Node *current;
    int i;

    current = head;
    for(i=1; i<position && current!=NULL; i++){
        current = current->next;
    }

    if(position == 1){
        deleteFromBeginning();
    }
    else if(current == tail){
        deleteFromEnd();
    }
    else if(current != NULL){
        current->prev->next = current->next;
        current->next->prev = current->prev;

        free(current); // Delete the n node

        printf("Success\n", position);
    }
    else{
        printf("Invalid position!\n");
    }
}


void InsertAtTail(int x) {
	struct Node* temp = head;
	struct Node* newNode = GetNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	while(temp->next != NULL) temp = temp->next; // Go To last Node
	temp->next = newNode;
	newNode->prev = temp;
	NodeCount++; 
}


void Print() {
	struct Node* temp = head;
	printf("Data: ");
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void Printn(int position) {
	struct Node *current;
	struct Node *next = NULL;
	struct Node *prev = NULL;
    int i;

    current = head;
    if(position == 1){
    	printf("Data: ");
    	printf(" %d", current->data);
    	current = current->next;
    	printf(" Adjacent data: ");
    	printf(" Error");
    	printf(" %d\n", current->data);
	}
	else{
	    for(i = 0; i < position - 1 && current != NULL; i++){
	        current = current->next;
	        prev = current->prev;
	        next = current->next;
	    }
		
			printf("Data: ");
			printf(" %d", current->data);
			printf(" Adjacent data: ");
			if(prev != NULL){
				printf(" %d", prev->data);
			}
			else{
				printf(" Error ");
			}
			
			if(next != NULL){
				printf(" %d\n", next->data);
			}
			else{
				printf(" Error\n");
			}
		}
}


void count(){
	struct Node* temp = head;
	
	head->current = 1;
	for(int i = 0; i < NodeCount; i++){
		temp->current = temp->current + 1;
	}
}




int main() {
	head = NULL;
	int select, NewData, position, del_key;

	printf("1.Add data\n");
	printf("2.Delete data\n");
	printf("3.Print all data\n");
	printf("4.Print data n and adjacent data\n");
	
	while(1){
		scanf(" %d", &select);
		switch(select){
			case 1:
				printf("Input new data:");
				scanf(" %d", &NewData);
				InsertAtTail(NewData);
				break;
				
			case 2:
				printf("Input node you want to delete:");
				scanf(" %d", &del_key);
				deleteFromN(del_key);
				break;
			case 3:
				Print();
				break;
				
			case 4:	
				printf("Input a node #:");
				scanf(" %d", &position);
				//1count();
				if(position > NodeCount){
					printf("Node doesn't exist!\n");
				}
				else{
					Printn(position);
				}
		}
	}
	return 0; 
}
