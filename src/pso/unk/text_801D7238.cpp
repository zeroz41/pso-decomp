#include "types.h"
#include "pso/network/LobbyRuleSettings.h"
#include "pso/item/drop/TItemDrop.h"

u8 LobbyRuleSettings::get_rule_field_0() {
    if (rules_active >= 2) {
        return TItemDrop__sub_80107B04(this);
    }
    return rules_active;
}
