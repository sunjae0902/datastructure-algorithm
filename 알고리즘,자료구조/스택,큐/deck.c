//
//  deck.c
//  스택,큐
//
//  Created by SUNJAE on 2022/02/23.
//

#include "deck.h"
#include <stdio.h>
#include <stdlib.h>

int InitializeDeck(Deck *d, int max){
    d->num=d->front=d->rear=0;
    if(d->dec=calloc(max, sizeof(int))==NULL) return -1;
    d->max=max;
    return 0;
}

int FrontEnque(Deck *d,int x){
    if (d->num>=d->max)  return -1;
    else{
        d->num++;
        
        if (--d->front<0) d->front=d->max-1; //front에 데이터를 인큐하면 front값은 1감소함..
        d->dec[d->front]=x;
        return 0;
    }
}
int RearEnque(Deck *d,int x){
    if (d->num>=d->max) return -1;
    else{
        d->num++;
        if (++d->rear>=d->max) d->rear=0;
        d->dec[d->rear]=x;
        return 0;
    }
}

int FrontDeque(Deck *d,int *x){
    if(d->num<=0)return -1;
    else{
        d->num--;
        if(++d->front>=d->max) d->front=0;
        *x=d->dec[d->front];
        return 0;
    }
}

int RearDeque(Deck *d,int *x){
    if(d->num<=0)return -1;
    else{
        d->num--;
        if(--d->rear<0) d->rear=d->max-1;
        *x=d->dec[d->rear];
        return 0;
    }
}


