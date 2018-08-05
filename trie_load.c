// Loads a dictionary as a trie, then has user check to see if a word is in the dictionary

#include <stdbool.h>
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>

int array_conv(char);

int main(void)

{
    //Defining a node of the trie
    typedef struct _node
    {
        bool is_word;
        struct _node* children[27];
    }
    node;

    // Initialize global variable root node
    node* root = malloc(sizeof(node));

    // Read string from a file
    FILE* inptr = fopen("small", "r");
    char buffer[45 + 1];

    // Read strings into buffer until EOF
    while (fscanf(inptr, "%s", buffer) != EOF)
    {
        // Every time you have a new word, set traversal ptr to root
        node* trav = root;

        // Iterate through characters of buffer
        for (int i = 0; i < strlen(buffer); i++)

        {
            // Get child position
            int pos = array_conv(buffer[i]);
            trav = trav->children[pos];

            //Traversal ptr checks the child for NULL, giving child if this is the case
            if (trav == NULL)
            {
                node* new_node = malloc(sizeof(node));
                trav->children[pos] = new_node;
                trav = new_node;
            }

            if (i == strlen(buffer) - 1)
            {
                trav->is_word = true;
            }
        }
    }

    string check = get_string("Check for word: ");

    for (int i = 0; i < strlen(check); i++)
    {
        node* trav2 = root;
        int pos = array_conv(check[i]);
        trav2 = trav2->children[pos];

        if (trav2 == NULL)
        {
            printf("This word does not exist in the dictionary\n");
        }

        if (i == strlen(buffer) - 1)
        {
            if (trav2->is_word)
            {
                printf("This word does exist in the dictionary\n");
            }
        }
    }


}

    // Function to convert ascii values to numerical values for position in array, returning apostrophe if nonalphabetical
    int array_conv (char c)
    {
        int x = 26;

        if (isalpha(c))
        {
            x = c -'a';
        }

            return x;
    }
