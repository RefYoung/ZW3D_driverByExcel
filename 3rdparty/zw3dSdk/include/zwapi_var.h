/**
@file zwapi_var.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Variable API
Note -- The common functions of variable are defined in this header file.
*/
/**
@defgroup zwapi_var Variable Common API
@ingroup CommonModel
@brief
@details THE MODULE FOR THE ZW3D Variable API
Note -- The common functions of variable are defined in this header file.
*/

#pragma once
#ifndef ZW_API_VAR_H /* this ifndef surrounds entire header */
#define ZW_API_VAR_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Equations Edit Data */
    //====================================================================================================================
    /**
    @brief equation set option
    @ingroup zwapi_var
    */
    typedef enum evxEqnSetOpt
    {
        VX_EQN_MANUAL_SET_EQN         = 0, /**<@brief  manually set every equations */
        VX_EQN_AUTO_OVERWRITE_ALL_EQN = 1, /**<@brief  auto overwrite all repeated equations */
        VX_EQN_AUTO_NEW_ALL_EQN       = 2, /**<@brief  auto create copy for all repeated equations */
        VX_EQN_AUTO_CANCEL_ALL_EQN    = -1 /**<@brief  auto cancel the operation for all repeated equations */
    } evxEqnSetOpt;

    //====================================================================================================================
    /** @name Equation Query */
    //====================================================================================================================
    /**
    @ingroup zwapi_var

    Output all the equations of equation set.
    In specified equation set,if no equation, *count=0 and *idList=NULL.

    The memory referenced by "idList" is allocated by this function.
    The calling procedure is responsible to free it (cvxMemFree((void**)idList)).

    @param [in] idSet equation set id
    @param [out] count number of idList
    @param [out]  idList list of equation id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartInqEqnSetMembers(int idSet, int *count, int **idList);

    /**
    @ingroup zwapi_var

    Get equation set containing specified equation.  
    If cannot find, *idSet = -1.

    @param [in] idEqn equation id
    @param [out] idSet equation set id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartInqEqnAssociatedSet(int idEqn, int *idSet);

    /**
    @ingroup zwapi_var

    Looking for an equation object(VEQ) whose variable name matches the input name.  
    Output expression of the equation object with variable "exp".

    @param [in] name object name
    @param [in,out] exp output of expression
    @param [in] size size of expression

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_OBJ_DATE_GET_ERROR
    */
    extern evxErrors cvxEqGetExpByName(char *name, char *exp, int size);

    /**
    @ingroup zwapi_var

    Looking for an equation object(VEQ) whose variable id matches the input id.  
    Output description of the equation object with variable "desc".

    @param [in] idEqn object id
    @param [in,out] desc output of description
    @param [in] size size of description

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxEqGetDescById(int idEqn, char *desc, int size);

    /**
    @ingroup zwapi_var

    Update the specified equation's description without regard for how  
    the equation was generated.

    @param [in] idEqn equation id
    @param [in] desc description that defines the equation

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxEqSetDescById(int idEqn, char *desc);


    //====================================================================================================================
    /** @name Equation Edit */
    //====================================================================================================================
    /**
    @ingroup zwapi_var

    Substitute variable values into a string for all occurrences of  
    variable references.  The syntax for each variable reference is [$VAR]  
    where VAR is the name of a variable in the active target.  References  
    for which the variable cannot be found are left in the string.

    This function is not limited to parts, but can be used when the active  
    target is any type of root object in which variables may exist.

    The maximum number of bytes allowed in the "Str" character array is  
    "nBytes" including a terminating '\0' byte.  When this function  
    returns, "Truncated" is set to 0 if the string with variable  
    substitutions fits within this maximum size.  If a variable  
    substitution would cause the string to exceed this size, the string is  
    truncated and "Truncated" is set to 1.  The caller may pass NULL in  
    place of the "Truncated" argument if this result is not of interest.

    It is not an error if "Str" is NULL or empty, nor is it an error if the  
    string has no [$VAR] references, but it is an error if a variable  
    specified in such a reference cannot be found in the active target.

    @see cvxPartVarSubstituteResize() for a similar function that never  
    truncates, but instead resizes a string.

    @param [in,out] Str null-terminated string, may be NULL
    @param [in] nBytes maximum size of Str array in bytes
    @param [out] Truncated 1 if string was truncated, 0 if not; may be NULL

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -
    */
    extern evxErrors cvxPartVarSubstitute(char *Str, int nBytes, int *Truncated);

    /**
    @ingroup zwapi_var

    Substitute variable values into a string for all occurrences of  
    variable references.  The syntax for each variable reference is [$VAR]  
    where VAR is the name of a variable in the active target.  References  
    for which the variable cannot be found are left in the string.  

    This function is not limited to parts, but can be used when the active  
    target is any type of root object in which variables may exist.

    The string will be reallocated (if necessary) to insert the variable
    values.

    It is not an error if "Str" is NULL or empty, nor is it an error if the  
    string has no [$VAR] references, but it is an error if a variable  
    specified in such a reference cannot be found in the active target.

    The string is reallocated if substituting the variable values produces  
    a longer string.  The string is not reallocated if it becomes shorter  
    or stays the same length.

    If the block of memory used for the string is larger than needed for  
    the string (i.e. larger than the number of bytes in the string plus  
    1), this function might make the block smaller.  That is because  
    reallocation requests only the amount of memory needed for the string,  
    and might not consider unused space in the block.  There is no need to  
    allocate more memory than the string needs before calling this
    function.

    @see cvxPartVarSubstitute() for a similar function that truncates a
    string instead of resizing it.

    @param [in,out] Str null-terminated string, may be NULL

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -
    */
    extern evxErrors cvxPartVarSubstituteResize(char **Str);

    /**
    @ingroup zwapi_var

    Use this function to add equations by importing excel.

    @param [in] fullpath  fullpath of excel to import
    @param [in] option option of equation

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    -        ZW_API_FORM_CREATE_FAIL
    -        ZW_API_FORM_SHOW_FAIL
    */
    extern evxErrors cvxEqLoadFile(const vxLongPath fullpath, evxEqnSetOpt option);

    /**
    @ingroup zwapi_var

    Regenerate all/specified equations.

    @param [in] idEqn -1 to regen all equation; equation id to regen specified equation

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxEqRegen(int idEqn);

    /**
    @ingroup zwapi_var

    Delete all equation if idEqn = -1.
    Delete equation set or equation by specified idEqn.

    @param [in] idEqn equation id or equation set id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxPartEqnDelete(int idEqn);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_VAR_H */
