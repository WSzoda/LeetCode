class Solution {
public:
    int n = 0;
    int ans = INT_MAX;
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> temp(k,0);
        n = cookies.size();
        distribute(cookies, k, temp, 0);

        return ans;
    }

    void distribute(vector<int>& cookies, int k, vector<int>& temp, int start){
        if(start == n){
            int maxi = 0;
            for(int i = 0; i < temp.size(); i++){
                maxi = max(maxi, temp[i]);
            }
            ans = min(ans, maxi);
            return;
        }

        for(int i = 0; i < k; i++){
            temp[i] += cookies[start];
            distribute(cookies, k, temp, start + 1);
            temp[i] -= cookies[start];
            if(temp[i]==0) break;
        }
        return;
    }
};