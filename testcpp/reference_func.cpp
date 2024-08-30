#include <iostream>

int& func(int& a){
    a = 5;
    return a;
}

int main(){
    int b = 2;
    int c = func(b);
    return 0;
}