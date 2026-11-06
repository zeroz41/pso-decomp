#include "types.h"
#include "pso/menu/CreationInput.h"
#include "pso/ui/TChCrCharSelect.h"
#include "pso/object/TObjCMProportion.h"


void TChCrCharSelect::reset_proportions() { TObjCMProportion::poll_pad_buttons(); update_creation_direction_repeat(); }

