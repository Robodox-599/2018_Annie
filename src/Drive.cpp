/*
 * Drive.cpp
 *
 *  Created on: Apr 25, 2018
 *      Author: Admin
 */
#include "Drive.h"

Drive::Drive()
{
	frontLeftMotor = new TalonSRX(Drive_Front_Left_Motor_Channel);
	rearLeftMotor = new TalonSRX(Drive_Rear_Left_Motor_Channel);
	frontRightMotor = new TalonSRX(Drive_Front_Right_Motor_Channel);
	rearRightMotor = new TalonSRX(Drive_Rear_Right_Motor_Channel);

	fwdSpeed = 0;
	turnSpeed = 0;
}

Drive::~Drive()
{
	delete frontLeftMotor;
	delete rearLeftMotor;
	delete frontRightMotor;
	delete rearRightMotor;

	frontLeftMotor = nullptr;
	rearLeftMotor = nullptr;
	frontRightMotor = nullptr;
	rearRightMotor = nullptr;
}

void Drive::drive(float xAxis, float yAxis)
{
	setFwdSpeed(yAxis);
	setTurnSpeed(xAxis);

	//driveStraight(yAxis, xAxis);

	updateRightMotors(fwdSpeed + turnSpeed);
	updateLeftMotors(fwdSpeed - turnSpeed);
}

void Drive::updateLeftMotors(float speed)
{
	frontLeftMotor->Set(ControlMode::PercentOutput, -speed);
	rearLeftMotor->Set(ControlMode::PercentOutput, -speed);
}

//group right motors
void Drive::updateRightMotors(float speed)
{
	frontRightMotor->Set(ControlMode::PercentOutput, speed);
	rearRightMotor->Set(ControlMode::PercentOutput, speed);
}

void Drive::setFwdSpeed(float fwd)
{
	if(fwd > 0.2)
	{
		fwdSpeed = (fwd-0.2)*1/.8;
	}
	else if(fwd < -0.2)
	{
		fwdSpeed = (fwd+0.2)*1/.8;
	}
	else
	{
		fwdSpeed = 0;
	}
}

void Drive::setTurnSpeed(float turn)
{
	if(turn > 0.2)
	{
		turnSpeed = (turn-0.2)*1/.8;
	}
	else if(turn < -0.2)
	{
		turnSpeed = (turn+0.2)*1/.8;
	}
	else
	{
		turnSpeed = 0;
	}
}
