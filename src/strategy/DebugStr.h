#include "Strategy.h"
#include "../Defines.h"

#ifndef DEBUGSTR_H
#define DEBUGSTR_H
class DebugStr : public Strategy
{
private:
    
public:
    DebugStr(Hardware *hw) : Strategy(hw){
        hardware->getMovement()->setGyroEnabled(true);
        hardware->getMovement()->setDirection(0);
        hardware->getMovement()->setSpeed(0);
        hardware->getMovement()->setRotationByGyro();
    }

    void doStrategy() override {
        Log::info("Gyro", String(getMovement()->getRobotAngle()));
        Log::info("Line", String(getLightSensor()->isLine()));
        Log::info("Cam", String(getGoalDist()));
        Log::info("Ball", String(getBallSensor()->getAngle()));



        /*getMovement()->setSpeed(BASE_SPEED);


        if(getBallSensor()->isCanSee()){
            if(getBallSensor()->isCatched())
                getMovement()->setDirection(getCamSensor()->getYAngle() * 1.325);
            else
                getMovement()->setDirection(getBallSensor()->getAngle() * getAngleMultipiller());
        } else {
            getMovement()->setDirection(getCamSensor()->getBAngle());
        
            if(getGoalDist() <= 25)
                getMovement()->setSpeed(0);
        }*/
    }

    int getType() override {
        return 10;
    }

    ~DebugStr(){

    }

    float getGoalDist(){
        return abs(getCamSensor()->getCamDist() * cos(radians(getCamSensor()->getCamAngle())));
    }

    float getAngleMultipiller(){
      if(getBallSensor()->getDistanse() > 60 || abs(getBallSensor()->getAngle()) < 25)
        return 1.75;
      return 1.1;
    }
};

#endif
