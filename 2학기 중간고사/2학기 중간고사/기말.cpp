#include<stdio.h>
#include<stdlib.h>
#include<stack>
using namespace std;
struct NODE{int v; NODE *l,*r;};
char S[100];
stack<NODE*> st;
NODE *t;
void post(NODE *v){
	if(v==NULL) return;
	post(v->l);
	post(v->r);
	printf("%c",v->v);
}
void in(NODE *v){
	if(v==NULL) return;
	in(v->l);
	printf("%c",v->v);
	in(v->r);
}
void pre(NODE *v){
	if(v==NULL) return;
	printf("%c",v->v);
	pre(v->l);
	pre(v->r);
}


int main(){
	scanf("%s",S);
	for(int i=0;S[i];i++){
		if('a'<=S[i]&&S[i]<='z'){
		t=(NODE *)malloc(sizeof(NODE));
		t->v=S[i],t->l=t->r=NULL;
		st.push(t);
		}
		else{
			t=(NODE *)malloc(sizeof(NODE));
			t->v=S[i];
			t->r=st.top(),st.pop();
			t->l=st.top(),st.pop();
			st.push(t);
		}
	}
	in(t);
}