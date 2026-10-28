#include "types.h"
#include "pso/player/TObjPlayer_8012D8E4.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 scale_current_matrix(void *);
u8 get_item_index__5TItemFv();
s32 post_translate_matrix(void *);
s32 rotate_matrix_z(s32, s32);
s32 rotate_matrix_x(s32, s32);
}

extern const f32 lbl_805DAF34;

void enlarge_flight_cutter_slicer(void *arg0) {
    if (arg0 != NULL) {
        *(f32 *)((s8 *)arg0 + 0x68) = (f32) lbl_805DAF34;
        *(f32 *)((s8 *)arg0 + 0x6C) = (f32) lbl_805DAF34;
        *(f32 *)((s8 *)arg0 + 0x70) = (f32) lbl_805DAF34;
    }
}

void TObjPlayer::setup_item_render() {
    s32 player_list;

    switch ((s32) get_item_index__5TItemFv()) {
    case 5:
        player_list = TObjPlayer::get_player_list();
        switch (player_list) {
        case 1:
            rotate_matrix_x(0, *(s32 *)&this->unk_1F8);
            return;
        case 2:
            scale_current_matrix((u8 *)&this->m_1fc);
            return;
        }
        break;
    case 7:
        switch (TObjPlayer::get_player_list()) {
        case 4:
            post_translate_matrix((u8 *)&this->m_1fc);
            return;
        case 2:
            rotate_matrix_z(0, *(s32 *)&this->unk_1F8);
            break;
        }
        break;
    }
}
