//
//  main.c
//  구조체
//
//  Created by SUNJAE on 2022/01/26.
//

#include <stdio.h>
#define VMAX 21
typedef struct {
    int y,m,d;
} Date; //구조체 자료형 이름

int mdays[][12]={
    {31,28,31,30,31,30,31,31,30,31,30,31}, //평년
    {31,29,31,30,31,30,31,31,30,31,30,31} //윤년
};
int isleap(int year){ //윤년이면 1, 평년이면 0 반환
    return year %4==0 && year %100!=0 || year%400==0;
}
Date Before(Date x, int n);
Date After(Date x, int n); //함수 원형 선언

Date Dateof(int y,int m, int d){
    Date temp;
    temp.y=y;
    temp.m=m;
    temp.d=d;
    
    return temp;
    
}

Date After(Date x, int n){ //x일의 n일 뒤 반환
    if (n<0) return Before(x,-n);
    
    x.d+=n;
    while (x.d > mdays[isleap(x.y)][x.m-1]) { //다음 달로 넘어가는 경우, 일수가 해당 달의 최대 일수를 넘지 않을때까지 반복
        x.d-=mdays[isleap(x.y)][x.m-1];
        if (++x.m>12){ //전위 연산
            x.m=1;
            x.y++;
        }
    }
    return x;
}

Date Before(Date x, int n){ //x일의 n일 전 반환
    if (n<0)return After(x, -n);
    
    x.d-=n;
    while (x.d<=0) { //전 달로 넘어가는 경우
        if (--x.m<1){ //1월에서 12월로 넘어가는 경우 (1월->0월)
            x.m=12;
            x.y--;
            }
        // (--x.m>=1)인경우
        x.d+=mdays[isleap(x.y)][x.m - 1];
        }
    
    return x;
    
}



int main() {
 
        
    
    
    

    
    
    return 0;
}
