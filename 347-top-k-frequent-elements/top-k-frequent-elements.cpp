class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;
        for (auto& i : mp) {
            if (pq.size() == k) {
                if (i.second > pq.top().first) {
                    pq.pop();
                    pq.push({i.second,i.first});
                }
            } else
                pq.push({i.second,i.first});
        }
        vector<int>res;
        while(pq.size()>0){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};