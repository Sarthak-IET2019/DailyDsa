class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {

        // so let's say a continous length of 0's is 5 then total number of subarrys possible is 15! how? for n it's n*(n+1)/2;

        int j;
        long long ans=0;
        for(int i=0;i<nums.size();i++){

            if(nums[i]==0) {
                j=i;
                while(i<nums.size() and nums[i]==0) i++;

                long long length = (i-j);
                ans+=((length)*(length+1))/2;
            }
        }

        return ans;
        
    }
};