#include <iostream>

class Rettangolo{
    private:

        //values for the rectangle
        float height;
        float base;

    public:

        //constructor
        Rettangolo(float h, float b){
            height = h;
            base = b;
        }

        //method for the area
        void area(){
            float area = base*height;
            std::cout << "\narea: " << area;
        }

        //getter for the height
        float getHeight() {
            return height;
        }

        //getter for the base
        float getBase(){
            return base;
        }

        void setHeight(float h){
            if(h > 0){
                height = h;
            }
        }

        void setBase(float b){
            if(b > 0){
                base = b;
            }
        }
};

int main(){

    float h, b; //h: height, b: base
    std::cout << "height: ";
    std::cin  >> h;
    std::cout << "base: ";
    std::cin >> b;

    //initializing a class variable
    Rettangolo r(h, b);

    //using the getter
    std::cout << "\nheight inserted: " << r.getHeight();
    std::cout << "\nbase inserted: " << r.getBase();

    //using the method
    r.area();   

    bool running = true;
    while(running){
        std::cout << "\nwhat do you want to modify?"
                  << "\n1) height"
                  << "\n2) base"
                  << "\n3) exit\n";

        int choice;
        std::cin >> choice;

        switch(choice){

            case 1: //height 
                std::cout << "set a new height: ";
                std::cin >> h;
                
                //using the setter
                r.setHeight(h);
            break;


            case 2: //base
                std::cout << "set a new base: ";
                std::cin >> b;

                //using the setter
                r.setBase(b);
            break;
            

            case 3: //exit
                running = false;
            break;

            default:
                std::cout << "invalid number.";
            break;

        }

        if(choice > 0 && choice < 3){
            std::cout << "\nheight inserted: " << r.getHeight();
            std::cout << "\nbase inserted: " << r.getBase();
            r.area();
        }
    }

    return 0;
}