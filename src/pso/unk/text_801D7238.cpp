#include "types.h"
#include "pso/unk/TLobby.h"
struct Obj_801D7238 { u8 v; };

extern "C" {
u8 TItemDrop__sub_80107B04(Obj_801D7238 *p);
u8 TLobby::get_rule_field_0() {
    Obj_801D7238 *p = (Obj_801D7238 *)this;
    if (p->v >= 2) {
        return TItemDrop__sub_80107B04(p);
    }
    return p->v;
}

}
