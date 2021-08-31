#include <stdio.h> // 표준입출력 라이브러리
#include <stdlib.h> // random 함수 라이브러리
#include <time.h> // time 시드를 넣기위한 라이브러리

int list[100]; // 100개의 랜덤 숫자를 담을 배열

// 랜덤 배열 생성
void randompick(){ // 랜덤 배열을 생성하는 함수
    int count = 0; // 인덱스 조작을 위한 변수
    srand((unsigned)time(NULL)); // 시간을 기준으로 랜덤 시드를 정해줌
    while(count!=100){ // 100개의 랜덤 배열이 생성되면 반복을 종료
        list[count] = (rand()%1000) + 1; // 1~999의 랜덤을 만듬
        
        int check = 1; // 중복 판단을 위한 변수
        for(int i=0; i<count; i++){ // 중복 판단
            if (list[i] == list[count]){ // 있을경우 check = 0이 되고 반복을 종료
                check = 0;
                break;
            }
        }

        if(check){ // 중복이 아니라면 인덱스를 한칸 밀어줘서 새로운 다른 장소에 값을 저장함
            count++;
        }
    }
}

// 선택정렬 알고리즘
int selectionSort(int n, int max){ // 정렬을 위한 선택정렬 알고리즘
    int i, j;

    for(i=0; i<max-1; i++){
        int min = i;

        for(j=i+1; j<max; j++){
            if(list[j] < list[min]){ // 비교해서 정렬해준다.
                min = j;
            }
        }

        int swap = list[min];
        list[min] = list[i];
        list[i] = swap; // list[min]과 list[i] 값을 바꿔준다.
    }
    return 0;
}

// 이진탐색 알고리즘
int binary_search(int key, int n){
    int low, high, middle; // 최하, 최고, 중간 값을 저장한다.
    low = 0;
    high = n-1;

    while(low<=high){
        middle = (low +high)/2; // 절반으로 나누어서 높거나 낮음에 따라서 인덱스를 바꿔준다.
        if(key == list[middle])
            return middle;
        else if(key > list[middle])
            low = middle + 1;
        else
            high = middle - 1;
    }
    return -1;
}

// 순차탐색 알고리즘
int seq_search(int key, int high){ // 처음부터 순서대로 탐색해서 원하는 값을 찾는다.
    for(int i=0; i<=high; i++)
        if(list[i] == key)
            return i;
    return -1;
}

// 타이머
void timer( int(*function)(int, int),int n) { // 포인터 함수를 사용해서 함수를 매개변수로 받는다.
    clock_t  start, finish;
    clock_t  duration;

    start = clock();
    function(n,100); // 매개변수는 2개를 사용한다.
    finish = clock();

    duration = finish - start; // 소요된 클럭을 계산한다.
    printf( "%d 클럭입니다.\n", duration );
}

int main(void){
    double duration;
    clock_t start, end;
    int n;
    scanf("%d",&n);

    randompick();

    // 순차탐색 시간 계산
    start = clock();
    timer(seq_search, n);
    end = clock();

    duration = (double)(end-start)/CLOCKS_PER_SEC;
    printf("순차 탐색: %.4lf\n",duration);

    // 선택정렬 시간 계산
    start = clock();
    timer(selectionSort, n);
    end = clock();

    duration = (double)(end-start)/CLOCKS_PER_SEC;
    printf("선택 정렬: %.4lf\n",duration);

    // 이진탐색 시간 계산
    start = clock();
    timer(binary_search, n);
    end = clock();

    duration = (double)(end-start)/CLOCKS_PER_SEC;
    printf("이진 탐색: %.4lf\n",duration);

    return 0;
}