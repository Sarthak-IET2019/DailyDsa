class Solution {
public:

    bool isposs(vector<int>&arr,int balls,int force){

        int lpos=arr[0];
        int temp=1;

        for(int i=1;i<arr.size();++i){

            if(abs(arr[i]-lpos)>=force){
                temp++;
                lpos=arr[i];
            }
        }

        return temp>=balls;

    }


    int maxDistance(vector<int>& position, int m) {


        sort(position.begin(),position.end());

        int n= position.size();
        int st=0,ed=1e9;
        int ans=-1;

        while(st<=ed){

            int mid= st+(ed-st)/2;

            if(isposs(position,m,mid)){
                ans=max(ans,mid);
                st=mid+1;
            }

            else ed = mid-1;

            
        }

        return ans;

        
    }
};