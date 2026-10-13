#include <iostream>
using namespace std;

class Rectangle {
private:
    double width;
    double length;

public:
    // Default constructor
    Rectangle() : width(1.0), length(1.0) {}

    // Parameterized constructor
    Rectangle(double w, double l) : width(0.0), length(0.0) {
        setWidth(w);
        setLength(l);
    }

    // Getters
    double getWidth() const { return width; }
    double getLength() const { return length; }

    // Setters (reject negative values)
    void setWidth(double w) {
        if (w >= 0) {
            width = w;
        } else {
            cout << "Invalid width. Width must be non-negative." << endl;
        }
    }

    void setLength(double l) {
        if (l >= 0) {
            length = l;
        } else {
            cout << "Invalid length. Length must be non-negative." << endl;
        }
    }

    // Calculations
    double calculateArea() const { return width * length; }
    double calculatePerimeter() const { return 2 * (width + length); }
};

void displayRectangle(const string& name, const Rectangle& r) {
    cout << name << ":" << endl;
    cout << "  Width     = " << r.getWidth() << endl;
    cout << "  Length    = " << r.getLength() << endl;
    cout << "  Area      = " << r.calculateArea() << endl;
    cout << "  Perimeter = " << r.calculatePerimeter() << endl;
    cout << endl;
}

int main() {
    // Example 1: default constructor, then set dimensions
    Rectangle rect1;
    cout << "--- Example 1: Default rectangle ---" << endl;
    displayRectangle("rect1 (default)", rect1);

    rect1.setWidth(5.0);
    rect1.setLength(8.0);
    cout << "After setting dimensions:" << endl;
    displayRectangle("rect1", rect1);

    // Example 2: parameterized constructor
    cout << "--- Example 2: Rectangle created with values ---" << endl;
    Rectangle rect2(3.5, 6.2);
    displayRectangle("rect2", rect2);

    // Example 3: modify an existing rectangle
    cout << "--- Example 3: Modifying rect2 ---" << endl;
    rect2.setWidth(10.0);
    rect2.setLength(4.0);
    cout << "New width: " << rect2.getWidth() << ", new length: " << rect2.getLength() << endl;
    displayRectangle("rect2 (updated)", rect2);

    // Example 4: invalid input handling
    cout << "--- Example 4: Invalid input ---" << endl;
    rect2.setWidth(-2.0);
    cout << "Width is still: " << rect2.getWidth() << endl;

    return 0;
}
