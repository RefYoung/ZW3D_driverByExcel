/**
@file zwapi_cmd_subcmd_data.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Generic Data Types and Structures of
Second Menu Command functions.
*/
/**
@defgroup zwapi_cmd_subcmd_data Sub Commands Data
@ingroup PartandAssemblyCommands
@brief
@details THE MODULE FOR THE ZW3D Generic Data Types and Structures of
Second Menu Command functions.
*/

#pragma once
#ifndef ZW_API_SUB_COMMAND_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_SUB_COMMAND_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Sub-command(Point) Data */
    //====================================================================================================================
    /**
    @brief the data to get the point by Offset command
    @ingroup zwapi_cmd_subcmd_data
    */
    typedef struct svxPntByOffset
    {
        svxPntOnEnt pntOnEnt; /**<@brief  point on entity */
        double xOffset;       /**<@brief  x offset value */
        double yOffset;       /**<@brief  y offset value */
        double zOffset;       /**<@brief  z offset value */
    } svxPntByOffset;

    /**
    @brief the data to get the point by From 2 Lines command
    @ingroup zwapi_cmd_subcmd_data
    */
    typedef struct svxPntBy2Lines
    {
        svxPntOnEnt pntOnCrv1; /**<@brief  point on first edge/line */
        svxPntOnEnt pntOnCrv2; /**<@brief  point on second edge/line */
        double dDst1;          /**<@brief  distance from the first edge/line */
        double dDst2;          /**<@brief  distance from the second edge/line */
    } svxPntBy2Lines;

    /**
    @brief the distance method of the distance field, it can set the value by the specified sub-command
    @ingroup zwapi_cmd_subcmd_data
    */
    typedef enum evxDistanceMethod
    {
        VX_INPU_VALUE     = 0, /**<@brief  the start/end field by the input number*/
        VX_BY_THROUGH_ALL = 1, /**<@brief  the start/end field by the through all method */
        VX_TO_POINT       = 2, /**<@brief  the start/end field by the to point method */
        VX_TO_FACES       = 3, /**<@brief  the start/end field by the to faces method */
        VX_TO_EXTEND_FACE = 4, /**<@brief  the start/end field by the to extend face method(extrude) */
        VX_TO_FACE        = 5, /**<@brief  the start/end field by the to extend face method (normal cut) */
    } evxDistanceMethod;

    /**
    @brief loft boundary constraints
    @ingroup zwapi_cmd_subcmd_data
    */
    typedef struct svxLoftBndCons
    {
        int continuity; /**<@brief  specify the continuity level at end of loft (0 = None, 1 = tangent, 2 = curvature, 3 = flow) */
        int direction;  /**<@brief  specify direction of loft at start and end profiles (0 = perpendicular, 1 = along edges) */
        double weight;  /**<@brief  specify the amount of the loft affected by the enforcement of tangency */
        int idFace;     /**<@brief  id of tangency, it's ignored when a single face on the edges or continuity = 0,
                      0 to use default face */
    } svxLoftBndCons;

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_SUB_COMMAND_DATA_H */
