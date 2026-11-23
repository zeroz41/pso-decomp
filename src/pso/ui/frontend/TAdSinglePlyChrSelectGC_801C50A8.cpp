#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801C50A8.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/TUnk_804C3F48.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/player/TObjPlayer_801BDF5C.h"
#include "pso/player/PlayerSlots.h"

extern "C" {
    extern int duel_result_window;
TObject *ad_single_ply_chr_select_instance;
void TAdSinglePlyChrSelectGC::set_slot(int a0) { *(short*)((char*)active_character_save_record + 0x21b0) = a0; }
u16 TAdSinglePlyChrSelectGC::get_char_select_slot() {
    return *(u16 *)((s8 *)(*(u8 * *)&active_character_save_record) + 0x21B0);
}
void TAdSinglePlyChrSelectGC__sub_801C50C0(int a0) { *(short*)((char*)active_character_save_record + 0x21ae) = a0; }
u16 TAdSinglePlyChrSelectGC__sub_801C50CC(void) {
    return *(u16 *)((s8 *)(*(u8 * *)&active_character_save_record) + 0x21AE);
}
void TAdSinglePlyChrSelectGC__sub_801C50D8(int a0) { *(short*)((char*)active_character_save_record + 0x21ac) = a0; }
u16 TAdSinglePlyChrSelectGC__sub_801C50E4(void) {
    return *(u16 *)((s8 *)(*(u8 * *)&active_character_save_record) + 0x21AC);
}
void TAdSinglePlyChrSelectGC__sub_801C50F0(int a0) { *(short*)((char*)active_character_save_record + 0x21aa) = a0; }
u16 TAdSinglePlyChrSelectGC__sub_801C50FC(void) {
    return *(u16 *)((s8 *)(*(u8 * *)&active_character_save_record) + 0x21AA);
}
void TAdSinglePlyChrSelectGC__sub_801C5108(int a0) { *(short*)((char*)active_character_save_record + 0x21a8) = a0; }
u16 TAdSinglePlyChrSelectGC__sub_801C5114(void) {
    return *(u16 *)((s8 *)(*(u8 * *)&active_character_save_record) + 0x21A8);
}
void TAdSinglePlyChrSelectGC__sub_801C5120(void) { duel_result_window = 0; }
void TAdSinglePlyChrSelectGC::destroy() {
    if (ad_single_ply_chr_select_instance != NULL) {
        ad_single_ply_chr_select_instance->queue_destruction();
    }
}
void TAdSinglePlyChrSelectGC__sub_801C5158(void) { ad_single_ply_chr_select_instance = NULL; }
s32 TAdSinglePlyChrSelectGC::create_if_key_pressed() {
    s32 area;
    area = get_current_floor_area();
    if ((area != AREA_BATTLE1) && (area != AREA_BATTLE2)) {
        return 0;
    }
    if (ad_single_ply_chr_select_instance != NULL) {
        return 0;
    }
    ad_single_ply_chr_select_instance = new TUnk_804C3F48(tl_00);
    return 1;
}

}

struct Ply_801C51D4 { u8 pad[0x30]; u32 flags; u8 pad34[4]; f32 pos[3]; };

struct Self_801C51D4 { u8 pad[0x1C]; s32 life; s32 timer; Ply_801C51D4 *owner; };

extern "C" {
f32 xz_distance_squared(void *, void *);
void *play_sound_effect(s32, s32, s32, s32, f32);

#pragma push
#pragma fp_contract on
void TUnk_804C3F48::run_task() {
    Self_801C51D4 *self = (Self_801C51D4 *)this;
    s32 i;
    Ply_801C51D4 *p;
    f32 min;
    f32 d;
    f32 f;
    if (--self->life <= 0) {
        ((TObject *)self)->queue_destruction();
        return;
    }
    if (self->life > 0x5A) {
        if (--self->timer <= 0) {
            min = 2250000.0f;
            for (i = 0; i < 4; i++) {
                p = (Ply_801C51D4 *)get_player_by_client_id(i);
                if (p != NULL && p != self->owner && !(p->flags & 0x800)) {
                    d = xz_distance_squared(self->owner->pos, p->pos);
                    min = min < d ? min : d;
                }
            }
            f = newton_sqrtf(min) > 200.0f ? newton_sqrtf(min) : 200.0f;
            f -= 200.0f;
            min = 1.0f - 0.00076923077f * f;
            set_sound_pitch_request((saddr)play_sound_effect(0x23230, 0, 0, 0, f), (s32)(256.0f * min), 0);
            self->timer = (s32)(-53.0f * min) + 0x3C;
        }
    }
}
#pragma pop

}

TUnk_804C3F48::~TUnk_804C3F48() {
    ad_single_ply_chr_select_instance = NULL;
}

TUnk_804C3F48::TUnk_804C3F48(TObject *parent) : TObject(parent) {
    life = 0x3DE;
    timer = 0x1E;
    owner = (saddr)get_local_player();
}
