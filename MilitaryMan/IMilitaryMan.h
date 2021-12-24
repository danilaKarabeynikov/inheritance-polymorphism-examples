#pragma once
#include "stdafx.h"
#include "Let11IMilitaryManApi.h"

LET11IMILITARYMAN_API extern int globalMilitaryCount;

class IMilitaryMan
{
public:
	LET11IMILITARYMAN_API void virtual Serve() = 0;
	LET11IMILITARYMAN_API virtual ~IMilitaryMan()=0;
};

class Soldier: public IMilitaryMan
{
public:
	LET11IMILITARYMAN_API Soldier() {_jobCount = 0; ++globalMilitaryCount;}
	LET11IMILITARYMAN_API void Serve() override {++_jobCount;}
	LET11IMILITARYMAN_API int getJobCount() const { return _jobCount; }
	LET11IMILITARYMAN_API ~Soldier() {--_jobCount; --globalMilitaryCount;}
private:
	int _jobCount;
};

class Officer : public IMilitaryMan
{
public:
	LET11IMILITARYMAN_API Officer(IMilitaryMan** slaves, int countSlaves);
	LET11IMILITARYMAN_API void Serve() override;
	LET11IMILITARYMAN_API ~Officer();
private:
	IMilitaryMan * * _slaves;
	int _countSlaves;
};
