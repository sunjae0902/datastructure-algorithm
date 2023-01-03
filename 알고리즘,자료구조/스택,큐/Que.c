//
//  Que.c
//  스택,큐
//
//  Created by SUNJAE on 2022/02/21.
//

#include <stdlib.h>
#include <stdio.h>
#include "IntQueue.h"


int Initialize(IntQueue *q, int max){
    q->num=q->front=q->rear=0; //초기화
    if ((q->que=calloc(max,sizeof(int)))==NULL){
        q->max=0;
        return -1;
}
    q->max=max;
    return 0;
}

int Enque(IntQueue *q, int x){
    if(q->num>=q->max) return -1;
    else{
        q->num++; //개수 하나 증가
        q->que[q->rear++]=x; //데이터를 추가하고 rear에 다음 인덱스 저장
        if(q->rear==q->max) q->rear=0; return 0; //증가한 rear값이 max와 같아질 경우 0으로 변경.
    }
    
}

int Deque(IntQueue *q,int *x){
    if (q->num<=0) return -1;
    else{
        q->num--;
        *x=q->que[q->front++];
        if (q->front==q->max) q->front=0; return 0; //front값이 max와 같아질 경우 0으로 변경
    }
}

int PEEk(const IntQueue *q, int *x){
    if (q->num<=0) return -1;
    *x=q->que[q->front];
    return 0;
}

void Clear(IntQueue *q){
    q->num=q->front=q->rear=0;
    
}

int Capacity(const IntQueue *q){
    return q->max;
}
int size(const IntQueue *q){
    return q->num;
}
int IsEmpty(const IntQueue *q){
    return q->num<=0;
}

int IsFull(const IntQueue *q){
    return q->num==q->max;
}

int Search(const IntQueue *q,int x){
    int idx;
    for (int i=0;i<q->num;i++){
        if (q->que[idx=(i+q->front) % q->max]==x)  //처음 인덱스부터 검색 시작
            return idx;
    }
    return -1;
}

int Search2(const IntQueue *q,int x){
    
    for (int i=0;i<q->num;i++){
        if (q->que[(i+q->front) % q->max]==x)  //처음 인덱스부터 검색 시작
            return i;
    }
    return -1;
}

void Print(const IntQueue *q){
    int i;
    for (i=0;i<q->num;i++){
        printf("%d ",q->que[(i+q->front)% q->max]);
        
    }
    printf("\n");
}

void Terminate(IntQueue *q){
    if(q->que!=NULL) free(q->que);
    q->max=q->num=q->front=q->rear=0;
}

int main(){
    IntQueue q;
    
    if (Initialize(&q,64)==-1){
        printf("큐 생성 실패\n");
        return 1;
    }
    while (1) {
        int m,x;
        
        printf("현재 데이터 수: %d / %d\n",size(&q),Capacity(&q));
        printf("1.인큐 2.디큐 3.피크 4.출력 5.초기화 6.검색 7.가득찬/빈상태 0.종료:");
        scanf("%d",&m);
        
        if (m==0) break;
        switch(m){
        case 1:
            printf("인큐할 데이터:"); scanf("%d",&x);
            if (Enque(&q,x)==-1) printf("인큐 실패\n");
            break;
        case 2:
            if(Deque(&q,&x)==-1) printf("디큐 실패\n");
            else
                printf("디큐한 데이터는 %d입니다.\n",x);
            break;
        case 3:
                if(PEEk(&q,&x)==-1) printf("피크 실패\n");
                else
                    printf("피크한 데이터는 %d입니다\n",x);
                break;
        case 4:
                Print(&q);
                break;
        case 5:
                Clear(&q);
                break;
        case 6:
                printf("데이터:"); scanf("%d",&x);
            
                int idx1=Search(&q, x);
                int idx2=Search2(&q, x);
                if (idx1==-1 || idx2==-1) printf("검색 실패\n");
                else{
                    printf("검색한 데이터는 %d번째 요소에 있으며 맨 앞 인덱스에서 %d만큼 뒤에 있습니다.\n",idx1,idx2);
                }
                break;
                
        case 7:
                printf("큐가 비어 %s.\n",IsEmpty(&q) ? "있습니다":"있지 않습니다");
                printf("큐가 가득 %s.\n",IsFull(&q) ? "찼습니다":"차지 않았습니다");
                break;
                
       
        }
    }
    
    
    
    Terminate(&q);
    
    
    
    return 0;
}
