//
//  main.c
//  sort
//
//  Created by SUNJAE on 2022/03/31.
//

#include <stdio.h>
#include <stdlib.h>
#define swap(type,x,y) do {type t=x; x=y; y=t;} while (0)

void bubble(int a[], int n){ //버블 sorting-오름차순 정렬
    int i,j;
    
    for (i=0;i<n-1;i++){
        for (j=n-1;j>i;j--){
            if (a[j-1]>a[j])
                swap(int, a[j-1], a[j]);
        }
    }
}

//q1
void bubble1(int a[], int n){
    int i,j;
    
    for (i=0;i<n-1;i++){
        for (j=1;j<n-i+1;j++){
            if (a[j-1]>a[j])
                swap(int,a[j-1],a[j]);
        }
    }
}

//q2

void bubble2(int a[],int n){
    int i,j,m;
    int cnt1=0,cnt2=0;
    for (i=0;i<n-1;i++){
        printf("패스%d:\n ",i+1);
        for (j=n-1;j>i;j--){
            for (m=0;m<n-1;m++){
                printf("%3d %c",a[m],(m!=j-1)? ' ':(a[j-1]>a[j])? '+':'-'); //중첩 삼항 연산자
            }
            printf("%3d\n",a[n-1]);
            cnt1++; //비교횟수 증가
            
            if(a[j-1]>a[j]){
                cnt2++; //교환횟수 증가
                swap(int, a[j-1], a[j]);            }
            
            
        }
        for (m=0;m<n;m++){
            printf("%3d ",a[m]);
        }
        printf("\n");
    
        
        
        
       
        
    }
}
void bubble3(int a[],int n){ //알고리즘 개선. 멈춤이용
    int i,j;
    for (i=0;i<n-1;i++){
        int exch=0;
        for (j=n-1;j>i;j--){
            if (a[j-1]>a[j]){
                swap(int, a[j-1], a[j]);
                exch++;
            }
            
        }
        if (exch==0) break;
    }
    
}

int is_sorted(const int a[],int n){ // q4 검사하는 함수
    int i;
    for(i=0;i<n-1;i++){
        if(a[i]<a[i+1]) return 1;
    }
    return 0;
    
}
//q4
void bubble4(int a[],int n){ //알고리즘 개선. 멈춤이용, 출력
    int i,j,m,cnt1=0,cnt2=0;
    for (i=0;i<n-1;i++){
        printf("패스%d:\n",i+1);
        int exch=0;
        
        for (j=n-1;j>i;j--){
            for (m=0;m<n;m++){
                printf("%3d %c",a[m],(m!=j-1) ? ' ': (a[j-1]>a[j]) ? '+':'-');
            }
            printf("\n");
            cnt1++;
            if (a[j-1]>a[j]){
                swap(int, a[j-1], a[j]);
                exch++;
            }
            
        }
        if (exch==0) break;
        else cnt2+=exch;
        for (m=0;m<n;m++) printf("%3d  ",a[m]);
        printf("\n");
    }
    printf("비교를 %d회 했습니다\n",cnt1);
    printf("교환을 %d회 했습니다\n",cnt2);
    
}


    




int main() {
   
    int i,nx;
    int *x;
    printf("요소 개수:");
    scanf("%d",&nx); //배열 요솟수 입력받기
    x=calloc(nx,sizeof(int)); //메모리 동적 할당
    
    for (i=0;i<nx;i++){
        printf("x[%d]=",i);
        scanf("%d",&x[i]); //배열 요소 입력 받기
    }
    
    
    
    puts("오름 차순 정렬 완료");
    bubble4(x, nx);
    is_sorted(x, nx);
    //for (i=0;i<nx;i++)
        //printf("x[%d]=%d\n",i,x[i]);
    
    free(x);

    
    
    
    
    
    
    return 0;
}
