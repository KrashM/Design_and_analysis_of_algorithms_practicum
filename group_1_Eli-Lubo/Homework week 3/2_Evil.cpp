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

bool insideInterval(Interval const &superInterval, Interval const &subInterval){
    return superInterval.start <= subInterval.start && subInterval.start <= superInterval.end;
}

Interval combineIntervals(Interval const &left, Interval const &right){
    return Interval{min(left.start, right.start), max(left.end, right.end)};
}

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

    for(size_t i = 1; i < intervals.size(); ++i)
        if(insideInterval(intervals[i - 1], intervals[i])){

            intervals[i] = combineIntervals(intervals[i - 1], intervals[i]);
            intervals.erase(intervals.begin() + (--i));

        }

    for(size_t i = 0; i < intervals.size(); ++i)
        result += intervals[i].end - intervals[i].start + 1;

    cout << result << '\n';

}