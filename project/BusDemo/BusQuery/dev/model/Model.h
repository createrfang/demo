#pragma once

#include <string>
#include <vector>

class Station
{
private:
	std::string m_name;
	double m_x;
	double m_y;
public:	
	void set_Name(const std::string& name)
	{
		this->name = name;
	}
	void set_x(double x) throw()
	{
		this->x = x;
	}
	void set_y(double y) throw()
	{
		this->y = y;
	}
	std::string get_Name() const throw()
	{
		return name;
	}
	double get_x() const throw() 
	{
		return x;
	}
	double get_y() const throw()
	{
		return y;
	}
	Station& operator=(const Staion& s)
	{
		if(this != &s)
		{
            name = s.name;
    		x = s.x;
    		y = s.y;     
        }
      
		return *this;
	} 
	Station& operator=(Staion&& s)
	{
		if(this != &s){
           name = static_cast<std::string&&>(s.name);
           x = s.x;
		   y = s.y;
        }
        

		return *this;
	}
};

class BusRoute
{
public:
	int Number;
	std::vector<Station> BusStop;
	
	void Add(const Station& s)
	{
		BusStop.push_back(s);
		++Number;
	}
	void Clear()
	{
		BusStop.clear();
		Number = 0;
	}
};

class RouteSet
{
public:
	int Number;
	std::vector<BusRoute> Busline;

	void Add(const BusRoute& b)
	{
		Busline.push_back(b);
		++Number;
	}
	void Clear()
	{
		BusLine.clear();
		Number = 0;
	}
};

class BusDataModel
{
public:
	RouteSet routeSet;
};
