#pragma once

#include <iostream>
#include <boost/asio.hpp>

class SerialPort {
public:
	SerialPort(const std::string& _com);
	virtual ~SerialPort();
	virtual void open(int bauRate = 9600);
	virtual void close();
	virtual void write(const std::string& data);
	virtual std::string read();

private:
	const std::string comPort;
	boost::asio::io_service* io;
	boost::asio::serial_port* serialPort;	
};