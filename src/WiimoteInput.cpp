#include "WiimoteInput.h"
#include <stdexcept>
#include <wiiuse\wiiuse.h>

std::vector<WiimoteInput*> WiimoteInput::connect(int maxNumOfWiimotes, int delay) {
	wiimote** wiimotes = wiiuse_init(maxNumOfWiimotes);
	int found = wiiuse_find(wiimotes, maxNumOfWiimotes, delay);
	if (found == 0) {
		return std::vector<WiimoteInput*>();
	}

	std::vector<WiimoteInput*> wiimoteInputs;
	int connected = wiiuse_connect(wiimotes, maxNumOfWiimotes);
	for (int i = 0; i < connected; ++i) {
		wiimoteInputs.push_back(new WiimoteInput(wiimotes[i]));
	}
	return wiimoteInputs;
}

WiimoteInput::WiimoteInput(wiimote_t* _device) : device(_device) {
}

WiimoteInput::~WiimoteInput() {
	wiiuse_disconnect(device);
	delete device;
}

bool WiimoteInput::isConnected() {
	return device > 0 && WIIMOTE_IS_CONNECTED(device);
}

void WiimoteInput::turnOnVibration() {
	wiiuse_rumble(device, 1);
}

void WiimoteInput::turnOffVibration() {
	wiiuse_rumble(device, 0);
}

void WiimoteInput::turnOnMotionSensing() {
	wiiuse_motion_sensing(device, 1);
}

void WiimoteInput::turnOffMotionSensing() {
	wiiuse_motion_sensing(device, 0);
}

void WiimoteInput::turnOnLed(WiimoteLed led) {
	int ledId = ledToWiiUseLed(led);
	wiiuse_set_leds(device, ledId);
}

bool WiimoteInput::isAccelermeterEnabled() {
	return WIIUSE_USING_ACC(device);
}

WiimoteEvent WiimoteInput::getEvent() {
	if (wiiuse_poll(&device, 1) == 0) {		
		return WiimoteEvent::NONE;
	}	
	return toWiimoteEvent(device->event);
}

WiimoteStatus WiimoteInput::getStatus() {
	WiimoteStatus status;
	status.a = getButtonStatus(WIIMOTE_BUTTON_A);
	status.b = getButtonStatus(WIIMOTE_BUTTON_B);
	status.plus = getButtonStatus(WIIMOTE_BUTTON_PLUS);
	status.minus = getButtonStatus(WIIMOTE_BUTTON_MINUS);
	status.one = getButtonStatus(WIIMOTE_BUTTON_ONE);
	status.two = getButtonStatus(WIIMOTE_BUTTON_TWO);
	status.home = getButtonStatus(WIIMOTE_BUTTON_HOME);
	status.up = getButtonStatus(WIIMOTE_BUTTON_UP);
	status.down = getButtonStatus(WIIMOTE_BUTTON_DOWN);
	status.right = getButtonStatus(WIIMOTE_BUTTON_RIGHT);
	status.left = getButtonStatus(WIIMOTE_BUTTON_LEFT);
	if (isAccelermeterEnabled()) {
		Orientation orient;
		orient.pitch = device->orient.pitch;
		orient.roll = device->orient.roll;
		orient.yaw = device->orient.yaw;
		orient.absolutePitch = device->orient.a_pitch;
		orient.absoluteRoll = device->orient.a_roll;
		status.orientation = orient;
	}	
	return status;
}

int WiimoteInput::ledToWiiUseLed(WiimoteLed led) const {
	switch (led) {
	case LED_OFF:
		return 0;
	case LED_1:
		return WIIMOTE_LED_1;
	case LED_2:
		return WIIMOTE_LED_2;
	case LED_3:
		return WIIMOTE_LED_3;
	case LED_4:
		return WIIMOTE_LED_4;
	}
}

WiimoteEvent WiimoteInput::toWiimoteEvent(int e) const {
	return (WiimoteEvent)e;
}

Button WiimoteInput::getButtonStatus(int button) const {
	if (IS_JUST_PRESSED(device, button)) {
		return Button::JUST_PRESSED;
	}
	if (IS_PRESSED(device, button)) {
		return Button::PRESSED;
	}
	return Button::RELEASED;
}