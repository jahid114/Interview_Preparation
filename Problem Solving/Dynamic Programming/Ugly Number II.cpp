class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1) return 1;
        int i=2, n2 = 0, n3 = 0, n5 = 0;
        vector<int>ans;
        
        ans.push_back(1);
        
        for(int i=1;i<n;++i){
            ans.push_back(min({ans[n2]*2, ans[n3]*3, ans[n5]*5}));
            if(ans[i]==ans[n2]*2)
                n2++;
            if(ans[i]==ans[n3]*3)
                n3++;
            if(ans[i]==ans[n5]*5)
                n5++;
        }
        
        return ans[n-1];
    }
};