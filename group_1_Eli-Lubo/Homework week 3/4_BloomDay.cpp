class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int result = 0, currentTime = 0;
        vector<pair<int, int>> plant(plantTime.size());
        for(size_t i = 0; i < plant.size(); ++i)
            plant[i] = {plantTime[i], growTime[i]};
        sort(plant.begin(), plant.end(), [](pair<int, int> const &lhs, pair<int, int> const &rhs){
            return lhs.second > rhs.second;
        });
        for(size_t i = 0; i < plant.size(); ++i){

            result = max(result, currentTime + plant[i].first + plant[i].second);
            currentTime += plant[i].first;

        }
        
        return result;
    }
};