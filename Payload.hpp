/* HOW DO WE ADD THE OUTPUTS? DO WE ADD THEM IN THIS CLASS? */

/***************************************************************************************************
*  File:        Payload.hpp                                                                        *
*  Authors:     Pau Luque Lozano (PLL)                                                             *
*  Creation:    2018-oct-17                                                                        *
*  Description: This class emulates payload models.                                                 *
*                                                                                                  *
*  This file is part of a project developed by Nano-Satellite and Payload Laboratory (NanoSat Lab) *
*  at Technical University of Catalonia - UPC BarcelonaTech.                                       *
* ------------------------------------------------------------------------------------------------ *
*  Changelog:                                                                                      *
*  v#   Date            Author  Description                                                        *
*  0.1  2018-oct-17     PLL     Creation                                                           *
***************************************************************************************************/

#ifndef __PAYLOAD_HPP__
#define __PAYLOAD_HPP__

#include "dss.hpp"
#include "Model.hpp"
#include "PayloadSpec.hpp"
#include "DataScientific.hpp"

/***********************************************************************************************//**
 *  This class is used to model the actions of a payload in a satellite                            *
 **************************************************************************************************/
class Payload : public Model
{

public:

  /**********************************************************************************************//**
  * Basic constructor that initializes the member attributes.
  * @param     conf               A configuration set for the created Model instance.
  *            spec_ptr           A pointer containing the specifications of the payload
  **************************************************************************************************/
  Payload(ModelConfig conf, std::shared_ptr<PayloadSpec> spec_ptr);

  /**********************************************************************************************//**
  * Auto-generated destructor.
  **************************************************************************************************/
  ~Payload(void) = default;

  /**********************************************************************************************//**
  * Auto-generated copy constructor.
  **************************************************************************************************/
  Payload(const PayloadSpec&) = default;

  /**********************************************************************************************//**
  * Auto-generated assign operator.
  **************************************************************************************************/
  Payload& operator=(const Payload&) = default;

  /**********************************************************************************************//**
  * Auto-generated move constructor.
  **************************************************************************************************/
  Payload(Payloadc&&) = default;

  /**********************************************************************************************//**
  * Auto-generated move-assign operator.
  **************************************************************************************************/
  Payload& operator=(Payload&&) =default;

  /**********************************************************************************************//**
  * Getters for the attributes.
  **************************************************************************************************/
  std::shared_ptr<PayloadSpec> getSpecPtr(void);
  float getPowerW(void);
  float getDataRateBpm(void);

  /**********************************************************************************************//**
  * Setters for the attributes.
  **************************************************************************************************/
  void setSpecPtr(std::shared_ptr<PayloadSpec> spec_ptr);
  void setPowerW(float power_W);
  void setDataRateBpm(float data_rate_bpm);

  /**********************************************************************************************//**
  * Functions used to compute the values of outputs
  **************************************************************************************************/
  DataScientific generateOutputData(); /* use Model::getTimeDelta and getDataRateBpm */
  /* HOW DO WE GET OUR ID AND THE ID OF THE DESTINATION????? */

  /**********************************************************************************************//**
  * JSON string converter function                          (PENDIENTE)
  **************************************************************************************************/
  void serialize(Serializer&, SerializedClass<Serializer,SerializedType>);
  /*The function we need is something like this?*/

private:

  std::shared_ptr<PayloadSpec> m_spec_ptr; /* Pointer to the specifications of the payload */
  float m_power_W;                         /* Power consumption of the payload in watts    */
  float m_data_rate_bpm;                   /* Data rate of the payload in bytes per minute */

};

#endif /* __PAYLOAD_HPP__ */
