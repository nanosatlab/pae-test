/***************************************************************************************************
*  File:        Data.hpp                                                                           *
*  Authors:     Oriol Fusté (OF)                                                                   *
*               Pau Luque Lozano (PLL)                                                             *
*  Creation:    2018-oct-17                                                                        *
*  Description: Standarized classs for data handling                                               *
*                                                                                                  *
*  This file is part of a project developed by Nano-Satellite and Payload Laboratory (NanoSat Lab) *
*  Lab) at Technical University of Catalonia - UPC BarcelonaTech.                                  *
* ------------------------------------------------------------------------------------------------ *
*  Changelog:                                                                                      *
*  v#   Date            Author  Description                                                        *
*  0.1  2018-oct-17     OF      Creation                                                           *
***************************************************************************************************/
#ifndef __DATA_HPP__
#define __DATA_HPP__

#include "dss.hpp"

/***********************************************************************************************//**
 *  The final type of a Data object (once it is extended).
 **************************************************************************************************/
enum class DataType
{
  SCIENTIFIC,           /**< The data has scientific purposes                                     */
  LOGISTIC              /**< The data has logistic purposes                                       */
};

/***********************************************************************************************//**
 *  A class to encapsulate the data chunks that the different models move by the emulated system   *
 **************************************************************************************************/
class Data
{

public:

    /**********************************************************************************************//**
    * Basic constructor that initializes the member attributes.
    * @param     origin_id                 The ID of the generator of this data
    *            destiny_id                The ID of the final receiver of this data
    *            bytes                     Amount of data in bytes represented by this object
    **************************************************************************************************/
    Data(std::string origin_id, std::string destiny_id, float bytes);

    /**********************************************************************************************//**
    * Auto-generated destructor.
    **************************************************************************************************/
    ~Data(void) = default;

    /**********************************************************************************************//**
    * Auto-generated copy constructor.
    **************************************************************************************************/
    Data(const Data&) = default;

    /**********************************************************************************************//**
    * Auto-generated assign operator.
    **************************************************************************************************/
    Data& operator=(const Data&) = default;

    /**********************************************************************************************//**
    * Auto-generated move constructor.
    **************************************************************************************************/
    Data(Data&&) = default;

    /**********************************************************************************************//**
    * Auto-generated move-assign operator.
    **************************************************************************************************/
    Data& operator=(Data&&) =default;

    /**********************************************************************************************//**
    * Getters for the attributes.
    **************************************************************************************************/
    std::string getOriginId(void);
    std::string getDestinyId(void);
    DataType getDataType(void);
    float getBytes(void);

    /**********************************************************************************************//**
    * Setters for the attributes.
    **************************************************************************************************/
    void setOriginId(std::string id_origin);
    void setDestinyId(std::string id_destiny);
    void setDataType(DataType type_of_data);
    void setBytes(float) number_of_bytes);

    /**********************************************************************************************//**
    * JSON string converter function                          (PENDIENTE)
    **************************************************************************************************/
    void serialize(Serializer&, SerializedClass<Serializer,SerializedType>);
    /*The function we need is something like this?*/

protected:
    std::string m_origin_id;                  /* The ID of the entity who generated this object       */
    std::string m_destiny_id;                 /* The ID of the entity that will receive this object   */
    DataType m_data_type;                     /* The final type of this object once is extended       */
    float m_bytes;                              /* The amount of data bytes represented by this object  */


};

#endif /* __DATA_HPP__ */
