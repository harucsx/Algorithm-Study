#include <cstdio>
#include <climits>
typedef long long ll;
int c,n,m;
ll a[111];
ll b[111];
ll d[111][111];

ll max2(ll a,ll b){
    return (a>b ? a : b);
}

int main(void){

    scanf("%d",&c);

    while(c--){
        scanf("%d %d",&n,&m);
        a[0]=b[0]=LLONG_MIN;
        for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
        for(int i=1; i<=m; i++) scanf("%lld",&b[i]);

        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(a[i]==b[j]) d[i][j]=0;
                else{
                    if(i==0 || j==0) d[i][j]=1;
                    else d[i][j]=2;

                    for(int k=0; k<i; k++)
                        if(max2(a[k],b[j])<a[i]) d[i][j]=max2(d[i][j],d[k][j]+1);

                    for(int k=0; k<j; k++)
                        if(max2(a[i],b[k])<b[j]) d[i][j]=max2(d[i][j],d[i][k]+1);
                }
                printf("%d ", d[i][j]);
            }
            printf("\n");
        }

        ll sol=0;
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                sol=max2(sol,d[i][j]);
                //printf("d[%d][%d]=%lld\n",i,j,d[i][j]);
            }
        }
        printf("%lld\n",sol);
    }
    return 0;
}