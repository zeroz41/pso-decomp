#include "types.h"
#include "pso/unk/text_802C095C.h"
#include "pso/object/TUnk_804E0898.h"
#include "pso/system/task/TMainTask.h"


void *create_lobby_pigeon(void *source) {
    return new TUnk_804E0898(tl_05, source);
}

