class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long count=0;
        for(int i=0;i<intervals.size();i++){
            int start=intervals[i][0];
            while(!pq.empty() && pq.top()<start){
                pq.pop();
            }
            count+=pq.size();
            pq.push(intervals[i][1]);
        }
        return count;
    }
};