#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"

    extern const float lbl_805DC098;
void TUnk_804B9870::reset_motion_fields() {
    m_20 = 0;
    prev_position.z = lbl_805DC098;
    prev_position.y = lbl_805DC098;
    prev_position.x = lbl_805DC098;
    home_position.z = lbl_805DC098;
    home_position.y = lbl_805DC098;
    home_position.x = lbl_805DC098;
    rotation_z = 0;
    rotation_y = 0;
    rotation_x = 0;
    center.z = lbl_805DC098;
    center.y = lbl_805DC098;
    center.x = lbl_805DC098;
    set_entry = NULL;
}
