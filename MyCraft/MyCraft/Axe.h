#pragma once
#include "Instrument.h"

class Axe : public Instrument
{
public:
	string instrumentType() override;
};