//
//  deck.h
//  스택,큐
//
//  Created by SUNJAE on 2022/02/23.
//

#ifndef deck_h
#define deck_h

typedef struct {
    
    int *dec; //배열을 가리키는 포인터
    int max; //배열의 최대 용량
    int front; //맨 앞
    int rear; //맨 뒤
    int num; //데이터의 개수
   
}Deck;

#include <stdio.h>

int InitializeDeck(Deck *d,int max);
int FrontEnque(Deck *d,int x);
int FrontDeque(Deck *d,int *x);
int RearEnque(Deck *d,int x);
int RearDeque(Deck *d,int *x);
#endif /* deck_h */
