#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int *lottorng(){                                                  //RNG
	int *random, i;
	random = (int*)malloc(sizeof(int)*7);
	
	srand(time(NULL));
	for(i = 0; i < 7; i++){
	random[i] = (rand() % 43) + 1;
    }
	return random;
}

void checkprize(int *num, int *random){
	FILE *fp;
	char index;
	int  i, j, k, count = 0, special = 0 ;
	
	if(random[1] == 0){
		printf("Error!");
	}
	
	
	else{
	
	
	for(i = 0; i < 6; i++){                                     //check number
	    for(j = 0; j < 7; j++){
	    	if(random[i] == num[j]){
	    		count++;
			}
		}
	}
	for(i = 0; i < 6; i++){                                     //check special number
		if(random[6] == num[i])  {
			special = 1;
		}
	}
	
	if((count == 0) || (count == 1) || (count == 2)){           
		printf("  Lotto level : non\n");
	}
	else if ((count == 3) && (special == 0)){                  
		printf("  Lotto level : 7th\n");
	}                    
	else if ((count == 3) && (special == 1)){                                     
		printf("  Lotto level : 6th\n");
	}                    
	else if ((count == 4) && (special == 0)){                 
		printf("  Lotto level : 5th\n");
	}                    
	else if ((count == 4) && (special == 1)){                  
		printf("  Lotto level : 4th\n");
	}                    
	else if ((count == 5) && (special == 0)){                  
		printf("  Lotto level : 3rd\n");
	}                    
	else if ((count == 5) && (special == 1)){                  
		printf("  Lotto level : 2nd\n");
	}                    
	else if ((count == 6) && (special == 0)){                 
		printf("  Lotto level : 1st\n");
	}            
	
	
	/*for(i = 0; i < 7; i++){                                     //test 
		printf("%d. %02d %d\n", i + 1, *(random + i), *(num + i));
}*/ 
}
}

void write(int *num, int index, FILE *fp){                   //output
	char filename[128];
	int i;
	
	fprintf(fp, ">>No.%d : %02d,%02d,%02d,%02d,%02d,%02d\n", index, num[0], num[1], num[2], num[3], num[4], num[5]);	
	fclose(fp);
}


int main(){
	int choice, i, *random, *num;
	FILE *fp, *fptr;
	char filename[128], index;
	random = (int*)malloc(sizeof(int)*7);
	num = (int*)malloc(sizeof(int)*6);
    
	printf("FCU lotto Machine\n");
	printf("   [1]Lotto No.\n");
	printf("   [2]Check file\n");
	printf("   [3]Output result\n");
	do{
	printf("   Choose function:");

	scanf("%d", &choice);

	
	
	if(choice == 1){                         //1 
	    random = lottorng();                   
		printf("\n");
		
		
		printf("   Lotto No.: ");
	for(i = 0; i < 6; i++){
		printf("%02d, ", random[i]);
	}
	    printf("  Special No.: %d\n", random[6]);
		printf("   [1]Lotto No.\n");
	    printf("   [2]Check file\n");
	    printf("   [3]Output result\n");
	}
	
	else if(choice == 2){                   //2 
		printf("File name:");
		scanf("%s", filename);
		if((fp = fopen(filename, "r")) == NULL){
			printf("Error!\n");
		}
		else{
			
			for(i = 0; i < 6; i++){
				fscanf(fp, "%d.%d,%d,%d,%d,%d,%d", &index, &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
				printf(">>No.%d : %02d,%02d,%02d,%02d,%02d,%02d", index, num[0], num[1], num[2], num[3], num[4], num[5]);
				checkprize(num, random);
				printf("\n");
			}
		}
		fclose(fp);
		printf("   [1]Lotto No.\n");
	    printf("   [2]Check file\n");
	    printf("   [3]Output result\n");
        printf("\n");
	}
	
	else if(choice == 3){               //3 
		printf("File name:");
	    scanf("%s", filename);
	    fptr = fopen(filename, "w+");
	    if(num[1] == 0){
			printf("Error!\n");
		}
	    else{
		
	    fprintf(fptr, "Lotto No.: %02d,%02d,%02d,%02d,%02d,%02d", random[0], random[1], random[2], random[3], random[4], random[5]);
		fprintf(fptr, "  Special No.: %02d\n", random[6]);
	for(i = 0; i < 6; i++){
		fscanf(fptr, "%d.%d,%d,%d,%d,%d,%d", &index, &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
		//printf(">>²Ä%d²Õ¸¹½X : %02d,%02d,%02d,%02d,%02d,%02d\n", index, num[0], num[1], num[2], num[3], num[4], num[5]);
		write(num, index, fptr);
		printf("\n");
	}
}
	fclose(fptr);
	    printf("   [1]Lotto No.\n");
	    printf("   [2]Check file\n");
	    printf("   [3]Output result\n");
    printf("\n");
	}
	
	
}while((choice == 1) || (choice == 2) || (choice == 3));
    
	return 0;
}
