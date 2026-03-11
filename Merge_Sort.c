#include<stdio.h>
#include<time.h>

void merge(int arr[],int left,int mid,int right){
    int i,j,k;
    int nl=mid-left+1;
    int nr=right-mid;
    int L[nl],R[nr];
    for(i=0;i<nl;i++) L[i]=arr[left+i];
    for(j=0;j<nr;j++) R[j]=arr[mid+1+j];
    i=0;
    j=0;
    k=left;
    while(i<nl && j<nr){
        if(L[i]<R[j]){
            arr[k++]=L[i++];
        }
        else{
            arr[k++]=R[j++];
        }
    }
    while(i<nl){
        arr[k++]=L[i++];
    }
    while(j<nr){
        arr[k++]=R[j++];
    }
}

void mergeSort(int arr[],int left,int right){
    if(left<right){
        int mid;
        mid=(left+right)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

int main(){
    int n,i;

    clock_t start,end;
    double CPU_time;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter the array elements: ");
    for(i=0;i<n;i++) 
        scanf("%d",&arr[i]);

    start = clock();  

    mergeSort(arr,0,n-1);

    end = clock();     

    CPU_time = ((double)(end-start))/CLOCKS_PER_SEC;

    printf("\nArray after sorting:\n");
    for(i=0;i<n;i++) 
        printf("%d\t",arr[i]);

    printf("\nExecution Time: %f seconds\n",CPU_time);

    return 0;
}
