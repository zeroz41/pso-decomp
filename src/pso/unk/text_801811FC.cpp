#include "types.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_801811FC.h"
#include "pso/object/TObjMotion.h"

extern "C" {

void __dl__7TObjectFPv(void *);

f32 fn_801811FC(void* p) { return *(f32*)((char*)p + 0x94); }
f32 fn_80181204(void* p) { return *(f32*)((char*)p + 0x90); }

extern s32 __vt__18TObjCityAirCar_Car[];

void *__dt__18TObjCityAirCar_CarFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__18TObjCityAirCar_Car;
        if (*(void **)((s8 *)arg0 + 0xA8) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0xA8)); }
        __dt__8TObjBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}
