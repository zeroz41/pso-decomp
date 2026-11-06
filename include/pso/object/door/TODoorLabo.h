#ifndef PSO_OBJECT_DOOR_TODOORLABO_H
#define PSO_OBJECT_DOOR_TODOORLABO_H

#include "types.h"
#include "pso/object/door/TODoorFourLightBase.h"

struct TODoorLabo : public TODoorFourLightBase {
    virtual ~TODoorLabo();
    void init_model_by_type();
    static void free_resources();
    static void load_resources();
};

typedef char TODoorLabo_size[sizeof(TODoorLabo) == 0xFC ? 1 : -1];

extern "C" {
void TLanguage__sub_8029FF0C(void);
u8 *TODoorFourLightSeabedU__ct(u8 *arg0);
s32 TODoorFourLightSeabedU__vt19(void);
s32 TODoorFourLightSeabedU__vt20(void);
u8 *TODoorFourLightSeabed__ct(u8 *arg0);
s32 TODoorFourLightSeabed__vt19(void);
s32 TODoorFourLightSeabed__vt20(void);
s32 TODoorLaboNormal__vt19(void);
s32 TODoorLaboNormal__vt20(void);
s32 TODoorLabo__vt19(void);
s32 TODoorLabo__vt20(void);
void *__dt__10TODoorLaboFv(void *arg0, s16 arg1);
void *__dt__16TODoorLaboNormalFv(void *arg0, s16 arg1);
void *__dt__21TODoorFourLightSeabedFv(void *arg0, s16 arg1);
void *__dt__22TODoorFourLightSeabedUFv(void *arg0, s16 arg1);
}
void load_labo_door_resources(void);

#endif
