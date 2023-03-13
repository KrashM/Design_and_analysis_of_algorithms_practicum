#include <algorithm>
#include <iostream>
#include <vector>

using std::ios;
using std::min;
using std::max;
using std::cin;
using std::cout;
using std::sort;
using std::vector;

struct Interval{
    size_t start, end;
};

int main(){

    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    vector<Interval> intervals;
    Interval temp;
    size_t n, m, start, end, result = 0;
    cin >> n >> m;

    for(size_t i = 0; i < m; ++i){

        cin >> temp.start >> temp.end;
        intervals.push_back(temp);

    }

    sort(intervals.begin(), intervals.end(), [](Interval const &lhs, Interval const &rhs){
        return lhs.start < rhs.start;
    });

    start = intervals[0].start;
    end = intervals[0].end;

    for(size_t i = 1; i < intervals.size(); ++i)
        if(intervals[i].start <= end)
            end = max(end, intervals[i].end);
        else{

            result += end - start + 1;
            start = intervals[i].start;
            end = intervals[i].end;

        }

    result += end - start + 1;
    cout << result << '\n';

}