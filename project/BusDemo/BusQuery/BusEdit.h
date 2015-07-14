#pragma once

#include "dev/view/BusEditT.h"

// CBusEdit

class CBusEdit : public CEdit,
	             public BusEditT<CBusEdit>
{
	DECLARE_DYNAMIC(CBusEdit)

public:
	CBusEdit();
	virtual ~CBusEdit();

protected:
	DECLARE_MESSAGE_MAP()
};


