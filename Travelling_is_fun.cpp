#include<bits/stdc++.h>
using namespace std;

int find(vector<int> par,int u)
{
    int x=par[u];
    if(x!=u)
    {
        return find(par,x);
    }
    return x;
}

int main()
{
    int n,g,q;
    cin>>n>>g>>q;
    
    vector<int> par(n+1);
    
    for(int i=0;i<=n;i++)
    {
        par[i]=i;
    }
    
    for(int i=g+1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(__gcd(i,j)>g)
            {
                int x=find(par,i);
                int y=find(par,j);
                
                par[x]=y;
            }
        }
    }
    
    vector<int> ori(q);
    for(int i=0;i<q;i++)
    {
        cin>>ori[i];
    }
    
    int j;
    cin>>j;
    vector<int> dest(q);
    for(int i=0;i<q;i++)
    {
        cin>>dest[i];
    }
    
    vector<int> res;
    
    for(int i=0;i<q;i++)
    {
        int a=ori[i];
        int b=dest[i];
        
        if(find(par,a)==find(par,b))
        {
            res.push_back(1);
        }
        else
        {
            res.push_back(0);
        }
    }
    
    for(int i=0;i<q;i++)
    {
        cout<<res[i]<<" ";
    }
    
    return 0;
}