#include "types.h"
#include "pso/unk/text_80181278.h"
#include "pso/unk/TObjCityAirCar_Car.h"

struct RecoveredGlobal_80181278_lbl_804B5908 {
    s32 value;
    u8 remaining[0x30];
};

extern "C" {
u8 * __ct__8TObjBaseFP7TObject(void *);
extern RecoveredGlobal_80181278_lbl_804B5908 __vt__18TObjCityAirCar_Car;
extern s32 TObjCityAirCar_Car__name;
extern const f32 lbl_805DBBC8;
typedef char RecoveredGlobal_80181278_lbl_804B5908_size[sizeof(RecoveredGlobal_80181278_lbl_804B5908) == 0x34 ? 1 : -1];
u8 *construct_city_air_car(TObjCityAirCar_Car *city_air_car_car, s32 arg1, s32 arg2, s32 arg3, f32 farg0) {
    __ct__8TObjBaseFP7TObject(city_air_car_car);
    *(s32 **)((s8 *)city_air_car_car + 0x18) = &__vt__18TObjCityAirCar_Car.value;
    *(s32 *)((s8 *)city_air_car_car + 0) = (s32) TObjCityAirCar_Car__name;
    *(f32 *)((s8 *)city_air_car_car + 0x90) = (f32) lbl_805DBBC8;
    *(s32 *)((s8 *)city_air_car_car + 0x98) = arg2;
    city_air_car_car->m_9c = arg3;
    city_air_car_car->m_94 = farg0;
    *(s32 *)((s8 *)city_air_car_car + 0xA0) = 0;
    city_air_car_car->m_a4 = 0;
    *(s32 *)((s8 *)city_air_car_car + 0xA8) = 0;
    city_air_car_car->update_path_motion();
    city_air_car_car->rotation_z = 0;
    return (u8 *)city_air_car_car;
}

}
