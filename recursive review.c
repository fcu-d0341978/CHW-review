#include<stdio.h>
#include<stdlib.h>

void num(int a){
	if(a == 1)
	printf("1");
	else{
		num(a-1);
		printf("%d",a);
	}
}

int main(){
	int b;
	scanf("%d", &b);
	num(b);
	return 0;
}
