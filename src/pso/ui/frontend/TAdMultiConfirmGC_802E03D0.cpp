#include "pso/player/TPlyCharData.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdChrSelPlayerGC.h"
#include "pso/ui/frontend/TAdPlyStatusGC.h"
#include "pso/object/ambient/TObjFish.h"
#pragma defer_codegen on
#include "types.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/ui/charcreate/CharacterPreview.h"
#include "pso/boss/galgryphon/TObjBoss5Pillar_8028B714.h"
#include "pso/ui/frontend/TAdMultiConfirmGC_802E03D0.h"

#include "pso/object/base/TObjMotion.h"
#include "pso/npc/TNpcPlayer.h"

#include "pso/ui/frontend/TAdMultiConfirmGC.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TPlyCharData.h"


extern "C" {
extern const char lbl_804728D0[];
const char lbl_804728D0[] = "TAdChrSelPlayerGC";
}

struct Stack_802E0468
{
  f32 sp8;
  f32 spC;
  f32 sp10;
  f32 sp14;
};

extern "C" {
void set_chunk_material_override_pair(s32, s32);
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;

typedef struct Stack_802E0468 Stack_802E0468;

s32 post_translate_matrix(void *);
s32 rotate_matrix_y(int, int);

extern TObjMotionAction lbl_804E2F78[9];
u8 *TAdMultiPlyChrSelectGC__resource_bundle;

void copy_player_visual_record(void *, const void *);

}

TAdChrSelPlayerGC *multi_chr_select_player_slot_table[4] = { NULL };

extern "C" {

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
        rotation_x = 0;
        rotation_y = 0xF3D5;
        rotation_z = 0;
        spin_model = 1;
        break;
    case 1:
    case 2:
        position.x = 0.0f;
        position.y = -10.5f;
        position.z = -40.0f;
        rotation_x = 0;
        rotation_y = 0xF3D5;
        rotation_z = 0;
        spin_model = 1;
        break;
    case 3:
        position.x = 28.0f * formation_index + -14.0f;
        position.y = -10.0f;
        position.z = -110.0f;
        rotation_x = 0;
        rotation_y = 182.04445f * (7.25f - 14.5f * formation_index);
        rotation_z = 0;
        break;
    case 4:
        position.x = 19.0f * formation_index + -19.0f;
        position.y = -10.0f;
        position.z = -110.0f;
        rotation_x = 0;
        rotation_y = 182.04445f * (9.8f - 9.8f * formation_index);
        rotation_z = 0;
        break;
    case 5: {
        f32 xs[4] = { -21.5f, -8.0f, 7.0f, 23.5f };
        f32 zs[4] = { -110.0f, -118.56f, -110.0f, -118.56f };
        f32 rs[4] = { 11.6f, 3.86f, -3.64f, -11.21f };
        position.x = xs[formation_index];
        position.y = -10.0f;
        position.z = zs[formation_index];
        rotation_x = 0;
        rotation_y = 182.04445f * rs[formation_index];
        rotation_z = 0;
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
        TAdPlyStatusGC::set_status_index(reinterpret_cast<saddr>(status), status_index);
    }
}

TAdChrSelPlayerGC::~TAdChrSelPlayerGC() {
    if (multi_chr_select_player_slot_table[slot] != NULL) {
        multi_chr_select_player_slot_table[slot] = NULL;
    }
    if (joint_matrices != NULL) {
        mem_free(joint_matrices);
        joint_matrices = NULL;
    }
    if (preview_data != NULL) {
        free_chcr_resources(preview_data, 1);
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
            free_chcr_resources(preview_data, 1);
            preview_data = NULL;
        }
        if (pending_state != 0) {
            state = pending_state - 1;
            pending_state = 0;
        }
        break;
    case 1:
        if (preview_data != NULL) {
            free_chcr_resources(preview_data, 1);
            preview_data = NULL;
        }
        if (pending_state != 0) {
            state = pending_state - 1;
            pending_state = 0;
            break;
        }
        switch (layout_mode) {
        case 0:
            copy_player_visual_record(&visual_record, &TAdSinglePlyChrSelectGC::get_char_index(0xFFFF)->m_disp_part2);
            p = new CharacterPreview(this, &visual_record, 0);
            preview_data = p;
            rotation_y = 0xF3D5;
            break;
        case 1:
            copy_player_visual_record(&visual_record, &TAdSinglePlyChrSelectGC::get_entry(status_index)->m_disp_part2);
            p = new CharacterPreview(this, &visual_record, 0);
            preview_data = p;
            rotation_y = 0xF3D5;
            break;
        case 2:
            copy_player_visual_record(&visual_record, &TAdSinglePlyChrSelectGC::get_char_index(0xFFFF)->m_disp_part2);
            p = new CharacterPreview(this, &visual_record, 0);
            preview_data = p;
            rotation_y = 0xF3D5;
            break;
        case 3:
        case 4:
        case 5:
            copy_player_visual_record(&visual_record, &TAdSinglePlyChrSelectGC::get_char_table_entry(slot)->m_disp_part2);
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
                free_chcr_resources(preview_data, 1);
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
                free_chcr_resources(preview_data, 1);
                preview_data = NULL;
            }
            state = pending_state - 1;
            pending_state = 0;
        } else {
            if (spin_model == 1) {
                rotation_y = rotation_y - 0x100;
            }
            animation_ticks = animation_ticks + 1;
            t = animation_ticks;
            if (t == 0x384 || t == 0x708) {
                TAdMultiConfirmGC::set_cursor_index_1(this);
            } else if (t == 0x546) {
                TAdMultiConfirmGC::set_cursor_index_2(this);
            }
            if (animation_ticks == 0x8CA) {
                TAdMultiConfirmGC::reset_cursor(this);
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
    this->set_action_table(lbl_804E2F78);
    this->set_motion_list(reinterpret_cast<BmlResource *>(TAdMultiPlyChrSelectGC__resource_bundle)->motions);
    set_cursor_index(0);
    set_animation((this->requested_action));
}

void TAdChrSelPlayerGC::set_cursor_index(s32 arg1) {
    s16 requested_action;

    this->requested_action = (s16) (arg1 * 3);
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
    post_translate_matrix((u8 *)&position);
    rotate_matrix_y(0, rotation_y);
    TObjFish::set_global_param(preview_data->get_status_sub());
    draw_model_with_arg((void *)preview_data->get_body_model());
    push_matrix_from((void *)get_joint_matrix(0x3A));
    TObjFish::set_global_param(preview_data->get_status_data());
    TObjPlayer::play_phase_transition_sound(preview_data->get_attachment_model());
    pop_matrix();
    if (preview_data->get_head_model() != 0U) {
        push_matrix_from((void *)get_joint_matrix(0x3B));
        TObjFish::set_global_param(preview_data->get_chara_making_data());
        TCharaMaking::enable_making();
        TObjPlayer::play_phase_transition_sound(preview_data->get_head_model());
        TCharaMaking::clear_flag_bit0();
        pop_matrix();
    }
    if (preview_data->get_hair_model() != 0U) {
        push_matrix_from((void *)get_joint_matrix(0x3B));
        TObjFish::set_global_param(preview_data->get_chara_making_data());
        TCharaMaking::enable_making();
        TObjPlayer__sub_802E0580(this, preview_data->get_hair_model(), &visual_record);
        TCharaMaking::clear_flag_bit0();
        pop_matrix();
    }
    pop_matrix();
}

void TAdChrSelPlayerGC::draw_model_with_arg(void *model) {
    this->model = model;
    set_motion_interpolation_flag();
    draw_saving_joints_checked();
}

void TObjPlayer__sub_802E0580(void * _w0, int _w1, void * _w2) {
    ((s32 (*)(f32))TObjPlayer__sub_802E0468)(1.0f);
}

void TObjPlayer__sub_802E0468(long long child, u8 *arg2, f32 farg0) {
  Stack_802E0468 stack;
  int new_var;
  saved_model_render_flags = model_render_flags;
  saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
  saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
  model_render_flags |= 0x10;
  new_var = 1;
  if (farg0 < 1.0f)
  {
    set_chunk_material_override_pair(-new_var, 0x800);
  }
  stack.sp8 = farg0;
  stack.spC = 0.003921569f * ((f32) (*((s16 *) (((s8 *) arg2) + 0x42))));
  stack.sp10 = 0.003921569f * ((f32) (*((s16 *) (((s8 *) arg2) + 0x44))));
  stack.sp14 = 0.003921569f * ((f32) (*((s16 *) (((s8 *) arg2) + 0x46))));
  set_constant_material((const NJS_ARGB *)((&stack.sp8)));
  TObjPlayer::play_phase_transition_sound(child);
  chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
  chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
  model_render_flags = saved_model_render_flags;
}

bool fn_802E0454(u8 *arg0) {
    return *(s32 *)((s8 *)arg0 + 0xFC) == 3;
}

void TAdMultiConfirmGC__sub_802E0448(void* p) { *(s32*)((char*)p + 0x11c) = 1; }

int TAdMultiConfirmGC::reset_cursor(void* p) { return ((int (*)(void *, int))set_cursor_index__17TAdChrSelPlayerGCFl)(p, 0); }

int TAdMultiConfirmGC::set_cursor_index_1(void* p) { return ((int (*)(void *, int))set_cursor_index__17TAdChrSelPlayerGCFl)(p, 1); }

int TAdMultiConfirmGC::set_cursor_index_2(void* p) { return ((int (*)(void *, int))set_cursor_index__17TAdChrSelPlayerGCFl)(p, 2); }

void TAdMultiConfirmGC__sub_802E03D0(void* p) { *(s32*)((char*)p + 0x118) = 0; }

}

TObjMotionAction lbl_804E2F78[9] = {
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
