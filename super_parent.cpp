#include<bits/stdc++.h>
using namespace std;

#define total 256

bool present(vector<string> child,string par)
{
    int n=child.size();
    bool res=true;
    for(int i=0;i<n;i++)
    {
        string ch=child[i];
        
        int char_child[total]={0};
        int char_par[total]={0};
        
        for(int j=0;j<n;j++)
        {
            char_child[ch[j]]++;
        }
        bool find=false;
        int count=0;
        for(int j=0;j<par.size();j++)
        {
            char_par[par[j]]++;
            
            if(char_child[par[j]]!=0 && char_par[par[j]]<=char_child[par[j]])
            {
                count++;
            }
            
            if(count==ch.size())
            {
                find=true;
            }
        }
        
        res=res&find;
        if(!res)
        {
            return false;
        }
        
    }
    
    return true;
}

int main()
{
    int n,m;
    cin>>n;
    vector<string> parent(n);
    for(int i=0;i<n;i++)
    {
        cin>>parent[i];
    }
    
    int t;
    cin>>t;
    vector<string> child(t);
    for(int i=0;i<t;i++)
    {
        cin>>child[i];
    }
    
    vector<string> res;
    
    for(int i=0;i<n;i++)
    {
        bool var=present(child,parent[i]);
        if(var)
        {
            res.push_back(parent[i]);
        }
    }
    
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}