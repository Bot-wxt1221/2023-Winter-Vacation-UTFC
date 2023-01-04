#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int cha[1000005];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	#endif
    int n=read();
    int m=read();
    for(int i=1;i<=m;i++){
    	int l=read(),r=read();
    	int a=read();
    	int b=read();
    	int last=a+(r-l)*b;
    	cha[l]+=a;
    	cha[l+1]+=(b-a);
    	cha[r+1]-=(b+last);
    	cha[r+2]=last;
	}
	for(int i=1;i<=n;i++){
		cha[i]+=cha[i-1];
	}
	for(int i=1;i<=n;i++){
		cha[i]+=cha[i-1];
	}
	for(int i=1;i<=n;i++){
		printf("%lld ",cha[i]);
	}
	return 0;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		c=='-'?f=-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f*x;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/


