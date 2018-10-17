/***************************************************************************************************
*  File:        PayloadSpec.hpp                                                                    *
*  Authors:     Pau Luque Lozano (PLL)                                                             *
*  Creation:    2018-oct-17                                                                        *
*  Description: This class encapsulates the specifications of payloads.                            *
*                                                                                                  *
*  This file is part of a project developed by Nano-Satellite and Payload Laboratory (NanoSat Lab) *
*  at Technical University of Catalonia - UPC BarcelonaTech.                                       *
* ------------------------------------------------------------------------------------------------ *
*  Changelog:                                                                                      *
*  v#   Date            Author  Description                                                        *
*  0.1  2018-oct-17     PLL     Creation                                                           *
***************************************************************************************************/

#ifndef __PAYLOAD_SPEC_HPP__
#define __PAYLOAD_SPEC_HPP__

#include "dss.hpp"

/***********************************************************************************************//**
 *  The purpose of this class is to encapsulate the technical parameters of a Payload. The idea is *
 *  to have only one instance for each payload model, and use a std::shared_ptr to use it.         *
 **************************************************************************************************/
class PayloadSpec
{

public:

  /**********************************************************************************************//**
  * Basic constructor that initializes the member attributes.
  * @param     measurement        The name ID for the measurement type
  *            resolution         The resolution of the measurement (units?) --> normalized per measurement?
  *            accuracy           The accuracy   of the measurement (units?) --> normalized per measurement?
  *            power_W            The power consumed by the payload (in watts)
  *            data_rate_bpm      The speed at which the payload generates data (in bytes per minute)
  **************************************************************************************************/
  PayloadSpec(std::string measurement, float resolution, float accuracy, float power_W, float data_rate_bpm);

  /**********************************************************************************************//**
  * Auto-generated destructor.
  **************************************************************************************************/
  ~PayloadSpec(void) = default;

  /**********************************************************************************************//**
  * Disable copy constructor.
  **************************************************************************************************/
  PayloadSpec(const PayloadSpec&) = 0;

  /**********************************************************************************************//**
  * Disable assign operator.
  **************************************************************************************************/
  PayloadSpec& operator=(const PayloadSpec&) = 0;

  /**********************************************************************************************//**
  * Disable move constructor.
  **************************************************************************************************/
  PayloadSpec(PayloadSpec&&) = 0;

  /**********************************************************************************************//**
  * Disable move-assign operator.
  **************************************************************************************************/
  PayloadSpec& operator=(PayloadSpec&&) = 0;

  /**********************************************************************************************//**
  * Getters for the attributes.
  **************************************************************************************************/
  std::string getMeasurement(void);
  float getResolution(void);
  float getAccuracy(void);
  float getPowerW(void);
  float getDataRateBpm(void);

  /**********************************************************************************************//**
  * Setters for the attributes.
  **************************************************************************************************/
  void setMeasurement(std::string measurement);
  void setResolution(float resolution);
  void setAccuracy(float accuracy);
  void setPowerW(float power_W);
  void setDataRateBpm(float data_rate_bpm);

  /**********************************************************************************************//**
  * JSON string converter function                          (PENDIENTE)
  **************************************************************************************************/
  void serialize(Serializer&, SerializedClass<Serializer,SerializedType>);
  /*The function we need is something like this?*/

private:

  std::string m_measurement;  /* This indicates what measures the payload     */
  float m_resolution;         /* Resolution of the payload sensors            */
  float m_accuracy;           /* Accuracy of the payload sensors              */
  float m_power_W;            /* Power consumption of the payload in watts    */
  float m_data_rate_bpm;      /* Data rate of the payload in bytes per minute */

};

#endif /* __PAYLOAD_SPEC_HPP__ */
