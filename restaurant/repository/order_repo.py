import functools
import os
import pickle
class OrderRepo:
    def __init__(self):
        self.orderlist = []
        self.orderdic = {}

    def add_bestellung(self, order):
        self.orderlist.append(order)

    def cost_count(self, one_order):
        self.gesamtkosten = functools.reduce(lambda i, j: i + j, one_order)
        return self.gesamtkosten


class FileOrderRepo(OrderRepo):
    def __init__(self, filename):
        OrderRepo.__init__(self)
        self.filename = filename
        if os.path.exists(self.filename):
            self.load()

    def save_order(self):
        f = open(self.filename, 'wb')
        pickle.dump(self.orderlist, f)
        f.close()

    def add_order(self, essen):
        super().add_bestellung(essen)
        self.save_order()

    def load(self):
        f = open(self.filename, 'rb')
        self.orderlist = pickle.load(f)
        f.close()

    def reset_orders(self):
        self.orderlist.clear()
        f = open(self.filename, 'wb')
        pickle.dump(self.orderlist, f)
        f.close()


    def invoice_string(self, filename):
        pass
