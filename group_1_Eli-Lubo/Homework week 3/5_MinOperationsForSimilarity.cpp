class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {

        sort(nums.begin(), nums.end(), [](int const &lhs, int const &rhs){
            if(lhs % 2) return rhs % 2 ? lhs < rhs : true;
            return rhs % 2 ? false : lhs < rhs;
        });

        sort(target.begin(), target.end(), [](int const &lhs, int const &rhs){
            if(lhs % 2) return rhs % 2 ? lhs < rhs : true;
            return rhs % 2 ? false : lhs < rhs;
        });

        long long answer = 0;

        for(size_t i = 0; i < nums.size(); ++i)
            if(nums[i] < target[i])
                answer += (target[i] - nums[i]) / 2;

        return answer;

    }

};