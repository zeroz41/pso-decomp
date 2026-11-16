#include "types.h"
#include "pso/ui/charcreate/TObjCMIcon.h"


void *TObjCMIcon::create(void *object) {
    return new TObjCMIcon((TObject *)object);
}

