from modelle.essen import Essen
class Costumer:
    def __init__(self, name: str, street: str, order: Essen):
        self.name = name
        self.street = street
        self.order = order


    def __eq__(self, other):
        return self.name == other.name

    def __str__(self):
        return (f'Costumer: {self.name}, Street: {self.street}, \n'
                f'Order: {self.order}\n')
