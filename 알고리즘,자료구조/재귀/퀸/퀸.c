//
//  퀸.c
//  재귀
//
//  Created by SUNJAE on 2022/03/20.
//


#include <stdio.h>
#include "IntStack.h"

int flag_a[8]; //각 행에 퀸을 배치했는지 확인하는 배열
int flag_b[15]; //대각선 /에 퀸을 배치했는지 확인
int flag_c[15]; //대각선 \에 퀸을 배치했는지 확인
int pos[8]; //갹 열에서 퀸의 위치

void print(void){ //퀸의 위치를 출력하는 함수
    int i,j;
    
    for (j=0;j<8;j++){ //j열
        for (i=0;i<8;i++){ //i행
            if (pos[j]==i) printf("[*]");
            else printf("[ ]");
            
        }
        printf("%d",pos[j]);
        putchar('\n');
    }
    putchar('\n');
}


void set(int i){ //i열에서 알맞은 위치에 퀸 배치하는 함수
    int j;
    for (j=0;j<8;j++){
        if(!flag_a[j] && !flag_b[i+j] && !flag_c[i-j+7]) {//i열에 퀸이 배치되지 않았을 경우
            pos[i]=j;
            if (i==7) //모든 열애 배치를 마쳤을 경우
                print(); //출력
            else {
                flag_a[j]=flag_b[i+j]=flag_c[i-j+7]=1; //열에 퀸을 배치해야 하는 경우->값을 1로 변경
                set(i+1); //재귀 호출
                flag_a[j]=flag_b[i+j]=flag_c[i-j+7]=0; //퀸을 배치했으므로 다시 0대입
            }
        
        }
        
    }
    
}

void set2(int i){ //i열에서 알맞은 위치에 퀸 배치하는 함수->비재귀적으로 구현
    int j;
    IntStack jstk;
    Initialize(&jstk,8);
    
Start:
    while(1){ // 삼중 while문
        j=0;
        while(1){
            while(j<8){
                if (!flag_a[j] && !flag_b[i+j] && !flag_c[i-j+7])
            }
        }
        
    }
    
}



int main(void){
    int i;
    for (i=0;i<8;i++){
        flag_a[i]=0; //각 행 0으로 초기화
        }
    for (i=0;i<15;i++){
        flag_b[i]=flag_c[i]=0; //대각선
    }
    set(0);
    return 0;
}
