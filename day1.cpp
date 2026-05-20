//20th may 2026 Wednesday
//basic but important problems

//wap tp swap two values wiothout using any third variable
//there are two approach we can use for this 1st: using "+" & "-" operator 2nd: using bitwise xor operator
#include<bits/stdc++.h>
using namespace std;

void swapNumbers(int a,int b){
    cout<<"Numbers before swappiong: "<<a<<" "<<b<<endl;
    //1st approach
    a = a + b;
    b =  a - b;
    a = a - b;
    cout<<"Numbers after swappiong: "<<a<<" "<<b<<endl;
}

void swap(int a, int b){
    cout<<"Numbers before swappiong: "<<a<<" "<<b<<endl;
    //2nd approach
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout<<"Numbers after swappiong: "<<a<<" "<<b<<endl;
}

//wap to print number between two given numbers
bool isPrime(int a){
    for(int i = 2; i < a; i++){
        if(a % i == 0) return 0;
    }
    return 1;
}

void printPrime(int a, int b){
    for(int i = a; i < b; i++){
        if(isPrime(i)) cout<<i<<" ";
    }
}

//wap to find the highest value digit in a given number
void highestDigit(int n){
    int maxdigit = n % 10;
    n /= 10;
    while(n > 0){
        if(maxdigit < n % 10) maxdigit = n % 10;
        n /= 10;
    }
    cout<<"Highest digit is: "<<maxdigit<<endl;
}

//wap tp calculate LCM of two numbers
int calculateLCM(int a, int b){
    int l;
    for(l = a > b ? a : b; l <= a*b; l++){
        if(l % a == 0 && l % b == 0) break;
    }
    return l;
}

//wap to calculate HCF of two numbers
int calculateHCF(int a, int b){
    int h;
    for(h = a < b ? a : b; h >= 1; h--){
        if(a % h == 0 && b % h == 0) break;
    }
    return h;
}

//wap to calculate x raised to the power y;
double calculatePower(int x,int y){
    long long power = 1;
    if( y == 0) return 1;
    int exp = abs(y);
    while( exp > 0){
        power *= x;
        exp--;
    }
    if(y < 0) return 1.0 / power;
    else return power;
}

//wap for pascal triangle
//there are three types of problems asked on pascale triangle;
//1st row given col given find the value at that position
//2nd row given find the whole row  
//3rd given the number of rows print the whole triangle
// pascal triangle looks like:  
/*
    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1
*/
//1st type of problem
//it will be based on combination formula nCr = n! / (r! * (n-r)!)
int factorial(int n){
    int fact = 1;
    for(int i = 1; i <= n; i++){
        fact *= i;
    }
    return fact;
}

double positionValue(int r, int c){
    return factorial(r-1) / (factorial(c-1) * factorial(r - c));
}

//type 1 optimized solution
double nCr(int n, int r){
    long long res = 1;
    for(int i = 0; i < r; i++){
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

//2nd type of problem
vector<int> printRow(int row){
    long long ans = 1;
    vector<int>res;
    res.push_back(1);
    for(int col = 1; col < row; col++){
        ans = ans * (row - col);
        ans = ans / (col);
        res.push_back(ans);
    }
    return res;
}

//type 3 proble (print entire pascal triangle)
void printPascalTriangle(int rows){
    for(int i = 1; i <= rows; i++){
        vector<int> row = printRow(i);
        for(int j = 0; j < row.size(); j++){
            cout<<row[j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    // swapNumbers(10,20);
    // swap(10,20);
    // printPrime(10,20);
    // highestDigit(239854);
    // cout<<"LCM of 12 and 15 is: "<<calculateLCM(12,15)<<endl;
    // cout<<"HCF of 12 and 15 is: "<<calculateHCF(12,15)<<endl;
    // cout<<"25 raised to the power 2 is: "<<calculatePower(25, 2)<<endl;
    // cout<<"25 raised to the power -2 is: "<<calculatePower(25, -2)<<endl;
    // cout<<"Value at row 5, column 3 is: "<<positionValue(5, 3)<<endl;
    printPascalTriangle(5);
    return 0;
}