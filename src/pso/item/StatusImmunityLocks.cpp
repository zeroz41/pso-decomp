#include "types.h"
#include "pso/item/StatusImmunityLocks.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/item/TItemLockCountCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer.h"

// The lock-counted item effects (TItemLockCountCtrl objects), one per effect.
TItemLockCountCtrl *item_effect_object_table[7];

// Releases client's hold on item effect `effect`; the last release stops it.
void unlock_effect(u16 client, u32 effect) {
    TItemLockCountCtrl *ctrl;
    if ((client < 12) && (effect < 7)) {
        ctrl = item_effect_object_table[effect];
        if (ctrl != NULL) {
            ctrl->unlock(client);
        }
    }
}

// Takes a hold on item effect `effect` for client; the first hold starts it.
void lock_effect(u16 client, u32 effect) {
    TItemLockCountCtrl *ctrl;
    if ((client < 12) && (effect < 7)) {
        ctrl = item_effect_object_table[effect];
        if (ctrl != NULL) {
            ctrl->lock(client);
        }
    }
}


void remove_freeze_immunity(int client) {
    TObjPlayer *player = get_player_by_client_id((u16)client);
    if (player != NULL) {
        player->remove_immunity_flags(0x20);
    }
}

void remove_confusion_immunity(int client) {
    TObjPlayer *player = get_player_by_client_id((u16)client);
    if (player != NULL) {
        player->remove_immunity_flags(0x10);
    }
}


void remove_slow_immunity(int client) {
    TObjPlayer *player = get_player_by_client_id((u16)client);
    if (player != NULL) {
        player->remove_immunity_flags(8);
    }
}

void remove_shock_immunity(int client) {
    TObjPlayer *player = get_player_by_client_id((u16)client);
    if (player != NULL) {
        player->remove_immunity_flags(4);
    }
}

void remove_paralysis_immunity(int client) {
    TObjPlayer *player = get_player_by_client_id((u16)client);
    if (player != NULL) {
        player->remove_immunity_flags(2);
    }
}

void remove_poison_immunity(int client) {
    TObjPlayer *player = get_player_by_client_id((u16)client);
    if (player != NULL) {
        player->remove_immunity_flags(1);
    }
}

void remove_status_cleanse(int client) {
    TObjPlayer *player = get_player_by_client_id((u16)client);
    if (player != NULL) {
        player->clear_actor_flags(0x40);
    }
}

void add_freeze_immunity(int client) {
    TObjPlayer *player = get_player_by_client_id((u16)client);
    if (player != NULL) {
        player->add_immunity_flags(0x20);
    }
}

void add_confusion_immunity(int client) {
    TObjPlayer *player = get_player_by_client_id((u16)client);
    if (player != NULL) {
        player->add_immunity_flags(0x10);
    }
}

void add_slow_immunity(int client) {
    TObjPlayer *player = get_player_by_client_id((u16)client);
    if (player != NULL) {
        player->add_immunity_flags(8);
    }
}

void add_shock_immunity(int client) {
    TObjPlayer *player = get_player_by_client_id((u16)client);
    if (player != NULL) {
        player->add_immunity_flags(4);
    }
}

void add_paralysis_immunity(int client) {
    TObjPlayer *player = get_player_by_client_id((u16)client);
    if (player != NULL) {
        player->add_immunity_flags(2);
    }
}

void add_poison_immunity(int client) {
    TObjPlayer *player = get_player_by_client_id((u16)client);
    if (player != NULL) {
        player->add_immunity_flags(1);
    }
}

void add_status_cleanse(int client) {
    TObjPlayer *player = get_player_by_client_id((u16)client);
    if (player != NULL) {
        player->set_actor_flags(0x40);
    }
}
void free_all() {
    s32 i;
    for (i = 0; i != 7; i++) {
        delete item_effect_object_table[i];
        item_effect_object_table[i] = 0;
    }
}
void TItemLockCountCtrl::init_effect_table() {
    item_effect_object_table[0] = new TItemLockCountCtrl(0, 0xC, add_status_cleanse, remove_status_cleanse);
    item_effect_object_table[1] = new TItemLockCountCtrl(0, 0xC, add_poison_immunity, remove_poison_immunity);
    item_effect_object_table[2] = new TItemLockCountCtrl(0, 0xC, add_paralysis_immunity, remove_paralysis_immunity);
    item_effect_object_table[3] = new TItemLockCountCtrl(0, 0xC, add_shock_immunity, remove_shock_immunity);
    item_effect_object_table[4] = new TItemLockCountCtrl(0, 0xC, add_slow_immunity, remove_slow_immunity);
    item_effect_object_table[5] = new TItemLockCountCtrl(0, 0xC, add_confusion_immunity, remove_confusion_immunity);
    item_effect_object_table[6] = new TItemLockCountCtrl(0, 0xC, add_freeze_immunity, remove_freeze_immunity);
}
