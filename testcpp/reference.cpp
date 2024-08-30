#include <iostream>

int main(){
    int x;
    int& y = x;
    int& z = y;

    x = 1;
    std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;

    x = 2;
    std::cout << "x : " << x << " y : " << y << " z : " << z << "\n";

    x = 3;
    std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;
}