#include <iostream>

int opzioni(int vet[]);
void stampaVettore(int vet[]);

void inserimentoVoid();
int TipoDiInserimento(int inserimento);

int insOrdinato(int num, int vet[]);
int insSceglimento(int num, int vet[]);

int main() {
    int inserimento;
    inserimentoVoid();
    inserimento = TipoDiInserimento(inserimento);
    
    while(inserimento !=1 && inserimento !=2){

        std::cout << "inserimento non valido, inserisci 1 o 2\n";
        inserimento = TipoDiInserimento(inserimento);
    }

int vet[100];
for(int i = 0; i < 100; i++){
    vet[i] = 0;
} 

int num;

switch(inserimento){
    case 1:
        insOrdinato(num, vet);
        break;
    case 2:
        insSceglimento(num, vet);
        break;
}

while(true){
switch(opzioni(vet)){
    case 1:
        stampaVettore(vet);
        break;
    case 2:
         int inserimento;
    inserimentoVoid();
    inserimento = TipoDiInserimento(inserimento);
    
    while(inserimento !=1 && inserimento !=2){

        std::cout << "inserimento non valido, inserisci 1 o 2\n";
        inserimento = TipoDiInserimento(inserimento);
    }
    switch(inserimento){
        case 1:
            insOrdinato(num, vet);
            break;
        case 2:
            insSceglimento(num, vet);
            break;
        }
        break;
    case 3:
        std::cout << "funzione non ancora implementata\n";
        break;
    case 4:
        std::cout << "funzione non ancora implementata\n";
        break;
    case 5:
        std::cout << "funzione non ancora implementata\n";
        break;
    case 6:
        std::cout << "funzione non ancora implementata\n";
        break;
}
}
}

void inserimentoVoid(){
    std::cout << "questo è un menu, come vuoi inserire i numeri? in ordine [1] o scegliendo la casella [2]?\n";
}
int TipoDiInserimento(int inserimento){
    std::cin >> inserimento;
    return inserimento;
}

int insOrdinato(int num, int vet[]){
    for(int i = 0; i < 100; i++){
        std::cout << "inserisci un numero per la casella " << i << " (max 100), lettera o 0 per terminare\n";
        if(!(std::cin >> num) || num == 0){
            std::cout << "esco dall'inserimento...\n \n";
            std::cin.clear(); //resetta lo stato di errore
            std::cin.ignore(100, '\n'); //ignora l'input non valido
            return 0; //esce dalla funzione
        }else if(i != 99){
            vet[i] = num;
        std::cout<< "hai inserito "<< num << " nella casella numero " << i << "\n";
        }else{
        std::cout << "hai riempito il vettore \n";
        return 0;
    }
}
}

int insSceglimento(int num, int vet[]){
    for(int i=0; i < 100; i++){
        std::cout << "inserisci la casella in cui vuoi inserire il numero (max 100), lettera per terminare \n";
        int casella;
        if(!(std::cin >> casella)){
            std::cout << "esco dall'inserimento...\n \n";
            std::cin.clear(); //resetta lo stato di errore
            std::cin.ignore(100, '\n'); //ignora l'input non valido
            return 0; //esce dalla funzione
        }else if(casella <0 || casella > 99){
            std::cout << "casella non valida, inserisci un numero tra 0 e 100\n";
            i--; //decremento i per ripetere l'iterazione
            continue;}
            else{
        std::cout << "inserisci il numero che vuoi inserire nella casella " << casella << "\n";
        if(!(std::cin >> num) || num == 0){
            std::cout << "esco dall'inserimento...\n \n";
            std::cin.clear(); //resetta lo stato di errore
            std::cin.ignore(100, '\n'); //ignora l'input non valido
            return 0; //esce dalla funzione
        }
        vet[casella] = num;
        std::cout << "hai inserito " << num << " nella casella numero " << casella << "\n";
        }
    }
}

int opzioni(int vet[]){

    std::cout << "\n Cosa vuoi fare ora? \n";
    std::cout << "1. stampare il vettore \n";
    std::cout << "2. inserire altri numeri con sovrascrizione\n";
    std::cout << "3. inserire altri numeri senza sovrascrizione \n";
    std::cout << "4. eliminare numeri \n";
    std::cout << "5. calcolare la media dei numeri \n";
    std::cout << "6. mettere in ordine i numeri \n";

    int opzione;
    std::cin >> opzione;
    return opzione;
}

void stampaVettore(int vet[]){
    for(int i = 0; i < 100; i++){
        if(vet[i] != 99){
            if(vet[i] != 0){
        std::cout << "casella " << i << ": " << vet[i] << ",   ";
        }else{
            break;
        }
    }
}
}