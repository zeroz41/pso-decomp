#include "types.h"
#include "pso/item/TUnk_804B97C0.h"
#include "pso/object/TObjMotion.h"
#include "pso/item/TUnk_804B97C0.h"
#include "pso/item/TObjContainerIdo.h"

extern "C" {
int __ct__14TObjCollidableFP7TObject(void);
extern s32 __vt__13TUnk_804B97C0[];
void __dl__7TObjectFPv(void *);

}
TUnk_804B97C0::~TUnk_804B97C0() {

}
extern "C" {
void*TUnk_804B97C0::init_positions() { __ct__14TObjCollidableFP7TObject(); *(int*)((char*)this + 0x18) = (int)((unsigned char *)&__vt__13TUnk_804B97C0); *(float *)&this->unk_AC = 400.0f; this->m_b0 = 10.0f; return this; }

}
