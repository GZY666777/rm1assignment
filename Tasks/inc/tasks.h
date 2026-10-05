#ifndef TASKS_H
#define TASKS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* 全局计时变量：定时器每 1ms 给它 +1，Ozone 里要能看到它 */
extern volatile uint32_t tick;

/* 你自己的初始化函数（第 1 题：点灯） */
void Tasks_Init(void);

#ifdef __cplusplus
}
#endif

#endif /* TASKS_H */
