class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if (st.empty()) {
            st.push({price, 1});
            return 1;
        }
        if(st.top().first>price){
            st.push({price,1});
            return 1;
        }
        else{
            int count=0;
            while(!st.empty() && price>=st.top().first){
                count+=st.top().second;
                st.pop();
            }
            st.push({price,count+1});
            return count+1;
        }

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */