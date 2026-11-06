#include "types.h"
#include "pso/player/TPlyCharData.h"
#include "pso/unk/text_801A3BB8.h"
extern "C" {
u8 TPlyCharData__global_destructor_registration[0xC];
u8 TPlyCharData__global_character_data[0x41C];
void *__ct__12TPlyCharDataFv(void *p);
void __register_global_object(void *obj, void *dtor, void *link);
void fn_801A3BB8(void) {
    __register_global_object(__ct__12TPlyCharDataFv(TPlyCharData__global_character_data), (void *)__dt__12TPlyCharDataFv, TPlyCharData__global_destructor_registration);
}

}

__declspec(section ".ctors") static void *const __sinit_text_801A3BB8_cpp_ref = (void *)fn_801A3BB8;
