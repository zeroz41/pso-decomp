#include "types.h"
#include "pso/ui/charcreate/TChCrTagName.h"
#include "pso/ui/charcreate/TChCrTagOccupation.h"
#include "pso/ui/charcreate/TChCrCharSelect.h"
#include "pso/ui/charcreate/TChCrTagPlBack.h"
#include "pso/ui/charcreate/TChCrTagPlGraphic.h"
#include "pso/ui/charcreate/TChCrTagInformation.h"

void TChCrCharSelect::init_widgets() { TChCrTagOccupation::create_all(); create_all__12TChCrTagNameFv(); create_all_ch_cr_tag_headers(); TChCrTagPlBack::create_default(); TChCrTagPlGraphic::create_matching_tags(); TChCrTagInformation::create_default(); }
