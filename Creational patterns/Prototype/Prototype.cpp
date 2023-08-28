#include <iostream>
#include <unordered_map>

using namespace std;

enum Type 
{
    PROTOTYPE_1 = 0,
    PROTOTYPE_2
};


class Prototype 
{
protected:
    string _prototype_name;
    float _prototype_field;

public:
    Prototype() {}
    Prototype(string prototype_name)
        : _prototype_name(prototype_name) {}
    virtual ~Prototype() {}

    virtual Prototype* Clone() const = 0;
    virtual void Method(float prototype_field)
    {
        this->_prototype_field = prototype_field;
        std::cout << "Call Method from " << _prototype_name << " with field : " << prototype_field << std::endl;
    }
};

class ConcretePrototype1 : public Prototype 
{
private:
    float _concrete_prototype_field1;

public:
    ConcretePrototype1(string prototype_name, float concrete_prototype_field)
        : Prototype(prototype_name), _concrete_prototype_field1(concrete_prototype_field) {}

    Prototype* Clone() const override 
    {
        return new ConcretePrototype1(*this);
    }
};

class ConcretePrototype2 : public Prototype 
{
private:
    float _concrete_prototype_field2;

public:
    ConcretePrototype2(string prototype_name, float concrete_prototype_field)
        : Prototype(prototype_name), _concrete_prototype_field2(concrete_prototype_field) {}

    Prototype* Clone() const override 
    {
        return new ConcretePrototype2(*this);
    }
};


class PrototypeFactory 
{
private:
    std::unordered_map<Type, Prototype*, std::hash<int>> _prototypes;

public:
    PrototypeFactory() 
    {
        _prototypes[Type::PROTOTYPE_1] = new ConcretePrototype1("PROTOTYPE_1 ", 50.f);
        _prototypes[Type::PROTOTYPE_2] = new ConcretePrototype2("PROTOTYPE_2 ", 60.f);
    }

    ~PrototypeFactory() 
    {
        delete _prototypes[Type::PROTOTYPE_1];
        delete _prototypes[Type::PROTOTYPE_2];
    }

    Prototype* CreatePrototype(Type type) 
    {
        return _prototypes[type]->Clone();
    }
};

void Client(PrototypeFactory& prototype_factory) 
{
    std::cout << "Let's create a Prototype 1\n";

    Prototype* prototype = prototype_factory.CreatePrototype(Type::PROTOTYPE_1);
    prototype->Method(90);
    delete prototype;

    std::cout << "\n";

    std::cout << "Let's create a Prototype 2 \n";

    prototype = prototype_factory.CreatePrototype(Type::PROTOTYPE_2);
    prototype->Method(10);

    delete prototype;
}


int main() 
{
    PrototypeFactory* prototype_factory = new PrototypeFactory();
    Client(*prototype_factory);
    delete prototype_factory;

    return 0;
}