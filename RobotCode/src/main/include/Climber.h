#pragma once

#include "Constants.h"
#include <ctre/Phoenix.h>
#include <frc/Solenoid.h>



class Climber{
    public:
        enum State{ //feel free to change the names if they suck
            IDLE,

           //only for climb to first bar
            VERTICAL_ARM_EXTEND,
            VERTICAL_ARM_RETRACT,

            //can be used for all subsequent bars
            DIAGONAL_ARM_EXTEND,
            DIAGONAL_ARM_RAISE, //hooks onto bar
            DIAGONAL_ARM_RETRACT //involves retracting & returning to vertical            
        };

        Climber();
        void Periodic(double time, bool passIdle, bool drivenForward, bool passDiagonalArmRaise, bool doSecondClimb); //executes state actions

        //returns next state of climber
        State Idle(bool passIdle);
        
        State VerticalArmExtend(bool drivenForward);
        State VerticalArmRetract();

        State TestDiagonalArmExtend();
        State DiagonalArmExtend();
        State DiagonalArmRaise(bool passDiagonalArmRaise);
        State DiagonalArmRetract(bool doSecondClimb);

        void SetState(State newState); //can set state manually

        void Calibrate();

        bool hooked();

        bool waited(double time, double startTime);

    private:
        State state;

        double currTime = 0;

        WPI_TalonFX gearboxMaster{ClimbConstants::gearboxPort1};
        WPI_TalonFX gearboxSlave{ClimbConstants::gearboxPort2};

        //Higher pneumatic
        frc::Solenoid climbFullExtend{frc::PneumaticsModuleType::REVPH, 
            ClimbConstants::solenoid1Port};
        //Lower pneumatic
        frc::Solenoid climbMedExtend{frc::PneumaticsModuleType::REVPH,
            ClimbConstants::solenoid2Port};

        frc::Solenoid brake{frc::PneumaticsModuleType::REVPH, ClimbConstants::BrakeSolenoidPort};

};