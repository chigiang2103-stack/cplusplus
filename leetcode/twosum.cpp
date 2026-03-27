#include<iostream>
using namespace std;
#include<vector>
int main ()
{}
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    vector<int>arr;
    for (int i = 0 ; i<nums.size()-1;i++) {
        for(int j = i + 1; j<nums.size();j++) {
            if(nums.at(i) + nums.at(j) == target) {
                arr.push_back(i);
                arr.push_back(j);
            }
        }
    }
    return arr;
    }
};