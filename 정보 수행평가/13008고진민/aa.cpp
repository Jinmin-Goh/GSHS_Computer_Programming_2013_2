//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int i,j,k,m,n,p;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%d",&n);
	if(n>=9876) printf("10234");
	else{
		n=n+1;
		for(p=n;p<9876;p++){
			i=p/1000;
			j=(p/100)%10;
			k=(p/10)%10;
			m=p%10;if(i==0&&j==0&&k==0){
				printf("%d",p+1); goto end;
			}
			else if(i==0&&j==0){
				
				if(k==0||m==0) continue;if(k==m) continue;
				else{printf("%d",i*1000+j*100+k*10+m);goto end;}
			}
			else if(i==0){
				
				if(j==0||k==0||m==0) continue;if(j==k||j==m||k==m) continue;
				else{printf("%d",i*1000+j*100+k*10+m);goto end;}
			}
			else{
				if(i==0||j==0||k==0||m==0) continue;
				if(i==j||i==k||i==m||j==k||j==m||k==m) continue;
				else{printf("%d",i*1000+j*100+k*10+m);goto end;}
			}
		}
	}	
end:; 
}