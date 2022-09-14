int partition(int arr, int l, int r){
    int pivot = a[r];
    int i = l;
    int j = r-1;
    while (i<j)
    {
        while(pivot<i && i<r){
            i++;
        }
        while(pivot>j){
            j++;
        }
        if(i<j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j], arr[r]);
    return j;
}
quicksort(int arr, int l, int r)
{
    if (l < r)
    {
        int part = partion(arr, l, r);
        quicksort(arr, l, part - 1);
        quicksort(arr, part + 1, r);
    }
}
