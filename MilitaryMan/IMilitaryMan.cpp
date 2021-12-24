#include "stdafx.h"
#include "IMilitaryMan.h"
#include "Let11IMilitaryManApi.h"

int globalMilitaryCount = 0;

Officer::Officer(IMilitaryMan** slaves, int countSlaves)
{
	_slaves = slaves;
	for (int i = 0; i < countSlaves; ++i)
	{
		_slaves[i] = slaves[i];
	}
	_countSlaves = countSlaves;
	++globalMilitaryCount;
}

Officer::~Officer()
{
	for (int i = 0; i < _countSlaves; ++i)
	{
		delete _slaves[i];
	}
	--globalMilitaryCount;
}

void Officer::Serve()
{
	for (int i = 0; i < _countSlaves; ++i)
	{
		_slaves[i]->Serve();
	}
}

IMilitaryMan::~IMilitaryMan()
{}
