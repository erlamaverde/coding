# GUESS THE WORD

>[!Important]
>Yeah ngl questo esercizio è lowkey **fire**

Questo esercizio simula il gioco _"indovina la parola"_, ma in modo leggermente più creativo.

Il programma sceglie una parola a caso, prendendola da un vettore _lista_. la censura sostituendo le sue parole con *, e chiede al giocatore di indovinare la parola, lettera per lettera.

---

## SELEZIONE RANDOM DELLA PAROLA

Per la selezione della parola in modo completamente casuale ho usato, come da file, questo codice:

```cpp
    std::random_device rd; //genero un numero casuale con rumore hardware (seed)
    std::mt19937 gen(rd()); //uso il seed (rd) per generare un numero casuale con l'algoritmo mt19937
    std::uniform_int_distribution<int> dist(0, lista.size()-1); //indico il range
```
Questi comandi li conoscevo perchè li avevo studiati all'asilo, e finalmente mi sono tornati utili.

Per utilizzarli, è necessaria la libreria:
```cpp
include <random>
```
