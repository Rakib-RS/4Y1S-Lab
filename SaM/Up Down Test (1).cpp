
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
    double b,reminder,ex=10,a=-1;
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

    int ob[cls+5]={0},i=0,run[totalNumbers+5],k,nRun=0;
    double j,calc[cls+5],sum = 0,mean,variance,z;

    while(inFile>>b){
            if(a!=-1){
                if(a>b){
                    run[i++] = -1;
                }
                else run[i++] = 1;
            }
            a = b;


    }
    cout<<"The sequence of runs up and down is as follows:"<<endl;
    for(k=0;k<i-1;k++){
        if(run[k]==1) cout<<"+  ";
        else cout<<"-  ";
        if(k%40==0 && k>0) cout<<endl;
        if(run[k]==run[k+1])
            continue;
        nRun++;


    }
    if(run[k]==1) cout<<"+ \n";
    else cout<<"-  \n";
    nRun++;
    //cout<<nRun<<endl;
    mean = (2.0*totalNumbers - 1)/3.0;
    variance = (16.0 * totalNumbers - 29)/90.0;
    cout<<"Total numbers(N) = "<<totalNumbers<<endl;
    cout<<"a = "<<nRun<<endl;
    cout<<"mean = "<<mean<<endl;
    cout<<"variance = "<<variance<<endl;
    variance = sqrt(variance);
    z = (nRun - mean)/(variance * 1.0);
    cout<<"Zo = "<<z<<endl;
    if(z>=-1.96 && z<=1.96)
        cout<<"ACCEPTED"<<endl;
    else
        cout<<"NOT ACCEPTED"<<endl;

    return 0;
}

