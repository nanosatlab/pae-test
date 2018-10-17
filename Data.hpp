/***************************************************************************************************
*  File:        Data.hpp                                                                           *
*  Authors:     Oriol Fusté (OF)                                                                   *
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

class Data
{

public:
    /**********************************************************************************************//**
    * Basic constructor that initializes the member attributes.
    * @param     sat_origin                The ID of the satellite where this data was generated
    *            bytes                     Amount of data in bytes represented by this object
    **************************************************************************************************/
    Data(std::string sat_origin, double bytes);
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
    Data& operator=(cpnst Data&) = default;

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
    std::string getSatOrigin(void);
    double getBytes(void);

    /**********************************************************************************************//**
    * JSON string converter function                          (PENDIENTE)
    **************************************************************************************************/
    
protected:
    std::string m_sat_origin;                    /* The ID of the satellite who generated this object */
    double m_bytes;                            /* The amount of data bytes represented by this object */

};

#endif
