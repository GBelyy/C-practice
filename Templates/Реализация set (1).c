#include <stdio.h>
#include <stdlib.h>
struct number
{
    long numb;
};
typedef struct number Number;

struct set
{
    long size;
    long n_elements;
    Number** table;
};
typedef struct set Set;

Set* set_create()
{
    Set* s = malloc(sizeof(Set));
    s->n_elements = 0;
    s->table = malloc(sizeof(Number));
    s->size = 1;
    for(int i = 0; i < s->size; i++)
       {
           s->table[i] = NULL;
       }
    return s;
}

Number* is_element_of(Set* ht, long n)
{
    unsigned int id = set_function(n);
    Number* pn = ht->table[id];
    while (pn != NULL)
    {
        if (n == pn->numb)
            return 1;
    }
    return NULL;
}
unsigned int set_function(long n)
{
    n *= n;
    n >>= 11;
    unsigned int h = (unsigned int)n % 1024;
    return h;
}
void insert(Set * s, long n)
{
	    if (set_find(s, n) != NULL)
	        return;
        s->table = realloc(s,sizeof(Number)*(s->size+1));
	    Number* pn = malloc(sizeof(Number));
	    pn->numb = malloc(sizeof(long));
	    pn->numb = n;
	    unsigned int id = set_function(n)%->size;
	    s->table[id] = pn;
	    s->n_elements++;
	    s->size += 1;
}
void erase(Set * s, long n)
{
    unsigned int id = hash_function(n);
    Number* pn = s->table[id];
    if (pn == NULL)
        return 0;
    if (pn->numb == n)
    {
        free_node(pn);
        s->n_elements--;
        return 1;
    }
    return 0;
}
void set_destroy(Set* ht)
{
    for (int i = 0; i < ht->size; i++)
    {
            Number* pn = ht->table[i];
            Number* temp = pn;
            free_number(temp);
    }
    free(ht->table);
    free(ht);
}
void free_number(Number* node)
{
    free(node->numb);
    free(node);
}
void print_set(Set* ht)
{
    printf("\n\n\n\tSet: size = %d, number of elements = %d\n", ht->size, ht->n_elements);
    for (int i = 0; i < ht->size; i++)
    {
        printf("\tId %u:\n", i);
        Number* pn = ht->table[i];
        printf("%ld", pn->numb);
    }
}
int main()
{
    Set* s = set_create();
    set_insert(s, 15);
    set_insert(s, 4);
    set_insert(s, 15);
    set_insert(s, 42);
    set_erase(s, 15);
    if (is_element_of(15, s))
        printf("YES\n");
    else
        printf("NO\n");
    set_destroy(s);
}