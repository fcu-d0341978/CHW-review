#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    Node* next;
};

/*Declare lists*/
Node* head1 = NULL;
Node* head2 = NULL;
Node* Add = NULL;

Node* NewNode(int Newdata){    //Create new node 
	Node* temp = (Node*) malloc(sizeof(Node));
	
	temp->data = Newdata;
	temp->next = NULL;
	return temp;
}

void reverseHead1(){  //Function to reverse Head1
    Node* prev = NULL;
    Node* current = head1;
    Node* next = head1->next;
    if(head1 == NULL || head1->next == NULL){
    	
	}
	else{
		while (next != NULL){
        current->next = prev;  
        prev = current;   
        current = next;
        next = next->next;
    	}
    	current->next = prev;
    	head1 = current;
	}
}

void reverseHead2(){  //Function to reverse Head2
    Node* prev = NULL;
    Node* current = head2;
    Node* next = head2->next;
    if(head2 == NULL || head2->next == NULL){
    	
	}
	else{
		while (next != NULL){
        current->next = prev;  
        prev = current;   
        current = next;
        next = next->next;
    	}
    	current->next = prev;
    	head2 = current;
	}
}

void reverseAdd(){  //Function to reverse Add
    Node* prev = NULL;
    Node* current = Add;
    Node* next = Add->next;
    if(Add == NULL || Add->next == NULL){
    	
	}
	else{
		while (next != NULL){
        current->next = prev;  
        prev = current;   
        current = next;
        next = next->next;
    	}
    	current->next = prev;
    	Add = current;
	}
}

void createHead1(int Newdata){  //Function to create head1
	
    Node* temp; 
    temp = head1;
    
    if(head1 == NULL){
    	head1 = NewNode(Newdata);
	}
	else{
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = NewNode(Newdata);
	}
}

void createHead2(int Newdata){  //Function to create head2
	
    Node* temp; 
    temp = head2;
    
    if(head2 == NULL){
    	head2 = NewNode(Newdata);
	}
	else{
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = NewNode(Newdata);
	}
}

void createAdd(int Newdata){  //Function to create Add
	
    Node* temp; 
    temp = Add;
    
    if(Add == NULL){
    	Add = NewNode(Newdata);
	}
	else{
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = NewNode(Newdata);
	}
}

void addition(){  //Addition (there's bug in it, not enough time to finish)
	Node* temp1 = head1;
	Node* temp2 = head2;
	Node* temp3 = Add;
	int newDigit, carry = 0;
	int size1 = sizeof(head1);
	int size2 = sizeof(head2);
	
	for(int i = 0; i < 3; i++){
		newDigit = carry + temp1->data + temp2->data;
		if(newDigit >= 10){
			newDigit = newDigit - 10;
			carry = 1;
			createAdd(newDigit);
		}
		else{
			createAdd(newDigit);
			carry = 0;
		}
		temp1 = temp1->next;
		temp2 = temp2->next;
		temp3 = temp3->next;
	}
}

void printAdd(){  //Print
	struct Node* temp = Add;
	
	if(Add == NULL){
	
	}
	while(temp != NULL){
        printf("%d ", temp->data); 
		printf(" ");   
        temp = temp->next;  
    }
}

void printList(Node* head){  //Print
    struct Node* temp = head;
    
    while(temp != NULL){
        putchar(temp->data); 
		printf(" ");   
        temp = temp->next;  
    }
}    

int main(){
    int digit;
  
    while(digit != 10){         //when typed in "Enter", break
    	digit = getchar();      //get every number one by one
    	createHead1(digit);
	}     
	
    printf("Entered number(linked list)\n");
	printList(head1);    
    reverseHead1();             //reverse for addition use       
     
	printf("\n\n");
	
	digit = -1;					//set to -1 or it will never do the next while loop
	
	while(digit != 10){
    	digit = getchar();      //when typed in "Enter", break
    	createHead2(digit);     //get every number one by one
	}      
	
	printf("Entered number(linked list)\n");
	printList(head2);    
    reverseHead2();             //reverse for addition use 
	
	addition();     
	printf("Added number(linked list)\n");
	reverseAdd();
	printAdd(); 
	     
    
}
