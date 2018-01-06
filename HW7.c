#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
	int num;
	struct Node* next;
	struct Node* down;
}Node;

Node* head = NULL;

Node* NewNode(int);
void print_a_list();
void print_all();
void sort();
void Input(int);

Node* NewNode(int num){
	Node* temp = (Node*)malloc(sizeof(Node));
	
	temp->num = num;
	temp->next = NULL;
	temp->down = NULL;
}

void Input(int num){
	Node* temp = head;
	int flag = 0, flag2 = 0;
	
	if(head == NULL){  
		head = NewNode(num%10);
		head->next = NewNode(num);
	}
	else{
		while(temp->down != NULL){   
			if(temp->num == (num%10)){  //浪琩琌籔headЮ计 
				flag = 1;  
				break;
			}
			temp = temp->down;  
		}
		if(temp->num == (num%10)){  //浪琩程琌籔headЮ计 
				flag = 1;
		}
		
		if(flag == 0){  //狦瓃常ぃ才 玥穝糤穝 
			temp->down = NewNode(num%10);
			temp = temp->down;
			temp->next = NewNode(num);
		}
		else if(flag == 1){  //璝Τ 
			
			while(temp->next != NULL){ 
				if(temp->num == num){  //浪琩计琌瞷筁 
					flag2 = 1;
					break;
				}
				temp = temp->next;
			}
			if(temp->num == num){ //浪琩计琌蛤程竊翴 
					flag2 = 1;
			}
				
			if(flag2 == 0){  //璝计⊿瞷筁 
				temp->next = NewNode(num);	
			}
			else{ //璝计瞷筁 
				printf("This number already exists\n\n");
			}
		}
	}
}

void print_a_list(Node* start){
	
	printf("%d", start->num);
	start = start->next;
	while(start != NULL){
		printf(" -> %d", start->num);
		start = start->next;
	}
	printf("\n");
}

void print_all(){
	Node* temp = head;
	
	if(temp == NULL){
		printf("No data!");
	}
	else{
		print_a_list(temp);
		temp = temp->down;
		while(temp != NULL){
			print_a_list(temp);
			temp = temp->down;
		}	
	}
}

void sort_a_list(){
	Node* temp1 = head; 
	Node* temp2 = head; 
	Node* temp3 = head;
	int tempnum;
	
	while(temp1 != NULL){
		temp2 = temp1;
		while(temp2 != NULL){
			temp3 = temp2;
			while(temp3 != NULL){
				if(temp2->num > temp3->num){
					tempnum = temp2->num;
					temp2->num = temp3->num;
					temp3->num = tempnum;
				}
				temp3 = temp3->next; 
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->down;
	}
}

void sort_all(){
	Node* temp1 = head; 
	Node* temp2 = head; 
	int tempnum;
	
	sort_a_list();
	
	while(temp1 != NULL){
		temp2 = temp1;
		while(temp2 != NULL){
			if(temp2->num < temp1->num){
				Node* temp = NULL;
				temp = (Node*)malloc(sizeof(Node));
				
				tempnum = temp2->num;
				temp->next = temp2->next;
				temp->down = NULL;
				
				temp2->num = temp1->num;
				temp2->next = temp1->next;
				
				temp1->num = tempnum;
				temp1->next = temp->next;
				free(temp);
			}
			temp2 = temp2->down; 
		}
		temp1 = temp1->down;
	}
}

int main(){
	int choice, num;
	
	srand(time(NULL));
	
	printf("Choose a function:\n");
	printf("(1)Create new random data\n");
	printf("(2)Print all data\n");
	printf("(3)Exit\n\n");
	
	while(1){
		scanf(" %d", &choice);
		printf("\n");
		
		switch(choice){
			case 1:
				num = (rand()%999)+1;
				Input(num);
				printf("The random input number is %d\n\n", num);
				break;
			case 2:
				sort_all();
				print_all();
				break;
			case 3:
				exit(0);
				break;
			default:
				printf("Invalid choice!\n\n");
				break;
		}
	}
	return 0;
}
