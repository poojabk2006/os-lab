#include<stdio.h>

int main()
{
    int n,i,j,small,time=0,count=0;
    int at[20],bt[20],ct[20],tat[20],wt[20];
    int completed[20]={0};
    float avgwt=0,avgtat=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter Arrival Time and Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("P%d AT: ",i+1);
        scanf("%d",&at[i]);
        printf("P%d BT: ",i+1);
        scanf("%d",&bt[i]);
    }

    while(count<n)
    {
        small=-1;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && completed[i]==0)
            {
                if(small==-1 || bt[i]<bt[small])
                small=i;
            }
        }

        if(small==-1)
        {
            time++;
        }
        else
        {
            time=time+bt[small];
            ct[small]=time;
            tat[small]=ct[small]-at[small];
            wt[small]=tat[small]-bt[small];

            avgwt+=wt[small];
            avgtat+=tat[small];

            completed[small]=1;
            count++;
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f",avgtat/n);
    printf("\nAverage Waiting Time = %.2f",avgwt/n);

    return 0;
}
