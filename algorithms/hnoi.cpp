#include <iostream>
#include <stdio.h>
#include <stack> 

using namespace std;

struct State{
    int _n;
    char _x,_y,_z;
    State(int n,char x,char y,char z):_n(n),_x(x),_y(y),_z(z){}
};

static int num = 0;
void hanoi(int n,char A,char B,char C){
    stack<State> s;
    s.push(State(n,A,B,C));
    while(!s.empty()){
        State t = s.top();
        s.pop();
        if(t._n == 1){
            printf("Move from %c to %c\n",t._x,t._z);
            num++;
        }
            
        else{
            // opposite of the normal sequence 
            s.push(State(t._n-1,t._y,t._x,t._z));
            s.push(State(1,t._x,t._y,t._z));
            s.push(State(t._n-1,t._x,t._z,t._y));
        }
    }
}

int main(){
    hanoi(12,'A','B','C');
    printf("%d times",num);
    return 0;
}