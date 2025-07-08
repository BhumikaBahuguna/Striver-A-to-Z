#include<bits/stdc++.h>
using namespace std;
int seclargest(vector<int>&a,int n){
    int largest=a[0];
    int second_largest=INT_MIN; // Initialize to the smallest possible integer
    for(int i=0;i<n;i++){
        if(a[i]>largest){
            second_largest=largest; // Update second largest before changing largest
            largest=a[i];
        }else if(a[i]>second_largest && a[i]!=largest){
            second_largest=a[i];
        }
    }
    return second_largest;
}
int secsmallest(vector<int>&a,int n){
    int smallest=a[0];
    int second_smallest=INT_MAX; // Initialize to the largest possible integer
    for(int i=0;i<n;i++){
        if(a[i]<smallest){
            second_smallest=smallest; // Update second smallest before changing smallest
            smallest=a[i];
        }else if(a[i]<second_smallest && a[i]!=smallest){
            second_smallest=a[i];
        }
    }
    return second_smallest;
}
vector<int> getsecondorderelements(vector<int>&a,int n){
    int slargest=seclargest(a,n);
    int ssmallest=secsmallest(a,n);
    return {slargest,ssmallest};
}

