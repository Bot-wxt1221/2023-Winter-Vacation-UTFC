#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
using namespace std;
int a[1000005],b[1000005],c[1000005];
int read(){
	char temp=getchar();
	int f=1,x=0;
	while('0'>temp||temp>'9'){
		(temp=='-')?(f=-1):0;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}
signed main(){
    int n,m;
    n=read();
    m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        b[i]=read();
        c[i]=read();
    }
    for(int i=1;i<n;i++){
        int _max=((floor(m*a[i]/100))*100)/a[i+1];
        _max=std::max(m,_max);
        _max=std::max(_max,(int)((floor(m*c[i]/100))*100)/c[i+1]);
        m=_max;
    }
    printf("%lld",m);
    return 0;
}
