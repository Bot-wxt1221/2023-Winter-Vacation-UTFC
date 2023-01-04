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
//	freopen("f4.in","r",stdin);
//	freopen("f4.out","w",stdout);
    int n;
    double m;
    n=read();
    m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        b[i]=read();
        c[i]=read();
    }
    for(int i=1;i<n;i++){
        double _max=m*a[i]/a[i+1];
        _max=std::max(m,_max);
        _max=std::max(_max,m*c[i]/c[i+1]);
        m=_max;
    }
    printf("%lld",(int)(floor(m)));
    return 0;
}
