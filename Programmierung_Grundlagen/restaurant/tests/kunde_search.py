from controller.controller import Controller

class TestSearch():
    def __init__(self, controller: Controller):
        self.controller = controller

    def kunde_search(self):
        part_name = input("Search for name: ")
        cust_found = self.controller.cost_exists(part_name)
        if cust_found:
            for part in cust_found:
                with open('rest_cost.txt', 'r') as file:
                    for line in file:
                        if part in line:
                            return True

        else:
            return False

    def street_search(self):
        part_street = input("Search for street: ")
        street_found = self.controller.street_exists(part_street)
        if street_found:
            for part in street_found:
                with open('rest_cost.txt', 'r') as file:
                    for line in file:
                        if part in line:
                            return True

        else:
            return False

    def bestellung(self):
        x = input('Which costumers invoice? Give ID: ')
        with open('bestellung.data', 'r') as file:
            for line in file:
                if x in line:
                    return True
                else:
                    return False

    def bestellung_saved(self):
        with open('bestellung.data', 'rb') as file:
            for line in file:
                if line != 0:
                    return True
        return False


    def update_cost(self):
        cost_id = int(input('Search for the ID: '))
        with open('rest_cost.txt', 'r') as file:
            for line in file:
                if str(cost_id) not in line:
                    return False
        return True

    def test_kunde_search(self):
        assert self.kunde_search() == True

    def test_street_search(self):
        assert self.street_search() == True

    def test_bestellung(self):
        assert self.bestellung() == True

    def test_saved_bestellung(self):
        assert self.bestellung_saved() == True

    def test_update_cost(self):
        assert self.update_cost() == True
