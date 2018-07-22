#include<cstdio>
#include<string>

double p1[1001] = {0.0},p2[1001] = {0.0},ans[2001] = {0.0};

int main(){
	int k1,k2,count=0;
	scanf("%d",&k1);
	for(int i=0;i < k1;++i){
		int exp;
		float coe;
		scanf("%d",&exp);
		scanf("%lf",&p1[exp]);
	}
	scanf("%d",&k2);
	for(int i=0;i < k2;++i){
		int exp;
		float coe;
		scanf("%d",&exp);
		scanf("%lf",&p2[exp]);
	}
	for(int i=0;i < 1001;++i){
		if(p1[i] == 0) continue;
		for(int j=0;j < 1001;++j){
			if(p2[j] == 0) continue;
			int exp,coe;
			ans[i+j] += (p1[i]*p2[j]);
		}
	}
	for(int i=0;i < 2001;++i){
		if(ans[i] != 0.0)
			++count;
	}
	printf("%d",count);
	for(int i=2000;i >=0;--i){
		if(ans[i] != 0.0)
			printf(" %d %.1f",i,ans[i]);
	}
	printf("\n");
	return 0;
}