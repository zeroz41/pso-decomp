#include "types.h"
#include "pso/ui/charcreate/TChCrEffTag.h"
#include "pso/ui/charcreate/TChCrEffTagStr.h"

void *TChCrEffTag::create_str(void *arg0, void *arg1, void *arg2) {
    return new TChCrEffTagStr((TObject *)arg0, arg1, arg2);
}
