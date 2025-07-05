#include <iostream>

class Shape {
public:
    virtual void draw() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Rysuje kolo\n";
    }
};

class Square : public Shape {
public:
    void draw() const override {
        std::cout << "Rysuje kwadrat\n";
    }
};

void print(int x) {
    std::cout << "Liczba calkowita: " << x << std::endl;
}

void print(double x) {
    std::cout << "Liczba zmiennoprzecinkowa: " << x << std::endl;
}

template <typename T>
void show(T value) {
    std::cout << "Wartosc: " << value << std::endl;
}

int main() {
    Shape* shape1 = new Circle();
    Shape* shape2 = new Square();

    shape1->draw();
    shape2->draw();

    delete shape1;
    delete shape2;

    print(5);
    print(3.14);

    show(10);
    show(2.71);
    show("Hello");

    return 0;
}