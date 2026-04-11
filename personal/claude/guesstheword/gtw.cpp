//Gioco "indovina la parola"
//Il programma sceglie una parola a caso da un vettore, la mostra con * al posto delle lettere, e l'utente indovina lettera per lettera. 

#include <iostream>
#include <vector>
#include <string>
#include <random>

//funzioni
bool islonger(std::string inserimento, std::string parola);
void check(std::string parola, std::string inserimento);

int main(){

    //non uso fstream perchè lo imparerò più avanti
    std::vector<std::string> lista = {"banana", "autostrada", "macchina", "terremoto", 
                                      "programmazione", "tastiera", "finestra", "vettore",
                                      "struttura", "funzione", "compilatore", "algoritmo",
                                      "variabile", "puntatore", "ricorsione", "biblioteca",
                                      "carattere", "stringa", "pinguino", "elefante",
                                      "montagna", "cascata", "fulmine", "labirinto"};

    
    std::string parola;
    

    std::random_device rd; //genero un numero casuale con rumore hardware (seed)
    std::mt19937 gen(rd()); //uso il seed (rd) per generare un numero casuale con l'algoritmo mt19937
    std::uniform_int_distribution<int> dist(0, lista.size()-1); //indico il range
    
    //creo assegno il numero a un intero e lo uso per indicare quale parola sto usando
    int indice = dist(gen);
    parola = lista[indice];

    //stampo la parola con solo *
    for(int i=0; i<parola.size(); i++){
        std::cout << "*";
    }
    std::cout << " (" << parola.size() << " lettere)";

bool running = true;

    while(running){

        //richiedo un inserimento
        std::cout << "\nindovina la parola: ";
        std::string inserimento;
        std::cin >> inserimento;

        
        switch(islonger(inserimento, parola)){

            //controllo se la parola inserita è più lunga di quella del vettore
            case true:
            
            std::cout << "\nhai inserito una parola da " << inserimento.size() << " lettere, troppo lunga!\n";
            for(int i=0; i<parola.size(); i++){
                std::cout << "*";
            }   std::cout << "(" << parola.size() << " lettere)\n";

            std::cout << "indovina la parola: ";
            std::cin >> inserimento;
            
            break;


            case false:
            
            check(inserimento, parola);
            break;
        }
    }


}

//funzione per controllare se la parola inserita è più lunga di quella del vettore
bool islonger(std::string inserimento, std::string parola){

        if(inserimento.size() > parola.size()){
            return true;
        }
        else{
            return false;
        }

}

//funzione che controlla quali lettere sono uguali
void check(std::string parola, std::string inserimento){
    std::vector<char> output;

    for(int i=0; i<parola.size(); i++){
        output.push_back('*');
    }
    std::cout << "\n";
    for(int i=0; i<parola.size(); i++){
        if(parola[i] = inserimento[i]){
            output[i] = inserimento[i];
        }
    }

    for(int i=0; i<output.size(); i++){
        std::cout << output[i];
    }
}