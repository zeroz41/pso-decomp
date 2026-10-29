#include "types.h"
#include "pso/misc/TODoorAncient01.h"
#include "pso/unk/TUnk_804B0BB8.h"

extern "C" {

void* init_door_base(void* a0);
int __ct__13TUnk_804AFBF8FP7TObject(void);

    extern unsigned char lbl_804B0BB8[];
    extern const float lbl_805DB3DC;
void* init_door_base(void* a0) { __ct__13TUnk_804AFBF8FP7TObject(); *(int*)((char*)a0 + 0x18) = (int)lbl_804B0BB8; *(int*)((char*)a0 + 0xc8) = -1; ((TUnk_804B0BB8 *)a0)->m_cc = 0; ((TUnk_804B0BB8 *)a0)->m_d0 = 0; ((TUnk_804B0BB8 *)a0)->m_ac = 0; ((TUnk_804B0BB8 *)a0)->m_b8 = lbl_805DB3DC; return a0; }

void TUnk_804B0BB8::vfunc_20() {  }
void TODoorAncient01::vfunc_20() {  }

}
