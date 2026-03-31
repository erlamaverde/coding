#include <iostream>
#include <string>
#include <vector>
#include <limits>

//funzioni
void reverse();
void unevenswitch();
void translate();

int main(){

    while(true){
    int scelta;
    std::cout << "inserisci scelta: \n"
              << "[1] rovescia la parola\n"
              << "[2] scambia lettere dispari della parola\n"
              << "[3] traduci in simboli e numeri\n";

    std::cin >> scelta;

    switch(scelta){

        case 1:
        reverse();
        break;
        
        case 2:
        unevenswitch();
        break;

        case 3:
        translate();
        break;

        default:
        std::cout << "scelta invalida \n";
        break;
    }
}
}


//1 scambia lettere di una stringa
void reverse(){
    std::cout << "\ndammi una parola: \n";
    std::string parola;
    getline(std::cin >> std::ws, parola);
    int m = parola.size() / 2;
    if(parola.size() % 2 != 0){
        m++;
    }

    for(int i=0; i<m; i++){
        std::swap(parola[i], parola[parola.size()-1-i]);
    }
    std::cout << parola << "\n";
}

//1.1 scambia le lettere reciproce

void unevenswitch(){
    std::cout << "\ndammi una parola: \n";
    std::string parola;
    getline(std::cin >> std::ws, parola);
    int m = parola.size() / 2;
    if(parola.size() % 2 != 0){
        m++;
    }

    for(int i=0; i<m; i++){
        std::swap(parola[i], parola[parola.size()-1-i]);
        i++;
    }
    std::cout << parola;
    std::cout << "\n" << parola.size()/2;
}

//2 traduci una parola in un vettore di ? per consonanti e * per vocali con il rispettivo numero

void translate(){

    //struttura per contentere sia ?/* che il numero
    struct TLettera{
        char lettera;
        int numero;
    };

    std::string parola;
    std::vector<TLettera> vect;

    //input parola
    std::cout << "\nInserisci una parola: \n";
    getline(std::cin >> std::ws, parola);

    //ciclo per controllare ogni lettera della parola
    for(int i=0; i<parola.size(); i++){
    if(parola[i] == 'a' || parola[i] == 'e' || parola[i] == 'i' || parola[i] == 'o' || parola[i] == 'u') //controllo se la lettera è una vocale
    {   

        //mi segno che è di categoria vocale
        TLettera vocale;
        vocale.lettera = '*';

        //mi segno quale vocale è
        if(parola[i] == 'a'){
            vocale.numero = 1;
        }
        if(parola[i] == 'e'){
            vocale.numero = 2;
        }
        if(parola[i] == 'i'){
            vocale.numero = 3;
        }
        if(parola[i] == 'o'){
            vocale.numero = 4;
        }
        if(parola[i] == 'u'){
            vocale.numero = 5;
        }

        //mi salvo la lettera tradotta nel vettore
        vect.push_back(vocale);
    }
    else if(parola[i] >= 'a' && parola[i] <= 'z') //se non è una vocale, controllo se è una consonante
    {   
        //mi segno che è di categoria consonante
        TLettera consonante;
        consonante.lettera = '?';

        //controllo quale consonante è
        if(parola[i] > 'a' && parola[i] < 'e'){
            consonante.numero = parola[i] - 'a';
        }
        if(parola[i] > 'e' && parola[i] < 'i'){
            consonante.numero = parola[i] - 'b'; 
        }
        if(parola[i] > 'i' && parola[i] < 'o'){
            consonante.numero = parola[i] - 'c';
        }
        if(parola[i] > 'o' && parola[i] < 'u'){
            consonante.numero = parola[i] - 'd';
        }
        if(parola[i] > 'u'){
            consonante.numero = parola[i] - 'e';
        }

        //mi salvo la lettera tradotta nel vettore
        vect.push_back(consonante);

    }
    }

    //stampo vettore
    for (int i = 0; i < vect.size(); i++) {
        std::cout << vect[i].lettera << vect[i].numero << " ";
}   
    //codice per ritradurre da simboli a lettere
    while(true){
    std::cout << "vuoi riscriverla come prima? [y/n]\n";
    char cont;
    if(!(std::cin >> cont)){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\ninvalid input\n";
        continue;
    }
    else if(cont == 'y'){

        char CharLettera;

        //controllo se è una vocale o una consonante e la salvo nella variabile CharLettera
        for(int i=0; i<vect.size(); i++){

            if(vect[i].lettera == '*')
            {
                if(vect[i].numero == 1){ 
                    CharLettera = 'a';
                }
                if(vect[i].numero == 2){
                    CharLettera = 'e';  
                }
                if(vect[i].numero == 3){
                    CharLettera = 'i';    
                }
                if(vect[i].numero == 4){
                    CharLettera = 'o';
                }
                if(vect[i].numero == 5){
                    CharLettera = 'u'; }
            }
            else if(vect[i].lettera == '?')
            {
                if(vect[i].numero >= 1  && vect[i].numero <= 3){
                    CharLettera = 'a' + vect[i].numero;
                }
                if(vect[i].numero >= 4 && vect[i].numero <= 6){   
                    CharLettera = 'b' + vect[i].numero;
                }
                if(vect[i].numero >= 7 && vect[i].numero <= 11){  
                    CharLettera = 'c' + vect[i].numero;
                }
                if(vect[i].numero >= 12 && vect[i].numero <= 16){ 
                    CharLettera = 'd' + vect[i].numero;
                }
                if(vect[i].numero >= 17){                       
                    CharLettera = 'e' + vect[i].numero;
                }
            }

            //stampo la parola lettera per lettera
            std::cout << CharLettera;
        }
        std::cout << "\n";
        break;
    }
    else
    {
        std::cout<< "\nexiting...\n";
        break;
    }
}
}


void frag(){


    std::string parola;  //parola data
    std::vector<char> vectvocali; //vettore di vocali
    std::vector<char> vectconsonanti; //vettore di consonanti

    //input
    std::cout << "dammi una parola: \n"; 
    getline(std::cin >> std::ws, parola);

    //array delle vocali
    char vocali[] = {'a', 'e', 'i', 'o', 'u'};

    //ciclo per separare vocali e consonanti
    for(int i=0; i<parola.size(); i++){
        char lettera; //char per eseguire push_back

        if(parola[i] == 'a' ||)
        }
        std::cout << "Consonanti: {";
        for(auto i : vectconsonanti){
            std::cout << vectconsonanti[i] << ", ";
        }

        std::cout << "}  Vocali: {";
        for(auto i : vectvocali){
            std::cout << vectvocali[i] << ", ";
        }

        std::cout << "}";
    }


