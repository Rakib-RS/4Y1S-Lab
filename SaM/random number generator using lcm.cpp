#include<bits/stdc++.h>
using namespace std;
int main(){
    double a,c,x0,x1,m;
    int n,i;
    printf("Enter seed(x0),constant multiplier(a),increment(c),mod(m),n:");
    scanf("%lf %lf %lf %lf %d",&x0,&a,&c,&m,&n);
    freopen("random.txt","w",stdout);

    for(i=1;i<=n;i++){
        x1 = (a*x0+c);
        x1 = fmod(x1,m);
        x0 = x1;
        printf("%.2lf ",x1);
        if(i%20==0)
            printf("\n");
    }

    return 0;
}
