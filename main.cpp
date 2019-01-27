#include <iostream>
#include <vector>
/**
 * merges the subarrays iteratively
 * @return
 */

using namespace std;

 void myMerge(vector<int>& arr, int low, int med, int high) {
    int firstIndex = low;
    int secondIndex = med+1;
    int placeholder = low;
    vector<int> v(arr.size());
    while (firstIndex <= med && secondIndex <= high) {
        if (arr[firstIndex] < arr[secondIndex]) {
            v[placeholder] = arr[firstIndex];
            placeholder++; firstIndex++;
        } else {
            v[placeholder] = arr[secondIndex];
            placeholder++; secondIndex++;
        }
    }
    while (firstIndex <= med) {
        v[placeholder] = arr[firstIndex];
        placeholder++; firstIndex++;
    }
    while (secondIndex <= high) {
        v[placeholder] = arr[secondIndex];
        placeholder++; secondIndex++;
    }
    for (int i=low; i<placeholder; i++) {
        arr[i] = v[i];
    }
 }

/**
* Sorts the integers in arr into ascending order
* @param arr
* @param low
* @param high
*/
void mergesort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // Calculate the middle of the array
        int mid = low + (high-low) / 2;

        // Mergesort the first half of the array
        mergesort(arr, low, mid);
//        cout << "First call. Low is " << low << " Mid is " << mid << " high is " << high << endl;
        // Mergesort the second half of the array
        mergesort(arr, mid+1, high);

//        cout << "Low is " << low << " Mid is " << mid << " high is " << high << endl;
//         Merge the arrays
        myMerge(arr, low, mid, high);

    }
}


int main() {
    int myInts[] = {10,3,1,6};
    std::vector<int> v;
    for (int i = 0; i<4; i++) {
        int value = myInts[i];
        v.push_back(value);
    }

    mergesort(v,0,3);

    for (int i : v) {
        cout << i << endl;
    }

    return 0;
}