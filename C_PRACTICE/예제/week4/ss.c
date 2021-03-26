list[100];

int seq_search(int key, int low, int high){
    int i;
    for(i=low; i<=high; i++){
        if(list[i] == key)
            return i;
    }
    return -1;
}