class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        
        int month1=stoi(arriveAlice.substr(0,2));
        int month2=stoi(leaveAlice.substr(0,2));
        int month3=stoi(arriveBob.substr(0,2));
        int month4=stoi(leaveBob.substr(0,2));

        int day1=stoi(arriveAlice.substr(3,2));
        int day2=stoi(leaveAlice.substr(3,2));
        int day3=stoi(arriveBob.substr(3,2));
        int day4=stoi(leaveBob.substr(3,2));

        unordered_map<int,int>mp;
        mp[1]=31;
        mp[2]=28;
        mp[3]=31;
        mp[4]=30;
        mp[5]=31;
        mp[6]=30;
        mp[7]=31;
        mp[8]=31;
        mp[9]=30;
        mp[10]=31;
        mp[11]=30;
        mp[12]=31;
        cout<<month1<<" "<<month2<<" "<<month3<<" "<<month4<<endl;
        cout<<day1<<" "<<day2<<" "<<day3<<" "<<day4<<endl;
        //chose month
        int startMonth, startDay;

        if (month1 > month3) {
            startMonth = month1;
            startDay = day1;
        }
        else if (month3 > month1) {
            startMonth = month3;
            startDay = day3;
        }
        else {
            startMonth = month1;
            startDay = max(day1, day3);
        }
        
        int endMonth, endDay;

        if (month2 < month4) {
            endMonth = month2;
            endDay = day2;
        }
        else if (month4 < month2) {
            endMonth = month4;
            endDay = day4;
        }
        else {
            endMonth = month2;
            endDay = min(day2, day4);
        }

        //cout<<a<<" "<<b<<" "<<monthdays1<<" "<<monthdays2<<" ";
        if(startMonth==endMonth) return (endDay-startDay+1)<0?0:(endDay-startDay+1);
        if(startMonth>endMonth) return 0;
        int ans=0;
        ans+=mp[startMonth]-startDay+1;
        for(int i=startMonth+1;i<endMonth;i++){
            ans+=mp[i];
        }
        ans+=endDay;
        return ans<0?0:ans;
    }
};