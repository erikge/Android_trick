#ifndef __PRINTSAY_H_INCL__
#define __PRINTSAY_H_INCL__

#include "cpp_impl.h"

/**
 * TODO: Add class description
 * 
 * @author   erik
 */
class PrintSay {
public:
    // Method to fetch singleton instance.
    static PrintSay* getInstance();

    // Destructor
    virtual ~PrintSay();
    
    int psayCount();
    SayHandle psayCreate(SayType type);
    
    int psayHello(SayHandle handle);
    int psayName(SayHandle handle);
    
    int psayRegister(SayInner *impl);

protected:
    // Constructor - protected so users cannot call it.
    PrintSay();

private:
    
    SayInner *inner_say_[4];
    
    // private static member referencing the single instance of the object
    // TODO: Replace PrintSay with the type of object you want to
    // return the single instance of
    static PrintSay *_instance;

    // Copy constructor
    // Declared but not defined to prevent auto-generated
    // copy constructor.  Refer to "Effective C++" by Meyers
    PrintSay(const PrintSay &src);

    // Assignment operator
    // Declared but not defined to prevent auto-generated
    // assignment operator.  Refer to "Effective C++" by Meyers
    PrintSay& operator=(const PrintSay &src);

};

// Constructor implementation
inline PrintSay::PrintSay() {
    for (int i = 0; i < 4; ++i) {
        inner_say_[i] = (SayInner *)NULL;
    }
}

// Destructor implementation
inline PrintSay::~PrintSay() {
}

// TODO: Uncomment the copy constructor when you need it.
//inline PrintSay::PrintSay(const PrintSay& src)
//{
//   // TODO: copy
//}

// TODO: Uncomment the assignment operator when you need it.
//inline PrintSay& PrintSay::operator=(const PrintSay& rhs)
//{
//   if (this == &rhs) {
//      return *this;
//   }
//
//   // TODO: assignment
//
//   return *this;
//}


#endif // __PRINTSAY_H_INCL__
