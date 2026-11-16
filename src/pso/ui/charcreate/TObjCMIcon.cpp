#include "types.h"
#include "pso/ui/charcreate/TObjCMIcon.h"

extern "C" {


void *TObjCMIcon::create(void *object) {
    return new TObjCMIcon((TObject *)object);
}

}
