/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>

#include "dictionary.h"

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
 bool load(const char* dictionary)
{
    // TODO
    // opens dictionary
    FILE* file = fopen(dictionary, "r");
    if (file == NULL)
        return false;
    
    // create an array for word to be stored in
    char word[LENGTH+1];
    
    // scan through the file, loading each word into the hash table
    while (fscanf(file, "%s\n", word)!= EOF)
    {
        // increment dictionary size
        dictionarySize++;
        
        // allocate memory for new word 
        node* Word = malloc(sizeof(node));
        
        // put word in the new node
        strcpy(Word->word, word);
        
        // find what index of the array the word should go in
        int count = hash(word);
        
        // if hashtable is empty at index, insert
        if (hashtable[count] == NULL)
        {
            hashtable[count] = Word;
            Word->next = NULL;
        }
        
        // if hashtable is not empty at index, append
        else
        {
            Word->next = hashtable[index];
            hashtable[index] = Word;
        }      
    }
    
    // close file
    fclose(file);
    
    // return true if successful 
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
