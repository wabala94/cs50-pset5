// Unloads memory from hashtable

bool unload(void)
{
    for(i = 0, i < 26, i++)
    {
        node* trav = hash_table[i];

        while (trav != NULL)
        {
            node* temp = trav;
            trav = trav->next;
            free(temp);
        }
    }
}
