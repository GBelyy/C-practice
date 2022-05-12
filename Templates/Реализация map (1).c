#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node
{
    char* name;
    long val;
    struct node* next;
};
typedef struct node Node;

struct map
{
    int size;
    int n_elements;
    Node** table;
};
typedef struct map Map;

Map* map_create()
{
    Map* ht = malloc(sizeof(Map));
    ht->size = 1;
    ht->n_elements = 0;
    ht->table = malloc(sizeof(Node));

    for(int i = 0; i < ht->size; i++)
        ht->table[i] = NULL;

    return ht;
}


unsigned int hash_function(char* s)
{
    unsigned int h = 0;

    for(char* p = s; *p; p++)
        h = h * 97 + *p;

    return h;
}

Node* find(Map* ht, char* name)
{

    unsigned int id = hash_function(name);
    Node* pn = ht->table[id];
    while (pn != NULL)
    {
        if (strcmp(name, pn->name) == 0)
            return pn;
    }
    return NULL;
}

void map_insert(Map * s,char* name, long n)
{
	    if (find(s, n) != NULL)
	        return;
        s->table = realloc(s,sizeof(Node)*(s->size+1));
	    Node* pn = malloc(sizeof(Node));
	    pn->name = malloc(strlen(name) + 1);
	    pn->val = n;
	    unsigned int id = hash_function(n);
	    s->table[id] = pn;
	    s->n_elements++;
	    s->size += 1;
	    pn->next = s->table[id];
	    s->table[id] = pn;
}
void map_assign(Map * s,char* name, long n)
{
     if (find(s, n) != NULL)
     {
        find(s, n)->val = n;
     }
     else
    {
        insert(s, name, n);
    }
}

void free_node(Node* node)
{
    free(node->name);
    free(node->val);
    free(node);
}

void erase(Map * s,char* name)
{
    unsigned int id = hash_function(name);
    Node* pn = s->table[id];
    if (pn == NULL)
        return 0;

    if (strcmp(name, pn->name) == 0)
    {
        s->table[id] = pn->next;
        free_node(pn);
        s->n_elements--;
        return 1;
    }
    Node* prev = pn;
    Node* curr = pn->next;
    while (curr != NULL)
    {
        if (strcmp(name, curr->name) == 0)
        {
            prev->next = curr->next;
            free_node(curr);
            s->n_elements--;
            return 1;
        }
        prev = curr;
        curr = curr->next;
    }

    return 0;
}
void map_destroy(Map* s)
{
    for (int i = 0; i < s->size; i++)
    {
        Node* pn = s->table[i];
        while (pn != NULL)
        {
            Node* temp = pn;
            pn = pn->next;
            free_node(temp);
        }
    }
    free(s->table);
    free(s);
}
int main()
{
Map* m = map_create();
map_insert(m, "Dolgoprudny", 90956);
map_insert(m, "London", 8908081);
map_insert(m, "Montevideo", 1719453);
map_assign(m, "Adelaide", 1345777);
map_assign(m, "Dolgoprudny", 108861); // Как бы m["Dolgoprudny"] = 108861;
Node* p = map_find(m, "London");
if (p != NULL)
printf("London is in the map. Population = %d\n", p->value);
else
printf("No London in the map\n");
map_destroy(m);
}
