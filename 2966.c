#include <stdio.h>
#include <string.h>

int a, b, c;
int n;
char buf[100];

void first(){
   char letter[] = {'A', 'B', 'C'};
   int index = 0;

  for(int i =0; i<n; i++){
     if(letter[index++] == buf[i]){
       a++;
     }
     if(index == 3){
       index =0;
     }
  }
}

void second(){
   char letter[] = {'B', 'A', 'B', 'C'};
   int index = 0;

   for(int i =0; i<n; i++){
     if(letter[index++] == *(buf + i)){
      b++;
     }
     if(index == 4)
      index = 0; 
   }
}

void third(){
  char letter[] = {'C', 'C', 'A','A', 'B', 'B'};
  int index = 0;
   for(int i =0; i<strlen(buf); i++){
     if(letter[index++] == *(buf + i)){
       c++;
     }
     if(index == 6)
      index = 0; 
   }
}
int main(void){
  fscanf(stdin, "%d", &n);
  getchar(); 
  fgets(buf, n+1, stdin);
  first();
  second();
  third();
//  printf("%d\n", a);
 // printf("%d\n", b);
 if(a > b && a >c) {
   printf("%d\n", a);
   printf("Adrian\n");
 }
 else if(b> a && b > c){
   printf("%d\n", b);
   printf("Bruno\n");
 }
 else if(c > a && c >b){
   printf("%d\n", c);
   printf("Goran\n");
 }
 else if(a == b && a > c){
   printf("%d\n", a);
   printf("Adrian\n");
   printf("Bruno\n");
 }else if(a ==  c && a > b){
   printf("%d\n", a);
   printf("Adrian\n");
   printf("Goran\n");
 }else if(b == c && b > a){
   printf("%d\n", b);
   printf("Bruno\n");
   printf("Goran\n");
 }else if(a == b && a == c){
   printf("%d\n", b);
   printf("Adrian\n");
   printf("Bruno\n");
   printf("Goran\n");
 }
}
