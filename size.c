// Determines size of dictionary

int size(void)
{
int word_ctr = 0;

for (int i = 0; i < 26; i++)
{
    node* trav = hash_table[i];

    while (trav != NULL)
    {
        word_ctr++;
        trav = trav->next;
    }
}
}
