// Implements a dictionary's functionality

#include <stdbool.h>
#include "dictionary.h"
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>

// Define a node
typedef struct _node
{
    char word[LENGTH + 1];
    struct _node* next;
}
node;

int hash(const char*);

// Creating an appropriate array to serve as rows of hashtable
node* hash_table[26];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int indexed = hash(word);
    node* trav = hash_table[indexed];

    while (trav != NULL)
    {
        int j = strcasecmp(hash_table[indexed]->word, word);

        if (j == 0)
        {
            return true;
        }
    }

        return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //Declare head to each element of array = NULL
    for(int i = 0; i < 26; i++)
    {
        hash_table[i] = NULL;
    }

    // Read string from a file
    FILE* inptr = fopen(dictionary, "r");
    char buffer[LENGTH + 1];

    // Place strings into nodes until EOF
    while (fscanf(inptr, "%s", buffer) != EOF)
    {
        // Allocate memory for new node
        node* new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return false;
        }

        // Copy file word into node
        strcpy(new_node->word, buffer);

        // Determine index of word
        int index = hash(new_node->word);

        // Add the word to the front of the list
        new_node->next = hash_table[index];
        hash_table[index] = new_node;
    }

    fclose(inptr);
    return true;

}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (&load == false)
    {
    return 0;
    }

    unsigned int word_ctr = 0;

    for (int i = 0; i < 26; i++)
    {
        node* trav = hash_table[i];

        while (trav != NULL)
        {
            word_ctr++;
            trav = trav->next;
        }
    }

    return word_ctr;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for(int i = 0; i < 26; i++)
    {
        node* trav = hash_table[i];

        while (trav != NULL)
        {
            node* temp = trav;
            trav = trav->next;
            free(temp);
        }
    }

    return true;

}

// Definition of hash function
int hash(const char* s)
{
    int _index = 0;

    if (isupper(s[0]))
    {
        _index = s[0] - 'A';
    }

    else
    {
        _index = s[0] - 'a';
    }
   return _index;
}
