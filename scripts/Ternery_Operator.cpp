#include <iostream>
using namespace std;

int main()
{
    cout << "Neeraj Sahasrabudhe"<<endl;

    int x = 10;
    int y = 20;
    int& max_ref = (x > y) ? x : y; // Use ternary operator to find the reference to the maximum of two integers
    max_ref = 30; // Assign 30 to the maximum of x and y
    cout << "Max of " << x << " and " << y << " is " << max_ref << endl;

}
  
