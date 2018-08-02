//
//  main.c
//  알고리즘
//
//  Created by rpp[t on 2018. 7. 31..
//  Copyright © 2018년 rppt. All rights reserved.
//

#include <stdio.h>

struct Magic_Square{
    int num[2][4];
    int input_num[2][4];
    
    void (*f_init_ptr)(int (*)[2][4]);
}square_var;

struct Magic_Square * square_ptr = &square_var;

void print(){
    int (*ptr_num)[2][4] = &(square_ptr->num);
    for(int i = 0; i<2; i++){
        for(int j =0; j<4; j++){
            printf("%d\t", (*ptr_num)[i][j]);
        }
        puts("");
    }
}

int compare(){
    for(int i =0; i<2; i++){
        for(int j =0; j<4; j++){
            if(square_ptr->num[i][j] != square_ptr->input_num[i][j])
                return -1;
        }
    }
    return 0;
}
void A(){
    int i =0, j = 0;
    
    for(i = 0 ; i<1; i++){
        for(j = 0; j<4; j++){
            int temp = square_ptr->num[1][j];
            square_ptr->num[1][j] = square_ptr->num[i][j];
            square_ptr->num[i][j] = temp;
        }
    }
}
void B(){
    int t1 = square_ptr->num[0][3];
    int t2 = square_ptr->num[1][3];
    
    for(int i =0 ; i<2; i++){
        for(int j = 4-1; j>0; j--){
            square_ptr->num[i][j] = square_ptr->num[i][j-1];
        }
        if(i == 0)
            square_ptr->num[i][0] = t1;
        else
            square_ptr->num[i][0] = t2;
    }
}

void C(){
    int temp_array[4];
    
    temp_array[0] = square_ptr->num[1][1];
    temp_array[1] = square_ptr->num[0][1];
    temp_array[2] = square_ptr->num[0][2];
    temp_array[3] = square_ptr->num[1][2];
    
    square_ptr->num[0][1] = temp_array[0];
    square_ptr->num[1][1] = temp_array[3];
    square_ptr->num[0][2] = temp_array[1];
    square_ptr->num[1][2] = temp_array[2];
}

void init(int (*ptr_num)[2][4]){
    int x = 1;
    for(int i = 0; i<2; i++)
        for(int j =0; j<4; j++)
            *(*((*ptr_num)+i)+j) = x++;
}

int main(int argc, const char * argv[]){
    square_ptr->f_init_ptr = init;
    square_ptr->f_init_ptr(&((*square_ptr).num));
    
    for(int i =0 ; i<2; i++){
        for(int j = 0; j<4; j++){
            fscanf(stdin, "%d", &(square_ptr->input_num)[i][j]);
        }
    }
    
//    while(compare() != 1){
//        A();
//        B();
//        C();
        print();
//    }
    return 0;
}

