#include "pso/network/protocol/protocol_types.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/render/render_util.h"
#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/object/warp/TObjWarpBossMulti.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/PlayerActionProvider.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerActionPaletteState.h"
#include "pso/player/TObjPlayerActions.h"
#include "pso/player/PlayerAttackController.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/effect/enemy/TObjEneHoldEffect.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/ui/font/TFontSmallLobby.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/network/TLobby.h"
#include "pso/ui/hud/TLockOnCursor.h"
#include "pso/ui/hud/TMainCursor.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/technique/TTecLuker.h"
#include "pso/technique/TTecReverser.h"
#include "pso/ui/window/TWindowActionPalette.h"
#include "pso/item/TItem.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/map/FloorArea.h"
#include "pso/map/FloorMapSelection.h"
#include "pso/math/AngleLookup.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/item/TItemTimerEvent.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/object/base/TObjBase.h"
#include "pso/system/vector.h"
#include "pso/object/base/CollisionActorLookup.h"

#pragma readonly_strings on

void CapturedTargetList::clear_lockon_list() {
    s32 i;
    CapturedTarget *entry = entries;
    count = 0;
    for (i = 0; i < 10; i++) {
        entry->clear();
        entry++;
    }
}

void PlayerAttackController::advance_and_clamp_state() {
    if (++pending_stage > 2) {
        set_saved_attack_stage(2);
    }
}

s16 PlayerAttackController::get_validated_attack_stage() {
    s16 stage = pending_stage;
    if (is_valid_attack_stage(stage) == 0) {
        stage = 0;
    }
    return stage;
}

s32 is_valid_attack_stage(s16 stage) {
    if ((stage < 0) || (stage >= 3)) {
        return 0;
    }
    return 1;
}

s16 PlayerAttackController::get_validated_queued_kind() {
    s16 kind;
    kind = queued_kind;
    if (is_valid_attack_kind(kind) == 0) {
        kind = 0;
    }
    return kind;
}

s16 PlayerAttackController::get_validated_attack_kind() {
    s16 kind;
    kind = attack_kind;
    if (is_valid_attack_kind(kind) == 0) {
        kind = 0;
    }
    return kind;
}

s32 is_valid_attack_kind(s16 kind) {
    if ((kind < 0) || (kind >= 3)) {
        return 0;
    }
    return 1;
}

void PlayerAttackController::queue_physical_attack_input(TObjPlayer *player, s32 channel, s16 maximum_stage) {
    s16 kind;
    if (get_flags()->test_flags_any(2) == 0 || is_flag32_clear() == 0) {
        get_flags()->set(4);
    }
    if (get_flags()->test_flags_any(2) != 0 && get_flags()->test_flags_any(4) == 0) {
        get_flags()->set(1);
        advance_and_clamp_state();
        if (get_validated_attack_stage() > maximum_stage) {
            set_saved_attack_stage(maximum_stage);
        }
        kind = player->get_action_palette_entry(channel);
        player->set_action_palette_state_mode(2);
        set_queued_kind(kind);
        TWindowCtrl::dispatch_to_child((u16)player->get_entity_id(), channel);
    }
}

s32 PlayerAttackController::tick_burst_recovery() {
    if (flags.test_flags_any(8) != 0) {
        return tick_recovery_timer();
    }
    return 0;
}

s32 PlayerAttackController::tick_recovery_timer() {
    s32 remaining;

    remaining = recovery_timer - 1;
    recovery_timer = remaining;
    if (remaining < 0) {
        flags.set(1);
        return 1;
    }
    return 0;
}

void PlayerAttackController::register_strike(TObjPlayer *player) {
    flags.set(2);
    recovery_timer = (s32)player->get_attack_recovery_count();
    player->clear_flag_128();
}

void PlayerAttackController::begin(TObjPlayer *player, s32 stage, s32 begun) {
    set_saved_attack_stage(stage);
    begun_stage = begun;
    hit_count = 0;
    burst_count = 0;
    flags.clear(0x1F);
    recovery_timer = 6;
    attack_speed = evp_scale;
    if (attack_kind) {
        attack_speed *= 1.25f;
    }
}

s32 PlayerAttackController::get_first_target_position(Vec *out) {
    CapturedTarget *target = get_first_target();
    u16 uid = target->get_uid();
    TObjCollidable *actor;
    if (uid == 0xFFFF) {
        return 0;
    }
    actor = find_entity_by_id(uid);
    if (actor == NULL) {
        return 0;
    }
    VecCopy(out, &actor->bodies[target->collider_index].center);
    return 1;
}

CapturedTargetList *PlayerAttackController::capture_lockon_targets(TObjPlayer *player) {
    LockOnActionSlot *slot;
    s32 count;
    CapturedTarget *entry;
    s32 i;
    LockOnTargetRecord *record;
    if (player->lock_on_cursor == 0) return 0;
    lockon_targets.clear_lockon_list();
    slot = player->find_palette_lockon_slot();
    if (slot == 0) return 0;
    if (get_cursor_palette_mode(slot) != 2) return 0;
    lock_range = slot->lock_range;
    horizontal_cone_cos = slot->horizontal_cone_cos;
    vertical_cone_cos = slot->vertical_cone_cos;
    cone_apex_offset = slot->cone_apex_offset;
    count = slot->target_records.get_count();
    entry = lockon_targets.entries;
    lockon_targets.set_count(count);
    for (i = 0; i != count; i++) {
        record = slot->target_records.get_record(i);
        entry->set_uid(record->get_entity_id());
        entry->set_collider_index(record->get_part());
        entry++;
    }
    player->lock_on_cursor->set_cursor_pos(lockon_targets.entries[0].uid, lockon_targets.entries[0].collider_index);
    return &lockon_targets;
}

void PlayerAttackController::reset() {
    queued_kind = 0;
    attack_kind = 0;
    attack_speed = 1.0f;
    hit_count = 0;
    pending_stage = 0;
    begun_stage = 0;
    burst_count = 0;
    recovery_timer = 0;
    lock_range = 20.0f;
    horizontal_cone_cos = 1.0f;
    vertical_cone_cos = 1.0f;
    cone_apex_offset = 0.0f;
    lockon_targets.clear_lockon_list();
}

s16 LockOnTargetRecord::get_part() { return flag; }

void PlayerAttackController::set_saved_attack_stage(s16 stage) { pending_stage = stage; }

int PlayerAttackController::is_flag32_clear() { return flags.test_flags_any(32) == 0; }

CapturedTarget *PlayerAttackController::get_first_target() { return lockon_targets.get_captured_target_entry(0); }

void TObjPlayer::set_action_palette_state_mode(u8 mode) {
    action_palette_state.set_mode(mode);
}

void TObjPlayer::clear_flag_128() { this->clear_state_flags(128); }

void handle_6x54(void) {  }

void handle_6x8C(void) {  }

void handle_6x65(void) {  }

void handle_6x8B(void) {  }

void handle_6x64(void) {  }
