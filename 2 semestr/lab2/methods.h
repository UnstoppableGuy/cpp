// ---------------------------------------------------------------------------
#include"main.h"
#ifndef methodsH
#define methodsH
// ---------------------------------------------------------------------------
#include <string>
#include <vcl.h>
#include <sstream>

class Puplist {
private:
	std::string surname;
	std::string name;
	std::string patronymic;
	std::string specialty;
	std::string math;
	std::string physics;
	std::string english;
	std::string certificate;

public:
	Puplist(std::string surname1, std::string name1, std::string patronymic1,
		std::string specialty1, std::string math1, std::string physics1,
		std::string english1, std::string certificate1) {
		surname = surname1;
		name = name1;
		patronymic = patronymic1;
		specialty = specialty1;
		math = math1;
		physics = physics1;
		english = english1;
		certificate = certificate1;
	}

	Puplist() {
	};
	UnicodeString show();
	bool search(std::string, std::string, std::string);
	bool searchspec(std::string);
	int getNumber();
};

#endif
