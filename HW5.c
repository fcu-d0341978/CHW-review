#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

struct data{
	char name[9];
	int calculas;
	int comp;
	double avg;
};

void bubblesort(struct data student[20]){ //Sort
	int i, j;
	struct data temp;
	
	for(i = 0; i < 20; i++){
		for(j = i; j < 20; j++){
			if(student[i].avg < student[j].avg){
				temp = student[i];
				student[i] = student[j];
				student[j] = temp;
				/*temp.avg = student[i].avg; 
				student[i].avg = student[j].avg;
				student[j].avg = temp.avg;
				
				temp.calculas = student[i].calculas;
				student[i].calculas = student[j].calculas;
				student[j].calculas = temp.calculas;
				
				temp.comp = student[i].comp;
				student[i].comp = student[j].comp;
				student[j].comp = temp.comp;
				
				strcpy(temp.name, student[i].name);
				strcpy(student[i].name, student[j].name);
				strcpy(student[j].name, temp.name);*/
			}
		}
	}
}

int main(){
	struct data student[20];
	int i, j;
	
	srand(time(NULL));
	for(i = 0; i < 20; i++){
		for(j = 0; j < 9; j++){
			if(j == 8) {
			student[i].name[j] = '\0';
			}
			else student[i].name[j] = (rand() % 26) + 65; //Name
    	}
    	
    	student[i].calculas = (rand() % 100) + 1; //score
    	student[i].comp = (rand() % 100) + 1; //score
    	student[i].avg = (student[i].calculas + student[i].comp) / (double)2; //average
	}
	
	printf("Original data:\n");
	printf("Name     Calculas   Computer   Average:\n");
	
	for(i = 0; i < 20; i++){
		printf("%-8s %-10d %-10d %-6.1lf\n", student[i].name, student[i].calculas, student[i].comp, student[i].avg);
	}
	
	bubblesort(student);
	printf("\n");
	printf("Sorted data:\n");
	printf("Name     Calculas   Computer   Average:\n");
	
	for(i = 0; i < 20; i++){	
		printf("%-8s %-10d %-10d %-6.1lf\n", student[i].name, student[i].calculas, student[i].comp, student[i].avg);
	}
	
	return 0;
}
