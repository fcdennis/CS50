#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

double cont_letters(string txt);//função de contagem de letras
double cont_words(string txt);//função de contagem de palavras
double cont_sentences(string txt);//função de contagem de sentenças(frases).
double index(double letters, double words, double sentences);//função de calculo do index
int main(void)
{
    //Funçaõ principal recebe o texto, aciona as outras funções e entrega a impressão do resultado mais adequado
    string txt = get_string("Digite o texto: ");
    double numletters = cont_letters(txt);
    double numwords = cont_words(txt);
    double numsentences = cont_sentences(txt);
    double index_grade = index(numletters, numwords, numsentences);
    //Após o calculo do index ele imprime a opção mais adequada
    if (index_grade < 1.0)
    {
        printf("Before Grade 1\n");
    }
    else if (index_grade > 16.0)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", round(index_grade));
    }
}

double cont_letters(string txt)//função contagem de letras, recebe um texto
{
    double letters = 0;
    for (int i = 0, len = strlen(txt); i < len; i++)
    {
        if (isalnum(txt[i]))
        {
            letters++;
        }
    }
    return letters;//retorna a quantidade de letras do texto
}

double cont_words(string txt)//função contagem de palavras, recebe um texto
{
    double words = 1;
    {
        for (int i = 0, len = strlen(txt); i < len; i++)
        {
            if (isblank(txt[i]))
            {
                words++;
            }
        }
    }
    return words;//retorna a quantidade de palavras do texto
}

double cont_sentences(string txt)//função de contagem de sentenças(frases), recebe um texto
{
    char exclamation = 33, point = 46, interrogation = 63;
    double sentences = 0;
    for (int i = 0, len = strlen(txt); i < len; i++)
    {
        if (txt[i] == exclamation || txt[i] == point || txt[i] == interrogation)
        {
            sentences++;
        }
    }
    return sentences;//retorna a quantidade de sentenças(frases)
}

double index(double letters, double words, double sentences)//função de calculo do index
{
    double L = (100 * letters) / words;
    double S = (100 * sentences) / words;
    double index = (0.0588 * L - 0.296 * S - 15.8);//formula de Coleman-Liau
    return index;
}