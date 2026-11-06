#include "types.h"
#include "pso/unk/text_8007F8D0.h"
#include "pso/render/TDLGraph.h"
#include "pso/ui/frontend/TAdDialingGC.h"

extern "C" {
extern void *lbl_8048DF94[];

extern void *tl_clipout;

void *TDLGraph::create() {
    return new TDLGraph((TObject *)tl_clipout);
}
void TAdDialingGC::select_dial_image(void *self, s32 x) {
    launch_switcher_dol((const char *)lbl_8048DF94[x ? 1 : 0]);
}

}
