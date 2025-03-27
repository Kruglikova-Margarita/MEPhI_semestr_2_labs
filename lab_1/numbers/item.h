#include <stdlib.h>

#ifndef item_h
#define item_h

typedef struct item {
    const struct itemInfo *info;
    void (*printItem)();
    void *data;
} item;

typedef struct itemInfo {
    size_t size;
    void *(*getData)(item *);
    void (*freeItem)(item *);
    item *(*zero)();
    item *(*one)();
    item *(*sum)(item *, item *);
    item *(*mult)(item *, item *);
    item *(*reverseSum)(item *);
    item *(*reverseMult)(item *);
    item *(*difference)(item *, item *);
    item *(*division)(item *, item *);
    item *(*copy)(item *);
    int (*compare)(item *, item *);
    int (*equal)(item *, item *);
} itemInfo;

#endif