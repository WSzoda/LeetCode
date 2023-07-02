class Solution {
public:
int answer = 0;

    void maxRequest(int start, int n, vector<vector<int>>& requests, vector<int>& indegree, int count){
        if(start == requests.size()){
            for(int i = 0; i < n; i++){
                if(indegree[i] != 0){
                    return;
                }
            }

            answer = max(count, answer);
            return;
        }


        indegree[requests[start][0]]--;
        indegree[requests[start][1]]++;
        maxRequest(start+1, n, requests, indegree, count+1);

        indegree[requests[start][0]]++;
        indegree[requests[start][1]]--;
        maxRequest(start+1, n, requests, indegree, count);
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> indegree(n, 0);
        maxRequest(0, n, requests, indegree, 0);

        return answer;
    }
};