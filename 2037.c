#include <stdio.h>


int list[100];

int main(void)
{
  int n, x;
  int index = 0;

  int (*list_p)[100] = &list;

  scanf("%d", &n);
  
  if(1<= n && n <= 1000)
  {
    for(x = n; ; x++ )
    {
      double t = (double)x/n;

    if(t < 1 || t >=2)
        break;


        (*list_p)[index++] = x;
    }

  for(int y = 0 ; y < n; y++)
    for(x = 0 ; x < index - 2; x++){
       int temp = (*list_p)[x];
       
       if((*list_p)[x] > (*list_p)[x+1])
       {
         (*list_p)[x] = (*list_p)[x+1];
         (*list_p)[x+1] = temp; 
       }
     }
 
  if(index == 1){
    printf("{%d}\n", (*list_p)[0]);
    return 0;
  }

   for(int i  = 0 ; i<index; i++){
     if(i == 0){
        printf("{%d, ", (*list_p)[i]);
     }else if(i == index - 1)
     {
       printf("%d}\n" , (*list_p)[i]);
     }else{
       printf("%d, ", (*list_p)[i]);
     }
   }
  }
}
