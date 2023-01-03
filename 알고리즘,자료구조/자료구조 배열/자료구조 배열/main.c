//
//  main.c
//  자료구조 배열
//
//  Created by SUNJAE on 2022/01/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h> //rand,srand,time함수 선언 헤드
#define swap(type,x,y) do {type t=x;x=y;y=t;} while(0) //함수 형식 매크로 do문으로. type형(자료형의 매개변수) x,y교환

int maxof(const int a[],int n){
    int max=a[0];
    for (int i=0;i<n;i++){
        if (max<a[i]) max=a[i];
    }
    return max;
}

void ary_reverse(int a[],int n){
    for (int i=0;i<n/2;i++) swap(int, a[i], a[n-i+1]);
}

int card_convr(unsigned x,int n, char d[]){ //정수 x를 n진수로 변환하여 d배열에 저장
    char dchar[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //dchar[0]='0'~dchar[35]='Z'로 저장됨(배열초기화)
    int digits=0;
    if (x==0)
        d[digits++]=dchar[0]; //정수가 0아면 변환 후에도 0저장
    else
        while (x) { //0이 아닌 경우:무한루프
            d[digits++]=dchar[x%n]; //n으로 나눈 나머지 저장
            x/=n;
        }

    return digits;
    
}

int mdays[][12]={
    {31,28,31,30,31,30,31,30,31,30,31,30,31}, //윤년x(0)
    {31,29,31,30,31,30,31,30,31,30,31,30,31}// 윤년(1)
}; //각 달의 날 수


int isleep(int year){//윤년
    return year%4==0 && year%100!=0 || year%400==0; //윤년이면 1반환 아니면 0반환
        
}

int dayofyear(int y,int m,int d){ //지난 날 수를 구하기
    while (--m) {
        d+=mdays[isleep(y)][m-1]; //달이 1씩 감소하면서(전위 연산) ..
}
}

int main(void) {
    //배열 a[5]의 요소 개수 구하기: sizeof(a)/sizeof(a[0])
    
    //calloc함수로 메모리 할당 (실패 시 NULL값 반환)
    int *x=calloc(1,sizeof(int));
    if (x==NULL) printf("메모리 할당 실패\n");
    else {
        *x=57; // 포인터가 가리키는 대상의 메모리에 57저장
        printf("*x=%d\n",*x);
    }
    free(x); //할당되었던 메모리 해제
    
    //int 형 배열의 동적 메모리 할당
    int i,n;
    printf("요소 개수:");
    scanf("%d",&n);
    int *a=calloc(n, sizeof(int));
    if (a==NULL) printf("메모리 할당 실패\n");
    else{
        printf("%d개의 정수를 입력하세요\n:",n);
        for (i=0;i<n;i++){
            printf("a[%d]: ",i);
            scanf("%d",&a[i]);
        }
        printf("각 요소의 값은 아래와 같음\n");
        for (i=0;i<n;i++){
            printf("a[%d]=%d\n",i,a[i]);
        }
        free(a);
        
    
    }
    
// 배열 요소의 최댓값을 구하는 maxof 함수
    int number;
    printf("사람 수:");
    scanf("%d",&number);
    int *height=calloc(number,sizeof(int)); //매개변수의 첫번째 요소, 사람들의 키 요소 number개를 배열로 저장해서 포인터에 저장
    printf("%d사람의 키를 입력하세요\n:",number);
    for (int i=0;i<number;i++){
        printf("height[%d]=",i);
        scanf("%d",&height[i]);
    }
    printf("요소 중 최댓값은 %d입니다\n",maxof(height,number));
    
    free(height);
    
    
    
    
//난수를 사용해 배열의 요솟값 설정하기
    /* 난수 생성 : rand,srand,time 함수
     * 환경마다 다른 seed값 기준으로 매번 같은 순서의 난수를 생성함. 0~RAND_MAX 범위.
     rand: 의사 난수 생성-> 다음 값을 예측가능
     srand: seed값 변경. srand(50); seed가 50으로 변경됨
     time:현재 시간 반환 함수
     srand에 매개변수(변경할 seed값)는 임의의 난수로 설정해야함-> 매개변수로 현재 시간의 값을 전달
    */
    int number2;
    printf("사람 수:");
    scanf("%d",&number2);
    int *height2=calloc(number2, sizeof(int));
    srand(time(NULL));
    
    for (int i=0;i<number2;i++){
        height2[i]=100+rand()%90; // 100-189사이의 의사 난수
    }
    printf("요소 중 최댓값은 %d입니다\n",maxof(height2,number2));
    
    free(height2);

/* 배열 요소 역순으로 정렬하기(원래 배열에서 반대로)-함수 형식 매크로 swap이용
 -교환횟수: 요소갯수/2번 교환 a[i]와 a[n-i+1]요소 교환
 -두 값을 교환하는 함수 형식 매크로 swap이 n/2번 호출됨 */
    int nx;
    printf("요소 개수:");
    scanf("%d",&nx);
    int *ox=calloc(nx, sizeof(int));//int형 배열을 포인터에 저장
    printf("%d개의 정수 입력\n",nx);
    for (int i=0;i<nx;i++){
        printf("ox[%d]=",i);
        scanf("%d",&ox[i]);
    }
    ary_reverse(ox, nx); //ox가 가리키는 배열의 요소들을 n/2번 교환 (swap함수 n/2번 호출)
    printf("배열의 요소들을 역순으로 정렬\n");
    for (int i=0;i<nx;i++) printf("ox[%d]=%d\n",i,ox[i]);
    
    free(ox);
    
//기수 변환
    unsigned no;//변환할 정수
    int cd,dno; //기수, 변환 후 자릿수
    char cno[512]; //변환한 값의 각 자리의 숫자를 저장한 배열
    int retry; //한번 더
    puts("10진수를 기수 변환 합니다");
    do { //외부 do문: 재시도할때마다 전체 반복
        printf("변환할 음이 아닌 정수:");
        scanf("%u",&no); //%u: unsigned 정수
    
        do { //내부 do문 : 2-36진수만 입력가능
            printf("어떤 진수로 변환할까요?:");
            scanf("%d",&cd);
        } while(cd<2||cd>36);
        
        dno=card_convr(no, cd, cno); //10진수 no를 cd진수로 변환
        printf("%d진수로는 ",cd);
        for (int i=dno-1;i>=0;i--) //윗자리부터 역순으로 출력
            printf("%c",cno[i]); //
        printf("입니다.\n");
        printf("한번 더?(1..예/0..아니오) :");
        scanf("%d",&retry);
    }while (retry==1);
    
//한 해의 지난 날 수를 계산하는 프로그램
    int year,month,day;
    int retry;
    do {
        printf("년: "); scanf("%d",&year);
        printf("월: "); scanf("%d",&month);
        printf("일: "); scanf("%d",&day);
        printf("%d년의 %d일째입니다.\n",year,dayofyear(year, month, day));
        printf("다시? (예:1 아니오:0)"); scanf("%d",&retry);
    } while (retry==1);
    
    

    
    

    
    

    

    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
