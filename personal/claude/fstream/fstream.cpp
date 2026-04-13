#include <iostream>
#include <fstream>
#include <string>

//struttura
struct Tpersona{
    std::string nome;
    int eta;
};

//funzione
std::istream& operator>>(std::istream& is, Tpersona& s);

//main
int main(){

    //ofstream con sovrascrizione
    std::ofstream fileOut("dati.txt");
    fileOut << "lista di persone\n";

    std::cout << "quante persone vuoi inserire? ";
    int quantita;
    std::cin >> quantita;

    for(int i=0; i<quantita; i++){
        Tpersona persona;
        std::cout << "(" << i+1 << " persona):\n";
        std::cin >> persona;

        fileOut << i+1 << ") ";
        fileOut << "NOME: " << persona.nome << ", ETA: " << persona.eta << "\n \n";
        
    }
    fileOut.close();

    std::ifstream fileIn("dati.txt");
    std::string read;

    while(getline(fileIn, read)){
        std::cout << read << "\n";
    }
    fileIn.close();
}

//funzioni
std::istream& operator>>(std::istream& is, Tpersona& s){

    std::cout << "dammi un nome: ";
    getline(is >> std::ws, s.nome);

    std::cout << "dammi un età: ";
    is >> s.eta;

    std::cout << "\n";

    return is;
}

