#pragma once

template <typename T, T beginValue, T endValue>
class EnumIterator {

    typedef typename std::underlying_type<T>::type value;
    int valueAsInt;

public:
    // Constructor that initializes iterator with an enum value
    EnumIterator(const T& f) : valueAsInt(static_cast<value>(f)) {}

    // Default constructor, initializing iterator to beginValue
    EnumIterator() : valueAsInt(static_cast<value>(beginValue)) {}

    // Pre-increment operator
    EnumIterator operator++() {
        ++valueAsInt;
        return *this;
    }

    // Dereference operator
    T operator*() const { return static_cast<T>(valueAsInt); }

    // Begin method, returns the iterator at beginValue
    EnumIterator begin() const { return *this; }

    // End method, creates and returns a new iterator at endValue
    EnumIterator end() const {
        return EnumIterator(endValue);  // Return a new instance, not static
    }

    // Comparison operator
    bool operator!=(const EnumIterator& i) const {
        return valueAsInt != i.valueAsInt;
    }
};