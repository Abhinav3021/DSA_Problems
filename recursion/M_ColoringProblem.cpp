/*
Given an undirected graph and an integer M. The task is to determine if the graph can be colored with at most M colors such that no two adjacent vertices of the graph are colored with the same color. Here coloring of a graph means the assignment of colors to all vertices. Print 1 if it is possible to colour vertices and 0 otherwise.
*/

#include<bits/stdc++.h>
using namespace std ;

class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    bool safty(bool graph[101][101], int n,int node,vector<int> color,int currentColor){
        for(int k=0;k<n;k++){
            if(k!=node && graph[node][k]==1 && color[k]==currentColor){
                return false;
            }   // safty function will check weather the adjecent node have the same color or not
        }
        return true;
    }
    bool solve(bool graph[101][101], int m, int n,int node,vector<int> color){
        //base case
        if(node==n){
            return true;
        }
        for(int k=0;k<m;k++){
            if(safty(graph,n,node,color,k)){
            color[node]=k;
            if(solve(graph,m,n,node+1,color)) return true; //If that recursive call returns true, it means the graph can be colored successfully, so return true
            color[node]=-1;  //If the recursive call returns false, it means that coloring didn't work, so backtrack by resetting the color of the current node (color[node] = -1).
            }
        }
        return false; //If no valid color is found for the current node, return false
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector <int> color(n,-1);
        if(solve(graph,m,n,0,color)) return true;
        return false;
    }
};