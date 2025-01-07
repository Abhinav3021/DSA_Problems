


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1) {
        stack<int> s;
        vector<int> v;
        for(int i=0;i<nums1.size();i++){
            if(s.empty()){
                s.push(nums1[i]);
                v[i]=-1;
            }
            else{
                while(!s.empty() && s.top()<=nums1[i]){
                    s.pop();
                }
                (s.empty())? v[i]=-1: v[i]=s.top();
                s.push(nums1[i]);
            }
        }
    
        return v;
    }
};