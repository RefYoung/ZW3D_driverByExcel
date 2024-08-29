/**
@file zwapi_sk_opts.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Popup Menu Commands of Sketch API
*/
/**
@defgroup zwapi_sk_opts Sketch Objects Operation
@ingroup SketchObjectsModel
@brief
@details THE MODULE FOR THE ZW3D Popup Menu Commands of Sketch API
*/

#pragma once
#ifndef ZW_API_SK_OPTS_H /* this ifndef surrounds entire header */
#define ZW_API_SK_OPTS_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Sketch Operations */
    //====================================================================================================================
    /**
    @ingroup zwapi_sk_opts

    Use the function to solve the current sketch automatically, all constraints, equations,
    dimensions and variable links associated with the current sketch are executed.

    */
    extern void cvxSkRegen();


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_SK_OPTS_H */
