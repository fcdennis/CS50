def main():
    txt = input('Text: ')
    numLetters = cont_letters(txt)
    numWords = cont_words(txt)
    numSentences = cont_sentences(txt)
    indexGrade = index(numLetters, numWords, numSentences)

    if(indexGrade < 1):
        print('Before Grade 1')
    elif(indexGrade > 16):
        print('Grade 16+')
    else:
        print(f'Grade {round(indexGrade)}')


def cont_letters(txt):
    letters = 0
    txtlength = len(txt)
    for c in range(0, txtlength):
        if(txt[c].isalnum()):
            letters += 1
    return letters


def cont_words(txt):
    words = 1 # the last word doesn't  count 
    txtlength = len(txt)
    for c in range(0, txtlength):
        if(txt[c].isspace()):
            words += 1
    return words


def cont_sentences(txt):
    sentences = 0
    txtlength = len(txt)
    for c in range(0, txtlength):
        if(txt[c] == '!' or txt[c] == '?' or txt[c] == '.'):
            sentences += 1
    return sentences


def index(letters, words, sentences):
    L = (100 * letters)  / words
    S = (100 * sentences) / words
    return (0.0588 * L) - (0.296 * S) - 15.8


main()