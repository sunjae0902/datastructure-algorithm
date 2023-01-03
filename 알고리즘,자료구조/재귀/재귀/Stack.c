//
//  스택,큐.c
//  스택,큐
//
//  Created by SUNJAE on 2022/02/21.


#include "IntStack.h"
#include <stdio.h>
#include <stdlib.h>

int Initialize(IntStack *s,int max){
    s->ptr=0;
    if ((s->stk=calloc(max, sizeof(int)))==NULL){
        s->max=0;
        return -1;
    }
    s->max=max;
    return 0;
} //스택 초기화 함수. 배열을 위한 메모리 공간을 만들기 위해 스택을 비워놓아야 함.

int Push(IntStack *s,int x){
    if (s->ptr>=s->max) return -1;
    s->stk[s->ptr++]=x;
    return 0;
}
int Pop(IntStack *s, int *x){
    if (s->ptr<=s->max) return -1;
    *x=s->stk[--s->ptr];
    return 0;
}

int Peek(const IntStack *s,int *x){
    if (s->ptr<=0) return -1;
    *x=s->stk[s->ptr-1];
    return 0;
}

void Clear(IntStack *s){
    s->ptr=0;
}

int Capacity(const IntStack *s){
    return s->max;
}
int Size(const IntStack *s){
    return s->ptr;
}
int IsEmpty(const IntStack *s){
    return s->ptr<=0; //비었으면 1반환
}
int IsFull(const IntStack *s){
    return s->ptr>=s->max; //가득 찼으면 1반환
}
int Search(const IntStack *s,int x){
    int i;
    for (i=s->ptr-1;i>=0;i--){
        if (s->stk[i]==x) return i; //인덱스 반환, 꼭대기부터 검색
    }
    return -1; //실패시 -1반환
}
void Print(const IntStack *s){
    for (int i=0;i<=s->ptr-1;i++) printf("%d ",s->stk[i]);
        printf("\n");
    
}
void Terminate(IntStack *s){
    if (s->stk!=NULL) free(s->stk);
    s->max=s->ptr=0;
}

int main(){
    IntStack s;
    if (Initialize(&s,64)==-1){
        printf("스택 생성 실패\n");
        return -1;
    }
    
    while (1) {
        int menu,x;
        printf("현재 데이터 수: %d / %d\n",Size(&s),Capacity(&s));
        printf("1.푸시 2.팝 3.피크 4.출력 5.검사 6.초기화 7.빈/가득 찬 상태 0.종료: ");
        scanf("%d",&menu);
        
        if (menu==0) break;
        switch(menu){
            case 1:
                printf("푸시할 데이터: "); scanf("%d", &x);
                if (Push(&s, x)==-1) printf("푸시 실패\n");
                break;
            case 2:
                if (Pop(&s,&x)==-1) printf("팝 실패\n");
                else
                    printf("팝 데이터는 %d입니다.\n",x);
                break;
            case 3:
                if (Peek(&s,&x)==-1 )printf("피크 실패\n");
                else
                    printf("피크 데이터는 %d입니다\n",x);
                break;
            case 4:
                Print(&s);
                break;
            case 5:
                printf("검색할 데이터: "); scanf("%d",&x);
                if (Search(&s,x)==-1) printf("검색 실패\n");
                else{
                    int idx=Search(&s, x);
                    printf("검색한 요소는 배열의 %d번째 요소입니다\n",idx);}
                break;
            case 6:
                Clear(&s);
                break;
            case 7:
                printf("스택이 가득 %s.\n",IsFull(&s) ? "찼습니다":"차지 않았습니다");
                printf("스택이 비어 %s.\n", IsEmpty(&s) ? "있습니다":"있지 않습니다");
                break; //조건 수식 연산자
        }
       
            
            
    
    }
    
    
    
    Terminate(&s);
    


    

    return 0;
 
}

