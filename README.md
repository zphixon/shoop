# shoop

*shared-object-oriented programming*

todo: inheritance/subclassing

```c
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
```
