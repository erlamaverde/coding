#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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
void InsertRubrica(Tpersone persona, int& NumPerson);
void deletePerson();


int main(){

    std::ifstream rubricaOut("rubricaIn.txt");
    int NumPerson = 1;
    std::string output;
    while(getline(rubricaOut, output)){
        NumPerson++;
    }

    Tpersone persona;

    std::cout << "Rubrica di persone \n \n";

    PrintRubrica();
    
    bool running = true;
    while(running){

        std::cout << "\ncosa vuoi fare?\n"
                  << "[1] stampare la rubricaIn\n"
                  << "[2] inserire persone\n"
                  << "[3] eliminare una persona\n"
                  << "[4] modificare dati di una persona\n";
        int scelta;
        std::cin >> scelta;

        switch(scelta){

            case 1:
                PrintRubrica();
            break;

            case 2:
                InsertRubrica(persona, NumPerson);
            break;    

            case 3:
                deletePerson();
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

//print rubricaIn
void PrintRubrica(){
    std::ifstream rubricaOut("rubricaIn.txt");
    std::string output;
    
    while(getline(rubricaOut, output)){
        std::cout << output << "\n";
    }
    rubricaOut.close();
}

//insert people
void InsertRubrica(Tpersone persona, int& NumPerson){
    std::ofstream rubricaIn("rubricaIn.txt", std::ios::app);
    std::cin >> persona;
    
    rubricaIn << NumPerson << ") ";
    rubricaIn << "NOME: " << persona.nome 
              << ", COGNOME: " << persona.cognome 
              << ", ETA': " << persona.eta
              << "\n";
    NumPerson++;
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

//delete person

void deletePerson(){
    std::cout << "\n chi vuoi eliminare (inserisci il numero)? \n";
    std::ifstream rubricaOut("rubrica.txt");
    std::vector<std::string> FlyingFile;
    std::string output;

    while(getline(rubricaOut, output)){
        std::cout << output << "\n";
        FlyingFile.push_back(output);
    }

    rubricaOut.close();
    int choice;
    std::cin >> choice;

    FlyingFile[choice-1].erase();

    std::ofstream rubricaIn("rubrica.txt");
    for(int i=0; i<FlyingFile.size(); i++){
        std::string input;
        input = FlyingFile[i];
        rubricaIn << input << "\n";
    }
    rubricaIn.close();
}