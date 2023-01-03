//
//  연습.c
//  2
//
//  Created by SUNJAE on 2022/01/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(type,x,y) do {type t=x;x=y;y=t;} while(0)
//자료구조_배열_Q1~11
int maxof(const int a[],int n){
    int max=a[0];
    for (int i=0;i<n;i++)
        if (max<a[i]) max=a[i];
    return max;
}

int minof(const int a[],int n){
    int min=a[0];
    for (int i=0;i<n;i++)
        if (min>a[i]) min=a[i];
    return min;
}
int sumof(const int a[],int n){
    int sum=0;
    for (int i=0;i<n;i++){
        sum+=a[i];
    }
    return sum;
}
double aveof(const int a[],int n){
    double sum=0.0;
    for (int i=0;i<n;i++){
        sum+=a[i];
    }
    
    return sum/n;
}
void ary_print( const int a[],int n){ //매개변수 선언 시 const: 함수내에서 읽기전용. 쓸수없음
    for (int i=0;i<n;i++)
        printf("%3d ",a[i]);
    printf("\n");
    
}

void ary_reverse(int a[],int n){
    for (int i=0;i<n/2;i++){
        ary_print(a, n);
        printf("a[%d]와 a[%d]를 교환합니다.\n",i,n-i-1);
        swap(int,a[i],a[n-i-1]);
    }
    ary_print(a,n);
    
}

int card_convr(unsigned x,int n,char d[]){
    char dchar[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int digits=0;
    if (x==0) d[digits++]=dchar[0];
    else
        while(x){
        d[digits++]=dchar[x%n]; //나머지 값에 해당하는 dchar배열 값 저장
        x=x/n; //x에 n으로 나눈 몫 저장
            
    }
    // 윗저리부터 저장하는 함수-> swap함수로 역순 정렬
    for (int i=0;i<digits/2;i++){
        swap(char,d[i],d[digits-i-1]);
    }
    return digits;
}

void ary_copy(int a[],const int b[],int n){
    for (int i=0;i<n;i++){
        a[i]=b[i];
    }
}

void ary_rcopy(int a[],int const b[],int n){
    for (int i=0;i<n;i++){
        a[i]=b[n-1-i];
    }
}

void shuffle(int a[],int n){ //의사 난수 이용
    srand(time(NULL)); //seed초기화
    for (int i=n-1;i>0;i--){
        int j=rand()%(i+1);
        int temp=a[j];
        a[j]=a[i];
        a[i]=temp;
    }
}



int main(void){
/*Q4
    
    srand(time(NULL));
    int pn=5+rand()%16; //생성한 난수를 16으로 나눈 나머지 : 0~15에 5더한거로 범위 설정
    printf("사람 수: %d\n",pn);
    int * height=calloc(pn, sizeof(int));
    
    for (int i=0;i<pn;i++){
        height[i]=100+rand()%90;
        printf("height[%d]=%d",i,height[i]);
        
    }
    printf("키 최댓값은 %d입니다\n",maxof(height, pn));
    
    free(height);
 */
//Q5
    int an;
    printf("요소 개수:");
    scanf("%d",&an);
    int *a=calloc(an, sizeof(int));
    printf("%d개의 요소값 입력\n",an);
    for (int i=0;i<an;i++){
        
        printf("a[%d]=",i);
        scanf("%d",&a[i]);
    }
    
    ary_reverse(a,an);
    puts("역순 정렬을 종료합니다.\n");
    free(a);
    
 //Q6~Q7
    unsigned x;
    int n,dno,retry;
    char d[512];
    do{
        printf("변환할 음이 아닌 정수 입력:");
        scanf("%d",&x);
        do {
            printf("몇 진수로 변환할까요:");
            scanf("%d",&n);} while(n<2||n>36);
        
        dno=card_convr(x,n,d); //변환한 자릿수를 dno에 저장
        for (int i=0;i<dno;i++){
            printf("%d |        %d...%d\n",n,x,x%n);
            printf("  + --------\n");
            x/=n;
        }
        printf("            0\n");
       
        printf("%d진수로는 ",n);
        
        for (int i=0;i<dno;i++)
            printf("%c",d[i]);
        printf("입니다.\n");
            
            
            
        printf("다시? (예...1/ 아니오...0)");
        scanf("%d",&retry);
        } while (retry==1);

//Q8,9,
    printf("몇개의 요소:");
    scanf("%d",&n);
    
    int *A=calloc(n, sizeof(int));
    int *B=calloc(n, sizeof(int));
    
    printf("%d개의 요소값 입력\n",n);
    for (int i=0;i<n;i++){
        printf("B[%d]= ",i);
        scanf("%d",&B[i]);
    }
    ary_rcopy(A, B, n);
    
    printf("복사한 배열 A의 요소\n");
    for (int i=0; i<n; i++) {
        printf("A[%d]=%d\n",i,A[i]);
    }
    free(A);
    free(B);
    
//Q10
    printf("몇개의 요소:");
    scanf("%d",&n);
    
    int *sa=calloc(n,sizeof(int));
    
    printf("%d개의 요소 입력\n",n);
    for (int i=0;i<n;i++){
        printf("sa[%d]=",i);
        scanf("%d",&sa[i]);
    }
    shuffle(sa, n);
    printf("뒤섞인 배열 a의 요소\n");
    for (int i=0;i<n;i++){
        printf("a[%d]=%d\n",i,  sa[i]);
    }
    free(sa);
//소수 나열하기->불필요한 나눗셈 하지 않기 (소수는 2부터 n-1까지의 어떤 소수로도 나눠지지 x)-> 소수는 n제곱근 이하의 어떤 소수로도 나눠지지x
    int i,j,ptr=0; //변수 선언main함수 안에서 ptr:이미 얻은 소수의 개수
    unsigned long counter=0; //나눈횟수기록->불필요한 나눗셈을 하고 있는가 판단
    int prime[500]; //소수를 저장하는 배열
    prime[ptr++]=2;
    for (int i=3;i<=1000;i+=2){  //홀수만을 대상으로함 (4이상 짝수는 이미 소수가 아님)
        for (j=1;j<ptr;j++){
            counter++;
            if (i%prime[j]==0) break; //나눠떨어지므로 소수아님
            
        }
        if (i==ptr) prime[ptr++]=i; //끝까지 나눠떨어지지 않았으므로 소수 배열에 저장

    }
    for (i=0;i<ptr;i++)
        printf("%d\n",prime[i]);
    printf("나눗셈 횟수:%lu\n",counter);
    
//소수 나열 3
    int prime2[500];
    int m,ptr2=0;
    unsigned long count=0;
    prime2[ptr2++]=2;
    prime2[ptr2++]=3; //2,3저장
    for (int i=5;i<=1000;i+=2){
        int flag=0;
        for ( m=1;count++,prime2[m]*prime2[m]<=i;m++){
            count++;
            if (i%prime2[m]==0){
                flag=1;
                break;
        }
    }
        

    if (! flag) prime2[ptr++]=i;
    }
    
    for (int i=0;i<ptr;i++){
        printf("%d\n",prime2[i]);
    }

    printf("나눈 횟수: %lu\n",count);
     
       
        
        
                
       
            
            
    
        
            
            
            
    
    
          
    
    
    
    
    
    
    
    
    
    
    return 0;
}





