#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
inline int read();
int mod=100000921;
class matrix{
    public:
        int map[10][10];
        int n,m;
        matrix(int nn=0,int nm=0,int tag=0){
            memset(map,0,sizeof(map));
            n=nn;
            m=nm;
            for(int i=1;i<=std::min(n,m);i++){
                map[i][i]=tag;
            }
        }
};
matrix operator * (matrix a,matrix b){
    matrix ans(a.n,b.m,0);
    for(int i=1;i<=a.n;i++){
        for(int j=1;j<=b.m;j++){
            for(int k=1;k<=a.m;k++){
                ans.map[i][j]+=a.map[i][k]*b.map[k][j];
                ans.map[i][j]%=mod;
            }
        }
    }
    return ans;
}
matrix pow(matrix a,int b){
    if(b==0){
        return matrix(a.n,a.n,1);
    }
    if(b%2==0){
        matrix temp=pow(a,b/2);
        return temp*temp;
    }
    return pow(a,b-1)*a;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	// freopen("b.in","r",stdin);
	// freopen("b.out","w",stdout);
	#endif
    int n=read();
    int a=read();
    int b=read();
    int c=read();
    if(n<2){
        printf("1");
        return 0;
    }
    matrix po(6,6,0);
    po.map[1][1]=1;
    po.map[2][1]=1;
    po.map[3][1]=b;
    po.map[4][1]=a;
    po.map[5][1]=c;
    po.map[2][2]=1;
    po.map[3][2]=b;
    po.map[4][2]=a;
    po.map[5][2]=c;
    po.map[2][3]=1;
    po.map[4][4]=1;
    po.map[5][4]=1;
    po.map[6][4]=2;
    po.map[5][5]=1;
    po.map[5][6]=1;
    po.map[6][6]=1;
    matrix bas(1,6,0);
	int f2=1+b+4*a+c;
    bas.map[1][1]=f2+1;
	bas.map[1][2]=f2;
    bas.map[1][3]=bas.map[1][5]=1;
    bas.map[1][4]=9;
    bas.map[1][6]=3;
    po=pow(po,n-2);
    bas=bas*po;
    // bas=bas*po;
    printf("%lld",bas.map[1][1]);
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

