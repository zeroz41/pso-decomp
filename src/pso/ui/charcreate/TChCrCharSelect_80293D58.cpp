#include "types.h"
#include "pso/ui/charcreate/TChCrCharSelect.h"


void TChCrCharSelect::init_and_create(TObject *parent) {
    TChCrCharSelect::selected_char_index = -1;
    TChCrCharSelect::selected_slot_index = -1;
    create(parent);
}

