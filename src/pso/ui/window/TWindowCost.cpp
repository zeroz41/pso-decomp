#include "types.h"
#include "pso/ui/window/TWindowCost.h"


extern "C" {

void *TWindowCost__ct(void *arg0);
void TWindowMeseta__ct(void *);
void get_item_count__24TShopEquipmentSellWindowFv(void *, int);

extern s32 __vt__11TWindowCost[];

}
TWindowCost::~TWindowCost() {

}


extern void *TWindowCost__class_name;

void *TWindowCost__ct(void *arg0) {
    TWindowMeseta__ct(arg0);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__11TWindowCost;
    *(void * *)&((TWindowCost *)arg0)->m_name = TWindowCost__class_name;
    get_item_count__24TShopEquipmentSellWindowFv(arg0, 0);
    return arg0;
}

