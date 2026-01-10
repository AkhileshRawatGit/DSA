#include<stdio.h>
int main(){
    int n;
    printf("Enter the size of array: ");
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
    int found=-1;
    for(int i=0;i<n;i++){  
        if(arr[i]==seaching_element){
            found=i;
            break;
        }
    }
    if(found!=-1){
        printf("element found at index%d",found);
    }
    else{
        printf("Element not found");
    }
    return 0;
}

//time and space complexity
//0->n 
//O(n)