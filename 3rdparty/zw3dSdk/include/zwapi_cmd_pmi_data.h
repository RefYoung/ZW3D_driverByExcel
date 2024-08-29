/**
@file zwapi_cmd_pmi_data.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the PMI
Command functions.
*/
/**
@defgroup zwapi_cmd_pmi_data PMI Commands Data
@ingroup PartandAssemblyCommands
@brief
@details THE MODULE FOR THE ZW3D Data Types and Structures of the PMI
Command functions.
*/

#pragma once
#ifndef ZW_API_PMI_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_PMI_DATA_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Annotation Data */
    //====================================================================================================================
    /**
    @brief Roughness PMI text define
    @ingroup zwapi_cmd_pmi_data
    */
    typedef struct svxRoughTexts
    {
        char a1[65]; /**<@brief  max roughness average (or =NULL) */
        char a2[65]; /**<@brief  min roughness average (or =NULL) */
        char b[65];  /**<@brief  processing method/treatment (or =NULL) */
        char c[65];  /**<@brief  sampling length/roughness cutout (or =NULL) */
        char e[65];  /**<@brief  machining allowance (or =NULL) */
        char f1[65]; /**<@brief  Rz, roughness value (or =NULL) */
        char f2[65]; /**<@brief  other roughness value/spacing (or =NULL) */
        char f3[65]; /**<@brief  third row optional string (or =NULL) */
    } svxRoughTexts;

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_PMI_DATA_H */
