#include "Parameters.h"
#include "Arrays.h"
#include <iostream>
using namespace std;


int main()
{
    cout << "I am runnning" << endl;
    MJArray points(2);
    points[0]=2;
    points[1]=4;

    ParametersPieceWiseConstant test(points);

    cout << test.Integral(5,8) << endl ;
    cout << "no problem" << endl;
}
