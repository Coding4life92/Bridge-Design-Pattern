#include <iostream>
using namespace std;

// Implementor
class GuitarShop
{
public:  
    virtual void build() = 0;
};

// Abstraction
class Guitar 
{
public:  
    Guitar(GuitarShop* guitarshop1, GuitarShop* guitarshop2)
        : _guitarshop1(guitarshop1),
        _guitarshop2(guitarshop2) {}

    virtual void manufacture() = 0;
protected: 
    GuitarShop* _guitarshop1;
    GuitarShop* _guitarshop2;
};

// Concrete implementation1
class Produce : public GuitarShop
{
public:  
    virtual void build()
    {
        cout << "Produced" << endl;
    }
};

// Concrete implementation2
class Assmble : public GuitarShop
{
public:  
    virtual void build()
    {
        cout << "Assembled" << endl;
    }
};

// Refine Abstraction1
class Electric : public Guitar
{
public:  
    Electric(GuitarShop* guiarshop1, GuitarShop* guitarshop2)
        : Guitar(guiarshop1, guitarshop2) {}

    virtual void manufacture()
    {
        cout << "Eeletric ";
        _guitarshop1->build();
        _guitarshop2->build();
    }
};

// Refine Abstraction 2
class Acoustic : public Guitar
{
public:  
    Acoustic(GuitarShop* guitarshop1, GuitarShop* guitarshop2)
        : Guitar(guitarshop1, guitarshop2) {}

    virtual void manufacture()
    {
        cout << "Acoustic ";
        _guitarshop1->build();
        _guitarshop2->build();
    }
};

int main()
{
    Guitar* guitar1 = new Electric(new Produce(), new Assmble());
    guitar1->manufacture();

    Guitar* guitar2 = new Acoustic(new Produce(), new Assmble());
    guitar2->manufacture();

    return 0;
}
