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

    std::cout << "This is an agenda of people, before inserting tell me how many people would you like to insert [max should be 100]:\n";
    int NumP;
    std::cin >> NumP;
    std::cout << "Now insert the data, ";

    for(int i=0; i<NumP; i++){
        std::cout << "person " << i+1 << ":\n"; 
        std::cin >> persone[i];       
    }

    std::cout << "now, watchu gon' do next?"
              << "\n[1] insert people"
              << "\n[2] print agenda\n";
    
    int option;
    std::cin >> option;
    
    while(true){
    switch(option){
        
        case 1:
            for(int i=0; i<NumP; i++){
                std::cout << "\nperson " << i+1 << ":\n"; 
                std::cin >> persone[i];       
            }
        break;

        case 2:
            for(int i=0; i<NumP; i++){
                std::cout << "\nperson " << i+1 << ":"; 
                std::cout << persone[i]; 
            }
        break;
        
        default:
            std::cout << "inserimento non valido";
        break;

    }
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
           << "\ncivic: " << s.civic << "\n";

        return os;
    }