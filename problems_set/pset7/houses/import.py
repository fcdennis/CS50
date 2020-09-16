import csv
from cs50 import SQL
from sys import argv, exit


if len(argv) != 2:
    print("Usage: python import.py characters.csv")
    exit(1)

db = SQL("sqlite:///students.db")

def main():
    with open(argv[1]) as csv_file:
        data = csv.DictReader(csv_file)
        for row in data:
            names = partitionFullName(row["name"])
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                names[0], names[1], names[2], row["house"], row["birth"]
            )


def partitionFullName(fullName):
    names = fullName.split()
    if(len(names) >= 3):
        return names
    else:
        return [names[0], None, names[1]]


main()