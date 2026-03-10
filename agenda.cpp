//LIBRERIE
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <limits>


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

void modifyPerson(std::vector<TStudente>& person);
void deletePerson(std::vector<TStudente>& person);

//MAIN
int main()
{
    TStudente PersonModel; //riferimento per l'inserimento dei dati, poi pushati nel vector
    std::vector<TStudente> person; //agenda di persone

    std::cout << "This is an agenda of people, before inserting tell me how many people would you like to insert [max should be 100]:\n";
    int NumP;
    std::cin >> NumP;
    std::cin.ignore();
    std::cout << "Now insert the data, ";

    for(int i=0; i<NumP; i++){
        std::cout << "person " << i+1 << ":\n"; 
        std::cin >> PersonModel;
        person.push_back(PersonModel);
    }
    
    //WHILE
    bool running = true;

    while(running){
        
    std::cout << "\nnow, what will you do next?"
              << "\n[1] insert people"
              << "\n[2] modify person"
              << "\n[3] delete person\n"
              << "\n[7] print agenda\n";
    
    int option;
    std::cin >> option;

    switch(option){
        
        case 1:
            std::cout << "how many people would you like to insert [max should be 100]:\n";
            std::cin >> NumP;
            std::cin.ignore();
            for(int i=0; i<NumP; i++){
                std::cout << "\nperson " << i+1 << ":\n"; 
                std::cin >> PersonModel;
                person.push_back(PersonModel);
            }
        break;

        case 2:
            modifyPerson(person);
            break;

        case 3:
            deletePerson(person);
            break;

        case 4:
            //permanent sort
            break;
        
        case 5:
            //temporary sort
            break;

        case 6:
            //mix agenda
            break;
        
        case 7:
            for(int i=0; i<person.size(); i++){
                std::cout << "\nperson " << i+1 << ":"; 
                std::cout << person[i];
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


//modify person
    void modifyPerson(std::vector<TStudente>& person){

        while(true){
        std::cout << "wich peroson would you like to modify? [insert its number]\n";

        for(int i=0; i<person.size(); i++){
        std::cout << "[" << i+1 << "] " << person[i].name << " " << person[i].surname << "\n";
        }

        int target;
        if(!(std::cin >> target))
        {
            std::cout << "invalid input, returning to menu\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }
        else if(target < 1 || target > person.size())
        {
            std::cout << "invalid input, returning to menu\n";
            return;
        }
        else
        {   
            //name
            std::cout << "name [press enter to skip]:\n";
            std::string newName;
            std::cin.ignore();
            getline(std::cin, newName);
            if(newName.empty())
            {
                newName = person[target-1].name;
            }
            
            //surname
            std::cout << "surname [press enter to skip]:\n";
            std::string newSurname;
            getline(std::cin, newSurname);
            if(newSurname.empty())
            {
                newSurname = person[target-1].surname;
            }
            
            //age
            std::cout << "age [press enter to skip]:\n";
            int newAge;
            std::string ageInput;
            getline(std::cin, ageInput);
            if(ageInput.empty()){
                ageInput = std::to_string(person[target-1].age);
            }
            
            //civic
            std::cout << "civic [press enter to skip]:\n";
            int newCivic;
            std::string civicInput;
            getline(std::cin, civicInput);
            if(civicInput.empty()){
                civicInput = std::to_string(person[target-1].civic);
            }

            //update queue
            person[target-1].name = newName;
            person[target-1].surname = newSurname;
            person[target-1].age = std::stoi(ageInput);
            person[target-1].civic = std::stoi(civicInput);

            std::cout <<"press any letter or number to exit or [1] to modify another person?\n";
            int choice;
            if(!(std::cin>>choice))
            {
                std::cout << "returning to menu\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return;
            }
            else if(choice != 1)
            {
                return;
            }
            else
            {
                continue;
            }
            }
            
        }
    }

//delete person
void deletePerson(std::vector<TStudente>& person){


    std::cout << "wich person would you like to delete?\n";
    for(int i=0; i<person.size(); i++){
        std::cout << "[" << i+1 << "] " << person[i].name << " " << person[i].surname << "\n";
        }

        int target;
        if(!(std::cin >> target))
        {
            std::cout << "invalid input, returning to menu\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }
        else if(target < 1 || target > person.size())
        {
            std::cout << "invalid input, returning to menu\n";
            return;
        }
        else
        {   
            std::cout << "are you sure you want to delete person [" << target << "] " << person[target-1].name << " " << person[target-1].surname << "? [y/n]\n";
            char confirmation;
            if(!(std::cin >> confirmation))
            {
                std::cout << "invalid input, returning to menu\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return;
            }
            else if (confirmation == 'n' || confirmation == 'N')
            {
                std::cout << "deletion cancelled, returning to menu\n";
                return;
            }
            else if (confirmation == 'y' || confirmation == 'Y')
            {
            person.erase(person.begin() + target -1);
            std::cout << "person deleted successfully\n";
            return;
            }
            else
            {
                std::cout << "invalid input, returning to menu\n";
                return;
            }

    }
}

//permanent sort
void permSort(std::vector<TStudente>& person){
    std::cout << "how would you like to sort the agenda?\n"
              << "[1] name\n"
              << "[2] surname\n"
              << "[3] age\n"
              << "[4] civic\n";
    int choice;
    if(!(std::cin >> choice))
    {
        std::cout << "invalid input, returning to menu\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    else if(choice < 1 || choice > 4)
    {
        std::cout << "invalid input, returning to menu\n";
        return;
    }
    else
    {
        //sort logic here
    }
}

//temporary sort
void tempSort(std::vector<TStudente>& person){
    std::cout << "how would you like to sort the agenda?\n"
              << "[1] name\n"
              << "[2] surname\n"
              << "[3] age\n"
              << "[4] civic\n";
    int choice;
    if(!(std::cin >> choice))
    {
        std::cout << "invalid input, returning to menu\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    else if(choice < 1 || choice > 4)
    {
        std::cout << "invalid input, returning to menu\n";
        return;
    }
    else
    {
        //sort logic here
    }
}