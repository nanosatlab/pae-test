/***************************************************************************************************
*  File:        MetricObtainer.cpp                                                                 *
*  Authors:     Oriol Fusté (OF)                                                                   *
*  Creation:    2018-oct-14                                                                        *
*  Description: Metrics obtantion from database extracted data                                     *
*                                                                                                  *
*  This file is part of a project developed by Nano-Satellite and Payload Laboratory (NanoSat Lab) *
*  Lab) at Technical University of Catalonia - UPC BarcelonaTech.                                  *
* ------------------------------------------------------------------------------------------------ *
*  Changelog:                                                                                      *
*  v#   Date            Author  Description                                                        *
*  0.1 2018-oct-15      OF      Creation                                                           *
***************************************************************************************************/

#include "MetricObtainer.h"



MetricObtainer::MetricObtainer(bool numOfCS, bool durationOfCS, bool totalData,
                               bool totalDataSat, bool totalDataGS, bool averageLag)
{
  m_num_of_cs = numOfCS;
  m_duration_of_cs = durationOfCS;
  m_total_data = totalData;
  m_total_data_sat = totalDataSat;
  m_total_data_gs= totalDataGS;
  m_average_lag = averageLag;
}

double MetricObtainer::dataObtainedTotal('?') const
{

}

double MetricObtainer::averageLag('?') const
{

}

std::map<std::string, double> MetricObtainer::dataObtainedSats('?') const
{

}

std::map<std::string, double> MetricObtainer::dataObtainedGS('?') const
{

}

double MetricObtainer::numOfCS(std::map<std::string, std::map<double, bool>> cs_states) const
{
  list_of_cs = listCSs(cs_states);
  return list_of_cs.size();
}

std::list<CSTriggered> MetricObtainer::listCSs(std::map<std::string, std::map<double, bool>> cs_states ) const
{
  std::list<CSTriggered> cs_list;
  for(auto sat_it : cs_states )
  {
    previous_state = false;
    for(auto states_it : sat_it->second)
    {
      if(states_it->second != previous_state)
      {
        if(states_it->second)                                  /**< When a Critical State starts */
        {
          CSTriggered aux_struct;
          aux_struct.start_time = states_it->first;
          aux_struct.sat_id = sat_it->first;
          previous_state = true;
        } else {                                                 /**< When a Critical State ends */
          aux_struct.end_time = states_it->first;
          aux_struct.duration = states_it->first - aux_struct.start_time;
          cs_list.emplace_front(aux_struct);
          previous_state = false;
        }
      }
    }
    if(previous_state)       /**< Ends Critical State in case it lasts untill the simulation end */
    {
      aux_struct.end_time = states_it->first;
      aux_struct.duration = states_it->first - aux_struct.start_time;
      cs_list.emplace_front(aux_struct);
    }
  }
  return cs_list;
}
