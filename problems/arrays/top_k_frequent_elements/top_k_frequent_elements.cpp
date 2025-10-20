class TopKFrequentElements {
public:
    vector<int> approach1(vector<int>& nums, int k) {
        // sorting
        unordered_map<int, int> ump;
        for(int num: nums) {
            ump[num]++;
        }

        vector<pair<int, int>> freq;
        for(auto it: ump) {
            freq.push_back({it.second, it.first});
        }

        sort(freq.begin(), freq.end());

        vector<int> res;
        int n = freq.size();
        for(int i = n-1; i >= n-k; i--) {
            res.push_back(freq[i].second);
        }
        
        return res;
    }

    vector<int> approach2(vector<int>& nums, int k) {
        // min-heap
        unordered_map<int, int> ump;
        for(int num: nums) {
            ump[num]++;
        }
        
        // min-heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(auto it: ump) {
            pq.push({it.second, it.first}); // {frequency, element}
            if(pq.size() > k) pq.pop();
        }

        vector<int> res;
        while(!pq.empty()) {
            res.push_back(pq.top().second); // get the element from the top
            pq.pop();
        }

        return res;
    }

    vector<int> approach3(vector<int>& nums, int k) {
        // bucket sort
        unordered_map<int, int> ump;
        for(int num: nums) {
            ump[num]++;
        }
        
        int n = nums.size();
        // index -> frequency
        // value -> all elements with that frequency
        vector<vector<int>> buckets(n + 1);
        for(auto it: ump) {
            buckets[it.second].push_back(it.first);
        }

        vector<int> res;
        for(int i = n; i >= 0 && res.size() < k; i--) {
            for(int num: buckets[i]) {
                res.push_back(num);
                if(res.size() == k) break;
            }
        }

        return res;
    }
};