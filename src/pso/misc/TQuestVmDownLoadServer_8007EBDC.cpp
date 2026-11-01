#include "types.h"
#include "pso/misc/TUnk_8048DF58.h"
#include "pso/misc/TQuestVmDownLoadServer_8007EBDC.h"

#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/system/memory.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern "C" {
extern u8 lbl_805005A4[];
extern u8 lbl_80500598[];
void *__ct__13TUnk_8048DF58Fv(void *arg0);
void __register_global_object(void *obj, void *dtor, void *entry);
int fn_803DE864(void*);

int TQuestVmDownLoadServer__sub_8007EBDC(void* p) { return fn_803DE864(p); }
void *TQuestVmDownLoadServer::alloc(u32 size) { return xmalloc(size); }


void TQuestVmDownLoadServer::register_global_instance_dtor() {
    __register_global_object(__ct__13TUnk_8048DF58Fv(lbl_805005A4), (void *)__dt__13TUnk_8048DF58Fv, lbl_80500598);
}

}
TUnk_8048DF58::~TUnk_8048DF58() {

}
TUnk_8048DF58::TUnk_8048DF58() : TObject(0) {

}
__declspec(section ".ctors") static void *const __sinit_TQuestVmDownLoadServer_8007EBDC_cpp_ref = (void *)TQuestVmDownLoadServer::register_global_instance_dtor;
