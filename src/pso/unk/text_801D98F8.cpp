#include "types.h"
struct SetTechniqueLevelEntryObject { u8 pad[0x48]; u8 arr[1]; };

extern "C" {
void set_technique_level_entry(SetTechniqueLevelEntryObject *p, s16 i, u8 v);
void set_technique_level_entry(SetTechniqueLevelEntryObject *p, s16 i, u8 v) {
    p->arr[i] = v;
}

}
