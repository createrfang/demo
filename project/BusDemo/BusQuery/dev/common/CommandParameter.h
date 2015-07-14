#pragma once

class TwoStringParameter : public ICommandParameter
{
public:
    void set_S1(const std::string& str)
    {
         m_s1 = str;
    }
    const std::string& get_S1() const throw()
    {
         return m_s1;
    }
    void set_S2(const std::string& str)
    {
         m_s2 = str;
    }
    const std::string& get_S2() const throw()
    {
         return m_s2;
    }

private:
	std::string m_s1;
	std::string m_s2;
};
