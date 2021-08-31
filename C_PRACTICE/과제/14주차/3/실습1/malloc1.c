#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int* list;
	
	list = (int*)malloc(3 * sizeof(int)); // 동적 생성
	if (list == NULL) { // 메모리 할당 오류 예외 처리
		printf("동적 메모리 할당 오류\n");
		exit(1);
	}
	list[0] = 10; // 생성 1
	list[1] = 20; // 생성 2
	list[2] = 30; // 생성 3
	free(list);

	return 0;
}