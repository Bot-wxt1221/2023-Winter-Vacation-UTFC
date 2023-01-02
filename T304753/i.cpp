#include <iostream>
#include <cstdio>
inline int read();
int a[100005][10];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	#endif
    int n=read();
    bool zero=0;
    for(int i=1;i<=n;i++){
        a[i][0]=read();
        if(a[i][0]==0){
            zero=1;
        }
    }
    if(zero){
        for(int i=1;i<=n;i++){
            printf("%d ",a[i][0]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i][0]<a[j][0]){
                std::swap(a[i][0],a[j][0]);
            }
        }
    }
    for(int m=1;;m=(!m)){
        int mid=n/2;
        int now=0;
        int aa=1;
        int ab=mid+1;
        while(aa<=mid&&ab<=n){
            if(a[aa][!m]-1<a[ab][!m]){
                a[++now][m]=a[ab++][!m];
            }else{
                a[++now][m]=a[aa++][!m]-1;
                if(a[now][m]==0){
                    zero=1;
                }
            }
        }
        while(aa<=mid){
            a[++now][m]=a[aa++][!m]-1;
            if(a[now][m]==0){
                zero=1;
            }
        }
        while(ab<=n){
            a[++now][m]=a[ab++][!m];
        }
        if(zero){
            for(int i=1;i<=n;i++){
                printf("%d ",a[i][m]);
            }
            return 0;
        }
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

