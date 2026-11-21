#include "types.h"
#include "pso/boss/darkfalz/TObjDFDemoF.h"
#include "pso/system/task/TObject.h"

extern "C" {

TObjDFDemoF *__ct__11TObjDFDemoFFP7TObject(TObjDFDemoF *demo, TObject *parent);

TObjDFDemoF *TObjDFDemoF::create(TObject *parent) {
    TObjDFDemoF *o = (TObjDFDemoF *)TObject::operator new(sizeof(TObjDFDemoF));
    if (o != NULL) {
        o = __ct__11TObjDFDemoFFP7TObject(o, parent);
    }
    return o;
}

}
