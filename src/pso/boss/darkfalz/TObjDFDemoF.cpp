#include "types.h"
#include "pso/boss/darkfalz/TObjDFDemoF.h"
#include "pso/system/task/TObject.h"

extern "C" {

void *__ct__11TObjDFDemoFFP7TObject(void *, void *);

void *TObjDFDemoF::create(void *arg0) {
    void *o = TObject::operator new(0xBC);
    if (o != NULL) {
        o = __ct__11TObjDFDemoFFP7TObject(o, arg0);
    }
    return o;
}

}
