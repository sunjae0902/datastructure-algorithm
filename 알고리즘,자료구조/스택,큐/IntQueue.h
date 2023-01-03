//
//  IntQueue.h
//  스택,큐
//
//  Created by SUNJAE on 2022/02/21.
//

#ifndef ___IntQueue
#define ___IntQueue

typedef struct{
    int max; //큐의 용량
    int num; //현재 데이터 수
    int front;
    int rear;
    int *que; //큐의 첫 요소에 대한 포인터
} IntQueue;

int Initialize(IntQueue *q, int max);
int Enque(IntQueue *q,int x);
int Deque(IntQueue *q,int *x);
int Peek(const IntQueue *q);
int Capacity(const IntQueue *q);
int IsEmpty(const IntQueue *q);
int IsFull(const IntQueue *q);
void Clear(IntQueue *q);
int Search(const IntQueue *q,int x);
int Search2(const IntQueue *q,int x);
void Print(const IntQueue *q);
void Terminate(IntQueue *q);


#endif /* IntQueue_h */
