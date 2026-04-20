#include <iostream>

int factorial(int num);

int main(){
    int num;
    std::cout << "Dammi un numero: ";
    std::cin >> num;
    std::cout << factorial(num);
}

int factorial(int num){
    if (num <= 0){ return 1;
    }
    return num * factorial(num -1);
}
