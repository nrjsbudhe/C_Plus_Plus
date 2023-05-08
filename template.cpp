
#include <iostream>
using namespace std;
 

// This is a Template
template <typename T> 
void swapy(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;

}

// Example of Template overloading
template <typename T>
void swapy(T x[], T y[], int g){
  for(int i = 0; i < g; i++){
    T temp = x[i];
    x[i] = y[i];
    y[i] = temp;
  }
}
 
int main()
{
    int a = 10;
    int b = 100;
    swapy(a,b);

    cout<<a<<endl;
    cout<<b<<endl;

    string A = "Neeraj";
    string B = "Sahasrabudhe";

    swapy(A,B);

    cout<<A<<endl;
    cout<<B<<endl;

    int ones[] = {1,1,1,1,1};
    int twos[] = {2,2,2,2,2};

    swapy(ones,twos,5);

    cout<<ones[0]<<endl;
    cout<<twos[0]<<endl;
 
    return 0;
}

