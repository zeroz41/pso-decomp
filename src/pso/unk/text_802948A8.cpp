#include "types.h"
#include "pso/ui/charcreate/TObjCMHexTile.h"
#include "pso/unk/text_802948A8.h"
#include "pso/system/task/TMainTask.h"

void *create_TObjCMHexTile(void *pos) {
    void *o = (void *)new TObjCMHexTile(tl_07, pos);
    return o;
}
