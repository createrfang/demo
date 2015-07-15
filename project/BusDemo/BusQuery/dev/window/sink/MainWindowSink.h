#pragma once

#include "../../common/common.h"

template <class T>
class MainWindowSink : public INotification
{
public:
    RefPtr<INotification> get_Notification() throw()
    {
        return RefPtr<INotification>(static_cast<INotification*>(this));
    }

	virtual void OnPropertyChange(const std::string& str)
	{
        T* pT = static_cast<T*>(this);
        if( str == "StartStop" ) {
            CString str(pT->m_editStart.get_Name().c_str());
            pT->m_editStart.SetWindowText(str);
        }
        else if( str == "EndStop" ) {
            CString str(pT->m_editEnd.get_Name().c_str());
            pT->m_editEnd.SetWindowText(str);
        }
    }
 	virtual void OnCommandComplete(const std::string& str, bool bOK)
 	{
 		if( str == "Query") {
	 		if( !bOK )
				AfxMessageBox(_T("error"));
 		}
 	}
 };
