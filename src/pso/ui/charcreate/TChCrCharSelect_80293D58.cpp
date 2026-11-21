#include "types.h"
#include "pso/ui/charcreate/TChCrCharSelect.h"

extern "C" {

    extern int TChCrCharSelect__selected_char_index;
    extern int TChCrCharSelect__selected_slot_index;
void TChCrCharSelect::init_and_create(TObject *parent) {
    TChCrCharSelect__selected_char_index = -1;
    TChCrCharSelect__selected_slot_index = -1;
    create(parent);
}

}
