#include <stdio.h>
#define SIZE 5

int main(void){

    int buffer[SIZE] = {10,20,30,40,50};
    FILE *fp = NULL; // 파일 포인터 초기화

    fp = fopen("binary.bin","wb");
    
    if(fp==NULL){
        fprintf(stderr, "binary.bin 파일을 열 수 없습니다.");
        return 1;
    }

    fwrite(buffer, sizeof(int), SIZE, fp); // 포인터에 있는 값 하나씩 이진파일에 저장
    fclose(fp);
    
    return 0;
}