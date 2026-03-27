#include<iostream>
using namespace std;
int main() {
    int findPartitionIndex(int* nums,int size);
    int nums[6]={2,2,1,2,2,1};
    int size = 6;
    int res = findPartitionIndex(nums,size);
    cout << res << endl;
    return 0;
}
int findPartitionIndex(int* nums, int size) {
    int total = 0;
    for (int i = 0; i < size; i++) total += nums[i];
    int leftSum = 0;
    for (int i = 0; i < size; i++) {
        total -= nums[i];
        leftSum += nums[i]; 
        if (leftSum == total)
            return i;
    }
    return -1;
}

