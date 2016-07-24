#include "SerialPort.h"
using namespace boost::asio;

SerialPort::SerialPort(const std::string& _com) :
	comPort(_com), io(new io_service()), serialPort(0) {
}

SerialPort::~SerialPort() {
	delete io;
	delete serialPort;
}

void SerialPort::open(int bauRate) {
	serialPort = new serial_port(*io, comPort);
	serialPort->set_option(serial_port::baud_rate(bauRate));
}

void SerialPort::close() {
	serialPort->close();
}

void SerialPort::write(const std::string& data) {
	serialPort->write_some(buffer(data));
}

std::string SerialPort::read() {
	char buf[1024];
	int length = serialPort->read_some(buffer(buf));
	return std::string(buf, length);
}