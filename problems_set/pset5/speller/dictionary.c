// Implements a dictionary's functionality

#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

unsigned int num_words =  0;
bool is_loaded = false;

// Number of buckets in hash table
const unsigned int N = 1;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char check_word[strlen(word)];
    strcpy(check_word, word);
    for (int i = 0; check_word[i] != '\0'; i++)
    {
        check_word[i] = tolower(check_word[i]);
    }
    int index = hash(check_word);
    if (table[index] != NULL)
    {
        for (node *nodeptr = table[index]; nodeptr != NULL; nodeptr = nodeptr->next)
        {
            if(strcmp(nodeptr->word, check_word) == 0)
            {
                return true;
            }
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int hash = 0;
    int n;
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (isalpha(word[i]))
        {
            n = word[i] - 'a' + 1;
        }
        else
        {
            n = 27;
        }
        hash = ((hash << 3) + n) % N;
    }
    return hash;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *infile = fopen(dictionary, "r");
    
    if (infile != NULL)
    {
        for (int i = 0; i < N; i++)
        {
            table[i] = NULL;
        }
        
        char word[LENGTH + 1];
        node *new_nodeptr;
        while (fscanf(infile, "%s", word) != EOF)
        {
            num_words++;
            do
            {
                new_nodeptr = malloc(sizeof(node));
                if (new_nodeptr == NULL)
                {
                    free(new_nodeptr);
                }
            } while (new_nodeptr == NULL);
            
            strcpy(new_nodeptr->word, word);
            int index = hash(word);

            new_nodeptr->next = table[index];
            table[index] = new_nodeptr;
        }
        fclose(infile);
        is_loaded = true;
        return true;
    }
    
    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (is_loaded)
    {
        return num_words;
    }
    
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    if (is_loaded)
    {
        for (int i = 0; i < N; i++)
        {
            if (table[i] != NULL)
            {
                node *ptr = table[i];
                while (ptr != NULL)
                {
                    node *predptr = ptr;
                    ptr = ptr->next;
                    free(predptr);
                }
            }
        }
        return true;
    }
    
    return false;
}