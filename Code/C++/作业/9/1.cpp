#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
const double PI =3.1416;

class Shape
{
public:
    virtual ~Shape(){}
    virtual double getArea() const =0;
};

class Circle:public Shape
{
private:
    double r;
public:
    Circle(double R):r(R){}
    double getArea() const {return PI*r*r;}
};

class Rectangle:public Shape
{
private:
    double a,b;
public:
    Rectangle(double x,double y):a(x),b(y){}
    double getArea() const {return a*b;}
};

class Triangle:public Shape
{
private:
    double a,b,c;
public:
    Triangle(double x,double y,double z):a(x),b(y),c(z){}
    double getArea() const
    {
        double p=(a+b+c)/2;
        p=p*(p-a)*(p-b)*(p-c);
        return sqrt(p);
    }
};

double TotalArea(vector<Shape*> & v)
{
    double s=0;
    for(int i=0;i<v.size();++i)
    {
        s+=v[i]->getArea();
        delete v[i];
    }
    return s;
}

int main()
{
    string s;
    vector<Shape*> v;
    Shape* p=NULL;
    while(cin >> s)
    {
        if(s=="circle")
        {
            double r;
            cin >> r;
            p=new Circle(r);
            v.push_back(p);
        }
        else if(s=="rectangle")
        {
            double a,b;
            cin >> a >> b;
            p=new Rectangle(a,b);
            v.push_back(p);
        }
        else if(s=="triangle")
        {
            double a,b,c;
            cin >> a >> b >> c;
            p=new Triangle(a,b,c);
            v.push_back(p);
        }
    }
    cout << fixed << setprecision(4) <<TotalArea(v) << endl;
    return 0;
}
