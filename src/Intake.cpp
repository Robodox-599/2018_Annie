/*
 * Intake.cpp
 *
 *  Created on: Apr 26, 2018
 *      Author: Admin
 */
#include "Intake.h"
#include "ctre/Phoenix.h"
#include "WPILib.h"

Intake::Intake()
{
	intakeRoller = new TalonSRX(Intake_Roller);
	intakeLeft = new DoubleSolenoid(Intake_Left_1, Intake_Left_2);
	intakeRight = new DoubleSolenoid(Intake_Right_1, Intake_Right_2);

	intakeLeft->Set(DoubleSolenoid::kReverse);
	intakeRight->Set(DoubleSolenoid::kReverse);
}

Intake::~Intake()
{
	delete intakeRoller;
	delete intakeLeft;
	delete intakeRight;

	intakeRoller = nullptr;
	intakeLeft = nullptr;
	intakeRight = nullptr;
}

void Intake::intakeBall(bool intake, float intakeSpeed)
{
	if(intake)
	{
		intakeLeft->Set(DoubleSolenoid::kForward);
		intakeRight->Set(DoubleSolenoid::kForward);
		intakeRoller->Set(ControlMode::PercentOutput, intakeSpeed);
	}
}

void Intake::resetIntake(bool reset)
{
	if(reset)
	{
		intakeLeft->Set(DoubleSolenoid::kReverse);
		intakeRight->Set(DoubleSolenoid::kReverse);
		intakeRoller->Set(ControlMode::PercentOutput, 0);
	}
}
