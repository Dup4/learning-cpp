class Solution {
public:
    /**
     * return a array which include all ans for op3
     * @param op int整型vector<vector<>> operator
     * @return int整型vector
     */
    vector<int> getMinStack(vector<vector<int> >& op) {
        vector<int> res;
        stack<int> sta[2];
        for (auto& it : op) {
            if (it[0] == 1) {
                sta[0].push(it[1]);
                int Min = it[1];
                if (!sta[1].empty()) {
                    Min = min(Min, sta[1].top());
                }
                sta[1].push(Min);
            } else if (it[0] == 2) {
                sta[0].pop();
                sta[1].pop();
            } else {
                res.push_back(sta[1].top());
            }
        }
        return res;
    }
};