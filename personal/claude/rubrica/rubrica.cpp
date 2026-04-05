//Rubrica telefonica: crea una struct Contatto con nome e numero, salva più contatti in un vettore e permetti di cercare un contatto per nome

#include <iostream>
#include <string>
#include <vector>

struct Tcontatto{
    std::string nome;
    std::string cognome;
    int numero;
};

int main(){
    
    std::vector<Tcontatto> rubrica;

    bool running = true;

    while(running){
        std::cout << "cosa vuoi fare?\n"
                  << "[1] inserire un contatto\n"
                  << "[2] cercare un contatto in base al nome\n";
        int scelta;
        std::cin >> scelta;

        switch(scelta){

            case 1:
                //inserire contatto
                break;

            case 2:
                //cercare un contatto
                break;

            default:
                std::cout << "input non valido...\n";
                break;

        }

    }

}

void inserimento(std::vector<Tcontatto>& rubrica){

    //algoritmo
}