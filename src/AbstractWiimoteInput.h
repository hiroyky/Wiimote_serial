#pragma once
#include "WiimoteStructs.h"

class AbstractWiimoteInput {
public:
	virtual bool isConnected() = 0;
	virtual void turnOnVibration() = 0;
	virtual void turnOffVibration() = 0;
	virtual void turnOnMotionSensing() = 0;
	virtual void turnOffMotionSensing() = 0;
	virtual void turnOnLed(WiimoteLed led) = 0;
	virtual WiimoteEvent getEvent() = 0;
	virtual WiimoteStatus getStatus() = 0;
};

