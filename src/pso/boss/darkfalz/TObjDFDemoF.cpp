#include "types.h"
#include "pso/boss/darkfalz/TObjDFDemoF.h"
#include "pso/system/task/TObject.h"

extern "C" {

void *TObjDFDemoF__ct(void *, void *);

void *TObjDFDemoF::create(void *arg0) {
    void *o = TObject::operator new(0xBC);
    if (o != NULL) {
        o = TObjDFDemoF__ct(o, arg0);
    }
    return o;
}

}
