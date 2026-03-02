//LIBRERIE
#include <iostream>
#include <string>
#include <fstream>


//STRUTTURE
struct TStudente
{
    std::string name;
    std::string surname;
    int age;
    int civic;
};

//FUNZIONI DICHIARATE
std::istream& operator>>(std::istream& is, TStudente& s);
std::ostream& operator<<(std::ostream& os, TStudente& s);


//MAIN
int main()
{

    TStudente persone[100];

    std::cout << "Questa è un'agenda di persone, inserisci i dati di una persona:\n";

    for(int i=0; i<2; i++){
       std::cin >> persone[i];       
    }

    for(int i=0; i<2; i++){
       std::cout << persone[i]; 
    }
    
    return 0;
}


//FUNZIONI

//input stream
std::istream& operator>>(std::istream& is, TStudente& s)
    {
        std::cout << "insert the name:\n";
        getline(is >> std::ws, s.name);

        std::cout << "insert the surname\n";
        getline(is >> std::ws, s.surname);

        std::cout << "insert the age\n";
        is >> s.age;

        std::cout << "insert ur civic number (italy):\n";
        is >> s.civic;

        return is;
    }

//output stream
std::ostream& operator<<(std::ostream& os, TStudente& s)
    {
        os << "\nname: " << s.name
           << "\nsurname: " << s.surname
           << "\nage: " << s.age
           << "\ncivic: " << s.civic;

        return os;
    }