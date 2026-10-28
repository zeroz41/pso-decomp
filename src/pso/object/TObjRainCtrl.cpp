#include "pso/TObjRainCtrl.h"
#include "pso/object/TObjRain.h"
#include "pso/object/TObjRainCtrl.h"
#include "pso/map/FloorArea.h"

#include "types.h"
#include "pso/map/FloorArea.h"

extern "C" {
u32 __nw__7TObjectFUl(int);
extern s32 tl_particle;
void __ct__7TObjectFP7TObject(void *);

extern s32 __vt__12TObjRainCtrl[];
extern void *lbl_805D3428;

#pragma push
#pragma fp_contract on
void TObjRainCtrl::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    void *p;
    temp_r0 = *(s32 *)((s8 *)arg0 + 0x1C) - 1;
    *(s32 *)((s8 *)arg0 + 0x1C) = temp_r0;
    if (temp_r0 < 0) {
        if (get_current_floor_area() == AREA_GAL_GRYPHON) {
            p = (void *) __nw__7TObjectFUl(0x220);
            if (p != NULL) {
                __ct__8TObjRainFv((u8 *)p, (tl_particle), 0x24);
            }
        } else {
            p = (void *) __nw__7TObjectFUl(0x220);
            if (p != NULL) {
                __ct__8TObjRainFv((u8 *)p, (tl_particle), 9);
            }
        }
        *(s32 *)((s8 *)arg0 + 0x1C) = 2;
    }
}
#pragma pop

TObjRainCtrl::~TObjRainCtrl() {}
void *TObjRainCtrl__ct(void *rain_ctrl) {
    __ct__7TObjectFP7TObject(rain_ctrl);
    *(s32 **)((s8 *)rain_ctrl + 0x18) = __vt__12TObjRainCtrl;
    *(void * *)&((TObjRainCtrl *)rain_ctrl)->m_name = lbl_805D3428;
    *(u32 *)((s8 *)rain_ctrl + 0x1C) = 2;
    return rain_ctrl;
}

}
