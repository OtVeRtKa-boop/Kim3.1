#include <iostream>
#include <array>
#include <string>
using namespace std;

constexpr int n = 6;

double lagrange(array<int,n> x, array<int,n> y, double _x);

int main() {
    array<int,n> xi{-1,0,1,2,3,4};
    array<int,n> yi{-243,-32,-1,0,1,32};

    for(const auto i : xi)
        cout << lagrange(xi,yi,i)<<" ";
    cout << endl;



    return 0;
}
double lagrange(array<int,n> x, array<int,n> y, double _x)
{
    double result = 0.0;
    for (short i = 0; i < n; i++)
    {
        double P = 1.0;
        for (short j = 0; j < n; j++)
            if (j != i)
                P *= (_x - x[j])/ (x[i] - x[j]);
        result += P * y[i];
    }
    return result;
}