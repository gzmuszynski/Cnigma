#ifndef MODULE_H
#define MODULE_H


class Module
{
public:
    Module* left  = nullptr;
    Module* right = nullptr;

    virtual int forward()  = 0;
    virtual int backward() = 0;

    virtual void setLeft (Module* module) = 0;
    virtual void setRight(Module* module) = 0;
};

#endif // MODULE_H
