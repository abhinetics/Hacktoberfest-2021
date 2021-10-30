#include <iostream>
#include <cmath>
using namespace std;

class Harpeet
{
    float a, b, c, x1, x2, discriminant, realPart, imaginaryPart;

public:

    void getData()
    {

        cout << "Enter coefficients a, b and c: ";
        cin >> a >> b >> c;

    }
    friend void quad(Harpeet&);

};

void quad(Harpeet &i)
{

    i.discriminant = i.b*i.b - 4*i.a*i.c;

    if (i.discriminant > 0) {
        i.x1 = (-i.b + sqrt(i.discriminant)) / (2*i.a);
        i.x2 = (-i.b - sqrt(i.discriminant)) / (2*i.a);
        cout << "Roots are real and different." << endl;
        cout << "x1 = " << i.x1 << endl;
        cout << "x2 = " << i.x2 << endl;
    }

    else if (i.discriminant == 0) {
        cout << "Roots are real and same." << endl;
        i.x1 = -i.b/(2*i.a);
        cout << "x1 = x2 =" << i.x1 << endl;
    }

    else {
        i.realPart = -i.b/(2*i.a);
        i.imaginaryPart =sqrt(-i.discriminant)/(2*i.a);
        cout << "Roots are complex and different."  << endl;
        cout << "x1 = " << i.realPart << "+" << i.imaginaryPart << "i" << endl;
        cout << "x2 = " << i.realPart << "-" << i.imaginaryPart << "i" << endl;
    }

}

int main() {


    Harpeet obj;
    obj.getData();
    quad(obj);

    return 0;
}
