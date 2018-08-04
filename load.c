// Loads words from dictionary onto a hashtable

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

#define LENGTH 45

// Declare functions to be used at a later time
int hash(string);

// Node definition for individual components of linked lists
typedef struct _node
{
    char word[LENGTH + 1];
    struct _node* next;
}
node;


int main(void)
{

// Creating an appropriate array to serve as rows of hashtable
node* hash_table[26];

//Declare head to each element of array, with pointer pointing to NULL
for(int i = 0; i < 26; i++)
{
    hash_table[i]->next = NULL;              //THIS (LINE 31) IS WHERE I AM GETTING A SEG FAULT//
}

// Actually inputting the word into the text


// Read string from a file
FILE* inptr = fopen("small", "r");
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

    // If it's the first node being added, just replace the string here
    if ((hash_table[index]->next) == NULL)
    {
        strcpy((hash_table[index]->word), (new_node->word));
    }

    // If not, mess with the pointers accordingly
    else
    {
    new_node->next = hash_table[index];
    hash_table[index] = new_node;
    }
}


// Make sure contents of hash table are correct - just for me, to make sure this works

// Ask user for array number for contents
int contents = get_int("Check words in array number: ");

// Create traversable pointer to array number specified by user
node* trav = hash_table[contents];

// print the word in each node associated with the array number until you reach end of linked list
while (trav != NULL)
{
    printf("%s\n", trav->word);
    trav = trav->next;
}

}

// Definition of hash function

int hash(string s)
{
   int _index = s[0] - 'a';
   return _index;
}
