#include<bits/stdc++.h>
using namespace std;
int n,e;
int st[10000];
int cost=0;
struct ver
{
    int u,v;
    int wei;
}vm[1000];

void s()
{
    for(int i=1;i<=n;i++)
    {
        st[i]=i;
    }

}

int fnd(int u)
{
    if(st[u]==u)
        return u;
    else
       return fnd(st[u]);

}

bool comp(ver a,ver b)
{
    if(a.wei<b.wei)
        return true;
    else
        return false;
}

int kruskal()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<e;j++)
        {
            if(fnd(vm[j].u)!=fnd(vm[j].v))
            {
                st[fnd(vm[j].u)]=fnd(vm[j].v);
                cost+=vm[j].wei;
            }
            if(j==n-1)
            {
                break;
            }
        }
    }
}

int main()
{
    cout<<"Enter the number of nodes and edges:"<<endl;
    cin>>n>>e;
    cout<<"enter the connections and costs:"<<endl;
    for(int i=0;i<e;i++)
    {
        cin>>vm[i].u>>vm[i].v>>vm[i].wei;

    }
    s();
    sort(vm,vm+e,comp);

    kruskal();
    cout<<"Minimum Cost is: "<<endl;
    cout<<cost<<endl;
  return 0;
}
