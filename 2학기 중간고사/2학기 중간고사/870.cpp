#include<stdio.h>
long long int C[100][100],a,b,c,d,n,i,j,data[10000],cnt;
int main(){
	scanf("%d",&n);
	if(n<4) printf("0");
	else{
		for(i=1;i<=99;i++){
			C[i][0]=C[i][i]=1;
			for(j=1;j<i;j++) C[i][j]=C[i-1][j]+C[i-1][j-1];
		}
		printf("%lld",C[n-1][3]);
	}
}  
