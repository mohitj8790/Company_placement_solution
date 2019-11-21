#include<bits/stdc++.h>
using namespace std;

bool isVowel(char ch)
{
    return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
}

int longestStringVow(string str)
{
    int n=str.size();
    int start=0;
    int end=n-1;
    
    while(start<n && isVowel(str[start]))
    {
        start++;
    }
    
    while(end>=0 && isVowel(str[end]))
    {
        end--;
    }
    
    if(start>=n)
    {
        return n;
    }
    
    int res=start+n-1-end;
    
    int count=0;
    int longest=0;
    
    for(int i=start+1;i<=end;i++)
    {
        if(isVowel(str[i]))
        {
            count++;
        }
        else
        {
            count=0;
        }
        
        longest=max(longest,count);
    }
    
    return res+longest;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string str;
    cin>>str;
    
    cout<<longestStringVow(str);
}