#include<stdio.h>
#include<stdlib.h>

void bubble(int number[]) {

    
    int i = 0, j = 0;
    int temp = 0;

    for( i = 0; i < 4; i++) {
        for( j = i; j < 4; j++) {
            if( number[j] > number[i] ) {
                temp = number[j];
                number[j] = number[i];
                number[i] = temp;
            }
        }
    }

    /*for( i = 0; i < 4; i++ ) {
        printf("%d ", number[i]);
    }*/
}
int main(){
	FILE *ptr;
	int   inf[3],i, j, mid, final, num, miss;
	float avg, pavg, classavg,fclassavg;
	char name[10];
	
	
	ptr = fopen("inputex.txt", "r");
	
	if(!ptr){
		printf("Error");
		exit(1);
	}
	else{
	printf("座號  姓名  總成績\n");
	for( j = 0 ; j < 6 ; j++ ){
		fscanf(ptr, "%d %s %d %d %d %d %d %d %d", &num, name, &miss, &inf[0], &inf[1], &inf[2], &inf[3], &mid, &final);	
		//printf("%d %s %d %d %d %d %d %d %d\n",num, name, miss, inf[0], inf[1], inf[2], inf[3], mid, final);
		bubble(inf);
	    //printf("%d %s %d %d %d %d %d %d %d\n",num, name, miss, inf[0], inf[1], inf[2], inf[3], mid, final);
	    if(miss == 0){
	    	avg = (float)(inf[0] + inf[1]) / 2;
		}
		else if(miss == 1){
	    	avg = (float)(inf[0] + inf[1] + inf[2]) / 3;
		}
		else {
	    	avg = (float)(inf[0] + inf[1] + inf[2] + inf[3]) / 4;
		}
		pavg = (float)avg * 0.3 + mid * 0.3 + final * 0.4;
		classavg = classavg + pavg;
		
		printf("%-5d %-5s %-5.2f\n",num, name, pavg);
	}
	fclassavg = classavg / 6;
	printf("班平均: %.2f",fclassavg);
}
}
