#include "types.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/boss/olgaflow/TBoss6Demo15_TYPE2_WAIT.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/unk/TLobby.h"
struct O_80340040 { u8 pad[0x60]; void *o[10]; };

struct Vec_8033FF78 { f32 x, y, z; };

struct O_8033FF78 { u8 pad[0x24]; s32 f24; u8 pad28[0x40 - 0x28]; Vec_8033FF78 pos; };

struct P_8033FF78 { u8 pad[0x38]; Vec_8033FF78 pos; };

struct Vec_8034009C { f32 x, y, z; };

struct E_8034009C { Vec_8034009C a; Vec_8034009C b; s32 f18; };

struct P_8034009C {
    u8 pad0[0xC];
    Vec_8034009C a;
    s32 f18;
    s32 f1c;
    s32 f20;
    Vec_8034009C b;
    s32 f30;
    s32 f34;
};

struct O_8034009C { u8 pad[0x60]; void *o[10]; };

extern "C" {
void fn_80340040(O_80340040 *arg0);
int get_player_data__10TObjPlayerFi(int a0);
f32 vector_length(void *);
s32 subtract_vector(void *, void *);
extern const f32 lbl_805DFAF8;
s32 create__10TObjMapCsnFl(void *);
extern E_8034009C lbl_8047843C[];
void fn_8034009C(O_8034009C *arg0);

void TBoss6Demo15_TYPE2_WAIT::check_any_player_near() {
    O_8033FF78 *arg0 = (O_8033FF78 *)this;
    Vec_8033FF78 v;
    s32 n;
    s32 i;
    f32 lim;
    f32 y;
    P_8033FF78 *p;
    arg0->f24 = 0;
    n = TLobby::get_game_mode();
    y = lbl_805DFAF8;
    lim = 25.0f;
    for (i = 0; i < n; i++) {
        p = (P_8033FF78 *)get_player_data__10TObjPlayerFi(i);
        if (((TBoss6PlotFalz *)p)->is_active() != 0) {
            VecCopy((Vec *)&v, (const Vec *)&arg0->pos);
            subtract_vector(&v, &p->pos);
            v.y = y;
            if (vector_length(&v) <= lim) {
                arg0->f24 = 1;
                return;
            }
        }
    }
}

void fn_80340040(O_80340040 *arg0) {
    s32 i;
    for (i = 0; i < 10; i++) {
        if (arg0->o[i] != 0) {
            queue_destruction__7TObjectFv(arg0->o[i]);
            arg0->o[i] = 0;
        }
    }
}
void fn_8034009C(O_8034009C *arg0) {
    P_8034009C prm;
    s32 i;
    s32 j;
    for (j = 0; j < 10; j++) {
        arg0->o[j] = 0;
    }
    prm.f30 = 2;
    prm.f34 = 0;
    for (i = 0; i < 10; i++) {
        E_8034009C *e = &lbl_8047843C[i];
        VecCopy((Vec *)&prm.a, (const Vec *)&e->a);
        prm.f18 = 0;
        prm.f1c = e->f18;
        prm.f20 = 0;
        VecCopy((Vec *)&prm.b, (const Vec *)&e->b);
        arg0->o[i] = (void *)create__10TObjMapCsnFl(&prm);
    }
}

}
