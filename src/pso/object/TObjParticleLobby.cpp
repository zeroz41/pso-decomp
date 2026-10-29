#include "types.h"
#include "pso/TParticleCtrl.h"
#include "pso/object/TObjParticleLobby.h"
#include "pso/TMainTask.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/boss/TBoss4Type2_800874F4.h"
#include "pso/misc/TLobby.h"
#include "pso/player/TObjPlayer.h"

// Written from its last function back: the unit is built -inline off,deferred
// (configure.py), which emits the functions in reverse.

#pragma readonly_strings on

const char *obj_particle_lobby_class_name = "TObjParticleLobby";

TObjParticleLobby::TObjParticleLobby(TObject *parent, void *set_data) : TObjMapObject(parent) {
    m_name = obj_particle_lobby_class_name;
    apply_object_set_data(set_data);
    emitter = create_particle_emitter(&position, 1);
    setup_emitter();
    fade_scale = 1.0f;
}

TObjParticleLobby::~TObjParticleLobby() {
    if (emitter != NULL) {
        emitter->queue_destruction();
        emitter = NULL;
    }
}

void TObjParticleLobby::load_resources() {}

void TObjParticleLobby::free_resources() {}

void *TObjParticleLobby::create(void *set_data) {
    return new TObjParticleLobby(tl_05, set_data);
}

void TObjParticleLobby::setup_emitter() {
    u16 flags;
    u16 base;
    s32 kind;
    f32 dir;
    flags = 0;
    switch (set_params[0]) {
    case 1:
        event_theme = 1;
        break;
    case 2:
        event_theme = 5;
        break;
    case 3:
        event_theme = 7;
        break;
    case 4:
        event_theme = 3;
        break;
    case 5:
        event_theme = 9;
        break;
    case 6:
        event_theme = 8;
        break;
    case 7:
        event_theme = 4;
        break;
    case 8:
        event_theme = 10;
        break;
    case 9:
        event_theme = 11;
        break;
    default:
        event_theme = 0;
        break;
    }
    if (event_theme == get_event_theme_index()) {
        fade_state = 3;
    } else {
        fade_state = 0;
    }
    kind = (s32)scale.x;
    if (kind < 0) {
        kind = 0;
    }
    if (kind >= 0x240) {
        kind = 0x23F;
    }
    if (emitter != NULL) {
        emitter->set_param_ptr(kind);
    }
    dir = scale.z;
    if (dir < 0.0f) {
        base = 0x2;
        if (set_params[1] == 1) {
            base = 0x42;
        }
        flags = base;
        if (set_params[2] == 1) {
            flags = base | 0x2000;
        }
    } else if ((s32)dir == 2) {
        base = 0x8;
        if (set_params[1] == 1) {
            base = 0x48;
        }
        flags = base;
        if (set_params[2] == 1) {
            flags = base | 0x2000;
        }
    } else if ((s32)dir == 3) {
        base = 0x4;
        if (set_params[1] == 1) {
            base = 0x44;
        }
        flags = base;
        if (set_params[2] == 1) {
            flags = base | 0x2000;
        }
    } else {
        if (set_params[1] == 1) {
            flags = 0x40;
        }
        if (set_params[2] == 1) {
            flags |= 0x2000;
        }
    }
    if (emitter != NULL) {
        emitter->set_flags(flags);
    }
    if (emitter != NULL) {
        emitter->set_position(&position);
    }
}

void TObjParticleLobby::run_task() {
    if (TObjPlayer::check_demo_mode() == 1) {
        demo_step();
        return;
    }
    switch (fade_state) {
    case 0:
        if (event_theme == get_event_theme_index()) {
            fade_state = 2;
        }
        if (emitter != NULL) {
            emitter->enable();
        }
        break;
    case 2:
        fade_scale += 0.1f;
        if (fade_scale >= 1.0f) {
            fade_scale = 1.0f;
            fade_state = 3;
        }
        if (emitter != NULL) {
            emitter->set_scale(fade_scale, 1.0f);
        }
        break;
    case 1:
        fade_scale -= 0.1f;
        if (fade_scale <= 0.0f) {
            fade_scale = 0.0f;
            fade_state = 0;
            break;
        }
        if (emitter != NULL) {
            emitter->set_scale(fade_scale, 1.0f);
        }
        break;
    case 3:
    default:
        if (event_theme != get_event_theme_index()) {
            fade_state = 1;
        }
        break;
    }
}

void TObjParticleLobby::render() {}

void TObjParticleLobby::demo_step() {}

// The lobby's event theme as this object's set data numbers it: theme 12
// shows the default (0) set and theme 13 the one for 8.
s32 TObjParticleLobby::get_event_theme_index() {
    s32 theme = TLobby::get_filtered_event_theme();
    switch (theme) {
    case 12:
        return 0;
    case 13:
        return 8;
    }
    return theme;
}
