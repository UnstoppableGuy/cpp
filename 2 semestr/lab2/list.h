// ---------------------------------------------------------------------------

#ifndef listH
#define listH
// ---------------------------------------------------------------------------
#endif
#include "methods.h"

class PuplistReal
{
private:
	int length;
	Puplist **elements;

public:
	PuplistReal()
	{
		elements = new Puplist*[100];
	}
	void show(TMemo *);
	void addElement(Puplist *);
	void search(std::string, std::string, std::string, TMemo *);
	void delet(std::string, std::string, std::string, TMemo *);
	void sort();
	void showtime(std::string, TMemo *);
	~PuplistReal();
};
