class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size()<4){
            return ans;
        }
          
        sort(nums.begin(),nums.end());
        
        
        // -2 -1 0 0 1 2
        int left = 0 , right = nums.size()-1;
        for(int i=0;i<nums.size();i++){
            
            for(int j=i+1;j<nums.size()-2;j++){
                if( (j-1!= i) && nums[j-1] == nums[j])
                    continue;
               // cout << nums[i] << " " << nums[j] << " ";
                
                int t_target = target - nums[i] - nums[j];   // a+b+c+d = target    c+d = target - a -b
                //cout << " target: " <<　t_target << " \n";
                int left = j+1 , right = nums.size()-1;
                //cout << " left: " << nums[left] << " right " << nums[right] << endl;
                int t_sum = nums[left] + nums[right];
            
                while(left < right){
                    t_sum = nums[left] + nums[right];
                    vector<int> t_ans;
                    //cout << "t_sum : " << t_sum << " \n\n";
                    if(t_sum < t_target){ // 小 left往右
                        //cout << "now target: " << t_target << "  left: " << nums[left] << "  right: " << nums[right] << endl << endl; 
                        left +=1;
                        while(nums[left-1] == nums[left] &&  left<right)
                            left +=1;
                        //t_sum = nums[left] + nums[right];
                    }else if(t_sum > t_target){//大 right 往左
                        right -=1;
                        
                    }else if( t_sum == t_target){ //等於 push進 ans
                        t_ans.push_back(nums[i]);
                        t_ans.push_back(nums[j]);
                        t_ans.push_back(nums[left++]);                       
                        t_ans.push_back(nums[right--]);   
                        
                        if( find(ans.begin(),ans.end(),t_ans)== ans.end() )
                            ans.push_back(t_ans);                    
                    }
                }
 
            } 
        }
        return ans;
    }
};
