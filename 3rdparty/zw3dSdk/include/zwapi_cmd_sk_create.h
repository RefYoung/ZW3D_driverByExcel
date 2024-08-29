/**
@file zwapi_cmd_sk_create.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Sketch Creation Commands API
*/
/**
@defgroup zwapi_cmd_sk_create Create Sketch Commands
@ingroup PartandAssemblyCommands
@brief
@details THE MODULE FOR THE ZW3D Sketch Creation Commands API
*/

#pragma once
#ifndef ZW_API_SKETCH_CREATE_H /* this ifndef surrounds entire header */
#define ZW_API_SKETCH_CREATE_H

#include "zwapi_cmd_sk_create_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Sketch Creation */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_sk_create

    Inserts a copy of the specified sketch in the active part
    on the specified insertion plane.  It is assumed that "File"
    resides in one of the default search directories.  If "idSketch"
    is not NULL, the id of the new sketch is output.

    @param [in] File name of ZW3D file that contains the sketch as root object
    @param [in] Name name of sketch root object
    @param [in] Plane sketch insertion plane
    @param [out] idSketch id of new sketch (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartSkIns(const vxLongPath File, const vxRootName Name, svxMatrix *Plane, int *idSketch);

    /**
    @ingroup zwapi_cmd_sk_create

    Inserts a copy of the specified sketch in the active part
    on the specified datum plane. The sketch location will be
    associatively linked to the datum plane -- if the datum
    plane is moved (via history redefine/regen), the sketch
    will move with it.

    It is assumed  that "File" resides in one of the default
    search directories. If "idSketch" is not NULL, the id of
    the new sketch is output.

    @param [in] File name of ZW3D file that contains the sketch as root object
    @param [in] Name name of sketch root object
    @param [in] idPlane datum plane id
    @param [in] iAsso option of associate copy
    @param [out] idSketch id of new sketch (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartSkIns2(const vxLongPath File, const vxRootName Name, int idPlane, int iAsso, int *idSketch);

    /**
    @ingroup zwapi_cmd_sk_create

    Adds a new sketch to the active part, aligned with the
    specified insertion plane.  The sketch is activated for
    editing.

    Exit the sketch edit mode (back to editing the
    parent part) using cvxRootExit() or cvxSkActivate(0,0).
    If "idSketch" is not NULL, the id of the new sketch is
    output.

    @param [in] Plane sketch insertion plane
    @param [out] idSketch id of new sketch

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartSkNew(svxMatrix *Plane, int *idSketch);

    /**
    @ingroup zwapi_cmd_sk_create

    Adds a new sketch to the active part, aligned with the
    specified insertion plane.  The sketch is activated for
    editing.

    Exit the sketch edit mode (back to editing the
    parent part) using cvxRootExit() or cvxSkActivate(0,0).
    If "idSketch" is not NULL, the id of the new sketch is
    output.

    @param [in] SkData sketch input data
    @param [out] idSketch id of new sketch (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartSkPlane(svxSketchData *SkData, int *idSketch);

    /**
    @ingroup zwapi_cmd_sk_create

    Initialize the svxHatchPtnData structure.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data cosmetic sketch hatch pattern definition data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxHatchPtnDataInit(svxHatchPtnData *data);

    /**
    @ingroup zwapi_cmd_sk_create

    Adds a new cosmetic sketch to the active part, aligned with the
    specified insertion plane.  The sketch is activated for
    editing.

    Exit the sketch edit mode (back to editing the
    parent part) using cvxRootExit() or cvxSkActivate(0,0).
    If "idSketch" is not NULL, the id of the new sketch is
    output.

    @note
    Structure svxSketchData can be initialized through interface cvxMemZero().  
    Structure svxHatchPtnData can be initialized through interface cvxHatchPtnDataInit().

    @param [in] SkData sketch input data
    @param [in] isAddHatPtn 1 if add hatch pattern ,else 0
    @param [in] PatData hatch pattern input data (NULL to use default)
    @param [out] idSketch id of new sketch (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartCosSkPlane(const svxSketchData *SkData, int isAddHatPtn, const svxHatchPtnData *PatData, int *idSketch);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_SKETCH_CREATE_H */
