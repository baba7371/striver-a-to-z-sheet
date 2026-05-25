#include <bits/stdc++.h>
using namespace std;

// 25/05/2026

// count primes LC 207
bool isPrime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int countPrimes(int n)
{
    int count = 0;
    for (int i = 2; i < n; i++)
    {
        if (isPrime(i))
            count++;
    }
    return count;
}

// optimized solution using sieve of eratosthenes
// tc: O(nloglogn)
// sc: O(n)
int countPrimeOptimized(int n)
{
    if (n <= 2)
        return 0;

    vector<bool> prime(n, true);

    prime[0] = prime[1] = false;

    for (int i = 2; i * i < n; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j < n; j += i)
            {
                prime[j] = false;
            }
        }
    }
    int count = 0;
    for (int i = 2; i < n; i++)
    {
        if (prime[i])
            count++;
    }
    return count;
}

// check armstrong number
// An Armstrong number is a number that is equal to the sum of its own digits each raised to the power of the number of digits.
//time complexity: O(n) where n is the number of digits in the number
//space complexity: O(1)
bool isArmstrong(int num)
{
    int n = num;
    int sum = 0;
    string s = to_string(num);
    int k = s.length();
    while (num > 0)
    {
        int x = num % 10;
        sum += round(pow(x, k));

        num /= 10;
    }
    return n == sum;
}

// factorial of a number
// time complexity: O(n)
// space complexity: O(1)
long long factorial(int n)
{
    long long fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

// check perfect number
// A perfect number is a positive integer that is equal to the sum of its proper divisors (excluding itself).
//time complexity: O(n)
//space complexity: O(1)
bool isPerfectNumber(int num)
{
    int sum = 0, i = 1;
    while (i < num)
    {
        if (num % i == 0)
            sum += i;
        i++;
    }
    return sum == num;
}

//fibonacci number using recursion + memoization
//tc: O(n)
//sc: O(n) due to memoization
vector<int>t;
int fun(int n){
    if(n == 0) return 0;
    if(n == 1)return 1;
    if(t[n] != -1) return t[n];
    return t[n] = fun(n-1) + fun(n-2);
}

int fibonacci(int n){
    t.resize( n +1, -1);
    return fun(n);
}

//now we will see some pattern printing problems
//q1: half pyramid pattern
/*
*
**
***
****
*****
*/

void halfPyramid(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(j <= i){
                cout<<" * ";
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

//inverted half pyramid pattern
/*
*****
****
***
**
*
*/
void invertedHalfPyramid(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(j <= n - i + 1){
                cout<<" * ";
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

//full pyramid pattern
/*
    *
   ***
  *****
 *******    
*********
*/
void fullPyramid(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 2*n - 1; j++){
            if( j >= n - i + 1 && j <= n + i - 1){
                cout<<"*";    
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

//inverted full pyramid pattern
/*
*********
 *******
  *****
   ***
    *
*/  
void invertedPyramid(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 2*n-1; j++){
            if(j >= i && j <= 2*n-i){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    // int n = 10;
    // cout<<countPrimes(n);

    /*int t;
    cin >> t;
    while(t--){
        int num;
        cin>>num;
        if(isArmstrong(num)) cout<<"Armstrong number"<<endl;
        else cout<<"Not an armstrong number"<<endl;
    }*/
    /*int t;
    cin >> t;
    while (t--)
    {
        int num;
        cin >> num;
        if (isPerfectNumber(num))
            cout << "Perfect number" << endl;
        else
            cout << "Not a perfect number" << endl;
    }*/
   int n = 5;
//    halfPyramid(n);
    // invertedHalfPyramid(n);
    // fullPyramid(n);
    invertedPyramid(n);
    return 0;
}