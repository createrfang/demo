
#include "stdafx.h"
#include "ViewModelTest.h"

#include "../BusQuery/dev/common/common.h"
#include "../BusQuery/dev/common/CommandParameter.h"
#include "../BusQuery/dev/viewmodel/ViewModel.h"

void ViewModel_Test() throw()
{
	try {
		BusDataModel mdl;
		BusViewModel vmdl;
		vmdl.set_BusModelRef(RefPtr<BusDataModel>(&mdl));
		//case 1
		vmdl.set_StartStop(std::string("gggg"));
		if (!(vmdl.get_StartStop() == "gggg"))
			throw int(2);
		//case 2
		vmdl.set_StartStop(std::string("cccc"));
		if (!(vmdl.get_StartStop() != "gggg"))
			throw int(2);

	}
	catch (...) {
		printf("exception\n");
	}
}
