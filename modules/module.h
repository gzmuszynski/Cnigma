#ifndef MODULE_H
#define MODULE_H


class Module
{
public:
    Module* nextModule = nullptr;

    Module() { }
    Module(Module* module) : nextModule(module){ }

    ~Module()
    {
        nextModule == nullptr;
    }

    virtual char  operator() (char) = 0;
    virtual void operator++ (int){ }
    virtual void operator = (char) { }
};

#endif // MODULE_H

