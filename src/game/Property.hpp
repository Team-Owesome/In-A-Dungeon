//
// Created by till on 2/26/13.
//
// To change the template use AppCode | Preferences | File Templates.
//



#ifndef PROPERTY_H
#define PROPERTY_H

#include <iostream>

namespace ow
{
    template <typename T>
    class Property
    {
    private:
        T m_value;

    public:
        T& getValue()
        {
            return m_value;
        }

        void setValue(T value)
        {
            m_value = value;
        }

        static std::shared_ptr<Property<T>> create()
        {
            return std::shared_ptr<Property<T>>::make_shared();
        }

        typedef std::shared_ptr<Property<T>> ptr;
    };
}

#endif // PROPERTY_H
