#pragma once
#include "WiimoteStructs.h"
#include <boost/property_tree/ptree.hpp>


struct OrientationPtreed: public Orientation {
	OrientationPtreed(const Orientation& base);
	boost::property_tree::ptree toPtree() const;
};

struct WiimoteStatusPtreed : public WiimoteStatus {
	WiimoteStatusPtreed(const WiimoteStatus& base);
	boost::property_tree::ptree toPtree() const;
	std::string toJson() const;
};