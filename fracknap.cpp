#include<bits/stdc++.h>
using namespace std;
double w[100],p[1000],cap,n,rat[100],totalpro;
int main()
{
    cout<<"Number of bosta :D : "<<endl;
    cin>>n;

    cout<<"Enter the weight and the profits of Bostas: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>w[i]>>p[i];
    }

    cout<<"Enter the highest capaity: " <<endl;
    cin>>cap;

    for (int i=0;i<n;i++)
    {
      rat[i] = p[i]/w[i];
    }


    for (int i=0;i<n;i++)
    {
      for (int j=0; j<n;j++)
      {
         if (rat[i]>rat[j])
        {
            swap(rat[i],rat[j]);
            swap(w[i],w[j]);
            swap(p[i],p[j]);

         }
      }
   }
   totalpro=0;
   //knapsack starts here
   int k;
   for (k=0;k<n;k++)
    {
      if (w[k]>cap)
         break;
      else
      {
         totalpro+=p[k];
         cap=cap-w[k];
      }
   }
   if (k<n)
   {

       totalpro+=(cap/w[k])*p[k];
   }

   cout<<endl<<"Maximum Profit is : "<<totalpro<<endl;


  return 0;
}
