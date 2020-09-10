import csv

person = {
    "AGATC": '4',
    "AATG": '1',
    "TATC": '5'
}

with open('databases/small.csv') as csvfile:
    sampleData = csv.DictReader(csvfile)
    for row in sampleData:
        if(row["AGATC"] == person["AGATC"] and row["AATG"] == person["AATG"] and row["TATC"] == person["TATC"]):
            print(row['name'])

csvfile.close()

count = 0
sequence = open('sequences/1.txt')
for c in sequence:
    for e in c:
        if(e == 'AATG'):
            count += 1

print(count)
sequence.close()
