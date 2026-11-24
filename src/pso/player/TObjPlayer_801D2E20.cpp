#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/network/protocol/protocol_types.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/render/render_util.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/object/warp/TObjWarpBossMulti.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/unk/TUnk_804DDD28.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerActionPaletteState.h"
#include "pso/player/TObjPlayer_801C7430.h"
#include "pso/player/TObjPlayer_801D2E20.h"
#include "pso/player/PlayerAttackController.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/effect/enemy/TObjEneHoldEffect.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/ui/font/TFontSmallLobby.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TLockOnCursor.h"
#include "pso/ui/hud/TMainCursor.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/technique/TTecLuker.h"
#include "pso/technique/TTecReverser.h"
#include "pso/ui/window/TWindowActionPalette.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer_8012121C.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/TLobby_80207644.h"
#include "pso/math/AngleLookup.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/ui/frontend/TAdRicoRing_8001BEE8.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/ui/hud/TMainCursor_8013E7B8.h"
#include "pso/item/TItemLockCountCtrl_8011E184.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/object/base/TObjBase.h"

#pragma readonly_strings on

struct Rec_801D3224 { u8 pad[0x1C]; Vec pos; u8 pad28[4]; };

struct Obj_801D3224 { u8 pad[0xA4]; Rec_801D3224 *recs; };

struct Slot_801D3224 { s16 a; s16 idx; };

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

void CapturedTargetList::clear_lockon_list() {
    s32 i;
    CapturedTarget *entry = entries;
    count = 0;
    for (i = 0; i < 10; i++) {
        entry->clear();
        entry++;
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjPlayer::advance_and_clamp_state() {
    if ((*(s16 *)((s8 *)this + 0x10) = *(s16 *)((s8 *)this + 0x10) + 1) > 2) {
        set_saved_attack_stage((s16)(2));
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s16 PlayerAttackController::get_validated_attack_stage() {
    s16 stage = pending_stage;
    if (TObjPlayer__sub_801D2EE8(stage) == 0) {
        stage = 0;
    }
    return stage;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s32 TObjPlayer__sub_801D2EE8(s16 stage) {
    if ((stage < 0) || (stage >= 3)) {
        return 0;
    }
    return 1;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s16 TObjPlayer__sub_801D2F0C(void *arg0) {
    s16 var_r31;
    var_r31 = *(s16 *)((s8 *)arg0 + 2);
    if (TObjPlayer__sub_801D2F8C((s16)(var_r31)) == 0) {
        var_r31 = 0;
    }
    return var_r31;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s16 TObjPlayer__sub_801D2F4C(s16 *arg0) {
    s16 var_r31;
    var_r31 = *arg0;
    if (TObjPlayer__sub_801D2F8C((s16)((s16)((int) (var_r31)))) == 0) {
        var_r31 = 0;
    }
    return var_r31;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s32 TObjPlayer__sub_801D2F8C(s16 arg0) {
    if ((arg0 < 0) || (arg0 >= 3)) {
        return 0;
    }
    return 1;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void queue_physical_attack_input(PlayerAttackController *self, TObjPlayer *obj, s32 kind, s16 arg3) {
    s16 t;
    if (((int (*)(void*, int))test_flags_any)((void*)(((void *)get_anim_field_c__10TObjPlayerFPv((void*)(self)))), 2) == 0 ||
        ((TObjPlayer *)self)->is_flag32_clear() == 0) {
        ((FlagWord *)((void *)get_anim_field_c__10TObjPlayerFPv((void*)(self))))->set(4);
    }
    if (((int (*)(void*, int))test_flags_any)((void*)(((void *)get_anim_field_c__10TObjPlayerFPv((void*)(self)))), 2) != 0 &&
        ((int (*)(void*, int))test_flags_any)((void*)(((void *)get_anim_field_c__10TObjPlayerFPv((void*)(self)))), 4) == 0) {
        ((FlagWord *)((void *)get_anim_field_c__10TObjPlayerFPv((void*)(self))))->set(1);
        ((TObjPlayer *)self)->advance_and_clamp_state();
        if (self->get_validated_attack_stage() > arg3) {
            ((TObjPlayer *)self)->set_saved_attack_stage(arg3);
        }
        t = ((TObjPlayer *)obj)->get_action_palette_entry(kind);
        ((TObjPlayer *)obj)->set_action_palette_state_mode(2);
        ((TObjPlayer *)self)->set_attack_target((s16)(t));
        TWindowCtrl::dispatch_to_child((u16)obj->get_entity_id(), kind);
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s32 TObjPlayer::update_if_flag8_set() {
    saddr arg0 = (saddr)this;
    if (((int (*)(void*, int))test_flags_any)((void*)(arg0 + 0xC), 8) != 0) {
        return tick_countdown_timer();
    }
    return 0;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s32 TObjPlayer::tick_countdown_timer() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;

    temp_r0 = *(s32 *)((s8 *)arg0 + 0x1C) - 1;
    *(s32 *)((s8 *)arg0 + 0x1C) = temp_r0;
    if (temp_r0 < 0) {
        ((FlagWord *)(arg0 + 0xC))->set(1);
        return 1;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void apply_anim_action__10TObjPlayerFPvi(u8 *arg0, saddr arg1) {
    ((FlagWord *)((void *) (arg0 + 0xC)))->set(2);
    *(s32 *)((s8 *)arg0 + 0x1C) = (s32) ((TObjPlayer *)arg1)->get_attack_recovery_count();
    TObjPlayer::clear_flag_128((void*)((void *) (arg1)));
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void begin_player_attack(u8 *player, s32 arg1, s16 arg2, s32 arg3) {
  s8 *new_var;
  ((TObjPlayer *)player)->set_saved_attack_stage((s16)(arg2));
  *((s32 *) (((s8 *) player) + 0x14)) = arg3;
  *((s16 *) (((s8 *) player) + 0x12)) = 0;
  new_var = (s8 *) player;
  *((s32 *) (((s8 *) player) + 0x18)) = 0;
  ((FlagWord *)((void *) (player + 0xC)))->clear(0x1F);
  *((s32 *) (new_var + 0x1C)) = 6;
  *((f32 *) (new_var + 4)) = (f32) (*((f32 *) (((s8 *) player) + 8)));
  if ((s16) (*((s16 *) (((s8 *) player) + 0))))
  {
    *((f32 *) (((s8 *) player) + 4)) *= 1.25f;
  }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

s32 get_first_target_position__10TObjPlayerFPvPv(void *arg0, Vec *out) {
    Slot_801D3224 *s = (Slot_801D3224 *)TObjPlayer__sub_801D345C((void*)(arg0));
    u16 uid = ((CapturedTarget *)s)->get_uid();
    Obj_801D3224 *o;
    if (uid == 0xFFFF) {
        return 0;
    }
    o = ((Obj_801D3224 * (*)(u16))find_entity_by_id)(uid);
    if (o == NULL) {
        return 0;
    }
    ((void (*)(Vec *, Vec *))VecCopy__FP3VecPC3Vec)(out, &o->recs[s->idx].pos);
    return 1;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void *capture_lockon_targets(Self_801D32A0 *self, Pl_801D32A0 *player) {
    Cur_801D32A0 *cur;
    s32 n;
    CapturedTarget *e;
    s32 i;
    void *obj;
    if (player->cursor == 0) return 0;
    self->targets.clear_lockon_list();
    cur = TObjPlayer__sub_801B57E8(player);
    if (cur == 0) return 0;
    if (get_cursor_palette_mode(cur) != 2) return 0;
    self->f20 = cur->x28;
    self->f24 = cur->x2c;
    self->f28 = cur->x30;
    self->f2c = cur->x3c;
    n = ((TLockOnCursor *)(cur->lock))->get_target();
    e = self->targets.entries;
    self->targets.set_count(n);
    for (i = 0; i != n; i++) {
        obj = TObjPlayer__sub_80116620(cur->lock, i);
        e->set_uid(((TObjPlayer *)obj)->get_type_id());
        e->set_collider_index(((TObjPlayer *)obj)->get_obj_id());
        e++;
    }
    ((TMainCursor *)(player->cursor))->set_cursor_pos(self->targets.entries[0].uid, self->targets.entries[0].collider_index);
    return &self->targets;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjPlayer::reset_movement_state() {
    *(s16 *)((s8 *)((u8 *)this) + 2) = 0;
    *(s16 *)((s8 *)((u8 *)this) + 0) = 0;
    *(f32 *)((s8 *)((u8 *)this) + 4) = 1.0f;
    *(s16 *)((s8 *)((u8 *)this) + 0x12) = 0;
    *(s16 *)((s8 *)((u8 *)this) + 0x10) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x14) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x18) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x1C) = 0;
    *(f32 *)((s8 *)((u8 *)this) + 0x20) = 20.0f;
    *(f32 *)((s8 *)((u8 *)this) + 0x24) = 1.0f;
    *(f32 *)((s8 *)((u8 *)this) + 0x28) = 1.0f;
    *(f32 *)((s8 *)((u8 *)this) + 0x2C) = 0.0f;
    ((CapturedTargetList *)((u8 *)this + 0x30))->clear_lockon_list();
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s16 TObjPlayer::get_obj_id() { return *(s16*)((char*)this + 0x2); }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjPlayer::set_saved_attack_stage(s16 v) { *(s16*)((char*)this + 0x10) = v; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
int TObjPlayer::is_flag32_clear() { return (((int (*)(void*, int))test_flags_any)((void*)((char*)this + 0xc), 32)) == 0; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s32 *TObjPlayer__sub_801D345C(void *p) { return (s32 *)((CapturedTargetList *)((char*)p + 0x30))->get_captured_target_entry(0); }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjPlayer::set_action_palette_state_mode(u8 mode) {
    set_player_action_palette_mode(&action_palette_state, mode);
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjPlayer::clear_flag_128(void* p) { ((TObjPlayer *)p)->clear_state_flags(128); }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void handle_6x54(void) {  }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void handle_6x8C(void) {  }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void handle_6x65(void) {  }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void handle_6x8B(void) {  }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void handle_6x64(void) {  }
#pragma pop
