#include <iostream>
#include <graphics.h>
using namespace std;
class point {
    int x , y;
public:
    point(){
    x =0;
    y =0;
    }
    point (int _x , int _y ){
        x = _x;
        y = _y;
        cout << "Point Ctor01 \n";

    }
      ~point(){
     cout<< "Point Destructor \n";
     x=y=0;
     }

    void setx(int _x) {x = _x;}
    void sety(int _y ){y = _y;}
    int getx(){return x;}
    int gety (){return y;}
    void show ()
    {
        cout <<x<<endl;
        cout<<y<<endl;
    }

};
///line
class line {
     point start;
     point last;
     int color;
public:
       line (int x1, int y1 ,int x2 ,int y2 , int cl)
        :start(x1 ,y1) , last (x2 ,y2)
        {
            color =cl;
        }
            ~line(){
                 cout<< "line Destructor \n";
            }

        void draw ()
        {
            line (start.getx(), start.gety(),last.getx(),last.gety());
        }
};
///circle
class circle{
    point center;
    int radius;
public:

    circle(){
    radius = 0;
    }

    circle(int x1 ,int y1, int r ): center(x1, y1)
    {
        radius = r;
    }
        ~circle(){}

    void draw (){
    circle(center.getx(),center.gety(),radius);
    }

};

///rectaingle
class rect {
     point ul;
    point lr ;
    int color;
public:
    rect(){
    color = 0;}

    rect(int x1 ,int y1 ,int x2, int y2, int cl):ul(x1, y1),lr (x2 ,y2)
    {color =cl;}

    rect(point a1, point a2, int cl):ul(a1.getx(), a1.gety()), lr(a2.getx(), a2.gety()){
    color = cl;}

    ~rect(){
    }
   void draw (){
    Rectangle(ul.getx(),ul.gety(),lr.getx(),lr.gety());
    }
};
///triangle
class triangle{
point start;
point last ;
point tr;
int color;
public:
    triangle(int x1, int y1, int x2 , int y2,int x3 , int y3 , int cl): start(x1 ,y1), last (x2 ,y2),tr(x3 ,y3)
    {color = cl;}
    ~triangle(){}

void draw (){
    line (start.getx(), start.gety(),last.getx(), last.gety());
    line (last.getx(), last.gety(),tr.getx(), tr.gety());
    line (tr.getx(), tr.gety(),start.getx(), start.gety());

    }
};
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

    return 0;
}
