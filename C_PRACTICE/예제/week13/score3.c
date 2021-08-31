#include <stdio.h>
#include <stdlib.h>

int main(void){

    FILE *fp; // 파일 포인터

    char fname[100];
    int number, count = 0;
    char name[20];
    float score, total = 0.0;

    printf("성적 파일 이름을 입력하시오: ");
    scanf("%s", fname); // 파일명 입력

    if((fp=fopen(fname, "w"))==NULL){ // 파일명을 쓰기 형식으로 열기
        fprintf(stderr, "성적 파일 %s을 열 수 없습니다.\n", fname);
        exit(1);
    }

    while(1){
        printf("학번, 이름, 성적을 입력하시오: (음수이면 종료)");
        scanf("%d", &number);

        if( number < 0 ) break;
        scanf("%s %f", name, &score);
        fprintf(fp, "%d %s %f", number, name, score); // 파일에 저장
    }

    fclose(fp); // 파일 닫기

    if((fp=fopen(fname, "r"))== NULL){ // 읽기 형식으로 열기
        fprintf(stderr, "성적 파일 %s을 열 수 없습니다.\n", fname);
        exit(1);
    }

    while(!feof(fp)){ // feof 파일의 EOF 인듯
        fscanf(fp, "%d %s %f", &number, name, &score);
        total += score; // 합을 저장
        count++;        // 전체 수
    }

    printf("평균 = %f\n", total/count); // 평균 출력
    fclose(fp); // 파일 닫기

    return 0;
}