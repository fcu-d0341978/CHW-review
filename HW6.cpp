#include <stdio.h>
#include <stdlib.h>

typedef struct data{
    int coefficient;		//系數 
    int power;		        //次方 
    struct data *next;
}Data;

Data* poly_1;
Data* poly_2;
Data* addition;
Data* multiply;

Data* NewNode(int coefficient,int power) {
    Data* temp = (Data*) malloc(sizeof(Data));
    if(temp == NULL){
    	printf("Fail\n");
	}
	if(coefficient == 0){
		power = 0;
	}
    temp->coefficient = coefficient;
    temp->power = power;
    temp->next = NULL;

    return temp;
}

void NewNodeForPoly1(int coefficient,int power){
	Data* temp;
	
	temp = poly_1;
	if(poly_1 == NULL){
		poly_1 = NewNode(coefficient,power);
	}
	else{
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = NewNode(coefficient,power);
	}
} 

void NewNodeForPoly2(int coefficient,int power){
	Data* temp;
	
	temp = poly_2;
	if(poly_2 == NULL){
		poly_2 = NewNode(coefficient,power);
	}
	else{
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = NewNode(coefficient,power);
	}
} 

void NewNodeForAddition(int coefficient,int power){
	Data* temp;
	
	temp = addition;
	if(addition == NULL){
		addition = NewNode(coefficient,power);
	}
	else{
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = NewNode(coefficient,power);
	}
} 

void NewNodeForMultiply(int coefficient,int power){
	Data* temp;
	
	temp = multiply;
	if(multiply == NULL){
		multiply = NewNode(coefficient,power);
	}
	else{
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = NewNode(coefficient,power);
	}
} 

void PrintList(Data* temp){ 
	printf("%d", temp->coefficient);
	printf("X^%d", temp->power);
	temp = temp->next;
	while(temp != NULL){
		if(temp->coefficient < 0){
			printf("%d", temp->coefficient);
		} 
		else{
			printf("+%d", temp->coefficient);	
		}
		//if(temp->power != 0){
			printf("X^%d", temp->power);
		//}
		temp = temp->next;
	}
	printf("\n\n");
}

void sort(Data* sorted){
	Data* temp, box;
	int coefficient, power;
	
	while(sorted != NULL){
		temp = sorted->next;
		while(temp != NULL){
			if(temp->power > sorted->power){
				coefficient = sorted->coefficient;
				power = sorted->power;
				
				sorted->coefficient = temp->coefficient;
				sorted->power = temp->power;
				
				temp->coefficient = coefficient;
				temp->power = power;
			}
			else if(temp->power == sorted->power){
				sorted->coefficient = sorted->coefficient + temp->coefficient;
				temp->coefficient = 0;
			}
			temp = temp->next;
		}
		sorted = sorted->next;	
	}
}

void add(){
	Data* temp;
	
	temp = poly_1;
	while(poly_1 != NULL){
		NewNodeForAddition(poly_1->coefficient, poly_1->power);
		poly_1 = poly_1->next;
	}
	
	temp = poly_2;
	while(poly_2 != NULL){
		NewNodeForAddition(poly_2->coefficient, poly_2->power);
		poly_2 = poly_2->next;
	}
	sort(addition);
}

void multi(){
	int coefficient, power;
	
	while(poly_1 != NULL){
		while(poly_2 != NULL){
			coefficient = poly_1->coefficient * poly_2->coefficient;
			power = poly_1->power + poly_2->power;
			NewNodeForMultiply(coefficient, power);
			poly_2 = poly_2->next;
		}
		poly_1 = poly_1->next;
	}
	sort(multiply);
}

void deletNode(Data* temp){
	Data *temp_2, *temp_3;

	while(temp != NULL){
		if(temp->coefficient == 0 ){
			Data* temp_2 = temp;
			temp_3->next = temp->next;
			free(temp_2);
			temp = temp_3;
		}
		else{
			temp_3 = temp;
			temp = temp->next;
		}
	}
	
}
int main(){
	int coefficient, power, choice;
	
	printf("Please input the first polynomial(0 to end): \n");
	while(1){
		scanf(" %d", &coefficient);
		if(coefficient == 0){
			break;
		}
		else{
			scanf(" %d", &power);
			NewNodeForPoly1(coefficient, power);
		}
	}
	sort(poly_1);
	printf("Your input: \n");
	PrintList(poly_1);
	
	printf("Please input the second polynomial(0 to end): \n");
	while(1){
		scanf(" %d", &coefficient);
		if(coefficient != 0){
			scanf(" %d", &power);
			NewNodeForPoly2(coefficient, power);
		}
		else if(coefficient == 0){
			break;
		}
	}
	sort(poly_2);
	printf("Your input: \n");
	PrintList(poly_2);
	
	printf("Please choose your function:\n");
	printf("(1)Addition\n");
	printf("(2)Multiply\n");
	printf("(3)End\n");
	
	while(1){
		scanf(" %d", &choice);
		switch(choice){
			case 1:
				add();
				printf("Result:\n");
				deletNode(addition);
				PrintList(addition);
				break;
				
			case 2:
				multi();
				printf("Result:\n");
				deletNode(multiply);
				PrintList(multiply);
				break;	
			case 3:
				exit(0);
				break;
			default:
				printf("Wrong choice!");
		}
	}	
	return 0;
}





