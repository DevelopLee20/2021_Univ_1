int main(void){
    
    ListNode *list1 = NULL; // 첫번째 list 생성
    ListNode *list2 = NULL; // 두번째 list 생성

    int array1[4] = {7,5,3,1}; // 첫번째 list의 값
    int array2[3] = {5,4,2};   // 두번째 list의 값

    list1 = consList(array1, 4); // 리스트에 값을 추가
    list2 = consList(array2, 3); // 리스트에 값을 추가

    print_list(list1); // 첫번째 list 출력
    print_list(list2); // 첫번째 list 출력

    ListNode *merging = NULL;      // 정렬할 ListNode 생성
    merging = merge(list1, list2); // merge 함수 실행

    print_list(merging);           // 정렬한 ListNode 출력

    return 0;
}