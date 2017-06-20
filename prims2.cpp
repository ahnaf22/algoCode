#include<bits/stdc++.h>
using namespace std;
vector<int>adj[1000];
int cost[1000][1000];
int vis[10000][10000];
#define pb push_back
int n,e;
int node;
int c=0,f=0,inf=99999;
int m=inf;

void prims()
{
    int f=0;
    for(int k=1;k<=n;k++)
    {
            for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(cost[i][j]<m)
                {
                    m=cost[i][j];
                    cost[i][j]=inf;
                    cost[j][i]=inf;

                }
            }

        }
        f+=1;
        c+=m;
        m=inf;

    if(f==n-1)
            break;
    }



}


int main()
{
    int x,y,z;


    cout<<"How many Nodes and edges??: "<<endl;
    cin>>n>>e;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cost[i][j]=inf;
        }
    }
    cout<<"enter the connections with cost in the last input: "<<endl;
    for(int i=1;i<=e;i++)
    {
        cin>>x>>y>>z;
        adj[x].pb(y);
        adj[y].pb(x);
        cost[x][y]=z;
        cost[y][x]=z;

    }

   //connections:

    cout<<"connections are: "<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" ---- ";
        for(int j=0;j<adj[i].size();j++)
    {
        cout<<adj[i][j]<<" ";


    }
    cout<<endl;
    }

    cout<<"Costs are:"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<cost[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    prims();
    cout<<"cost is: "<<endl;
    cout<<c<<endl;


    return 0;
}

