#include<bits/stdc++.h>
using namespace std;

//two sum problem
/*
given array of positive integers and integer target you need to return 
the two index that adding up gives values equal to target
*/
//time complexity: O(n)
//space complexity: O(n)
vector<int> twoSum(vector<int>&arr, int target){
    
    //map store kreg: {ELEMENT_KA_VALUE, USHKA_ORIGINAL INDEX}
    unordered_map<int, int>mpp;

    for(int i = 0; i < arr.size(); i++){
        int remaining = target - arr[i];

        //agar remaining element map me pehle se hai
        if(mpp.count(remaining)){
            return {mpp[remaining], i}; // dono indices mil gaye
        }

        //agar nhi hai, toh current element ko ushke element ke sath map me daal do...
        mpp[arr[i]] = i;
    }
    return {}; // agar koi pair na mile{ waise ek solution hmesha hoga}
}

//remove dublicatess from sorted array
//time complexity: O(n)
//space complexity: O(1)
int removeDuplicates(vector<int>&arr){
    int k = 1;
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] != arr[i-1]){
            arr[k++] = arr[i];
        }
    }
    return k;
}

//best time to buy and sell stock
//time complexity: O(n)
//space complexity: O(1)
int bestTimetoBuyAndSellStock(vector<int>&prices){
    int n = prices.size();
    int mini = prices[0], profit = 0;
    for(int i = 1;i < n; i++){
        int cost = prices[i] - mini;
        profit = max(profit, cost);
        mini = min(mini, prices[i]);
    }
    return profit;
}

//plus one problem
//time complexity: O(n)
//space complexity: O(1)
vector<int> plusOne(vector<int>&digits){
    int n = digits.size();
    for(int i = n - 1; i >= 0; i++){
        if(digits[i] < 9){
            digits[i]++;
            return digits;
        }
        digits[i] = 0;
    }
    digits.insert(digits.begin(), 1);
    return digits;
}

//missing number problem
//time complexity: O(n)
//space complexity: O(1)
int missingNumber(vector<int>& arr){
    int n = arr.size();
    // 0 se n tak ka sum = (n * (n + 1)) / 2
    int sum = (n * (n + 1)) / 2;
    int totalSum = 0;
    for(int i = 0; i < n; i++){
        totalSum += arr[i];
    }
    return sum - totalSum;
}

//maximum subarray sum problem
//time complexity: O(n)
//space complexity: O(1)
int maxSubarray(vector<int>&arr){
    int sum = 0, maxSum = INT_MIN;
    for(int i = 0; i < arr.size(); i++){
        sum += arr[i];
        maxSum = max(maxSum, sum);
        if(sum < 0) sum = 0;
    }
    return maxSum;
}

//moves zero at the end of array
//time complexity: O(n)
//space complexity: O(1)
void movesZero(vector<int>&arr){
    int j = -1;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == 0) {
            j = i;
            break;
        }
    }
    if(j == -1) return;
    for(int i = j + 1; i < arr.size(); i++){
        if(arr[i] != 0){
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

//contains dublicate problem
//time complexity: O(nlogn) due to sorting
//space complexity: O(1)
bool containsDublicate(vector<int>&arr){
    sort(arr.begin(), arr.end());
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] == arr[i-1]) return true;
    }
    return false;
}

//intersection of two arrays
//time complexity: O(nlogn + mlogm) due to sorting
//space complexity: O(1)
vector<int> intersectionArray(vector<int>&arr1, vector<int>&arr2){
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    vector<int>ans;
    int i = 0, j = 0;
    while(i < arr1.size() && j < arr2.size()){
        if(arr1[i] < arr2[j]) i++;
        else if(arr1[i] > arr2[j]) j++;
        else{
            if(ans.empty() || ans.back() != arr1[i]){
                ans.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }
    return ans;
}

//2nd largest element in array
//time complexity: O(n)
//space complexity: O(1)
int secondLargest(vector<int>&arr){
    int maxi1 = arr[0], maxi2 = -1;
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] > maxi1){
            maxi2 = maxi1;
            maxi1 = arr[i];
        }
        else if(maxi1 > arr[i] && maxi2 < arr[i]){
            maxi2 = arr[i];
        }
    }
    return maxi2;
}

//reverse string problem
//time complexity: O(n)
//space complexity: O(1)
void reverseString(vector<char>&s){
    int i = 0, j = s.size()-1;
    while(i < j){
        swap(s[i], s[j]);
        i++;
        j--;
    }
}

//maximum count of positive integers and negative integers in array
//time complexity: O(n)
//space complexity: O(1)
int maxCount(vector<int>&arr){
    int pos= 0, neg = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == 0) continue;
        else if(arr[i] > 0) pos++;
        else neg++;
    }
    return max(pos, neg);
}

int main(){
    // vector<int>arr = {2,7,9,11};
    // int target = 9;
    // vector<int>res = twoSum(arr, target);
    // for(int x: res) cout<<"{"<<x<<" " <<"}";
    vector<int> arr1 = {4,9,5}; 
    vector<int> arr2 = {9,4,9,8,4};
    // cout << "Missing Number: " << missingNumber(arr) << endl;
//     movesZero(arr);
//     cout << "Array after moving zeros to the end: ";
//    for(int i = 0; i < arr.size(); i++){
//         cout << arr[i] << " ";
//     }
    // cout << "Contains Duplicate: " << containsDublicate(arr) << endl;
    vector<int> intersection = intersectionArray(arr1, arr2);
    cout << "Intersection of the two arrays: ";
    for(int x: intersection) cout << x << " ";
    return 0;
}