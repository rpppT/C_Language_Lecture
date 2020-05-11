#include <stdio.h>

int main(void){
	int result = 0;
	int i, j;
	int n = 0;
	int check = 1;
	int array[13];
	int b = 0;
	int p = 0;
	
	for(i = 1; i<18; i++){
		result = (i*i)*(290-i*i);
		array[i-1]= result;
		int k = 0;
		while(1){
			k++;
			if(k*k > result){
				break;
			}
		}
		for(j =1 ; j<k; j++){
			if(j*j == result){
				n++;
				check = 0;
			}	
		}
		if(check)
		printf("%d * %d = %d\n", i*i, 290-i*i, result);
		else
		printf("Á¦°ö¼ö : %d * %d = %d, Á¦°ö±Ş = %d\n", i*i, 290-i*i, result,k-1);	
		check = 1;
	}
	for(i = 0; i<12; i++){
		if(array[i] >= array[i+1]){
			b = array[i];		
		}else{
			b = array[i+1];
		}
	}
	p = 17 -n;
	printf("count : %d\n", n);
	
	printf("p : %d\n", p);
	printf("b : %d\n", b);
	printf("´ä : %d\n", b/((p-1)*(p-1)));
	return 0;	
}
