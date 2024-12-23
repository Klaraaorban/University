import functools
class Identifizierbar:
    def __init__(self, id):
        self.id = id

class Gericht(Identifizierbar):
    def __init__(self, id, portion, preis):
        Identifizierbar.__init__(self, id)
        self.portion = portion
        self.preis = preis

class GekochGericht(Gericht):
    def __init__(self, id, portion, preis, zeit):
        Gericht.__init__(self, id, portion, preis)
        self.zeit = zeit

class Getrank(Gericht):
    def __init__(self, id, portion, preis, alkgehalt):
        Gericht.__init__(self, id, portion, preis)
        self.alkgehalt = alkgehalt

class Kunde(Identifizierbar):
    def __init__(self, id, name, adress):
        Identifizierbar.__init__(self, id)
        self.name = name
        self.adress = adress

    def __eq__(self, other):
        return self.name == other.name

class Bestellung(Identifizierbar):
    def __init__(self, kunden_id, gesamtkosten):
        Identifizierbar.__init__(self, id)
        self.gericht_id = []
        self.getrank_id = []
        self.gesamtkosten = gesamtkosten
        self.kunden_id = kunden_id

    def cost_count(self, one_order):
        self.gesamtkosten = functools.reduce(lambda i, j: i + j, one_order)
        return self.gesamtkosten

    def gen_inv_str(self):
        self.gesamtkosten = map(lambda x, y: x + y, self.gericht_id, self.getrank_id)
        # return (f'{self.kunden_id}:{self.gericht_id}, {self.getrank_id}')
