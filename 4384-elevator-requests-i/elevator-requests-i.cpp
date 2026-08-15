class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int result=0;
        int floor=0;
        for(int i=0;i<requests.size();i++){
            result=result+(abs(floor-requests[i]));
            floor=requests[i];
        }
        return result;
    }
};