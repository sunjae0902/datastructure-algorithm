//
//  스택,큐.h
//  스택,큐
//
//  Created by SUNJAE on 2022/02/21.
//

#ifndef _________IntStack
#define _________IntStack

#include <stdio.h>
typedef struct {
    int max; //스택의 최대 용량. 배열 요소의 개수와 같음
    int ptr; //스택 포인터. 스택에 쌓인 데이터의 개수를 나타냄
    int *stk; //스택으로 사용할 배열을 가리키는 포인터
} IntStack;


int Initialize(IntStack *s, int max);
//
int Push(IntStack *s, int x);
//
int Pop(IntStack *s, int *x);
//
int Peek(const IntStack *s, int *x);
//
void Clear(IntStack *s);
//
int Capacity(const IntStack *s);
//
int Size(const IntStack * s);

int IsEmpty(const IntStack * s);

int IsFull(const IntStack * s);
int Search(const IntStack * s, int x);

void Print(const IntStack * s);

void Terminate(IntStack * s);


#endif /* _________h */
