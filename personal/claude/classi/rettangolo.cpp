#include <iostream>

class Rettangolo{
    private:

        float height;
        float base;

    public:

        Rettangolo(float h, float b){
            height = h;
            base = b;
        }

        void area(){
            float area = base*height;
            std::cout << "\narea: " << area;
        }
};

int main(){
    float h, b;
    std::cout << "height: ";
    std::cin  >> h;
    std::cout << "base: ";
    std::cin >> b;

    Rettangolo r(h, b);
    r.area();
    
}