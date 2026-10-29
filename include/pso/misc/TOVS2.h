#ifndef PSO_MISC_TOVS2_H
#define PSO_MISC_TOVS2_H
#include "types.h"
#include "pso/object/TObjMapObject.h"

// The base of the VS2 wreck objects (TOVS2Wreck01-06): one model of the
// VS2 resource with its collision body and a map-collision object.
class TOVS2 : public TObjMapObject {
public:
    TOVS2(void *set_data, s32 index);
    virtual ~TOVS2();
    virtual void render();
    s32 m_c8;  // the map-collision object TObjMapCsn::create made for it
    s32 m_cc;  // the last update_object_view_visibility result
};

typedef char TOVS2Size[sizeof(TOVS2) == 0xD0 ? 1 : -1];

// The derived constructors and destructors still written out by hand call
// these by their symbols.
extern "C" void *__ct__5TOVS2FPvl(void *self, void *set_data, s32 index);
extern "C" void *__dt__5TOVS2Fv(void *self, s16 del);

#endif
