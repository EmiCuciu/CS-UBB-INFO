#include "TestScurt.h"
#include "Colectie.h"
#include "IteratorColectie.h"
#include <assert.h>

void testAll() {
    Colectie c;
    c.adauga(5);
    c.adauga(6);
    c.adauga(0);
    c.adauga(5);
    c.adauga(10);
    c.adauga(8);

    assert(c.dim() == 6);
    assert(c.nrAparitii(5) == 2);

    assert(c.sterge(5) == true);
    assert(c.dim() == 5);

    assert(c.cauta(6) == true);
    assert(c.vida() == false);

    IteratorColectie ic = c.iterator();
    assert(ic.valid() == true);
    while (ic.valid()) {
        ic.element();
        ic.urmator();
    }
    assert(ic.valid() == false);
    ic.prim();
    assert(ic.valid() == true);

    Colectie c1;
    c1.adauga(0);
    c1.adauga(0);
    c1.adauga(0);
    c1.adauga(1);
    c1.adauga(1);
    c1.adauga(2);
    c1.adauga(3);
    c1.adauga(3);

    assert(c1.transformaInMultime() == 4);
    assert(c1.dim() == 4);
    IteratorColectie ic1 = c1.iterator();
    assert(ic1.element() == 0);
    ic1.urmator();
    assert(ic1.element() == 1);
    ic1.urmator();
    assert(ic1.element() == 2);
    ic1.urmator();
    assert(ic1.element() == 3);
    ic1.urmator();
    assert(ic1.valid() == false);
}
