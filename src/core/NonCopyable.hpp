//
// Created by till on 3/21/13.
//
// To change the template use AppCode | Preferences | File Templates.
//



#ifndef OW_NON_COPYABLE
#define OW_NON_COPYABLE

#include <iostream>

class NonCopyable
{
public:
    NonCopyable() = default;

private:
    NonCopyable(const NonCopyable&) = delete;
    NonCopyable& operator=(const NonCopyable&) = delete;
};


#endif // OW_NON_COPYABLE
