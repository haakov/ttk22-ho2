#include <iostream>
#include <fstream>

#include <IMC/Spec/PlanSpecification.hpp>
#include <IMC/Spec/PlanManeuver.hpp>
#include <IMC/Spec/SetEntityParameters.hpp>
#include <IMC/Spec/Loiter.hpp>
#include <IMC/Base/InlineMessage.hpp>


int main() {
    IMC::Loiter *loiter = new IMC::Loiter();
    loiter->timeout = 1000;
    loiter->lat = 0.7188016469344056;
    loiter->lon = -0.15194250254286037;
    loiter->z = 3;
    loiter->z_units = 1;
    loiter->duration = 300;
    loiter->speed = 1000;
    loiter->speed_units = 1;
    loiter->type = 1;
    loiter->radius = 20;
    loiter->length = 1;
    loiter->bearing = 0;
    loiter->direction = 1;

    IMC::EntityParameter *ep = new IMC::EntityParameter();
    ep->name = "Active";
    ep->value ="false";
    //ep->toJSON(std::cout);
    
    IMC::SetEntityParameters *sep = new IMC::SetEntityParameters();
    sep->params.push_back(ep);
    
    sep->name = "LBL";
    IMC::PlanManeuver *maneuver = new IMC::PlanManeuver();
    maneuver->start_actions.push_back(sep);
    maneuver->maneuver_id = "1";
    maneuver->data.set(loiter);
    
    IMC::PlanSpecification *yes = new IMC::PlanSpecification();
    yes->plan_id = "cmd-lauv-xplore-1";
    yes->setTimeStamp();
    yes->setSource(16652);
    yes->setSourceEntity(44);
    yes->setDestination(30);
    yes->setDestinationEntity(255);
    yes->start_man_id = "1";
    yes->maneuvers.push_back(maneuver);


    std::ofstream outputfile;
    outputfile.open("plan.json");
    yes->toJSON(outputfile);
    outputfile.close();
    return 0;
}