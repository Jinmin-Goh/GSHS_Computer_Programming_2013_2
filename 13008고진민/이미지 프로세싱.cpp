#include<stdio.h>
#include<math.h>
int R[1025][1281],G[1025][1281],B[1025][1281],gray[1025][1281];
int main(){
	int i,j,error,pi,gradient,d;
	FILE *in=fopen("sample.bmp","rb");
	FILE *out=fopen("result1.bmp","wb");
	error=80;
	gradient=1;
	pi=3.141592;
	d=128;
	for(i=0;i<54;i++)
		putc(getc(in),out);
	
	/*
	//�ǻ���? - ������ ���� ����
	for(i=0;i<1024;i++){
		for(j=0;j<1280;j++){
			B[i][j]=getc(in);G[i][j]=getc(in);R[i][j]=getc(in);
			if(d>G[i][j]) G[i][j]=(int)((255-G[i][j])*0.67+G[i][j]*0.33);
			if(d>B[i][j]) B[i][j]=(int)((255-B[i][j])*0.67+B[i][j]*0.33);
			if(d>R[i][j]) R[i][j]=(int)((255-R[i][j])*0.67+R[i][j]*0.33);
		}
	}
	*/

	

	//��¼�ٺ��� ������
	for(i=0;i<1024;i++){
		for(j=0;j<1280;j++){
			B[i][j]=getc(in);G[i][j]=getc(in);R[i][j]=getc(in);
			if(d>G[i][j]) G[i][j]=255-G[i][j];
			if(d>B[i][j]) B[i][j]=255-B[i][j];
			if(d>R[i][j]) R[i][j]=255-R[i][j];
		}
	}
	
	

	/*
	
	//������ �˰���(���� - gradient�� 2 �̻��� ���, �̻� �߻�)
	for(i=0;i<1024;i++){
		for(j=0;j<1280;j++){
			gray[i][j]=B[i][j]*0.11+G[i][j]*0.59+R[i][j]*0.3;
			B[i][j]=gray[i][j];
			R[i][j]=gray[i][j];
			G[i][j]=gray[i][j];
			
		}
	}

	for(i=0;i<=1024;i++){
		for(j=0;j<=1280;j++){
			if(gray[i][j]==0) gray[i][j]=1;
		}
	}

	for(i=0;i<1024;i++){
		for(j=0;j<1280;j++){
			if((gray[i][j]/gray[i+1][j+1]>gradient||gray[i][j]/gray[i+1][j+1]<1/gradient)&&(gray[i][j]/gray[i+1][j]>gradient||gray[i][j]/gray[i+1][j]<1/gradient)&&(gray[i][j]/gray[i][j+1]>gradient||gray[i][j]/gray[i][j+1]<1/gradient))
				continue;
			else gray[i][j]=255;
			
		}
	}

	*/
	
	/*
	
	//�߾� ���, �׵θ� ��Ӱ� �˰���(���� ȿ��)
	for(i=0;i<1024;i++){
		for(j=0;j<1280;j++){
			B[i][j]=(int)(getc(in)*(sin((double)j*pi/1280)*sin((double)j*pi/1280)*0.5+sin((double)i*pi/1280)*sin((double)i*pi/1280)*0.5));
			G[i][j]=(int)(getc(in)*(sin((double)j*pi/1280)*sin((double)j*pi/1280)*0.5+sin((double)i*pi/1280)*sin((double)i*pi/1280)*0.5));
			R[i][j]=(int)(getc(in)*(sin((double)j*pi/1280)*sin((double)j*pi/1280)*0.5+sin((double)i*pi/1280)*sin((double)i*pi/1280)*0.5));
		}
	}
	*/

	/*

	//�߾� ���, �׵θ� ��Ӱ� �˰���(���� ȿ��)
	for(i=0;i<1024;i++){
		for(j=0;j<1280;j++){
			B[i][j]=(int)(getc(in)*(sin((double)j*pi/1280)*0.5+sin((double)i*pi/1280)*0.5));
			G[i][j]=(int)(getc(in)*(sin((double)j*pi/1280)*0.5+sin((double)i*pi/1280)*0.5));
			R[i][j]=(int)(getc(in)*(sin((double)j*pi/1280)*0.5+sin((double)i*pi/1280)*0.5));
		}
	}
	
	*/


	/*

	//������ ���� �� ���� �ణ+��� �˰���
	for(i=0;i<1024;i++){
		for(j=0;j<1280;j++){
			B[i][j]=(int)(getc(in)*0.2+255*sin((double)j*pi/1280)*0.4+255*sin((double)i*pi/1280)*0.4)%255;
			G[i][j]=(int)(getc(in)*0.2+255*sin((double)j*pi/1280)*0.4+255*sin((double)i*pi/1280)*0.4)%255;
			R[i][j]=(int)(getc(in)*0.2+255*sin((double)j*pi/1280)*0.4+255*sin((double)i*pi/1280)*0.4)%255;
		}
	}
	*/






	/*
	//ȸ�� �迭(������ �˰���) - �׸��� ���� error�� �� ���� ���� �ʿ�

	for(i=0;i<=1024;i++){
		for(j=0;j<=1280;j++){
			int gray=R[i][j]*0.3+G[i][j]*0.59+B[i][j]*0.11;  //ȸ������
			R[i][j]=gray; G[i][j]=gray; B[i][j]=gray;


			if(((B[i][j]-R[i][j]>error)||(B[i][j]-R[i][j]<-error))||(G[i][j]-R[i][j]>error)||(G[i][j]-R[i][j]<-error)||(B[i][j]-G[i][j]<-error)||(B[i][j]-G[i][j]>error)) B[i][j]=255,G[i][j]=255,R[i][j]=255;
			if(B[i][j]+G[i][j]+R[i][j]>300&&B[i][j]+G[i][j]+R[i][j]<760) B[i][j]=255,G[i][j]=255,R[i][j]=255;
		}
	}

	*/




	/*

	//��輱 �˰���(���� ����)
	for(i=0;i<=1024;i++){
		for(j=0;j<=1280;j++){
			if(R[i][j]==0) R[i][j]=1;
			if(G[i][j]==0) G[i][j]=1;
			if(B[i][j]==0) B[i][j]=1;

		}
	}
	
	for(i=0;i<1024;i++)
		for(j=0;j<1280;j++){
			B[i][j]=255-B[i][j]/B[i+1][j+1]*255;
			G[i][j]=255-G[i][j]/G[i+1][j+1]*255;
			R[i][j]=255-R[i][j]/R[i+1][j+1]*255;
			//if(B[i][j]+G[i][j]+R[i][j]<760) B[i][j]=0,G[i][j]=0,R[i][j]=0;
			if(((B[i][j]-R[i][j]>error)||(B[i][j]-R[i][j]<-error))||(G[i][j]-R[i][j]>error)||(G[i][j]-R[i][j]<-error)||(B[i][j]-G[i][j]<-error)||(B[i][j]-G[i][j]>error)) B[i][j]=255,G[i][j]=255,R[i][j]=255;
		}
		
	for(i=0;i<1024;i+16)
		for(j=0;j<1280;j+16){
			if(B[i][j]+G[i][j]+R[i][j]>=700) B[i][j]=255,G[i][j]=255,R[i][j]=255;
		}
		*/


	for(i=0;i<1024;i++)
		for(j=0;j<1280;j++){
			//int gray=(int)(double)R[i][j]*0.3+(double)G[i][j]*0.59+(double)B[i][j]*0.11;
			putc(B[i][j],out);
			putc(G[i][j],out);
			putc(R[i][j],out);

		}

}