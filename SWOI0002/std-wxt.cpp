#include <iostream>
#include <cstdio>
#include <cmath>
#include <stack>
#define int unsigned long long
inline int read();
class node{
    public:
        int l;
        int r;
        node(int ll,int rr){
            l=ll;
            r=rr;
        }
};
int sum[1000006];
int sum2[1000006];
int ans;
std::stack<node>a;
int _max[1000005][20];
int _max2[1000005][20];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	#endif
    int n=read();
    for(int i=1;i<=n;i++){
        _max[i][0]=read();
        _max2[i][0]=i;
        sum[i]=_max[i][0]+sum[i-1];
//        sum[i]%=mod;
    }
    for(int i=1;i<=n;i++){
        sum2[i]=sum2[i-1]+sum[i];
//        sum2[i]%=mod;
    }
    int lg=log2(n);
    for(int i=1;i<=lg;i++){
        for(int j=1;j<=n;j++){
            _max[j][i]=std::max(_max[j][i-1],_max[j+(1<<(i-1))][i-1]);
            if(_max[j][i-1]>_max[j+(1<<(i-1))][i-1]){
                _max2[j][i]=_max2[j][i-1];
            }else{
                _max2[j][i]=_max2[j+(1<<(i-1))][i-1];
            }
        }
    }
    a.push(node(1,n));
    while(a.size()>0){
        node st=a.top();
        a.pop();
        int lg=log2(st.r-st.l+1);
        int as=std::max(_max[st.l][lg],_max[st.r-(1<<lg)+1][lg]);
        int asi;
        if(_max[st.l][lg]>_max[st.r-(1<<lg)+1][lg]){
            asi=_max2[st.l][lg];
        }else{
            asi=_max2[st.r-(1<<lg)+1][lg];
        }
        ans+=(asi-st.l+1)*(sum2[st.r]-sum2[asi-1])*as;
        // ans%=mod;
        if(st.l!=1)
            ans-=(st.r-asi+1)*(sum2[asi-1]-sum2[st.l-2])*as;
        else
            ans-=(st.r-asi+1)*(sum2[asi-1])*as;
        // ans%=mod;
        if(st.l<=asi-1)
            a.push(node(st.l,asi-1));
        if(asi+1<=st.r){
            a.push(node(asi+1,st.r));
        }
    }
    std::cout<<ans;
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


