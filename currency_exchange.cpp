#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {

    cout << "Enter an amount in cents: ";
    int e_cents {};
    cin >> e_cents;

    cout << "You can provide this change as follows: " << endl;

    int currency {};

    currency = e_cents / 100;
    cout << "dollers: " << currency << endl;
    e_cents -= currency * 100;

    currency = e_cents / 25;
    cout << "quarters: " << currency << endl;
    e_cents -= currency * 25;

    currency = e_cents / 10;
    cout << "dimes: " << currency << endl;
    e_cents -= currency * 10;

    currency = e_cents / 5;
    cout << "nickles: " << currency << endl;
    e_cents -= currency *5;

    cout << "pennies: " << e_cents<< endl;

    cout << endl;
    return 0;
}
