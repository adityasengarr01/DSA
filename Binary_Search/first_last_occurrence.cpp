#include<bits/stdc++.h>
using namespace std;

// Function for First Occurrence
int firstocc(int arr[], int n, int key) {

    int start = 0;
    int end = n - 1;
    int ans = -1;

    while(start <= end) {

        int mid = start + (end - start) / 2;

        if(arr[mid] == key) {
            ans = mid;
            end = mid - 1;
        }

        else if(arr[mid] > key) {
            end = mid - 1;
        }

        else {
            start = mid + 1;
        }
    }

    return ans;
}

// Function for Last Occurrence
int lastocc(int arr[], int n, int key) {

    int start = 0;
    int end = n - 1;
    int ans = -1;

    while(start <= end) {

        int mid = start + (end - start) / 2;

        if(arr[mid] == key) {
            ans = mid;
            start = mid + 1;
        }

        else if(arr[mid] > key) {
            end = mid - 1;
        }

        else {
            start = mid + 1;
        }
    }

    return ans;
}

int main() {

    int arr[5] = {1, 2, 3, 3, 4};

    cout << "First Occurrence: "
         << firstocc(arr, 5, 3) << endl;

    cout << "Last Occurrence: "
         << lastocc(arr, 5, 3);

    return 0;
}