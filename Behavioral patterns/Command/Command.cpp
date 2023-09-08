#include <iostream>


class Command {
public:
    virtual ~Command() { }
    virtual void Execute() const = 0;
};


class SimpleCommand : public Command 
{
private:
    std::string _pay_load;

public:
    explicit SimpleCommand(std::string pay_load) : _pay_load(pay_load) { }

    void Execute() const override 
    {
        std::cout << "SimpleCommand: See, I can do simple things like printing (" << this->_pay_load << ")\n";
    }
};


class Receiver 
{
public:
    void DoSomething(const std::string& a) 
    {
        std::cout << "Receiver: Working on (" << a << ".)\n";
    }
    void DoSomethingElse(const std::string& b) 
    {
        std::cout << "Receiver: Also working on (" << b << ".)\n";
    }
};


class ComplexCommand : public Command 
{
private:
    Receiver* _receiver;
    
    std::string _a;
    std::string _b;
    
public:
    ComplexCommand(Receiver* receiver, std::string a, std::string b) : _receiver(receiver), _a(a), _b(b) 
    { }
    
    void Execute() const override 
    {
        std::cout << "ComplexCommand: Complex stuff should be done by a receiver object.\n";
        this->_receiver->DoSomething(this->_a);
        this->_receiver->DoSomethingElse(this->_b);
    }
};


class Invoker 
{
private:
    Command* _on_start;
    Command* _on_finish;
    
public:
    ~Invoker() 
    {
        delete _on_start;
        delete _on_finish;
    }

    void SetOnStart(Command* command) 
    {
        this->_on_start = command;
    }
    void SetOnFinish(Command* command) 
    {
        this->_on_finish = command;
    }

    void DoSomethingImportant() 
    {
        std::cout << "Invoker: Does anybody want something done before I begin?\n";
        if (this->_on_start) 
        {
            this->_on_start->Execute();
        }

        std::cout << "Invoker: ...doing something really important...\n";

        std::cout << "Invoker: Does anybody want something done after I finish?\n";
        if (this->_on_finish) 
        {
            this->_on_finish->Execute();
        }
    }
};


int main() 
{
    Invoker* invoker = new Invoker;
    invoker->SetOnStart(new SimpleCommand("Say Hi!"));
    Receiver* receiver = new Receiver;
    invoker->SetOnFinish(new ComplexCommand(receiver, "Send email", "Save report"));
    invoker->DoSomethingImportant();

    delete invoker;
    delete receiver;

    return 0;
}