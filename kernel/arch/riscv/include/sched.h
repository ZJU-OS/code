#ifndef __SCHED_H__
#define __SCHED_H__

#include <stdint.h>
#include <private_kdefs.h>

/* 任务状态 */
#define TASK_RUNNING 0
#define TASK_DEAD 4

/* 优先级 */
#define MIN_PRIORITY 10
#define MAX_PRIORITY 1

/* 时间片 */
#define TIMER_INTERVAL (TIMECLOCK / 100) // 100ms
#define TIME_SLICE (TIMER_INTERVAL * 5) // 500ms

/**
 * @brief 调度实体结构体
 */
struct sched_entity {
	uint64_t runtime; /**< 时间片 */
	uint64_t sum_exec_runtime; /**< 已执行时间 */
};

/**
 * @brief 主动调度
 */
void schedule(void);

#endif