#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        
        if(n == 0){
            return result;
        }
        if(n == 1){
            result.push_back(nums[0]);
            return result;
        }
        
        sort(nums.begin(), nums.end());

        int count = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]){
                count++;
            }else{
                if(count > (n/3)){
                    result.push_back(nums[i-1]);
                }
                count = 1;
            }
        }
        
        if(count > (n/3)){
            result.push_back(nums[n-1]);
        }
        
    return result;
}

int main(){
    vector<int> nums = {4,1,3,1,3,3,1,2,3,2,4,2,1,4,4,4,4,4};
    majorityElement(nums);
    return 0;
}