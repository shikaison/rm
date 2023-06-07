//
// Created by 14685 on 2022/7/3.
//

#ifndef HNU_RM_UP_SHOOT_H
#define HNU_RM_UP_SHOOT_H

#include "sys.h"
#include "cmsis_os.h"
#include "motor.h"
#include "Gimbal.h"

/*************************�����ٶ�����*******************************/
#define SHOT_FRIC_WHEEL_SPEED    4000
#define SHOT_SUCCESS_FRIC_WHEEL_SPEED  6800  //����ɹ�Ħ���ֻ����
#define SHOT_ABLE_FRIC_WHEEL_SPEED  6000
#define SHOOT_PERIOD 2
/* ���������ı������г� */
#define DEGREE_60_TO_ENCODER  49146
#define DEGREE_45_TO_ENCODER -36864

#define TRIGGER_MOTOR_REDUCTION_RATIO 36
#define BULLETS_PER_ROUND 8

/*************************����Ƶ������*******************************/
#define TRIGGER_MOTOR_SPEED      1500


//ң��������
#define RC_SINGLE_TRIG   ((last_sw1 != RC_MI) && (rc.sw1 == RC_MI))           // ((last_wheel_value != 660) && (rc.wheel == 660))
//ң��������
#define RC_CONTIN_TRIG   ((rc.sw1 == RC_MI) && (HAL_GetTick() - shoot_continue_time >= 1500))   //((rc.wheel == 660) && (HAL_GetTick() - continue_shoot_time >= 1000))

/**
 * @brief ���״̬ö��
 */
enum ShootState
{
    SINGLE_SHOOT,          /*! �������    */
    TRIBLE_SHOOT,          /*! ���������  */
    CONTINUOUS_SHOOT,      /*! �������   */
    DONT_SHOOT,            /*! �����    */
};

/**
 * @brief           ���Ƶ��ָǵıպ�
 */
void Cap_Control_open(void);

/**
 * @brief           �ӵ��ĵ�������������
 */
void Shoot_Custom_control(void);

/**
 * @brief           ����Ħ���ִ���
 */
void FrictionWheel_Turn_on_off(void);

/**
  * @brief          ����������Ƶ���㲦������ٶȣ���ʵ����������������Ƶ�������������ӵ�
  * @param[1]       ��Ƶ����λ����/s
  * @param[2]       ��������ӵ���
  * @param[3]       ����������ʱ��
  * @retval         ������������ٶ� ��λ��RPM
  */
float ShootAndDelay(float speedInNumsPerSec, uint32_t numsOfOneShot, uint32_t delayTimeInMs);


extern uint8_t  shooter_output; //����ϵͳ��SHOOT�Ĺ������
/*extern PIDTypeDef pid_trigger
extern PIDTypeDef pid_trigger_speed
extern PIDTypeDef pid_shoot_left
extern PIDTypeDef pid_shoot_right*/

#endif //HNU_RM_UP_SHOOT_H
