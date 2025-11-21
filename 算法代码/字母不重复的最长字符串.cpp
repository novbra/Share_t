#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	bool letter[128];
		int ans=0;
		for(int p1=0,p2=0;p2<s.size();){
			if(!letter[s[p2]]){
				//不重复
				letter[s[p2]]=true;
				ans=max(ans,p2-p1+1);
				p2++;
			}else{
				//重复字母
				//删去p1指向元素在letter数组的标记
				letter[s[p1]]=false;
				//移动p1指针
				p1++;
			}
		}
    	return ans;
    }
};

int main(){
	string t;
	cin>>t;
	Solution s=new Solution(t);
	cout<<s.lengthOfLongestSubstring()<<"\n";
	return 0;
}