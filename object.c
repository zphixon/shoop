#include <assert.h>
#include <stdio.h>

#define _GNU_SOURCE
#define __USE_GNU
#include <dlfcn.h>

#include "object.h"

void make_object(object* this) {
    void* handle = dlmopen(LM_ID_NEWLM, "./object.so", RTLD_NOW);
    assert(handle);

    typedef void (*fntype_make_object)(object*, void*);
    fntype_make_object make_object_dl = (fntype_make_object) dlsym(handle, "make_object");
    assert(!dlerror());

    make_object_dl(this, handle);
}

void free_object(object* this) {
    assert(!dlclose(this->handle));
}

void debug_object(object* this) {
    printf("object { x = %d }\n", this->x);
}
