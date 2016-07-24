#include <iostream>
#include <boost\program_options.hpp>
#include "ComnProcess.h"

using namespace boost;
using namespace boost::program_options;

int main(int argc, char* argv[]) {
	options_description opt("options: ");
	opt.add_options()
		("help,h", "Show help")
		("com,c", value<std::string>(), "Bluetooth COM port to Smart phone");
	variables_map argmap;
	store(parse_command_line(argc, argv, opt), argmap);
	notify(argmap);

	if(argmap.count("help") || !argmap.count("com")) {
		std::cout << opt << std::endl;
		return 1;
	}

	ComnProcess process(argmap["com"].as<std::string>());
	process.initialize();
	process.run();

	return 0;
}