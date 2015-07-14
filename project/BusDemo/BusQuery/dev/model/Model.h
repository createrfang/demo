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
    Station() throw() : m_x(0.0), m_y(0.0)
    {
    }
	Station(const Station& s){
		m_name = s.m_name;
		m_x = s.m_x;
		m_y = s.m_y;
	}
	Station(Station&& s){
		m_name = static_cast<std::string&&>(s.m_name);
		m_x = s.m_x;
		m_y = s.m_y;
	}

	void set_Name(const std::string& name)
	{
		this->m_name = name;
	}
	void set_x(double x) throw()
	{
		this->m_x = x;
	}
	void set_y(double y) throw()
	{
		this->m_y = y;
	}
	const std::string& get_Name() const throw()
	{
		return m_name;
	}
	double get_x() const throw()
	{
		return m_x;
	}
	double get_y() const throw()
	{
		return m_y;
	}
	Station& operator=(const Station& s)
	{
		if(this != &s){
			m_name = s.m_name;
			m_x = s.m_x;
			m_y = s.m_y;
		}

		return *this;
	} 
	Station& operator=(Station&& s)
	{
		if(this != &s){
			m_name = static_cast<std::string&&>(s.m_name);
			m_x = s.m_x;
			m_y = s.m_y;
		}

		return *this;
	} 
};

class BusRoute
{
private:
	int m_Number;
	std::vector<Station> m_BusStop;

public:
	BusRoute() throw() : m_Number(0) 
    {
    }
    BusRoute(BusRoute&& b){
		m_Number = b.m_Number;
		m_BusStop = static_cast<std::vector<Station>&&>(b.m_BusStop);
	}
	BusRoute(const BusRoute& b){
		m_Number = b.m_Number;
		m_BusStop = b.m_BusStop;
	}
    
    void Add(const Station& s)
	{
		m_BusStop.push_back(s);
		++m_Number;
	}
	void Clear() throw()
	{
		m_BusStop.clear();
		m_Number = 0;
	}
	
	BusRoute& operator= (BusRoute&& b)
	{
		if(this != &b){
			m_Number = b.m_Number;
			m_BusStop = static_cast<std::vector<Station>&&>(b.m_BusStop);
		}
		
		return *this;
	} 
	BusRoute& operator= (const BusRoute& b)
	{
		if(this != &b){
			m_Number = b.m_Number;
			m_BusStop = b.m_BusStop;
		}
		
		return *this;
	} 
	std::vector<Station>& get_BusRoute() throw()
    {
        return this->m_BusStop;
    }
};

class RouteSet
{
private:
	int m_Number;
	std::vector<BusRoute> m_BusLine;
public:
    RouteSet() throw() : m_Number(0)
    {
    }
	RouteSet(RouteSet&& r){
		m_Number = r.m_Number;
		m_BusLine = static_cast<std::vector<BusRoute>&&>(r.m_BusLine);
	}
	RouteSet(const RouteSet& r){
		m_Number = r.m_Number;
		m_BusLine = r.m_BusLine;
	}
    void Add(const BusRoute& b)
	{
		m_BusLine.push_back(b);
		++m_Number;
	}
	void Clear() throw()
	{
		m_BusLine.clear();
		m_Number = 0;
	}
	
	RouteSet& operator= (RouteSet&& r)
	{
		if(this != &r){
			m_Number = r.m_Number;
			m_BusLine = static_cast<std::vector<BusRoute>&&>(r.m_BusLine);
		}
		
		return *this;
	} 
	RouteSet& operator= (const RouteSet& r)
	{
		if(this != &r){
			m_Number = r.m_Number;
			m_BusLine = r.m_BusLine;
		}
		
		return *this;
	} 
	std::vector<BusRoute>& get_BusLine()
	{
        return this->m_BusLine;
    }
};

class BusDataModel
{
public:
    bool Query(const std::string& ss, const std::string& es) const throw()
    {
         return true;     
    }         
private:
	RouteSet m_RouteSet;
};
