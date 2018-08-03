#include <stdio.h>
#include <string.h>

int main(void){
	char buf[100] = {0, };
	fgets(buf, 100, stdin);
	
	int i = 0;
	int j;
	
	int acc =  0;
	
	
  if(strlen(buf)-1 >= 10){
	while(buf[i] != 0){
		if((i+1) % 10 == 0){
			for( j = i+1- 10; j <= i; j++)
				printf("%c", buf[j]);
		    	printf("\n");
		    acc = i;
		}
		i++;
	}
	if(i - acc== 1 || i - acc == 0 )
	   return 0;
	   
	for(j = acc; j < i; j++){
		printf("%c", buf[j]);
	}
	printf("\n");
  }else{
  	while(buf[i++] != 0){
  		printf("%c", buf[i-1]);
  }
  printf("\n");
}
  return 0; 
}
