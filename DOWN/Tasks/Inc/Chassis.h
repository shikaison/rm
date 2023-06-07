//
// Created by 14685 on 2022/7/16.
//

#ifndef HNU_RM_DOWN_CHASSIS_H
#define HNU_RM_DOWN_CHASSIS_H



#include "stm32f4xx_hal.h"
#include "controller.h"
#include "motor.h"

/* ���̿������� (ms) */
#define CHASSIS_PERIOD 2



/**
  * @brief     ���̿���ģʽö��
  */
typedef enum
{
    CHASSIS_STOP,          //����ֹͣ
    CHASSIS_RELAX,         //����ʧ��
    CHASSIS_OPEN_LOOP,     //���̿���
    CHASSIS_FOLLOW_GIMBAL, //���̸�����̨
    CHASSIS_SPIN,          //��������ģʽ
    CHASSIS_FLY            //���̷���ģʽ
} ChassisModeType;

/**
  * @brief     ���̿������ݽṹ��
  */
typedef struct
{
    /* ���̿���ģʽ��� */
    ChassisModeType  ctrl_mode;       //��ǰ���̿���ģʽ
    ChassisModeType  last_mode;  //�ϴε��̿���ģʽ

    /* �����ƶ��ٶ�������� */
    float           vx;         //����ǰ���ٶ�
    float           vy;         //���������ٶ�
    float           vw;         //������ת�ٶ�


    uint8_t         last_sw2;
} ChassisTypeDef;

/**
  * @brief     ���̿��Ʋ�����ʼ��
  */
void Chassis_Init_param(void);

/**
  * @brief     ����״̬������ȡ���̿���ģʽ
  */
void Chassis_Get_mode(void);

/**
 * @brief    ����ʧ��ģʽ���ƺ���
 */
void Chassis_Relax_control(void);

/**
 * @brief    ���̾�ֹģʽ���ƺ���
 */
void Chassis_Stop_control(void);

/**
 * @brief    ���̷���ģʽ���ƺ���
 */
void Chassis_Fly_control(void);

/**
 * @brief    ���̲�������̨ģʽ���ƺ���
 */
void Chassis_Open_control(void);

/**
 * @brief    ���̸�����̨ģʽ���ƺ���
 */
void Chassis_Follow_control(void);

/**
 * @brief    ����ʧ��ģʽ���ƺ���
 */
void Chassis_Spin_control(void);

/**
  * @brief     ���̿�����Ϣ��ȡ
  */
void Chassis_Get_control_information(void);

/**
 * @brief     �����˶����ٶȷֽ⣬�Լ����ת�ٵıջ�����
 */
void Chassis_Custom_control(void);

/**
  * @brief     �����ٶȷֽ⣬�������ÿ�������ٶ�
  * @param     vx: ����ǰ���ٶ�
  * @param     vy: ���������ٶ�
  * @param     vw: ������ת�ٶ�
  * @param     speed[]: 4 �������ٶ�����
  */
void Chassis_Calc_moto_speed(float vx, float vy, float vw, int16_t speed[]);

/**
  * @brief     �����ٶȱջ�������㺯��
  */
void Chassis_Calculate_close_loop(void);

/**
 * @brief          ���͵��̵���������ݵ����
 * @param current  ���͵ĵ�������
 */
void Chassis_Send_current(int16_t current[]);

/**
  * @brief     �������ݴ�����
  */
void Chassis_Top_handle(void);




extern MotorTypeDef chassis_motor[4];
extern ChassisTypeDef chassis;
//���̸�����̨PID�ṹ��
extern PIDTypeDef rotate_follow;
extern float yaw_relative_angle;


#endif //HNU_RM_DOWN_CHASSIS_H