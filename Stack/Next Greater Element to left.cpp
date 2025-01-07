

class Solution {
public:
    vector<int> nextGreaterElementToLeft(vector<int>& nums1) {
        stack<int> s;
        vector<int> v;
        for(int i=0;i<nums1.size();i++){ // traverse from left to right( as opposite to we do in brute force approach)
            if(s.empty()){
                s.push(nums1[i]);
                v[i]=-1;
            }
            else{
                while(!s.empty() && s.top()<=nums1[i]){ // if top element of stack is less than or equal to current element then pop it
                    s.pop();
                }
                (s.empty())? v[i]=-1: v[i]=s.top(); // if stack is empty then there is no element greater than current element to its left so answer is -1 else answer is top element of stack
                s.push(nums1[i]);
            }
        }
    
        return v;
    }
};