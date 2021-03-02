#include<bits/stdc++.h>
using namespace std;
#define APROXIMATION  0.01

double f(double x)
{
    return x*x -3;
}

double df(double x)
{
    return 2*x;
}


void Bisection(double a, double b)
{
  double c;
    while ((b-a) >= APROXIMATION)
    {
        // Find middle point
        c = (a+b)/2;

        if (f(c) == 0.0)
            break;

        else if (f(c)*f(a) < 0)
            b = c;
        else
            a = c;


    }
    cout << "Root Value : " << c;
}
void False_Position(double a, double b)
{
    double c;
    while ((b-a) >= APROXIMATION)
    {
        // Find middle point
        c = (a*f(b)-b*f(a))/(f(b)-f(a));

        if (f(c) == 0.0)
            break;

        else if (f(c)*f(a) < 0)
            b = c;
        else
            a = c;

    }
    cout << "Root Value : " << c;
}
void Newton_Raphson(double x)
{
    double h = f(x) / df(x);
    while (abs(h) >= APROXIMATION)
    {

        x = x - h;
        if(f(x)==0)
        {
            break;
        }
         h = f(x)/df(x);

    }

    cout << "Root Value : " << x;
}

int main()
{
    double a,b,select;
    cout<<"Enter two assumption Value. If you Choice Newton Rephson Method it will consider only First value: \n";
    cin>>a;
    cin>>b;
    cout<<"Press 1 for Bisection method: \n";
    cout<<" Press 2 for Regular_Falsi method: \n";
    cout<<"Press 3 for Newton_Raphson method: \n";
   label:
    cin>>select;

    if(select==1)
    {
        Bisection(a, b);
    }
    else if(select==2)
    {
        False_Position(a, b);
    }
    else if(select==3)
    {
        Newton_Raphson(a);
    }
    else
    {
        cout<<"Press right value: ";
        goto label;
    }
    return 0;
}
