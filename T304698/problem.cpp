#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int a[10005];
int b[10005];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	// freopen("problem.in","r",stdin);
	// freopen(".out","w",stdout);
	#endif
    int n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    for(int i=1;i<=n;i++){
        b[i]=read();
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]>a[j]){
                std::swap(a[i],a[j]);
            }
            if(b[i]>b[j]){
                std::swap(b[i],b[j]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=((a[i]-b[i])%1000000007)*((a[i]-b[i])%1000000007);
        ans%=1000000007;
    }
    printf("%lld",ans);
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

