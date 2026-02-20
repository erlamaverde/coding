#include <iostream>

int opzioni(int vet[]);
void stampaVettore(int vet[]);

void inserimentoVoid();
int TipoDiInserimento(int inserimento);

//inserimenti senza sovrascrizione
int InsOrdinatoNO(int num, int vet[]);
int insSceglimentoNO(int num, int vet[]);
//inserimenti con sovrascrizione
int insOrdinato(int num, int vet[]);
int insSceglimento(int num, int vet[]);

int EliminaNumero(int vet[]);

void Media(int vet[]);

void BubbleSort(int vet[]);

void somma(int vet[]);

int main(){

    //richiedo il tipo di inserimento
    int inserimento;
    inserimentoVoid();
    TipoDiInserimento(inserimento);
    //se non viene scelto un numero tra 1 e 2, l'inserimento non è valido e necessito di una nuova risposta
    

//riempio il vettore di 0, così da poter contare lo 0 come casella vuota
int vet[100];
for(int i = 0; i < 100; i++){
    vet[i] = 0;
} 

int num;

//in base al tipo di inserimento, eseguo la funzione associata
switch(inserimento){
    case 1:
        insOrdinato(num, vet);
        break;
    case 2:
        insSceglimento(num, vet);
        break;
}

//creo un ciclo per poter ritornare sempre alla lista di opzioni
while(true){
switch(opzioni(vet)){
    case 1:
        //stampo il vettore
        stampaVettore(vet);
        continue;


    case 2:

    //inserisco nuovi numeri (con sovrascrizione)
            inserimentoVoid();
            inserimento = TipoDiInserimento(inserimento);

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

    //inserisco nuovi numeri (senza sovrascrizione)
            inserimentoVoid();
            inserimento = TipoDiInserimento(inserimento);
    
            switch(inserimento){
                case 1:
                    InsOrdinatoNO(num, vet);
                    break;
                case 2:
                    insSceglimentoNO(num, vet);
                    break;
                }
        break;



    case 4:
    
    //elimino le caselle richieste
        EliminaNumero(vet);
        break;
    case 5:

    //calcolo la media dei numeri
        Media(vet);
        break;
    case 6:

    //riordino i numeri
        BubbleSort(vet);
        
        std::cout << "\n questi sono i numeri in ordine:\n";
        stampaVettore(vet);
        break;
    
    case 7:

    //calcolo la somma
        somma(vet);
        break;

    default:

    //se vengono inseriti altri numeri ristampo la lista di opzioni
    std::cout << "\nil numero he hai inserito non è associato a nessuna azione!\n";
    break;
}
}
}











//FUNZIONI

void inserimentoVoid(){
    std::cout << "questo è un menu, come vuoi inserire i numeri? in ordine [1] o scegliendo la casella [2]?\n";
}

int TipoDiInserimento(int inserimento){
    while(true){
        if(!(std::cin >> inserimento)){
            std::cout << "inserimento non valido, inserisci 1 o 2\n";
            std::cin.clear();
            std::cin.ignore(100, '\n');
            continue;
        }else if(inserimento !=1 && inserimento !=2){
        std::cout << "inserimento non valido, inserisci 1 o 2\n";
        continue;
    }else{
        break;
    }
}
return inserimento;
}

int InsOrdinatoNO(int num, int vet[]){

    //controllo se la casella è vuota, in caso contrario, passo alla successiva
    for(int i = 0; i < 100; i++){
        if (vet[i] != 0){
            continue;
        }

        //richiedo un numero da inserire per la casella numero (i)
        std::cout << "inserisci un numero per la casella " << i << " (max 100), lettera per terminare\n";

        //controllo se viene inserita una lettera o uno 0 --> lo 0 è proibito
        if(!(std::cin >> num)){
            std::cout << "esco dall'inserimento...\n \n";
            std::cin.clear();
            std::cin.ignore(100, '\n');
            return 0;
        }
        if(num == 0){
            std::cout << "il numero 0 è proibito\n";
            i--;
            continue;
        }
        
        //confermo l'inserimento del numero nella corrispondende casella
        else if(i != 99){
            vet[i] = num;
        std::cout<< "hai inserito "<< num << " nella casella numero " << i << "\n";
        }else{
        std::cout << "hai riempito il vettore \n";
        return 0;
            }
        }
}

int insSceglimentoNO(int num, int vet[]){

    //richiedo una casella da riempire
    for(int i=0; i < 100; i++){
        std::cout << "inserisci la casella in cui vuoi inserire il numero (max 100), lettera per terminare \n";
        int casella;

        //controllo se viene inserita una lettera o se è stata inserita una casella invalida
        if(!(std::cin >> casella)){
            std::cout << "esco dall'inserimento...\n \n";
            std::cin.clear();
            std::cin.ignore(100, '\n');
            return 0;
        }else if(vet[casella] != 0){
            std::cout << "casella già occupata, inserisci un numero tra 0 e 100\n";
            i--;
            continue;
        }if(casella <0 || casella > 99){
            std::cout << "casella non valida, inserisci un numero tra 0 e 100\n";
            i--;
            continue;}

        //richiedo un numero da inserire nella casella selezionata
        else{
        std::cout << "inserisci il numero che vuoi inserire nella casella " << casella << "\n";

        //controllo se viene inserita una lettera o uno 0 --> lo 0 è proibito
        if(!(std::cin >> num)){
            std::cout << "esco dall'inserimento...\n \n";
            std::cin.clear();
            std::cin.ignore(100, '\n');
            return 0;
        }
        if(num == 0){
            std::cout << "il numero 0 è proibito\n";
            i--;
            continue;
        }

        //confermo l'inserimento del numero nella corrispondende casella
        vet[casella] = num;
        std::cout << "hai inserito " << num << " nella casella numero " << casella << "\n";
        }
    }
}


int insOrdinato(int num, int vet[]){

    //richiedo un numero da inserire per la casella numero (i)
    for(int i = 0; i < 100; i++){
        std::cout << "inserisci un numero per la casella " << i << " (max 100), lettera per terminare\n";

        //controllo se viene inserita una lettera o uno 0 --> lo 0 è proibito
        if(!(std::cin >> num)){
            std::cout << "esco dall'inserimento...\n \n";
            std::cin.clear();
            std::cin.ignore(100, '\n');
            return 0;
        }
        if(num == 0){
            std::cout << "il numero 0 è proibito\n";
            i--;
            continue;
        }
        
        //confermo l'inserimento del numero nella corrispondende casella
        else if(i != 99){
            vet[i] = num;
        std::cout<< "hai inserito "<< num << " nella casella numero " << i << "\n";
        }else{
        std::cout << "hai riempito il vettore \n";
        return 0;
    }
}
}

int insSceglimento(int num, int vet[]){

    //richiedo una casella da riempire
    for(int i=0; i < 100; i++){
        std::cout << "inserisci la casella in cui vuoi inserire il numero (max 100), lettera per terminare \n";
        int casella;

        //controllo se viene inserita una lettera o se è stata inserita una casella invalida
        if(!(std::cin >> casella)){
            std::cout << "esco dall'inserimento...\n \n";
            std::cin.clear();
            std::cin.ignore(100, '\n');
            return 0;
        }else if(casella <0 || casella > 99){
            std::cout << "casella non valida, inserisci un numero tra 0 e 100\n";
            i--;
            continue;
        }

        //richiedo un numero da inserire nella casella selezionata
        else{
        std::cout << "inserisci il numero che vuoi inserire nella casella " << casella << "\n";

        //controllo se viene inserita una lettera o uno 0 --> lo 0 è proibito
        if(!(std::cin >> num)){
            std::cout << "esco dall'inserimento...\n \n";
            std::cin.clear();
            std::cin.ignore(100, '\n');
            return 0;
        }
        if(num == 0){
            std::cout << "il numero 0 è proibito\n";
            i--;
            continue;
        }

        //confermo l'inserimento del numero nella corrispondende casella
        vet[casella] = num;
        std::cout << "hai inserito " << num << " nella casella numero " << casella << "\n";
        }
    }
}

int opzioni(int vet[]){

    //elenco le opzioni
    std::cout << "\n Cosa vuoi fare ora? \n";
    std::cout << "1. stampare il vettore \n";
    std::cout << "2. inserire altri numeri con sovrascrizione\n";
    std::cout << "3. inserire altri numeri senza sovrascrizione \n";
    std::cout << "4. eliminare numeri \n";
    std::cout << "5. calcolare la media dei numeri \n";
    std::cout << "6. mettere in ordine i numeri \n";
    std::cout << "7. calcolare la somma dei numeri\n";

    //richiedo un'opzione
    int opzione;
    std::cin >> opzione;
    return opzione;
}

void stampaVettore(int vet[]){

    bool vuoto = true;  //variabile per verificare se il menu è vuoto

    //stampo solo le caselle che contengono numeri diversi da 0 (lo 0 indica una casella vuota)
    for(int i = 0; i < 100; i++){
        if(vet[i] == 0){
            continue;
        }else{
        std::cout << "casella " << i << ": " << vet[i] << "\n";
        vuoto = false;
        }
    }
    if(vuoto){
        std::cout << "\n! il menu è vuoto !\n";
    }

}

int EliminaNumero(int vet[]){

    //richiedo una casella da svuotare
    for(int i=0; i < 100; i++){
    std::cout << "quale casella vuoi svuotare? inserisci un numero tra 0 e 99, lettera per terminare \n";
    int casella;

    //controllo se viene inserita una lettera o se è stata inserita una casella invalida 
    if(!(std::cin >> casella)){
        std::cout << "esco dall'eliminazione...\n \n";
        std::cin.clear(); 
        std::cin.ignore(100, '\n');
        return 0;
    }else if(casella<0 || casella>99){
        std::cout << "casella non valida, inserisci un numero tra 0 e 99\n";
        i--;
        continue;
    
    //se viene inserita una casella valida, svuoto la casella se già piena
    }if(vet[casella] == 0){
        std::cout << "la casella numero " << casella << " è già vuota\n";
        i--;
    }else{
        vet[casella] = 0;
        std::cout << "hai svuotato la casella numero " << casella << "\n";
    }
}

}

void Media(int vet[]){

    float a = 0;
    float somma;
    float media;
    bool vuoto = true;

    //sommo tutti i numeri e ne scrivo la formula
    std::cout << "\n formula della media: (";
    for(int i = 0; i < 100; i++){
        if(vet[i] == 0){
            continue;
        }else{
        somma = somma + vet[i];
        a++;
        std::cout << vet[i];
            std::cout << " + ";
        vuoto = false;

        }

    //concludo la formula e stampo la media
    }if(vuoto == true){
        std::cout << "il menu è vuoto, non posso calcolare la media)\n";
        return;
    }else{
    std::cout << "0)/" << a << "\n";
    media = somma/a;
    std::cout << "la media è: " << media << "\n";
}
}

void BubbleSort(int vet[]){

    //questo bubble sort mette in ordine i numeri senza cambiare la posizione delle caselle

    //sposto i numeri in un'altro vettore
    int b = 0;
    int slot[100];
    int bubble[100];
    for(int i = 0; i <99; i++){
        if(vet[i] == 0){
            continue;
        }else{
            bubble[b] = vet[i];
            slot[b] = i;
            b++;
        }
    }

    //metto in ordine il secondo vettore
    int temp;
    bool swapped;
    for(int i = 0; i < b; i++){
        swapped = false;
        for(int j = 0; j < b-1; j++){
            if(bubble[j] > bubble[j+1]){
                temp = bubble[j];
                bubble[j] = bubble[j+1];
                bubble[j+1] = temp;
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }

    //riporto i numeri ordinati nel primo vettore
    for(int i = 0; i < b; i++){
        vet[slot[i]] = bubble[i];
    }
}

void somma(int vet[]){

    int somma1 = 0;

    for(int i = 0; i < 99; i++){
        somma1 += vet[i];
    }

    if(somma1 == 0){
        std::cout << "\nil menu è vuoto, non posso calcolare la somma\n";
        return;
    }else{
        std::cout << "\n la somma dei numeri è uguale a: " << somma1 << "\n";
    }
}