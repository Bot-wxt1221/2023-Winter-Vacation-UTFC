#include <iostream>
#include <cstdio>
#include <stack>
inline int read();
int h[1000005];
int ans[1000005];
std::stack<int>a;
int main(){
	#ifdef ONLINE_JUDGE
	#else
	 freopen("b.in","r",stdin);
	 freopen("b.out","w",stdout);
	#endif
	int n=read();
    for(int i=1;i<=n;i++){
        h[i]=read();
    }
    a.push(n);
    ans[n]=1;
    for(int i=n-1;i>=1;i--){
        while(a.size()>0&&h[a.top()]<h[i]){
            a.pop();
        }
        ans[i]=ans[a.top()]+1;
        a.push(i);
    }
    for(int i=1;i<=n;i++){
        printf("%d ",ans[i]);
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


