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
        priority_queue<int, vector<int>, greater<int>> q;
        sort(intervals.begin(), intervals.end(), cmp);

        for (auto &i : intervals) {
            if (q.size() && q.top() <= i.start) {
                q.pop();
            }
            q.push(i.end);
        }
        return q.size();
    }
};
