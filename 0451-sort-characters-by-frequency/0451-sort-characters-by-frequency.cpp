class Solution {
public:
    string frequencySort(string s) {
    string ans="";
    int freq[256]={0};
    for(int i=0;i<s.length();i++){
        freq[s[i]]++;
    }
    
    vector<pair<int,char>> v;
    for(int i=0;i<256;i++){
        if(freq[i]>0){
            v.push_back({freq[i],(char)i});
        }
    }
    sort(v.begin(),v.end(),greater<pair<int,char>>());
    for(int i=0;i<v.size();i++){
        ans.append(v[i].first,v[i].second);//(3,'a')===>>> aaa
    }
    return ans;

    }
};