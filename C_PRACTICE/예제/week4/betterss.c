list[100];

int seq_search2(int key, int low, int high){
    int i;
    list[high+1] = key;
    for(i=low; list[i] != key; i++);
    if (i == (high+1)) return 01;
    else return i;
}