#include <iostream>
using namespace std;
class Point {
public:
  int x, y;
  Point() {}
  Point(int x, int y) {
    this->x = x;
    this->y = y;
  }
  friend ostream &operator<<(ostream &os, const Point &pt) {
    os << "(" << pt.x << ", " << pt.y << ")";
    return os;
  }
};
class Shape {
  // FEEL FREE TO CHANGE THE THIS CLASS
  // AS LONG AS YOU DON'T HAVE TO CHANGE THE
      // CONTENTS OF MAIN() AND
      // PRINT_SHAPES() FUNCTIONS
protected :
    Point _location;

public:
  Shape() {}
  Shape(const Point &location) : _location(location) {}
  ~Shape() {}
  virtual void draw() {
    cout << "location: " << _location << endl;
  }
  virtual void get_info_from_user() {
    cout << "Enter position: ";
    cin >> _location.x >> _location.y;

  }
};
// YOU NEED TO COMPLETE THIS CLASS
class Tri : public Shape{
protected:
  int _width, _height;

public:
    virtual void draw() {
    cout << "location: " << _location << endl;
    cout << "    Width and Height" << _width <<" "<< _height<< endl;
  }
  virtual void get_info_from_user() {
    cout << "Enter position: ";
    cin >> _location.x >> _location.y;
    cout << "Enter Width and Height";
    cin >> _width  >> _height;
  }
};

// YOU NEED TO COMPLETE THIS CLASS
class Cir : public Shape{
protected:
  int _radius;

public:
    virtual void draw() {
    cout << "location: " << _location << endl;
    cout  << "    Radius: " << _radius << endl;
  }
  virtual void get_info_from_user() {
    cout << "Enter position: ";\
    cin >> _location.x >> _location.y;
    cout << "Enter Radius";
    cin >> _radius;
  }

};

/////////////////////////////////////////////////
//
// DO NOT CHANGE CODE BELOW THIS LINE
//
/////////////////////////////////////////////////
#define MAX_SHAPES 10
void print_shapes(Shape **shapes, int n) {
  for (int i = 0; i < n; ++i) {
    cout << "[" << i << "] ";
    shapes[i]->draw();
  }
}
int main() {
  Shape *shapes[MAX_SHAPES];
  int n = 0;
  char shape_choice;
  do {
    cout << "Choose a shape to add" << endl;
    cout << "\t(a) for triangle" << endl;
    cout << "\t(b) for circle" << endl;
    cout << "\t(p) to print the shapes" << endl;
    cout << "\t(0-9) to modify a shape"<< endl;
    cout << "\t(q) to exit" << endl;
    cout << ": ";
    cin >> shape_choice;
    if (shape_choice =='q' )break;
    switch (shape_choice) {
    case'0' :
    case'1' :
    case'2':
    case'3' :
    case'4' :
    case'5' :
    case'6' :
    case'7' :
    case'8' :
    case'9' :
        shapes[((int)shape_choice) - 48]->get_info_from_user();
        break;
    case'a' :
        if (n >= MAX_SHAPES){
            cout << "== Cannot add any more shapes ==" << endl;
            continue;
        }
        cout<< "== You selected a triangle. ==" << endl;
        shapes[n] = new Tri();
        shapes[n]->get_info_from_user();
        ++n;
        break;
    case'b' :
        if (n >= MAX_SHAPES){
            cout << "== Cannot add any more shapes ==" << endl;
            continue;
        }
        cout<< "== You selected a circle. ==" << endl;
        shapes[n] = new Cir();
        shapes[n]->get_info_from_user();
        ++n;
        break;
    case'p' :
        print_shapes(shapes, n);
        break;
    case 'q' :
        break;
    default:
        cerr << "== Invalid choice ==" << endl;
        break;
    }
    }while (true);
for (int i = 0; i < n; ++i)
        delete shapes[i];
}
