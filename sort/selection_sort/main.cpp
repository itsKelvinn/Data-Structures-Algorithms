#include <iostream>
#include <vector>

using namespace std;

void selection_sort(vector<int>& arr){
    
    int size = arr.size();

    for(int i = 0; i < size - 1; i++){

        int min_index = i;

        for(int j = i; j < size ; j++){
            if(arr[min_index] > arr[j]){
                min_index = arr[j];
            }
        }

        if(min_index != i){
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }

    }

}

int main(){
    
    vector<int> arr = {2,1,3,5,4};



    selection_sort(arr);


    for(int i : arr){
        cout << i << endl;
    }


    return 0;
}