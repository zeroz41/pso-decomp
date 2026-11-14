#ifndef PSO_OBJECT_DOOR_TODOORFOURLIGHTSEABEDU_H
#define PSO_OBJECT_DOOR_TODOORFOURLIGHTSEABEDU_H

#include "types.h"
#include "pso/object/door/TODoorFourLightBase.h"

struct TODoorFourLightSeabedU : public TODoorFourLightBase {
    virtual ~TODoorFourLightSeabedU();
    virtual s32 vfunc_21();
    virtual s32 vfunc_22();
};
typedef char TODoorFourLightSeabedU_size[sizeof(TODoorFourLightSeabedU) == 0xFC ? 1 : -1];

#endif
