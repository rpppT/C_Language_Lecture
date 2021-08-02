#include <stdio.h>
#include <math.h>



int array[306];
int len = 306;
int possible_num_cnt = 0;

void resetCnt(){
  possible_num_cnt = 0;
}

void print_array(){
  for(int i = 0; i<len; i++)
    printf("%d " , array[i]);

  printf("===================================\n");

  return;
}

int primeOne(){ 
  int acc_result = 1;

  for(int i = 0; i<len; i++){
   while(1){
        if(acc_result*array[i] > 2021)
          break;
        else
          acc_result *= array[i];
        
           printf("소수 p= %d : 가능한 자연수 : %d \n",  array[i], acc_result);
        
           possible_num_cnt++;
    } 
    acc_result = 1;
  } 

  printf("가능한 자연수 개수 : %d\n", possible_num_cnt); 
  printf("==================================\n");

  return possible_num_cnt;
}

int primeTwo(){ 
  int result;

  for(int i = 0; i<len-1; i++){
    for(int j = i+1; j<len; j++){
        result = (array[i]) * (array[j]);
        if(result < (int)sqrt(2021)){
          printf("소수 p= %d : 소수 : q= %d : 가능한 수 :  %d\n",array[i], array[j], result*result);
          possible_num_cnt++;
        }
    } 
  } 

  printf("가능한 자연수 개수: %d\n", possible_num_cnt);
  printf("=================================\n"); 

  return   possible_num_cnt;
}  

int primeThree(){
  long double result1;
  long double result2;
  
  for(int i =0 ; i<len-2; i++)
    for(int j = i+1; j<len-1; j++)
      for(int k = j+1; k<len; k++){
        result1 = sqrt((array[i]*array[i])*(array[j]*array[j]*array[j])*array[k]);
        result2 = sqrt((array[i]*array[i]*array[i])*(array[j]*array[j])*array[k]);
        
        if(result1 <= sqrt(2021)) 
        { 
         printf("n의 구성 소수 : %d %d %d , 지수 => 2,3,1 가능한 수 : %d\n",array[i], array[j], array[k],(array[i]*array[i])*(array[j]*array[j]*array[j])*array[k]); 
         possible_num_cnt++; 
        }
        if(result2 <= sqrt(2021))
        { 
          printf("n의 구성 소수 : %d %d %d , 지수 => 3,2,1 가능한 수 : %d\n", array[i], array[j], array[k], (array[i]*array[i]*array[i])*(array[j]*array[j])*array[k]);
          possible_num_cnt++; 
        }

      }
  
  printf("가능한 자연수 개수 : %d\n", possible_num_cnt);

  return possible_num_cnt;
} 



int main(void){
  int array_index = 0;
  int compose_num_cnt = 0;
  int result = 0;

  for(int i = 2; i<=2021; i++){
     for(int j = 1; j<=i; j++){
        if(i % j == 0)
          compose_num_cnt++;
     } 
     if(compose_num_cnt == 2)
       array[array_index++] = i; 

     compose_num_cnt = 0;
  } 
  
  print_array();

  result += primeOne();
  resetCnt();
  result += primeTwo(); 
  resetCnt();
  result += primeThree(); 
   
  printf("\n");
  printf("%d/%d\n", 306,result);

  return 0;
}
