#include <stdio.h>


//함수 포인터를 쓸 때 자료형을 괄호롤 묶으면 다른 게 됨ㅓ
void encrypt(char (*p_buf)[20] , int * len)
{
  int ascii_value = 0;
  int i;
  
  int x = 3;
  int p[x];
  char str_1[*len+1], str_2[*len+1];
  str_1[*len]= 0;
  str_2[*len] = 0;
 
 for(i = 0 ; i<*len; i++){
   str_1[i] = (char)((*p_buf)[i] + 2);
   str_2[i] = (char)(((*p_buf)[i] * 7 ) % 80 + 48);
  } 
 printf("%s\n%s\n", str_1, str_2);
}
int main(void)
{
  char buf[20];
  int i;

/*  fgets(buf, 20, stdin);
  for(i =0 ; i < 20; i++){
    if(buf[i] == ' ')
      return 0;
    if(buf[i] == 0)
      break;
  }
  */
  scanf("%s", buf);
  i = 0;

  while(buf[i++] != 0);
  i--;
 void (*fptr)(char(*)[20], int *) = encrypt;
 fptr(&buf, &i);
  return 0;
}
