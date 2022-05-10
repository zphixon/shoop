#include <assert.h>
#include "object_impl.h"

static object* this;
static int already_linked;

int getX() {
    return this->x;
}

void setX(int x) {
    this->x = x;
}

void make_object(object* this_, void* handle) {
    assert(!already_linked);
    already_linked = 1;

    this = this_;
    this->handle = handle;
    this->getX = getX;
    this->setX = setX;

    this->x = 0;
}

