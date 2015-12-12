class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.empty())  return 0;
        /*int number = 0;
        for(int i = 0; i < nums.size(); i++) {
            number = number ^ nums[i];
        }
        return number;*/
        unordered_set<int> numset;
        for(int i = 0; i < nums.size(); i++) {
            if(numset.count(nums[i]) == 0) {
                numset.insert(nums[i]);
            }
            else {
                numset.erase(nums[i]);
            }
        }
        return *numset.begin();
    }
};