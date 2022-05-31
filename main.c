#include <assert.h>

// just include your class header
#include "object.h"

int main() {
    // make an instance of your class
    object obj;
    make_object(&obj);

    // send it messages (call its methods)
    obj.setX(3);
    debug_object(&obj);
    assert(obj.getX() == 3);

    // maybe make another one?
    object obj2;
    make_object(&obj2);

    // do something different
    obj2.setX(4);
    debug_object(&obj2);

    // as expected
    assert(obj.getX() != obj2.getX());

    // don't forget to clean up your memory!
    free_object(&obj);
    free_object(&obj2);
}


// How it works:
//
// Normal languages do the familiar `x.y()` syntax by transforming that method
// call into a function call `y(&x)` (or `y(x)` by value). Since we can't do
// anything that fancy in C automatically, we instead put the object's vtable
// into itself and use a variable marked `static` to store the pointer to
// `this`, so that y is a function pointer member of x, and in the body of y,
// `this` refers to a global variable.
//
// This becomes a problem if we want to instantiate more than one member of our
// class. Obviously we want to keep our nice clean syntax of `x.y()`, so we
// can't take the Rust approach and define some struct to hold on to our state
// in order to fake a closure. Instead, we can compile our class as a shared
// library and dlmopen(3) it every time we want a new instance, so that the
// function pointers stored in x in different instances refer to separate
// shared libraries.
//
// According to man 3, "dlmopen() differs from dlopen() primarily in that it
// accepts an additional argument, lmid, that specifies the link-map list (also
// referred to as namespace) in which the shared object should be loaded. (By
// comparison, dlopen() adds the dynamically loaded shared object to the same
// namespace as the shared object from which the dlopen() call is made.)"
