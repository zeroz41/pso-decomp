#ifndef _DOLPHIN_OS_INTERNAL_H_
#define _DOLPHIN_OS_INTERNAL_H_

#include <dolphin/os.h>

extern char* __OSExceptionNames[15];
extern OSTime __OSStartTime;

unsigned long __OSIsDebuggerPresent(void);
void __OSPSInit(void);

extern void* BOOT_REGION_START AT_ADDRESS(0x812FDFF0);
extern void* BOOT_REGION_END AT_ADDRESS(0x812FDFEC);

extern volatile int __OSCurrHeap;

void __OSInitAudioSystem(void);
void __OSStopAudioSystem(void);

void __OSCacheInit(void);

void __OSContextInit(void);

void __OSInitMemoryProtection(void);

void __OSUnhandledException(unsigned char exception, struct OSContext* context,
                            unsigned long dsisr, unsigned long dar);

extern void __RAS_OSDisableInterrupts_begin(void);
extern void __RAS_OSDisableInterrupts_end(void);

extern unsigned long long __OSSpuriousInterrupts;
extern char* __OSInterruptNames[33];
extern char* __OSPIErrors[8];
extern OSErrorHandlerEx __OSErrorTable[16];

__OSInterruptHandler __OSSetInterruptHandler(__OSInterrupt interrupt,
                                             __OSInterruptHandler handler);
__OSInterruptHandler __OSGetInterruptHandler(__OSInterrupt interrupt);
void __OSInterruptInit(void);
OSInterruptMask __OSMaskInterrupts(OSInterruptMask global);
OSInterruptMask __OSUnmaskInterrupts(OSInterruptMask global);
void __OSDispatchInterrupt(__OSException exception, OSContext* context);
void __OSModuleInit(void);

void __OSUnlockAllMutex(struct OSThread* thread);
int __OSCheckDeadLock(struct OSThread* thread);
int __OSCheckMutexes(struct OSThread* thread);

void __OSResetSWInterruptHandler(__OSInterrupt exception,
                                 struct OSContext* context);

void __OSDoHotReset(s32);

void __OSReboot(u32, u32);

int __OSGetRTC(unsigned long* rtc);
int __OSSetRTC(unsigned long rtc);
void __OSInitSram();
struct OSSram* __OSLockSram(void);
struct OSSramEx* __OSLockSramEx(void);
int __OSUnlockSram(int commit);
int __OSUnlockSramEx(int commit);
int __OSSyncSram(void);
int __OSCheckSram(void);
int __OSReadROM(void* buffer, long length, long offset);
int __OSReadROMAsync(void* buffer, long length, long offset,
                     void (*callback)());
unsigned char __OSGetBootMode(void);
void __OSSetBootMode(unsigned char ntd);

extern void __OSSystemCallVectorStart();
extern void __OSSystemCallVectorEnd();

void __OSInitSystemCall(void);

void __OSThreadInit(void);
long __OSGetEffectivePriority(struct OSThread* thread);
void __OSPromoteThread(struct OSThread* thread, long priority);
void __OSReschedule(void);

void __OSSetTime(long long time);
long long __OSGetSystemTime();
void __OSSetTick(register unsigned long newTicks);

extern u32 __OSGetDIConfig(void);

__declspec(section ".init") asm void __init_hardware(void);
__declspec(section ".init") asm void __flush_cache(void* address,
                                                   unsigned int size);
void __init_user(void);
void __init_cpp(void);
void __fini_cpp(void);
void _ExitProcess(void);

void __start(void);

__declspec(section ".init") extern void __start(void);

void InitMetroTRK(void);
void EnableMetroTRKInterrupts(void);

void __OSEVStart(void);
void __OSEVEnd(void);
void __OSEVSetNumber(void);
void __OSExceptionVector(void);
void __DBVECTOR(void);
void __OSDBINTSTART(void);
void __OSDBINTEND(void);
void __OSDBJUMPEND(void);

extern u8 __ArenaLo[];
extern u8 __ArenaHi[];
extern u8 _stack_addr[];
extern u8 _stack_end[];
extern u8 _SDA_BASE_[];
extern u8 _SDA2_BASE_[];

typedef struct RomSection {
    void* romOfs;
    void* virtualOfs;
    size_t size;
} RomSection;

typedef struct BssSection {
    void* virtualOfs;
    size_t size;
} BssSection;

__declspec(section ".init") extern RomSection _rom_copy_info[];
__declspec(section ".init") extern BssSection _bss_init_info[];

int main(int argc, char** argv);

long long __get_clock(void);
unsigned long __get_time(void);
int __to_gm_time(void);

#endif
