/**
@file zwapi_cmd_ecadboard_data.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the ECAD Board
command functions.
*/
/**
@defgroup zwapi_cmd_ecadboard_data ECAD Board Commands Data
@ingroup PartandAssemblyCommands
@brief
@details THE MODULE FOR THE ZW3D Data Types and Structures of the ECAD Board
command functions.
*/

#pragma once
#ifndef ZW_DATA_ECAD_BOARD_DATA_H /* this ifndef surrounds entire header */
#define ZW_DATA_ECAD_BOARD_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Engineer Feature Data */
    //====================================================================================================================
    /**
    @brief region setting type
    @ingroup zwapi_cmd_ecadboard_data
    */
    typedef enum evxEcadRgnSetType
    {
        VX_ROUTING_RGN       = 0, /**<@brief  routing region */
        VX_PLACEMENT_RGN     = 1, /**<@brief  placement region */
        VX_VIA_RGN           = 2, /**<@brief  via region */
        VX_OTHER_RGN         = 3, /**<@brief  other region */
        VX_PLACEMENT_GRP_RGN = 4, /**<@brief  placement group region */
    } evxEcadRgnSetType;

    /**
    @brief region owner
    @ingroup zwapi_cmd_ecadboard_data
    */
    typedef enum evxEcadRgnOwner
    {
        VX_MCAD_RGN    = 0, /**<@brief  MCAD region */
        VX_ECAD_RGN    = 1, /**<@brief  ECAD region */
        VX_UNOWNED_RGN = 2, /**<@brief  unowned region */
    } evxEcadRgnOwner;

    /**
    @brief Region set data
    @ingroup zwapi_cmd_ecadboard_data
    */
    typedef struct svxEcadRgnSetData
    {
        evxEcadRgnSetType Type; /**<@brief  the type of the region setting */
        int idCosmeticSk;       /**<@brief  id of the cosmetic sketch */
        int Volume;             /**<@brief  3d volume (0 as default) */
        double Height;          /**<@brief  region height(0.0 as default) */
        int KeepType;           /**<@brief  0-keep in, 1- keep out (0 as default, 1 as default if Type = VX_VIA_RGN) */
        vxLongName RgnType;     /**<@brief  input the region type (Type = VX_OTHER_RGN) */
        evxEcadRgnOwner Owner;  /**<@brief  region owner */
        evxColor Color;         /**<@brief  region color (VX_COLOR_LIGHT_MAGENTA as default) */
    } svxEcadRgnSetData;

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_DATA_ECAD_BOARD_DATA_H */
