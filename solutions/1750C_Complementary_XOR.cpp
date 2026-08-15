#include <bits/stdc++.h>
using namespace std;
 
 
bool check(string s2,  string s1 , int n){
    for(int i=0 ; i<n ; i++){
        if(s2[i]==s1[i]){
            return false;
        }
 
    }
 
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
 
 
        if(s1!=s2){
            if(check(s1 , s2 , n)==false){
                cout<<"NO\n";
                continue;
            }
        }
 
        // other wise start with the procedure to remove all the zeros . 
        cout<<"YES\n";
        int cnt=0;
        vector<pair<int,int>> ans;
        if(s1!=s2){
            cnt+=1;
            ans.push_back({1 , n});
            for(int i=0; i<n ; i++){
                if(s1[i]=='0'){
                    s1[i]='1';
                }
                else{
                    s1[i]='0';
                }
            }
        }
        // cout<<s1<<"\n";
        int l=0,r=0;
        int cnt2=0;
        while(l<n){
            if(s1[l]=='0'){
                r=l;
                while(r<n && s1[r]=='0'){
                    r++;
                }
                ans.push_back({l+1 , r});
                cnt2++;
                l=r;
            }
            else{
                l++;
            }
        }
 
 
        if(cnt2%2!=0){
           ans.push_back({1 , n}); 
        }
        else{
            ans.push_back({1 , 1});
            ans.push_back({2 , n});
        }
 
        cnt=ans.size();
        cout<<cnt<<"\n";
        for(auto p : ans){
            cout<<p.first<<" "<<p.second<<"\n";
        }
    }
}