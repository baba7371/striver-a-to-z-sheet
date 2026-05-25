#include<bits/stdc++.h>
using namespace std;

//strings problems date: 24-05-2026

//valid palindrome 
//time complexity: O(n)
//space complexity: O(n)
bool isPalindrome(string s){
    string str = "";
    for(char c: s){
        if(isalnum(c)){
            str += tolower(c);
        }
    }
    int i = 0, j = str.size()-1;
    while(i < j){
        if(str[i] != str[j]) return false;
        i++;
        j--;
    }
    return true;
}

//LC POTD 24th may 2026
//Jump game V
//time complexity: O(n*d) in worst case
//space complexity: O(n) due to memoization
vector<int>t;
int solve(vector<int>& arr, int i, int d){
    int n = arr.size()-1;
    int result = 1;
    if(t[i] != -1) return t[i];
    // left part ke liye
    for(int j = i - 1; j >= max(0, i - d); j--){
        if(arr[j] >= arr[i]) break;
        result = max(result, 1 + solve(arr, j, d));
    }

    // right part ke liye
    for(int j = i + 1; j <= min(n, i + d); j++){   
        if(arr[j] >= arr[i]) break;
        result = max(result, 1 + solve(arr, j, d));
    }
    return t[i] = result;
}


int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        t.resize(n, -1);
        int result = 1;
        for(int i = 0; i < n; i++){
            result = max(result, solve(arr, i, d));
        }
        return result;
    }

int main(){
    // string s = "A man, a plan, a canal: Panama";
    // cout << isPalindrome(s) << endl; // Output: 1 (true)
    vector<int>arr = {6,4,14,6,8,13,9,7,10,6,12};
    int d = 2;
    cout << maxJumps(arr, d) << endl; // Output: 4
    return 0;
}