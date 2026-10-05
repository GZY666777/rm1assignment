#include "tasks.h"
#include "main.h"        // 提供 HAL、TIM/IWDG/GPIO 的类型和宏

extern "C" {             // C++ 写 HAL 相关函数必须加，否则 HAL 找不到

/* main.c 里定义了 htim2、hiwdg，但 main.h 没有声明它们，
   所以这里自己声明一下才能使用 */
extern TIM_HandleTypeDef htim2;
extern IWDG_HandleTypeDef hiwdg;

/* 全局计时变量（必须叫 tick、必须是 volatile，Ozone 才看得到） */
volatile uint32_t tick = 0;

/* 定时器更新中断回调：TIM2 每 1ms 溢出一次，HAL 会自动调用这个函数 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM2)        // 确认是 TIM2 触发的中断
    {
        tick = tick + 1;               // 每 1ms 加 1
        HAL_IWDG_Refresh(&hiwdg);      // 喂狗 —— 第 3 题把这一行删掉
    }
}

/* 第 1 题：把 PC13 输出成低电平 -> 板载灯亮 */
void Tasks_Init(void)
{
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
}

}
