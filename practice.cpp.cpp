#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, n, end, start, sum;
	
	scanf("%d %d", &start, &end);
	
	for(i = start; i <= end; i++){
		sum = 0;
		for(n = start; n < i; n++){
				if(i % n == 0){
					sum = sum + n;
				}
		}	
		if(sum == i){
			printf("%d ", i);
		}
	}
	printf("\n");
	return 0;
}
