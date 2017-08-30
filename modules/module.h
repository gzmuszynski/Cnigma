#ifndef MODULE_H
#define MODULE_H


class Module
{
public:
    Module* nextModule = nullptr;

    Module();
    Module(Module* module) : nextModule(module){}

    ~Module()
    {
        if(nextModule != nullptr);
        {
            delete nextModule;
            nextModule = nullptr;
        }
    }

    virtual char  operator() (char value) = 0;
    virtual void operator++ (){ }
    virtual void operator = (char value);
};

#endif // MODULE_H

