#include <exception>
#include "SetIterator.h"
#include "Set.h"
#include <iostream>


SetIterator::SetIterator(const Set& m) : set(m)
{	//punem iteratorul pe prima pozitie unde avem un element si daca set-ul e gol initializam it cu -1; best: theta(1) - e pe prima pozitie, worst: theta(m) - e ultima sau e gol, average: theta(m) -> O(m)
	it = 0;
	while (it < set.m && set.T[it] == NULL_TELEM)
		it++;
	if (it == set.m)
		it = -1;
}


void SetIterator::first() {
	//punem iteratorul pe prima pozitie unde avem un element si daca set-ul e gol initializam it cu -1; best: theta(1) - e pe prima pozitie, worst: theta(m) - e ultima sau e gol, average: theta(m) -> O(m)
	it = 0;
	while (it < set.m && set.T[it] == NULL_TELEM)
		it++;
	if (it == set.m)
		it = -1;
}


void SetIterator::next() {
	//crestem iteratorul pana la prima pozitie valida, daca it e mai mare decat capacitatea sau e gol set-ul aruncam exceptie ; best: theta(1) - e prima pozitie gasita, worst: theta(m) - ultima pozitie, average: theta(m) -> O(m)
	it++;
	if (it >= set.m || set.len == 0)
	{
		std::exception e;
		throw e;
	}
	while (set.T[it] == NULL_TELEM && it < set.m - 1)
		it++;
}


TElem SetIterator::getCurrent()
{	//returneaza elementul de la pozitia it, daca nu e valid aruncam exceptie; best, worst, average: theta(1)
	if (!valid())
	{
		std::exception e;
		throw e;
	}
	return set.T[it];
}

bool SetIterator::valid() const {
	//daca elementul de la pozitia it este null sau set-ul e gol atunci nu este valid altfel este; best, worst, average: theta(1)
	if (set.T[it] == NULL_TELEM or it == -1)
		return false;
	return true;
}



