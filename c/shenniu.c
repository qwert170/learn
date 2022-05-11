#include<stdio.h>
int main(){
    int m,k,n;
    scanf("%d%d%d",&k,&m,&n);
    int a[m+1];
    int b[m+1];
    int i,j,t,flag=0;
    for(i=1;i<=m;i++){
        scanf("%d %d",&a[i],&b[i]);
    }
    for(i=1;i<=m;i++){
        if(a[i]){
        t=k/a[i];
            if(t*b[i]>=n){
            flag=1;
            printf("%d ",i);
            }else{
            ;
            }
        }else if(a[i]==0){
            if(b[i]>0){
                flag=1;
            printf("%d ",i);
            }
        }
       
    }
    printf("\b");
    if(flag==0){
        printf("-1");
    }

    return 0;
}