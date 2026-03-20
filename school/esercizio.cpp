//1 scambia lettere di una stringa
#include <iostream>
#include <string>

int main(){

    


    std::string p = "busatto";
    int m = p.size() / 2;
    if(p.size() % 2 != 0){
        m++;
    }

    for(int i=0; i<m; i++){
        std::swap(p[i], p[p.size()-1-i]);
    }
    std::cout << p;
    std::cout << "\n" << p.size()/2;
}

//1.1 scambia le lettere reciproce


//2 traduci una parola in un vettore di ? per consonanti e * per vocali con il rispettivo numero

//3 traduci dal vettore a parola