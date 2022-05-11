//三个数的最大乘积
/*#include<stdio.h>
#include<string.h>
int maximumProduct(int* nums, int numsSize);
int main(){
    int nums[]={1,2,3,4,5};
    int t;
    t=maximumProduct(&nums, 5);
    printf("%d",t);
    return 0;
}
int maximumProduct(int* nums, int numsSize){
     int i,j,t=0;
     int a,b,c;
     int min;
     a=nums[0];
     b=nums[1];
     c=nums[2];
     i=0;
     for(i=3;i<5;i++){
         if(nums[i]>a||nums[i]>b||nums[i]>c){
            min=a;
            if(min>b) min=b;
            if(min>c)  min=c;

            if(min==a)  a=nums[i];
            else if(min==b)  b=nums[i];
            else if(min==c)  c=nums[i];
         }
     }
     t=a*b*c;
     return t;
}*/


//两树之和
/*int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i,j;
    int *b=NULL;
   
    for(i=0;i<numsSize;i++){
        for(j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j]==target){
                b=(int *)malloc(sizeof(int)*2);
                b[0]=i;
                b[1]=j;
                *returnSize=2;
                
            }
        }
    }
    return b;
}*/
