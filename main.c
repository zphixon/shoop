#include <assert.h>
#include <dlfcn.h>

#include "object_maker.h"

int main() {
    object obj; make_object(&obj);

    obj.setX(3);
    debug_object(&obj);
    assert(obj.getX() == 3);

    object obj2; make_object(&obj2);
    obj2.setX(4);
    debug_object(&obj2);
    assert(obj.getX() != obj2.getX());
}
