#include <iostream>
#include <array>
#include <string>
using namespace std;

constexpr int n = 6;
array<int,n> xi{-1,0,1,2,3,4};
array<int,n> yi{-243,-32,-1,0,1,32};

double lagrange(double _x);

int main() {

    for(const auto i : xi)
        cout << lagrange(i)<<" ";
    cout << endl;
    string L;
    for (int j = 0; j < n; ++j) {
        L+= to_string(yi[j]*lagrange(j)/lagrange(xi[j])) + '\t';
    }
    cout << L;
    return 0;
}
double lagrange(double _x)
{
    double result = 0.0;
    for (short i = 0; i < n; i++)
    {
        double P = 1.0;
        for (short j = 0; j < n; j++)
            if (j != i)
                P *= (_x - xi[j])/(xi[i] - xi[j]);
        result += P * yi[i];
    }
    return result;
}