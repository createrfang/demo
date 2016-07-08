
#pragma once

class StartState : public IStateBase
{
public:
	//IStateBase methods
	virtual int Process(unsigned int uEvent)
	{
		if( uEvent == EVT_LEFT_MOUSE ) {
			return 0;
		}
		return 0;
	}
};
