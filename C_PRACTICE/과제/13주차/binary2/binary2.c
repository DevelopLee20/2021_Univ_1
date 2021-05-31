#include <stdio.h>
#define SIZE 5

int main(void){

    int i;
    int buffer[SIZE];
    FILE *fp = NULL; // 파일 포인터 초기화

    fp = fopen("binary.bin", "rb"); // 읽기형식으로 저장

    if(fp==NULL){
        fprintf(stderr, "binary.bin 파일을 열 수 없습니다.");
        return 1;
    }

    fread(buffer, sizeof(int), SIZE, fp); // buffer에 복사해서 데이터형만큼 사이즈만큼 fp에서 복사함

    for(i=0; i<SIZE; i++){
        printf("%d", buffer[i]);
    }

    fclose(fp);

    return 0;
}