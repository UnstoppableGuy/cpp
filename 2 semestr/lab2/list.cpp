// ---------------------------------------------------------------------------

#pragma hdrstop

#include "list.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

void PuplistReal::show(TMemo *Mem)
{
	for (int i = 0; i < length; i++)
	{
		Mem->Lines->Add(elements[i]->show());
	}

}

void PuplistReal::addElement(Puplist *puplist)
{
	elements[length] = puplist;
	length++;

}

void PuplistReal::search(std::string surname, std::string name,
	std::string patronymic, TMemo *Mem)
{
	for (int i = 0; i < length; i++)
	{
		if (elements[i]->search(surname, name, patronymic) == true)
		{
			Mem->Lines->Add(elements[i]->show());
		}
	}

}

void PuplistReal::delet(std::string surname, std::string name,
	std::string patronymic, TMemo *Mem)
{
	Puplist **elementsplus = new Puplist*[100];
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (elements[i]->search(surname, name, patronymic) == true)
		{
			continue;
		}
		else
		{
			elementsplus[count] = elements[i];
			count++;
		}
	}
	for (int j = 0; j < length; j++)
	{
		elements[j] = elementsplus[j];
	}
	length--;
	delete[]elementsplus;

}

void PuplistReal::sort()
{

	int i, j, step, flg;
	Puplist *n = new Puplist;
	for (step = length / 2; step > 0; step /= 2)
	{
		do
		{
			flg = 0;
			for (i = 0, j = step; j < length; i++, j++)
			{
				if (elements[i]->getNumber() < elements[j]->getNumber())

				{
					n = elements[j];
					elements[j] = elements[i];
					elements[i] = n;
					flg = 1;
				}
			}
		}
		while (flg);
	}

}

void PuplistReal::showtime(std::string POG, TMemo *Mem)
{
	Puplist **elementsplus = new Puplist*[100];
	int count = 0;
	for (int i = 0; i < length; i++) {
		if (elements[i]->searchspec(POG) != true)
		{
			continue;
		}
		else
		{
			elementsplus[count] = elements[i];
			count++;
		}
	}
	int i, j, step, flg;
	Puplist *n = new Puplist;
	for (step = count / 2; step > 0; step /= 2)
	{
		do
		{
			flg = 0;
			for (i = 0, j = step; j < count; i++, j++) {
				if (elementsplus[i]->getNumber() < elementsplus[j]->getNumber())
				{
					n = elementsplus[j];
					elementsplus[j] = elementsplus[i];
					elementsplus[i] = n;
					flg = 1;
				}
			}
		}
		while (flg);
	}

	for (int i = 0; i < count; i++)
	{
		Mem->Lines->Add(elementsplus[i]->show());
	}

}

PuplistReal::~PuplistReal()
{
	for (int i = 0; i < length; i++)
	{
		delete elements[i];
	}
	delete[]elements;
}
