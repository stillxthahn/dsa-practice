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
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        int s = 0, e = 0;
        vector<int> start(n, 0), end(n, 0);
        for (int i = 0; i < n; i++) {
            start[i] = intervals[i].start;
            end[i] = intervals[i].end;
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int count = 0, res = 0;
        while (s < n) {
            if (start[s] < end[e]) {
                count++;
                s++;
            }
            else {
                e++;
                count--;
            }
            res = max(res, count);
        }
        return res;
    }
};
