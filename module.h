#ifndef MODULE_H
#define MODULE_H


class Module
{
public:
    Module* left  = nullptr;
    Module* right = nullptr;

    virtual void forward(int character)  = 0;
    virtual void backward(int character) = 0;

    void setLeft (Module* module) { left  = module; }
    void setRight(Module* module) { right = module; }
};

#endif // MODULE_H

