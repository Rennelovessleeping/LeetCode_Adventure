/**************************************************************************
 * File Name : LongestArithmeticProgression.cpp
 *
 * Purpose :
 *
 * Creation Date : 21-02-2017
 *
 * Last Modified : Tue Feb 21 17:19:19 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Given a set of numbers, find the Length of the Longest Arithmetic Progression (LLAP) in it.
// If the Array is sorted, we can use DP to achieve O(N^2) solution

int longestArithmeticProgression(vector<int>& nums){
	if(nums.size()<=2) return nums.size();
	int n = nums.size(), maxLen = 0;
	vector<vector<int>> dp(n, vector<int>(n));

	// Initialization
	for(int i=0; i<n; i++) dp[i].back()=2;

	for(int j=n-2; j>0; j--){
		int i=j-1, k=j+1;
		while(i>=0 && k<n){
			if(nums[i] + nums[k] < 2*nums[j]) k++;
			else if(nums[i] + nums[k] > 2*nums[j]){
				dp[i][j] = 2;
				i--;
			}
			else{
				dp[i][j] = dp[j][k] + 1;
				maxLen = max(maxLen, dp[i][j]);
				i--; k++;
			}
		}

		while(i>=0) dp[i][j] = 2;
	}
	return maxLen;
}

// But when arr is not sorted, we can use hashtable{incr, list of pairs} to calculate the max length of LAP
public class Solution {
   //given a sorted array with no dups
   //O(n^2) time, O(n^2) space
   private static int longestArithmeticProgression(int[] nums) {
       if (nums == null || nums.length < 2) {
           return 0;
       }
       HashMap<Integer, ArrayList<ArrayList<Integer>>> map = new HashMap<>();//key is diff, value is pair of indices
       for (int i = 0; i < nums.length - 1; i++) {
           for (int j = i + 1; j < nums.length; j++) {
               int diff = nums[j] - nums;
               if (!map.containsKey(diff)) {
                   map.put(diff, new ArrayList<>());
               }
               ArrayList<Integer> pair = new ArrayList<>(Arrays.asList(i, j));
               map.get(diff).add(pair);
           }
       }
       int max = 0;
       for (int key : map.keySet()) {
           int[] lengths = new int[nums.length];
           for (int i = 0; i < lengths.length; i++) {
               lengths = 1;//initialize all nums to 1
           }
           for (ArrayList<Integer> pair : map.get(key)) {
               lengths[pair.get(1)] = lengths[pair.get(0)] + 1;//update length of this diff's Arithmetic Progression
               max = Math.max(max, lengths[pair.get(1)]);
           }       
		}
       return max;
   }
}

// Note that this solution is valid when there are no duplicates, but whether nums is sorted or not does not matter;
int LongestArithmeticProgression(vector<int>& nums){
	if(nums.size()<=2) return nums.size();
	int n = nums.size(), maxLen = 0;
	unordered_map<int, vector<pair<int, int>>> mp// {diff, {i,j}}
	
	// Build diff: idx pair dictionary
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			mp[nums[j]-nums[i]].push_back({i,j});	
		}
	}

	for(auto item:mp){
		vector<int> lengths(n,1);
		maxLen = max(maxLen, lengths[x.second.second] = lengths[x.second.firt] + 1);	
		// Since there are no duplicates, given fixed j and diff(i,j) are unique over all the i;
	}	

	return maxlen;
}



