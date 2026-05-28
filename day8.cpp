
#include<iostream>
using namespace std;

/*class and object revision
define a class date to represent date like d=31, m =12, y=2002.
declare appropriate member of instance member variables and also define instance member function to set date and display date
*/

class Date1{
    int d, m, y;
    public:
        void setDate(int d1, int m1, int y1){
            d = d1;
            m=m1;
            y=y1;
        }
        void displayDate(){
            cout << d << "/" << m << "/" << y << endl;
        }
};

/*in question above define a method to display date in the following pattern 12-12-2020*/
class Date2{
    int d, m, y;
    public:
        void setDate(int d1, int m1, int y1){
            d = d1;
            m=m1;
            y=y1;
        }
        void displayDate(){
            cout << d << "-" << m << "-" << y << endl;
        }
};

/*31-Dec-2002*/
/*class Date3{
    int d, m, y;
    public:
        void setDate(int d1, int m1, int y1){
            d = d1;
            m=m1;
            y=y1;
        }
        char* getMonth(){
            switch(m){
                case 1:
                   return "Jan";
                case 2:
                   return "Feb";
                case 3:
                   return "March";
                case 4:
                   return "Apr";
                case 5:
                   return "May";
                case 6:
                   return "June";
                case 7:
                   return "July";
                case 8:
                   return "Aug";
                case 9:
                   return "Sept";
                case 10:
                   return "Oct";
                case 11:
                   return "Nov";
                case 12:
                   return "Dec";
            }
        }
        void displayDate(){
            cout << d << "-" << getMonth() << "-" << y << endl;
        }
};*/

/*d4fine a class TestResult with appropriate roll_no, right, wrong, netscore. Also define class properties
right_weightage, wrong_weitage. Provide methods to set and get all the properties.
Also write a driver function main() to use TestResult class.
Create an array to 5 test result objects, set values to all the objects and display the results
in sorted order(by net score)
*/

class TestResult{
    private:
        int roll_no, right, wrong, netscore;
        static int right_weightage, wrong_weightage;
    public:
        void setRollNo(int r) { roll_no = r;}
        void setRight(int r) {right = r;}
        void setWrong(int w) {wrong = w;}
        void setNetScore(int s) {netscore = s;}
        void setRightWeightage(int rw) {right_weightage = rw;}
        void setWrongWeightage(int ww) {wrong_weightage = ww;}
        int getRollNo() {return roll_no;}
        int getRight() {return right;}
        int getWrong() {return wrong;}
        int getNetScore() {return netscore;}    
        int getRightWeightage() {return right_weightage;}
        int getWrongWeightage() {return wrong_weightage;}
};
int TestResult:: right_weightage;
int TestResult:: wrong_weightage;

/*void setTestResult(TestResult &t, int r, int wrong, int right){
    t.setRollNo(r);
    t.setRight(right);
    t.setWrong(wrong);
    t.setNetScore(t.getRight() *TestResult:: getRightWeightage() - t.getWrongWeightage() *TestResult:: getWrongWeightage());
}*/

void sortByNetScore(TestResult t[], int size){
    int round, i;
    for(round = 1; round < size; round++){
        for(i = 0; i < size-round; i++){
            if(t[i].getNetScore() < t[i+1].getNetScore()){
                TestResult temp = t[i];
                t[i] = t[i+1];
                t[i+1] = temp;
            }
        }
    }
}

void showResults(TestResult t[], int size){
    for(int i = 0; i < size; i++){
        cout << "Roll No: " << t[i].getRollNo() << " Right: " << t[i].getRight() << " Wrong: " << t[i].getWrong() << " Net Score: " << t[i].getNetScore() << endl;
    }
}

//reverse singly linked list
class Node{
    public:
        int val;
        Node* next;
        Node(int val){
            this->val = val;
            next = NULL;
        }
};

Node* reverseSLL(Node* head){
    Node* curr = head;
    Node* prev = nullptr;
    while(curr){
        Node* nextNode = curr -> next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

//remove nth node from SLL from last
Node* removeNthFromEnd(Node* head, int n){
    Node* fast = head;
    for(int i = 0; i < n; i++) fast = fast -> next;
    Node* slow = head;
    if(!fast) return head -> next; //if n is equal to the length of the list
    while(fast->next != nullptr){
        slow = slow -> next;
        fast = fast -> next;
    }
    Node* delNode = slow->next;
    slow -> next = slow -> next -> next;
    delete delNode;
    return head;
}

//merger two sorted singly linked list
Node* mergeTwoLists(Node* list1, Node* list2) {
        Node* dummyNode = new Node(-1);
        Node* t1=list1;
        Node* t2=list2;
        Node* t=dummyNode;
        while(t1 != nullptr && t2 != nullptr){
            if(t1->val < t2->val){
                t->next = t1;
                t = t1;
                t1=t1->next;
            }else{
                t->next = t2;
                t = t2;
                t2=t2->next;
            }
        }
        while(t1 != nullptr){
            t->next = t1;
            t = t1;
            t1=t1->next;
        }
        while(t2 != nullptr){
            t->next = t2;
            t = t2;
            t2=t2->next;
        }
        return dummyNode->next;
    }

int main(){
    // Date3 d1;
    // d1.setDate(27, 05, 2026);
    // d1.displayDate();

    /*Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head = reverseSLL(head);
    Node* temp = head;
    while(temp){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;*/
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head = removeNthFromEnd(head, 4);
    Node* temp = head;
    while(temp){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}