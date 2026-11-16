#include "types.h"
#include "pso/ui/charcreate/TChCrCharSelect.h"


void *TChCrCharSelect::create(void *object) {
    return new TChCrCharSelect((TObject *)object);
}

