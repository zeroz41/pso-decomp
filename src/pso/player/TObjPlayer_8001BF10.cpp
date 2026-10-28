#include "types.h"
#include "pso/system/FlagWord.h"

FlagWord::FlagWord() { reset(); }

void FlagWord::reset() { bits = 0; }
