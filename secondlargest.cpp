#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int largest = arr[0];
    int second_largest = INT_MIN; // Initialize to the smallest possible integer
    for(int i = 0; i < n; i++){
        if(arr[i] > largest){
            second_largest = largest; // Update second largest before changing largest
            largest = arr[i];
        } else if(arr[i] > second_largest && arr[i] != largest){
            second_largest = arr[i];
        }
    }
    /*if(second_largest == INT_MIN){
        cout << "No second largest element found." << endl;
    } else {
        cout << "Second largest element is: " << second_largest << endl;
    }*/
    cout << "Second largest element is: " << second_largest << endl;
    return 0;
}