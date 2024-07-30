#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
int count;
void merge(int A[SIZE],int l, int m, int r){
    int i,j,k,B[SIZE];
    i=l;
    j=m+1;
    k=l;
    while(i<=m && j<=r){
            count++;
        if (A[i]<A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];
    }
    while(i<=m)
        B[k++]=A[i++];
    while(j<=r)
        B[k++]=A[j++];
    for(i=l;i<=r;i++)
        A[i]=B[i];
}
void merge_sort(int A[SIZE], int l,int r ){
    int m;
    if(l<r){
        m=(l+r)/2;
    merge_sort(A,l,m);
    merge_sort(A,m+1,r);
    merge(A,l,m,r);
    }
}
int main()
{
    int n,i,a[SIZE],l,r;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter the array elements: \n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    l=0;
    r=n-1;
    merge_sort(a,l,r);
    printf("Sorted Array: \n");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("Count: %d",count);
    return 0;
}
