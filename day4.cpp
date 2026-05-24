#include<bits/stdc++.h>
using namespace std;

//3 sum problem
//time complexity: O(n^2)
//space complexity: O(1)
vector<vector<int>> threeSum(vector<int>&arr){
    vector<vector<int>>ans;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); i++){
        if(i > 0 && arr[i] == arr[i-1]) continue;
        int left = i+1, right = arr.size()-1;
        while(left < right){
            if(arr[i] + arr[left] + arr[right] == 0){
                ans.push_back({arr[i], arr[left], arr[right]});
                left++;
                right--;
                while(left < right && arr[left] == arr[left-1]) left++;
                while(left < right && arr[right] == arr[right+1]) right--;
            }
            else if(arr[i] + arr[left] + arr[right] < 0) left++;
            else right--;
        }
    }
    return ans;
}

//sort an array of 0s, 1s and 2s
//dutch national flag algorithm
void sortColors(vector<int>&arr){
    int left = 0, mid = 0, right = arr.size()-1;
    while(mid <= right){
        if(arr[mid] == 0){
            swap(arr[left], arr[mid]);
            left++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid], arr[right]);
            right--;
        }
    }
}

//longest substring without repeating characters
//time complexity: O(n)
//space complexity: O(256) due to hash map
int lengthOfLongestSubstring(string s){
    int hash[256] = {-1};
    int left = 0, right = 0, maxLen = 0;
    while(right < s.size()){
        if(hash[s[right]] != -1){
            if(hash[s[right]] >= left){
                left = hash[s[right]] + 1;
            }
        }
        int len = right - left + 1;
        maxLen = max(maxLen, len);
        hash[s[right]] = right;
        right++;
    }
    return maxLen;
}


int main(){
    /*vector<int>arr = {-1,0,1,2,-1,-4};
    vector<vector<int>>res = threeSum(arr);
    for(auto x: res){
        cout<<"{";
        for(int y: x) cout<<y<<" ";
        cout<<"}"<<endl;
    }*/

   /*vector<int> arr={2,0,2,1,1,0};
    sortColors(arr);
    for(int x: arr) cout<<x<<" ";*/

    string str = "cadbzabcd";
    cout<<lengthOfLongestSubstring(str)<<endl;
    return 0;
}
