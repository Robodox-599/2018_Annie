/*
 * Intake.h
 *
 *  Created on: Apr 26, 2018
 *      Author: Admin
 */

#ifndef SRC_INTAKE_H_
#define SRC_INTAKE_H_

#include "Macros.h"
#include "ctre/Phoenix.h"
#include "WPILib.h"

class Intake
{
public:
	Intake();
	~Intake();

	void intakeBall(bool intake, float intakeSpeed);
	void resetIntake(bool reset);

private:
	TalonSRX* intakeRoller;
	DoubleSolenoid* intakeLeft;
	DoubleSolenoid* intakeRight;

};


#endif /* SRC_INTAKE_H_ */
