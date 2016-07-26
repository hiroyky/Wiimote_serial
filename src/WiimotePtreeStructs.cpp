#include "WiimotePtreeStructs.h"
#include <boost/property_tree/json_parser.hpp>

using namespace boost::property_tree;

OrientationPtreed::OrientationPtreed(const Orientation& base) : Orientation(base) {
}

ptree OrientationPtreed::toPtree() const {
	ptree pt;
	pt.put("Roll", roll);
	pt.put("Pitch", pitch);
	pt.put("Yaw", yaw);
	pt.put("AbsoluteRoll", absoluteRoll);
	pt.put("AbsolutePitch", absolutePitch);
	return pt;
}

WiimoteStatusPtreed::WiimoteStatusPtreed(const WiimoteStatus& base) : WiimoteStatus(base) {
	orientation = OrientationPtreed(base.orientation);
}

ptree WiimoteStatusPtreed::toPtree() const {
	ptree pt;
	pt.put("A", a);
	pt.put("B", b);
	pt.put("One", one);
	pt.put("Two", two);
	pt.put("Plus", plus);
	pt.put("Minus", minus);
	pt.put("Home", home);
	pt.put("Up", up);
	pt.put("Down", down);
	pt.put("Right", right);
	pt.put("Left", left);
	pt.add_child("Orientation", ((OrientationPtreed)orientation).toPtree());
	return pt;
}

std::string WiimoteStatusPtreed::toJson() const {
	std::stringstream ss;
	write_json(ss, toPtree());
	return ss.str();
}