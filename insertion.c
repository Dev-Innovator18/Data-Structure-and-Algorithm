#include<stdio.h>
void insertion(int arr[],int n){
    int i,j,key;
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
void main(){
    int n;
    printf("Enter the number of elements to be stored in the array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    insertion(arr,n);
    printf("The sorted array is:");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}