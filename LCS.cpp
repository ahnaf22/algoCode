#include<bits/stdc++.h>
using namespace std;
#define MAX 10000

int lx,ly,c[MAX][MAX];
char x[MAX],y[MAX],b[MAX][MAX];

int lcs_length(int m,int n)
{

    for(int i=1;i<=m;i++)
    {
            for(int j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='T';
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]='U';
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]='L';
            }
        }
    }

    return c[m][n];


}

void print_lcs(int m,int n)
{
    if(m==0||n==0)
    {
        return;
    }
    else if(b[m][n]=='T')
    {
        print_lcs(m-1,n-1);
        cout<<x[m-1];
    }
    else if(b[m][n]=='U')
    {
        print_lcs(m-1,n);
    }
    else
    {
        print_lcs(m,n-1);
    }
}




int main()
{

    gets(x);
    gets(y);
    lx=strlen(x);
    ly=strlen(y);

    int e=lcs_length(lx,ly);
    cout<<"\nLCS IS: "<<e<<endl;
    cout<<"\nSubsequence is: "<<endl;
    print_lcs(lx,ly);
    cout<<endl;




    return 0;
}




