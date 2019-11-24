#include<stdio.h>
int n,i,j,k,m,p;
int main(){
	scanf("%d",&n);
	if(n>=9876) printf("10234");
	else{
		n=n+1;
		for(p=n;p<=9876;p++){
			m=p/1000;
			i=(p/100)%10;
			j=(p/10)%10;
			k=p%10;
			if(m==0) 
			if(m==i||m==j||m==k||i==j||i==k||j==k) continue;
			else {printf("%d",1000*m+100*i+10*j+k); goto end;}
		}
	}
end:;
}