#pragma defer_codegen on
#include "pso/system/MatrixStack.h"
#include "types.h"
#include "pso/ui/frontend/TAdChrSelPlayerGC.h"
#include "pso/ui/frontend/TAdPlyStatusGC.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/system/BmlResource.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/player/TPlyCharData.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/system/MatrixStack.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/TextureState.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/ui/charcreate/CharacterPreview.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/ui/frontend/TAdMultiConfirmGC.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/render/GinjaTextureMatrices.h"
#include "pso/math/MatrixReflect.h"
#include "pso/render/model_render_state.h"

extern const char chr_sel_player_class_name_string[] = "TAdChrSelPlayerGC";
BmlResource *multi_ply_chr_select_resource_bundle;

const char *chr_sel_player_class_name = chr_sel_player_class_name_string;

void load_multi_ply_chr_select_resources(void) {
    multi_ply_chr_select_resource_bundle = new BmlResource(1, &creation_menu_resource_descriptor, 0, 0, NULL);
}

void free_multi_ply_chr_select_resources(void) {
    if (multi_ply_chr_select_resource_bundle != NULL) {
        delete multi_ply_chr_select_resource_bundle;
        multi_ply_chr_select_resource_bundle = NULL;
    }
}

TAdChrSelPlayerGC *TAdMultiPlyChrSelectGC::get_or_create_player(TObject *parent, s32 mode, s32 index, s32 slot) {
    if (multi_chr_select_player_slot_table[slot] == NULL) {
        multi_chr_select_player_slot_table[slot] = new TAdChrSelPlayerGC(parent, mode, index, slot);
    }
    return multi_chr_select_player_slot_table[slot];
}

TAdChrSelPlayerGC::TAdChrSelPlayerGC(TObject *parent, s32 mode, s32 index, s32 slot) : TObjMotion(parent) {
    this->slot = slot;
    formation_index = index;
    init_selection_model(mode);
}

void TAdChrSelPlayerGC::init_selection_model(s32 window_offset_index) {
    this->m_name = chr_sel_player_class_name;
    state = 0;
    this->pending_state = 0;
    this->status_index = 0;
    layout_mode = window_offset_index;
    preview_data = NULL;
    this->joint_matrices = new Mtx34[64];
    TAdPlyStatusGC::get_instance(this, window_offset_index);
    place_model_for_mode(layout_mode);
}



TAdChrSelPlayerGC *multi_chr_select_player_slot_table[4] = { NULL };

#pragma push
#pragma fp_contract on
#pragma pool_data off

void TAdChrSelPlayerGC::place_model_for_mode(s32) {
    spin_model = 0;
    switch (layout_mode) {
    case 0:
        position.x = 17.0f;
        position.y = -10.5f;
        position.z = -40.0f;
        rotation.x = 0;
        rotation.y = 0xF3D5;
        rotation.z = 0;
        spin_model = 1;
        break;
    case 1:
    case 2:
        position.x = 0.0f;
        position.y = -10.5f;
        position.z = -40.0f;
        rotation.x = 0;
        rotation.y = 0xF3D5;
        rotation.z = 0;
        spin_model = 1;
        break;
    case 3:
        position.x = 28.0f * formation_index + -14.0f;
        position.y = -10.0f;
        position.z = -110.0f;
        rotation.x = 0;
        rotation.y = 182.04445f * (7.25f - 14.5f * formation_index);
        rotation.z = 0;
        break;
    case 4:
        position.x = 19.0f * formation_index + -19.0f;
        position.y = -10.0f;
        position.z = -110.0f;
        rotation.x = 0;
        rotation.y = 182.04445f * (9.8f - 9.8f * formation_index);
        rotation.z = 0;
        break;
    case 5: {
        f32 xs[4] = { -21.5f, -8.0f, 7.0f, 23.5f };
        f32 zs[4] = { -110.0f, -118.56f, -110.0f, -118.56f };
        f32 rs[4] = { 11.6f, 3.86f, -3.64f, -11.21f };
        position.x = xs[formation_index];
        position.y = -10.0f;
        position.z = zs[formation_index];
        rotation.x = 0;
        rotation.y = 182.04445f * rs[formation_index];
        rotation.z = 0;
        break;
    }
    }
}
#pragma pop

void TAdChrSelPlayerGC::set_index_and_close_status(s32 index) {
    layout_mode = index;
    place_model_for_mode(layout_mode);
    TAdPlyStatusGC *status = TAdPlyStatusGC::get_index();
    if (status != NULL) {
        status->close_window(index);
    }
}

void TAdChrSelPlayerGC::set_status_value(s32 value) {
    status_index = value;
    TAdPlyStatusGC *status = TAdPlyStatusGC::get_index();
    if (status != NULL) {
        status->set_status_index(status_index);
    }
}

TAdChrSelPlayerGC::~TAdChrSelPlayerGC() {
    if (multi_chr_select_player_slot_table[slot] != NULL) {
        multi_chr_select_player_slot_table[slot] = NULL;
    }
    if (joint_matrices != NULL) {
        delete[] joint_matrices;
        joint_matrices = NULL;
    }
    if (preview_data != NULL) {
        delete preview_data;
        preview_data = NULL;
        TAdPlyStatusGC *status = TAdPlyStatusGC::get_index();
        if (status != NULL) {
            status->set_status_param(preview_data);
        }
    }
}

void TAdChrSelPlayerGC::run_task() {
    CharacterPreview *p;
    TAdPlyStatusGC *status;
    s32 t;
    switch (state) {
    case 0:
        if (preview_data != NULL) {
            delete preview_data;
            preview_data = NULL;
        }
        if (pending_state != 0) {
            state = pending_state - 1;
            pending_state = 0;
        }
        break;
    case 1:
        if (preview_data != NULL) {
            delete preview_data;
            preview_data = NULL;
        }
        if (pending_state != 0) {
            state = pending_state - 1;
            pending_state = 0;
            break;
        }
        switch (layout_mode) {
        case 0:
            copy_player_visual_record((disp_data_part2 *)&visual_record, &TAdSinglePlyChrSelectGC::get_char_index(0xFFFF)->m_disp_part2);
            p = new CharacterPreview(this, &visual_record, 0);
            preview_data = p;
            rotation.y = 0xF3D5;
            break;
        case 1:
            copy_player_visual_record((disp_data_part2 *)&visual_record, &TAdSinglePlyChrSelectGC::get_entry(status_index)->m_disp_part2);
            p = new CharacterPreview(this, &visual_record, 0);
            preview_data = p;
            rotation.y = 0xF3D5;
            break;
        case 2:
            copy_player_visual_record((disp_data_part2 *)&visual_record, &TAdSinglePlyChrSelectGC::get_char_index(0xFFFF)->m_disp_part2);
            p = new CharacterPreview(this, &visual_record, 0);
            preview_data = p;
            rotation.y = 0xF3D5;
            break;
        case 3:
        case 4:
        case 5:
            copy_player_visual_record((disp_data_part2 *)&visual_record, &TAdSinglePlyChrSelectGC::get_char_table_entry(slot)->m_disp_part2);
            p = new CharacterPreview(this, &visual_record, slot);
            preview_data = p;
            break;
        }
        init_model_animation();
        state = 2;
        break;
    case 2:
        if (pending_state != 0) {
            if (preview_data != NULL) {
                delete preview_data;
                preview_data = NULL;
            }
            state = pending_state - 1;
            pending_state = 0;
        } else if (preview_data->is_unloaded() != 0) {
            state = 3;
            animation_ticks = 0;
        }
        break;
    case 3:
        if (pending_state != 0) {
            if (preview_data != NULL) {
                delete preview_data;
                preview_data = NULL;
            }
            state = pending_state - 1;
            pending_state = 0;
        } else {
            if (spin_model == 1) {
                rotation.y = rotation.y - 0x100;
            }
            animation_ticks = animation_ticks + 1;
            t = animation_ticks;
            if (t == 0x384 || t == 0x708) {
                set_cursor_index_1();
            } else if (t == 0x546) {
                set_cursor_index_2();
            }
            if (animation_ticks == 0x8CA) {
                reset_cursor();
                animation_ticks = 0;
            }
            advance_animation();
        }
        break;
    }
    status = TAdPlyStatusGC::get_index();
    if (status != NULL) {
        status->set_load_state(state);
        status->set_status_param(preview_data);
    }
}

void TAdChrSelPlayerGC::init_model_animation() {
    this->set_action_table(chr_sel_player_actions);
    this->set_motion_list(multi_ply_chr_select_resource_bundle->motions);
    set_cursor_index(0);
    set_animation((this->requested_action));
}

void TAdChrSelPlayerGC::set_cursor_index(s32 index) {
    s16 requested_action;

    this->requested_action = (s16) (index * 3);
    requested_action = this->requested_action;
    if ((requested_action < 0) || (requested_action > 8)) {
        this->requested_action = 0;
    }
    if (visual_record.classFlags & 2) {
        this->requested_action = (this->requested_action + 1);
        if ((s32) static_cast<u8>(visual_record.classId) == 6) {
            this->requested_action = (this->requested_action + 1);
        }
    }
}

void TAdChrSelPlayerGC::render() {
    if (state == 3) {
        update_chara_making();
    }
}

void TAdChrSelPlayerGC::update_chara_making() {
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation.y);
    set_texture_list(preview_data->get_status_sub());
    draw_model_with_arg(preview_data->get_body_model());
    push_matrix_from(get_joint_matrix(0x3A));
    set_texture_list(preview_data->get_status_data());
    TObjPlayer::draw_part_model(preview_data->get_attachment_model());
    pop_matrix();
    if (preview_data->get_head_model() != NULL) {
        push_matrix_from(get_joint_matrix(0x3B));
        set_texture_list(preview_data->get_chara_making_data());
        TCharaMaking::enable_making();
        TObjPlayer::draw_part_model(preview_data->get_head_model());
        TCharaMaking::clear_flag_bit0();
        pop_matrix();
    }
    if (preview_data->get_hair_model() != NULL) {
        push_matrix_from(get_joint_matrix(0x3B));
        set_texture_list(preview_data->get_chara_making_data());
        TCharaMaking::enable_making();
        draw_model_tinted_opaque(preview_data->get_hair_model(), &visual_record);
        TCharaMaking::clear_flag_bit0();
        pop_matrix();
    }
    pop_matrix();
}

void TAdChrSelPlayerGC::draw_model_with_arg(NJS_OBJECT *model) {
    this->model = model;
    set_motion_interpolation_flag();
    draw_saving_joints_checked();
}

void TAdChrSelPlayerGC::draw_model_tinted_opaque(NJS_OBJECT *model, CharacterAppearanceFields *appearance) {
    draw_model_tinted(model, appearance, 1.0f);
}

void TAdChrSelPlayerGC::draw_model_tinted(NJS_OBJECT *model, CharacterAppearanceFields *appearance, f32 alpha) {
  NJS_ARGB color;
  int one;
  saved_model_render_flags = model_render_flags;
  saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
  saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
  model_render_flags |= 0x10;
  one = 1;
  if (alpha < 1.0f)
  {
    set_chunk_material_override_pair(-one, 0x800);
  }
  color.a = alpha;
  color.r = 0.003921569f * ((f32) appearance->red);
  color.g = 0.003921569f * ((f32) appearance->green);
  color.b = 0.003921569f * ((f32) appearance->blue);
  set_constant_material(&color);
  TObjPlayer::draw_part_model(model);
  chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
  chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
  model_render_flags = saved_model_render_flags;
}

BOOL is_player_model_shown(TAdChrSelPlayerGC *player) {
    return player->state == 3 ? TRUE : FALSE;
}

void enable_spin_model(TAdChrSelPlayerGC *player) { player->spin_model = 1; }

void TAdChrSelPlayerGC::reset_cursor() { set_cursor_index(0); }

void TAdChrSelPlayerGC::set_cursor_index_1() { set_cursor_index(1); }

void TAdChrSelPlayerGC::set_cursor_index_2() { set_cursor_index(2); }

void reset_animation_ticks(TAdChrSelPlayerGC *player) { player->animation_ticks = 0; }

TObjMotionAction chr_sel_player_actions[9] = {
    { 1, 0, 0x21, 1.0f, 0 },
    { 1, 0, 0x1, 1.0f, 0 },
    { 1, 0, 0x0, 1.0f, 0 },
    { 1, 0, 0x1F, 1.0f, 0 },
    { 1, 0, 0x20, 1.0f, 0 },
    { 1, 0, 0x1E, 1.0f, 0 },
    { 1, 0, 0x2F, 1.0f, 0 },
    { 1, 0, 0x30, 1.0f, 0 },
    { 1, 0, 0x2E, 1.0f, 0 },
};
