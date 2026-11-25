#include "types.h"
#include "pso/network/TLobby.h"
#include "pso/item/drop/TItemDrop.h"
struct GetRuleField0Object { u8 v; };

extern "C" {
u8 TLobby::get_rule_field_0() {
    GetRuleField0Object *p = (GetRuleField0Object *)this;
    if (p->v >= 2) {
        return TItemDrop__sub_80107B04(p);
    }
    return p->v;
}

}
