class Solution {
    public :
    vector<vector<int>> threeSum(vector<int> & nums){
        sort(nums.begin(),nums.end());
        vector<vector<int>>result;
        for(int i=0; i<nums.size()-2; i++){

            if(i>0 && nums[i]==nums[i-1]) continue
            int target = -nums[i]; //target to achieve;
            int j=i+1, k=nums.end();

            while(j<k){
                int two_sum = nums[j]+nums[k];
                if(two_sum<target){
                    j++;
                }
                else if (two_sum==target){
                    result.push_back(nums[i]);
                    result.push_back(nums[j]);
                    result.push_back(nums[k]);
                }
                else{
                    k--;
                }
            }



            return result;

        }







        };
