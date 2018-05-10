/*
 * Catapult.cpp
 *
 *  Created on: Apr 25, 2018
 *      Author: Admin
 */
#include "Catapult.h"

Catapult::Catapult()
{
	winchMotor = new TalonSRX(Winch_Motor);
	release = new DoubleSolenoid(Release_Piston_1, Release_Piston_2);

	catapultLimit = new DigitalInput(0);

	timer = new Timer();

	release->Set(DoubleSolenoid::kForward);
}

Catapult::~Catapult()
{
	delete winchMotor;
	delete release;

	winchMotor = nullptr;
	release = nullptr;
}

void Catapult::reset(bool resetButton, float winchSpeed)
{
	if(resetButton)
	{
		release->Set(DoubleSolenoid::kForward);
		winchMotor->Set(ControlMode::PercentOutput, winchSpeed);
	}
	if(catapultLimit)
	{
		winchMotor->Set(ControlMode::PercentOutput, 0);
	}
}

void Catapult::launch(bool trigger)
{
	if(trigger)
	{
		release->Set(DoubleSolenoid::kReverse);
	}
}

void Catapult::launchAndReset(bool trigger, float winchSpeed)
{
	if(trigger)
	{
		release->Set(DoubleSolenoid::kReverse);
		timer->Start();
	}
	if(timer->Get() > 0.2)
	{
		release->Set(DoubleSolenoid::kForward);
		winchMotor->Set(ControlMode::PercentOutput, winchSpeed);
		timer->Stop();
		timer->Reset();
	}
	if(catapultLimit)
	{
		winchMotor->Set(ControlMode::PercentOutput, 0);
	}
}
