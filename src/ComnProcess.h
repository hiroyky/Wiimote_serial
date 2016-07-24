#pragma once

#include <iostream>
#include "SerialPort.h"
#include "WiimoteInput.h"

class ComnProcess {
public:
	ComnProcess(const std::string& _com);
	virtual ~ComnProcess();
	virtual void initialize();
	virtual void run();

private:	
	SerialPort* serialPort;
	WiimoteInput* wiimote;
};