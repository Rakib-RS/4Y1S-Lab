#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main()
{
    int n,i,m;
    printf("Enter n & mod(m) :");
    scanf("%d%d",&n,&m);
	srand(time(0));
	freopen("random.txt","w",stdout);

	for(i = 1; i<=n; i++){
		printf("%d ", rand()%m);
		if(i%40==0)
            printf("\n");
	}

	return 0;
}

