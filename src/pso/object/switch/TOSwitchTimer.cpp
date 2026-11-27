#include "types.h"
#include "pso/object/switch/TOSwitchTimer.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/render/render_util.h"
#include "pso/system/NinjaTypes.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/task/TMainTask.h"
#include <stddef.h>
#include "pso/object/switch/TOChatSensor.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/network/protocol/SubcommandHandlers.h"
#pragma readonly_strings on

void handle_6x93_set_switch_flag_from_timer(G_SetSwitchFlagFromTimer_6x93 *command) {
    command->bswap();
    if (command->should_set == 1) {
        set_floor_switch_flag(command->switch_flag_num, command->switch_flag_floor);
    } else if (command->switch_flag_floor != get_current_floor()) {
        clear_floor_switch_flag(command->switch_flag_num, command->switch_flag_floor);
    }
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void TOSwitchTimer::send_switch_states() {
    G_SetSwitchFlagFromTimer_6x93 clear_packet;
    G_SetSwitchFlagFromTimer_6x93 set_packet;
    u16 *switch_id;
    s32 i;
    if ((u32) this->mode == 0U) {
        if ((u16) this->trigger_switch < 0x100U) {
            clear_packet.init();
            clear_packet.switch_flag_floor = this->floor;
            clear_packet.switch_flag_num = this->trigger_switch;
            clear_packet.should_set = 0;
            clear_packet.send();
            clear_floor_switch_flag((this->trigger_switch), (this->floor));
        }
    } else {
        switch_id = target_switches;
        i = 0;
        do {
            if ((u16) *switch_id < 0x100U) {
                set_packet.init();
                set_packet.switch_flag_floor = this->floor;
                set_packet.switch_flag_num = *switch_id;
                set_packet.should_set = 1;
                set_packet.send();
            }
            i += 1;
            switch_id++;
        } while (i != 3);
    }
}
#pragma pop



void TOSwitchTimer::init_from_set_data() {
    s32 i;
    u16 *ids;

    this->state = 0;
    this->timer = 0;
    this->mode = (u32)this->rotation_x;
    if (this->mode >= 2) {
        this->mode = 1;
    }
    this->tick_sound = this->rotation_y;
    if ((s32)this->tick_sound > 1) {
        this->tick_sound = 0;
    }
    this->duration = this->rotation_z;
    if ((s32)this->duration < 0) {
        this->duration = 0;
    }
    this->steady_after = (s32)this->duration * 3 / 4;
    this->trigger_switch = this->set_params[0];
    if (this->trigger_switch < 0x100) {
        this->trigger_state = is_current_floor_switch_set(this->trigger_switch);
    } else {
        this->trigger_switch = 0xFFFF;
        this->trigger_state = 0;
    }
    ids = target_switches;
    for (i = 0; i < 3; i++) {
        *ids = (u32)set_params[i] >> 16;
        if (*ids >= 0x100) {
            *ids = 0xFFFF;
        }
        ids++;
    }
    this->floor = get_current_floor();
}

const char *switch_timer_name = "TOSwitchTimer";




void TOSwitchTimer::render() {
    if (TObjPlayer::check_demo_mode() == 1) {
        NJS_ARGB color;
        color.a = 0.3f;
        color.r = 0.6f;
        color.g = 0.3f;
        color.b = 0.0f;
        debug_draw_sphere(&position, &color, 10.0f);
    }
}

void TOSwitchTimer::run_task() {
    s32 elapsed;
    u32 switch_state;

    switch (this->state) {
    case 0:
        switch_state = is_current_floor_switch_set(this->trigger_switch);
        if ((s32) this->trigger_state != (s32) switch_state) {
            this->trigger_state = switch_state;
            if (switch_state == 1) {
                this->state = 1;
                this->timer = 0;
                if ((u32) this->mode == 0U) {
                    this->trigger_state = 0U;
                }
            }
        }
        return;
    case 1:
        if (this->tick_sound == 1) {
            if (this->timer < this->steady_after) {
                if ((this->timer % 30) == 0) {
                    play_sound_effect(0x53218, 0, 0, 0);
                }
            } else {
                play_persistent_sound(0x53218, this, NULL, 0, 0);
            }
        }
        elapsed = this->timer;
        this->timer = (elapsed + 1);
        if (elapsed == (s32) this->duration) {
            send_switch_states();
            this->state = 0;
        }
        break;
    }
}


void *TOSwitchTimer::create(void *set_data) {
    void *o = (void *)new TOSwitchTimer(tl_05, set_data);
    return o;
}

void TOSwitchTimer::free_resources() {  }
void TOSwitchTimer::load_resources() {  }
TOSwitchTimer::~TOSwitchTimer() {
    if ((u32) this->mode == 0U) {
        clear_floor_switch_flag(this->trigger_switch, (s16) this->floor);
    }
}
TOSwitchTimer::TOSwitchTimer(TObject *parent, void *set_data) : TObjBase(parent) {
    m_name = switch_timer_name;
    apply_object_set_data(set_data);
    init_from_set_data();
}
