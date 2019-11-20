#include<bits/stdc++.h>
using namespace std;

map<char,int> mp;
vector<char> valid(5);
void init(void)
{
    mp['a']=0;
    mp['e']=1;
    mp['i']=2;
    mp['o']=3;
    mp['u']=4;
    
    valid[0]='a';
    valid[1]='e';
    valid[2]='i';
    valid[3]='o';
    valid[4]='u';
}

bool isValid(string str)
{
    for(auto u:valid)
    {
        size_t found=str.find(u);
        if(found==string::npos)
        {
            return false;
        }
    }
    return true;
}

string longestsubsequence(string str,string ans,int index)
{
    //cout<<ans<<" ";
    if(str.size()==index)
    {
        if(isValid(ans))
        {
            return ans;
        }
        else
        {
            return "";
        }
    }
    
    else
    {
        if(ans.size()==0)
        {
            if(str[index]!='a')
            {
                return longestsubsequence(str,ans,index+1);
            }
            else
            {
                return longestsubsequence(str,ans+str[index],index+1);
            }
        }
        else if(mp[ans[ans.size()-1]]==mp[str[index]])
        {
            return longestsubsequence(str,ans+str[index],index+1);
        }
        else if(mp[ans[ans.size()-1]]+1==mp[str[index]])
        {
            string s1=longestsubsequence(str,ans+str[index],index+1);
            string s2=longestsubsequence(str,ans,index+1);
            
            if(s1.size()>s2.size())
            {
                return s1;
            }
            else
            {
                return s2;
            }
        }
        else
        {
            return longestsubsequence(str,ans,index+1);
        }
    }
}

int main()
{
    init();
    string str;
    cin>>str;
    
    string ans="";
    
    cout<<longestsubsequence(str,ans,0).size();
    return 0;
}