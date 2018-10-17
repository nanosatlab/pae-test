/***************************************************************************************************
*  File:        DataScientific.hpp                                                                 *
*  Authors:     Pau Luque Lozano (PLL)                                                             *
*  Creation:    2018-oct-17                                                                        *
*  Description: Extension of Data to manage Data generated at payloads.                            *
*                                                                                                  *
*  This file is part of a project developed by Nano-Satellite and Payload Laboratory (NanoSat Lab) *
*  at Technical University of Catalonia - UPC BarcelonaTech.                                       *
* ------------------------------------------------------------------------------------------------ *
*  Changelog:                                                                                      *
*  v#   Date            Author  Description                                                        *
*  0.1  2018-oct-17     PLL     Creation                                                           *
***************************************************************************************************/

#ifndef __DATA_SCIENTIFIC_HPP__
#define __DATA_SCIENTIFIC_HPP__

#include "dss.hpp"
#include "Data.hpp"
#include "PayloadSpec.hpp"

/***********************************************************************************************//**
 *  This class extends Data. Its purpose is to be used to encapsulate payload data.                *
 **************************************************************************************************/
class DataScientific : public Data
{

public:

  /**********************************************************************************************//**
  * Basic constructor that initializes the member attributes.
  * @param     origin_id                 The ID of the generator of this data
  *            destiny_id                The ID of the final receiver of this data
  *            bytes                     Amount of data in bytes represented by this object
  *            specs_ptr                 Shared pointer to the payload specifications
  **************************************************************************************************/
  DataScientific(std::string origin_id, std::string destiny_id, int bytes, std::shared_ptr<PayloadSpec> specs_ptr);

  /**********************************************************************************************//**
  * Auto-generated destructor.
  **************************************************************************************************/
  ~DataScientific(void) = default;

  /**********************************************************************************************//**
  * Auto-generated copy constructor.
  **************************************************************************************************/
  DataScientific(const DataScientific&) = default;

  /**********************************************************************************************//**
  * Auto-generated assign operator.
  **************************************************************************************************/
  DataScientific& operator=(const DataScientific&) = default;

  /**********************************************************************************************//**
  * Auto-generated move constructor.
  **************************************************************************************************/
  DataScientific(DataScientific&&) = default;

  /**********************************************************************************************//**
  * Auto-generated move-assign operator.
  **************************************************************************************************/
  DataScientific& operator=(DataScientific&&) =default;

  /**********************************************************************************************//**
  * Getters for the attributes.
  **************************************************************************************************/
  std::shared_ptr<PayloadSpec> getPayloadSpec(void);

  /**********************************************************************************************//**
  * Setters for the attributes.
  **************************************************************************************************/
  void setPayloadSpec(std::shared_ptr<PayloadSpec> specs_ptr);

  /**********************************************************************************************//**
  * JSON string converter function                          (PENDIENTE)
  **************************************************************************************************/
  void serialize(Serializer&, SerializedClass<Serializer,SerializedType>);
  /*The function we need is something like this?*/


private:
  std::shared_ptr<PayloadSpec> m_payload_specs; /*Has specifications of the providing payload.*/

};

#endif /* __DATA_SCIENTIFIC_HPP__ */
