#pragma once

#include <climits>
#include <vector>

typedef int TElem;

typedef struct Nod {
    TElem element;
    Nod* urmator;
    Nod* precedent;
}Nod;

typedef bool(*Relatie)(TElem, TElem);

//in implementarea operatiilor se va folosi functia (relatia) rel (de ex, pentru <=)
// va fi declarata in .h si implementata in .cpp ca functie externa colectiei
bool rel(TElem, TElem);

class IteratorColectie;

class Colectie {

	friend class IteratorColectie;

private:
    int cap;
    int len;
    int* urm;
    int* prec;
    int* frecventa;
    TElem* el;
    int prim;
    int ultim;
    int primLiber;
    Relatie relatie;

    int aloca();

    void dealoca(int i);

    void initSpatiuLiber(int a);

    int creeazaNod(TElem e);
public:
		//constructorul implicit
		Colectie();

		//adauga un element in colectie
		void adauga(TElem e);

		//sterge o aparitie a unui element din colectie
		//returneaza adevarat daca s-a putut sterge
		bool sterge(TElem e);

		//verifica daca un element se afla in colectie
		bool cauta(TElem elem) const;

		//returneaza numar de aparitii ale unui element in colectie
		int nrAparitii(TElem elem) const;


		//intoarce numarul de elemente din colectie;
		int dim() const;

		//verifica daca colectia e vida;
		bool vida() const;

		//returneaza un iterator pe colectie
		IteratorColectie iterator() const;

		// destructorul colectiei
		~Colectie();


    int cauta_ind(TElem e);

    void adaugaToateElementele(const Colectie &b);
};

