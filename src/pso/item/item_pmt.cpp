#include "pso/system/task/TObject.h"
#include "pso/item/drop/TItemDrop_80105D0C.h"
#include "pso/item/TItemLoad_8010FDF0.h"
#include "pso/item/item_pmt.h"
#include "types.h"
#include "pso/item/TItemLoad.h"

extern "C" void*    item_pmt;
extern "C" void*    item_pmt_tbl;
extern "C" TObject* item_mgr;

extern "C" char* const item_pmt_filename_descriptor;


void free_item_pmt() {
    delete (RelocatedFile *)item_pmt;
    item_pmt = NULL;
    item_pmt_tbl = NULL;
}

void unload_items() {
    delete item_mgr;
    item_mgr = NULL;
    free_item_pmt();
}

void load_item_pmt() {
    RelocatedFile *p = new RelocatedFile(item_pmt_filename_descriptor, 0x10000);
    item_pmt = p;
    if (p != NULL) {
        item_pmt_tbl = ((RelocatedFile *)p)->get_root();
    }
}

void load_items() {
    load_item_pmt();
    item_mgr = (TObject *)create_drop__9TItemDropFi(0);
}
