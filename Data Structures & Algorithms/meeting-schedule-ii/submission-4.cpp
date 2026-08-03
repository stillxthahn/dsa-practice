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
    static bool cmp(Interval &a, Interval &b) {
        return a.start < b.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);

        priority_queue<int, vector<int>, greater<int>> q;
        for (auto &it : intervals) {
            if (!q.empty() && q.top() <= it.start) {
                q.pop();
            }
            q.push(it.end);
        }
        return q.size();
        // int res = INT_MIN;
        // int rooms = 1;
        // for (int i = 0; i < n; i++) {
        //     rooms = 1;
        //     int start = intervals[i].start;
        //     int end = intervals[i].end;
        //     for (int j = 0; j < n; j++) {
        //         if (i == j) continue;

        //         if (start >= intervals[j].start && start <= intervals[j].end) {
        //             rooms++;
        //             cout << "Room adds when:  " << start << ":" << end << ", and " <<  intervals[j].start << ":" << intervals[j].end << endl;
        //         }
        //     }
        //     res = max(res, rooms);
        // }
        // return res;
    }
};
