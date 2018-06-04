#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void * bsearch(const void * key, const void * base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
int cmpint(const void * main, const void * compared);
int cmpstr(const void * main, const void * compared);

int main(int argc, char const *argv[]) {
    //char * item;
    int * item;
    int key = 631;
    //char key[20] = "lodz";
    int values[] = {1, 56, 89, 125, 630};
    //char words[][20] = {"bialystok", "ife", "lodz", "major", "suchodolski"};
    //item = (char *) bsearch (key, words, 5, 20, (int(*)(const void*, const void*)) strcmp);
    item = (int *) bsearch (&key, values, 5, sizeof(int), cmpint);

    /*if (item == NULL)
        printf("Not found - %s\n", key);
    else
        printf("Got it! - %s\n", item);*/

    if (item == NULL)
        printf("Not found - %d\n", key);
    else
        printf("Got it! - %d\n", * item);
    return 0;
}

void * bsearch(const void * key, const void * base, size_t nmemb, size_t size, int (* compar)(const void *, const void *)) {
    const void * current_element;
    int cmpresult, first = 0, last = nmemb, medium;
    while (first <= last) {
        medium = first + (last - first) / 2;
        current_element = ((const char *) base) + (medium * size);
        cmpresult = (* compar)(key, current_element);
        if (cmpresult < 0)
            last = medium - 1;
        else if (cmpresult > 0)
            first = medium + 1;
        else
            return (void *) current_element;
    }
    return NULL;
}

int cmpint(const void * main, const void * compared) {
    int * mainref = (int *) main, * cmpd = (int *) compared;
    if (* mainref > * cmpd) return 1;
    if (* mainref == * cmpd) return 0;
    return -1;
}
