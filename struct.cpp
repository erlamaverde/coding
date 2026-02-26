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
};

//FUNZIONI DICHIARATE
std::istream& operator>>(std::istream& is, TStudente& s);

std::ostream& operator<<(std::ostream& os, TStudente& s);


//MAIN
int main()
{
    TStudente persona1;
    int vet[100];

    std::cin >> persona1;
    std::cout << persona1;
    
    return 0;
}


//FUNZIONI
std::istream& operator>>(std::istream& is, TStudente& s)
    {
        std::cout << "gimme ur name\n";
        getline(is >> std::ws, s.name);

        std::cout << "gimme ur surname\n";
        getline(is >> std::ws, s.surname);

        std::cout << "now i need ur age\n";
        std::cin >> s.age;

                    return is;
    }

std::ostream& operator<<(std::ostream& os, TStudente& s)
    {
        os << "\nname: " << s.name
           << "\nsurname: " << s.surname
           << "\nage: " << s.age;
        return os;
    }