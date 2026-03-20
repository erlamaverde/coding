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
    std::string p;
    getline(std::cin >> std::ws, p);
    int m = p.size() / 2;
    if(p.size() % 2 != 0){
        m++;
    }

    for(int i=0; i<m; i++){
        std::swap(p[i], p[p.size()-1-i]);
    }
    std::cout << p << "\n";
}

//1.1 scambia le lettere reciproce

void unevenswitch(){
    std::cout << "\ndammi una parola: \n";
    std::string p;
    getline(std::cin >> std::ws, p);
    int m = p.size() / 2;
    if(p.size() % 2 != 0){
        m++;
    }

    for(int i=0; i<m; i++){
        std::swap(p[i], p[p.size()-1-i]);
        i++;
    }
    std::cout << p;
    std::cout << "\n" << p.size()/2;
}

//2 traduci una parola in un vettore di ? per consonanti e * per vocali con il rispettivo numero

void translate(){

    struct TLettera{
        char lettera;
        int numero;
    };

    std::string p;
    std::vector<TLettera> tl;
    std::cout << "Inserisci una parola: \n";
    getline(std::cin >> std::ws, p);
    for(int i=0; i<p.size(); i++){
    if(p[i] == 'a' || p[i] == 'e' || p[i] == 'i' || p[i] == 'o' || p[i] == 'u')
    {   

        TLettera vocale;
        vocale.lettera = '*';
        if(p[i] == 'a'){
            vocale.numero = 1;
        }
        if(p[i] == 'e'){
            vocale.numero = 2;
        }
        if(p[i] == 'i'){
            vocale.numero = 3;
        }
        if(p[i] == 'o'){
            vocale.numero = 4;
        }
        if(p[i] == 'u'){
            vocale.numero = 5;
        }

        tl.push_back(vocale);
    }
    else if(p[i] >= 'a' && p[i] <= 'z')
    {
        TLettera consonante;
        consonante.lettera = '?';
        if(p[i] > 'a' && p[i] < 'e'){
            consonante.numero = p[i] - 'a';
        }
        if(p[i] > 'e' && p[i] < 'i'){
            consonante.numero = p[i] - 'a' - 1; 
        }
        if(p[i] > 'i' && p[i] < 'o'){
            consonante.numero = p[i] - 'a' - 2;
        }
        if(p[i] > 'o' && p[i] < 'u'){
            consonante.numero = p[i] - 'a' - 3;
        }
        if(p[i] > 'u'){
            consonante.numero = p[i] - 'a' - 4;
        }
        tl.push_back(consonante);

    }
    }
    for (int i = 0; i < tl.size(); i++) {
    std::cout << tl[i].lettera << " " << tl[i].numero << "\n";
}
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
        
        for(int i=0; i<tl.size(); i++){
            if(tl[i].lettera == '*'){

            }
        }
        break;
    }
    else
    {
        std::cout<< "\nexiting...\n";
        break;
    }
}
}


//2 con scrittura {} consigliata da claude
void translate1(){

    struct TLettera{
        char lettera;
        int numero;
    };

    std::string p;
    std::vector<TLettera> tl;
    std::cout << "Inserisci una parola: \n";
    getline(std::cin >> std::ws, p);
    for(int i=0; i<p.size(); i++){
    if(p[i] == 'a' || p[i] == 'e' || p[i] == 'i' || p[i] == 'o' || p[i] == 'u')
    {   

        TLettera vocale;
        tl.push_back({'*', p[i]});
    }
    else if(p[i] >= 'a' && p[i] <= 'z')
    {
        tl.push_back({'?', p[i]});

    }
    }
    for (int i = 0; i < tl.size(); i++) {
    std::cout << tl[i].lettera << " " << tl[i].numero << "\n";
}

}

//3 traduci dal vettore a parola

void reverseTranslate(){

}