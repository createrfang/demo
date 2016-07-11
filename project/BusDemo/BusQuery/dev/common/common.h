#pragma once

#include <assert.h>
#include <vector>
#include <string>
#include <map>
#include <memory>

template <typename T>
class RefPtr
{
public:
    explicit RefPtr(T* p = NULL) throw() : m_p(p)
    {
    }
    RefPtr(const RefPtr<T>& src) throw() : m_p(src.m_p)
    {
    }
    RefPtr(RefPtr&& src) throw()
    {
        m_p = src.m_p;
        src.m_p = NULL;
    }
    ~RefPtr() throw()
    {
    }

    void Release() throw()
    {
        m_p = NULL;
    }

    RefPtr<T>& operator=(const RefPtr<T>& src) throw()
    {
         if( this != &src ) {
              m_p = src.m_p;
         }
         return *this;
    }
    RefPtr<T>& operator=(RefPtr<T>&& src) throw()
    {
         if( this != &src ) {
              m_p = src.m_p;
              src.m_p = NULL;
         }
         return *this;
    }

    const T& Deref() const throw()
    {
        assert( m_p != NULL ); 
        return *m_p;
    }
    T& Deref() throw()
    {
        assert( m_p != NULL ); 
        return *m_p;
    }

private:
    T* m_p;
};

class RefPtrHelper
{
public:
    template <class T, class TBase>
    static RefPtr<TBase> TypeCast(const RefPtr<T>& t) throw()
    {
        return RefPtr<TBase>((TBase*)static_cast<const TBase*>(&(t.Deref())));
    }
};

template <class T>
class NotificationImpl
{
public:
	std::vector<RefPtr<T>>& GetNotificationArray() throw(){
		return m_array;
	}
	void AddNotification(const RefPtr<T>& p)
	{
		m_array.push_back(p);
	}

private:
	std::vector<RefPtr<T>> m_array; 
};

class INotification
{
public:
	virtual void OnPropertyChange(const std::string& str) = 0;
	virtual void OnCommandComplete(const std::string& str, bool bOK) = 0;
};

template <class T>
class Proxy_Notification : public NotificationImpl<INotification>
{
public:
	void Fire_OnPropertyChange(const std::string& str)
	{
        std::vector<RefPtr<INotification>>& vec = GetNotificationArray();
        auto iter(vec.begin());
        for( ; iter != vec.end(); ++ iter ) {
            (*iter).Deref().OnPropertyChange(str);
        }
    }
	void Fire_OnCommandComplete(const std::string& str, bool bOK)
	{
        std::vector<RefPtr<INotification>>& vec = GetNotificationArray();
        auto iter(vec.begin());
        for( ; iter != vec.end(); ++ iter ) {
            (*iter).Deref().OnCommandComplete(str, bOK);
        }
	}
};

class ICommandParameter
{
};

class ICommandEx
{
public:
    virtual void SetParameter(const RefPtr<ICommandParameter>& param) = 0;
	virtual void Exec() = 0;
/*
virtual std::shared_ptr<ICommandEx> get_Undo() = 0;
virtual std::shared_ptr<ICommandEx> get_Redo() = 0;
use make_shared, then the virtual destructor is not necessary. (RAII)
*/
};

class CommandManager
{
public:
/*

*/
private:
	std::vector<std::shared_ptr<ICommandEx>> m_vecUndo;
	std::vector<std::shared_ptr<ICommandEx>> m_vecRedo;
};

class IStateBase
{
public:
	virtual int Process(unsigned int uEvent) = 0;
};

class StateManager
{
public:
/*
viud Add(unsigned int uEvent, const std::shared_ptr<IStateBase>& spState)
{
...
}
void Process(unsigned int uEvent)
{
...
}
...
*/
private:
	int m_iCurrentState;
	std::map<unsigned int, std::shared_ptr<IStateBase>> m_map;
};
