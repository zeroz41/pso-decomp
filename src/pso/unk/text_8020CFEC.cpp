#include "pso/object/ObjectFactoryTables.h"

#include "types.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/map/CurrentArea.h"

extern "C" {
typedef ObjectFactoryFunction Fn_8020CFEC;
typedef ObjectFactoryEntry Ent_8020CFEC;
struct Msg_8020CFEC { s16 id; s16 pad; u8 data[1]; };
s32 call_area_set_factory(s32 arg0, Msg_8020CFEC *arg1) {
    Fn_8020CFEC f = floor_object_factory_tables[get_current_area()][arg1->id].create;
    if (f != 0) {
        return (s32) f(arg1->data);
    }
    return 0;
}

typedef s32 (*Fn_8020D054)(void *);
struct Out_8020D054 { s32 a; Fn_8020D054 fn; };
struct Msg_8020D054 { s16 id; s16 pad; u8 data[1]; };
s32 find_set_factory_index(void *, void *);
s32 create_set_object_from_row(Msg_8020D054 *row) {
    Out_8020D054 o;
    if (row->id != -1 && find_set_factory_index(row, &o) >= 0) {
        return o.fn(row->data);
    }
    return 0;
}

}
