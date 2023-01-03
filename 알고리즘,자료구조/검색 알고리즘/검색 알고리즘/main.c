//
//  main.c
//  검색 알고리즘
//
//  Created by SUNJAE on 2022/02/04.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strcmp함수: 문자열 비교 같으면 0, 전자가 크면 양수, 후자가 크면 음수 반환

typedef struct {
    char name[32];
    int height;
    int weight;

}Person;

int npcmp(const Person *x, const Person *y){
    return strcmp(x->name, y->name);
} //Person형의 비교함수: 오름차순으로 이름 정렬


int search(const int a[],int n, int key){
    int i=0;
    for (i=0;i<n;i++){
        if(a[i]==key) return i;
    }
    return -1;
}

int search2( int a[],int n, int key){ //선형 보초법
    int i=0;
    a[n]=key; //배열 끝에 key값 저장
    while (1) {
        if(a[i]==key){
            break;
        }
        i++;
    }
    return i==n ? -1:i; //검색 실패시 -1반환 성공시 i반환
}

int bin_search(const int a[],int n,int key){ //바이너리서치
    int pl=0;
    int pr=n-1; //맨 처음, 끝 인덱스
    int pc;//중간
    
    do{
        pc=(pl+pr)/2; //중간 인덱스 저장
        if (a[pc]==key) return pc; //검색 성공
        else if (a[pc]<key) pl=pc+1;
        else pr=pc-1;
        
    } while (pl<=pr);
    return -1; //검색 실패
           
}

int bin_Search2(const int a[], int n, int key){
    int pl=0;
    int pr=n-1;
    int pc,count=-1;
    int *x=calloc(n,sizeof(int)); //같은 값의 인덱스를 저장할 새로운 배열
    do{
        pc=(pl+pr)/2;
        if (a[pc]==key){
            for (int i=pc-1;i>=0;i--){
                if (a[i]==key){
                    count++;
                    for (int j=0;j<=count;j++)
                        x[j]=i;
                        }
            
            }
            return x[count]; //검색 성공
            
        }
        else if (a[pc]<key) pl=pc+1;
        else pr=pc-1;
        
    } while (pl<=pr);
    return -1; //검색 실패
}

//Q3
int Search_idx(const int a[],int n, int key, int idx[]){
    int j=0;
    for (int i=0;i<n;i++){
        if (a[i]==key) {
            idx[j]=i; //성공 시 인덱스 저장
            j++;
        }
}
    return j;
}

int int_cmp(const int *a, const int *b){ //정수를 비교하는 함수 (오름차순)
    if (*a<*b) return -1;
    else if (*a>*b) return 1;
    else return 0;
}
int int_cmp2(const int *a, const long *b){ //정수를 비교하는 함수 (내림차순)
    if (*a>*b) return -1;
    else if (*a<*b) return 1;
    else return 0;
}

int sum(int a, int b){
    return a+b;
}
int mul(int a, int b){
    return a*b;
}

void kuku(int (*calc)(int,int)){
    for (int i=1;i<=9;i++){
        for (int j=1;j<=9;j++){
            printf("%3d",(*calc)(i,j));
            
        }
        printf("\n");
    }
}

//Q7-선형 검색 알고리즘 사용, 배열 정렬 무관





void *seqsearch(const void *key, const void *base, size_t nmemb, size_t size
                ,int (*int_cmp)(const void *, const void * ))
{
    char *x=(char *)base; //형변환 후 새로운 문자열 포인터 변수에 저장
    for (size_t i=0;i<nmemb;i++){
        if(!int_cmp((const void *)&x[i*size],key)) // !x: x가 거짓(0이 아닌경우) 비교함수
            return (&x[i * size]); //같은 요소값 리턴. (요소의 사이즈 단위로 움직여야 다음 요소에 접근 가능)
    }
    return NULL;//검색 실패
}

void *binsearch(const void *key, const void *base, size_t nmemb, size_t size,
                int (*int_cmp)(const void *, const void *)){
    size_t pl=0,pr=nmemb-1,pc;
    char *x=(char *)base;
    if (nmemb>0){
        while (1) {
            int comp=int_cmp((const void *)&x[(pc = (pl + pr) / 2) * size], key);
            if (comp==0) return (&x[pc*size]); //검색성공
            else if (pl==pr)break; //검색 실패
            else if (comp<0) //-1일때->키값이 더 클때
                pl=pc+1;
            else pr=pc-1;  //1일때
        }
    
    }
    
    return NULL;
}

void *bsearchx(const void *key, const void *base, size_t nmemb, size_t size,
                int (*int_cmp)(const void *, const void *)){
    size_t pl=0,pr=nmemb-1,pc;
    char *x=(char *)base;
    size_t count=0;
    size_t *a=calloc(count, sizeof(int));
    
    if (nmemb>0){
        while (1) {
            int comp=int_cmp((const void *)&x[(pc = (pl + pr) / 2) * size], key);
            if (comp==0) {//검색성공
                count++;
                for (size_t i=pc-1;i>=0;i--){
                    if (&(x[pc*size])==key)
                        a[count-1]=i;
                }
                return a;
            }
            else if (pl==pr)break; //검색 실패
            else if (comp<0) //-1일때->키값이 더 클때
                pl=pc+1;
            else pr=pc-1;  //1일때
        }
        
}
    return NULL;
}


int main() {
    //Q4
   int nx,i,key;
   int *x; //배열의 첫번째 요소에 대한 포인터
    int *p;//검색한 요소에 대한 포인터


   puts("bsearch 함수 이용 검색");
   printf("요소 개수:");
   scanf("%d",&nx);
   x=calloc(nx,sizeof(int)); //nx개의 int형 배열 생성
    printf("오름차순으로 입력하세요\n");
    printf("x[0]: ");
    scanf("%d",&x[0]); //배열 요소 값 입력
    for(i=1;i<nx;i++){
        do{ printf("x[%d]: ",i);
           scanf("%d",&x[i]); //배열 요소 값 입력
        }while(x[i]<x[i-1]);
    }
    
    printf("key값 입력:");
    scanf("%d",&key);
    
    
   /* printf("   |");
    for (int j=0;j<nx;j++) printf("%3d ",j);
    printf("\n");
    printf("---+------------------------------\n");
    printf("   |"); */
    p=bsearchx(&key, x, nx, sizeof(int), (int (*) (const void *a, const void *b))int_cmp);
    //p는 찾은 요소에 대한 포인터\
    
  /*  for (int j=0;j<=idx;j++){
        printf("%*s", 3*(j-1)+6 , "");
        printf("*\n");
        printf(" %d |",j);
        for (int k=0;k<=idx;k++)
            printf("%3d ",x[k]);
        printf("\n");
        printf("   |");
        
    
    }
    
    
    printf("\n"); */
    
    if (p==NULL) printf("검색 실패\n");
    else printf("%d는(은) x[%d]에 있습니다.\n",key,(int)(p-x)); //형변환해주기. (int *->int)
    
    
    

    free(x);
    
    
/* bsearch함수를 사용해 오름차순 정렬 배열 검색
 bsearch(&key,x,nx,sizeof(int),(int(*)(const void *a,const void *b))int_cmp); */
    
//함수에 대한 포인터 (kuku함수-덧셈,곱셈표
    kuku(sum);
    kuku(mul);
    
    //구조체
    Person X[]={
        {"kim",179,79},
        {"park",172,63},
        {"lee",176,52},
        {"choi",165,51},
        {"ham",181,73},
        {"홍지아",172,84}
    };
    int nX=sizeof(X)/sizeof(X[0]); //배열의 요소 개수
    int retry;
    
    puts("이름으로 검색합니다");
    do{
        Person temp, *p;
        printf("이름:");
        scanf("%s",temp.name);
        p=bsearch(&temp, X, nX, sizeof(Person),(int(*)(const void *,const void *))npcmp); //비교함수
        
        if (p==NULL) printf("검색 실패\n");
        else {
            printf("검색 성공. 아래 요소를 찾음\n");
            printf("X[%d]: %s %dcm %dkg\n",(int)(p-X),p->name,p->height,p->weight);
        }
        printf("다시?(예 1 아니오 0)...");
        scanf("%d",&retry);
    }while(retry==1);
    
//Q6
    long *a,*P;
    int na,ka;
    printf("요소 개수:"); scanf("%d",&na);
    a=calloc(na, sizeof(long));
    
    puts("내림 차순으로 입력.");
    printf("a[0]:");
    scanf("%ld",&a[0]);
    for(int i=1;i<na;i++){
        do{
            printf("a[%d]:",i);
            scanf("%ld",&a[i]);
        }while (a[i-1]<a[i]);
    }
    
    printf("key값 입력:"); scanf("%d",&ka);
    
    P=bsearch(&ka, a, na, sizeof(int),(int(*)(const void *,const void *))int_cmp2);
    //P에 bsearch함수의 반환값 저장됨 . 비교함수 : 내림차순 정렬된 배열에서 key값과 요소 값을 비교해서 같은지 판단.
    if (P==NULL)
        printf("검색 실패\n");
    else
        printf("%d는 a[%d]에 있습니다.\n", ka, (int)(P - a));
    free(a);
    
   
   return 0;
}


