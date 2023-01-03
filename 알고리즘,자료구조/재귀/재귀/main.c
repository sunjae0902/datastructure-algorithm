//
//  main.c
//  재귀
//
//  Created by SUNJAE on 2022/03/06.
//

#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"


void Move(int no, int x, int y){ //원반 no개를 x에서 y로 (비재귀적)
    IntStack stk,xtk,ytk;
   
    Initialize(&stk,100);
    Initialize(&xtk,100);
    Initialize(&ytk,100);
    
Top:
    if (no>0){
        Push(&stk, no);
        Push(&xtk, x);
        Push(&ytk, y); //스택에 푸시(저장)
        
        no-=1; //no=no-1대입
        y=6-x-y;
        goto Top;
        
    }
    
    else if (no==1)
        printf("원반[%d]를 %d기둥에서 %d기둥으로 옮김\n",no,x,y);
        
    if (!IsEmpty(&stk)){
        Pop(&stk,&no);
        Pop(&xtk,&x);
        Pop(&ytk,&y);
        printf("원반[%d]를 %d기둥에서 %d기둥으로 옮김\n",no,x,y);
        no-=1;
        y=6-x-y;
        goto Top;
        
    }
    Terminate(&stk);
    Terminate(&xtk);
    Terminate(&ytk);
    

}




  
 





int main() {
    int n;
    scanf("%d",&n);
    Move(n, 1, 3);
return 0;
}
