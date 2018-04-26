/*
 * Catapult.h
 *
 *  Created on: Apr 25, 2018
 *      Author: Admin
 */

#ifndef SRC_CATAPULT_H_
#define SRC_CATAPULT_H_

#include "Macros.h"
#include "ctre/Phoenix.h"
#include "WPILib.h"
class Catapult
{
public:
	Catapult();
	~Catapult();
	void reset(bool resetButton, float winchSpeed);
	void launch(bool trigger);

private:
	TalonSRX* winchMotor;
	DoubleSolenoid* release;
	DigitalInput* catapultLimit;
};




#endif /* SRC_CATAPULT_H_ */
