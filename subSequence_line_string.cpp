#include<bits/stdc++.h>
using namespace std;

#define M 1000000007

int dp[1001][2501][2];

int countSubUtil(string str,int n,int start,int end,int idx,bool flag)
{
    if(start<0 || start>n)
    {
        return 0;
    }
    
    if(start==end && str.size()==idx)
    {
        return 1;
    }
    
    if(idx>=str.size())
    {
        return 0;
    }
    
    if(dp[idx][start][flag]!=-1)
    {
        return dp[idx][start][flag];
    }
    
    int ans=0;
    
    if((str[idx]=='l' && flag) || (str[idx]=='r' && !flag))
    {
        int change=str[idx]=='l' ? -1:1;
        
        ans=countSubUtil(str,n,start+change,end,idx+1,flag)+countSubUtil(str,n,start+change,end,idx+1,!flag);
    }
    
    else
    {
        ans=countSubUtil(str,n,start,end,idx+1,flag);
    }
    
    return dp[idx][start][flag]=ans;
}

int countSub(string str,int n,int s,int e)
{
    memset(dp,-1,sizeof(dp));
    return countSubUtil(str,n,s,e,0,true)+countSubUtil(str,n,s,e,0,false);
}

int main()
{
    string str;
    cin>>str;
    int n,s,e;
    cin>>n>>s>>e;
    
    cout<<countSub(str,n,s,e);
    return 0;
}