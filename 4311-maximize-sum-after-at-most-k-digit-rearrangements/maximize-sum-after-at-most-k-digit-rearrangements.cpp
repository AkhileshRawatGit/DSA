class Solution {
public:
    long long rearrange(long long n){
        long long res = 0;
        vector<int>a;
        while(n > 0){
            a.push_back(n%10);
            n = n / 10;
        }
        sort(a.begin(),a.end());
        for(int i=a.size()-1;i>=0;i--){
            res=res*10+a[i];
        }
        return res;
    }
    long long maximizeSum(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            long long arrange=rearrange(nums[i]);
            if(arrange>nums[i]){
                long long gain=arrange-nums[i];
                pq.push({gain,i});
                if(pq.size()>k){
                    pq.pop();
                }
            }
        }
        while(pq.size()>0){
            sum+=pq.top().first;
            pq.pop();
        }
        return sum;
        
    }
};