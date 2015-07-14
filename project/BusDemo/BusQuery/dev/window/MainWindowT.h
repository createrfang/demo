#pragma once

#include "sink/MainWindowSink.h"
#include "../common/CommandParameter.h"

template <class T, class TEdit>
class MainWindowT : public MainWindowSink<T>
{
public:
    TEdit m_editStart;
    TEdit m_editEnd;

    RefPtr<ICommandEx> m_cmdQuery;

public:
    void InitUI() throw()
    {
         T* pT = static_cast<T*>(this);
        m_editStart.SubclassWindow(pT->GetDlgItem(IDC_EDIT_START)->GetSafeHwnd());
	    m_editEnd.SubclassWindow(pT->GetDlgItem(IDC_EDIT_END)->GetSafeHwnd());
    }
    void set_QueryCommand(const RefPtr<ICommandEx>& cmd) throw()
    {
         m_cmdQuery = cmd;
    }
    void CallQueryCommand(const std::string& str1, const std::string& str2)
    {
         TwoStringParameter param;
         param.set_S1(str1);
         param.set_S2(str2);
         m_cmdQuery.Deref().SetParameter(RefPtrHelper::TypeCast<TwoStringParameter, ICommandParameter>(RefPtr<TwoStringParameter>(&param)));
         m_cmdQuery.Deref().Exec();
    }
};
