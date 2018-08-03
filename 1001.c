#include <stdio.h>

int main(void){
	int a, b;
	scanf("%d%d", &a, &b);
	
	if((0 < a && a < 10) && ((0<b && b < 10))){
		printf("%d\n", a-b);
	}
}
