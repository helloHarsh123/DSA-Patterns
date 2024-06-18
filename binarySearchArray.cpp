int search(vector<int>& arr, int n, int k)
{
    if(k == arr[0]) return 0;

    int pivot = arr[0];

    // 34512
    // k > 3 == mid > 3 : correct combo
    // k > 3 != mid > 3 : reverse combo
    int l = 0, h = n;
    while(l < h){
        int mid = l + (h - l)/2;
        if(arr[mid] == k) return mid;
        if((arr[mid] < arr[0]) == (k < arr[0])){
            if(arr[mid] > k){
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        else{
            if(arr[mid] > k){
                l = mid+1;

            }
            else{
                h = mid-1;
            }
        }
    }
    return (arr[l] == k) ? l : -1;
}
