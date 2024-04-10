#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {

    std::vector<int> arr = {12, 11, 13, 5, 6};

    insertion_sort(arr);

    for(int i : arr){
        cout << i << endl;
    }


    return 0;
}
