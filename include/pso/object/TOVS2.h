#ifndef PSO_OBJECT_TOVS2_H
#define PSO_OBJECT_TOVS2_H
#include "types.h"
#include "pso/object/base/TObjMapObject.h"

struct TObjMapCsn;

// The base of the VS2 wreck objects (TOVS2Wreck01-06): one model of the
// VS2 resource with its collision body and a map-collision object.
class TOVS2 : public TObjMapObject {
public:
    TOVS2(void *set_data, s32 index);
    virtual ~TOVS2();
    virtual void render();
    TObjMapCsn *m_c8;  // the map-collision object TObjMapCsn::create made for it
    s32 m_cc;  // the last update_object_view_visibility result
};

LAYOUT_ASSERT(TOVS2Size, sizeof(TOVS2) == 0xD0);

#endif
