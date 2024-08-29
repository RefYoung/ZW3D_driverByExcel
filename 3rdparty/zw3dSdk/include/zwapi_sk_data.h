/**
@file zwapi_sk_data.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Generic Data Types and Structures of the functions
of Sketch objects.
*/
/**
@defgroup zwapi_sk_data Sketch Data
@ingroup SketchObjectsModel
@brief
@details THE MODULE FOR THE ZW3D Generic Data Types and Structures of the functions
of Sketch objects.
*/

#pragma once
#ifndef ZW_API_SK_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_SK_DATA_H

#include "zwapi_util.h"
#include "zwapi_cmd_sk_cmds_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Overlap Geometries Data */
    //====================================================================================================================
    /**
    @brief Overlap Geometries Data
    @ingroup zwapi_sk_data
    */
    typedef struct svxSkOverlapGeom
    {
        int idEnt1;      /**<@brief  the first overlap entity */
        svxLimit limit1; /**<@brief  parameter interval of the first overlap entity */
        int idEnt2;      /**<@brief  the second overlap entity */
        svxLimit limit2; /**<@brief  parameter interval of the second overlap entity */
    } svxSkOverlapGeom;

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_SK_DATA_H */
