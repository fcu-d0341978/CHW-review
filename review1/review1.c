#include<stdio.h>
#include<string.h>

int main(){
	FILE *ptr;
	char buffer[512], word[256];
	ptr = fopen("input.txt","r");
	scanf("%s", word);
	
	while(1){
		if(feof(ptr)){
			printf("No!");
			break;
		}
		fscanf(ptr,"%s",buffer);	
		if(strstr(buffer, word)){
			printf("Yes!");
			break;
		}
	}
	fclose(ptr);							
	
	
	return 0;
}
