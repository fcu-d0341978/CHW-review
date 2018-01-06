#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <ctype.h>

struct data{
	char letter[128];
	int line;
	int count;
};

int main(){
	FILE *fp;
	data word[128], wordtemp, proc[128];
	int line = 1, i = 0, j = 0, k, sum, count = 1;
	
	
	
		fp = fopen("input_for_hw1.txt","r");
	
	if (!fp) {
        printf("error...\n");
        exit(1);
    }
 
    while(fscanf(fp,"%c",&word[i].letter[j]) != EOF){                  //讀入字元 
    
    	if(word[i].letter[j] == '\n'){                                 //遇到換行的處理 
    		word[i].letter[j] = '\0';                   
    		word[i].line = line;
    		line++;
    		i++;
    		j = 0;
    		
    		
		}
		else if(word[i].letter[j] == ' '){                           //遇到空格的處理   
			word[i].line = line;
			word[i].letter[j] = '\0';
			i++;
			j = 0;
		
		}
		else{
			word[i].letter[j] = tolower(word[i].letter[j]);          //做小寫 
			j++;
		}
		
	}
	
	word[i].line = line;
	sum = i;
	
	for(i = 0; i < sum; i++){                                       //先把所有字串排序 
		for(j = i; j < sum + 1; j++){
			if(strcmp(word[i].letter,word[j].letter) > 0 ){
					wordtemp = word[i];
		     	    word[i] = word[j];
		     		word[j] = wordtemp;
		    }
        }
    }
    /*for(i = 0; i < sum + 1; i++){                                //測試用 
		printf("%s %d\n", word[i], word[i].line);
	}*/
	
	
	for(i = 0; i < sum ; i++){                                     //算出現次數 
		word[i].count = 1;
		for(j = i + 1; j <= sum ; j++){
			if(strcmp(word[i].letter,word[j].letter) == 0 ){
					word[i].count++;	
		}
		    else{
		    	break;
		}
    }
}
    for(i = 0; i < sum; i++){                                       //把重複的字串去掉,存進新的陣列 
			if(strcmp(word[i-1].letter,word[i].letter) != 0 ){
				strcpy(proc[i].letter, word[i].letter);
				proc[i].count = word[i].count;
				proc[i].line = word[i].line;
			}
			else{
				continue;
			}
	}
    printf("Word   count   line\n");                               // print
    printf("=====================\n");
    for(i = 0; i < sum + 1; i++){
		printf("%-6s  %-6d", proc[i].letter, proc[i].count);	
		if(proc[i].count > 1){
			printf("%d,%d\n", proc[i].line - 1, proc[i].line);
		}				
		else{
			printf("%d\n", proc[i].line);
		}
	}
}
