/*
 * Drive.h
 *
 *  Created on: Apr 25, 2018
 *      Author: Admin
 */

#ifndef SRC_DRIVE_H_
#define SRC_DRIVE_H_

#include "Macros.h"
#include "ctre/Phoenix.h"
#include "WPILib.h"

class Drive
{
public:
	Drive();
	~Drive();

	void drive(float xAxis, float yAxis);
	void updateLeftMotors(float speed);
	void updateRightMotors(float speed);
	void setFwdSpeed(float fwd);
	void setTurnSpeed(float turn);

private:
	TalonSRX* frontLeftMotor;
	TalonSRX* rearLeftMotor;
	TalonSRX* frontRightMotor;
	TalonSRX* rearRightMotor;

	float fwdSpeed;
	float turnSpeed;
};



#endif /* SRC_DRIVE_H_ */
