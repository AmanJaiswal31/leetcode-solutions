class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        int count = 0;

        vector<int> PrefixSum(n, 0);

        PrefixSum[0] = arr[0];

        for (int i = 1; i < n; i++) {
            PrefixSum[i] = PrefixSum[i - 1] + arr[i];
        }


        // map to store <PrefixSum, Frequency>
        unordered_map<int, int> m;


        // check prefix sum equals k
        for (int j = 0; j < n; j++) {
            if (PrefixSum[j] == k) count++;
        
int val = PrefixSum[j]-k;
if(m.find(val) != m.end()){
    count += m[val];

}


 
m[PrefixSum[j]] = 0;
}


m[PrefixSum[j]]++;
 

             
        }

        return count;
    }
};


