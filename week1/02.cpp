/*
Create a flight class that has private data members: flight number (integer),
destination(characters), distance (float), fuel (float).
a) Initialize fuel to 13.2 liters
b) Provide a parameterized function that accepts fuel details
c) Private Member functions: calculate_fuel() to calculate the value of Fuel as per the following
criteria:
Distance (in kilometers) Fuel (in liters)
<=1000 500
>1000 and <=2000 1100
>2000 2200
*/

#include <iostream>
using namespace std;
class flight{
        int flight_no;
        char destination[20];
        float distance , fuel = 13.2;

        void calculate_fuel(float dist){
                if(dist <= 1000)
                        fuel = 500;
                else if(dist > 1000 && dist <=2000)
                        fuel = 1100;
                else
                        fuel = 2200;
        }

        public:
                void information_entry(){
                        cout << "Enter flight number: ";
                        cin >> flight_no;
                        cout << "Enter destination: ";
                        cin >> destination;
                        cout << "Enter distance: ";
                        cin >> distance;
                        calculate_fuel(distance);
                }

                void display_info(){
                        cout << "Flight number : " << flight_no << endl;
                        cout << "Destination : " << destination << endl;
                        cout << "Distance = " << distance << endl;
                        cout << "Fuel = " << fuel << " liters" << endl;
                }
};

int main(){
        flight f;
        f.information_entry();
        f.display_info();
        return 0;
}



