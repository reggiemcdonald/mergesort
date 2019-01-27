#include <iostream>
#include <vector>
/**
 * merges the subarrays iteratively
 * @return
 */

using namespace std;

 void myMerge(vector<int>& arr, int low, int med, int high) {
     int requiredSizeOfCopyArray = high - low+1; // predefine the size of the copy array
     vector<int> v(requiredSizeOfCopyArray);
     int firstArrIndex = low;
     int secondArrIndex = med+1;

     while (firstArrIndex <= med && secondArrIndex <= high) {
         if (arr[firstArrIndex] < arr[secondArrIndex]) {
             v[firstArrIndex] = arr[firstArrIndex]; v[firstArrIndex+1] = arr[secondArrIndex];
             firstArrIndex++; secondArrIndex++;
         } else if (arr[firstArrIndex] >= arr[secondArrIndex]) {
             v[firstArrIndex] = arr[secondArrIndex]; v[firstArrIndex+1] = arr[firstArrIndex];
             firstArrIndex++; secondArrIndex++;
         }
     }
     while (firstArrIndex <= med) {
         v[firstArrIndex] = arr[firstArrIndex];
         firstArrIndex++;
     }
     while (secondArrIndex <= high) {
         v[firstArrIndex] = arr[secondArrIndex];
         firstArrIndex++;
         secondArrIndex++;
     }

     // Copy the copy array to the original array
     for (int i = low; i<=high; i++) {
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

        // Mergesort the second half of the array
        mergesort(arr, mid+1, high);

        // Merge the arrays
        myMerge(arr, low, mid, high);

    }
}


int main() {
    int myInts[] = {10,3,1};
    std::vector<int> v;
    for (int i = 0; i<3; i++) {
        int value = myInts[i];
        v.push_back(value);
    }

    mergesort(v,0,2);

    for (int i : v) {
        cout << i << endl;
    }

    return 0;
}