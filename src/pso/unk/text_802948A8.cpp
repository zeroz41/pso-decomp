#include "types.h"
#include "pso/ui/charcreate/TObjCMHexTile.h"
#include "pso/unk/text_802948A8.h"

extern void *tl_07;

void *create_TObjCMHexTile(void *pos) {
    void *o = (void *)new TObjCMHexTile((TObject *)tl_07, pos);
    return o;
}
