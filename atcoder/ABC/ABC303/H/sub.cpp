#include <stdio.h>

int main(void)
{
	int people, count, i,j,matrix[50][50],finishflag,s,t,hunaka=0;
	scanf("%d",&people);
	scanf("%d",&count);
	for(i=0;i<=count-1;i++){
		for(j=0;j<=people-1;j++){
			scanf("%d",&matrix[i][j]);
		}
	}
	for(i=1;i<=people-1;i++){
		for(j=i+1;j<=people;j++){
			finishflag = 0;
			for(s=0;s<=count-1;s++){
				for(t=1; t<=people;t++){
					if((matrix[s][t-1] == i && matrix[s][t] == j)||(matrix[s][t-1] == j && matrix[s][t] == i)){
						finishflag = 1;
						break;
					}
					if(finishflag == 1)
						break;
				}
				if(finishflag == 1)
					break;
			}
			if(finishflag == 0)
				hunaka++;
		}
	}
	printf("%d",hunaka);
	return 0;
}