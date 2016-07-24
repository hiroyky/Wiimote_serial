#include "WiimotePtreeStructs.h"
#include <boost/property_tree/json_parser.hpp>

using namespace boost::property_tree;

OrientationPtreed::OrientationPtreed(const Orientation& base) : Orientation(base) {
}

ptree OrientationPtreed::toPtree() const {
	ptree pt;
	pt.put("roll", roll);
	pt.put("pitch", pitch);
	pt.put("yaw", yaw);
	pt.put("absoluteRoll", absoluteRoll);
	pt.put("absolutePitch", absolutePitch);
	return pt;
}

WiimoteStatusPtreed::WiimoteStatusPtreed(const WiimoteStatus& base) : WiimoteStatus(base) {
	orientation = OrientationPtreed(base.orientation);
}

ptree WiimoteStatusPtreed::toPtree() const {
	ptree pt;
	pt.put("a", a);
	pt.put("b", b);
	pt.put("one", one);
	pt.put("two", two);
	pt.put("plus", plus);
	pt.put("minus", minus);
	pt.put("home", home);
	pt.put("up", up);
	pt.put("down", down);
	pt.put("right", right);
	pt.put("left", left);
	pt.add_child("orientation", ((OrientationPtreed)orientation).toPtree());
	return pt;
}

std::string WiimoteStatusPtreed::toJson() const {
	std::stringstream ss;
	write_json(ss, toPtree());
	return ss.str();
}