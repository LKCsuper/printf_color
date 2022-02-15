#ifndef _PRINTF_COLOR_H
#define _PRINTF_COLOR_H

#include "stdio.h"
#define PRINTF_COLOR            1 //颜色日志输出模式（显示终端需要支持）
#if PRINTF_COLOR
/* 字体颜色 */
#define BLACK                30
#define RED                  31
#define GREEN                32
#define BROWN                33
#define YELLOW               33
#define BLUE                 34
#define PURPLE               35
#define CYAN                 36
#define GRAY                 37
#define WHITE                37

/* 字体格式 */
#define BOLD                 1
#define UNDERLINE            4
#define BLINK                5
#define REVERSE              7
#define HIDE                 8
#define CLEAR                2
#define NONE                 0

/* 背景颜色 */
#define BLACK_BACKGROUND                40
#define RED_BACKGROUND                  41
#define GREEN_BACKGROUND                42
#define YELLOW_BACKGROUND               43
#define BLUE_BACKGROUND                 44
#define PURPLE_BACKGROUND               45
#define CYAN_BACKGROUND                 46
#define WHITE_BACKGROUND                47

/* dis_mode:显示模式 fwd_clor:前景色 bak_clor:背景色 */
#define COLR_SET(dis_mode, fwd_clor, bak_clor) {\
    printf("\033[%d;%d;%dm",dis_mode, fwd_clor, bak_clor);\
}
#define DEVICE_LOG(dis_mode, fwd_clor, bak_clor, dev_name,...) {\
/*设置颜色*/ COLR_SET(dis_mode, fwd_clor, dev_name);\
/*设置参数*/ printf(dev_name, ##__VA_ARGS__);\
/*设置结束*/ COLR_SET(0, 0, 0);\
}
#define DEVICE_MULTI_LOG(dis_mode0, fwd_clor0, bak_clor0, \
dis_mode1, fwd_clor1, bak_clor1, dev_name,...) {\
/*设置device name的颜色*/       COLR_SET(x0,y0,z0);\
/*设置device name*/ 		printf("%s",#dev_name);\
/*设置参数的颜色*/ 		COLR_SET(x1,y1,z1);\
/*设置参数*/ 		printf(__VA_ARGS__);\
/*设置结束*/	COLR_SET(0,0,0);\
}

/* 不同颜色的打印 */
#define PRINTF_YELLOW(fmt, ...)     DEVICE_LOG(BOLD, YELLOW, BLACK_BACKGROUND,fmt,##__VA_ARGS__)
#define PRINTF_RED(fmt, ...)        DEVICE_LOG(BOLD, RED,    BLACK_BACKGROUND,fmt,##__VA_ARGS__)
#define PRINTF_BLACK(fmt, ...)      DEVICE_LOG(BOLD, BLACK,  BLACK_BACKGROUND,fmt,##__VA_ARGS__)
#define PRINTF_GREEN(fmt, ...)      DEVICE_LOG(BOLD, GREEN,  BLACK_BACKGROUND,fmt,##__VA_ARGS__)
#define PRINTF_BROWN(fmt, ...)      DEVICE_LOG(NONE, BROWN,  BLACK_BACKGROUND,fmt,##__VA_ARGS__)
#define PRINTF_BLUE(fmt, ...)       DEVICE_LOG(BOLD, BLUE,   BLACK_BACKGROUND,fmt,##__VA_ARGS__)
#define PRINTF_PURPLE(fmt, ...)     DEVICE_LOG(BOLD, PURPLE, BLACK_BACKGROUND,fmt,##__VA_ARGS__)
#define PRINTF_CYAN(fmt, ...)       DEVICE_LOG(BOLD, CYAN,   BLACK_BACKGROUND,fmt,##__VA_ARGS__)
#define PRINTF_GRAY(fmt, ...)       DEVICE_LOG(NONE, GRAY,   BLACK_BACKGROUND,fmt,##__VA_ARGS__)
#define PRINTF_WHITE(fmt, ...)      DEVICE_LOG(BOLD, WHITE,  BLACK_BACKGROUND,fmt,##__VA_ARGS__)

/* 普通打印 */
#define PRINTF(fmt, ...)    PRINTF_WHITE(fmt, ##__VA_ARGS__)
/* 通知 */
#define INFO(fmt, ...)      PRINTF_BLUE("INFO:"fmt, ##__VA_ARGS__)
/* 警告 */
#define WARNING(fmt, ...)   PRINTF_YELLOW("WARNING:[%s %s line%d]"fmt, __FILE__,  __FUNCTION__, __LINE__, ##__VA_ARGS__)
/* 错误 */
#define ERROR(fmt, ...)     PRINTF_RED("ERROR:[%s %s line%d]"fmt, __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)
/* 打印日期 */
#define PRINTF_Date()       PRINTF_WHITE("Firmware compile time:%s %s\n", __DATE__, __TIME__)

#endif

#endif