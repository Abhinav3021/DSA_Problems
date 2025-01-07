/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
*/
//To solve the above question we have to find out how far a building an be expands

class Solution {
public:
    vector<int> right;
    vector<int> left;
    void NSL(vector<int>& heights){      //Nearest smaller to left function to find the index through which a building can be expand in left
        stack<int> s;
        for(int i=0;i<heights.size();i++){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){left.push_back(-1);}
            else{
                left.push_back(s.top());
            }
            s.push(i);
        }
    }

    void NSR(vector<int>& heights){     //Nearest smaller to right function to find the index through which a building can be expand in right
        stack<int> s;
        for(int i=heights.size()-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){right.push_back(heights.size());}
            else{
                right.push_back(s.top());
            }
            s.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        NSL(heights);
        NSR(heights);
        reverse(right.begin(),right.end());
        int area=0;
        for(int i=0;i<heights.size();i++){
            area=max(area,heights[i]*(right[i]-left[i]-1));
        }
        return area;
    }
};