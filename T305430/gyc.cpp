#include<cstdio>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

#define STACK_DATA_TYPE int
const int STACK_SIZE=1000010;struct stack{STACK_DATA_TYPE _null,s[STACK_SIZE];int s_top;stack(){s_top=0;return;}void push(STACK_DATA_TYPE in){s[s_top]=in;++s_top;return;}void pop(){--s_top;return;}void pop(int in){s_top-=in;return;}STACK_DATA_TYPE top(){return s[s_top-1];}void clear(){s_top=0;}bool empty(){if(s_top==0){return true;}else{return false;}}int size(){return s_top;}STACK_DATA_TYPE read(int in){return s[in];}};

stack S;

int H[1000010],ans[1000010];

int main(){
	#ifdef file
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	#endif

    register int i;
    int n=read();
    for(i=0;i<n;++i) H[i]=read();

    for(i=n-1;~i;--i){
        while(S.size()&&H[i]>=S.top()) S.pop();
        S.push(H[i]);
        ans[i]=S.size();
    }

    for(i=0;i<n;++i){
        print(ans[i]);
        putchar(' ');
    }

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}
