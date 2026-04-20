#include <iostream>
#include <fstream>
#include <string>

//struct
struct Tpersone{
    std::string nome;
    std::string cognome;
    int eta;
};

//funzioni
void PrintRubrica();
std::istream& operator>>(std::istream& is, Tpersone& s);
std::ostream& operator<<(std::ostream& os, Tpersone& s);
void InsertRubrica(Tpersone persona);

int main(){

    Tpersone persona;

    std::cout << "Rubrica di persone \n \n";

    PrintRubrica();
    
    bool running = true;
    while(running){

        std::cout << "\ncosa vuoi fare?\n"
                  << "[1] stampare la rubrica\n"
                  << "[2] inserire persone\n"
                  << "[3] modificare dati di una persona\n"
                  << "[4] eliminare una persona\n";

        int scelta;
        std::cin >> scelta;

        switch(scelta){

            case 1:
                PrintRubrica();
            break;

            case 2:
                InsertRubrica(persona);
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

//functions

//print rubrica
void PrintRubrica(){
    std::ifstream rubricaOut("rubrica.txt");
    std::string lettura;
    
    while(getline(rubricaOut, lettura)){
        std::cout << lettura << "\n \n";
    }
    rubricaOut.close();
}

//insert people
void InsertRubrica(Tpersone persona){
    std::ofstream rubricaIn("rubrica.txt", std::ios::app);
    std::cin >> persona;
    
    rubricaIn << "1) ";
    rubricaIn << "NOME: " << persona.nome 
              << "COGNOME: " << persona.cognome 
              << "ETA': " << persona.eta
              << "\n";

    rubricaIn.close();
}

//input stream
std::istream& operator>>(std::istream& is, Tpersone& s){

    std::cout << "dammi il nome: ";
    getline(is >> std::ws, s.nome);

    std::cout << "\ndammi il cognome: ";
    getline(is >> std::ws, s.cognome);

    std::cout << "\ndammi l'età: ";
    is >> s.eta;

    return is;

}

//output stream
std::ostream& operator<<(std::ostream& os, Tpersone& s){

    os << "NOME: " << s.nome;
    
    os << "\nCOGNOME: " << s.cognome;

    os << "\nETA': " << s.eta;

    return os;
}