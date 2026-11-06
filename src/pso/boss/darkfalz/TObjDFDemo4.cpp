#include "types.h"
#include "pso/boss/darkfalz/TObjDFDemo4.h"

extern "C" {

void *TObjDFDemo4__ct(void *, void *, void *, void *);
void *__nw__7TObjectFUl(int);

void *TObjDFDemo4::create(void *arg0, void *arg1, void *arg2) {
    void *o;
    o = __nw__7TObjectFUl(0x11C);
    if (o != NULL) {
        o = TObjDFDemo4__ct(o, arg0, arg1, arg2);
    }
    return o;
}

}
