#ifndef _DOLPHIN_PAD_H_
#define _DOLPHIN_PAD_H_

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PAD_SPEC_0 0
#define PAD_SPEC_1 1
#define PAD_SPEC_2 2
#define PAD_SPEC_3 3
#define PAD_SPEC_4 4
#define PAD_SPEC_5 5

#define PAD_MOTOR_STOP 0
#define PAD_MOTOR_RUMBLE 1
#define PAD_MOTOR_STOP_HARD 2

#define PAD_CHAN0_BIT 0x80000000

#define PAD_MAX_CONTROLLERS     4

#define PAD_BUTTON_LEFT  (1 << 0)
#define PAD_BUTTON_RIGHT (1 << 1)
#define PAD_BUTTON_DOWN  (1 << 2)
#define PAD_BUTTON_UP    (1 << 3)
#define PAD_TRIGGER_Z    (1 << 4)
#define PAD_TRIGGER_R    (1 << 5)
#define PAD_TRIGGER_L    (1 << 6)
#define PAD_BUTTON_A     (1 << 8)
#define PAD_BUTTON_B     (1 << 9)
#define PAD_BUTTON_X     (1 << 10)
#define PAD_BUTTON_Y     (1 << 11)
#define PAD_BUTTON_MENU  (1 << 12)
#define PAD_BUTTON_START (1 << 12)

#define PAD_ERR_NONE 0
#define PAD_ERR_NO_CONTROLLER -1
#define PAD_ERR_NOT_READY -2
#define PAD_ERR_TRANSFER -3

#define RES_WIRELESS_LITE 0x40000

typedef void (*PADSamplingCallback)(void);

typedef struct PADStatus
{
 u16 button;
 s8 stickX;
 s8 stickY;
 s8 substickX;
 s8 substickY;
 u8 triggerLeft;
 u8 triggerRight;
 u8 analogA;
 u8 analogB;
 s8 err;
} PADStatus;

BOOL PADReset(u32 mask);
BOOL PADRecalibrate(u32 mask);
BOOL PADInit();
u32 PADRead(PADStatus* status);
void PADSetSamplingRate(u32 msec);
void __PADTestSamplingRate(u32 tvmode);
void PADControlAllMotors(const u32 *commandArray);
void PADControlMotor(s32 chan, u32 command);
void PADSetSpec(u32 spec);
u32 PADGetSpec();
BOOL PADGetType(s32 chan, u32* type);
BOOL PADSync(void);
void PADSetAnalogMode(u32 mode);
PADSamplingCallback PADSetSamplingCallback(PADSamplingCallback callback);

void PADClamp(PADStatus * status);

void __PADDisableXPatch(void);
BOOL __PADDisableRecalibration(BOOL disable);
extern u32 __PADSpec;

#ifdef __cplusplus
}
#endif

#endif
