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

    virtual int operator()(int value) = 0;
};

#endif // MODULE_H

