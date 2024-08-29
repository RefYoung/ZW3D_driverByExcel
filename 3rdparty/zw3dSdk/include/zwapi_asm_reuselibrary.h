/**
@file zwapi_asm_reuselibrary.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Reuse Library API
*/
/**
@defgroup zwapi_asm_reuselibrary Reuse Library
@ingroup AssemblyObjectsModel
@brief
@details THE MODULE FOR THE ZW3D Reuse Library API
*/

#pragma once
#ifndef ZW_API_REUSE_LIBRARY_H /* this ifndef surrounds entire header */
#define ZW_API_REUSE_LIBRARY_H

#include "zwapi_cmd_assembly_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Reuse Library Insert */
    //====================================================================================================================
    /******************************************************************************/ /**
@ingroup zwapi_asm_reuselibrary

Insert the standard part from reuse library to the current assembly/part as component/shape.

The "ValStr" given some parameter value to generate the instance. The name for the parameters can
be the really name or the description name. The value should be the value in excel or in config table
for the key and normal parameter. For custom value, it can be other value not in the excel or in config
table.

@note
Interface cvxCompInsInit() can initialize component data
of this function.
This function has updated in ZW3D 2024 SP(28.05), and svxCompData is very different from previous version,
you may meet some compatibility issues.
If you have used Comp->Copy or Comp->CopyPart before, you need to change to Comp->InstanceData.CopyPart now.
If you have used Comp->Align and Comp->AlignData before, you need to change to Comp->IdxAlignFaceDatum now.

@param [in] Comp component data
@param [in] InstanceName the instance name, my be null
@param [in] ValStr string for the selecet value, Like this A,20;B,30;C,40
@param [in] fFileType fFileType is the flag to create the part instance as new root(0)
                      or new file(1, 2 if read-only), ignored if fInsShape is 1.
@param [in] fInsShape insert as shape
@param [out] idComp id of new component, or new feature(fInsShape is 1)

@retval succeeds
-        ZW_API_NO_ERROR
@retval fail
-        ZW_API_GENERAL_ERROR
-        ZW_API_INVALID_INPUT
-        ZW_API_INVALID_OUTPUT
-        ZW_API_ROOT_OBJ_ACT_FAIL
-        ZW_API_WRONG_ROOT_ENV
-        ZW_API_OUT_OF_RANGE
-        ZW_API_CMMD_INIT_ERROR
-        ZW_API_INPUT_ERROR
-        ZW_API_ROOT_SINGLE_MULTI_TYPE_ERROR
-        ZW_API_CMMD_EXEC_ERROR
-        ZW_API_OBJ_DATA_SET_ERROR
@retval other
-       2 - get new component fails
*/
    extern int cvxLibPartIns(const svxCompData *Comp, const char *InstanceName,
                             const char *ValStr, int fFileType, int fInsShape, int *idComp);

    /******************************************************************************/ /**
@ingroup zwapi_asm_reuselibrary

Insert the specified part at the specified location as shape.

@note
Interface cvxCompInsInit() can initialize component data
of this function.
This function has updated in ZW3D 2024 SP(28.05), and svxCompData is very different from previous version,
you may meet some compatibility issues.
If you have used Comp->Copy or Comp->CopyPart before, you need to change to Comp->InstanceData.CopyPart now.
If you have used Comp->Align and Comp->AlignData before, you need to change to Comp->IdxAlignFaceDatum now.

@param [in] Comp component data

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
    extern evxErrors cvxInstPartAsShp(const svxCompData *Comp);

    /******************************************************************************/ /**
@ingroup zwapi_asm_reuselibrary

Change component part use the method like part library

@param [in] idComp the index of component
@param [in] File the file name (include the file path)
@param [in] Part the Root name
@param [in] ValStr string for the seleceted value, Like this A,20;B,30;C,40
@param [in] InstanceName the instance name, may be null

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
    extern evxErrors cvxLibPartAdjust(int idComp, const vxLongPath File, const vxRootName Part, const char *ValStr, const char *InstanceName);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_REUSE_LIBRARY_H */
