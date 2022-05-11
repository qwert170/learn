/*桶排序
#include<stdio.h>
int main(){
    int a[10]={1,3,6,2,4,9,10,23,45,99};
    int b[100];
    int i,t,j;
    for(i=0;i<100;i++){
        b[i]=0;
    }
    for(i=0;i<10;i++){
         t=a[i];
         b[t]++;
    }
    for(i=0;i<100;i++){
        for(j=1;j<=b[i];j++){
            printf("%d ",i);
        }
    }
    return 0;
}
*/


/*冒泡*/
                
/*快速排序*/
#include<stdio.h>
int a[10]={1,3,5,7,9,2,4,6,8,10}; ;
int n=10;
void q(int left,int right);

int main(){
     int i;
     q(0,n);
     for(i=0;i<n;i++){
         printf("%d ",a[i]);
     }
     return 0;
}

void q(int left,int right ){
    int i,j,t,temp;
    if(left>right)   return;
    temp=a[left];
    i=left;
    j=right;
    while(i!=j){
        while(a[j]>=temp&&i<j)   j--;
        while(a[i]<=temp&&i<j)   i++;
        if(i<j){
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    a[left]=a[i];
    a[i]=temp;

    q(left,i-1);
    q(i+1,right);
}