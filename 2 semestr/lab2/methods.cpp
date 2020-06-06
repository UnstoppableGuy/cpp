// ---------------------------------------------------------------------------

#pragma hdrstop

#include "methods.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

UnicodeString Puplist::show() {
	int sum = atoi(math.c_str()) + atoi(physics.c_str()) + atoi(english.c_str()) + atoi(certificate.c_str());
	std::stringstream ss;
	ss << sum;
	std::string str = ss.str();
	std::string object = surname + " " + name + " " + patronymic + " " +
	specialty + " " + str;
	return object.c_str();
}

bool Puplist::search(std::string surnam, std::string nam, std::string patronymi)
{
	if (surnam == surname && nam == name && patronymi == patronymic) {
		return true;
	}
	else {
		return false;
	}
}

int Puplist::getNumber() {
	int yay = atoi(math.c_str()) + atoi(physics.c_str()) + atoi(english.c_str()) + atoi(certificate.c_str());
	return yay;

}

bool Puplist::searchspec(std::string spec) {
	if (spec == specialty) {
		return true;
	}
	else {
		return false;
	}
}
