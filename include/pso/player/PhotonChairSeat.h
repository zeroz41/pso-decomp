#ifndef PSO_PLAYER_PHOTONCHAIRSEAT_H
#define PSO_PLAYER_PHOTONCHAIRSEAT_H

#include "types.h"

// TObjPlayer + 0x34C: the player's seat on a lobby photon chair. Action 0x18 sits the player down with
// the animation stored here and create_chair spawns the TPlyPhotonChair for the owner. While seated,
// turning sends 6xAF and moving sends 6xB0, each at most once every 8 frames; the 6xAF handler stores
// the angle the player turns to.
struct PhotonChairSeat {
    s16 animation;    // -1 when none
    u16 owner_id;     // entity id of the player, matched against TPlyPhotonChair's owner
    s16 pad_4;
    s16 delay_6xAF;   // frames until the next 6xAF may be sent
    s16 delay_6xB0;   // frames until the next 6xB0 may be sent
    u8 pad_A[0x2];
    s32 target_angle; // the rotation_y the seated player turns towards
    s32 move_angle;   // the stick angle a 6xB0 packet carries

    PhotonChairSeat();
    void reset();
    ~PhotonChairSeat();
    void set_owner_id(u16 id);
    void update();  // empty; TObjPlayer::update_state_group calls it
    int create_chair();
    void set_move_angle(s32 v);
    void set_target_angle(s32 angle);
    s32 get_target_angle();
    s16 get_animation();
    void set_animation(s16 v);
    void start_delay_6xAF();
    void tick_delay_6xAF();
    s32 is_delay_6xAF_over();
    void start_delay_6xB0();
    void tick_delay_6xB0();
    s32 is_delay_6xB0_over();
};

#endif
