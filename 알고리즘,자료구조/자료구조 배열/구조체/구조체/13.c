//
//  13.c
//  구조체
//
//  Created by SUNJAE on 2022/01/27.
//

#include <stdio.h>

typedef struct {
    int y;
    int m;
    int d;
    
} Date;


Date DateOf(int y,int m,int d){ //y년 m월 d일을 나타내는 구조체를 반환하는 함수
    printf("%d년 %d월 %d일\n",y,m,d);
    

}

int main(void){
    
    Date x[]={
        {}
    }
    
    
    
    return 0;
}

