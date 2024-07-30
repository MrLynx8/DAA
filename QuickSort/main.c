#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
int count=0;
int partition( int a[SIZE], int l, int r){
    int i,j,pivot,temp;
    pivot=a[l];
    i=l+1;
    j=r;
    while(1){
        while(pivot>=a[i] && i<=r){
            count++;
            i++;
        }
        while(pivot<a[j]){
            count++;
            j--;
        }
        count++;
        if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        else{
            temp=a[j];
            a[j]=a[l];
            a[l]=temp;
            return j;
        }
    }

}
void quicksort(int a[SIZE], int l,int r){
    int s;
    if(l<r){
        s=partition(a,l,r);
        quicksort(a,l,s-1);
        quicksort(a,s+1,r);

    }
}
int main()
{
    int n,i,a[SIZE],l=0;
    printf("Enter the size of the array: \n");
    scanf("%d",&n);
    printf("Enter the elements: \n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    quicksort(a,l,n-1);
    printf("Sorted Array: \n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("\nCount: %d",count);
    return 0;
}
