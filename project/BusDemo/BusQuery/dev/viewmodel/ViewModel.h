#pragma once
#include<vector>
#include"comand/QueryCommand.h"

class BusViewModel:public Proxy_Notification<BusViewModel, INotification>
{
public:
	void set_StartStop(const std::string& ss)
	{
		m_StartStop = ss;
	}
	const std::string& get_StartStop()const throw()
	{
		return m_StartStop;
	}
	RefPtr<std::string> get_StartStopRef()const throw()
	{
		return RefPtr<std::string>(&m_StartStop);
	}

	void set_EndStop(const std::string& es)
	{
		m_EndStop = es;
	}
    const std::string& get_EndStop()const throw()
	{
		return m_EndStop;
	}
	RefPtr<std::string> get_EndStopRef()const throw()
	{
		return RefPtr<std::string>(&m_EndStop);
	}

	void set_BusModelRef(const RefPtr<BusDataModel>& busdat) throw()
	{
		m_BusModel = busdat;
	}
	BusDataModel& get_BusModel() throw()
	{
		return m_BusModel.Deref();
	}

	/*get xArray, get yArray*/

    
    void Query(std::string& ss, std::string& es)
    {
         
    }

private:
	std::string m_StartStop;
	std::string m_EndStop;
	std::vector<double> m_xArray;
	std::vector<double> m_yArray;
	
   RefPtr<BusDataModel> m_BusModel;
	
};

