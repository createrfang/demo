#pragma once

template <class T>
class QueryCommand :public ICommandEx
{
public:
    QueryCommand(T* p) throw():m_pviemod(p)
    {
    }
    
    
	RefPtr<ICommandEx> get_QueryCommandRef() throw()
    {
         return RefPtrHelper::TypeCast<QueryCommand<T>, ICommandEx>(RefPtr<QueryCommand<T>>(this));   
    }
	void SetStartStop(const std::string& ss)
	{
		m_StartStop = ss;
	}
	void SetEndStop(const std::string& es)
	{
        m_EndStop = es;
	}
	virtual void Exec()
	{
        m_pviemod->Query(m_StartStop, m_EndStop);
    }

private:
	T* m_pviemod;
	std::string m_StartStop;
	std::string m_EndStop;
};
