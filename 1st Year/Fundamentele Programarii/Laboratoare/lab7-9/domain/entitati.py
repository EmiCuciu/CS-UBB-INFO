class Film:
    def __init__(self, film_id, titlu, descriere, gen):
        self.id = film_id
        self.titlu = titlu
        self.descriere = descriere
        self.gen = gen
        self.inchiriat = False

    def get_id(self):
        return self.id

    def set_id(self, film_id):
        self.id = film_id

    def get_titlu(self):
        return self.titlu

    def set_titlu(self, titlu):
        self.titlu = titlu

    def get_descriere(self):
        return self.descriere

    def set_descriere(self, descriere):
         self.descriere = descriere

    def get_gen(self):
        return self.gen

    def set_gen(self, gen):
        self.gen = gen

    def is_inchiriat(self):
        return self.inchiriat

    def set_inchiriat(self, inchiriat):
        self.inchiriat = inchiriat



class Client:
    def __init__(self, client_id, nume, cnp):
        self.id = client_id
        self.nume = nume
        self.cnp = cnp
        self.filme_inchiriate = []

    def get_id(self):
        return self.id

    def set_id(self, client_id):
        self.id = client_id

    def get_nume(self):
        return self.nume

    def set_nume(self, nume):
        self.nume = nume

    def get_cnp(self):
        return self.cnp

    def set_cnp(self, cnp):
        self.cnp = cnp

    def get_filme_inchiriate(self):
        return self.filme_inchiriate

    def set_filme_inchiriate(self, filme_inchiriate):
        self.filme_inchiriate = filme_inchiriate


class Inchiriere:
    def __init__(self, client, film):
        # Initializare obiect Inchiriere
        self.client = client
        self.film = film
