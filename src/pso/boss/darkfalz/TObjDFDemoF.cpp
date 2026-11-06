#include "types.h"
#include "pso/boss/darkfalz/TObjDFDemoF.h"

extern "C" {

void *TObjDFDemoF__ct(void *, void *);
void *__nw__7TObjectFUl(int);

void *TObjDFDemoF::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xBC);
    if (o != NULL) {
        o = TObjDFDemoF__ct(o, arg0);
    }
    return o;
}

}
