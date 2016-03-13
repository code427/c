//virtual tables
#include <stdio.h>

// class definitions 
typedef struct Base
{
    void (**vtable)();
    int _x;
} Base;
typedef struct Child
{
    void (**vtable)();
/* begin base class slice */
    int _x;
/* end base class slice */
    int _y;
} Child;
/* class method implementations */
void Base_ToString(Base const* obj) { printf("Base: (%d)\n", obj->_x); }
void Child_ToString(Child const* obj) { printf("Base: (%d,%d)\n", obj->_x, obj->_y); }
/* vtable implementation */
enum { Call_ToString };
void (*Base_Vtable[])() = { &Base_ToString };
void (*Child_Vtable[])() = { &Child_ToString };
/* virtual method implementation */
void ToString(Base const* obj)
{
    obj->vtable[Call_ToString](obj);
}
int main()
{
    /* pick the vtable for objects at compile time */
    Base base = {Base_Vtable, 123};
    Child child = {Child_Vtable, 456, 789};
    Base* a = &base;
    Base* b = (Base*)&child;
    /* call the virtual methods */
    ToString(a);
    ToString(b);
}
