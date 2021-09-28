
///round robin

#include <stdio.h>
const int N=1000,MAX=1e9;
int a[1000],b[1000],bt[1000],n; ///burst array and burst temp array
long long int w[1000],c[1000],t[1000];
void roundRobin(int x){
    int doneC=0,lastT=0; ///counter for done processes, last time used
    while(doneC<n){
        int mnT=MAX; ///get the minimum time
        ///if the minimum time in the following unfinished jobs is> lastT, skip to that time
        for(int i=0;i<n;i++){
            if(!bt[i])
                continue;
            if(a[i]<mnT)
                mnT=a[i];
        }
        if(mnT> lastT)
            lastT= mnT;
        ///basic round robin algorithm:
        for(int i=0;i<n;i++){
            if(!bt[i])
                continue;
            if(a[i]>lastT)
                continue;
            if(bt[i]<=x){
                lastT+=bt[i];
                bt[i]=0;
                c[i]= lastT;
                doneC++;
            }
            else{
                lastT+=x;
                bt[i]-=x;
            }
        }
    }

}
void calculateWait(){
    for(int i=0;i<n;i++){
        w[i]= c[i]- b[i]-a[i];
    }
}

void calculateTurnaround(){
    for(int i=0;i<n;i++){
        t[i]= b[i]+w[i];
    }
}
int getAverageTurnaround(){
    long long int sum=0;
    for(int i=0;i<n;i++){
        sum+= t[i];
    }
    sum/=n;
    return (int)sum;
}
int getAverageWaiting(){
    long long int sum=0;
    for(int i=0;i<n;i++){
        sum+= w[i];
    }
    sum/=n;
    return (int)sum;
}
void print(){
    printf("The following schedule represents the processes running using Round Robin algorithm:\n\n");
    printf("Arrival time # burst time  # waiting time # completion time # turnaround time\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t",a[i]);
        printf("%d\t\t",b[i]);
        printf("%d\t\t",w[i]);
        printf("%d\t\t",c[i]);
        printf("%d\t\t\t",t[i]);
        printf("\n");
    }
    printf("Average turn around time: %d\n",(getAverageTurnaround()));
    printf("Average waiting time: %d\n",(getAverageWaiting()));
}
int main(){
    int qt;
    printf("This code will run n processes, using round robin algorithm:\nPlease enter QT: ");
    scanf("%d",&qt);

    printf("\nplease enter the number of processes\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Process # %d:\n",i+1);
        printf("Arrival time: ");
        scanf("%d",a+i);
        printf("\nBurst time: ");
        scanf("%d",b+i);
        bt[i]=b[i];
        printf("\n**********************\n\n");
    }
    roundRobin(qt);
    calculateWait();
    calculateTurnaround();
    print();
    return 0;
}
