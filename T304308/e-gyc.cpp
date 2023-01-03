#include<cstdio>
#include<algorithm>
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

#define STACK_DATA_TYPE int
const int STACK_SIZE=1000050;struct stack{STACK_DATA_TYPE _null,s[STACK_SIZE];int s_top;stack(){s_top=0;return;}void push(STACK_DATA_TYPE in){s[s_top]=in;++s_top;return;}void pop(){--s_top;return;}void pop(int in){s_top-=in;return;}STACK_DATA_TYPE top(){return s[s_top-1];}void clear(){s_top=0;}bool empty(){if(s_top==0){return true;}else{return false;}}int size(){return s_top;}STACK_DATA_TYPE read(int in){return s[in];}};

#define QUEUE_TYPE int
const int QUEUE_SIZE=1000050;struct QUEUE{QUEUE_TYPE q[QUEUE_SIZE];int head,tail;QUEUE(){head=0;tail=-1;return;}void push(QUEUE_TYPE in){q[++tail]=in;return;}void pop(){head=head+1;return;}void pop_back(){tail=tail-1;return;}QUEUE_TYPE front(){return q[head];}QUEUE_TYPE back(){return q[tail];}void clear(){head=0;tail=-1;return;}bool empty(){if(tail+1==head)return true;else return false;}int size(){return tail-head+1;}QUEUE_TYPE read(int in){return q[head+in];}};

stack S;
QUEUE Q;

struct node{
    int to,next;
}e1[1000050],e2[1000050];

int tot1,tot2,dfn_now,color_now,head1[1000050],head2[1000050],V[1000050],V2[1000050],dfn[1000050],low[1000050],color[1000050],dp[1000050],d[1000050];
char instack[1000050],vis[1000050];

void addEdge(int u,int v,int *head,node *e,int &tot){
    e[tot].to=v;
    e[tot].next=head[u];
    head[u]=tot;
    ++tot;
    return;
}

void tarjan(int u){
    vis[u]=1;
    low[u]=dfn[u]=++dfn_now;
    S.push(u);
    instack[u]=1;
    for(int i=head1[u];~i;i=e1[i].next){
        if(!dfn[e1[i].to]){
            tarjan(e1[i].to);
            low[u]=std::min(low[u],low[e1[i].to]);
        }else if(instack[e1[i].to]){
            low[u]=std::min(low[u],dfn[e1[i].to]);
        }
    }

    if(dfn[u]==low[u]){
        ++color_now;
        color[u]=color_now;
        instack[u]=0;
        V2[color_now]=V[u];
        while(S.size()&&S.top()!=u){
            color[S.top()]=color_now;
            V2[color_now]+=V[S.top()];
            instack[S.top()]=0;
            S.pop();
        }
        S.pop();
    }
}

int main(){
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
    register int i,u,v,ans=0;
    int n=read();
    int m=read();

    head1[0]=head2[0]=-1;
    for(i=1;i<=n;++i) V[i]=read(),head1[i]=head2[i]=-1;
    for(i=0;i<m;++i){
        u=read();
        v=read();
        addEdge(u,v,head1,e1,tot1);
    }

    for(i=1;i<=n;++i)
        if(!vis[i])
            tarjan(i);

    for(i=1;i<=n;++i)
        for(u=head1[i];~u;u=e1[u].next){
            addEdge(color[i],color[e1[u].to],head2,e2,tot2);
            ++d[color[e1[u].to]];
        }

    for(i=1;i<=color_now;++i)
        if(!d[i]){
            dp[i]=V2[i];
            Q.push(i);
        }

    while(Q.size()){
        u=Q.front();
        ans=std::max(ans,dp[u]);
        Q.pop();
        for(i=head2[u];~i;i=e2[i].next){
            dp[e2[i].to]=std::max(dp[e2[i].to],dp[u]+V2[e2[i].to]);
            --d[e2[i].to];
            if(!d[e2[i].to]) Q.push(e2[i].to);
        }
    }

    print(ans);

    return 0;
}
