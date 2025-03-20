class Info{
    public:
    int data;
    int rowIndex;
    int colIndex;
    Info(int a, int b, int c){
        this->data =a;
        this->rowIndex =b;
        this->colIndex =c;

    }
};
class compare{
    public:
    bool operator()(Info* a,Info*b){
        return a->data>b->data;
    }
};


class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Info*, vector<Info*>,compare>pq;
        int maxi  = INT_MIN;
        int mini = INT_MAX;
        for(int i=0;i<nums.size();i++){
            int ele = nums[i][0];
            int row =i;
            int col =0;
            Info* temp = new Info(ele,row,col);
            pq.push(temp);
            maxi= max(maxi,ele);
            mini = min(mini,ele);
        }
        int ansStart = mini;
        int ansEnd = maxi;
        while(!pq.empty()){
            Info* topnode = pq.top();
            int topdata = topnode->data;
            int toprow=topnode->rowIndex;
            int topcol=topnode->colIndex;
            pq.pop();

            mini = topnode->data;
            if((maxi-mini)<(ansEnd-ansStart)){
                ansStart = mini;
                ansEnd = maxi;
            }
            if(topcol+1<nums[toprow].size()){
                int newele=nums[toprow][topcol+1];
                maxi=max(maxi,newele);
                Info* newinfo = new Info(newele,toprow,topcol+1);
                pq.push(newinfo);
            }
            else{
                break;
            }

        }
        vector<int>ans;
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;

    }
};