#pragma once
#include <vector>
#include "AbstractWiimoteInput.h"

struct wiimote_t;
class WiimoteInput;

/**
* Wii�����R���Ƃ̃C���^�[�t�F�C�X���s���N���X�ł��B
* Wii�����R���ƃC���^�[�t�F�C�X���s���N���X�ł��邽�߁A�{�N���X�Ƀr�W�l�X���W�b�N���������Ă͂����܂���B
*/
class WiimoteInput : public AbstractWiimoteInput {
public:	
	static std::vector<WiimoteInput*> connect(int maxNumOfWiimotes , int delay = 5);

	virtual ~WiimoteInput();
	virtual bool isConnected();
	virtual void turnOnVibration();
	virtual void turnOffVibration();
	virtual void turnOnMotionSensing();
	virtual void turnOffMotionSensing();
	virtual void turnOnLed(WiimoteLed led);
	virtual bool isAccelermeterEnabled();
	virtual WiimoteEvent getEvent();
	virtual WiimoteStatus getStatus();

private:
	WiimoteInput(wiimote_t* _device);	

	wiimote_t* device;
	int ledToWiiUseLed(WiimoteLed led) const;
	WiimoteEvent toWiimoteEvent(int e) const;
	Button getButtonStatus(int button) const;
};