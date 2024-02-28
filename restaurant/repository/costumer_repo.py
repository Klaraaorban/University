class CostumerRepo:
    def __init__(self):
        self.costumerdic = {}
        self.myCust = []
        self.myStreet = []
        self.myCustID = []

    def read_cost_file(self):
        with open('rest_cost.txt', "r") as file:
            for line in file:
                key, value = line.strip("\n").split(": ")
                self.costumerdic[key] = value

        print(self.costumerdic)


    def create_cost_list(self):
        strt = []
        with open('rest_cost.txt', 'r') as file:
            for line in file:
                key, value = line.strip(" ").split(": ")
                self.costumerdic[key] = value
                self.myCustID.append(key)
                strt.append(value)

        self.myCust = [i.strip(" ").split(", ")[0] for i in strt]
        # self.myStreet = [i.strip(" ").split(", ")[1] for i in strt]

        return self.myCust

    def create_street_list(self):
        strt = []
        with open('rest_cost.txt', 'r') as file:
            for line in file:
                key, value = line.strip("\n").split(": ")
                self.costumerdic[key] = value
                self.myCustID.append(key)
                strt.append(value)

        self.myStreet = [i.strip(" ").split(", ")[1] for i in strt]

        return self.myStreet

    def create_id_list(self):
        with open('rest_cost.txt', 'r') as file:
            for line in file:
                key, value = line.strip(" ").split(": ")
                self.costumerdic[key] = value
                self.myCustID.append(key)

        return self.myCustID

    def update_cost_name(self, cost_id, cost_name, cost_street):
        with open("rest_cost.txt", "r+") as file:
            new_f = file.readlines()
            file.seek(0)
            for line in new_f:
                if str(cost_id) not in line:
                    file.write(line)
            file.truncate()

        with open('rest_cost.txt', 'a') as file:
            file.write(f'{cost_id}: {cost_name}, {cost_street}\n')

