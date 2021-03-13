#include "Set.h"
#include "SetITerator.h"
#include <iostream>

Set::Set() {
	//initializam capacitatea, array-ul, m (nr. prim) si lungimea (care este egala cu nr. de elem. in acest caz) si initializam toate elementele cu null; best, worst, average: theta(m)
	len = 0;
	m = 60013; //nu merge realocarea
	T = new TElem[m];
	for (int i = 0; i < m; i++)
		T[i] = NULL_TELEM;
}


bool Set::add(TElem elem) {
	//daca elementul este deja in set nu il mai adaugam, altfel ii calculam valoarea hash si il inseram la pozitia corespunzatoare, crescand lungimea
	//daca nu mai avem loc facem resize si rehash
	//best: theta(1) - inseram primul element , worst: theta(m) - realocam sau ultimul element , average: theta(m) -> O(m)
	if (search(elem) == true)
		return false;
	int i = 0;
	int pos = hash(elem, i);
	while (i < m && T[pos] != NULL_TELEM)
	{
		i = i + 1;
		pos = hash(elem, i);
	}
	if (i == m) {
		m = m * 2;
		TElem* T2 = new TElem[m];
		for (int k = 0; k < m; k++)
			T2[k] = NULL_TELEM;
		for (int j = 0; j < len; j++)
		{
			int pos = hash(T[j], j);
			T2[pos] = T[j];
		}
		delete[] T;
		T = T2;
		delete[] T2;
	}
	else
		T[pos] = elem;
	len++;
	return true;
}

bool Set::remove(TElem elem) {
	//parcurgem array-ul si cautam elementul, daca il gasim il inlocuim cu null, scadem lungimea si returnam true altfel false; best: theta(1) - primul element, worst theta(m) - nu gasim sau ultimul, average theta(m) -> O(m)
	for (int i = 0; i < m; i++)
		if (T[i] == elem)
		{
			len--;
			T[i] = NULL_TELEM;
			return true;
		}
	return false;
}

bool Set::search(TElem elem) const {
	//parcurgem array-ul folosindu-ne de functia hash si daca gasim elementul returnam true altfel false; best: theta(1) - primul element, worst: theta(m) - ultimul sau nu am gasit, average: theta(m) -> O(m)
	int i = 0;
	int pos = hash(elem, i);
	bool search;
	while (i < m && T[pos] != NULL_TELEM && T[pos] != elem)
	{
		i = i + 1;
		pos = hash(elem, i);
	}
	if (i < m && T[pos] == elem)
		search = true;
	else
		search = false;
	return search;
}


int Set::size() const {
	//marimea este lungimea; best, worst, average: theta(1)
	return len;
}


bool Set::isEmpty() const {
	//daca nu are niciun element este gol altfel nu; best, worst, average: theta(1)
	if (len == 0)
		return true;
	return false;
}


Set::~Set() {
	//dealocam spatiul array-ului, O(1)
	delete[] T;
}


SetIterator Set::iterator() const {
	return SetIterator(*this);
}

Set Set::durchschnitt(Set s2, Set s3)
{//parcurgem primul set si daca gasim elementul si in al doilea set il adaugam la al treilea set care va fi intersectia primelor 2; best: theta(m^2) - nu gaseste elemente comune sau insereaza in s3 un element, worst: theta(m^3) - face resize, average: theta(m^3) -> O(m^3)
	for (int i = 0; i < m; i++)
		if (T[i] != NULL_TELEM && s2.search(T[i]) == true)
			s3.add(T[i]);
	return s3;
}


