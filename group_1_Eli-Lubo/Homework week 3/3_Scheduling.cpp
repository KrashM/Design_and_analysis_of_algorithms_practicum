// https://judge.openfmi.net/practice/open_contest?contest_id=21

#include <algorithm>
#include <iostream>
#include <vector>

using std::ios;
using std::cin;
using std::cout;
using std::sort;
using std::vector;

struct Time{
    size_t start, end;
};

int main(){

    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    size_t start, duration;
    vector<Time> timestamps;

    while(cin >> start >> duration)
        timestamps.push_back({start, start + duration});

    if(!timestamps.size()){

        cout << "0\n";
        return 0;

    }

    sort(timestamps.begin(), timestamps.end(), [](Time const &a, Time const &b){
        return a.end < b.end;
    });

    const size_t n = timestamps.size();
    size_t currentTime = timestamps[0].end, cnt = n;

    for(size_t i = 1; i < n; ++i)
        if(currentTime > timestamps[i].start) cnt--;
        else currentTime = timestamps[i].end;

    cout << cnt << '\n';

}