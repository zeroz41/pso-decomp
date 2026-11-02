#include "pso/TAdSoniclogo.h"

#include "types.h"
#include "pso/TLogo.h"
#include "pso/misc/THunterGuildSeqOffline.h"

struct Obj_8001C21C { u8 pad[0x1c]; s32 f1c; };

extern "C" {
s32 render_logo_with_default(void *, int, int, f32);
extern void* sonic_logo_object;
extern int TAdSoniclogo__state;
extern void *tl_00;
void *__nw__7TObjectFUl(u32 size);
int queue_destruction__7TObjectFv(void);

void TAdSoniclogo::request_destroy() { queue_destruction__7TObjectFv(); TAdSoniclogo__state = 1; }

}

void TAdSoniclogo::render() {
    render_logo_with_default(sonic_logo_object, 16, -1, -150.0f);
}
void TAdSoniclogo::run_task() {
    Obj_8001C21C *self = (Obj_8001C21C *)this;
    switch (TAdSoniclogo__state) {
    case 0:
        break;
    case 1:
        if (++self->f1c > 0x3c) {
            void *p;
            TAdSoniclogo__state = 2;
            p = __nw__7TObjectFUl(0x28);
            if (p != 0) {
                ((THunterGuildSeqOffline *)p)->init(tl_00, (void *)TLogo::request_exit);
            }
        }
        break;
    case 2:
        break;
    }
}
TAdSoniclogo::~TAdSoniclogo() {}
