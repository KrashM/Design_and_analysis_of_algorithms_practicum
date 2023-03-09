class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(), score.end(), [k](vector<int> const &lhs, vector<int> const &rhs){
            return lhs[k] > rhs[k];
        });
        return score;
    }
};