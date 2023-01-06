#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read();
int a[1000005];
int que[2000005];
int ans[1000005];
int l=1,r=0;
class node{
    public:
        int l,r;
        int i;
}ques[1000005];
int sum[1000005];
bool operator <(node a,node b){
    return a.r==b.r?a.l<b.l:a.r<b.r;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	#endif
    int n=read();int m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=m;i++){
        ques[i].l=read();
        ques[i].r=read();
        ques[i].i=i;
    }
    std::stable_sort(ques+1,ques+m+1);
    // for(int j=1;j<=ques[1].r;i++){
    //     while(l<=r&&sum[que[r]]>sum[j]){
    //         r--;
    //     }
    //     que[++r]=j;
    // }
    for(int i=1;i<=m;i++){
        if(ques[i].r!=ques[i-1].r){
            for(int j=ques[i-1].r+1;j<=ques[i].r;j++){
                while(l<=r&&sum[que[r]]>sum[j]){
                    r--;
                }
                que[++r]=j;
            }
        }
        int a=std::lower_bound(que+l,que+r+1,ques[i].l-1)-que;
        // printf("%d\n",sum[ques[i].r]-sum[que[a]]);
        ans[ques[i].i]=sum[ques[i].r]-sum[que[a]];
    }
    for(int i=1;i<=m;i++){
        printf("%d\n",ans[i]);
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


