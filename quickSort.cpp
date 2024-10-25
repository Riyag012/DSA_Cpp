#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int partition(vector<int>& nums, int s, int e){
        int pivot = nums[s];
        int count = 0;
        for (int i = s+1; i <= e; i++){
            if (nums[i]<pivot){
                count++;
            }
        }
        int pivotIndex = s+count;
        swap(nums[s],nums[pivotIndex]);
        //here we have achieved partition

        //reaarange elements around pivot

        int i = s, j = e;
        while(i<pivotIndex && j>pivotIndex){
            while (nums[i]<pivot){
                i++;
            }
            while (nums[j]>pivot){
                j--;
            }
            if (i<pivotIndex && j>pivotIndex){
                swap(nums[i++], nums[j--]);
            }
        }
        return pivotIndex;
    }
    void quickSort(vector<int>& nums, int s, int e){
        //base case
        if (s>=e){
            return;
        }
        int pivotIndex = partition(nums, s, e);
        
        quickSort(nums, s, pivotIndex-1);
        quickSort(nums, pivotIndex+1, e);

    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};
int main(){
    vector<int> arr = {44, 7, 9, 11, 10, -1, 5, 23, 13};
    
    Solution solution;
    vector<int> sortedArr = solution.sortArray(arr);

    // Output the sorted array
    for (int i = 0; i < sortedArr.size(); i++) {
        cout << sortedArr[i] << " ";
    }
    cout << endl;

    return 0;
}