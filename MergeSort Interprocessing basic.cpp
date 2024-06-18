#include <bits/stdc++.h> 

long long countInversions;

void merge(long long *arr, int n, int s,int mid, int e){
    if(s >= e) return;
    // cout<< s << " " << e << endl;
    int i = s;
    int j = mid+1;
    int k = 0;
    vector< long long > temp(e - s + 1);
    while( i <= mid && j <= e){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else {
            countInversions+=(mid - i + 1);
            temp[k++] = arr[j++];
        }
    }
    while( i <= mid){
            // countInversions++;
            temp[k++] = arr[i++];
    }
    while( j <= e){
            temp[k++] = arr[j++];
    }
    for(int i =0; i < temp.size(); i++){
        arr[s + i] = temp[i];
    }
}


void mergeSort(long long *arr, int n, int s, int e){
    if(s >= e) return;
    // cout<< s << " " << e << endl;
    int mid = (s + e)/2;
     mergeSort(arr, n, s, mid);
     mergeSort(arr, n, mid+1, e);
    merge(arr, n, s, mid, e); 
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    countInversions = 0;
    mergeSort(arr, n, 0, n-1);
    return countInversions;
}
