/**
@file zwapi_cmd_datum.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Datum/Axis/CSYS Commands API
*/
/**
@defgroup zwapi_cmd_datum Datum Commands
@ingroup PartandAssemblyCommands
@brief
@details THE MODULE FOR THE ZW3D Datum/Axis/CSYS Commands API
*/

#pragma once
#ifndef ZW_API_DATUM_H /* this ifndef surrounds entire header */
#define ZW_API_DATUM_H

#include "zwapi_cmd_datum_data.h"

/*
*********************************************************************
*! Command of Datum
*********************************************************************
*/
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Datum Axis */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_datum

    This function add a new datum axis to the active part according to the *Axis.
    If "idAxis" is not NULL, the id of the new datum axis is output.

    @note
    Interface cvxMemZero() can initialize variables of this function.

    @param [in] Axis Axis data
    @param [out] idAxis id of new datum Axis (NULL to ignore)

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
    extern evxErrors cvxPartAxisNew(svxAxisData *Axis, int *idAxis);

    //====================================================================================================================
    /** @name Datum Plane */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_datum

    Adds a datum plane to the active part, aligned with the
    specified local coordinate frame.  If "idDatum" is not
    NULL, the id of the new datum is output.

    If Frame is invalid, it will use the identity matrix.

    @param [in] Frame transformation matrix
    @param [out] idDatum id of new datum

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
    extern evxErrors cvxPartDatum(svxMatrix *Frame, int *idDatum);

    /**
    @ingroup zwapi_cmd_datum

    Adds a datum plane to the active part, aligned with the specified local coordinate frame.  
    If "idDatum" is not NULL, the id of the new datum is output.In addition to need input position   
    code its function is same as cvxPartDatum(), 1 as the default in cvxPartDatum().

    @param [in] Frame transformation matrix
    @param [in] iCode position code ,1 add label to entity, 0 don't
    @param [out] idDatum id of new datum

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
    extern evxErrors cvxPartDatum2(svxMatrix *Frame, int iCode, int *idDatum);

    /**
    @ingroup zwapi_cmd_datum

    This function add a new datum plane to the active part according to the Frame.   
    It is different to cvxPartDatum(). If "idDatum" is not NULL, the id of the new datum is output.

    @param [in] Frame transformation matrix
    @param [out] idDatum id of new datum

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
    extern evxErrors cvxPartNewDatum(svxMatrix *Frame, int *idDatum);

    /**
    @ingroup zwapi_cmd_datum

    Adds a datum plane to the active part that is normal to the specified
    curve "idCrv", with its origin located at the point on "idCrv" that
    lies closest to the input "Origin" point.

    If the reference point "Xaxis" is specified (i.e. not NULL), the new
    datum plane is oriented so that its X axis lies in the plane that
    contains "Xaxis" and the new datum's Z axis.  That is, the point
    "Xaxis" specifies the XZ plane of the new datum.

    @param [in] idCrv id of curve entity
    @param [in] Origin point at or near plane origin on curve
    @param [in] Xaxis point lying on plane of new datum's X axis (or NULL)
    @param [out] idPln id of new datum plane (or NULL)

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
    extern evxErrors cvxPartPlnCrv(int idCrv, svxPoint *Origin, svxPoint *Xaxis, int *idPln);

    /**
    @ingroup zwapi_cmd_datum

    Adds a datum plane to the active part that is normal to the specified
    curve "idCrv", with its origin located at the point on "idCrv" that
    lies closest to the input "Origin" point.

    If the reference point "Xaxis" is specified (i.e. not NULL), the new
    datum plane is oriented so that its X axis lies in the plane that
    contains "Xaxis" and the new datum's Z axis.  That is, the point
    "Xaxis" specifies the XZ plane of the new datum.

    If "Flip" is non-zero, flip the datum plane 180 degrees about the specified axis.

    Besides the "Flip" argument, the difference between this function and cvxPartPlnCrv()
    is that "Origin" and "Xaxis" can be defined more flexibly using the parameters available
    in "svxData".  The calling procedure is responsible for defining "svxData" correctly.

    @note
    Make sure you zero the entire "svxData" structure before initializing specific
    parameters {svxData Origin; \ref cvxMemZero(&Origin,sizeof(Origin);}.

    @param [in] idCrv id of curve entity
    @param [in] Origin point at or near plane origin on curve
    @param [in] Xaxis point lying on plane of new datum's X axis (or NULL)
    @param [in] Flip 0-ignore this input;  
                     1-flip plane 180 degrees about X axis;  
                     2-flip plane about Y axis;  
                     3-flip about Z axis
    @param [out] idPln id of new datum plane (or NULL)

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
    extern evxErrors cvxPartPlnCrv2(int idCrv, svxData *Origin, svxData *Xaxis, int Flip, int *idPln);

    /**
    @ingroup zwapi_cmd_datum

    Adds a datum plane to the active part that is tangent to the surface
    of the specified face "idFace", with its origin located at the point
    on "idFace" that lies closest to the input "Origin" point.

    @param [in] idFace id of face entity
    @param [in] Origin point at or near plane origin on face
    @param [out] idPln id of new datum plane (or NULL)

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
    extern evxErrors cvxPartPlnSrf(int idFace, svxPoint *Origin, int *idPln);

    /**
    @ingroup zwapi_cmd_datum

    Adds a datum plane to the active part that is tangent to the surface
    of the specified face "idFace", with its origin located at the point
    on "idFace" that lies closest to the input "Origin" point and its
    Z axis pointing along the face's outward normal at "Origin".

    If "XZ" is a non-NULL pointer to a 3D point, the point is used to
    control the plane's orientation by rotating the plane about its
    Z axis (face's outward normal) until its XZ plane intersects the
    point.

    If "Flip" is non-zero, the plane is flipped 180 degrees about
    its X axis (Flip=1), Y axis (Flip=2) or Z axis (Flip=3).

    @param [in] idFace id of face entity
    @param [in] Origin point at or near plane origin on face
    @param [in] XZ point on XZ plane (NULL to ignore)
    @param [in] Flip flip plane about an axis (see DESCRIPTION)
    @param [out] idPln id of new datum plane (NULL to ignore)

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
    extern evxErrors cvxPartPlnSrf2(int idFace, svxPoint *Origin, svxPoint *XZ, int Flip, int *idPln);

    /**
    @ingroup zwapi_cmd_datum

    This function add a new datum Plane to the active part according to the svxPlaneData.
    If "idPlane" is not NULL, the id of the new datum Plane is output.

    @param [in] Plane Plane data
    @param [out] idPlane id of new Plane (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartPlaneNew(svxPlaneData *Plane, int *idPlane);

    /**
    @ingroup zwapi_cmd_datum

    Initialize the parameters of the cvxPartPlaneAdd().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] method New Plane Methods
    @param [out] data New template command Plane input data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartPlaneAddInit(evxNewPlaneMethods method, svxNewPlaneData *data);

    /**
    @ingroup zwapi_cmd_datum

    This function add a new datum Plane to the active part according to the svxNewPlaneData.
    If "idPlane" is not NULL, the id of the new datum Plane is output.

    This function is similar to cvxPartPlaneNew().
    This interface uses a different command template than cvxPartPlaneNew().

    @note
    Interface cvxPartPlaneAddInit() can initialize variables of this function.

    @param [in] plane new plane data
    @param [out] idPlane id of new plane (pass in NULL to ignore)

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
    extern evxErrors cvxPartPlaneAdd(const svxNewPlaneData *plane, int *idPlane);

    //====================================================================================================================
    /** @name Datum CSYS */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_datum

    Initialize the parameters of the cvxPartCSYSNew().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] method csys method
    @param [out] data csys data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartCSYSNewInit(evxCSYSMethods method, svxCSYSData *data);

    /**
    @ingroup zwapi_cmd_datum

    This function add a new datum CSYS to the active part according to the Frame.
    If "idCSYS" is not NULL, the id of the new datum CSYS is output.

    @note
    Interface cvxPartCSYSNewInit() can initialize variables of this function.

    @param [in] CSYS CSYS data
    @param [out] idCSYS id of new CSYS (NULL to ignore)

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
    extern evxErrors cvxPartCSYSNew(svxCSYSData *CSYS, int *idCSYS);

    //====================================================================================================================
    /** @name LCS */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_datum

    Active the specified datum/CSYS as the LCS.

    @param [in] id id of datum/CSYS

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_eXEC_ERROR
    */
    extern evxErrors cvxPartActiveAsLCS(int id);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_DATUM_H */
