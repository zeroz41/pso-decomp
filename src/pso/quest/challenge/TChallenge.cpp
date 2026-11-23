#include "types.h"
#include "pso/quest/challenge/TChallenge.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

void *TChallenge::create() {
    return new TChallenge(tl_su);
}
