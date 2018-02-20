#include<stdio.h>
#include<stdlib.h>
int main()
{
struct process{
	
	int at;	//Arrival time
	int bt;	//Burst time
	int p;	//process no
	int ct;	//Completion time
	int tat; //Turn around time
	int wt;	//Waiting time
};
int n,i,j;
float avgtt=0,avgwt=0;
printf("no of process");
scanf("%d",&n);
struct process p[n]; 


for(i=0;i<n;++i)
{
//printf("\nProcess ID,AT%d,BT%d for the processes in order:",i+1,i+1);
p[i].p=i+1;
printf("\nenter the process number");
scanf("%d",&p[i].p);
printf("arrival time");
scanf("%d",&p[i].at);
printf("burst time");
scanf("%d",&p[i].bt);
}

struct process temp;
for(i=0;i<n-1;++i)	//sorting
{
	for(j=0;j<n-i-1;++j)
	{
		if(p[j].at>p[j+1].at)
		{
			temp=p[j];
			p[j]=p[j+1];
			p[j+1]=temp;
		}
	}
}


for(i=0;i<n;++i)
{
	if(i==0)
	{
		p[0].ct=p[0].at+p[0].bt;
		p[0].tat=p[0].ct-p[0].at;
		p[0].wt=p[0].tat-p[0].bt;
	}
	else
	{
		p[i].ct= p[i-1].ct+p[i].bt;
		p[i].tat=p[i].ct-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
		avgtt+=p[i].tat;
		avgwt+=p[i].wt;
	}
}

printf("\nID\twt\tat\tCT\tTAT\tWT\n");
for(i=0;i<n;++i)
{
printf("%d      %d     %d     %d     %d       %d",p[i].p,p[i].wt,p[i].at,p[i].ct,p[i].tat,p[i].wt);
printf("\n");
}
avgtt=avgtt/n;
avgwt=avgwt/n;
printf("Average TT: %f",avgtt);
printf("\nAverage WT: %f",avgwt);
printf("\n");


}
