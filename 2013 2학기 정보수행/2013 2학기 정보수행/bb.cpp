//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int n=99,k,i,j;
long long int C[100][100];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%d",&k);
	for(i=1;i<=n;i++){
		C[i][0]=C[i][i]=1;
		for(j=1;j<i;j++) C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	printf("%lld",C[k-1][3]);
}