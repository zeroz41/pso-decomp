#include "types.h"
#include "pso/misc/TUnk_804EFA88.h"
#include "pso/misc/TLobby_8033ECB0.h"
#include "pso/ui/TAdMcCheckGC.h"
#include "pso/misc/TLobby.h"
#include "pso/player/TObjPlayer.h"


struct RecoveredGlobal_8033ED24_lbl_804EFA88
{
  s32 value;
  u8 remaining[0x14];
};

extern "C" {
s32 lbl_805D6DA0;
void *mem_alloc(u32 size);
s32 __ct__7TObjectFP7TObject();
extern s32 __vt__13TUnk_804EFA88[];
void mem_free(void *p);

}
TUnk_804EFA88::~TUnk_804EFA88() {
    if ((u32) *(u32 *)((s8 *)this + 0x1C) != 0U) {
        mem_free(*(void **)((s8 *)this + 0x1C));
    }
    lbl_805D6DA0 = 0;
}


typedef struct RecoveredGlobal_8033ED24_lbl_804EFA88 RecoveredGlobal_8033ED24_lbl_804EFA88;
typedef char RecoveredGlobal_8033ED24_lbl_804EFA88_size[((sizeof(RecoveredGlobal_8033ED24_lbl_804EFA88)) == 0x18) ? (1) : (-1)];
u8 *TLobby__sub_8033ED24(u8 *arg0) {
  s32 var_r31;
  s32 var_r30;
  __ct__7TObjectFP7TObject();
  *((s32 **) (((s8 *) arg0) + 0x18)) = &(*(RecoveredGlobal_8033ED24_lbl_804EFA88 *)&__vt__13TUnk_804EFA88).value;
  ((TUnk_804EFA88 *)arg0)->m_20 = 0;
  *((s32 *) (((s8 *) arg0) + 0x1C)) = (s32)mem_alloc((u32)((void *) 0x240));
  if (((u32) (*((s32 *) (((s8 *) arg0) + 0x1C)))) != 0U)
  {
    var_r30 = 0;
    var_r31 = 0;
    do
    {
      TLobby__sub_8033EE38((void *)((*((s32 *) (((s8 *) arg0) + 0x1C))) + var_r31));
      var_r30 += 1;
      var_r31 += 0x24;
    }
    while (var_r30 < 0x10);
  }
  (*(u8 * *)&lbl_805D6DA0) = arg0;
  return arg0;
}

void TLobby::release_indexed_entry(s32 arg0) {
    if (((void *) (*(u8 * *)&lbl_805D6DA0) != NULL) && ((s32) *(s32 *)((s8 *)(*(u8 * *)&lbl_805D6DA0) + 0x20) < 0x10)) {
        ((TObjPlayer *)(*(u8 * *)&lbl_805D6DA0))->free_indexed_entry(arg0);
        *(s32 *)((s8 *)(*(u8 * *)&lbl_805D6DA0) + 0x20) = (s32) (*(s32 *)((s8 *)(*(u8 * *)&lbl_805D6DA0) + 0x20) + 1);
    }
}

void TLobby__sub_8033EDF8(void) { lbl_805D6DA0 = 0; }

void TLobby__sub_8033EE04(void) { lbl_805D6DA0 = 0; }

