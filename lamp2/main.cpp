#include <iostream>
#include <graphics.h>

using namespace std;

class Shape
{lamp
    int color;

public:
    Shape()
    {
        color = 0;
    }
    Shape(int c)
    {
        color = c;
    }
    void setColor(int c)
    {
        color = c;
    }


    virtual void Draw() = 0; ///Pure Virtual function
};
class Point
{
    int X, Y;
public:
    Point()
    {
        X = Y = 0;

    }
    Point( int _X, int _Y)
    {
        X = _X;
        Y = _Y;

    }
    ~Point() {}

    void SetX (int _X)
    {
        X = _X;
    }
    void SetY(int _Y)
    {
        Y = _Y;
    }
    int GetX()
    {
        return X;
    }
    int GetY()
    {
        return Y;
    }

    void Show()
    {
        cout <<"(" << X << ",";
        cout<< Y <<")"<<endl;

    }

};

///Rectangle
class Rect : public Shape
{
    Point upleft;
    Point lowright;

public:
    Rect()
    {


    }
    Rect (int X1, int Y1, int X2, int Y2, int color) :Shape(color),upleft(X1, Y1), lowright (X2, Y2)        {}

        /// Chaining
    ~Rect () { }

    void Draw ()
    {
        rectangle(upleft.GetX(),upleft.GetY(), lowright.GetX(),lowright.GetY());
    }

};

///Line Class
class Line : public Shape
{
    Point start;
    Point end;
    int Color;

public:
    Line ()
    {


    }
    Line (int X1, int Y1, int X2, int Y2, int color) :Shape(color),start(X1, Y1), end (X2, Y2){}
        /// Chaining

    ~Line () { }

    void Draw ()
    {
        line(start.GetX(),start.GetY(), end.GetX(),end.GetY());
    }
};

///Circle Class
class Circle : public Shape
{
    Point Center;
    int Radius;


public:

    Circle (int X1, int Y1,int _Radius,int color) :Shape(color),Center(X1,Y1)
        /// Chaining
    {Radius =_Radius;}

    ~Circle () { }

    void Draw ()
    {
        circle(Center.GetX(),Center.GetY(),getRadius());
    }

    int getRadius()
    {
        return Radius;
    }
};


class Triangle : public Shape
{
    Point first;
    Point second;
    Point third;

public:
    Triangle(int X1,int Y1,int X2,int Y2,int X3,int Y3,int color ):Shape(color),first(X1,Y1),second(X2,Y2),third(X3,Y3) {}
    /// Chaining
    ~Triangle() {}

    void Draw()
    {
        line(first.GetX(),first.GetY(),second.GetX(),second.GetY());
        line(first.GetX(),first.GetY(),third.GetX(),third.GetY());
        line(second.GetX(),second.GetY(),third.GetX(),third.GetY());
    }
};

class Picture
{
    int Number;
    Shape** Array;

public:
    Picture()
    {
        Number = 0;
        Array = 0;

    }
    Picture(Shape** _Array,int n)
    {
        Array = _Array;
        Number = n;
    }
    void setShape(int,Shape** );
    void paint();
};
void Picture::setShape(int n,Shape** shPtr)
{

    shapeNumber = n;
    shapeArray = shPtr;
}
void Picture::paint()
{
    for (int i = 0 ; i <shapeNumber ; i++)
    {

        shapeArray[i]->Draw();
    }
}
int main()
{
    initgraph();

  ///circle
circle c (250 ,100,20,10);
c.draw();
circle c2 (250,200,40,10);
c2.draw();
///line
line l(230,100,210,200,5);
l.draw();
line l2(270,100,290,200,5);
l2.draw();


///rect
rect R(240,240,260,300,9);
rect R2(180,300,320,350,9);

R.draw();

///triangle
    triangle t(210,320,200,330,220,330,4);
    t.draw();
    ///shaps
    Shape* shArr[7] = {&c,&l1,&l2,&c2,&r,&r2,&t};

    Picture P;

    P.setShape(7,shArr);
    P.paint();
    return 0;
}
