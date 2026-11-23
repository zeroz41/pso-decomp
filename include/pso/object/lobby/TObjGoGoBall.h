#ifndef PSO_OBJECT_LOBBY_TOBJGOGOBALL_H
#define PSO_OBJECT_LOBBY_TOBJGOGOBALL_H
#include "types.h"
#include "pso/object/base/TObjChara.h"

// The gogo ball in play, spawned by TGoGoBallGame::run_task on the beat.
class TObjGoGoBall : public TObjChara {
public:
    TObjGoGoBall(TObject *parent);
    virtual ~TObjGoGoBall();
    virtual void run_task();
    virtual void render();
    s32 reflect_velocity_off_collision(void *, void *);
    void start_throw(s32 angle);  // sets the throw velocity from the configuration along angle
    void update_goal_checks(u16);
    void update_best_time();
    void send_local_player_walk();
    void draw_shadow_on_ground();
    void draw_shadow_quads(Vec *pos, Vec *dir, s32 angle, Vec *scale, f32 alpha);
    s32 heading;          // the throw angle; render turns the drawn ball toward it
    s32 roll;             // render's rolling angle about the travel axis
    f32 gravity;          // added to velocity.y every frame
    f32 restitution;      // gogo_ball_configuration.restitution
    Vec velocity;
    s32 time;             // TLobby::get_clock_frames() % 2592
    s32 sequence;         // the 6x79 sequence of the last throw applied
    s32 resting;          // set while the ball does not move
    s32 rest_count;       // times the ball came to rest ("Go!")
    s32 scored;           // set once a goal counted, until the goal flags clear
    CollisionBody collision_body;
    f32 throw_forward_speed;
    f32 throw_up_speed;   // the vertical speed, reduced by restitution on every bounce
    f32 pad_398[2];
    f32 throw_speed;      // length of the launch velocity
};
LAYOUT_ASSERT(TObjGoGoBall_size, sizeof(TObjGoGoBall) == 0x3A4);

#endif
