struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 

class Solution 
{
    public:
    static bool cmp(Job a, Job b){
        return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,cmp);
        int maxiDeadLine=INT_MIN;
        for(int i=0;i<n;i++){
            maxiDeadLine=max(maxiDeadLine,arr[i].dead);
        }
        vector<int>schedule(maxiDeadLine+1,-1);
        int count=0;
        int maxProfit=0;
        for(int i=0;i<n;i++){
            int currProfit=arr[i].profit;
            int currId=arr[i].id;
            int currDead=arr[i].dead;
        for(int k=currDead;k>0;k--){
            if(schedule[k]==-1){
                count++;
                maxProfit+=currProfit;
                schedule[k]=currId;
                break;
            }
        }
       }
       vector<int>ans;
       ans.push_back(count);
       ans.push_back(maxProfit);
       return ans;
    } 
};
