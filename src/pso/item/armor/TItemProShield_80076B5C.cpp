#include "types.h"
#include "pso/item/armor/TItemProShield_80076B5C.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/item/TUnk_804CC048.h"

extern "C" {

void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);

s16 TItemProShield::get_field_2b8() { return *(s16*)((char*)this + 0x2b8); }

}

TUnk_804CC048::~TUnk_804CC048() {}
