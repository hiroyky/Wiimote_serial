#pragma once

enum WiimoteLed {
	LED_OFF, LED_1, LED_2, LED_3, LED_4
};

enum WiimoteEvent {
	NONE,
	GENERAL_EVENT,
	STATUS_EVENT,
	CONNECT_EVENT,
	DISCONNECT_EVENT,
	UNEXPECTED_DISCONNECT_EVENT,
	READ_DATA_EVENT,
	WRITE_DATA_EVENT,
	NUNCHUK_INSERTED_EVENT,
	NUNCHUK_REMOVED_EVENT,
	CLASSIC_CTRL_INSERTED_EVENT,
	CLASSIC_CTRL_REMOVE_EVENT,
	GUITAR_HERO_3_CTRL_INSERTED_EVENT,
	GUITAR_HERO_3_CTRL_REMOVED_EVENT,
	WII_BOARD_CTRL_INSERTED_EVENT,
	WII_BOARD_CTRL_REMOVED_EVENT,
	MOTION_PLUS_ACTIVATED_EVENT,
	MOTION_PLUS_REMOVED_EVENT,
};

enum Button {
	RELEASED, PRESSED, JUST_PRESSED
};

struct Orientation {
	float roll;
	float pitch;
	float yaw;
	float absoluteRoll;
	float absolutePitch;

	Orientation() :
		roll(0),
		pitch(0),
		yaw(0),
		absoluteRoll(0),
		absolutePitch(0) {}

	Orientation(const Orientation& b) :
		roll(b.roll),
		pitch(b.pitch),
		yaw(b.yaw),
		absoluteRoll(b.absoluteRoll),
		absolutePitch(b.absolutePitch){}
};

struct WiimoteStatus {
	Button one;
	Button two;
	Button a;
	Button b;
	Button plus;
	Button minus;
	Button home;
	Button up;
	Button down;
	Button left;
	Button right;
	Orientation orientation;

	WiimoteStatus() :
		one(Button::RELEASED),
		two(Button::RELEASED),
		a(Button::RELEASED),
		b(Button::RELEASED),
		plus(Button::RELEASED),
		minus(Button::RELEASED),
		home(Button::RELEASED),
		up(Button::RELEASED),
		down(Button::RELEASED),
		left(Button::RELEASED),
		right(Button::RELEASED),
		orientation(Orientation()) {}

	WiimoteStatus(const WiimoteStatus& b) :
		one(b.one),
		two(b.two),
		a(b.a),
		b(b.b),
		plus(b.plus),
		minus(b.minus),
		home(b.home),
		up(b.up),
		down(b.down),
		left(b.left),
		right(b.right),
		orientation(Orientation(b.orientation)) {}
};

struct WiimoteCtrlStatus {
};