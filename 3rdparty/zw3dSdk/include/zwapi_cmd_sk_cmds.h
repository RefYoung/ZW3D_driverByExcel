/**
@file zwapi_cmd_sk_cmds.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D All Commands of Sketch API
*/
/**
@defgroup zwapi_cmd_sk_cmds Sketch Commands
@ingroup SketchCommands
@brief
@details THE MODULE FOR THE ZW3D All Commands of Sketch API
*/

#pragma once
#ifndef ZW_API_SK_CMD_H /* this ifndef surrounds entire header */
#define ZW_API_SK_CMD_H

#include "zwapi_cmd_sk_cmds_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Drawing */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_sk_cmds

    Adds a 2D line to the active sketch or sheet.   If "idEnt" is not
    NULL, the id of the new line entity is output.

    @param [in] Start start point
    @param [in] End end point
    @param [out] idEnt id of new 2D line entity(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxSkLine2pt(svxPoint2 *Start, svxPoint2 *End, int *idEnt);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Create the polyline with the input points.

    @param [in] cntPnt count of 2D points
    @param [in] pnts list of 2D points
    @param [in] addCns 1-add constraint, else 0

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxSkAddPolyline(int cntPnt, svxPoint2 *pnts, int addCns);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Adds a 2D Axis to the active sketch. If "idAxis" is not
    NULL, the id of the new entity is output.

    @param [in] Axis Axis data
    @param [out] idAxis id of new 2D Axis entity (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxSkAxis(const svxSkAxisData *Axis, int *idAxis);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Adds a 2D circle to the active sketch or sheet.   If "idEnt" is not
    NULL, the id of the new circle entity is output.

    @param [in] P1 first point on circle
    @param [in] P2 second point on circle
    @param [in] P3 third point on circle
    @param [out] idEnt id of new 2D circle entity(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxSkCir3pt(svxPoint2 *P1, svxPoint2 *P2, svxPoint2 *P3, int *idEnt);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Adds a 2D circle to the active sketch or sheet.   If "idEnt" is not
    NULL, the id of the new entity is output.

    @param [in] Center center point (mm)
    @param [in] Radius radius (mm)
    @param [out] idEnt id of new 2D circle entity(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxSkCirRad(svxPoint2 *Center, double Radius, int *idEnt);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Adds a 2D arc to the active sketch or sheet.   If "idEnt" is not
    NULL, the id of the new arc entity is output.

    @param [in] Start start point
    @param [in] End end point
    @param [in] Mid mid (i.e. through) point
    @param [out] idEnt id of new 2D arc entity(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_INPUT_ERROR
    */
    extern evxErrors cvxSkArc3pt(svxPoint2 *Start, svxPoint2 *End, svxPoint2 *Mid, int *idEnt);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Adds a 2D circle to the active sketch or sheet.   If "idEnt" is not
    NULL, the id of the new entity is output.

    @param [in] Center center point (mm)
    @param [in] Radius radius (mm)
    @param [in] Start start angle (deg - CCW from X axis)
    @param [in] End end angle (deg - CCW from X axis)
    @param [out] idEnt id of new 2D circle entity(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxSkArcRad(svxPoint2 *Center, double Radius, double Start, double End, int *idEnt);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Initialize the parameters of the cvxSkEllipse().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data ellipse data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxSkEllipseInit(svxEllipse *data);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Adds a 2D ellipse to the active sketch or sheet. If "idEnt" is not
    NULL, the id of the new entity is output.

    @note
    Interface cvxSkEllipseInit() can initialize variables of this function.

    @param [in] ellipse ellipse data
    @param [out] idEnt id of new 2D ellipse entity (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxSkEllipse(svxEllipse *ellipse, int *idEnt);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Adds a 2D point entity to the active sketch or drawing.

    @param [in] Point point coordinate
    @param [out] idEnt id of new 2D point entity (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_INPUT_ERROR
    */
    extern evxErrors cvxSkPnt(svxPoint2 *Point, int *idEnt);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Creates point entities spaced on and along a curve based on the specified input parameters.

    @param [in] idCrv id of curve entity in active object
    @param [in] Pnt reference point that specifies which end of the curve to start from;   
                    this input is only necessary if "Dist" is defined (i.e. non-zero);   
                    if this argument is NULL, the geometric start point of the curve will
                    be used if needed.
    @param [in] Num the number of points to create along the curve; if "Dist" is zero,
                    then the specified number of points will be created along the curve
                    with equal spacing between them;   
                    if "Dist" is "non-zero", then "Num" points will be created along the curve 
                    with "Dist" as the spacing between each point; in this case, "Pnt" should be 
                    input and an extension option should be defined in case the specified number 
                    of points at the specified distance exceeds the length of the curve;   
                    if "Num" is input as zero, then "Dist" must be specified; in this case, 
                    points are created the specified distance apart, beginning at the end of 
                    the curve closest to "Pnt" and ending at/before the other end of the curve.
    @param [in] Dist the distance (mm) between points (see description of "Num" argument)
    @param [in] Opt extension option is "Dist" is non-zero
    @param [out] Count if this argument is not NULL, output the number of points created
    @param [out] idEnts if "Count" is not NULL, and this argument is not NULL, a list of
                        the database id's of the point entities created by this function
                        is output.   
                        Memory for the list is allocated by this function.  The
                        calling procedure is responsible to free the memory.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxSkPntsOnCrv(int idCrv, svxPoint *Pnt, int Num, double Dist, evxExtendOpt Opt, int *Count, int **idEnts);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Initialize the parameters of the cvxSkReadyText().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] method ready text method
    @param [out] data data of ready sketch text

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxSkReadyTextInit(evxReadyTextMethods method, svxReadyText *data);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Adds a ready sketch text to the active sketch.

    Pass in NULL for "idRdText" if the output is not required.

    @note
    Interface cvxSkReadyTextInit() can initialize variables of this function.

    @param [in] RdText data of ready sketch text
    @param [out] idRdText index of the ready sketch text (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_INVALID_NAME
    */
    extern evxErrors cvxSkReadyText(const svxReadyText *RdText, int *idRdText);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Creates a new text with the given data. The target bin is sheet or sketch.  
    The Type include:   
    1-At point text, one point,   
    2-Aligned text, two points,   
    3-Box text, two points

    @param [in] String string of text
    @param [in] Type type of input points
    @param [in] Pnt[2] position of text
    @param [out] idEnt text id (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxEntTextNew(char *String, int Type, svxPoint2 Pnt[2], int *idEnt);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Initialize the svxSkNgons structure.

    @param [in] type  sketch polygon type
    @param [out] data sketch polygon data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxSkNgonsInit(evxSkNgonsType type, svxSkNgons *data);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Use this function to create a polygon by the input svxSkNgons data.

    @note
    Interface cvxSkNgonsInit() can initialize variables data of this function.

    @param [in] Spl      sketch polygon input data
    @param [out] cnt     count of idEnts(can be NULL)
    @param [out] idEnts  list of new entity id.(can be NULL) 

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxSkNgons(const svxSkNgons *Spl, int *cnt, int **idEnts);

    //====================================================================================================================
    /** @name Curve */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_sk_cmds

    Initialize the parameters of the cvxSkCrvInt().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data 2D interpolated curve data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxSkCrvIntInit(svxCrvIntData *data);

    /**
    @ingroup zwapi_cmd_wireframe

    Initialize the parameters StartScale and EndScale of svxCrvIntData by the interpolated points.

    @param [in] nPnt number of the points
    @param [in] pPnts points list
    @param [out] startScale start tangent scale factor(NULL to ignore)
    @param [out] endScale end tangent scale factor(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxSkCrvIntScaleInit(int nPnt, const svxPoint *pPnts, double *startScale, double *endScale);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Adds a 2D curve interpolated through through the input
    points with the specified degree to the active sketch or sheet.
    If "idEnt" is not NULL, the id of the new curve entity
    is output.

    The StartScale and EndScale of svxCrvIntData can be initialized through interface
    cvxSkCrvIntScaleInit() by the interpolated points, or use the default value by
    cvxSkCrvIntInit(), or set them by yourselves.

    @note
    Structure svxCrvIntData can be initialized through interface svxCrvIntDataInit().

    @param [in] Crv input data interpolated curve
    @param [out] idEnt id of new 2D interpolated curve entity(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxSkCrvInt(svxCrvIntData *Crv, int *idEnt);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Initialize the parameters of the cvxSkSpline().
    If count > 0, this function allocates memory to data->Pnts based on the
    value of count and initializes the data->Pnts structure.
    Otherwise data->Pnts will be initialized to NULL.

    cvxSplinePntInit() can initialize struct svxSplinePnt (data->Pnts).

    If the user needs to clear "data" and count > 0, the cvxMemFree() interface
    needs to be called to free "data->Pnts" memory.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data Spline data
    @param [in] count count of points

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxSkSplineInit(svxSplineData *data, int count);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Adds a 2D curve interpolated through through the input points/control points with the
    specified data to the active sketch or sheet.

    If "idEnt" is not NULL, the id of the new curve entity is output.

    @note
    Structure svxSplineData can be initialized through interface cvxSkSplineInit().

    @param [in] PntData spline data
    @param [out] idEnt id of new 2D spline entity (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxSkSpline(const svxSplineData *PntData, int *idEnt);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Add a 3 Point Conic to the active sketch or Drawing.

    If "idEnt" is not NULL, the id of the new curve entity is output.

    @note
    Structure svxConic3ptData can be initialized through interface cvxSkConic3ptInit().

    @param [in] Data 3 Point Conic data
    @param [out] idEnt id of new curve

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxSkConic3pt(const svxConic3ptData *Data, int *idEnt);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Initialize the parameters of the cvxSkConic3pt().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] Data 3 Point Conic data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxSkConic3ptInit(svxConic3ptData *Data);


    //====================================================================================================================
    /** @name Edit Curve */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_sk_cmds

    Initialize the parameters of the cvxSkFillet().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data information of fillet in sheeting or sketch

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxSkFilletInit(svxSkFilletData *data);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Create a fillet in sheeting or sketch. filletInfo must be initialized before used.

    @note
    Interface cvxSkFilletInit() can initialize variables of this function.

    @param [in] filletData information of fillet in sheeting
    @param [out] idFillet id of fillet that created (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxSkFillet(const svxSkFilletData *filletData, int *idFillet);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Initialize the parameters of the cvxSkChamfer().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data information of chamfer in sheeting or sketch

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxSkChamferInit(svxSkChamferData *data);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Create a chamfer in sheeting or sketch. chmInfo must be initialized before used.

    @note
    Interface cvxSkChamferInit() can initialize variables of this function.

    @param [in] chmData information of chamfer in sheeting
    @param [out] idChamfer id of chamfer that created (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxSkChamfer(const svxSkChamferData *chmData, int *idChamfer);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Use this function to trim the sketch bewteen start point and end point.

    @param [in] pwTrim  power trim input data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxSkPowerTrim(const svxSkPowerTrim *pwTrim);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Use this function to trim the sketch include the specific point.

    @param [in] pnt  one touch trim input point

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxSkOneTouchTrim(const svxPntOnEnt *pnt);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Initialize the svxSkTrimExt structure.

    @param [out] trimExt trim/extend input data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxSkTrimExtInit(svxSkTrimExt *trimExt);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Use this function to trim or extend the sketch by the input svxTrimExt data.

    @note
    Interface cvxSkTrimExtInit() can initialize variables Pattern of this function.

    @param [in] trimExt trim/extend input data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxSkTrimExt(const svxSkTrimExt *trimExt);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Initialize the svxSkTrimSplit structure.

    @param [out] trimSpl trim/split input data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxSkTrimSplitInit(svxSkTrimSplit *trimSpl);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Use this function to trim or split the sketch by the input svxSkTrimSplit data.

    @note
    Interface cvxSkTrimSplitInit() can initialize variables Pattern of this function.

    @param [in] trimSpl trim/split input data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxSkTrimSplitCrv(const svxSkTrimSplit *trimSpl);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Use this function to trim or split the sketch at point by the input 
    svxSkTrimSplitPnt data.

    @param [in] trimSpl trim/split at point input data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxSkTrimSplitPnt(const svxSkTrimSplitPnt *trimSpl);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Initialize the svxSkTrimSplitCor structure.

    @param [out] trimSpl  trim/split input data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxSkTrimSplitCorInit(svxSkTrimSplitCor *trimSpl);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Use this function to trim or split the sketch to corner by the input 
    svxSkTrimSplitCor data.

    @note
    Interface cvxSkTrimSplitCorInit() can initialize variables Pattern of this function.

    @param [in] trimSpl trim/split input data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxSkTrimSplitCor(const svxSkTrimSplitCor *trimSpl);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Use this function to delete the bowties of specific curves.

    @param [in] numCrv the number of curves
    @param [in] idCrv  the list id of curves

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxSkDelBowties(const int numCrv, const int *idCrv);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Initialize the svxSkSplitIsect structure.

    @param [out] Spl split at intersections input data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxSkSplitIsectInit(svxSkSplitIsect *Spl);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Use this function to split the sketch at intersections by the input
    svxSkSplitIsect data.

    @note
    Interface cvxSkSplitIsectInit() can initialize variables Pattern of this function.

    @param [in] Spl split at intersections input data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxSkSplitIsect(const svxSkSplitIsect *Spl);


    //====================================================================================================================
    /** @name Constraint */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_sk_cmds

    Use the function to analyze the current sketch geometry and add constraints
    and dimensions automatically.

    @param [in] BasePnt base point (NULL to use the default sketch origin)
    @param [in] Count number of entities to add constraints and dimensions (0 for all entities)
    @param [in] idEnts list of entities to add constraints and dimensions (NULL for all entities)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        Zw_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxSkAutoCons(svxConsGeom *BasePnt, int Count, int *idEnts);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Add the specified geometry constraint with specified data and the type.
    the number of geometry required varies from constraint type, please specify
    the number and data of constraint geometry based on the specific constraint
    being created.

    The number and order of geometry required for each constraint type is as follows:  
    VX_SK_CONS_FIX: one point or entity;                                              
    VX_SK_CONS_ALI_Y: one reference point and one alignment point;                    
    VX_SK_CONS_ALI_X: one reference point and one alignment point;                    
    VX_SK_CONS_MID: two endpoints and one midpoint;                                   
    VX_SK_CONS_ON_CRV: one curve and one alignment point;                             
    VX_SK_CONS_ISECT: two curves and one alignment point;                             
    VX_SK_CONS_COIN: two points;                                                      
    VX_SK_CONS_HOR: one line;                                                         
    VX_SK_CONS_VER: one line;                                                         
    VX_SK_CONS_SYM: one symmetrical axis and two symmetrical points or entities;      
    VX_SK_CONS_PERP: one line and one curve;                                          
    VX_SK_CONS_PARA: two lines;                                                       
    VX_SK_CONS_COLINLN: two lines;                                                    
    VX_SK_CONS_TANG: one line and one curve;                                          
    VX_SK_CONS_EQL_LEN: two lines;                                                    
    VX_SK_CONS_EQL_CURVATURE: two curves;                                             
    VX_SK_CONS_EQL_RAD: two arcs or circles;                                          
    VX_SK_CONS_CONC: one arc or circle and one alignment point;

    The calling procedure MUST deallocate the output list.

    @param [in] type constraint type
    @param [in] subType constraint type, only fix constraint, entity symmetrical constraint and 
                        point to midpoint constraint need to set the variable (evxGeomConsSubType):
                        0: both the X and Y coordinates are constrained, used to VX_SK_CONS_FIX
                        1: only the X coordinate is constrained, used to VX_SK_CONS_FIX
                        2: only the Y coordinate is constrained, used to VX_SK_CONS_FIX
                        3: point to arc midpoint constraint, used only VX_SK_CONS_MID
                        4: mark as points symmetry, used only VX_SK_CONS_SYM, 
    @param [in] nGeoms number of constraint geometries
    @param [in] geoms array of constraint geometries data
    @param [out] Count number of constraints generated (NULL to ignore)
    @param [out] idCons id of constraints generated (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxSkAddGeomCons(evxGeomConsType type, int subType, int nGeoms, svxConsGeom *geoms, int *Count, int **idCons);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Create coincident constraints for the specified sketch/current active sketch.
    This function just add the constraints, not solve the constraints.

    @param [in] idSketch index of sketch (-1 to use the active sketch)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxSkAutoAddCoinCons(int idSketch);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Create coincident constraints for the specified sketch/current active sketch.

    The difference between this function and cvxSkAutoAddCoinCons() is that this function can skip
    the reference geometries and solve the constraints.

    @param [in] idSketch index of sketch (-1 to use the active sketch)
    @param [in] skipFlag 1-skip the reference geometries, else 0
    @param [in] solveFlag 1-solve the constraints after adding them, else 0

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxSkAutoAddCoinConsSkipRefGeom(int idSketch, int skipFlag, int solveFlag);


    //====================================================================================================================
    /** @name Dimension */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_sk_cmds

    Add the specified constraint dimension with specified data and the type.

    The "pData" defined by current command.
    If the "type" is VX_SK_CONSDIM_LINEAR or VX_SK_CONSDIM_LINEAR_OFFSET,
    all the data of "pData" should be defined.

    If the "type" is VX_SK_CONSDIM_ANGULAR, the data of "pData" should be
    defined by the type of svxConsDim.

    If the "type" is VX_SK_CONSDIM_RADIAL, the second point and second entity
    don't need to be defined.

    If the "type" is VX_SK_CONSDIM_ARC_LENGTH, the second point, second entity and
    the type of svxConsDim don't need to be defined.

    The function does not yet support the creation of type VX_SK_CONSDIM_SYMMETRY and
    type VX_SK_CONSDIM_PERIMETER dimension.

    @param [in] type type of constraint dimension
    @param [in] pData data of constraint dimension

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    */
    extern evxErrors cvxSkAddConsDim(evxConsDimType type, svxConsDim *pData);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Use this function to create 2D perimeter dimensions at the sketch.

    @param [in] data   perimeter dimension data
    @param [out] idDim id of dimension

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxSkAddPerimeterDim(svxPerimeterDimData *data, int *idDim);

    //====================================================================================================================
    /** @name Reference */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_sk_cmds

    Use this function to initialize the parameters of the cvxSkReference().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] data reference geometry input data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxSkReferenceInit(svxSkRefData *data);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Use this function to project a curve, face, point or datum located in the 
    active part/component to the sketch plane.

    The calling procedure MUST deallocate the output list with cvxMemFree.

    @param [in] data reference geometry input data
    @param [out] count number of reference geometries (NULL to ignore)
    @param [out] idRefEnts list of reference geometry id's (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxSkReference(const svxSkRefData *data, int *count, int **idRefEnts);

    //====================================================================================================================
    /** @name Basic Editing */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_sk_cmds

    Initialize the parameters of the cvxSkMove().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] type move method
    @param [out] data Region set data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxSkMoveInit(evxMoveType2D type, svxMoveData2D *data);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Moves the specified entity(entities) within the active 2D environment(drawing of sketch).

    Because this function has an internal call to the "cvxDispRedraw()" function,
    it must be called on the main thread.

    @note
    Interface cvxSkMoveInit() can initialize variables of this function.

    @param [in] data move data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxSkMove(const svxMoveData2D *data);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Rotate the specified entity(entities) within the active 2D environment(drawing of sketch).
    If "idEnts" is not NULL and value of Setting is VX_ROTATE_COPY, the ids of the rotate entity is output.

    @note
    Interface cvxSkRotateInit() can initialize variables of this function.

    @param [in] data Rotate data
    @param [out] cnt number of Entity ids that created (input NULL to ignore)
    @param [out] idEnts id of Entities that created (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxSkRotate(const svxRotateData2D *data, int *cnt, int **idEnts);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Initialize the parameters of the cvxSkRotate().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data Rotate data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxSkRotateInit(svxRotateData2D *data);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Mirror the specified entity(entities) within the active 2D environment(drawing of sketch).
    If "idEnts" is not NULL, the ids of the mirrored entity is output.

    @note
    Interface cvxSkMirrInit() can initialize variables of this function.

    @param [in] data mirror data
    @param [out] cnt number of Entity ids that created (input NULL to ignore)
    @param [out]  idEnts id of Entities that created (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxSkMirr(const svxMirrData2D *data, int *cnt, int **idEnts);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Initialize the parameters of the cvxSkMirr().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data mirror data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxSkMirrInit(svxMirrData2D *data);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Scales the specified entities in the active sketch or sheet by
    the input scale factors relative to the X, Y axes and origin
    of the active sketch  If "Pnt" is not NULL, its coordinates
    are used as the center of scaling.

    @param [in] Count number of entities
    @param [in] idEnts list of entity id's
    @param [in] X_scale X scale factor
    @param [in] Y_scale Y scale factor
    @param [in] Pnt optional reference point (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxSkScale(int Count, int *idEnts, double X_scale, double Y_scale, svxPoint2 *Pnt);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Initialize the svxSkPtnData structure.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] type  pattern type
    @param [out] data pattern data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxSkPtnDataInit(evxSkPatternType type, svxSkPtnData *data);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Use this function to pattern of sketches patterns.
    Three different methods of patterning are available, each method 
    requires different types of input.

    @note
    Interface cvxSkPtnDataInit() can initialize variables Pattern of this function.

    @param [in] Pattern  pattern input data
    @param [out] cnt     count of idEnts(can be NULL)
    @param [out] idEnts  list of new entity id.(can be NULL)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxSkPattern(const svxSkPtnData *Pattern, int *cnt, int **idEnts);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Initialize the svxSkCopy structure.

    @param [in] type  sketch copy type
    @param [out] data sketch copy data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxSkCopyInit(evxSkCopyType type, svxSkCopy *data);

    /**
    @ingroup zwapi_cmd_sk_cmds

    Use this function to create a copy by the input svxSkCopy data.

    @note
    Interface cvxSkCopyInit() can initialize variables data of this function.
    The calling procedure MUST deallocate the output list.

    @param [in] Spl       sketch copy input data
    @param [out] cnt      count of idEnts(can be NULL)
    @param [out] idEnts   list of new entity id.(can be NULL)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxSkCopy(const svxSkCopy *Spl, int *cnt, int **idEnts);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_SK_CMD_H */
