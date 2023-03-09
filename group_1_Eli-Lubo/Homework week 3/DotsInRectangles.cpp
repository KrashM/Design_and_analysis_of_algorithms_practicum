#include <iostream>
#include <vector>

using std::ios;
using std::cin;
using std::cout;
using std::vector;

struct Rect{
    size_t startX, width, height;
};

struct Point{
    size_t x, y;
};

bool binarySearch(vector<Rect> const &rects, Point const &point, int const &start, int const &end){

    if(start > end) return false;

    int mid = (start + end) / 2;

    if(rects[mid].startX < point.x && point.x < rects[mid].startX + rects[mid].width) return rects[mid].height >= point.y;
    if(rects[mid].startX == point.x) return (rects[mid].height >= point.y) || (mid ? rects[mid - 1].height >= point.y : 0);
    if(rects[mid].startX + rects[mid].width == point.x) return (rects[mid].height >= point.y) || (mid != rects.size() - 1 ? rects[mid + 1].height >= point.y : 0);

    if(rects[mid].startX > point.x) return binarySearch(rects, point, start, mid - 1);
    else return binarySearch(rects, point, mid + 1, end);

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    size_t n, m, result = 0;
    cin >> n >> m;

    vector<Rect> rects(n);
    Point p;

    for(size_t i = 0; i < n; ++i){

        cin >> rects[i].width >> rects[i].height;
        if(i != 0) rects[i].startX = rects[i - 1].startX + rects[i - 1].width;

    }

    for(size_t i = 0; i < m; ++i){

        cin >> p.x >> p.y;
        result += binarySearch(rects, p, 0, n);

    }

    cout << result << '\n';

}