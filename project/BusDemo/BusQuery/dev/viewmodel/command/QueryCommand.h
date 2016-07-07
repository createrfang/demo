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
    virtual void SetParameter(const RefPtr<ICommandParameter>& param)
    {
       m_param = param;
    }
	virtual void Exec()
	{
        RefPtr<TwoStringParameter> p = RefPtrHelper::TypeCast<ICommandParameter, TwoStringParameter>(m_param);
        bool bResult = m_pviemod->Query(p.Deref().get_S1(), p.Deref().get_S2());
        m_pviemod->Fire_OnCommandComplete(std::string("Query"), bResult);
	}

private:
	T* m_pviemod;
	RefPtr<ICommandParameter> m_param;
};
