
int secondLargest(vector <int> a,int n){
    int largest=a[0];
    int slargest=-1;                                 //1 2 3 4 7 7 5
    for(int i=1;i<n;i++){
        if(a[i]>largest){
            slargest=largest;
            largest=a[i];                                //O(N)
        }
        else if(a[i] < largest && a[i]>slargest){
            slargest=a[i];
        }
        
    }
    return slargest;
}
int secondSmallest(vector <int> a,int n){
    int smallest=a[0];
    int ssmallest=INT_MAX;
    for(int i=1;i<n;i++){
        if(a[i]<smallest){
            ssmallest=smallest;
            smallest=a[i];
        }
        else if(a[i]>smallest && a[i] < ssmallest){
            ssmallest=a[i];
        }
    }
    return ssmallest;
}

vector<int> getSecondOrderElements(int n, vector<int> a) {
    // Write your code here.
    vector <int > v;
    int slargest=secondLargest(a,n);
    int sSmallest=secondSmallest(a,n);
    v.push_back(slargest);
    v.push_back(sSmallest);
    return v;
}

