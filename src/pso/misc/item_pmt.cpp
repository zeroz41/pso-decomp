#include "pso/TObject.h"
#include "pso/item/TItemDrop_80105D0C.h"
#include "pso/item/TItemLoad_8010FDF0.h"
#include "pso/misc/item_pmt.h"
#include "types.h"
#include "pso/TItemLoad.h"

extern "C" void*    item_pmt;
extern "C" void*    item_pmt_tbl;
extern "C" TObject* item_mgr;

extern "C" char* const item_pmt_filename_descriptor;

extern "C" void*    get_type__8TItemMagFv(void* pmt);

void free_item_pmt() {
    __dt__9TItemLoadFPvs((s32 *)item_pmt, 1);
    item_pmt = NULL;
    item_pmt_tbl = NULL;
}

void unload_items() {
    delete item_mgr;
    item_mgr = NULL;
    free_item_pmt();
}

void load_item_pmt() {
    void* p = ::operator new(8);
    if (p != NULL) {
        p = ((TItemLoad *)p)->load_buffer((u32)item_pmt_filename_descriptor, 0x10000);
    }
    item_pmt = p;
    if (p != NULL) {
        item_pmt_tbl = get_type__8TItemMagFv(p);
    }
}

void load_items() {
    load_item_pmt();
    item_mgr = (TObject *)create_drop__9TItemDropFi(0);
}
