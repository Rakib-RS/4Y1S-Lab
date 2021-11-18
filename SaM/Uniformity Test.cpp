#include<bits/stdc++.h>
using namespace std;
int totalNumbers,mod;
void lcm(){
    double a,c,x0,m,x1;
    int n,i;

    printf("Enter seed(x0),constant multiplier(a),increment(c),mod(m),numbers(n):");
    scanf("%lf %lf %lf %lf %d",&x0,&a,&c,&m,&n);
    freopen("random.txt","w",stdout);
    totalNumbers = n;
    mod = m;

    for(i=1;i<=n;i++){
        x1 = (a*x0+c);
        x1 = fmod(x1,m);
        x0 = x1;
        printf("%.2lf ",x1);
        if(i%20==0)
            printf("\n");
    }

}
void builtRand(){
    int n,i,m;
    printf("Enter n & mod(m) :");
    scanf("%d%d",&n,&m);
    totalNumbers = n;
    mod = m;
	srand(time(0));
	freopen("random.txt","w",stdout);

	for(i = 1; i<=n; i++){
		printf("%d ", rand()%m);
		if(i%40==0)
            printf("\n");
	}

}
int main(){
    int opt,cls,diff;
    double b,reminder,ex=10;
    printf("Enter 1 for lcm or 2 otherwise:");
    cin>>opt;
    if(opt==1)
        lcm();
    else
        builtRand();
    ifstream inFile;
    inFile.open("random.txt");
    cout<<endl<<endl;;
    cls = 10;
    diff = mod/10;
    //reminder = totalNumbers%100;
    //if(cls == 0) cls++;
    ex = totalNumbers/cls;

    int ob[cls+5]={0},i;
    double j,calc[cls+5],sum = 0;

    while(inFile>>b){
        i = b/diff;
        //cout<<b<<" i="<<i<<endl;

        ob[i+1]++;
    }
   // cout<<ob[0];
   cout<<"i   "<<"Range    "<<"Oi    "<<"Ei    "<<" (Oi-Ei)^2/Ei"<<endl;
    for(i=1;i<=cls;i++){
        j =  ob[i] - ex;
        j = (j*j*1.0)/ex;
        calc[i] = j;
        sum += j;

        cout<<i<<"   "<<(i-1)*diff<<"-"<<i*diff-1<<"      "<<ob[i]<<"    "<<ex<<"     "<<calc[i]<<endl;
    }
    cout<<"Total = chi2 = "<<sum<<endl;
    if(sum>=1.73&& sum<=23.6)
        cout<<"ACCEPTED"<<endl;
    else
        cout<<"NOT ACCEPTED"<<endl;

    return 0;
}

