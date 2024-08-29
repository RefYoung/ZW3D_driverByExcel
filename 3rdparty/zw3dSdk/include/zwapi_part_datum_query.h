/**
@file zwapi_part_datum_query.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Datum Query API
*/
/**
@defgroup zwapi_part_datum_query Datum Query
@ingroup PartObjectsModel
@brief
@details THE MODULE FOR THE ZW3D Datum Query API
*/

#pragma once
#ifndef ZW_API_DATUM_QUERY_H /* this ifndef surrounds entire header */
#define ZW_API_DATUM_QUERY_H

#include "zwapi_cmd_datum_data.h"
#include "zwapi_part_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    /**********************************************************************
    *! zwapi_part_history.h - include the Axis, Datum and CSYS in the history tree
    *  extern evxErrors cvxPartInqFtrList(int* Count, int** Features);
    **********************************************************************/
    //====================================================================================================================
    /** @name Axis Query */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_datum_query

    Outputs a list of axis that belong to the current part.  
    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [out] Count number of axis
    @param [out]  Axis list of index of axises

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxPartInqAxis(int *Count, int **Axis);

    /**
    @ingroup zwapi_part_datum_query

    Get the direction associated with the specified object (idAxis).

    @param [in] idAxis index of axis
    @param [out] pPnt start point of axis
    @param [out] pDir direction of axis

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxAxisInqDir(int idAxis, svxPoint *pPnt, svxPoint *pDir);

    /**
    @ingroup zwapi_part_datum_query

    Get the Axis data associated with the specified idAxis.

    @note
    This interface can only retrieve datum data created by interface cvxPartAxisNew().

    @param [in] idAxis Axis id
    @param [out] Axis Axis data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxAxisGetData(int idAxis, svxAxisData *Axis);

    /**
    @ingroup zwapi_part_datum_query

    Get length of the specified datum axis.

    @param [in] idAxis id of datum axis
    @param [out] Length length of datum axis

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxAxisLengthGet(int idAxis, double *Length);

    /**
    @ingroup zwapi_part_datum_query

    Set length of the specified datum axis.

    @param [in] idAxis id of datum axis
    @param [in] Length length of datum axis

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_ERROR
    */
    extern evxErrors cvxAxisLengthSet(int idAxis, double Length);

    //====================================================================================================================
    /** @name Datum Query */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_datum_query

    Get the Plane data associated with the specified idPlane, contained
    frame and Entity path.

    @note
    This interface can only retrieve datum data created by interface cvxPartPlaneNew().

    @param [in] idPlane Plane id
    @param [out] Plane Plane data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPlaneGetData(int idPlane, svxPlaneData *Plane);


    //====================================================================================================================
    /** @name CSYS Query */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_datum_query

    Outputs a list of CSYS that belong to the current part.  
    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [out] Count number of CSYS
    @param [out]  Csys list of index of CSYS

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxPartInqCsys(int *Count, int **Csys);

    /**
    @ingroup zwapi_part_datum_query

    Get the Default CSYS/Datum ID which Uid is three 10.

    @param [out] CSYS Default CSYS/Datum id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartInqDefaultCSYS(int *CSYS);

    /**
    @ingroup zwapi_part_datum_query

    Get the id of the specified datum axis of the specified datum CSYS.

    @param [in] idCSYS id of datum CSYS
    @param [in] AxisType axis type to query
    @param [out] idAxis id of datum axis

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartInqCSYSAxis(int idCSYS, evxAxisType AxisType, int *idAxis);

    /**
    @ingroup zwapi_part_datum_query

    Get the id of the specified datum plane of the specified datum CSYS.

    @param [in] idCSYS id of datum CSYS
    @param [in] PlnType plane type to query
    @param [out] idPlane id of datum plane

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartInqCSYSPlane(int idCSYS, evxPlaneType PlnType, int *idPlane);

    /**
    @ingroup zwapi_part_datum_query

    Get the CSYS data associated with the specified idCSYS, contained
    frame and Entity path.

    @note
    This interface can only retrieve datum data created by interface cvxPartCSYSNew().

    @param [in] idCSYS CSYS id
    @param [out] CSYS CSYS data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxCSYSGetData(int idCSYS, svxCSYSData *CSYS);

    /**
    @ingroup zwapi_part_datum_query

    Gets the local CSYS matrix.

    @param [out] mat the local CSYS matrix.

    @warning
    -        ZW_API_INVALID_OUTPUT
    */
    extern void cvxPartInqLCSMat(svxMatrix *mat);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_DATUM_QUERY_H */
