//
//  sortingAlgorithm.c

//  Created by SUNJAE on 2022/11/03.
// sorting algorithm

#include <stdio.h>
#define swap(a,b) { int t=a; a=b; b=t;} //exchange sort에 쓰일 swap 매크로 정의
#define MAX 5000
#include <time.h>

int s[MAX]={50,32,5,13,56,47,1,23,45,67}; //배열 s를 전역 변수로 선언


// 1.exchange sort로 배열 s[0..n-1]을 오름차순으로 정렬

void bubble(int n){
    int i,j;
    
    for (i=0;i<=n-2;i++){
        for (j=i+1;j<=n-1;j++){
            if (s[i]>s[j]) swap(s[i],s[j]); //왼쪽 요소가 오른쪽 요소보다 클 경우 교환
        }
    }
} // O(n^2)의 시간복잡도

// 2.Mergesort
void merge(int, int , int);

void Mergesort(int low, int high){ //divide하는 함수
    int mid;
    
    if (low<high) {
        mid=(low+high)/2;
        Mergesort(low, mid); //왼쪽 배열 분할
        Mergesort(mid+1, high); //오른쪽 배열 분할
        merge(low, mid, high);

    }
}

void merge(int low, int mid, int high){ //합병하는 함수
    int i=low,j=mid+1,k=low;
    int U[MAX]={0,}; //최종 결과를 임시 저장할 배열 U[0..n-1]
    while (i<=mid && j<=high) {
        if (s[i]<s[j]){ //전역변수로 선언한 배열 s( 전역변수로 선언하지 않을 경우 파라미터로 전달)
            U[k]=s[i]; //더 작은 값 s[i]를 U에 저장하고 i를 1증가시킴
            i++;
        }
        else{
            U[k]=s[j];
            j++;
        }
        k++;
    }
    if (i>mid) //오른쪽 배열만 남았을 경우 -> 남은 값을 그대로 복사
        while (j<=high) {
            U[k++]=s[j];
            j++;
        }
    else{  //왼쪽 배열만 남았을 경우-> 그대로 복사
        while (i<=mid) {
            U[k++]=s[i];
            i++;
        }
    }
    
    while (low<=high) {
        s[low]=U[low];
        low++;
   } //U의 값을 s에 복사
}


// 3. quicksort(빠른 정렬)
/*  처음 배열 s에서 pivot을 정하고 정한 피봇을 기준으로 피봇 왼쪽에는 피봇보다 작은 값, 오른쪽은 큰 값이 오도록 분할한다. 나누어진 두 배열도 재귀적으로 정렬하여 전체 배열을 비내림차순으로 정렬하는 방법. */


/* 정렬 방법 -> 피봇값을 맨 처음 요소로 정하고, 피봇 다음 값부터 차례로 검색한다. 만약 피봇값보다 작다면 j인덱스를 1증가시킨 후 s[i]와 s[j]를 교환한다. (결국 피봇보다 큰 값과 작은 값이 서로 자리를 바꾸게 되고, 반복하다보면 피봇값을 기준으로 좌우로 정렬된다.이미 정렬된 데이터가 올 경우 최악의 시간 복잡도(N^2)를 가진다.
 */
int partition(int low, int high){ //분할 알고리즘
    
    int p_ind=low;
    int i,j=low;
    
    
    for(i=low+1;i<=high;i++)
        if (s[i]<s[p_ind]) {
            j++;
            swap(s[i], s[j]);
        }
    p_ind=j;
    swap(s[low], s[p_ind]);
    return p_ind;
   
  }
    
                                      

void quicksort(int low, int high){
    int p;
    if (low<high){
        p=partition(low,high); //분할된 후 반환된 피봇 인덱스 저장
        quicksort(low,p-1);
        quicksort(p+1, high);
        
    }
}





int main(void){
    bubble(10);
   printf("교환정렬 결과: ");
    for (int i=0;i<10;i++) printf("%d ",s[i]);
    
    printf("\n");
    
    Mergesort(0,9);
    printf("합병정렬 결과: ");
    for (int i=0;i<10;i++) printf("%d ",s[i]);
    
    printf("\n");
   
    quicksort(0, 9);
    printf("퀵정렬 결과: ");
    for (int i=0;i<10;i++) printf("%d ",s[i]);
    
  
    return 0;
}



