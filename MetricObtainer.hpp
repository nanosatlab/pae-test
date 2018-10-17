/***************************************************************************************************
*  File:        MetricObtainer.hpp                                                                 *
*  Authors:     Oriol Fusté (OF)                                                                   *
*  Creation:    2018-oct-14                                                                        *
*  Description: Metrics obtantion from database extracted data                                     *
*                                                                                                  *
*  This file is part of a project developed by Nano-Satellite and Payload Laboratory (NanoSat Lab) *
*  Lab) at Technical University of Catalonia - UPC BarcelonaTech.                                  *
* ------------------------------------------------------------------------------------------------ *
*  Changelog:                                                                                      *
*  v#   Date            Author  Description                                                        *
*  0.1 2018-oct-14      OF      Creation                                                           *
***************************************************************************************************/

#ifndef __METRIC_OBTAINER_HPP__
#define __METRIC_OBTAINER_HPP__

#include "dss.hpp"

/**********************************************************************************************//**
* Structure used for managing Critical States metrics.
**************************************************************************************************/
struct CSTriggered
{
    std::string sat_id;
    double start_time;
    double end_time;
    double duration;
}


class MetricObtainer
{
public:
    /**********************************************************************************************//**
    * Constructs a MetricObtainer with certain user metrics preferences(booleans).
    * (Explained in the attributes section)
    **************************************************************************************************/
    MetricObtainer(boolean numOfCS, boolean durationOfCS, boolean totalData, boolean totalDataSat,
                boolean totalDataGS, boolean averageLag);

    /**********************************************************************************************//**
    * Auto-generated destructor.
    **************************************************************************************************/
    ~MetricObtainer(void) = default;

    /**********************************************************************************************//**
    * Auto-generated copy constructor.
    **************************************************************************************************/
    MetricObtainer(const MetricObtainer&) = default;

    /**********************************************************************************************//**
    * Auto-generated assign operator.
    **************************************************************************************************/
    MetricObtainer& operator=(cpnst MetricObtainer&) = default;

    /**********************************************************************************************//**
    * Auto-generated move constructor.
    **************************************************************************************************/
    MetricObtainer(MetricObtainer&&) = default;

    /**********************************************************************************************//**
    * Auto-generated move-assign operator.
    **************************************************************************************************/
    MetricObtainer& operator=(MetricObtainer&&) =default;

    /**********************************************************************************************//**
    * Computes the total amount of data received by the ground stations in bytes.
    * @return   Total Amount
    * @param
    **************************************************************************************************/
    double dataObtainedTotal('?') const;

    /**********************************************************************************************//**
    * Calculates the average time delay between the time at wich the payload generates a data chunck
    * and the time it is received at a Ground Station.
    * @return   Average lag in seconds
    * @param
    **************************************************************************************************/
    double averageLag('?') const;

    /**********************************************************************************************//**
    * Generates a map containing all the satellite id's of the system, and the amount of data generated
    * and received at a Ground Station for each satellite.
    * @return   std::map<std::string, double> Where the Key 'string' is the satellite's unique id and
                                            the mapped value 'double' is the amount of data obtained
                                            from this satellite in bytes.
    * @param
    **************************************************************************************************/
    std::map<std::string, double> dataObtainedSats('?') const;

    /**********************************************************************************************//**
    * Generates a map containing all the Ground Station id's of the system, and the amount of data
    * received at each Ground Station.
    * @return   std::map<std::string, double> Where the Key 'string' is the Ground Station's unique id
                                            and the mapped value 'double' is the amount of data
                                            received at this Ground Station in bytes.
    * @param
    **************************************************************************************************/
    std::map<std::string, double> dataObtainedGS('?') const;

    /**********************************************************************************************//**
    * Calculates the number of energy Critical States triggered during the simulation.
    * @return  double                                              Total amount of CSs triggered.
    * @param   std::map<std::string, std::map<double,
    *          boolean>> cs_states                                 Map containg all the satellite
    *                                                              IDs(string) as keys, and as values
    *                                                              the maps with the values of the
    *                                                              Critical State variable(boolean)as
    *                                                              values, indexed with the time the
    *                                                              measure (double) was made, as key.
    **************************************************************************************************/
    double numOfCS(std::map<std::string, std::map<double, bool>> cs_states) const;

    /**********************************************************************************************//**
    * Auxiliar function used to create a list of CSTriggered structures detailing all the ocurred
    * Critical States during the simulation.
    * @return  std::list<CSTriggered>                              List containg a struct for each
    *                                                              Critical State triggered.
    * @param   std::map<std::string, std::map<double,
    *          boolean>> cs_states                                 Map containg all the satellite
    *                                                              IDs(string) as keys, and as values
    *                                                              the maps with the values of the
    *                                                              Critical State variable(boolean)as
    *                                                              values, indexed with the time the
    *                                                              measure (double) was made, as key.
    **************************************************************************************************/
    std::list<CSTriggered> listCSs(std::map<std::string, std::map<double, bool>> cs_states) const;

    /**********************************************************************************************//**
    * Getters for the private members.
    **************************************************************************************************/
    bool getNumOfCS(void) const { return m_num_of_cs; }
    bool getDurationOfCS(void) const { return m_duration_of_cs; }
    bool getTotalData(void) const { return m_total_data; }
    bool getTotalDataSat(void) const { return m_total_data_sat; }
    bool getTotalDataGS(void) const { return m_total_data_gs; }
    bool getAverageLag(void) const { return m_average_lag; }

private:
    /**********************************************************************************************//**
    * Boolean variables that will store if a certain metric is required by the user and needs to be
    * computed. Values are true for the ones required and false for the rest.
    **************************************************************************************************/
    bool m_num_of_cs;               /**< Total number of Critical States ocurred                     */
    bool m_duration_of_cs;          /**< Minimum, maximum and average duration of the Critical States*/
    bool m_total_data;              /**< Amount of data in bytes recived by all the Ground Stations  */
    bool m_total_data_sat;          /**< Amount of data in bytes received by each satellite          */
    bool m_total_data_gs;           /**< Amount of data in bytes received at each Ground Station     */
    bool m_average_lag;             /**< Averge delay between data generation and it's reception     */

};

#endif
