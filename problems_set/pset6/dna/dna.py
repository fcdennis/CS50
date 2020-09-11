from sys import argv, exit
import csv

def main():
    if len(argv) != 3:
        print('Usage: python dna.py data.csv sequence.txt')
        exit(1)

    csv_path = argv[1]
    with open(csv_path) as csv_file:
        database = csv.reader(csv_file)
        all_sequences = next(database)[1:]

        txt_path = argv[2]
        with open(txt_path) as txt_file:
            complete_dna_sequence = txt_file.read()
            actual = [nitrogen_sequence(complete_dna_sequence, seq) for seq in all_sequences]

        found_sequence_match(database, actual)


def nitrogen_sequence(complete_dna_sequence, nitrogen):
    ans = [0] * len(complete_dna_sequence)
    for i in range((len(complete_dna_sequence) - len(nitrogen)), -1, -1):
        if complete_dna_sequence[i: i + len(nitrogen)] == nitrogen:
            if i + len(nitrogen) > len(complete_dna_sequence) - 1:
                ans[i] = 1
            else:
                ans[i] = 1 + ans[i + len(nitrogen)]
    
    return max(ans)


def found_sequence_match(reader, actual):
    for line in reader:
        person = line[0]
        values = [int(val) for val in line[1:]]
        if values == actual:
            print(person)
            return
    print('No match')


if __name__ == "__main__":
    main()