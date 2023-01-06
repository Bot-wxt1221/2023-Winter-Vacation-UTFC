#include<cstdio>
#include<algorithm>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

struct node{
    int l,r,index,ans;
    bool operator < (const node another) const{
        return r<another.r;
    }
}qs[1000010];

inline bool cmp(node a,node b){
    return a.index<b.index;
} 

#define QUEUE_TYPE int
const int QUEUE_SIZE=1000010;struct QUEUE{QUEUE_TYPE q[QUEUE_SIZE];int head,tail;QUEUE(){head=0;tail=-1;return;}void push(QUEUE_TYPE in){q[++tail]=in;return;}void pop(){++head;return;}void pop_back(){--tail;return;}QUEUE_TYPE front(){return q[head];}QUEUE_TYPE back(){return q[tail];}void clear(){head=0;tail=-1;return;}bool empty(){return tail+1==head;}int size(){return tail-head+1;}QUEUE_TYPE read(int in){return q[head+in];}};

QUEUE Q;

int sum[1000010];

/*
5 7
-1 2 3 -2 4
1 2
1 3
2 3
1 5
1 4
1 5
3 5
*/

int main(){
	#ifdef file
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif

    register int i,j=0,pos;
    int n=read();
    int m=read();

    for(i=1;i<=n;++i) sum[i]=read()+sum[i-1];
    for(i=0;i<m;++i) qs[i].l=read(),qs[i].r=read(),qs[i].index=i;

    std::sort(qs,qs+m);

    Q.push(0);
    for(i=1;i<=n;i++){
        while(!Q.empty()&&sum[i]<sum[Q.back()]) Q.pop_back();
        Q.push(i);
        while(j<m&&qs[j].r==i){
            pos=std::lower_bound(Q.q,Q.q+Q.size(),qs[j].l-1)-Q.q;
            qs[j].ans=sum[i]-sum[Q.read(pos)];
            j++;
        }
    }

    std::sort(qs,qs+m,cmp);

    for(i=0;i<m;++i){
        print(qs[i].ans);
        putchar('\n');
    }

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}
