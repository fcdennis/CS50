class Studant():
    def __init__(self, name, id):
        self.name = name
        self.id = id


    def changeID(self, id):
        self.id = id

    
    def changeName(self, name):
        self.name = name


    def print(self):
        print(f"{self.name} - {self.id}")


jane = Studant("Jane", 10)
jane.print()
jane.changeID(11)
jane.print()
jane.changeName("Emma")
jane.print()

