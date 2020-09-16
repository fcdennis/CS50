from sys import argv
from cs50 import SQL

if len(argv) != 2:
    print("usage: python roster.py housename")
    exit(1)

db = SQL("sqlite:///students.db")
house = argv[1]
rows = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first", house)
for row in rows:
    print(f'{row["first"]} {row["middle"] + " " if row["middle"] else ""}{row["last"]}, born {row["birth"]}')
    