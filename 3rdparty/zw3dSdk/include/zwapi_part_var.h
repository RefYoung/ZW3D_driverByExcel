/**
@file zwapi_part_var.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Part Variables API
*/
/**
@defgroup zwapi_part_var Part Variable API
@ingroup PartObjectsModel
@brief
@details THE MODULE FOR THE ZW3D Part Variables API
*/

#pragma once
#ifndef ZW_API_PART_VAR_H /* this ifndef surrounds entire header */
#define ZW_API_PART_VAR_H

#include "zwapi_part_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Part Variable Query */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_var

    Outputs a list of variables that belong to the specified part.  
    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] File part file name (File[0]=0 or NULL for active file)
    @param [in] Part part name (Part[0]=0 or NULL for active part)
    @param [out] Count number of variables
    @param [out] Variables list of variables

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxPartInqVars(const vxLongPath File, const vxRootName Part, int *Count, svxVariable **Variables);

    /**
    @ingroup zwapi_part_var

    Output all equations and equation sets.
    If no equation,*cntList=0 and *idList=NULL.
    If no equation set,*cntSets=0 and *idSets=NULL.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [out] cntList number of idList
    @param [out]  idList list of equation id
    @param [out] cntSets number of idSets
    @param [out]  idSets list of equation set id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartInqEqnAllId(int *cntList, int **idList, int *cntSets, int **idSets);

    //====================================================================================================================
    /** @name Part Variable */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_var

    Adds the specified variable to the active part.

    Expression format of string type :"\"str\"";  
    Expression format of point type :"Point(1,2,3)";  
    Expression format of vector type :"Vector(1,2,3)";

    If the type of variable is set to 0,then the sub_type must be set,else ignore.  
    If the sub_type of variable is set to 1 or 2,then the unit_type must be set,else ignore.

    evxUnitType for length unit and evxAngUnitType for angle unit.

    @param [in] Variable definition of a variable

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
    extern evxErrors cvxPartVarAdd(svxVariable *Variable);

    /**
    @ingroup zwapi_part_var

    Searches the active part for the variable named "Variable->Name".

    The value of the specified variable is output via  
    "Variable->Value" in database units (mm, deg).

    If "Variable->Name" is a string variable, the associated  
    text is output via "Variable->Expression".  Strings longer  
    than 256 bytes are truncated.

    @note
    "Variable->Expression" is not used to output the  
    expression that defines a variable.  It is used to output  
    text associated with a "string" variable.

    @param [in,out] Variable variable data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartVarGet(svxVariable *Variable);

    /**
    @ingroup zwapi_part_var

    Searches the active part for the equation id.

    @note
    "Variable->Expression" is not used to output the   
    expression that defines a variable.  It is used to output  
    text associated with a "string" variable.

    @param [in] idEqn equation id
    @param [out] Variable variable data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartVarGetById(int idEqn, svxVariable *Variable);

    /**
    @ingroup zwapi_part_var

    Updates the part variables (e.g. dimensions, parameters)  
    specified by "Variables" and regenerates the active part  
    with the modified values.

    You can disable the object regeneration normally performed by  
    this function by inputing "Working = -1".

    @see the description of "cvxRootVarSet()" for the names  
    used to identify various part parameters and attributes.

    Custom variables :
    Expression format of string type :"\"str\"";       \n
    Expression format of point type :"Point(1,2,3)";   \n
    Expression format of vector type :"Vector(1,2,3)";

    @param [in] Count number of variables
    @param [in] Variables list of variables
    @param [in] Working 1 to display "Working..." message, else 0

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxPartVarSet(int Count, svxVariable *Variables, int Working);

    /**
    @ingroup zwapi_part_var

    Moves some existing expressions to the specified equation set.

    Unlike the cvxPartVarAddToEqnSet() interface, this interface changes   
    the position of original expression.

    The cvxPartEqnSet() interface can create a equation set and this interface 
    can not.

    @param [in] idEqnSet   equation set id
    @param [in] cnt        number of variables
    @param [in] idListEqn  list of variables
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    */
    extern evxErrors cvxPartEqnMoveToEqnSet(int idEqnSet, int cnt, const int *idListEqn);

    /**
    @ingroup zwapi_part_var

    Adds some non-existent expressions and copys them to the specified equation set.

    Unlike the cvxPartEqnMoveToEqnSet() interface, this interface does not 
    change the position of original expression.

    @param [in] idEqnSet       equation set id
    @param [in] cnt            number of variables
    @param [in] vars           list of variables

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_STRING
    -        ZW_API_OBJ_TYPE_ERROR
    */
    extern evxErrors cvxPartVarAddToEqnSet(int idEqnSet, int cnt, const svxVariable *vars);

    /**
    @ingroup zwapi_part_var

    Create an equation set in active part, and add variables
    into this equation set.

    @param [in] Count number of variables
    @param [in] Variables list of variables

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartEqnSet(int Count, svxVariable *Variables);

    /**
    @ingroup zwapi_part_var

    DESCRIPTION:
    Create an equation set in active part, and add variables
    into this equation set.

    This interface can create an empty equation set or specify the
    name of the equation set.

    @param [in] setName equation set name(can be NULL)
    @param [in] count   number of variables
    @param [in] vars    list of variables

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
    -        ZW_API_INVALID_STRING
    */
    extern evxErrors cvxPartEqnSetWithName(const vxLongName setName, int count, svxVariable *vars);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_PART_VAR_H */
