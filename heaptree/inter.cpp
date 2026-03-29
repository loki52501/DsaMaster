    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>pq;
        int idx=0;
        std::sort(intervals.begin(),intervals.end());

        // store {query_value, original_index} to restore order later
        vector<pair<int,int>> sortedQ;
        for(int i=0;i<queries.size();i++)
            sortedQ.push_back({queries[i], i});
        sort(sortedQ.begin(), sortedQ.end());

        vector<int> ans(queries.size(), -1);  // pre-sized, default -1
        for(auto [query, origIdx] : sortedQ)
        {

            while(idx<intervals.size() && intervals[idx][0]<=query)
            {
                int inte=intervals[idx][1]-intervals[idx][0] +1;
                pq.push({inte,intervals[idx][1]});
                idx++;

            }
            while(!pq.empty() && pq.top().second<query)
                pq.pop();
            int res=(pq.empty())?-1:pq.top().first;
            ans[origIdx]=res;  // write to original position

                   
        }
    }