#pragma once

#include "../common/common.h"

template <class T>
class BusEditT
{
public:
    const std::string& get_Name() const throw()
    {
        return m_name.Deref();
    }
    void set_NameRef(const RefPtr<std::string>& str)
    {
        m_name = str;
    }

private:
    RefPtr<std::string> m_name;
};
