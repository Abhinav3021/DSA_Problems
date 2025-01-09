/*
Given a list of points on the 2-D plane and an integer K. The task is to find K closest points to the origin and print them.

Note: The distance between two points on a plane is the Euclidean distance.
*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> maxheap;
        vector<vector<int>> v;
        for(int i=0;i<points.size();i++){
                int val=points[i][0]*points[i][0] +points[i][1]*points[i][1];
                maxheap.push({val,{points[i][0],points[i][1]}});
                if(maxheap.size()>k){maxheap.pop();}
        }
        while(!maxheap.empty()){
            v.push_back({maxheap.top().second.first,maxheap.top().second.second});
            maxheap.pop();
        }
        return v;
        
    }
};