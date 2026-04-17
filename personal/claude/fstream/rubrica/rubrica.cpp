#include <iostream>
#include <fstream>
#include <string>

//funzioni
void PrintRubrica();

//struct
struct Tpersone{
    std::string nome;
    std::string cognome;
    int eta;
};

int main(){

    Tpersone persona;

    std::cout << "Rubrica di persone \n \n";

    PrintRubrica();
    
    bool running = true;
    while(running){

        std::cout << "cosa vuoi fare?\n"
                  << "[1] stampare la rubrica"
                  << "[2] inserire persone"
                  << "[3] modificare dati di una persona"
                  << "[4] eliminare una persona";

        int scelta;
        std::cin >> scelta;

        switch(scelta){

            case 1:
                PrintRubrica();
            break;

            case 2:
                //InsertRubrica
            break;    

            case 3:
                //modify person
            break;

            case 4:
                //delete person
            break;

            default: 
                std::cout << "invalid input";
            break;
                
        }

    }

}

//funzioni

//stampa rubrica
void PrintRubrica(){
    std::ifstream rubricaOut("rubrica.txt");
    std::string lettura;
    
    while(getline(rubricaOut, lettura)){
        std::cout << lettura << "\n \n";
    }
    rubricaOut.close();
}

//inserisci persone
void InsertRubrica(){
    std::ofstream rubricaIn("rubrica.txt");

}