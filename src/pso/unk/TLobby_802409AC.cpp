#include "types.h"
#include "pso/audio/SoundRequestVoice.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_8023F734.h"
#include "pso/unk/TLobby_80242910.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

typedef struct Entry_8024220C
{
  s32 id;
  s32 f4;
  char name[0x11];
  char s19[0x11];
  char s2A[0x11];
  char s3B[0x11];
  u8 f4C[0xC];
  u8 ext[0x64];
} Entry_8024220C;

typedef struct Src_8024220C
{
  s32 id;
  char name[0x30];
  char list[0x30];
  u8 f64[0xC];
  u8 ext[0x64];
} Src_8024220C;

extern "C" {
s32 __as__21TPlyMeetUserExtensionFRC21TPlyMeetUserExtension(void *, void *);
s32 strncpy(void *, void *, int);
s32 memset(void *, int, int);
extern u8 selected_guild_card_record[];
void load_selected_guild_card_record(Src_8024220C *arg0);
void *__construct_array(void *, void *, void *, u32, u32);
}
void set_field0__6TLobbyFPvi(SoundRequestVoice *voice, void *owner) { voice->owner = (SoundRequestOwner *)owner; }

extern const f32 TLobby__data_805DC9E0;
extern const f32 lbl_805DC9E4;
extern f32 lbl_805DC9E8;

void clamp_field9c__6TLobbyFPvf(void *arg0, f32 farg0) {
    f32 var_f1;

    var_f1 = farg0;
    if (var_f1 < TLobby__data_805DC9E0) {
        *(f32 *)((s8 *)arg0 + 0x9C) = (f32) lbl_805DC9E4;
        return;
    }
    if (var_f1 > lbl_805DC9E8) {
        var_f1 = lbl_805DC9E8;
    }
    *(f32 *)((s8 *)arg0 + 0x9C) = var_f1;
}

void TLobby__sub_802409E4(void* p) { *(s16*)((char*)p + 0x92) = 5; }

extern "C" s32 sndFXCtrl14(u32 vid, u8 ctrl, u16 value);

void TLobby__sub_802409F0(SoundRequestVoice *v) {
    switch (v->kind) {
    case 0:
        if (v->previousPitch != v->pitch) {
            sndFXCtrl14(v->token, 0x80, v->pitch);
            v->previousPitch = v->pitch;
        }
        break;
    }
}

void update__6TLobbyFPv(void *arg0) {
    s32 temp_r0;
    s32 temp_r4;

    if ((u32) (*(s32 *)((s8 *)arg0 + 0x80) + 0x77780000) == 0x8888U) {
        *(s32 *)((s8 *)arg0 + 0x84) = 0;
        *(s32 *)((s8 *)arg0 + 0x80) = 0;
        *(s32 *)((s8 *)arg0 + 0x78) = (s32) *(s32 *)((s8 *)arg0 + 0x7C);
    }
    temp_r4 = *(s32 *)((s8 *)arg0 + 0x80);
    if (temp_r4 > 0) {
        temp_r0 = *(s32 *)((s8 *)arg0 + 0x84);
        if (temp_r0 <= 0) {
            *(s32 *)((s8 *)arg0 + 0x84) = 0;
            *(s32 *)((s8 *)arg0 + 0x80) = 0;
            *(s32 *)((s8 *)arg0 + 0x78) = (s32) *(s32 *)((s8 *)arg0 + 0x7C);
        } else {
            *(s32 *)((s8 *)arg0 + 0x78) = (s32) ((s32) (*(s32 *)((s8 *)arg0 + 0x7C) * (temp_r4 - temp_r0)) / temp_r4);
            *(s32 *)((s8 *)arg0 + 0x84) = (s32) (*(s32 *)((s8 *)arg0 + 0x84) - ((s32 (*)(s32))get_field_308__6TLobbyFPv)(*(s32 *)((s8 *)arg0 + 0)));
        }
    }
    *(s32 *)((s8 *)arg0 + 0x64) = (s32) (*(s32 *)((s8 *)arg0 + 0x6C) + *(s32 *)((s8 *)arg0 + 0x70) + *(s32 *)((s8 *)arg0 + 0x78));
    *(s32 *)((s8 *)arg0 + 0x64) = (s32) (*(s32 *)((s8 *)arg0 + 0x64) + 0x2000);
    if ((s32) *(s32 *)((s8 *)arg0 + 0x64) < 0) {
        *(s32 *)((s8 *)arg0 + 0x64) = 0;
    }
    if ((s32) *(s32 *)((s8 *)arg0 + 0x64) > 0x3FFF) {
        *(s32 *)((s8 *)arg0 + 0x64) = 0x3FFF;
    }
}

#undef lbl_805162EC
#pragma push


struct Voice_80241FD8 {
    u32 pad0; s32 state; u32 pad1; s32 kind; u8 pad2[0x20 - 0x10]; s32 token;
    u8 pad3[0x48 - 0x24]; s32 fade; s32 fadeStep;
};

struct Ctl_80240B64 {
    u8 type;
    s16 value;
};

struct Params_80240B64 {
    u8 count;
    Ctl_80240B64 *ctl;
};

struct Owner_80241798 { u8 pad[0x288]; u32 field_288; };

struct Sound_80241798 {
    Owner_80241798 *owner;
    u8 pad4[0x4];
    s32 flags;
    u8 padC[0x4];
    s32 group;
    s32 id;
    u8 pad18[0x58];
    s32 pitch;
    s32 velocity;
    u8 pad78[0x14];
    s16 field_8C;
};

extern "C" {
s32 sndFXCtrl(int, int, int);
s32 sndFXKeyOff(int);
s32 OSDisableInterrupts(void);
s32 OSRestoreInterrupts(s32);
void TLobby__sub_80240F3C(SoundRequestVoice *);
void calc_sound_spatial_params(SoundRequestVoice *);
u32 sndFXStartParaInfo(u16, u8, u8, u8, Params_80240B64 *);
u32 sndFXCheck(u32);
extern s8 TLobby__data_805434A8[];
extern s32 TLobby__lobby_state_flags;
void TLobby__sub_80241798(Sound_80241798 *arg0);
}
void send_voice_controller_updates(u8 *arg0);

s32 set_voice_pitch_slide(u8 *arg0, s32 arg1, s32 arg2) {
    s32 var_r5;
    var_r5 = arg2;
    if (var_r5 <= 0) {
        var_r5 = 0x88888888;
    }
    *(s32 *)((s8 *)arg0 + 0x7C) = arg1;
    *(s32 *)((s8 *)arg0 + 0x80) = var_r5;
    *(s32 *)((s8 *)arg0 + 0x84) = var_r5;
    return 0;
}

s32 tick_sound_voice(SoundRequestVoice *v) {
    Params_80240B64 params;
    Ctl_80240B64 ctl[6];
    s32 level;
    s32 fade;
    s32 step;
    switch (v->kind) {
    case 0:
    switch (v->state) {
    case -1:
        v->age++;
        v->effect = ((s32 (*)(SoundRequestOwner*, s32, s32, s32))resolve_sound_effect_bank)(v->owner, v->kind, v->bank, v->index);
        if (v->effect < 0) {
            v->state = 0;
            return 0;
        }
        if (v->delay != 0) {
            v->delay--;
            break;
        }
        ((void (*)(SoundRequestVoice *))TLobby__sub_80241A0C)(v);
        TLobby__sub_80241798((Sound_80241798 *)(v));
    start:
        ((void (*)(SoundRequestVoice *))TLobby__sub_80240F38)(v);
        TLobby__sub_80240F3C(v);
        calc_sound_spatial_params(v);
        clamp_params__6TLobbyFPv(v);
        update__6TLobbyFPv(v);
        params.count = 1;
        params.ctl = ctl;
        ctl[0].type = 0x80;
        ctl[0].value = v->pitch;
        if (!(TLobby__lobby_state_flags & 2) && TLobby__data_805434A8[7] == 0) {
            level = OSDisableInterrupts();
        }
        v->token = sndFXStartParaInfo(v->effect, 0x7F, v->pan, v->studio, &params);
        send_voice_controller_updates((u8 *)v);
        if (!(TLobby__lobby_state_flags & 2) && TLobby__data_805434A8[7] == 0) {
            OSRestoreInterrupts(level);
        }
        send_sound_request_reverb((SoundRequestVoice *)(v));
        v->state = 1;
        break;
    case 0:
        break;
    case 1:
        if (v->flags & 0x80) {
            v->pitchMoving += v->pitchVelocity;
            if (v->pitchVelocity > 0) {
                if (v->pitchMoving > v->pitchLimit) {
                    v->pitchVelocity = -v->pitchVelocity;
                }
            } else if (v->pitchMoving < -v->pitchLimit) {
                v->pitchVelocity = -v->pitchVelocity;
            }
        }
        v->age++;
        fade = v->fade;
        if (fade <= -0x7F) {
            sndFXKeyOff(v->token);
            v->state = 0;
            break;
        }
        step = v->fadeStep;
        if (step != 0) {
            v->fade = fade - step;
        }
        if (v->flags & 1) {
            if (v->refresh >= 5) {
                calc_sound_spatial_params(v);
            }
        } else {
            calc_sound_spatial_params(v);
        }
        v->refresh--;
        send_sound_request_reverb((SoundRequestVoice *)(v));
        clamp_params__6TLobbyFPv(v);
        update__6TLobbyFPv(v);
        if (sndFXCheck(v->token) == 0xFFFFFFFF) {
            if ((v->flags & 1) && v->refresh >= 0) {
                sndFXKeyOff(v->token);
                v->previousPan = v->previousSurround = v->previousVolume = 0x88888888;
                goto start;
            }
            v->state = 0;
        } else {
            send_voice_controller_updates((u8 *)v);
            TLobby__sub_802409F0(v);
            if ((v->flags & 1) && v->refresh < 0) {
                sndFXKeyOff(v->token);
                v->state = 0;
            }
        }
        break;
    }
        break;
    }
    return 0;
}

void update_random_flip_flag__6TLobbyFPv(u8 *arg0) {
    switch (*(s32 *)((s8 *)arg0 + 0x10)) {
    case 0:
        switch (*(s32 *)((s8 *)arg0 + 0x14)) {
        case 0: case 1: case 2: case 3: case 4:
        case 7: case 8: case 9:
        case 21:
        case 23: case 24: case 25: case 26: case 27: case 28: case 29: case 30: case 31:
            *(s32 *)((s8 *)arg0 + 8) |= 0x100;
            break;
        }
        break;
    }
    if (*(s32 *)((s8 *)arg0 + 8) & 0x100) {
        *(s16 *)((s8 *)arg0 + 0x90) = (s16)(((u32 (*)(void*))advance_rng__6TLobbyFPv)(*(void **)((s8 *)arg0 + 0)) & 1);
    }
}

void TLobby__sub_80240F38(void) {  }

void TLobby__sub_80240F3C(SoundRequestVoice *v) {
    s32 num = 1;
    s32 den = 1;
    s32 extra = 0;
    switch (v->bank) {
    case 0:
        switch (v->index) {
        case 0: case 1: case 2: case 3: case 4:
        case 7: case 9:
        case 18: case 21:
        case 23: case 24: case 25: case 26: case 27: case 28: case 29: case 30: case 31:
            v->flags |= 0x40;
            break;
        }
        break;
    case 3:
        switch (((Owner_80241798 *)v->owner)->field_288) {
        case 2:
            switch (v->index) {
            case 12:
                den = 1;
                v->flags |= 0x40;
                break;
            case 1: case 24:
                den = 4;
                v->flags |= 0x40;
                break;
            }
            break;
        case 8:
            switch (v->index) {
            case 31:
                v->flags |= 0x40;
                break;
            }
            break;
        case 12:
            switch (v->index) {
            case 33: case 43: case 64: case 65:
                v->flags |= 0x40;
                break;
            }
            break;
        case 16:
            switch (v->index) {
            case 17: case 51: case 52:
                v->flags |= 0x40;
                break;
            }
            break;
        }
        switch (((Owner_80241798 *)v->owner)->field_288) {
        case 2:
            switch (v->index) {
            case 13:
                v->flags |= 0x40;
                break;
            case 36:
                den = 2;
                v->flags |= 0x40;
                break;
            case 47:
                den = 6;
                extra = 0x1C00;
                v->flags |= 0x40;
                break;
            }
            break;
        case 10:
            switch (v->index) {
            case 1:
                den = 4;
                v->flags |= 0x40;
                break;
            case 13:
                den = 2;
                v->flags |= 0x40;
                break;
            case 32:
                den = 3;
                v->flags |= 0x40;
                break;
            case 34:
                v->flags |= 0x40;
                break;
            case 41:
                num = 2;
                v->flags |= 0x40;
                break;
            }
            break;
        case 11:
            switch (v->index) {
            case 1:
                den = 4;
                v->flags |= 0x40;
                break;
            case 13:
                den = 2;
                v->flags |= 0x40;
                break;
            case 32:
                den = 3;
                v->flags |= 0x40;
                break;
            case 34:
                v->flags |= 0x40;
                break;
            case 41:
                num = 2;
                v->flags |= 0x40;
                break;
            }
            break;
        case 14:
            switch (v->index) {
            case 1:
                den = 1;
                v->flags |= 0x40;
                break;
            case 2:
                v->flags |= 0x40;
                break;
            case 10:
                den = 4;
                v->flags |= 0x40;
                break;
            case 22:
                v->flags |= 0x40;
                break;
            case 36:
                den = 3;
                v->flags |= 0x40;
                break;
            case 42:
                den = 2;
                v->flags |= 0x40;
                break;
            case 54:
                den = 6;
                v->flags |= 0x40;
                break;
            case 57:
                v->flags |= 0x40;
                break;
            case 64:
                num = 2;
                v->flags |= 0x40;
                break;
            }
            break;
        case 15:
            switch (v->index) {
            case 3: case 15:
                num = 2;
                v->flags |= 0x40;
                break;
            case 17:
                den = 4;
                v->flags |= 0x40;
                break;
            case 37: case 38:
                v->flags |= 0x40;
                break;
            case 16:
                break;
            }
            break;
        case 19:
            switch (v->index) {
            case 2: case 8: case 22:
                num = 2;
                v->flags |= 0x40;
                break;
            case 15:
                v->flags |= 0x40;
                break;
            case 27: case 28:
                num = 2;
                v->flags |= 0x40;
                break;
            }
            break;
        case 4:
            switch (v->index) {
            case 11: case 19:
                den = 3;
                v->flags |= 0x40;
                break;
            case 13: case 51: case 52:
                v->flags |= 0x40;
                break;
            case 12:
                break;
            }
            break;
        case 5:
            switch (v->index) {
            case 1: case 6:
                num = 2;
                v->flags |= 0x40;
                break;
            }
            break;
        case 6:
            switch (v->index) {
            case 3: case 15: case 24:
                num = 2;
                v->flags |= 0x40;
                break;
            }
            break;
        case 7:
            switch (v->index) {
            case 31:
                num = 2;
                v->flags |= 0x40;
                break;
            }
            break;
        case 8:
            switch (v->index) {
            case 38: case 45: case 50: case 51:
                num = 2;
                v->flags |= 0x40;
                break;
            case 63:
                den = 12;
                v->flags |= 0x40;
                break;
            }
            break;
        case 9:
            switch (v->index) {
            case 34:
                num = 2;
                v->flags |= 0x40;
                break;
            }
            break;
        case 18:
            switch (v->index) {
            case 13: case 14:
                v->flags |= 0x40;
                break;
            }
            break;
        case 12:
            switch (v->index) {
            case 2: case 12: case 19: case 21: case 40: case 48: case 57:
                num = 2;
                v->flags |= 0x40;
                break;
            }
            break;
        case 16:
            switch (v->index) {
            case 2: case 3: case 37: case 39: case 45:
                num = 2;
                v->flags |= 0x40;
                break;
            case 38:
                break;
            }
            break;
        case 20:
            switch (v->index) {
            case 5: case 28: case 62:
                num = 2;
                v->flags |= 0x40;
                break;
            }
            break;
        }
        break;
    case 6:
        switch (((Owner_80241798 *)v->owner)->field_288) {
        case 17:
            switch (v->index) {
            case 22: case 30: case 31:
                num = 2;
                v->flags |= 0x40;
                break;
            }
            break;
        }
        break;
    }
    if (v->flags & 0x40) {
        v->pitchMoving = num * ((s32)((advance_rng__6TLobbyFPv(v->owner) >> 16) & 0x3F00) - 0x2000 + extra) / den;
    }
}

void TLobby__sub_80241798(Sound_80241798 *arg0) {
    s32 num = 1;
    s32 den = 1;
    s32 mask = 0;
    s32 min = 0;
    switch (arg0->owner->field_288) {
    case 16:
        switch (arg0->group) {
        case 4:
            switch (arg0->id) {
            case 5: case 6: case 7: case 8: case 9:
                mask = 0x3F;
                min = 0x40;
                arg0->flags |= 0x80;
                break;
            }
            break;
        }
        break;
    case 2:
        switch (arg0->group) {
        case 4:
            switch (arg0->id) {
            case 6:
                mask = 0x3F;
                min = 0x20;
                arg0->flags |= 0x80;
                break;
            }
            break;
        }
        break;
    case 9:
        switch (arg0->group) {
        case 3:
            switch (arg0->id) {
            case 0: case 1:
                mask = 0x3F;
                min = 0x80;
                arg0->flags |= 0x80;
                break;
            }
            break;
        }
        break;
    case 12:
        switch (arg0->group) {
        case 4:
            switch (arg0->id) {
            case 11:
                mask = 0x3F;
                min = 0x20;
                arg0->flags |= 0x80;
                break;
            case 12: case 13:
                mask = 0x3F;
                min = 0x60;
                arg0->flags |= 0x80;
                break;
            }
            break;
        case 3:
            switch (arg0->id) {
            case 20:
                den = 6;
                mask = 0x3F;
                min = 0x20;
                arg0->flags |= 0x80;
                arg0->field_8C = 0x1000;
                break;
            }
            break;
        }
        break;
    case 13:
        switch (arg0->group) {
        case 3:
            switch (arg0->id) {
            case 5:
                num = 2;
                mask = 0x3F;
                min = 0xC0;
                arg0->flags |= 0x80;
                break;
            case 21: case 22:
                mask = 0x3F;
                min = 0x40;
                arg0->flags |= 0x80;
                break;
            }
            break;
        }
        break;
    }
    if (arg0->flags & 0x80) {
        arg0->pitch = num * ((s32)((((u32 (*)(void*))advance_rng__6TLobbyFPv)(arg0->owner) >> 16) & 0x3FFF) - 0x2000) / den;
        arg0->velocity = min + (mask & ((u32 (*)(void*))advance_rng__6TLobbyFPv)(arg0->owner));
        if ((s32)(((u32 (*)(void*))advance_rng__6TLobbyFPv)(arg0->owner) & 0x3F) < 0x20) {
            arg0->velocity = -arg0->velocity;
        }
    }
}

void TLobby__sub_80241A0C(void) {  }

extern const f32 lbl_805DC9EC;

void send_sound_request_reverb(SoundRequestVoice *voice) {
    f32 request = voice->reverb;
    s32 amount;
    if (request < TLobby__data_805DC9E0) {
        if (voice->bank == 5 || (voice->flags & 0x10)) amount = 0;
        else amount = s32(lbl_805DC9EC * voice->owner->reverb);
    } else amount = s32(lbl_805DC9EC * request);
    if (voice->bank == 6) {
        switch (voice->index) {
        case 12:
        case 25:
            return;
        default:
            break;
        }
    }
    if (voice->previousReverb != u8(amount))
        sndFXCtrl(voice->token, 91, amount);
}

void send_voice_controller_updates(u8 *arg0) {
    switch ((s32) *(s32 *)((s8 *)arg0 + 0xC)) {
    case 0:
    if ((*(s32 *)((s8 *)arg0 + 0x24)) != (s32) *(s32 *)((s8 *)arg0 + 0x28)) {
        *(s32 *)((s8 *)arg0 + 0x24) = *(s32 *)((s8 *)arg0 + 0x28);
        sndFXCtrl((int) (*(s32 *)((s8 *)arg0 + 0x20)), 7, (int) ((u8) *(s32 *)((s8 *)arg0 + 0x28)));
    }
    if ((*(s32 *)((s8 *)arg0 + 0x2C)) != (s32) *(s32 *)((s8 *)arg0 + 0x30)) {
        *(s32 *)((s8 *)arg0 + 0x2C) = *(s32 *)((s8 *)arg0 + 0x30);
        sndFXCtrl((int) (*(s32 *)((s8 *)arg0 + 0x20)), 0xA, (int) ((u8) *(s32 *)((s8 *)arg0 + 0x30)));
    }
    if ((s32) *(s32 *)((s8 *)arg0 + 0x10) == 5) {
        sndFXCtrl((int) (*(s32 *)((s8 *)arg0 + 0x20)), 0x83, (int) (0U));
        return;
    }
    if ((*(s32 *)((s8 *)arg0 + 0x34)) != (s32) *(s32 *)((s8 *)arg0 + 0x38)) {
        *(s32 *)((s8 *)arg0 + 0x34) = *(s32 *)((s8 *)arg0 + 0x38);
        sndFXCtrl((int) (*(s32 *)((s8 *)arg0 + 0x20)), 0x83, (int) ((u8) *(s32 *)((s8 *)arg0 + 0x38)));
    }
        break;
    }
}

void clamp_params__6TLobbyFPv(void *arg0) {
    *(s32 *)((s8 *)arg0 + 0x28) = (((*(s32 *)((s8 *)arg0 + 0x48) + *(s32 *)((s8 *)arg0 + 0x40)) + *(s32 *)((s8 *)arg0 + 0x3C)) + *(s32 *)((s8 *)arg0 + 0x44)) + 0x7F;
    *(s32 *)((s8 *)arg0 + 0x30) = (s32) (0x40 - (*(s32 *)((s8 *)arg0 + 0x50) + *(s32 *)((s8 *)arg0 + 0x54)));
    *(s32 *)((s8 *)arg0 + 0x38) = (s32) ((*(s32 *)((s8 *)arg0 + 0x58) + *(s32 *)((s8 *)arg0 + 0x60)) + 0x40);
    *(s32 *)((s8 *)arg0 + 0x28) = (s32) (*(s32 *)((s8 *)arg0 + 0x28) + *(s32 *)((s8 *)(*(void **)((s8 *)arg0 + 0)) + 0x280));
    if ((s32) *(s32 *)((s8 *)arg0 + 0x28) < 0) {
        *(s32 *)((s8 *)arg0 + 0x28) = 0;
    }
    if ((s32) *(s32 *)((s8 *)arg0 + 0x28) > 0x7F) {
        *(s32 *)((s8 *)arg0 + 0x28) = 0x7F;
    }
    if ((s32) *(s32 *)((s8 *)arg0 + 0x30) < 0) {
        *(s32 *)((s8 *)arg0 + 0x30) = 0;
    }
    if ((s32) *(s32 *)((s8 *)arg0 + 0x30) > 0x7F) {
        *(s32 *)((s8 *)arg0 + 0x30) = 0x7F;
    }
    if ((s32) *(s32 *)((s8 *)arg0 + 0x38) < 0) {
        *(s32 *)((s8 *)arg0 + 0x38) = 0;
    }
    if ((s32) *(s32 *)((s8 *)arg0 + 0x38) > 0x7F) {
        *(s32 *)((s8 *)arg0 + 0x38) = 0x7F;
    }
}

s32 start_voice_fade(struct Voice_80241FD8 *v, s32 step) {
    switch (v->kind) {
    case 0:
        if (v->fadeStep == 0) {
            if (step != 0) {
                v->fadeStep = step;
                v->fade = -step;
            } else {
                if (step == 0 && v->state == 1) {
                    sndFXKeyOff(v->token);
                }
                v->state = 0;
            }
        }
        break;
    }
    return 0;
}

#pragma push
#pragma fp_contract on
s32 init_sound_voice__6TLobbyFPviiii(void *lobby, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    *(s32 *)((s8 *)lobby + 4) = 0;
    *(s32 *)((s8 *)lobby + 8) = arg4;
    *(s32 *)((s8 *)lobby + 0xC) = arg1;
    *(s32 *)((s8 *)lobby + 0x10) = arg2;
    *(s32 *)((s8 *)lobby + 0x14) = arg3;
    *(s32 *)((s8 *)lobby + 0x1C) = 0;
    *(s32 *)((s8 *)lobby + 0x20) = 0;
    *(s32 *)((s8 *)lobby + 0x28) = 0x7F;
    *(s32 *)((s8 *)lobby + 0x24) = 0x88888888;
    *(s32 *)((s8 *)lobby + 0x30) = 0x40;
    *(s32 *)((s8 *)lobby + 0x2C) = 0x88888888;
    *(s32 *)((s8 *)lobby + 0x38) = 0;
    *(s32 *)((s8 *)lobby + 0x34) = 0x88888888;
    *(s32 *)((s8 *)lobby + 0x3C) = 0;
    *(s32 *)((s8 *)lobby + 0x40) = 0;
    *(s32 *)((s8 *)lobby + 0x44) = 0;
    *(s32 *)((s8 *)lobby + 0x48) = 0;
    *(s32 *)((s8 *)lobby + 0x4C) = 0;
    *(s32 *)((s8 *)lobby + 0x50) = 0;
    *(s32 *)((s8 *)lobby + 0x54) = 0;
    *(s32 *)((s8 *)lobby + 0x58) = 0;
    *(s32 *)((s8 *)lobby + 0x60) = 0;
    *(s32 *)((s8 *)lobby + 0x64) = 0;
    *(s32 *)((s8 *)lobby + 0x68) = 0x88888888;
    *(s32 *)((s8 *)lobby + 0x6C) = 0;
    *(s32 *)((s8 *)lobby + 0x70) = 0;
    *(s32 *)((s8 *)lobby + 0x74) = 0;
    *(s32 *)((s8 *)lobby + 0x78) = 0;
    *(s32 *)((s8 *)lobby + 0x7C) = 0;
    *(s32 *)((s8 *)lobby + 0x80) = 0;
    *(s32 *)((s8 *)lobby + 0x84) = 0;
    *(s16 *)((s8 *)lobby + 0x8C) = 0x3F00;
    *(s32 *)((s8 *)lobby + 0x98) = 0;
    *(s16 *)((s8 *)lobby + 0x90) = 0;
    *(s16 *)((s8 *)lobby + 0x92) = 0;
    *(s32 *)((s8 *)lobby + 0x94) = 0;
    *(f32 *)((s8 *)lobby + 0x9C) = (f32) lbl_805DC9E4;
    *(s32 *)((s8 *)lobby + 0x88) = 0;
    switch (*(s32 *)((s8 *)lobby + 0xC)) {
    case 0:
        *(s32 *)((s8 *)lobby + 4) = -1;
        update_random_flip_flag__6TLobbyFPv((u8 *)lobby);
        break;
    }
    return 0;
}
#pragma pop

#pragma pop

#pragma push

struct RecoveredGlobal_8024259C_TLobby__data_8050AAAC {
    s32 value;
    u8 remaining[0x24];
};

typedef struct Tag_802421C4 { s32 a; s32 b; } Tag_802421C4;

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Pair_80242380 {
    u8 c[8];
};

struct Ext_80242380 {
    u8 bytes[0x64];
};

typedef struct Entry_80242380 {
    s32 id;
    s32 f4;
    char name[0x11];
    char s19[0x11];
    char s2A[0x11];
    char s3B[0x11];
    Pair_80242380 f4C;
    s32 f54;
    Ext_80242380 ext;
} Entry_80242380;

extern "C" {
s32 seq_jump__9TProtocolFPUcR21TPlyMeetUserExtension(int, void *, void *);
extern RecoveredGlobal_8024259C_TLobby__data_8050AAAC TLobby__data_8050AAAC;
extern u32 TLobby__protocol_instance;
char *get_shared_text_buffer();
void text_builder_append(char *);
}
void text_builder_reset();
extern "C" {
s32 send_find_user__9TProtocolFR16TPlyGuildCardTagUl(void *, Tag_802421C4 *, s32);
extern unsigned char lbl_80517F9C[];
void __copy(void *, void *, int);
Entry_80242380 *copy_com_card_entry__6TLobbyFPvPv(Entry_80242380 *dst, Entry_80242380 *src);
int TLobby__sub_8024273C(void*);

SoundRequestVoice::~SoundRequestVoice() {
    state = 0;
}
SoundRequestVoice::SoundRequestVoice() {
    owner = NULL;
    state = 0;
}
s32 get_field_308__6TLobbyFPv(void* p) { return *(s32*)((char*)p + 0x308); }
int forward_8024273C__6TLobbyFPv(void* p) { return TLobby__sub_8024273C(p); }

void send_find_user_self_tag__6TLobbyFi(s32 arg0) {
    if ((u32) TLobby__protocol_instance != 0U) {
        Tag_802421C4 tag = *(Tag_802421C4 *)((u8 *)TLobby__protocol_instance + 0x1900);
        send_find_user__9TProtocolFR16TPlyGuildCardTagUl((void *)TLobby__protocol_instance, &tag, arg0);
    }
}

typedef struct Entry_8024220C Entry_8024220C;
typedef struct Src_8024220C Src_8024220C;
void load_selected_guild_card_record(Src_8024220C *arg0) {
  char *new_var;
  void *p;
  (*(Entry_8024220C *)&selected_guild_card_record).id = arg0->id;
  (*(Entry_8024220C *)&selected_guild_card_record).f4 = 0;
  memset((*(Entry_8024220C *)&selected_guild_card_record).name, 0, 0x11);
  strncpy((*(Entry_8024220C *)&selected_guild_card_record).name, arg0->name, 0x10);
  (*(Entry_8024220C *)&selected_guild_card_record).name[0x10] = 0;
  new_var = arg0->list;
  new_var = build_text_from_comma_list__6TLobbyFPv(new_var);
  p = new_var;
  p = ((void *)parse_csv_token__6TLobbyFPvPv((char *)(p), (char *)((*(Entry_8024220C *)&selected_guild_card_record).s19)));
  p = ((void *)parse_csv_token__6TLobbyFPvPv((char *)(p), (char *)((*(Entry_8024220C *)&selected_guild_card_record).s2A)));
  p = ((void *)parse_csv_token__6TLobbyFPvPv((char *)(p), (char *)((*(Entry_8024220C *)&selected_guild_card_record).s2A)));
  parse_csv_token__6TLobbyFPvPv((char *)(p), (char *)((*(Entry_8024220C *)&selected_guild_card_record).s3B));
  TLobby__sub_802422EC((*(Entry_8024220C *)&selected_guild_card_record).f4C, arg0->f64);
  __as__21TPlyMeetUserExtensionFRC21TPlyMeetUserExtension((*(Entry_8024220C *)&selected_guild_card_record).ext, arg0->ext);
}

void TLobby__sub_802422EC(void *arg0, void *arg1) {
    *(s32 *)((s8 *)arg0 + 0) = (s32) *(s32 *)((s8 *)arg1 + 0);
    *(s32 *)((s8 *)arg0 + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
    *(s16 *)((s8 *)arg0 + 8) = (s16) *(s16 *)((s8 *)arg1 + 8);
}

void find_and_load_com_card__6TLobbyFUi(u32 arg0) {
    s32 n;
    s32 i;
    n = ((s32 (*)(void))get_com_card_data__6TLobbyFv)();
    for (i = 0; i < n; i++) {
        get_com_card_entry__6TLobbyFi(i);
        if (arg0 == ((u32 (*)(void))TLobby__sub_802428F8)()) break;
    }
    if (i < n) {
        copy_com_card_entry__6TLobbyFPvPv((Entry_80242380 *)(selected_guild_card_record), (Entry_80242380 *)(get_com_card_entry__6TLobbyFi(i)));
    }
}

Entry_80242380 *copy_com_card_entry__6TLobbyFPvPv(Entry_80242380 *dst, Entry_80242380 *src) {
    dst->id = src->id;
    dst->f4 = src->f4;
    __copy(dst->name, src->name, 0x11);
    __copy(dst->s19, src->s19, 0x11);
    __copy(dst->s2A, src->s2A, 0x11);
    __copy(dst->s3B, src->s3B, 0x11);
    dst->f4C = src->f4C;
    dst->f54 = src->f54;
    dst->ext = src->ext;
    return dst;
}

void* get_com_card_entry__6TLobbyFi(int a0) {  return (char*)lbl_80517F9C + a0 * 188; }
typedef char RecoveredGlobal_8024259C_TLobby__data_8050AAAC_size[sizeof(RecoveredGlobal_8024259C_TLobby__data_8050AAAC) == 0x28 ? 1 : -1];

char *parse_csv_token__6TLobbyFPvPv(char *src, char *dst) {
    s32 i;
    for (i = 0x10; i != 0; i--) {
        char c = *src;
        if (c == 0) break;
        src++;
        if (c == ',') break;
        *dst = c;
        dst++;
    }
    if (*src == ',') {
        src++;
    }
    *dst = 0;
    return src;
}

char *skip_to_comma_field__6TLobbyFPvii(char *s, s32 a, s32 b) {
    s32 i;
    for (i = a + 1; i < b;) {
        if (*s == '\0') return s;
        if (*s++ == ',') i++;
    }
    return s;
}

char *build_text_from_comma_list__6TLobbyFPv(char *list) {
    char buf[0x11];
    char *s;
    char *d;
    s32 i;
    s32 count;
    text_builder_reset();
    s = list;
    count = 1;
    while (*s != '\0') {
        if (*s++ == ',') {
            count++;
        }
    }
    for (i = 0; i < count; i++) {
        TWindowSubStatusDisp::append_comma();
        s = skip_to_comma_field__6TLobbyFPvii(list, i, count);
        d = buf;
        while (*s != '\0' && *s != ',') {
            *d++ = *s++;
        }
        *d = '\0';
        text_builder_append(buf);
    }
    return get_shared_text_buffer();
}

void TLobby__sub_8024259C(s32 arg0) {
    if ((u32) TLobby__protocol_instance != 0U) {
        memset((void *)&TLobby__data_8050AAAC.value, 0, 0x11);
        strncpy((void *)&TLobby__data_8050AAAC.value, (void *)(arg0 + 0x19), 0x10);
        *(s8 *)((s8 *)&TLobby__data_8050AAAC.value + 0x10) = 0;
        seq_jump__9TProtocolFPUcR21TPlyMeetUserExtension(TLobby__protocol_instance, (void *)(arg0 + 0x4C), (void *)(arg0 + 0x58));
    }
}
}

#pragma pop

struct RecoveredGlobal_802426E8_lbl_80517F9C {
    s32 value;
    u8 remaining[0x5E0];
};

struct RecoveredGlobal_8024287C_lbl_80517EE0 {
    s32 value;
    u8 remaining[0xB8];
};

struct RecoveredGlobal_8024287C_lbl_80517F9C {
    s32 value;
    u8 remaining[0x5E0];
};

extern "C" {
#define lbl_80517F9C (*(RecoveredGlobal_802426E8_lbl_80517F9C *)lbl_80517F9C)
extern int com_card_entry_count;
#define selected_guild_card_record (*(RecoveredGlobal_8024287C_lbl_80517EE0 *)selected_guild_card_record)
#define lbl_80517F9C (*(RecoveredGlobal_802426E8_lbl_80517F9C *)lbl_80517F9C)
u32 find_card_by_id__17TWindowSubComCardFUl();
int construct_guild_card_tag_array(void*);
s32 get_com_card_list__6TLobbyFPv();

extern s32 lbl_805D63D8;

void init_player_entry__6TLobbyFPvPv(u8 *arg0, u8 *arg1) {
    s32 temp_r5;
    void *p;

    *(s32 *)((s8 *)arg0 + 0) = (s32) *(s32 *)((s8 *)arg1 + 0xC);
    temp_r5 = lbl_805D63D8;
    lbl_805D63D8 = temp_r5 + 1;
    *(s32 *)((s8 *)arg0 + 4) = temp_r5;
    ((s32 (*)(void*, void*, int))TLobby__sub_802422EC)(arg0 + 0x4C, arg1 + 0x10, temp_r5);
    __as__21TPlyMeetUserExtensionFRC21TPlyMeetUserExtension(arg0 + 0x58, arg1 + 0x60);
    ((TLobby *)arg0)->get_id();
    if (find_card_by_id__17TWindowSubComCardFUl() == 0U) {
        strncpy(arg0 + 8, (void *) (((TWindowSubStatusDisp *)arg0)->get_sub_disp_ptr()), 0x10);
    } else {
        strncpy(arg0 + 8, (void *) (get_com_card_list__6TLobbyFPv()), 0x10);
    }
    *(s8 *)((s8 *)arg0 + 0x18) = 0;
    p = ((void* (*)(void*))build_text_from_comma_list__6TLobbyFPv)(arg1 + 0x1C);
    p = ((void* (*)(void*, void*))parse_csv_token__6TLobbyFPvPv)(p, arg0 + 0x19);
    p = ((void* (*)(void*, void*))parse_csv_token__6TLobbyFPvPv)(p, arg0 + 0x2A);
    p = ((void* (*)(void*, void*))parse_csv_token__6TLobbyFPvPv)(p, arg0 + 0x2A);
    ((void* (*)(void*, void*))parse_csv_token__6TLobbyFPvPv)(p, arg0 + 0x3B);
}

typedef char RecoveredGlobal_802426E8_lbl_80517F9C_size[sizeof(RecoveredGlobal_802426E8_lbl_80517F9C) == 0x5E4 ? 1 : -1];
void remove_com_card_entry__6TLobbyFi(s32 arg0) {
    u8 *lobby;
    if (arg0 < 7) {
        lobby = (u8 *)&lbl_80517F9C.value + (arg0 * 0xBC);
        ((TLobby *)lobby)->move_words((u32 *)(lobby + 0xBC), (s32)((void *) ((u32) ((7 - arg0) * 0xBC) >> 2U)));
    }
    (*(s32 *)&com_card_entry_count) -= 1;
}

int TLobby__sub_8024273C(void *p) {
    u8 *entry;
    s32 slot = remove_com_card_by_id__6TLobbyFUi(*(u32 *)((u8 *)p + 0xC));
    entry = (u8 *)&lbl_80517F9C.value;
    entry += slot * 0xBC;
    init_player_entry__6TLobbyFPvPv(entry, (u8 *)p);
    com_card_entry_count++;
    TLobby__sub_80242918();
}

s32 remove_com_card_by_id__6TLobbyFUi(u32 arg0) {
    s32 i;
    s32 n;
    n = ((s32)get_com_card_data__6TLobbyFv());
    for (i = 0; i < n; i++) {
        if (arg0 == ((u32)((TLobby *)(((void* (*)(s32))get_com_card_entry__6TLobbyFi)(i)))->get_id())) {
            remove_com_card_entry__6TLobbyFi(i);
            n -= 1;
        }
    }
    if (n < 8) {
        return n;
    }
    remove_com_card_entry__6TLobbyFi(0);
    return 7;
}

void reset_state_805D63DC__6TLobbyFv(void*) { com_card_entry_count = 0; TLobby::clear_flag_bit2(); }

void reset_state__6TLobbyFPv(void* p) { reset_state_805D63DC__6TLobbyFv(p); }
void TLobby__sub_8024285C(void* p) { reset_state_805D63DC__6TLobbyFv(p); }

typedef char RecoveredGlobal_8024287C_lbl_80517EE0_size[sizeof(RecoveredGlobal_8024287C_lbl_80517EE0) == 0xBC ? 1 : -1];
typedef char RecoveredGlobal_8024287C_lbl_80517F9C_size[sizeof(RecoveredGlobal_8024287C_lbl_80517F9C) == 0x5E4 ? 1 : -1];
void construct_entry_arrays__6TLobbyFv(void) {
    TLobby__sub_802428C4((void*)((void *) &selected_guild_card_record.value));
    ((s32 (*)(s32 *, void *(*)(void *), s32, s32, s32))__construct_array)(&(*(RecoveredGlobal_8024287C_lbl_80517F9C *)&lbl_80517F9C).value, TLobby__sub_802428C4, 0, 0xBC, 8);
}

void* TLobby__sub_802428C4(void* p) { construct_guild_card_tag_array((char*)p + 0x58); return p; }
s32 TLobby__sub_802428F8(void* p) { return *(s32*)((char*)p + 0x4); }

int get_com_card_data__6TLobbyFv(void) {  return com_card_entry_count; }

}
#undef lbl_80517F9C
#undef selected_guild_card_record

u8 selected_guild_card_record[0xBC];
unsigned char lbl_80517F9C[0x5E4];
