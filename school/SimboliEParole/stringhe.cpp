#include <iostream>
#include <string>
#include <vector>
#include <limits>

//funzioni
void reverse();
void unevenswitch();
void translate();
void frag();

int main(){

    while(true){
    int scelta;
    std::cout << "inserisci scelta: \n"
              << "[1] rovescia la parola1\n"
              << "[2] scambia lettere dispari della parola1\n"
              << "[3] traduci in simboli e numeri\n"
              << "[4] separa consonanti e vocali\n";

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

        case 4:
        frag();
        break;

        default:
        std::cout << "scelta invalida \n";
        break;
    }
}
}


//1 scambia lettere di una stringa
void reverse(){
    std::cout << "\ndammi una parola1: \n";
    std::string parola1;
    getline(std::cin >> std::ws, parola1);
    int m = parola1.size() / 2;
    if(parola1.size() % 2 != 0){
        m++;
    }

    for(int i=0; i<m; i++){
        std::swap(parola1[i], parola1[parola1.size()-1-i]);
    }
    std::cout << parola1 << "\n";
}

//1.1 scambia le lettere reciproce

void unevenswitch(){
    std::cout << "\ndammi una parola1: \n";
    std::string parola1;
    getline(std::cin >> std::ws, parola1);
    int m = parola1.size() / 2;
    if(parola1.size() % 2 != 0){
        m++;
    }

    for(int i=0; i<m; i++){
        std::swap(parola1[i], parola1[parola1.size()-1-i]);
        i++;
    }
    std::cout << parola1;
    std::cout << "\n" << parola1.size()/2;
}

//2 traduci una parola1 in un vettore di ? per consonanti e * per vocali con il rispettivo numero

void translate(){

    //struttura per contentere sia ?/* che il numero
    struct TLettera{
        char lettera;
        int numero;
    };

    std::string parola1;
    std::vector<TLettera> vect;

    //input parola1
    std::cout << "\nInserisci una parola1: \n";
    getline(std::cin >> std::ws, parola1);

    //ciclo per controllare ogni lettera della parola1
    for(int i=0; i<parola1.size(); i++){
    if(parola1[i] == 'a' || parola1[i] == 'e' || parola1[i] == 'i' || parola1[i] == 'o' || parola1[i] == 'u') //controllo se la lettera è una vocale
    {   

        //mi segno che è di categoria vocale
        TLettera vocale;
        vocale.lettera = '*';

        //mi segno quale vocale è
        if(parola1[i] == 'a'){
            vocale.numero = 1;
        }
        if(parola1[i] == 'e'){
            vocale.numero = 2;
        }
        if(parola1[i] == 'i'){
            vocale.numero = 3;
        }
        if(parola1[i] == 'o'){
            vocale.numero = 4;
        }
        if(parola1[i] == 'u'){
            vocale.numero = 5;
        }

        //mi salvo la lettera tradotta nel vettore
        vect.push_back(vocale);
    }
    else if(parola1[i] >= 'a' && parola1[i] <= 'z') //se non è una vocale, controllo se è una consonante
    {   
        //mi segno che è di categoria consonante
        TLettera consonante;
        consonante.lettera = '?';

        //controllo quale consonante è
        if(parola1[i] > 'a' && parola1[i] < 'e'){
            consonante.numero = parola1[i] - 'a';
        }
        if(parola1[i] > 'e' && parola1[i] < 'i'){
            consonante.numero = parola1[i] - 'b'; 
        }
        if(parola1[i] > 'i' && parola1[i] < 'o'){
            consonante.numero = parola1[i] - 'c';
        }
        if(parola1[i] > 'o' && parola1[i] < 'u'){
            consonante.numero = parola1[i] - 'd';
        }
        if(parola1[i] > 'u'){
            consonante.numero = parola1[i] - 'e';
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

            //stampo la parola1 lettera per lettera
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

    std::string parola1;
    std::vector<char> vectvocali;
    std::vector<char> vectconsonanti;

    //input
    std::cout << "dammi una parola: ";
    getline(std::cin >> std::ws, parola1);

    char vocali[] = {'a', 'e', 'i', 'o', 'u'}; //array di vocali

    int num; //int per il push_back
    char lettera; //char per il push_back

    //ciclo che controlla lettera per lettera
    for(auto p : parola1){

        //check se appartiene all'alfabeto
        if('a' <= p <= 'z' || 'A' <= p <= 'Z'){

            //se appartiene all'alfabeto la inserisco nel vettore consonanti
            lettera = p;
            vectconsonanti.push_back(lettera);
        }
        
        //ciclo che controlla se la lettera è una vocale
        for(auto v : vocali){
            if(p == v || p == toupper(v)){

                //se è una vocale la sposto dall'array consonanti all'array vocali
                vectconsonanti.pop_back();
                vectvocali.push_back(lettera);
                break;
            }
        }
    }

    //stampo i vettori
    std::cout << "Consonanti: {";
    for(int i=0; i<vectconsonanti.size(); i++){
        std::cout << vectconsonanti[i];
        if(i < vectconsonanti.size()-1){
            std::cout << ", ";
        }
    }
    std::cout << "}  Vocali: {";
    for(int i=0;  i<vectvocali.size(); i++){
        std::cout << vectvocali[i];
        if(i < vectvocali.size()-1){
            std::cout << ", ";
        }
}
    std::cout << "}\n";
}
