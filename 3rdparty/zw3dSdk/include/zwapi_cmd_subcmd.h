/**
@file zwapi_cmd_subcmd.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Second Menu Commands API
*/
/**
@defgroup zwapi_cmd_subcmd Sub Commands
@ingroup PartandAssemblyCommands
@brief
@details THE MODULE FOR THE ZW3D Second Menu Commands API
*/

#pragma once
#ifndef ZW_API_SUB_COMMAND_H /* this ifndef surrounds entire header */
#define ZW_API_SUB_COMMAND_H

#include "zwapi_cmd_subcmd_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Point */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_subcmd

    Initialize the parameters of the svxPntByOffset.
    It will set data->pntOnEnt.critTyp to VX_START_POINT if useCirPnt = 1.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data point by offset data
    @param [in] useCirPnt 1- to use critical point, else 0

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartPntByOffsetInit(svxPntByOffset *data, int useCirPnt);

    /**
    @ingroup zwapi_cmd_subcmd

    Initialize the parameters of the svxPntBy2Lines.
    It will set data->pntOnCrv1.critTyp and data->pntOnCrv2.critTyp to VX_START_POINT
    if useCirPnt = 1.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data point by two lines data
    @param [in] useCirPnt 1- to use critical point, else 0

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartPntBy2LinesInit(svxPntBy2Lines *data, int useCirPnt);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* zwapi_cmd_subcmd_data */
