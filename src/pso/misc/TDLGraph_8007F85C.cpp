#include "types.h"
#include "pso/unk/text_8007F8D0.h"
#include "pso/misc/TDLGraph.h"
#include "pso/ui/TAdDialingGC.h"

extern "C" {
extern void *lbl_8048DF94[];
void *__nw__7TObjectFUl(int);

extern void *tl_clipout;

void *TDLGraph::create() {
    void *o = __nw__7TObjectFUl(0x64);
    if (o != NULL) {
        o = TDLGraph__ct((TDLGraph *)o, (TObject *)tl_clipout);
    }
    return o;
}
void TAdDialingGC::select_dial_image(void *self, s32 x) {
    launch_switcher_dol((const char *)lbl_8048DF94[x ? 1 : 0]);
}

}
