#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x){
    if(pos != MX){
        dat[pos] = x;
        pos ++;
    }
}

void pop(){
    if(pos != 0)
        pos --;
}

int top(){
    if(pos != 0)
        return dat[pos-1];
    else
        return -1;
}

bool empty(){
    if(pos == 0)
        return true;
    else
        return false;
}

int size(){
    return pos;
}

void test(){
  push(5); push(4); push(3);
  cout << top() << '\n'; // 3
  pop(); pop();
  cout << top() << '\n'; // 5
  push(10); push(12);
  cout << top() << '\n'; // 12
  pop();
  cout << top() << '\n'; // 10
}

int main(void) {
	test();
}