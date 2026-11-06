#include "types.h"
#include "pso/ui/TChCrCharSelect.h"

extern "C" {

int create__15TChCrCharSelectFPv(void);

    extern int TChCrCharSelect__selected_char_index;
    extern int TChCrCharSelect__selected_slot_index;
void TChCrCharSelect::init_and_create() { TChCrCharSelect__selected_char_index = -1; TChCrCharSelect__selected_slot_index = -1; create__15TChCrCharSelectFPv(); }

}
