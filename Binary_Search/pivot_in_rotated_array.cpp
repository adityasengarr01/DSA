#include<bits/stdc++.h>
using namespace std;

int pivot(int arr[], int n){

    int s = 0;
    int e = n - 1;

    while(s < e){

        int mid = s + (e - s) / 2;

        if(arr[mid] >= arr[0]){
            s = mid + 1;
        }
        else{
            e = mid;
        }
    }

    return s;
}

int main(){

    int arr[5] = {3,8,10,17,1};

    cout << "Pivot Index: " << pivot(arr, 5) << endl;

    return 0;
}