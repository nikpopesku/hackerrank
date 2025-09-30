#include <iostream>
using namespace std;

class Rectangle
{
protected:
    int height = 0, width = 0;

public:
    void display() const
    {
        cout << height << " " << width << "\n";
    }
};

class RectangleArea : public Rectangle
{
public:
    void read_input()
    {
        cin >> height >> width;
    }

    void display() const
    {
        cout << height * width << "\n";
    }
};

int main()
{
    RectangleArea r_area;

    r_area.read_input();
    r_area.Rectangle::display();
    r_area.display();

    return 0;
}
