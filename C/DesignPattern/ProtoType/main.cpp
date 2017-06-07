#include <iostream>

using namespace std;

class Prototype
{
public :
    Prototype(){}
    virtual ~Prototype(){}

    virtual Prototype * Clone() = 0;
};

class ConcretePrototype : public Prototype
{
public :
    ConcretePrototype():m_counter(0){}
    virtual ~ConcretePrototype(){}

    ConcretePrototype( const ConcretePrototype & rhs)
    {
        m_counter = rhs .m_counter;
    }

    virtual ConcretePrototype * Clone()
    {
        return new ConcretePrototype (*this );
    }

    virtual void Set(int number)
    {
        m_counter = number;
    }

    virtual void Show(void)
    {
        cout<<"Counter: "<<m_counter<<endl;
    }

private :
    int m_counter;
};

int main(void)
{
    ConcretePrototype * conProA = new ConcretePrototype ();

    conProA->Set(99);

    ConcretePrototype * conProB = conProA->Clone();

    conProA->Show();
    conProB->Show();

    delete conProA;
    conProA= NULL ;

    delete conProB;
    conProB= NULL ;

    return 0;
}
