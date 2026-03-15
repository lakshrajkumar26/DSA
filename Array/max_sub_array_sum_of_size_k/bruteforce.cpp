class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        
        int n = arr.size();
        int max= INT_MIN;
        int start = 0;
        int end = k-1;
        
        while(end <= n-1){
            int sum =0;
            for(int k = start; k <= end; k++ ){
                  sum = sum+arr[k];
                //  cout<<sum<<endl;
                 
                 if(sum > max){
                      max = sum;
                 }
                
            }
           
            
            start ++;
            end++;
        }
        return max;
    }
};