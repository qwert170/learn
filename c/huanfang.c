/*幻方*/
/*奇阶幻方    楼梯法*/
#include<stdio.h>
int main(){
    int a[5][5]={0};
	int b[5][5]={0};
    int i,j,k,cnt,x,y;
    cnt=1;
	x=0;y=2;

	while(cnt<26){
		if(x==-1&&y==5){
			x=1;
			y=4;
		}
		if(x<0){
			x=x+5;
		}
	    if(y>4){
           y=y-5;
		}
		
		if(b[x][y]==1){
			 x++;
			 x++;
			 y--;
		}
		 a[x][y]=cnt;
			 cnt++;
			 b[x][y]=1;
			 x--;
			 y++;
		
	}
	for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            printf("%2d ",a[i][j]);
        }
        printf("\n");
    }
	
    return 0;
}
