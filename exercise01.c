#include <stdio.h>
int getLowestRbit(int* CA, int* pageFrame){
    int mn= 11111111,mni=-1;
    for(int i=1;i<10001;i++){
        if((*(pageFrame+i))==0)
            continue;
        if(*(CA+i)<mn){
            mni=i;
            mn=*(CA+i);
        }
    }
    return mni;
}
int main(){
    int n,m,t[1000],a,rbit[10000],CA[10000]; ///CA is counter for ageing algorithm
    int pageFrame[10000];
    memset(pageFrame,0,sizeof pageFrame);
    memset(rbit,0,sizeof rbit);
    memset(CA,0,sizeof CA);
    int usedPagesNumber=0,hit=0,miss=0;
    
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",t+i,&a);
        if(i&&t[i]!=t[i-1]){
            for(int j=0;j<10001;j++){
                CA[j]= ((CA[j]>>1) | ((rbit[j]==t[i-1])<<7));
                rbit[j]=0;
            }
        }
        rbit[a]=t[i];
        if(pageFrame[a]){
            hit++;
            printf("1\n");
        }
        else{
            miss++;
            printf("0\n");
            if(usedPagesNumber<n){
                pageFrame[a]=1;
                usedPagesNumber++;
            }
            else{
                pageFrame[getLowestRbit(&CA, &pageFrame)]=0;
                pageFrame[a]=1;
                CA[a]=0;
            }
        }
    }
    printf("%f\n",hit*1.0/miss);
    return 0;
}
