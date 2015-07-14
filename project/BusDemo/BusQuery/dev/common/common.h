#pragma once

#include <vector>
#include <string>

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
        return RefPtr<TBase>(static_cast<TBase*>(&(t.Deref())));
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
};

template <class T, class TInterface>
class Proxy_Notification : public NotificationImpl<TInterface>
{
public:
	void Fire_OnPropertyChange(const std::string& str)
	{
        std::vector<RefPtr<TInterface>>& vec = GetNotificationArray();
        auto iter(vec.begin());
        for( ; iter != vec.end(); ++ iter ) {
            (*iter).Deref().OnPropertyChange(str);
        }
    }
};

class ICommandEx
{
public:
	virtual void Exec() = 0;
};
