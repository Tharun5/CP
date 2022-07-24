//MergeSort
// Refer: https://www.youtube.com/watch?v=TzeBrDU-JaY

void merge(int arr[],int st,int m,int lt){
    int n1=m-st+1;
    int n2=lt-m;

    int l[n1],r[n2];
    for(int i=0;i<n1;i++){
        l[i]=arr[i+st];
    }
    for(int i=0;i<n2;i++){
        r[i]=arr[i+m+1];
    }

    int i,j,k;
    i=j=0;
    k=st;
    while(i<n1 && j<n2){
        if(l[i]<=r[j]){
            arr[k]=l[i];
            i++;
        }else{
            arr[k]=r[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k]=l[i];
        i++;k++;
    }

    while(j<n2){
        arr[k]=r[j];
        j++;k++;
    }
}



void mergesort(int arr[], int st, int lt){
    if(st>=lt){
        return;
    }
    int m=(st+lt)>>1;
    mergesort(arr, st, m);
    mergesort(arr, m+1,lt);
    merge(arr, st, m, lt);
}

void solve(){
    int n;cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)cin>>arr[i];
    mergesort(arr,0,n-1);
}
