#include "I_Displayable.h"

#include <iostream>

using std::ostream;

// Overloading '<<' operator to use the display() method
ostream& operator<<(ostream& os, const I_Displayable& obj) {
    obj.display(os);    // Use the derived classes display overriden method
    return os;
}