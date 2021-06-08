#include <stdio.h>
#include <string.h>

int main(void){
    
    char filename[100];
    char s[100];
    int i;

    // 아래 반복문 한줄로
    // sprintf(filename, "image%d.jpg", i);
    for(i=0; i<6; i++){
        strcpy(filename, "image");
        sprintf(s, "%d", i);
        strcat(filename, s);
        strcat(filename, ".jpg");
        printf("%s\n", filename);
    }
    
    return 0;
}