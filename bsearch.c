#include <stdio.h>
#include <stdlib.h>

void * bsearch(const void * key, const void * base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
int cmpint(const void* key, const void* element);

int main(int argc, char const *argv[]) {
    int * item;
    int key = 127;
    int values[] = {1, 56, 89, 125, 630};
    item = (int *) bsearch (&key, values, 5, sizeof (int), cmpint);
    if (item == NULL)
        printf("There is no %d in the array\n", key);
    else
        printf("Got it: %d\n", * item);
    return 0;
}

void * bsearch(const void * key, const void * base, size_t nmemb, size_t size, int (* compar)(const void *, const void *)) {
    const void * current_element;
    int cmpresult,
        first = 0,
        last = nmemb,
        medium;
    while (first <= last) {
        medium = first + (last - first) / 2;
        current_element = ((const char *) base) + (medium * size);
        cmpresult = (* compar)(key, current_element);
        if (cmpresult < 0)
            last = medium - 1;
        else if (cmpresult > 0)
            first = medium + 1;
        else
            return (int *) current_element;
    }
    return NULL;
}

int cmpint(const void * main, const void * compared) {
    int * mainref = (int *) main,
        * cmpd = (int *) compared;
    if (* mainref > * cmpd) return 1;
    if (* mainref == * cmpd) return 0;
    return -1;
}
