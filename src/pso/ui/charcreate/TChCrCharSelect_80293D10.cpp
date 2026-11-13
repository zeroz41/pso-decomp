#include "types.h"
#include "pso/ui/charcreate/TChCrCharSelect.h"

extern "C" {

void *TChCrCharSelect::create(void *object) {
    return new TChCrCharSelect((TObject *)object);
}

}
