#include "ComnProcess.h"
#include <vector>
#include <excpt.h>
#include <ctime>
#include "SerialPort.h"
#include "WiimotePtreeStructs.h"

ComnProcess::ComnProcess(const std::string& _com) : 
	serialPort(new SerialPort(_com)),
	wiimote(0) {
}

ComnProcess::~ComnProcess() {
	serialPort->close();
	delete serialPort;
	delete wiimote;
}

void ComnProcess::initialize() {
	std::vector<WiimoteInput*> foundDevices = WiimoteInput::connect(1);
	if (foundDevices.size() == (size_t)0) {
		std::exception("Failed to connect wiimote devices.");
	}
	wiimote = foundDevices.front();
	wiimote->turnOnMotionSensing();
	wiimote->turnOnLed(WiimoteLed::LED_OFF);
	serialPort->open();
	std::cout << "Serial Port open" << std::endl;
}

void ComnProcess::run() {
	while (true) {
		WiimoteEvent eventType = wiimote->getEvent();
		if (eventType != WiimoteEvent::GENERAL_EVENT) {
			continue;
		}

		WiimoteStatusPtreed status = wiimote->getStatus();
#if 0
		std::cout << status.orientation.pitch << ", "
			<< status.orientation.roll << ", "
			<< status.orientation.yaw << std::endl;
#endif
		std::stringstream ss;
		ss << status.b << "," << status.orientation.pitch << "," << status.orientation.roll;
		serialPort->write(ss.str());		
	}
}