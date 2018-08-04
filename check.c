// Checks to see if word is in dictionary

int hash(string s) //DEFINED IN LOAD.C, FOR NOW//

bool check (string word)
{
    indexed = hash(word);
    node* trav = hash_table[indexed];

    while (trav != NULL)
    {
        strcasecmp(hash_table[indexed]->word, word);

        if (strcasecmp = 0)
        {
            return true;
        }
    }

    if (trav == NULL)
    {
        return false;
    }

}
