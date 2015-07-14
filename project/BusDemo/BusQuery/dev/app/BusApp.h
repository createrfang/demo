#pragma once

#include "../viewmodel/viewmodel.h"

template <class TMainWnd>
class BusApp
{
public:
     BusApp(TMainWnd* p) throw() : m_p(p)
     {
     }
     void Initialize()
     {
      	// load
      	m_vmdl.set_BusModelRef(RefPtr<BusDataModel>(&m_mdl));
      	// bind
      	m_p->m_editStart.set_NameRef(m_vmdl.get_StartStopRef());
      	m_p->m_editEnd.set_NameRef(m_vmdl.get_EndStopRef());
      	// notification
      	m_vmdl.AddNotification(m_p->get_Notification());
      	// command
        m_p->set_QueryCommand(m_vmdl.get_QueryCommandRef());
     }

private:
    TMainWnd* m_p;
   	BusDataModel m_mdl;
   	BusViewModel m_vmdl;
};
 
