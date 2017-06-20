#include<bits/stdc++.h>
using namespace std;
vector<int> edge[100], cost[100];
const int infinity =999999;
struct data
{
    int city, dist;
    bool operator < (const data &p) const
    {
        return dist > p.dist;
    }
};

int dijkstra(int source, int destination)
{

    int d[100];
    for(int i=0; i<100; i++) d[i] = infinity;

    priority_queue<data> q;
    data u, v;
    u.city = source, u.dist = 0;
    q.push( u );
    d[ source ] = 0;

    while( !q.empty() )
    {
        u = q.top(); q.pop();
        int ucost = d[ u.city ];
        for(int i=0; i<edge[u.city].size(); i++)
        {
            v.city = edge[u.city][i], v.dist = cost[u.city][i] + ucost;
            if( d[v.city] > v.dist )
            {
                d[v.city] = v.dist;
                q.push( v );
            }
        }
    }

    return d[ destination ];
}
int main()
{
    int e,n,p,q,c,s,en;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        cin>>p>>q;
        edge[p].push_back(q);
        edge[q].push_back(p);
        cost[p].push_back(1);
        cost[q].push_back(1);
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int a=dijkstra(i,j);
            if(a==infinity)
                cout<<"-"<<" ";
            else
                cout<<a<<" ";

        }
        cout<<endl;
    }


}
