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

    int count = 0;

    //ofstream con sovrascrizione

    //avvio scrittura file
    std::ofstream fileOut("dati.txt");
    fileOut << "lista di persone\n \n";

    //richiedo il numero di persone da inserire
    std::cout << "quante persone vuoi inserire?: ";
    int quantita;
    std::cin >> quantita;

    //ciclo per inserire le persone in base a quantita
    for(int i=0; i<quantita; i++){
        Tpersona persona;

        //inserisco le persone nella struttura
        std::cout << "(" << count+1 << " persona):\n";
        std::cin >> persona;

        //salvo le il nome e eta nel file
        fileOut << count+1 << ") ";
        fileOut << "NOME: " << persona.nome << ", ETA: " << persona.eta << "\n \n";
        count++;
    }
    //chiudo esecuzione di fileOut
    fileOut.close();

    //avvio lettura file
    std::ifstream fileIn("dati.txt");
    std::string read;

    //sposto ciò che è scritto nel file in una stringa per poterla stampare
    while(getline(fileIn, read)){
        std::cout << read << "\n";
    }   
    //chiudo esecuzione di fileIn
    fileIn.close();

    //avvio scritta del file dati.txt senza sovrascrizione
    std::ofstream fileOutApp("dati.txt", std::ios::app);

    //chiedo quante persone inserire
    std::cout << "quante altre persone vuoi inserire?: ";
    std::cin >> quantita;

    //avvio ciclo per inserire le persone in base alla quantita
    for(int i=0; i<quantita; i++){
        Tpersona persona;

        //inserimento persona nella struttura
        std::cout << "(" << count+1 << " persona)\n";
        std::cin >> persona;    

        //salvataggio dati nel file senza sovrascrivere
        fileOutApp << count+1 << ") ";
        fileOutApp << "NOME: " << persona.nome << ", ETA: " << persona.eta << "\n \n";
        count++;
    }

    fileOutApp.close();


    fileIn.open("dati.txt");

    std::string parola;

    while(getline(fileIn, parola)){
        std::cout << parola << "\n";
    }

    fileIn.close();

}

//funzioni

//input stream
std::istream& operator>>(std::istream& is, Tpersona& s){

    std::cout << "dammi un nome: ";
    getline(is >> std::ws, s.nome);

    std::cout << "dammi un età: ";
    is >> s.eta;

    std::cout << "\n";

    return is;
}
