#include<bits/stdc++.h>
using namespace std;
int chain(int index[20][20],int cm[],int i,int j);
void mcmPrint(int index[20][20],int i,int j);
int main()
{
    int size,i,value;
    int cm[100];
    int index[20][20];
    cin>>size;
    for(i=0;i<=size;i++)cin>>cm[i];

    value=chain(index,cm,1,size);
    cout<<"Number of multiplication : "<<value<<endl;
    cout<<"Order is : ";
    mcmPrint(index,1,size);
    return 0;

}


int chain(int index[20][20],int cm[],int i,int j)
{
    if(i==j)
        return 0;
    int k,cnt;

    int min=1000000;
    for (k=i;k<j;k++)
    {
        cnt=chain(index,cm,i,k)+chain(index,cm,k+1,j)+cm[i-1]*cm[k]*cm[j];
        if(cnt<min)
        {
            min=cnt;
            index[i][j]=k;
        }
    }
    return min;
}
void mcmPrint(int index[20][20],int i,int j)
{
    if(i==j)cout<<i;
    else
    {
        printf("(");
        mcmPrint(index,i,index[i][j]);
        mcmPrint(index,index[i][j]+1,j);
        printf(")");
    }
}


