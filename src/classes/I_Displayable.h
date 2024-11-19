#pragma once

#include <iostream>

using std::ostream;

// Interface class for 'displayable' classes - mainly for output testing
class I_Displayable {
public:
    // Non-member function to enable displaying through the '<<' operator
    friend ostream& operator<<(ostream& os, const I_Displayable& obj);
protected:
    // Pure virtual function to be overriden to implement specific display logic
    virtual void display(ostream& os) const = 0;
};