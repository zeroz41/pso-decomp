#include "types.h"
#include "pso/ui/ItemListRow.h"
#include "pso/ui/window/TWindowMenuIconLine.h"

extern "C" {


void TWindowMenuIconLine::add_list_entry(u8 icon, s32 arg2, s32 arg3) {
    if (this->entry_count < this->entry_capacity) {
        ((ItemListRow *)get_array_entry(entry_count))->init_list_entry(icon, arg2, arg3);
        this->entry_count = (this->entry_count + 1);
    }
}

}
