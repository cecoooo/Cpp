#pragma once
#include "Instrument.h"

class Hammer : public Instrument
{
public:
	string instrumentType() override;
};