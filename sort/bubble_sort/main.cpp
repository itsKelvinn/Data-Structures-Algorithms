#include <iostream>
#include <vector>

using namespace std;


void bubble_sort(vector<int>& arr){
    for(int i = 0 ; i < arr.size() - 1 ; i++){
        for(int j = 0; j < arr.size() - 1 - i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}



int main() {
    
    vector<int> arr = {4,2,5,3,1};

    bubble_sort(arr);

    for(int i : arr){
        cout << i << endl;
    }

    return 0;
}
