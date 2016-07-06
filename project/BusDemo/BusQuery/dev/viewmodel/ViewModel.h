#pragma once
#include<vector>
#include"command/QueryCommand.h"

#include "../model/model.h"

class BusViewModel:public Proxy_Notification<BusViewModel>,
                   public QueryCommand<BusViewModel>
{
public:
    BusViewModel() throw() :QueryCommand<BusViewModel>(this)
    {
    }
	void set_StartStop(const std::string& ss)
	{
		m_StartStop = ss;
	}
	const std::string& get_StartStop()const throw()
	{
		return m_StartStop;
	}
	RefPtr<std::string> get_StartStopRef() throw()
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
	RefPtr<std::string> get_EndStopRef() throw()
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

    
    bool Query(const std::string& ss, const std::string& es)
    {
         bool queryResult = m_BusModel.Deref().Query(ss, es);
         m_StartStop = ss + "!";
         m_EndStop = es + "!";
         Fire_OnPropertyChange(std::string("StartStop"));
         Fire_OnPropertyChange(std::string("EndStop"));
         return queryResult;
    }

private:
	std::string m_StartStop;
	std::string m_EndStop;
	std::vector<double> m_xArray;
	std::vector<double> m_yArray;
	
   RefPtr<BusDataModel> m_BusModel;
	
};

