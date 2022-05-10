#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _GNU_SOURCE
#define __USE_GNU
#include <dlfcn.h>

#include "object.h"

void make_object(object* this) {
    void* handle = dlmopen(LM_ID_NEWLM, "./object.so", RTLD_NOW);
    assert(handle);
    printf("handle = %p\n", handle);

    typedef void (*fntype_make_object)(object*);
    fntype_make_object make_object_dl = (fntype_make_object) dlsym(handle, "make_object");
    assert(!dlerror());

    make_object_dl(this);
}

void debug_object(object* this) {
    printf("object { x = %d }\n", this->x);
}
