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
        map<int, int> mp;

        for (auto &it : intervals) {
            mp[it.start]++;
            mp[it.end]--;
        }

        int res = 0, rooms = 0;
        for (auto &[key, value] : mp) {
            rooms += value;
            res = max(res, rooms);
        }
        return res;
    }
};
