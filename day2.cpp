//21 may 2026
/*Problem: Implement function overloading to support:

add(int,int) → returns int
add(double,double) → returns double
add(int,int,int) → returns int (sum of 3 integers)
(optional) add(string,string) → concatenation*/

#include<bits/stdc++.h>
using namespace std;

int add(int a, int b=0){
    return a+b;
}

double add(double a, double b = 0.0){
    return a + b;
}

int add(int a, int b, int c = 0){
    return a+b+c;
}

string add(string a, string b = ""){
    return a + " " + b;
}

/*Problem: Overload a print function to:

print(int) → print single integer (e.g., 7)
print(string) → print a message line (e.g., "Hi")
print(int a, int b) → print range like a to b
print(vector<int>&) → print all elements of a vector*/

void print(int a){
    cout<<a<<endl;
}

void print(string a){
    cout<<a<<endl;
}

void print(int a, int b){
    for(int i = a; i <= b; i++){
        cout<<i<<" ";
    }
}

void print(vector<int>&arr){
    for(int a: arr) cout<<a<<" ";
}


//LC Problem number 3043
//Length of the Longest Common Prefix
//approach using TRIE 
class TrieNode{
    public:
    TrieNode* children[10]; //assuming only digits 0-9
};

TrieNode* getTrieNode(){
    TrieNode* node = new TrieNode();
    for(int i = 0; i < 10; i++){
        node->children[i] = nullptr;
    }
    return node;
}

void insert(int num, TrieNode* root){
    TrieNode* crawl = root;
    string numStr = to_string(num);
    for(char ch: numStr){
        int idx = ch - '0';
        if(!crawl -> children[idx]){
            crawl->children[idx] = getTrieNode();   
        }

        crawl = crawl->children[idx];
    }
}

int search(int num, TrieNode* root){
    TrieNode* crawl = root;
    string numStr = to_string(num);
    int length = 0;

    for(char ch: numStr){
        int idx = ch - '0';
        if(crawl -> children[idx]){
            length++;
            crawl = crawl->children[idx];
        } else {
            break; //not found
        } 
    }
    return length; //found
}

//wap for selection sort (Time complexity ~ O(n^2)) in all three cases (best, average, worst)
void Selection_sort(vector<int>&arr){
    int n = arr.size();
    int mini = 0;
    for(int i = 0; i < n - 2; i++){
        mini = i;
        for(int j = i; j <= n - 1; j++){
            if(arr[j] < arr[mini]) mini = j;
        }
        swap(arr[mini], arr[i]);
    }
}

//wap for bubble sort  (Time complexity ~ O(n^2)) in two cases (average, worst)
void bubble_sort(vector<int>&arr){
    for(int round = 0; round < arr.size()-1; round++){
        for(int i = 0; i < arr.size()-1-round; i++){
            if(arr[i] > arr[i+1]) swap(arr[i], arr[i+1]);
        }
    }
}

//wap for insertion sort (Time complexity ~ O(n^2)) in two cases (average, worst)
//if array is already sorted then time complexity is O(n) as we are just traversing the array once
void insertion_sort(vector<int>&arr){
    int n = arr.size();
    for(int i = 0; i <= n - 1; i++){
        int j = i;
        while(j > 0 && arr[j - 1] > arr[j]){
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}

int main(){

    /*cout<<add("Abhishek")<<endl;
    print(7);
    print("Hi");
    print(5, 10);
    vector<int> arr = {1, 2, 3, 4, 5};
    print(arr);*/

    /* TrieNode* root = getTrieNode();
     vector<int> nums1 = {1,10,100};
     vector<int> nums2 = {1000};

     for(int num: nums1){
        insert(num, root);
     }

     int res = 0;
     for(int num: nums2){
        res = max(res, search(num, root));
     }
     cout<<"Maximum length of common prefix is: "<<res<<endl; */

     vector<int> arr = {64, 25, 12, 22, 11};
        //Selection_sort(arr);
        // bubble_sort(arr);
        insertion_sort(arr);
        cout << "Sorted array: \n";
        for (int i = 0; i < arr.size(); i++)
            cout << arr[i] << " ";

    return 0;
}