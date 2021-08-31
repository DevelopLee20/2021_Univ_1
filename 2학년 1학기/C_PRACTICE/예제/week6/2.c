int get_sum1(int a[], int n)
{
    int sum = 0;

    for(int i=0; i<n; i++){
        sum += a[i];
    }

    return 0;
}

int get_sum2(int a[], int n)
{
    int sum = 0;
    int *p;

    p = a;

    for(int i=0; i<n; i++){
        sum += *p++;
    }

    return sum;
}