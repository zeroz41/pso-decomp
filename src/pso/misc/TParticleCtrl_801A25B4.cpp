#include "types.h"
#include "pso/object/TObjMotion.h"

TUnk_804B9870::~TUnk_804B9870() {
    if (set_entry != NULL) {
        u16 id = entity_id;
        if (id >= 0x4000 && id < 0xFFFF) {
            mask_object_set_row_flags(-3);
            set_entry = NULL;
        }
    }
}
