#include<stdio.h>

int binarysearch(int arr[], int left , int right,int target){
        
    // int mid=left+(right-left)/2;  //large array ka mid
    //     if(arr[mid]==target){
    //         return mid;
    //     }
    //     else if(arr[mid]<target){
    //         return binarysearch(arr,mid+1,right, target);
    //     }
    //     else{
    //         //arr[mid]>target
    //         return binarysearch(arr,left,mid-1,target);
    //     }
    int ans =-1;
    while(left<right){
        int mid=(left+right)/2;
        if(arr[mid]==target){
            ans=mid;
            break;
        }
        else if(arr[mid]<target){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return ans;
}
int main(){
    int n;
    printf("enter the array size: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    //[1,2,3,4,5,6]
    //[0,1,2,3,4,5]
    int seaching_element;  //input 4
    printf("enter the searchin element:");
    scanf("%d",&seaching_element);
    int ans=binarysearch(arr,0,n,seaching_element);
    if(ans!=-1){
        printf("element found at index%d",ans);
    }
    else{
        printf("Element not found");
    }
}