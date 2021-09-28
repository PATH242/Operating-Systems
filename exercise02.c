
///Shortest job first

#include <stdio.h>
const int N=1e3;
int a[1000],b[1000],n;
long long int w[1000],c[1000],t[1000];
void calculateWait(){
    w[0]=a[0];
    for(int i=1;i<n;i++){
        w[i]=b[i-1]+w[i-1];
    }
    for(int i=0;i<n;i++){
        w[i]-=a[i];
        if(w[i]<0)
            w[i]=0;
    }
}
void calculateCompletion(){
    for(int i=0;i<n;i++){
        c[i]= t[i]+ a[i];
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
    printf("The following schedule represents the processes running using SJF:\n\n");
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
    printf("please enter the number of processes\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Process # %d:\n",i+1);
        printf("Arrival time: ");
        scanf("%d",a+i);
        printf("\nBurst time: ");
        scanf("%d",b+i);
        printf("\n**********************\n\n");
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                int temp= a[j];
                a[j]= a[j+1];
                a[j+1]=temp;
                temp= b[j];
                b[j]= b[j+1];
                b[j+1]=temp;
            }
            else
            if(a[j]==a[j+1]){
                if(b[j]>b[j+1]){
                   int temp= a[j];
                    a[j]= a[j+1];
                    a[j+1]=temp;
                    temp= b[j];
                    b[j]= b[j+1];
                    b[j+1]=temp;
                }
            }
        }
    }
    calculateWait();
    calculateTurnaround();
    calculateCompletion();
    print();
    return 0;
}
