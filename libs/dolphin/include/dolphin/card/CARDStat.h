#ifndef _DOLPHIN_CARDSTAT_H_
#define _DOLPHIN_CARDSTAT_H_

typedef struct CARDStat
{
 char fileName[CARD_FILENAME_MAX];
 u32 length;
 u32 time;
 u8 gameName[4];
 u8 company[2];
 u8 bannerFormat;
 u32 iconAddr;
 u16 iconFormat;
 u16 iconSpeed;
 u32 commentAddr;
 u32 offsetBanner;
 u32 offsetBannerTlut;
 u32 offsetIcon[CARD_ICON_MAX];
 u32 offsetIconTlut;
 u32 offsetData;
} CARDStat;

s32 CARDGetStatus(s32 chan, s32 fileNo, CARDStat *stat);
s32 CARDSetStatusAsync(s32 chan, s32 fileNo, CARDStat *stat, CARDCallback callback);
s32 CARDSetStatus(s32 chan, s32 fileNo, struct CARDStat * stat);

#endif
