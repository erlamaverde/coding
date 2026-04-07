//Gioco "indovina la parola"
//Il programma sceglie una parola a caso da un vettore, la mostra con * al posto delle lettere, e l'utente indovina lettera per lettera. 

#include <iostream>
#include <vector>
#include <string>
#include <random>

//funzioni
bool islonger(std::string inserimento, std::string parola);
int extralenght(std::string inserimento, std::string parola);

int main(){

    //non uso fstream perchè lo imparerò più avanti
    std::vector<std::string> lista = {"banana", "autostrada", "macchina", "terremoto", 
                                      "programmazione", "tastiera", "finestra", "vettore",
                                      "struttura", "funzione", "compilatore", "algoritmo",
                                      "variabile", "puntatore", "ricorsione", "biblioteca",
                                      "carattere", "stringa", "pinguino", "elefante",
                                      "montagna", "cascata", "fulmine", "labirinto"};

    
    std::string parola;
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, lista.size()-1);
    
    int indice = dist(gen);
    parola = lista[indice];

    for(int i=0; i<parola.size(); i++){
        std::cout << "*";
    }

    std::cout << "\n";
    std::string inserimento;
    std::cin >> inserimento;

    if(islonger(inserimento, parola)){
        int extra = extralenght(inserimento, parola);
        
    for(int i=0; i<extra; i++){
        inserimento.pop_back();
    }
    }


    std::cout << parola << "\n";
    std::cout << inserimento;

}

bool islonger(std::string inserimento, std::string parola){
    bool a;
    if(inserimento.size() > parola.size()){
        return true;
    }
    else
    {
        return false;
    }
}

int extralenght(std::string inserimento, std::string parola){
    return(inserimento.size() - parola.size());
}