#include <iostream>
#include <vector>

using namespace std;

int linear_search(vector<int> arr,int target){
    
    int arr_length = arr.size();

    for(int i = 0 ; i < arr_length ; i++){
        if(arr[i] == target){
            return i;
        }    
    }

    return -1;
}


int main(){
    
    vector<int> arr = {1,2,3,4,5};
    int target = 3;

    int found = linear_search(arr,target);

    if(found == -1){
        cout << "not found :(" << endl;
    } 
    else{
        cout << "found at index : " << found << endl;
    }

    return 0;
}