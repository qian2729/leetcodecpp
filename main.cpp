#include <iostream>
#include <vector>

#include "ReversePair.h"
using namespace std;

void print(int *arr, int n){
    for (int i = 0; i < n; ++i){
        printf("%d ", arr[i]);
    }
    cout << endl;
}
template  <typename T>
void print_vector(vector<T> vec){
    for(size_t i = 0; i < vec.size(); ++i){
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[]  = {7,5,6,4};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> vec(arr,arr + size);
    cout << count(vec, vec.size());
//    print_vector(vec);
    return 0;
}