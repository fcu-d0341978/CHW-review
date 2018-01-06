#include<stdio.h>
#include<stdlib.h>
struct data{
	char id[9];
	int english;
	int math;
}*student;

void sort_output(int size){
	int i, j;
	data temp;
	FILE *writeEnglish, *writeMath;
	
	writeEnglish = fopen("english.txt", "w");
	writeMath = fopen("math.txt", "w");
	
	for(i = 0; i < size - 1; i++){
		for(j = i; j < size - 1; j++){
			if(student[i].english < student[j].english){
				temp = student[i];
				student[i] = student[j];
				student[j] = temp;
			}
		}
		fprintf(writeEnglish, "%s %d\n", student[i].id, student[i].english);
	}
	fclose(writeEnglish);
	
	for(i = 0; i < size - 1; i++){
		for(j = i; j < size - 1; j++){
			if(student[i].math < student[j].math){
				temp = student[i];
				student[i] = student[j];
				student[j] = temp;
			}
		}
		fprintf(writeMath, "%s %d\n", student[i].id, student[i].math);
	}
	fclose(writeMath);
}

int main(){
	FILE *ptr;
	int i, size = 0;
	
	student = (data*)malloc(sizeof(data)*30);
	ptr = fopen("input_2.txt", "r");
	
	i = 0;
	while(ptr){
		fscanf(ptr, "%s %d %d", &student[i].id, &student[i].english, &student[i].math);
		i++;
		size++;
		if(feof(ptr)) break;
    }
    /*for(i = 0; i < 5; i++){
		printf("%s %d %d\n", student[i].id, student[i].english, student[i].math);
    }*/
    sort_output(size);
    return 0;
}
