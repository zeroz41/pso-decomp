#include "pso/TParticleCtrl.h"
#include "types.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/object/TObjParticleLobby.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TNowLoading.h"
#include "pso/misc/TOKey.h"
#include "pso/player/TObjPlayer.h"

#pragma readonly_strings on

extern "C" {
const char *lbl_805D44B8 = "TObjParticleLobby";
}


struct RecoveredGlobal_80369ADC___vt__17TObjParticleLobby {
    s32 value;
    u8 remaining[0x34];
};

struct Self_803696A0 { u8 pad0[0xC8]; s32 state; f32 t; s32 target; void *ctrl; };

extern "C" {
void *create_particle_emitter(void *pos, s32 id);
s32 __ct__13TUnk_804AFBF8FP7TObject(void *, void *);
extern s32 __vt__17TObjParticleLobby[];
extern const char *lbl_805D44B8;
void set_flags__11TBoss4Type2FUl(void *, u16);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

s32 get_event_theme_index__17TObjParticleLobbyFv(void) {
    s32 r = TLobby::get_filtered_event_theme();
    switch (r) {
    case 12:
        return 0;
    case 13:
        return 8;
    }
    return r;
}

void TObjParticleLobby__sub_80369698(void) {  }
void TObjParticleLobby::render() {  }

extern void *tl_05;

void TObjParticleLobby::run_task() {
    Self_803696A0 *o = (Self_803696A0 *)this;
    if (TObjPlayer::check_demo_mode() == 1) {
        ((void (*)(void *))TObjParticleLobby__sub_80369698)(o);
        return;
    }
    switch (*(s32 *)&this->m_c8) {
    case 0:
        if (*(s32 *)&this->m_d0 == ((s32 (*)(void *))get_event_theme_index__17TObjParticleLobbyFv)(o)) {
            *(s32 *)&this->m_c8 = 2;
        }
        if (o->ctrl != NULL) {
            ((TParticleCtrl *)(o->ctrl))->enable();
        }
        break;
    case 2:
        o->t += 0.1f;
        if (o->t >= 1.0f) {
            o->t = 1.0f;
            *(s32 *)&this->m_c8 = 3;
        }
        if (o->ctrl != NULL) {
            ((TParticleCtrl *)(o->ctrl))->set_scale(o->t, 1.0f);
        }
        break;
    case 1:
        o->t -= 0.1f;
        if (o->t <= 0.0f) {
            o->t = 0.0f;
            *(s32 *)&this->m_c8 = 0;
            break;
        }
        if (o->ctrl != NULL) {
            ((TParticleCtrl *)(o->ctrl))->set_scale(o->t, 1.0f);
        }
        break;
    case 3:
    default:
        if (*(s32 *)&this->m_d0 != ((s32 (*)(void *))get_event_theme_index__17TObjParticleLobbyFv)(o)) {
            *(s32 *)&this->m_c8 = 1;
        }
        break;
    }
}

void TObjParticleLobby::setup_emitter() {
    u16 flags;
    u16 t;
    s32 v;
    f32 f;
    flags = 0;
    switch (*(u32 *)&this->set_params[0]) {
    case 1:
        *(s32 *)&this->m_d0 = 1;
        break;
    case 2:
        *(s32 *)&this->m_d0 = 5;
        break;
    case 3:
        *(s32 *)&this->m_d0 = 7;
        break;
    case 4:
        *(s32 *)&this->m_d0 = 3;
        break;
    case 5:
        *(s32 *)&this->m_d0 = 9;
        break;
    case 6:
        *(s32 *)&this->m_d0 = 8;
        break;
    case 7:
        *(s32 *)&this->m_d0 = 4;
        break;
    case 8:
        *(s32 *)&this->m_d0 = 0xA;
        break;
    case 9:
        *(s32 *)&this->m_d0 = 0xB;
        break;
    default:
        *(s32 *)&this->m_d0 = 0;
        break;
    }
    if (*(s32 *)&this->m_d0 == ((s32 (*)(void *))get_event_theme_index__17TObjParticleLobbyFv)(this)) {
        *(s32 *)&this->m_c8 = 3;
    } else {
        *(s32 *)&this->m_c8 = 0;
    }
    v = (s32)this->scale.x;
    if (v < 0) {
        v = 0;
    }
    if (v >= 0x240) {
        v = 0x23F;
    }
    if (*(void * *)&this->m_d4 != NULL) {
        ((TBoss4Type2 *)(*(void * *)&this->m_d4))->set_param_ptr(v);
    }
    f = this->scale.z;
    if (f < 0.0f) {
        t = 0x2;
        if (*(s32 *)&this->set_params[1] == 1) {
            t = 0x42;
        }
        flags = t;
        if (*(s32 *)&this->set_params[2] == 1) {
            flags = t | 0x2000;
        }
    } else if ((s32)f == 2) {
        t = 0x8;
        if (*(s32 *)&this->set_params[1] == 1) {
            t = 0x48;
        }
        flags = t;
        if (*(s32 *)&this->set_params[2] == 1) {
            flags = t | 0x2000;
        }
    } else if ((s32)f == 3) {
        t = 0x4;
        if (*(s32 *)&this->set_params[1] == 1) {
            t = 0x44;
        }
        flags = t;
        if (*(s32 *)&this->set_params[2] == 1) {
            flags = t | 0x2000;
        }
    } else {
        if (*(s32 *)&this->set_params[1] == 1) {
            flags = 0x40;
        }
        if (*(s32 *)&this->set_params[2] == 1) {
            flags |= 0x2000;
        }
    }
    if (*(void * *)&this->m_d4 != NULL) {
        set_flags__11TBoss4Type2FUl(*(void * *)&this->m_d4, flags);
    }
    if (*(void * *)&this->m_d4 != NULL) {
        ((TParticleCtrl *)*(void * *)&this->m_d4)->set_position((u8 *)this + 0x38);
    }
}

void *TObjParticleLobby::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xD8);
    if (o != NULL) {
        o = TObjParticleLobby__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TObjParticleLobby__sub_80369A60(void) {  }
void TObjParticleLobby__sub_80369A64(void) {  }

void *__dt__17TObjParticleLobbyFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__17TObjParticleLobby;
        if (*(void **)((s8 *)arg0 + 0xD4) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0xD4)); ((TObjParticleLobby *)arg0)->m_d4 = 0; }
        __dt__13TUnk_804AFBF8Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_80369ADC___vt__17TObjParticleLobby_size[sizeof(RecoveredGlobal_80369ADC___vt__17TObjParticleLobby) == 0x38 ? 1 : -1];
u8 *TObjParticleLobby__ct(u8 *particle_lobby, s32 arg1, s32 arg2) {
    __ct__13TUnk_804AFBF8FP7TObject((void *)particle_lobby, (void *)arg1);
    *(s32 **)((s8 *)particle_lobby + 0x18) = &(*(RecoveredGlobal_80369ADC___vt__17TObjParticleLobby *)&__vt__17TObjParticleLobby).value;
    *(s32 *)((s8 *)particle_lobby + 0) = (s32) ((s32)lbl_805D44B8);
    ((TObjParticleLobby *)(particle_lobby))->apply_object_set_data((void *)arg2);
    ((TObjParticleLobby *)particle_lobby)->m_d4 = (s32)create_particle_emitter((particle_lobby + 0x38), 1);
    ((TObjParticleLobby *)particle_lobby)->setup_emitter();
    *(f32 *)((s8 *)particle_lobby + 0xCC) = (f32) (1.0f);
    return particle_lobby;
}

}
