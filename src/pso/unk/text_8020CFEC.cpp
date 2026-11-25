#include "pso/object/base/TObjMotion.h"
#include "pso/map/FloorPopulation.h"
#include "pso/object/base/ObjectFactoryTables.h"
#include "pso/map/FloorArea.h"

#include "types.h"
#include "pso/object/base/TObjCharaHelpers.h"


extern "C" {
typedef ObjectFactoryFunction Fn_8020CFEC;
typedef ObjectFactoryEntry Ent_8020CFEC;
TObjBase *call_area_set_factory(TSetManager *, FloorObjectSetRow *row) {
    ObjectFactoryFunction factory = floor_object_factory_tables[get_current_floor_area()][row->type].create;
    if (factory != NULL) {
        return static_cast<TObjBase *>(factory(&row->placement));
    }
    return NULL;
}

typedef s32 (*Fn_8020D054)(void *);
struct CreateSetObjectFromRowOut { s32 a; Fn_8020D054 fn; };
struct CreateSetObjectFromRowMsg { s16 id; s16 pad; u8 data[1]; };
s32 find_set_factory_index(void *, void *);
s32 create_set_object_from_row(CreateSetObjectFromRowMsg *row) {
    CreateSetObjectFromRowOut o;
    if (row->id != -1 && find_set_factory_index(row, &o) >= 0) {
        return o.fn(row->data);
    }
    return 0;
}

}
