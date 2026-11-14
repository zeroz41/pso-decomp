#ifndef PSO_OBJECT_DOOR_TODOORLABO_H
#define PSO_OBJECT_DOOR_TODOORLABO_H

#include "types.h"
#include "pso/object/door/TODoorFourLightBase.h"

struct TODoorLabo : public TODoorFourLightBase {
    virtual ~TODoorLabo();
    virtual s32 vfunc_21();
    virtual s32 vfunc_22();
    void init_model_by_type();
    static void free_resources();
    static void load_resources();
};

typedef char TODoorLabo_size[sizeof(TODoorLabo) == 0xFC ? 1 : -1];

extern "C" {
void TLanguage__sub_8029FF0C(void);
u8 *TODoorFourLightSeabedU__ct(u8 *arg0, void *parent, s32 arg);
u8 *TODoorFourLightSeabed__ct(u8 *arg0, void *parent, s32 arg);
}
void load_labo_door_resources(void);

#endif
