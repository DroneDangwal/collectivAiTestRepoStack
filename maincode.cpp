#include <iostream>
using namespace std;

class elem{

    int val;
    elem *next;

friend class stack;

};

class stack{

    elem *base;
    elem *top;
    int len;
public:
    stack(){
        base = new elem;
        top = base;
        len = 0;
    }

    void push(int x){
        elem e;
        e.val = x;
        if(len==0){
            *top = e;
            len++;
            return;
        }
        top -> next = new elem;
        top = top -> next;
        *top = e;
        len++;
    }

    void pop(){
        if(len == 0) return;

        elem *temp = base;
        while(temp->next != top) temp = temp->next;
        top = temp;
        delete (top->next);
    }

    inline int length(){return len;}

    void swap(stack &s){
        elem *temp = base;
        elem *temp2 = top;
        int x = len;
        base = s.base;
        top = s.top;
        len = s.len;
        s.base = temp;
        s.top = temp2;
        s.len = x;
    }

    void printStack(){
        elem *temp = base;
        cout << "Length of stack = " << len << '\n';
        cout << '{';
        while(temp != top){
            cout << temp->val << ' ';
            temp = temp->next;
        }
        cout << top->val << "}\n";
    }

};

int main(){
    stack pehla;
    stack dusra;
    pehla.push(3);
    pehla.push(63);
    pehla.push(4);
    pehla.push(5);
    dusra.push(43);
    dusra.push(32);
    pehla.printStack();
    dusra.printStack();
    pehla.swap(dusra);
    pehla.printStack();
    dusra.printStack();
}
