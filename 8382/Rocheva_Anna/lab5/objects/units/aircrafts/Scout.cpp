#include "Scout.hpp"

Unit & Scout::operator+=(NeutralObject &object) {
    if (object.getObjName() == HOSPITAL){
        auto *context = new UnitContext(new HospitalStrategyOther);
        context->changeUnitsAttributes(*this);
    }
    else if (object.getObjName() == TRAIN){
        auto *context = new UnitContext(new TrainStrategyOther);
        context->changeUnitsAttributes(*this);
    }
    else if (object.getObjName() == BAR){
        auto *context = new UnitContext(new BarStrategy);
        context->changeUnitsAttributes(*this);
    }
    else {
        auto *context = new UnitContext(new ShopStrategyScoutTank);
        context->changeUnitsAttributes(*this);
    }
    return *this;
}
