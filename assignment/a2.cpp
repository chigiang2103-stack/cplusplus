#include<iostream>
using namespace std;
int main() {
    int findPartitionIndex(int* nums,int size);
    int nums[2]={10,10};
    int size = sizeof(nums)/sizeof(nums[0]);
    int res = findPartitionIndex(nums,size);
    cout << res << endl;
    return 0;
}
// sizeof() : kích thước theo byte của mảng các phần tử 
// vd int nums[] = {1,2,3} mỗi kiểu int có 4 byte => 3 element là 12 byte
// muốn lấy số element cần chia cho kích thước của 1 element 
int findPartitionIndex(int* nums,int size)  {
    int left = 0 ;
    int right = size -1;
    int a1 = nums[left] , a2=nums[right];
    while (left < right && left != right-1 )  {
        a1+=nums[++left];
        if (left==right-1) {
            break;
        }
        a2+=nums[--right];
    }
    if (a1==a2) {
        return left;
    }
    return -1;
}
