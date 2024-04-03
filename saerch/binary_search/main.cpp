#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> arr , int target){
    
    int start = 0;
    int end = arr.size() - 1;
    
    while(start <= end){

        int mid = start + (end - start) / 2;

        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] > target){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }

    return -1;
}

int main(){

    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int target = 10;

    cout << binary_search(arr,target) << endl;
    return 0;
}