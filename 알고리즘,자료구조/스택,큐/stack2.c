//
//  stack2.c
//  스택,큐
//
//  Created by SUNJAE on 2022/09/19.
//

#include "stack2.h"
//스택 구현
int top=-1; //스택의 맨 마지막 인덱스를 나타내는 전역변수
void Push(int a[],int n){ //데이터 n을 push
    if (top>9999){
        printf("스택이 꽉 찼습니다.\n");
        return;}
    else {
        a[++top]=n;
        return;}
    
}
void Pop(int a[]){ //배열에서 pop -> 인덱스 하나 감소
    if (top<0){
        printf("pop할 데이터가 없습니다\n");
        return;
    }
    else{
        top--; return;
    }
}

void Show(int a[]){ //스택 
    for (int i=0;i<top;i++){
        printf("%d\n",a[i]);
    }
}

int main(void){
    int N,n;
    int arr[10000];
    while (1) {
        printf("=======메뉴=======\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Show\n");
        printf("4. Exit\n");
        printf("입력:(1-4): "); scanf("%d",&N);
        
        if (N==1){
            printf("push할 값을 입력하세요: "); scanf("%d",&n);
            Push(arr,n);
        }
        else if (N==2){
            Pop(arr);
        }
        else if (N==3){
            Show(arr);
        }
        else if (N==4){
            printf("프로그램 종료"); break;
        }
    }
}
