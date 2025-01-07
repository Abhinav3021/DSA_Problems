
class Solution {
public:
    vector<int> nearestSmallerElementToRight(vector<int>& nums1) {
        stack<int> s;
        vector<int> v;
        for(int i=nums1.size()-1;i>=0;i++){     // traverse from right to left ( as opposite to we do in brute force approach)
            if(s.empty()){
                s.push(nums1[i]);
                v[i]=-1;
            }
            else{
                while(!s.empty() && s.top()>=nums1[i]){  // if top element of stack is greater than or equal to current element then pop it
                    s.pop();
                }
                (s.empty())? v[i]=-1: v[i]=s.top(); // if stack is empty then there is no element smaller than current element to its left so answer is -1 else answer is top element of stack
                s.push(nums1[i]);
            }
        }
    
        return v;
    }
};