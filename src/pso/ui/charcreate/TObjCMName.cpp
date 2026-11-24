#pragma defer_codegen on
#pragma readonly_strings on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/render/Draw2D.h"
#include "pso/render/ColorLineList.h"
#include "pso/ui/MenuText.h"
#include "pso/ui/charcreate/CreationInput.h"
#include "types.h"
#include "pso/math/AngleLookup.h"
#include "pso/ui/UISprite.h"
#include "pso/render/render_util.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/ui/charcreate/TObjCMName.h"
#include "pso/ui/charcreate/TObjCMHairMenu.h"
#include "pso/ui/charcreate/TObjCMAssignMenu.h"
#include "pso/ui/charcreate/TObjCMMainMenu.h"
#include "pso/ui/charcreate/TObjCMMainMenu_8028D9A8.h"
#include "pso/camera/CreationCamera.h"
#include "pso/ui/charcreate/TObjCMProportion.h"
#include "pso/ui/charcreate/TObjCMAutoMkData.h"
#include "pso/ui/charcreate/CharacterCreationModels.h"
#include "pso/ui/charcreate/CharacterAppearanceTables.h"
#include "pso/ui/charcreate/TChCrCharSelect.h"
#include "pso/ui/charcreate/TChCrEffCtrlPl.h"
#include "pso/ui/charcreate/TChCrEffTag.h"
#include "pso/ui/charcreate/TObjCMIcon.h"
#include "pso/ui/charcreate/TObjCMIcon_80299488.h"
#include "pso/system/task/TObject.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/TWindowMakeTeam.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/object/TObjLuker.h"
#include "pso/unk/TLobby_801E2F94.h"
#include "pso/unk/text_801E3F24.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include <stdlib.h>
#include <string.h>
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/player/TPlyCharData.h"
#include "pso/system/vector.h"
#include "pso/system/SoundEffect.h"
#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/ui/charcreate/TObjCMMainMenu_8028EA88.h"
#include "pso/ui/charcreate/TObjCMHexTile.h"
#include "pso/unk/text_802993F0.h"
#include "pso/object/TCMCharacter.h"


struct Menu_80296D68
{
  u8 pad0[0x1C];
  u8 *app;
  s32 enabled;
  s32 index;
  s32 value;
  s32 limit;
  s32 wrap;
  u8 pad34[4];
  s32 ticks;
  s32 active;
  f32 fade;
  s32 step;
  s32 target;
  s32 columns;
  u8 pad50[8];
  f32 scroll;
};



typedef void (TObjCMMainMenu::*MainMenuStateHandler)();

extern "C" {
void run_task__16TObjCMAssignMenuFv(void *arg0);
}

s32 creation_menu_selected_entry;
s32 TObjCMMainMenu::state;


struct CreationMenuModeList {
    s32 count;
    s32 *entries;
};



extern "C" {
void copy_player_visual_record(void *, void *);

const char *TObjCMMainMenu::class_name = "TObjCMMainMenu";

const vec2f main_menu_icon_position = {614.0f, 434.0f};

CreationMenuEntry TObjCMMainMenu::menu_entries[10] = {
    {3, &TObjCMMainMenu::open_assign_menu},
    {2, &TObjCMMainMenu::open_assign_menu},
    {4, &TObjCMMainMenu::open_hair_menu},
    {0, &TObjCMMainMenu::open_assign_menu},
    {1, &TObjCMMainMenu::open_assign_menu},
    {1, &TObjCMMainMenu::open_assign_menu},
    {-1, &TObjCMMainMenu::open_proportion_menu},
    {-1, &TObjCMMainMenu::open_name_menu},
    {-1, &TObjCMMainMenu::open_auto_mk_menu},
    {-1, &TObjCMMainMenu::confirm_selection},
};

s32 creation_menu_modes_0[8] = {1, 2, 3, 4, 6, 7, 8, 9};

s32 creation_menu_modes_1[6] = {0, 5, 6, 7, 8, 9};

__declspec(section ".data") s32 creation_menu_modes_2[2] = {7, 9};

s32 creation_menu_modes_3[3] = {2, 3, 9};

s32 creation_menu_modes_4[5] = {0, 5, 9, 7, 9};

s32 creation_menu_modes_5[1] = {9};

CreationMenuModeList creation_menu_mode_lists[6] = {
    {8, creation_menu_modes_0}, {6, creation_menu_modes_1},
    {2, creation_menu_modes_2}, {3, creation_menu_modes_3},
    {3, creation_menu_modes_4}, {1, creation_menu_modes_5},
};
}

void reset_character_creation_figure_rotation(void);
void draw_creation_ruler_lines(f32 farg0);
NJS_COLOR proportion_frame_colors[4];
NJS_POINT2 proportion_marker_points[4];
NJS_COLOR proportion_marker_colors[4];

// RGBA colour of the hair colour bars (inferred: the alpha byte is set from the fade).
union HairBarColor {
    u32 rgba;
    u8 c[4];
};


extern "C" {
void restore_saved_depth_alpha_state();
}

s32 *TObjCMMainMenu::get_name_buffer() {
    return (s32 *)character_creation_name_buffer;
}

s32 TObjCMMainMenu::is_not_dressing_room_mode() {
    return creation_dressing_room_mode_flag == 0;
}

void TObjCMMainMenu::set_speed(f32 x) {
    if (creation_figure_object != NULL) {
        creation_figure_object->position.x = x;
    }
}

void TObjCMMainMenu::rotate_figure(s32 delta) { creation_figure_rotation_y += delta; }

void TObjCMMainMenu::set_selection(int selection) { creation_camera_mode = selection; }

f32 TObjCMMainMenu::get_proportion() {
    return creation_view_shift;
}

f32 TObjCMMainMenu::get_scale() {
    return ui_sprite_scale;
}

void TObjCMMainMenu::clear_task_state() { state = 0; }

TObjCMMainMenu::TObjCMMainMenu(TObject *parent) : TObject(parent) {
    m_name = class_name;
    character = creation_player_character;
    if (!(character->flags & 0xA) && character->classId == TObjCMMainMenu__sub_8028D9A8()->classId) {
        copy_player_visual_record(character, TObjCMMainMenu__sub_8028D9A8());
    }
    strncpy(character->name, (const char *)get_name_buffer(), 0xC);
    character->name[0xC] = 0;
    character->extraModel = 0;
    character->flags &= ~0xA;
    if (character->section == -1) {
        if (character->flags & 0xA) {
            mode = 2;
        } else if (!(character->classFlags & 0x10)) {
            mode = 0;
        } else {
            mode = 1;
        }
    } else if (character->flags & 0xA) {
        mode = 5;
    } else if (!(character->classFlags & 0x10)) {
        mode = 3;
    } else {
        mode = 4;
    }
    entry_count = creation_menu_mode_lists[mode].count;
    entries = creation_menu_mode_lists[mode].entries;
    state = 0;
    selected_entry = 0;
    creation_menu_selected_entry = entries[selected_entry];
    fn_802993F0();
    reveal = 0.0f;
    submenu_fade = 0.0f;
    slide_offset = 0.0f;
    unknown44 = 0.0f;
    progress = 0.0f;
    idle_ticks = 0;
    preview = 0.0f;
    set_speed(30.0f);
    nodes = new TObject(NULL);
    fn_802947A8();
    fn_8029945C(&main_menu_icon_position);
    after_construct();
}

TObjCMMainMenu::~TObjCMMainMenu() {
    if (nodes != NULL) {
        delete nodes;
        nodes = NULL;
    }
    character->nameColor = -1;
    character->version = 2;
}

TObjCMMainMenu *TObjCMMainMenu::create(TObject *parent) {
    return new TObjCMMainMenu(parent);
}

#pragma push
#pragma fp_contract on
void TObjCMMainMenu::run_task() {
    f32 magnitude;

    TChCrCharSelect::reset_proportions();
    rand();
    update_menu_reveal(reveal_ticks++);
    update_submenu_fade();
    update_slide_offset();
    static MainMenuStateHandler table[7] = {
        &TObjCMMainMenu::handle_creation_input, &TObjCMMainMenu::sub_8029862C, &TObjCMMainMenu::update_confirmation,
        &TObjCMMainMenu::sub_8029862C, &TObjCMMainMenu::sub_8029862C, &TObjCMMainMenu::finish_confirmation,
        &TObjCMMainMenu::finish_cancel,
    };
    (this->*table[state])();
    creation_menu_selected_entry = this->entries[this->selected_entry];
    TObjCMMainMenu::update_random_proportion_action(this);
    after_state_update();
    switch (state) {
    case 4:
    case 6:
        if (this->preview > 0.0f) {
            if ((this->preview += -0.2f) < 0.0f) {
                this->preview = 0.0f;
            }
        }
        break;
    default:
        if (TAdSinglePlyChrSelectGC::is_active() != 0 && get_char_creation_figure_draw_flag() != 0) {
            if (this->preview < 1.0f) {
                f32 step = 0.083333336f;
                if (this->preview > 0.5833333f) {
                    step *= -0.8f * ((this->preview - 0.5833333f) / 0.4166667f) + 1.0f;
                }
                f32 v = (this->preview += step);
                if (v > 1.0f) {
                    this->preview = 1.0f;
                }
            }
        } else {
            this->preview = 0.0f;
        }
        break;
    }
    TObjCMMainMenu::set_speed(30.0f * (1.0f - this->preview));
    get_creation_pad_stick(0, &magnitude);
    if (magnitude > 0.0f || creation_buttons_held(0xF0) != 0) {
        if (this->idle_ticks > 0) {
            request_creation_motion(0);
        }
        this->idle_ticks = 0;
    } else {
        this->idle_ticks++;
        if (this->idle_ticks == 0x384) {
            request_creation_motion(1);
        } else if (this->idle_ticks == 0x546) {
            request_creation_motion(2);
        } else if (this->idle_ticks > 0x546) {
            this->idle_ticks = 0x546;
        }
    }
    ((TObject *)(this->nodes))->run_tasks();
    after_run_task();
}

#pragma pop
void TObjCMMainMenu::handle_creation_input() {
    s32 next;
    s32 prev;
    if (is_not_dressing_room_mode() != 0) {
        TChCrEffTag::set_eff_tag(1);
    } else {
        TChCrEffTag::set_eff_tag(2);
    }
    if (TAdSinglePlyChrSelectGC::is_active() != 0) {
        if (character->section == -1 && creation_buttons_pressed(2) != 0) {
            play_sound_effect(0x53704, 0, 0, 0);
            TObjCMMainMenu__sub_8028D9B4(character);
            delay = 7;
            state = 6;
            return;
        }
        if (creation_direction_repeated(0x20) != 0) {
            next = selected_entry + 1;
            selected_entry = next;
            if (next >= entry_count) {
                this->selected_entry = 0;
            }
            play_sound_effect(0x54100, 0, 0, 0);
        } else if (creation_direction_repeated(0x10) != 0) {
            prev = selected_entry - 1;
            selected_entry = prev;
            if (prev < 0) {
                selected_entry = entry_count - 1;
            }
            play_sound_effect(0x54100, 0, 0, 0);
        }
        if (creation_buttons_pressed(4) != 0) {
            CreationMenuEntry *entry = &menu_entries[entries[selected_entry]];
            (this->*entry->select)();
        }
    }
}

void TObjCMMainMenu::sub_8029862C() {  }

#pragma push
#pragma fp_contract on
void TObjCMMainMenu::update_confirmation() {
    f32 progress;
    f32 fv;
    s32 delay;
    this->progress += 0.013333334f;
    delay = this->delay - 1;
    this->delay = delay;
    if (delay < 0) {
        this->delay = 0;
    }
    if (((s32) creation_resource_ready_state == 2) || ((s32) this->delay == 0)) {
        progress = this->progress;
        if (progress < 0.8f) {
            this->progress = (f32) ((0.25f * (0.8f - progress)) + progress);
        }
        fv = this->progress;
        if (fv > 1.0f) {
            this->progress = 1.0f;
        }
        if (creation_buttons_pressed(4) != 0) {
            play_sound_effect(0x52D01, 0, 0, 0);
            this->delay = 7;
            state = 5;
            TObjCMMainMenu::create_fade((void *)7, (void *)1);
        }
    } else {
        fv = this->progress;
        if (fv > 0.8f) {
            this->progress = 0.8f;
        }
    }
}

#pragma pop
void TObjCMMainMenu::finish_confirmation() {
    s32 delay;

    delay = this->delay - 1;
    this->delay = delay;
    if (delay < 0) {
        state = 3;
    }
}

void TObjCMMainMenu::finish_cancel() {
    s32 delay;

    delay = this->delay - 1;
    this->delay = delay;
    if (delay < 0) {
        state = 4;
    }
}

#pragma push
#pragma fp_contract on
void TObjCMMainMenu::update_menu_reveal(s32 ticks) {
    switch (state) {
    case 3:
    case 4:
    case 5:
    case 6:
        if ((reveal += -0.16666667f) < 0.0f) {
            reveal = 0.0f;
        }
        break;
    default:
        reveal += 0.008333334f;
        if (TAdSinglePlyChrSelectGC::is_active() != 0) {
            reveal += 0.25f * (1.0f - reveal);
        }
        if (reveal > 1.0f) {
            reveal = 1.0f;
        }
        break;
    }
}

#pragma pop
void TObjCMMainMenu::update_submenu_fade() {
    switch (state) {
    case 0:
        if ((submenu_fade += 0.083333336f) > 1.0f) {
            submenu_fade = 1.0f;
        }
        break;
    default:
        if ((submenu_fade += -0.22222222f) < 0.0f) {
            submenu_fade = 0.0f;
        }
        break;
    }
}

void TObjCMMainMenu::update_slide_offset() {
    switch (state) {
    case 1:
        if ((slide_offset += -0.22222222f) < 0.0f) {
            slide_offset = 0.0f;
        }
        break;
    default:
        if ((slide_offset += 0.083333336f) > 1.0f) {
            slide_offset = 1.0f;
        }
        break;
    }
}

void TObjCMMainMenu::update_random_proportion_action(void * _w0) {
    f32 right_trigger_ratio;
    f32 ratio;
    if (TAdSinglePlyChrSelectGC::is_active() != 0) {
        switch (state) {
        case 0:
        case 1:
            right_trigger_ratio = TObjCMProportion::get_right_trigger_ratio();
            ratio = TObjCMProportion::get_ratio() - right_trigger_ratio;
            if (fabs_float(ratio) > 0.05f) {
                rotate_figure((s32) (1092.0f * ratio));
            }
            break;
        }
    }
}

void TObjCMMainMenu::after_state_update() {  }

void TObjCMMainMenu::render() {
    set_depth_buffer_settings_1();
    draw_footer_divider();
    draw_name_warning_and_icons();
    draw_character_name();
    ((TObject *)nodes)->render_nodes();
    draw_root_menu();
    static void (TObjCMMainMenu::*table[7])() = {
        &TObjCMMainMenu::sub_802981BC, 0, &TObjCMMainMenu::draw_confirmation,
        0, 0, 0, 0,
    };
    void (TObjCMMainMenu::*action)() = table[state];
    if (action) (this->*action)();
    restore_saved_depth_alpha_state();
    after_render();
}

void TObjCMMainMenu::sub_802981BC() {  }

const char *creation_class_names[13] = {
    "HUmar", "HUnewearl", "HUcast", "RAmar", "RAcast", "RAcaseal", "FOmarl",
    "FOnewm", "FOnewearl", "HUcaseal", "FOmar", "RAmarl", "???",
};
s32 section_id_sprites[10] = {42, 43, 44, 45, 46, 47, 48, 49, 50, 51};
char unknown_section_name[4] = "???";

void TObjCMMainMenu::draw_confirmation() {
    f32 scale = get_scale();
    f32 alpha;
    if (progress >= 0.8f) {
        alpha = 1.0f;
    } else {
        alpha = progress / 0.8f;
    }
    vec2f pos;
    pos.x = 243.0f - TObjCMMainMenu::get_creation_sprite_id(154);
    pos.y = 173.0f;
    draw_ui_sprite(154, &pos, -3.0625f, alpha);
    pos.x = 242.0f - TObjCMMainMenu::get_creation_sprite_id(150);
    pos.y = 210.0f;
    draw_ui_sprite(150, &pos, -3.0625f, alpha);
    pos.x = 202.0f - TObjCMMainMenu::get_creation_sprite_id(153);
    pos.y = 246.0f;
    draw_ui_sprite(153, &pos, -3.0625f, alpha);

    u32 color = ((u32)(255.0f * alpha) << 24) | 0xFFFFFF;
    int char_class = character->classId;
    if (character->flags & 2) {
        char_class = 12;
    }
    TCameraCtrl::restore_full_screen_view();
    draw_menu_text(263.0f, 172.0f * scale, creation_class_names[char_class], color);
    TCameraCtrl::restore_saved_view();

    u32 name_color = character->nameColor;
    if (!(name_color & 0xFF000000)) {
        name_color = 0xFFFFFFFF;
    }
    // the name keeps its RGB; the alpha comes from the fade
    static const u32 rgb_mask = 0x00FFFFFF;
    name_color &= rgb_mask;
    TCameraCtrl::restore_full_screen_view();
    draw_menu_text(263.0f, 209.0f * scale, character->name, name_color | (color & 0xFF000000));
    TCameraCtrl::restore_saved_view();

    if (progress <= 0.8f) {
        return;
    }
    f32 section_alpha = (progress - 0.8f) / 0.19999999f;
    if (!(character->flags & 1)) {
        vec2f icon_pos;
        icon_pos.x = 212.0f;
        icon_pos.y = 234.0f;
        draw_ui_sprite(section_id_sprites[character->section], &icon_pos, -3.0625f, section_alpha);
    }
    const char *section_name = TObjLuker::get_stat_table_entry(character->section);
    if (character->flags & 1) {
        section_name = unknown_section_name;
    }
    TCameraCtrl::restore_full_screen_view();
    draw_menu_text(263.0f, 247.0f * scale, section_name, ((u32)(255.0f * section_alpha) << 24) | 0xFFFFFF);
    TCameraCtrl::restore_saved_view();
}
u32 footer_divider_colors[2][4] = {
    {0x00C7C7C7, 0x80C7C7C7, 0x80C7C7C7, 0x00C7C7C7},
    {0x80C7C7C7, 0x80C7C7C7, 0x80C7C7C7, 0x80C7C7C7},
};
ColorLineVertex footer_divider_vertices[2][4] = {
    {{275.0f, 0.0f}, {400.0f, 0.0f}, {400.0f, 0.0f}, {275.0f, 0.0f}},
    {{400.0f, 0.0f}, {640.0f, 0.0f}, {640.0f, 0.0f}, {400.0f, 0.0f}},
};


void TObjCMMainMenu::draw_footer_divider() {
    ColorLineList prim;
    u32 cols[4];
    f32 s = TObjCMMainMenu::get_scale();
    f32 top = 416.0f * s;
    f32 bot = top + 3.0f * s;
    u32 *src;
    ColorLineVertex *q;
    s32 i;
    s32 j;
    prim.tex = NULL;
    prim.count = 4;
    for (i = 0; i < 2; i++) {
        q = footer_divider_vertices[i];
        src = footer_divider_colors[i];
        q[1].y = top;
        q[0].y = top;
        q[3].y = bot;
        q[2].y = bot;
        for (j = 0; j < 4; j++) {
            u32 c = src[j];
            cols[j] = (c & 0x00FFFFFF) | ((u32)((f32)(c >> 24) * reveal) << 24);
        }
        prim.colors = cols;
        prim.verts = q;
        prim.draw_strip_swap_color(4, 6, -1.8125f);
    }
}
#pragma push
#pragma fp_contract on
void TObjCMMainMenu::draw_name_warning_and_icons() {
    u32 color;
    s32 i;
    f32 s;
    f32 step;
    f32 y;
    if (entries[selected_entry] == 9 && TObjCMMainMenu::validate_character_name((s8 *)character->name) == 0) {
        color = ((u32)(255.0f * (1.0f - 0.35f * fabs_float(sin_table_lookup(reveal_ticks << 10)))) << 24) | 0xFFFFFF;
        s = TObjCMMainMenu::get_scale();
        step = 19.0f * s;
        y = 396.0f * s - step;
        for (i = 0; i < 2; i++) {
            const char *str = (const char *)get_message_text(i + 0x3B);
            f32 x = 604.0f - (f32)calc_text_width((char *)str);
            TCameraCtrl::restore_full_screen_view();
            draw_menu_text(x, y, str, color);
            TCameraCtrl::restore_saved_view();
            y += step;
        }
    }
    switch (state) {
    case 0:
        if (TAdSinglePlyChrSelectGC::is_active() != 0) {
            if (entries[selected_entry] == 9 && TObjCMMainMenu::validate_character_name((s8 *)character->name) == 0) {
                s32 icon_ids[] = {1};
                TObjCMIcon__sub_802994C8(1, icon_ids);
            } else if (character->section == -1) {
                s32 icon_ids[] = {1, 4};
                TObjCMIcon__sub_802994C8(2, icon_ids);
            } else {
                s32 icon_ids[] = {4};
                TObjCMIcon__sub_802994C8(1, icon_ids);
            }
        } else {
            TObjCMIcon::reset_icon_flags();
        }
        break;
    case 1:
        switch (entries[selected_entry]) {
        case 7:
            TObjCMIcon::reset_icon_flags();
            break;
        case 8:
            break;
        default:
            s32 icon_ids[] = {3};
            TObjCMIcon__sub_802994C8(1, icon_ids);
            break;
        }
        break;
    case 2:
        if (delay == 0 || creation_resource_ready_state == 2) {
            s32 icon_ids[] = {6};
            TObjCMIcon__sub_802994C8(1, icon_ids);
        } else {
            TObjCMIcon::reset_icon_flags();
        }
        break;
    default:
        TObjCMIcon::reset_icon_flags();
        break;
    }
}
#pragma pop
void TObjCMMainMenu::draw_character_name() {
    char *name = character->name;
    if ((state == 0 ||
         (state == 1 && entries[selected_entry] != 7)) &&
        validate_character_name((s8 *)name)) {
        if ((unknown44 += 0.16666667f) > 1.0f) {
            unknown44 = 1.0f;
        }
    } else if ((unknown44 += -0.083333336f) < 0.0f) {
        unknown44 = 0.0f;
        return;
    }
    if (unknown44 <= 0.0f) {
        return;
    }
    f32 x = 604.0f - (f32)calc_text_width(name);
    u32 name_color = character->nameColor;
    if (!(name_color & 0xFF000000)) {
        name_color = 0xFFFFFFFF;
    }
    // the name keeps its RGB; the alpha comes from the fade
    static const u32 rgb_mask = 0x00FFFFFF;
    name_color &= rgb_mask;
    u32 color = ((u32)(255.0f * unknown44) << 24) | name_color;
    TCameraCtrl::restore_full_screen_view();
    draw_menu_text(x, 396.0f * get_scale(), name, color);
    TCameraCtrl::restore_saved_view();
}

const s32 char_creation_root_menu_tab_table[15] = {
    0xA7, 0xB4, 0xC1, 0xCE, 0xDB, 0xE7, 0xF3, 0x101, 0x10F, 0x11C, 0x129, 0x136, 0x143, 0x14F, 0x15B,
};

#pragma push
#pragma fp_contract on


void TObjCMMainMenu::draw_root_menu() {
    vec2f a;
    vec2f b;
    vec2f c;
    vec2f d;
    f32 t;
    f32 ratio;
    f32 x;
    f32 sq;
    f32 base;
    f32 alpha;
    f32 s;
    s32 i;
    s32 j;
    s32 v;
    s32 e;
    s32 k;
    u8 flag;
    s32 n;
    s32 o;
    s32 q;
    s32 r;

    t = reveal < submenu_fade ? reveal : submenu_fade;
    if (!(t <= 0.33f)) {
        if (t >= 0.66f) {
            ratio = 1.0f;
        } else {
            ratio = (t - 0.33f) / 0.33f;
        }
        b.y = 1.0f;
        a.y = 80.0f;
        for (i = 0; i < entry_count; i++) {
            k = 0;
            v = TObjCMMainMenu::get_creation_sprite_id(entries[i] + 0x8F) + 0x90;
            for (j = 0; j < 15; j++) {
                e = char_creation_root_menu_tab_table[j];
                if (v < e) {
                    break;
                }
            }
            x = ratio * ((f32) e - 115.0f) + 115.0f;
            a.x = 115.0f;
            if (TAdSinglePlyChrSelectGC::is_active() != 0 && i == selected_entry) {
                k = 2;
                a.x += 9.0f * sin_table_lookup(reveal_ticks << 10);
            }
            b.x = (x - a.x) / 48.0f;
            draw_ui_sprite_opaque(k + 6, &a, &b, -2.125f);
            a.x = x;
            b.x = 1.0f;
            draw_ui_sprite_opaque(k + 7, &a, &b, -2.125f);
            a.y += 44.0f;
        }
    }
    if (!(t <= 0.0f)) {
        if (t >= 0.33f) {
            alpha = 1.0f;
        } else {
            alpha = t / 0.33f;
        }
        c.x = 95.0f;
        c.y = 80.0f;
        for (n = 0; n < entry_count; n++) {
            o = 0;
            if (TAdSinglePlyChrSelectGC::is_active() != 0 && n == selected_entry) {
                o = -1;
            }
            draw_ui_sprite(o + 1, &c, -1.8125f, alpha);
            c.y += 44.0f;
        }
    }
    if (!(t <= 0.66f)) {
        x = (t - 0.66f) / 0.33999997f;
        d.x = 144.0f;
        d.y = 93.0f;
        sq = x * x;
        base = 0.6f * sq;
        for (q = 0; q < entry_count; q++) {
            flag = 0;
            if (entries[q] == 9 && TObjCMMainMenu::validate_character_name((s8 *)character->name) == 0) {
                flag = 1;
            }
            r = flag;
            if (TAdSinglePlyChrSelectGC::is_active() != 0 && q == selected_entry) {
                s = sin_table_lookup(reveal_ticks << 10);
                s = 0.25f * s + 1.0f;
                if (s > 1.0f) {
                    s = 1.0f;
                }
                alpha = s * sq;
                if (r) {
                    alpha *= 0.4f;
                }
                draw_ui_sprite(entries[q] + 0x8F, &d, -1.8125f, alpha);
            } else {
                alpha = base;
                if (r) {
                    alpha *= 0.4f;
                }
                draw_ui_sprite(entries[q] + 0x8F, &d, -1.8125f, alpha);
            }
            d.y += 44.0f;
        }
    }
}
#pragma pop
void TObjCMMainMenu::open_assign_menu() {
    play_sound_effect(0x52D01, 0, 0, 0);
    state = 1;
    TObjCMAssignMenu::create(nodes, menu_entries[entries[selected_entry]].kind);
}

void TObjCMMainMenu::open_hair_menu() {
    play_sound_effect(0x52D01, 0, 0, 0);
    state = 1;
    TObjCMHairMenu::create(nodes);
}

void TObjCMMainMenu::open_auto_mk_menu() {
    play_sound_effect(0x52D01, 0, 0, 0);
    state = 1;
    TObjCMAutoMkData::create(nodes);
}

void TObjCMMainMenu::open_proportion_menu() {
    play_sound_effect(0x52D01, 0, 0, 0);
    state = 1;
    TObjCMProportion::create(nodes);
}

void TObjCMMainMenu::open_name_menu() {
    play_sound_effect(0x52D01, 0, 0, 0);
    state = 1;
    TObjCMName::create(nodes);
}

void TObjCMMainMenu::confirm_selection() {
    if (validate_character_name((s8 *)character->name) == 0) {
        play_sound_effect(0x53F06, 0, 0, 0);
        return;
    }
    play_sound_effect(0x52D01, 0, 0, 0);
    if (character->section == -1) {
        character->section = calc_section_id_from_name((s8 *)character->name);
    } else {
        try_pay_fee();
    }
    set_selection(1);
    reset_character_creation_figure_rotation();
    delay = 60;
    state = 2;
}

s32 TObjCMMainMenu::try_pay_fee() {
    s32 meseta;
    TPlyCharData *data;

    if (TAdSinglePlyChrSelectGC::get_char_index(0xFFFF) == NULL) {
        play_sound_effect(0x40018519, 0, 0, 0);
        return 0;
    }
    data = TAdSinglePlyChrSelectGC::get_char_index(0xFFFF);
    meseta = data->m_stats.meseta;
    if (meseta < 10000) {
        data->m_stats.meseta = 0;
        play_sound_effect(0xB20C, 0, 0, 0);
        return 0;
    }
    data->m_stats.meseta = meseta - 10000;
    play_sound_effect(0x44E03, 0, 0, 0);
    return 1;
}

void TObjCMMainMenu::after_construct() {  }

void TObjCMMainMenu::after_run_task() {  }

void TObjCMMainMenu::after_render() {  }

const char *TObjCMAssignMenu__name = "TObjCMAssignMenu";

TObjCMAssignMenu::TObjCMAssignMenu(TObject *parent, s32 kind) : TObject(parent) {
    u32 bit;
    s32 i;
    m_name = TObjCMAssignMenu__name;
    appearance = creation_player_character;
    enabled = 0;
    this->kind = kind;
    limit = class_appearance_table[character_display_index(reinterpret_cast<uaddr>(appearance))].counts[this->kind];
    value = (&appearance->costume)[this->kind];
    item_count = 0;
    item_mask = 0;
    bit = 1;
    for (i = 0; i < limit; i++) {
        item_count++;
        item_mask |= bit;
        bit <<= 1;
    }
    calc_grid_layout();
    scroll = page;
    active = 1;
    fade = 0.0f;
    switch (this->kind) {
    case 0:
        TChCrEffTag::set_eff_tag(6);
        break;
    case 1:
        if (appearance->classFlags & 0x10) {
            TChCrEffTag::set_eff_tag(8);
        } else {
            TChCrEffTag::set_eff_tag(7);
        }
        break;
    case 2:
        TChCrEffTag::set_eff_tag(4);
        break;
    case 3:
        TChCrEffTag::set_eff_tag(3);
        break;
    }
}

TObjCMAssignMenu::~TObjCMAssignMenu() {}

TObjCMAssignMenu *TObjCMAssignMenu::create(TObject *parent, s32 kind) {
    return new TObjCMAssignMenu(parent, kind);
}

#pragma push
#pragma opt_common_subs off
void run_task__16TObjCMAssignMenuFv(void *arg0) {
  s32 step;
  s32 wrap;
  s32 old;
  s16 r;
  s16 *new_var;
  s16 v;
  s32 t;
  f32 fade;
  s32 off;
  Menu_80296D68 *self = (Menu_80296D68 *) arg0;
  u8 *app;
  s32 delta;
  self->ticks++;
  if (self->active == 0)
  {
    if ((self->fade += -0.083333336f) <= 0.0f)
    {
      self->fade = 0.0f;
      ((TObject *)self)->queue_destruction();
    }
    return;
  }
  if ((self->fade += 0.16666667f) > 1.0f)
  {
    self->fade = 1.0f;
  }
  delta = 0;
  if (self->enabled != 0)
  {
    if (creation_direction_repeated(0x80) != 0)
    {
      delta = 1;
    }
    else
      if (creation_direction_repeated(0x40) != 0)
    {
      delta = -1;
    }
    if (self->columns > 1)
    {
      if (creation_direction_repeated(0x20) != 0)
      {
        delta = self->step;
      }
      else
        if (creation_direction_repeated(0x10) != 0)
      {
        delta = -self->step;
      }
    }
  }
  if (delta != 0)
  {
    app = self->app;
    off = (self->index * 2) + 0x38;
    old = *((s16 *) (((s8 *) app) + off));
    *((s16 *) (((s8 *) app) + off)) = old + delta;
    if ((delta == 1) || (delta == (-1)))
    {
      v = *((s16 *) (((s8 *) app) + off));
      if (v >= self->limit)
      {
        *((s16 *) (((s8 *) app) + off)) = 0;
      }
      else
        if (v < 0)
      {
        *((s16 *) (((s8 *) app) + off)) = self->limit - 1;
      }
    }
    else
    {
      step = self->step;
      v = *((s16 *) (((s8 *) app) + off));
      r = old % step;
      wrap = self->wrap;
      if (v >= wrap)
      {
        *((s16 *) (((s8 *) app) + off)) = r;
      }
      else
      {
        if (self->fade)
        {
        }
        if (v < 0)
        {
          t = r;
          while ((t + step) < wrap)
          {
            t += step;
          }
          *((s16 *) (((s8 *) app) + off)) = t;
        }
      }
    }
    new_var = (s16 *) (((s8 *) app) + off);
    if ((*new_var) != old)
    {
      play_sound_effect(0x54100, 0, 0, 0);
    }
    self->value = *new_var;
  }
  ((TObjCMAssignMenu *)self)->calc_grid_layout();
  if (self->scroll < ((f32) self->target))
  {
    self->scroll += 0.33333334f;
    if (self->scroll > ((f32) self->target))
    {
      self->scroll = (f32) self->target;
    }
  }
  else
    if (self->scroll > ((f32) self->target))
  {
    self->scroll -= 0.33333334f;
    if (self->scroll < ((f32) self->target))
    {
      self->scroll = (f32) self->target;
    }
  }
  if ((self->enabled != 0) && (creation_buttons_pressed(6) != 0))
  {
    play_sound_effect(0x53704, 0, 0, 0);
    TObjCMMainMenu::clear_task_state();
    self->active = 0;
  }
  else
    if (self->enabled == 0)
  {
    self->enabled = 1;
  }
}

#pragma pop
void TObjCMAssignMenu::calc_grid_layout() {
    s32 index = 0;

    for (s32 i = 0; i < limit; i++) {
        if (i == value) {
            break;
        }
        index++;
    }
    columns = item_count;
    page = 0;
    pages = 1;
    page_columns = item_count;
    cursor = index;
    if (item_count > 0xA) {
        columns = 9;
        page = index / 9;
        pages = (item_count + 8) / 9;
        cursor = index % 9;
        page_columns = item_count - page * 9;
        if (page_columns > 9) {
            page_columns = 9;
        }
    }
}

__declspec(section ".data") vec2f lbl_804DBCC8[1] = {{56.0f, 146.0f}};

const f32 char_creation_assign_menu_tab_positions[10] = {
    206.0f, 219.0f, 243.0f, 271.0f, 271.0f, 284.0f, 297.0f, 323.0f, 347.0f, 347.0f,
};
const vec2f lbl_80465048 = {0.75f, 0.75f};
const vec2f lbl_80465050 = {1.0f, 0.5f};
const vec2f lbl_80465058 = {0.75f, 0.75f};
const s32 char_creation_assign_sprite_id_table[7] = {0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x29};
const s32 char_creation_assign_icon_sprite_id_table[4] = {0x29, 0x28, 0x27, 0x26};

#pragma push
#pragma fp_contract on
#pragma opt_loop_invariants off
void TObjCMAssignMenu::render() {
    vec2f pos;
    vec2f scl;
    vec2f pos2;
    vec2f pos3;
    f32 pulse;
    f32 base;
    f32 alpha;
    f32 w;
    f32 t;
    f32 a;
    f32 step;
    s32 idx;
    s32 i;
    s32 sprite;
    render_assign_slots();
    pulse = 0.25f * sin_table_lookup(ticks << 10) + 1.0f;
    if (pulse > 1.0f) {
        pulse = 1.0f;
    }
    idx = columns - 1;
    if (idx < 0) {
        idx = 0;
    } else if (idx >= 10) {
        idx = 9;
    }
    base = char_creation_assign_menu_tab_positions[idx];
    if (!(fade <= 0.33f)) {
        if (fade >= 0.66f) {
            t = 1.0f;
        } else {
            t = (fade - 0.33f) / 0.33f;
        }
        scl.y = 1.0f;
        pos.y = 146.0f;
        w = t * (base - 75.0f) + 75.0f;
        pos.x = 75.0f;
        pos.x = 9.0f * sin_table_lookup(ticks << 10) + pos.x;
        scl.x = (w - pos.x) / 48.0f;
        draw_ui_sprite_opaque(8, &pos, &scl, -2.75f);
        pos.x = w;
        scl.x = 1.0f;
        draw_ui_sprite_opaque(9, &pos, &scl, -2.75f);
    }
    if (!(fade <= 0.0f)) {
        draw_ui_sprite(0, lbl_804DBCC8, -2.4375f,
                       fade >= 0.33f ? 1.0f : fade / 0.33f);
    }
    if (!(fade <= 0.66f)) {
        a = (fade - 0.66f) / 0.33999997f;
        pos2.x = 103.0f;
        pos2.y = 150.0f;
        step = 17.0f;
        alpha = a * a;
        for (i = 0; i < page_columns; i++) {
            f32 s = alpha;
            sprite = 0x1F;
            if (i == cursor) {
                sprite = 0x20;
                if (creation_resource_ready_state != 2) {
                    s = alpha * (0.2f * fabs_float(sin_table_lookup(ticks << 12)) + 0.2f);
                } else {
                    s = alpha * pulse;
                }
            }
            draw_ui_sprite(sprite, &pos2, -2.4375f, s);
            pos2.x += step;
        }
        if (pages > 1) {
            s32 n = page;
            pos2.x += 6.0f;
            pos2.y += 20.0f;
            draw_ui_sprite_scaled(n + 0x14, &pos2, &lbl_80465048, -2.4375f, alpha);
        }
        w = base - 347.0f;
        pos3.x = 299.0f + w;
        pos3.y = 149.0f;
        draw_ui_sprite(cursor + 0x14, &pos3, -2.4375f, alpha * pulse);
        pos3.x = 305.0f + w;
        pos3.y = 150.0f;
        draw_ui_sprite(0x1E, &pos3, -2.4375f, alpha);
        pos3.x = 324.0f + w;
        pos3.y = 167.0f;
        draw_ui_sprite(page_columns + 0x13, &pos3, -2.4375f, alpha);
    }
    switch (kind) {
    case 0:
        draw_assign_sprites();
        break;
    case 1:
        if (appearance->classFlags & 0x10) {
            draw_assign_sprites();
        } else {
            draw_assign_icons();
        }
        break;
    }
}

#pragma pop
#pragma push
#pragma fp_contract on
void TObjCMAssignMenu::render_assign_slots() {
    f32 zero;
    f32 a;
    f32 step;
    f32 d;
    f32 t;
    s32 i;
    s32 n;
    s32 j;
    vec2f pos;
    if (pages == 1) return;
    t = fade;
    a = t * (t * (0.4f * t));
    if (a <= 1e-05f) return;
    zero = 0.0f;
    for (i = 0; i < pages; i++) {
        n = columns;
        d = (f32)i - scroll;
        if (i == pages - 1) {
            n = item_count - i * columns;
        }
        if (zero == d) continue;
        if (d < zero) {
            t = 1.0f - d;
            pos.x = 22.0f * t + 84.0f;
            pos.y = -20.0f * t + 168.0f;
        } else if (d > zero) {
            t = 1.0f + d;
            pos.x = -22.0f * t + 124.0f;
            pos.y = 20.0f * t + 148.0f;
        }
        step = 17.0f;
        for (j = 0; j < n; j++) {
            draw_ui_sprite_scaled(0x1F, &pos, &lbl_80465050, -3.0625f, a);
            pos.x += step;
        }
        pos.x += 10.0f;
        pos.y += 5.0f;
        draw_ui_sprite_scaled(i + 0x14, &pos, &lbl_80465058, -3.0625f, a);
    }
}

void TObjCMAssignMenu::draw_assign_sprites() {
    s32 idx;
    u32 bit;
    s32 i;
    f32 step;
    f32 a;
    vec2f pos;
    if (!(fade <= 0.66f)) {
        a = (fade - 0.66f) / 0.33999997f;
        pos.x = 113.0f;
        step = 17.0f;
        idx = 0;
        pos.y = 152.0f;
        bit = 1;
        a = a * a;
        for (i = 0; i < item_count; bit <<= 1, idx++, i++, pos.x += step) {
            while (!(bit & item_mask)) {
                bit <<= 1;
                idx++;
            }
            if (idx < 7) draw_ui_sprite(char_creation_assign_sprite_id_table[idx], &pos, -2.4375f, a);
        }
    }
}

void TObjCMAssignMenu::draw_assign_icons() {
    s32 idx;
    u32 bit;
    s32 i;
    f32 step;
    f32 a;
    vec2f pos;
    if (!(fade <= 0.66f)) {
        a = (fade - 0.66f) / 0.33999997f;
        pos.x = 113.0f;
        step = 17.0f;
        idx = 0;
        pos.y = 152.0f;
        bit = 1;
        a = a * a;
        for (i = 0; i < item_count; i++, pos.x += step) {
            while (!(bit & item_mask)) {
                bit <<= 1;
                idx++;
            }
            draw_ui_sprite(char_creation_assign_icon_sprite_id_table[idx], &pos, -2.4375f, a);
            bit <<= 1;
            idx++;
        }
    }
}

#pragma pop
const char *TObjCMHairMenu__name = "TObjCMHairMenu";

TObjCMHairMenu::TObjCMHairMenu(TObject *parent) : TObject(parent) {
    s32 i;
    m_name = TObjCMHairMenu__name;
    appearance = creation_player_character;
    initialized = 0;
    selection = 0;
    count = class_appearance_table[character_display_index(reinterpret_cast<uaddr>(appearance))].counts[4];
    active = 1;
    fade = 0.0f;
    for (i = 0; i < 3; i++) {
        trailing[i] = 0;
    }
    TChCrEffTag::set_eff_tag(5);
}

TObjCMHairMenu::~TObjCMHairMenu() {}

TObjCMHairMenu *TObjCMHairMenu::create(TObject *parent) {
    return new TObjCMHairMenu(parent);
}

void TObjCMHairMenu::run_task() {
    s32 next;
    s32 prev;
    s16 value;
    s32 sel;
    CharacterAppearanceFields *app;
    s32 off;

    ticks++;
    if (initialized == 0) {
        initialized = 1;
        return;
    }
    if (active == 0) {
        if ((fade += -0.083333336f) <= 0.0f) {
            fade = 0.0f;
            queue_destruction();
        }
    } else {
        if ((fade += 0.16666667f) > 1.0f) {
            fade = 1.0f;
        }
        if (creation_direction_repeated(0x20) != 0) {
            next = selection + 1;
            selection = next;
            if (next >= 4) {
                selection = 0;
            }
            play_sound_effect(0x54100, 0, 0, 0);
        } else if (creation_direction_repeated(0x10) != 0) {
            prev = selection - 1;
            selection = prev;
            if (prev < 0) {
                selection = 3;
            }
            play_sound_effect(0x54100, 0, 0, 0);
        }
        sel = selection;
        if (sel == 0) {
            app = appearance;
            if (creation_direction_repeated(0x80) != 0) {
                if (++app->hair >= count) {
                    app->hair = 0;
                }
                play_sound_effect(0x54100, 0, 0, 0);
            } else if (creation_direction_repeated(0x40) != 0) {
                if (--app->hair < 0) {
                    app->hair = count - 1;
                }
                play_sound_effect(0x54100, 0, 0, 0);
            }
        } else {
            app = appearance;
            off = (sel + 4) * 2 + 0x38;
            if (creation_buttons_pressed(0x80) != 0) {
                *(s16 *)((s8 *)app + off) = *(s16 *)((s8 *)app + off) + 1;
            } else if (creation_buttons_pressed(0x40) != 0) {
                *(s16 *)((s8 *)app + off) = *(s16 *)((s8 *)app + off) - 1;
            } else if (creation_buttons_held(0x80) != 0) {
                *(s16 *)((s8 *)app + off) = *(s16 *)((s8 *)app + off) + 5;
            } else if (creation_buttons_held(0x40) != 0) {
                *(s16 *)((s8 *)app + off) = *(s16 *)((s8 *)app + off) - 5;
            }
            value = *(s16 *)((s8 *)app + off);
            if (value > 0xFF) {
                *(s16 *)((s8 *)app + off) = 0xFF;
            } else if (value < 0) {
                *(s16 *)((s8 *)app + off) = 0;
            }
        }
        if (creation_buttons_pressed(6) != 0) {
            play_sound_effect(0x53704, 0, 0, 0);
            TObjCMMainMenu::clear_task_state();
            active = 0;
        }
    }
}

vec2f hair_slider_icon_positions[3] = {{105.0f, 194.0f}, {105.0f, 238.0f}, {105.0f, 282.0f}};

#pragma push
#pragma fp_contract on
const f32 lbl_8046509C[10] = {
    206.0f, 219.0f, 243.0f, 271.0f, 271.0f, 284.0f, 297.0f, 323.0f, 347.0f, 347.0f,
};
const f32 hair_bar_widths[4] = {0.0f, 244.0f, 244.0f, 244.0f};
const vec2f hair_bar_corners[4] = {{107.0f, 210.0f}, {99.0f, 224.0f}, {241.0f, 224.0f}, {249.0f, 210.0f}};
const HairBarColor hair_bar_colors[4] = {{0xFF000000}, {0x00FF0000}, {0x0000FF00}, {0x80808000}};

// render reaches each of the four hair arrays with its own lis/addi (no shared base): pool_data off
#pragma pool_data off
void TObjCMHairMenu::render() {
    NJS_POINT2 pts[4];
    NJS_COLOR cols[4];
    NJS_POINT2COL list;
    vec2f pos;
    vec2f scl;
    vec2f pos2;
    vec2f pos3;
    vec2f pos4;
    f32 pulse;
    f32 v;
    f32 w;
    f32 off;
    f32 a;
    f32 base;
    f32 alpha;
    s32 idx;
    s32 hair;
    f32 step;
    f32 hi;
    f32 t;
    f32 r;
    f32 dim;
    f32 scale;

    hair = appearance->hair;
    pulse = 0.25f * sin_table_lookup(ticks << 10) + 1.0f;
    if (pulse > 1.0f) {
        pulse = 1.0f;
    }
    idx = count - 1;
    if (idx < 0) {
        idx = 0;
    } else if (idx >= 10) {
        idx = 9;
    }
    base = lbl_8046509C[idx];
    if (!(fade <= 0.33f)) {
        if (fade >= 0.66f) {
            r = 1.0f;
        } else {
            r = (fade - 0.33f) / 0.33f;
        }
        scl.y = 1.0f;
        pos.y = 146.0f;
        for (s32 i = 0; i < 4; i++) {
            s32 sprite = 0;
            if (i == 0) {
                w = r * (base - 75.0f) + 75.0f;
            } else {
                w = r * (hair_bar_widths[i] - 75.0f) + 75.0f;
            }
            pos.x = 75.0f;
            if (i == selection) {
                sprite = 2;
                pos.x = 9.0f * sin_table_lookup(ticks << 10) + pos.x;
            }
            scl.x = (w - pos.x) / 48.0f;
            draw_ui_sprite_opaque(sprite + 6, &pos, &scl, -2.75f);
            pos.x = w;
            scl.x = 1.0f;
            draw_ui_sprite_opaque(sprite + 7, &pos, &scl, -2.75f);
            pos.y += 44.0f;
        }
    }
    if (!(fade <= 0.0f)) {
        if (fade >= 0.33f) {
            a = 1.0f;
        } else {
            a = fade / 0.33f;
        }
        pos2.x = 56.0f;
        pos2.y = 146.0f;
        for (s32 i = 0; i < 4; i++) {
            s32 sprite = 0;
            if (i == selection) {
                sprite = -1;
            }
            draw_ui_sprite(sprite + 1, &pos2, -2.4375f, a);
            pos2.y += 44.0f;
        }
    }
    if (!(fade <= 0.66f)) {
        t = (fade - 0.66f) / 0.33999997f;
        pos3.x = 103.0f;
        pos3.y = 150.0f;
        alpha = t * t;
        for (s32 i = 0; i < count; i++) {
            f32 s = alpha;
            s32 sprite = 0x1F;
            if (selection != 0) {
                s *= 0.6f;
            }
            if (i == hair) {
                sprite = 0x20;
                if (creation_resource_ready_state != 2) {
                    s *= 0.2f * fabs_float(sin_table_lookup(ticks << 12)) + 0.2f;
                } else if (selection == 0) {
                    s *= pulse;
                }
            }
            draw_ui_sprite(sprite, &pos3, -2.4375f, s);
            pos3.x += 17.0f;
        }
        off = base - 347.0f;
        dim = alpha;
        hi = alpha;
        if (selection == 0) {
            hi *= pulse;
        } else {
            hi *= 0.6f;
            dim = hi;
        }
        pos4.x = 299.0f + off;
        pos4.y = 149.0f;
        draw_ui_sprite(hair + 20, &pos4, -2.4375f, hi);
        pos4.x = 305.0f + off;
        pos4.y = 150.0f;
        draw_ui_sprite(0x1E, &pos4, -2.4375f, dim);
        pos4.x = 324.0f + off;
        pos4.y = 167.0f;
        draw_ui_sprite(count + 19, &pos4, -2.4375f, dim);
        for (s32 i = 1; i < 4; i++) {
            f32 s = alpha;
            if (i == selection) {
                s *= pulse;
            } else {
                s *= 0.6f;
            }
            draw_ui_sprite(i + 15, &hair_slider_icon_positions[i - 1], -2.4375f, s);
        }

        TCameraCtrl::restore_full_screen_view();
        scale = TObjCMMainMenu::get_scale();
        step = 44.0f * scale;
        list.p = pts;
        list.col = cols;
        list.tex = NULL;
        pts[0].x = 0.1f * (hair_bar_corners[1].x - hair_bar_corners[0].x) + hair_bar_corners[0].x;
        pts[1].x = 1.1f * (hair_bar_corners[1].x - hair_bar_corners[0].x) + hair_bar_corners[0].x;
        pts[2].x = 1.1f * (hair_bar_corners[2].x - hair_bar_corners[3].x) + hair_bar_corners[3].x;
        pts[3].x = 0.1f * (hair_bar_corners[2].x - hair_bar_corners[3].x) + hair_bar_corners[3].x;
        pts[0].y = pts[3].y = 0.1f * (hair_bar_corners[1].y - hair_bar_corners[0].y) + hair_bar_corners[0].y;
        pts[1].y = pts[2].y = 1.1f * (hair_bar_corners[1].y - hair_bar_corners[0].y) + hair_bar_corners[0].y;
        HairBarColor color = hair_bar_colors[3];
        pts[0].y *= scale;
        pts[1].y *= scale;
        pts[2].y *= scale;
        pts[3].y *= scale;
        color.c[3] = 255.0f * t;
        TObjCMHairMenu__sub_801E3F54(&cols[0].color, TObjCMHairMenu__sub_801E3F54(&cols[1].color,
            TObjCMHairMenu__sub_801E3F54(&cols[2].color, TObjCMHairMenu__sub_801E3F54(&cols[3].color, &color.rgba))));
        for (s32 i = 0; i < 3; i++) {
            draw_polygon_2d(&list, 4, 6, -2.75f);
            pts[0].y += step;
            pts[1].y += step;
            pts[2].y += step;
            pts[3].y += step;
        }
        for (s32 i = 0; i < 3; i++) {
            v = (&appearance->red)[i] / 255.0f;
            if (v != 0.0f) {
                pts[0].x = hair_bar_corners[0].x;
                pts[1].x = hair_bar_corners[1].x;
                pts[2].x = v * (hair_bar_corners[2].x - hair_bar_corners[1].x) + hair_bar_corners[1].x;
                pts[3].x = v * (hair_bar_corners[3].x - hair_bar_corners[0].x) + hair_bar_corners[0].x;
                for (s32 j = 0; j < 4; j++) {
                    pts[j].y = scale * hair_bar_corners[j].y + i * step;
                }
                HairBarColor bar_color = hair_bar_colors[i];
                bar_color.c[3] = 255.0f * t;
                TObjCMHairMenu__sub_801E3F54(&cols[0].color, TObjCMHairMenu__sub_801E3F54(&cols[1].color,
                    TObjCMHairMenu__sub_801E3F54(&cols[2].color, TObjCMHairMenu__sub_801E3F54(&cols[3].color, &bar_color.rgba))));
                draw_polygon_2d(&list, 4, 6, -2.4375f);
            }
        }
        TCameraCtrl::restore_saved_view();
    }
}

#pragma pop
const char *TObjCMAutoMkData__name = "TObjCMAutoMkData";

TObjCMAutoMkData::TObjCMAutoMkData(TObject *parent) : TObject(parent) {
    m_name = TObjCMAutoMkData__name;
    appearance = creation_player_character;
    copy_vec2(&width, &appearance->width);
    fade = 0.0f;
    state = 0;
    TChCrEffTag::set_eff_tag(0xB);
}

TObjCMAutoMkData::~TObjCMAutoMkData() {
    set_creation_projection_center(1.0f);
}

TObjCMAutoMkData *TObjCMAutoMkData::create(TObject *parent) {
    return new TObjCMAutoMkData(parent);
}

#pragma push
#pragma fp_contract on
void TObjCMAutoMkData::run_task() {
  f32 x;
  f32 t;
  s16 *lim;
  s16 *sel;
  s32 i;
  s32 v;
  CharacterAppearanceFields **new_var;
  x = TObjCMMainMenu::get_proportion();
  if (state != 2)
  {
    if (1.0f == fade)
    {
      x += -0.033333335f;
      if (x < 0.0f)
      {
        x = 0.0f;
      }
    }
  }
  else
  {
    x = (x > (1.0f - fade)) ? (x) : (1.0f - fade);
  }
  set_creation_projection_center(x);
  new_var = &appearance;
  if (state == 2)
  {
    if ((fade += -0.083333336f) <= 0.0f)
    {
      fade = 0.0f;
      queue_destruction();
    }
    return;
  }
  if ((fade += 0.16666667f) > 1.0f)
  {
    fade = 1.0f;
  }
  switch (state)
  {
    case 1:
    {
      s32 icon_ids[] = {2, 5};
      TObjCMIcon__sub_802994C8(2, icon_ids);
      break;
    }
    case 2:
      break;
    case 3:
      TObjCMIcon::reset_icon_flags();
      break;
  }
  switch (state)
  {
    case 0:
      state = 1;
      break;
    case 1:
      if (creation_buttons_pressed(2) != 0)
    {
      play_sound_effect(0x53704, 0, 0, 0);
      TObjCMMainMenu::clear_task_state();
      state = 2;
      break;
    }
      if (creation_buttons_pressed(4) == 0)
    {
      break;
    }
      lim = class_appearance_table[character_display_index((uaddr)appearance)].counts;
      sel = &appearance->costume;
      for (i = 0; i <= 4; i++, lim++, sel++)
    {
      if ((*lim) >= 2)
      {
        v = (s16) ((0.99f * ((f32) (*lim))) * (3.0517578e-05f * ((f32) ((int)rand()))));
        while (v == (*sel))
        {
          v++;
          if (v >= (*lim))
          {
            v = 0;
          }
        }
        *sel = v;
      }
    }
      red = (u8) ((s32) ((128.0f * (3.0517578e-05f * ((f32) ((int)rand())))) + (red + 0x40)));
      green = (u8) ((s32) ((128.0f * (3.0517578e-05f * ((f32) ((int)rand())))) + (green + 0x40)));
      blue = (u8) ((s32) ((128.0f * (3.0517578e-05f * ((f32) ((int)rand())))) + (blue + 0x40)));
      if ((width += (0.5f * (3.0517578e-05f * ((f32) ((int)rand())))) + 0.25f) >= 1.0f)
    {
      width -= 1.0f;
    }
      if ((height += (0.5f * (3.0517578e-05f * ((f32) ((int)rand())))) + 0.25f) >= 1.0f)
    {
      height -= 1.0f;
    }
      play_sound_effect(0x52D01, 0, 0, 0);
      ticks = 0;
      state = 3;
      break;
    case 2:
      break;
    case 3:
      ticks++;
      t = ((f32) ticks) / 30.0f;
      (*new_var)->red = (s32) (((f32) appearance->red) + (t * ((f32) (red - (*new_var)->red))));
      appearance->green = (s32) (((f32) (*new_var)->green) + (t * ((f32) (green - appearance->green))));
      appearance->blue = (s32) (((f32) appearance->blue) + (t * ((f32) (blue - (*new_var)->blue))));
      (*new_var)->width = (t * (width - appearance->width)) + appearance->width;
      appearance->height = (t * (height - (*new_var)->height)) + appearance->height;
      if (ticks >= 30)
    {
      if (creation_resource_ready_state == 2)
      {
        play_sound_effect(0x52802, 0, 0, 0);
        state = 1;
      }
      else
        if (ticks >= 150)
      {
        return;
      }
    }
      break;
  }
}

#pragma pop
void TObjCMAutoMkData::render() {
    draw_creation_ruler_lines(fade);
}

const char *TObjCMProportion__name = "TObjCMProportion";

TObjCMProportion::TObjCMProportion(TObject *parent) : TObject(parent) {
    m_name = TObjCMProportion__name;
    appearance = creation_player_character;
    initialized = 0;
    active = 1;
    fade = 0.0f;
    TChCrEffTag::set_eff_tag(9);
}

TObjCMProportion::~TObjCMProportion() {
    set_creation_projection_center(1.0f);
}

TObjCMProportion *TObjCMProportion::create(TObject *parent) {
    return new TObjCMProportion(parent);
}

#pragma push
#pragma fp_contract on
void TObjCMProportion::run_task() {
    TObjCMProportion *self = this;
    s32 angle;
    f32 magnitude;
    f32 visible;
    f32 height;
    f32 proportion;
    f32 d_width;
    f32 d_height;
    CharacterAppearanceFields *appearance;
    CharacterAppearanceFields *fields;

    proportion = TObjCMMainMenu::get_proportion();
    if (self->active != 0) {
        if (1.0f == self->fade) {
            proportion += -0.033333335f;
            if (proportion < 0.0f) {
                proportion = 0.0f;
            }
        }
    } else {
        visible = 1.0f - self->fade;
        proportion = (proportion > visible) ? proportion : visible;
    }
    set_creation_projection_center(proportion);
    if (self->initialized == 0) {
        self->initialized = 1;
        return;
    }
    if (self->active == 0) {
        if ((self->fade += -0.083333336f) <= 0.0f) {
            self->fade = 0.0f;
            ((TObject *)self)->queue_destruction();
        }
    } else {
        if ((self->fade += 0.16666667f) > 1.0f) {
            self->fade = 1.0f;
        }
        get_creation_pad_stick(&angle, &magnitude);
        d_width = 0.016666668f * (magnitude * sin_table_lookup(angle));
        d_height = 0.016666668f * (magnitude * -cos_table_lookup(angle));
        if (0.0f == (fabs_float(d_width) + fabs_float(d_height))) {
            if (creation_buttons_held(0x80) != 0) {
                d_width = 0.013333335f;
            } else if (creation_buttons_held(0x40) != 0) {
                d_width = -0.013333335f;
            }
            if (creation_buttons_held(0x20) != 0) {
                d_height = 0.013333335f;
            } else if (creation_buttons_held(0x10) != 0) {
                d_height = -0.013333335f;
            }
        }
        self->appearance->width += d_width;
        self->appearance->height += d_height;
        appearance = self->appearance;
        if (appearance->width > 0.99f) {
            appearance->width -= 0.99f;
        } else if (appearance->width < 0.0f) {
            appearance->width += 0.99f;
        }
        fields = self->appearance;
        height = fields->height;
        if (height > 0.99f) {
            fields->height = 0.99f;
        } else if (height < 0.0f) {
            fields->height = 0.0f;
        }
        if (creation_buttons_pressed(6) != 0) {
            play_sound_effect(0x53704, 0, 0, 0);
            TObjCMMainMenu::clear_task_state();
            self->active = 0;
        }
    }
}

NJS_POINT2 proportion_frame_points[4] = {{245.0f, 165.0f}, {395.0f, 165.0f}, {395.0f, 315.0f}, {245.0f, 315.0f}};
NJS_POINT2COL proportion_frame_strip = {proportion_frame_points, proportion_frame_colors, NULL, 4};
NJS_POINT2COL proportion_marker_strip = {proportion_marker_points, proportion_marker_colors, NULL, 4};

void TObjCMProportion::render() {
    f32 alpha;
    u32 color;
    f32 x;
    f32 y;

    alpha = fade * fade;
    color = ((s32)(32.0f * alpha) << 24) | 0xFF0000 | 0xFFFF;
    proportion_frame_colors[3].color = color;
    proportion_frame_colors[2].color = color;
    proportion_frame_colors[1].color = color;
    proportion_frame_colors[0].color = color;
    reinterpret_cast<ColorLineList *>(&proportion_frame_strip)->draw_strip_swap_color(4, 5, -2.0f);
    color = ((s32)(64.0f * alpha) << 24) | 0xFF0000 | 0xFFFF;
    proportion_marker_colors[3].color = color;
    proportion_marker_colors[2].color = color;
    proportion_marker_colors[1].color = color;
    proportion_marker_colors[0].color = color;
    x = 75.0f * (2.0f * (appearance->width - 0.5f)) + 320.0f;
    y = 75.0f * (2.0f * (appearance->height - 0.5f)) + 240.0f;
    proportion_marker_points[1].y = 150.0f;
    proportion_marker_points[0].y = 150.0f;
    proportion_marker_points[3].y = 330.0f;
    proportion_marker_points[2].y = 330.0f;
    proportion_marker_points[0].x = x - 2.0f;
    proportion_marker_points[1].x = 2.0f + x;
    proportion_marker_points[2].x = 2.0f + x;
    proportion_marker_points[3].x = x - 2.0f;
    reinterpret_cast<ColorLineList *>(&proportion_marker_strip)->draw_strip_swap_color(4, 6, -2.0f);
    proportion_marker_points[0].y = y - 2.0f;
    proportion_marker_points[1].x = 230.0f;
    proportion_marker_points[1].y = 2.0f + y;
    proportion_marker_points[0].x = 230.0f;
    proportion_marker_points[2].y = 2.0f + y;
    proportion_marker_points[3].y = y - 2.0f;
    proportion_marker_points[3].x = 410.0f;
    proportion_marker_points[2].x = 410.0f;
    reinterpret_cast<ColorLineList *>(&proportion_marker_strip)->draw_strip_swap_color(4, 6, -2.0f);
    draw_creation_ruler_lines(fade);
}

#pragma pop
const char *TObjCMName::class_name = "TObjCMName";

TObjCMName::TObjCMName(TObject *parent) : TObject(parent) {
    m_name = class_name;
    appearance = creation_player_character;
    initialized = 0;
    ticks = 0;
    keyboard = NULL;
    active = 1;
    fade = 0.0f;
    TChCrEffTag::set_eff_tag(10);
}

TObjCMName::~TObjCMName() {}

TObjCMName *TObjCMName::create(TObject *parent) {
    return new TObjCMName(parent);
}


void TObjCMName::run_task() {
    f32 pos[2];
    char name[13];
    TKeyBoardControl *kb;
    char *buf;
    s32 sound;
    f32 scale;

    ticks++;
    if (initialized == 0) {
        if (ticks > 1) {
            kb = new TKeyBoardControl(this, 12, 0, 0, TChCrEffCtrlPl::get_clamped_player_index());
            keyboard = kb;
            ((TKeyBoardControl *)keyboard)->set_text((char *)appearance->name);
            scale = TObjCMMainMenu::get_scale();
            pos[0] = 148.0f;
            pos[1] = 137.0f * scale;
            ((TKeyBoardControl *)keyboard)->set_sub_position((u8 *)pos);
            pos[0] = 53.0f;
            pos[1] = 178.0f * scale;
            ((TKeyBoardControl *)keyboard)->set_soft_position((u8 *)pos);
            initialized = 1;
        }
    } else if (active == 0) {
        if ((fade += -0.083333336f) <= 0.0f) {
            fade = 0.0f;
            queue_destruction();
        }
    } else {
        if ((fade += 0.16666667f) > 1.0f) {
            fade = 1.0f;
        }
        if (((TKeyBoardControl *)keyboard)->is_confirmed() != 0) {
            buf = (char *)((TKeyBoardControl *)keyboard)->realloc_buffer();
            sound = 0x53704;
            strncpy(name, buf, 12);
            name[12] = 0;
            if (TObjCMMainMenu::validate_character_name((s8 *)name) == 0) {
                sound = 0x5280D;
            }
            if (is_name_rejected(name) != 0) {
                sound = 0x52608;
                strncpy(name, (char *)appearance->name, 12);
                name[12] = 0;
            }
            ((TObjCMMainMenu *)name)->copy_char_name();
            strncpy((char *)appearance->name, name, 12);
            appearance->name[12] = 0;
            mem_free(buf);
            play_sound_effect(sound, 0, 0, 0);
            TObjCMMainMenu::clear_task_state();
            keyboard->queue_destruction();
            keyboard = NULL;
            active = 0;
        }
    }
}

#pragma push
#pragma fp_contract on
__declspec(section ".data") vec2f creation_name_panel_position[1] = {{95.0f, 124.0f}};

void TObjCMName::render()
{
  vec2f position;
  vec2f scale;
  float right_edge;
  if (!(this->fade <= 0.33f))
  {
    f32 amount = (this->fade >= 0.66f) ? (1.0f) : ((this->fade - 0.33f) / 0.33f);
    scale.y = 1.0f;
    position.y = 124.0f;
    right_edge = 115.0f + (232.0f * amount);
    position.x = 115.0f;
    f32 right = right_edge;
    f32 left = (9.0f * sin_table_lookup(this->ticks << 10)) + position.x;
    f32 width = right - left;
    position.x = left;
    scale.x = width / 48.0f;
    draw_ui_sprite_opaque(8, &position, &scale, -2.75f);
    position.x = right;
    scale.x = 1.0f;
    draw_ui_sprite_opaque(9, &position, &scale, -2.75f);
  }
  if (!(this->fade <= 0.0f))
  {
    draw_ui_sprite(0, creation_name_panel_position, -2.4375f, (this->fade >= 0.33f) ? (1.0f) : (this->fade / 0.33f));
  }
}

#pragma pop


s32 TObjCMName::is_name_rejected(char *name) { return 0; }
