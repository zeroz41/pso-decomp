#include "types.h"
#include "pso/ui/charcreate/TChCrCharSelect.h"

    extern int TChCrCharSelect__selected_char_index;
int TChCrCharSelect::get_selected_char() {  return TChCrCharSelect__selected_char_index; }

    extern int TChCrCharSelect__selected_slot_index;
int TChCrCharSelect::get_instance() {  return TChCrCharSelect__selected_slot_index; }
