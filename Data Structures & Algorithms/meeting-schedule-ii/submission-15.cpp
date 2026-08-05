/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool cmp(int &a, int &b) {
        return a < b;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<int> start, end;
        for (auto &i : intervals) {
            start.push_back(i.start);
            end.push_back(i.end);
        }
        sort(start.begin(), start.end(), cmp);
        sort(end.begin(), end.end(), cmp);

        int s = 0, e = 0;
        int res = 0, count = 0;        
        while (s < n) {
            if (start[s] < end[e]) {
                count++;
                s++;
            }
            else {
                count--;
                e++;
            }
            res = max(res, count);
        }
        return res;
    }
};
