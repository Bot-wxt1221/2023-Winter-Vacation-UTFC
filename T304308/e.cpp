#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
inline int read();
int w[1000005];
int fir[1000005];
int v[1000005];
int nxt[1000005];
int w2[1000005];
int fir2[1000005];
int v2[1000005];
int nxt2[1000005];
int vised[1000005];
int low[1000005];
int instack[1000005];
int dfn[1000005];
int in[1000005];
int col[1000005];
int df=0;
int co=0;
int now=0,now2=0;
std::stack<int>a;
std::queue<int>b;
int dp[1000005];
void add(int a,int b){
    v[++now]=b;
    nxt[now]=fir[a];
    fir[a]=now;
    return ;
}
void add2(int a,int b){
    in[b]++;
    v2[++now2]=b;
    nxt2[now2]=fir2[a];
    fir2[a]=now2;
    return ;
}
void tarjan(int now){
    low[now]=dfn[now]=++df;
    a.push(now);
    instack[now]=1;
    for(int i=fir[now];i!=-1;i=nxt[i]){
        if(dfn[v[i]]==0){
            tarjan(v[i]);
            low[now]=std::min(low[now],low[v[i]]);
        }else if(instack[v[i]]){
            low[now]=std::min(low[now],dfn[v[i]]);
        }
    }
    if(dfn[now]==low[now]){
        co++;
        col[now]=co;
        instack[now]=0;
        w2[co]=w[now];
        while(a.size()>0&&a.top()!=now){
            int tp=a.top();
            col[tp]=co;
            w2[co]+=w[tp];
            instack[tp]=0;
            a.pop();
        }
        a.pop();
    }
    return ;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
//	 freopen("e.in","r",stdin);
//	 freopen("e.out","w",stdout);
	#endif
    int n=read(),m=read();
    for(int i=1;i<=n;i++){
        w[i]=read();
        fir[i]=-1;
    }
    for(int i=1;i<=m;i++){
        int u=read();
        add(u,read());
    }
    for(int i=1;i<=n;i++){
        if(dfn[i]==0){
            tarjan(i);
        }
    }
    for(int i=1;i<=co;i++){
        fir2[i]=-1;
    }
    for(int i=1;i<=n;i++){
        for(int j=fir[i];j!=-1;j=nxt[j]){
        	if(col[i]!=col[v[j]])
            	add2(col[i],col[v[j]]);            
        }
    }
    int ans=0;
    for(int i=1;i<=co;i++){
        if(in[i]==0){
            b.push(i);
            dp[i]=w2[i];
            ans=std::max(ans,dp[i]);
        }
    }
    ans=0;
    while(b.size()>0){
        int now=b.front();
        b.pop();
        for(int i=fir2[now];i!=-1;i=nxt2[i]){
            dp[v2[i]]=std::max(dp[v2[i]],dp[now]+w2[v2[i]]);
            ans=std::max(ans,dp[v2[i]]);
            in[v2[i]]--;
            if(in[v2[i]]==0){
                b.push(v2[i]);
            }
        }
    }
    printf("%d",ans);
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

