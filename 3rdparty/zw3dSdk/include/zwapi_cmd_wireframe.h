/**
@file zwapi_cmd_wireframe.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Wireframe Commands API
*/
/**
@defgroup zwapi_cmd_wireframe Wireframe Commands
@ingroup PartandAssemblyCommands
@brief
@details THE MODULE FOR THE ZW3D Wireframe Commands API
*/

#pragma once
#ifndef ZW_API_WIREFRAME_FTR_H /* this ifndef surrounds entire header */
#define ZW_API_WIREFRAME_FTR_H

#include "zwapi_cmd_wireframe_data.h"


#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Drawing */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_wireframe

    Adds a 3D point entity to the active part.   If "idEnt" is not
    NULL, the id of the new point entity is output.

    @param [in] Point point coordinates
    @param [out] idEnt id of new point entity

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
    extern evxErrors cvxPartPnt(svxPoint *Point, int *idEnt);

    /**
    @ingroup zwapi_cmd_wireframe

    Adds 3D points entity to the active part. 

    If the id of the alignment plane "idAlignPln" is valid and "PrjToPln" is 1, 
    the input point is projected onto the specified alignment plane. 

    If "idPntFtr" is not NULL, the id of the new point feature is output.

    @param [in] Count number of points
    @param [in] PntData points data
    @param [in] idAlignPln id of align plane
    @param [in] PrjToPln whether to project point to alignment plane
    @param [out] idPntFtr id of new point feature

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
    extern evxErrors cvxPartPntNew(int Count, const svxPntOnEntPath *PntData, int idAlignPln, int PrjToPln, int *idPntFtr);

    /**
    @ingroup zwapi_cmd_wireframe

    Adds a list 3D point entities to the active part.

    @param [in] Count number of points
    @param [in] Points list of points

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
    extern evxErrors cvxPartPnts(int Count, svxPoint *Points);

    /**
    @ingroup zwapi_cmd_wireframe

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
                    input and an extension option should be defined in case the specified
                     number of points at the specified distance exceeds the length of the curve;    
                    if "Num" is input as zero, then "Dist" must be specified; in this case, points are created
                    the specified distance apart, beginning at the end of the curve closest
                    to "Pnt" and ending at/before the other end of the curve.
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
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartPntsOnCrv(int idCrv, svxPoint *Pnt, int Num, double Dist, evxExtendOpt Opt, int *Count, int **idEnts);

    /**
    @ingroup zwapi_cmd_wireframe

    Adds a 3D line to the active part.   If "idEnt" is not
    NULL, the id of the new line entity is output.

    @param [in] Start start point
    @param [in] End end point
    @param [out] idEnt id of new 3D line entity

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartLine2pt(svxPoint *Start, svxPoint *End, int *idEnt);

    /**
    @ingroup zwapi_cmd_wireframe

    Initialize the parameters of the cvxPartLine().

    @note
    Do not assign a value to variable "lineData" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] lineData 3D line data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartLineInit(svxLineData *lineData);

    /**
    @ingroup zwapi_cmd_wireframe

    Adds a 3D line to the active part. If "idLine" is not
    NULL, the id of the new line entity is output.

    @param [in] lineData 3D line data
    @param [out] idLine id of new 3D line

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartLine(const svxLineData *lineData, int *idLine);

    /**
    @ingroup zwapi_cmd_wireframe

    Initialize the parameters of the cvxPartPolyline().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data 3D polyline data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartPolylineInit(svxPolylineData *data);

    /**
    @ingroup zwapi_cmd_wireframe

    Add a 3D Polyline to the active part by creating a separate line
    entity between each pair of input points.
    If "idEnt" is not NULL, this function outputs a list of the new line
    entity id's, and the number of new lines is assigned to "Cnt".
    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] polylinedata 3D polyline data
    @param [out] Cnt number of lines to construct polyline
    @param [out] idEnt id of new lines to construct polyline

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartPolyLine(const svxPolylineData *polylinedata, int *Cnt, int **idEnt);

    /**
    @ingroup zwapi_cmd_wireframe

    Adds a 3D arc to the active part.   If "idEnt" is not
    NULL, the id of the new arc entity is output.

    @param [in] Start start point
    @param [in] End end point
    @param [in] Mid mid (i.e. through) point
    @param [out] idEnt id of new 3D arc entity

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartArc3pt(svxPoint *Start, svxPoint *End, svxPoint *Mid, int *idEnt);

    /**
    @ingroup zwapi_cmd_wireframe

    Adds a 3D arc to the active part.  The arc lies on
    the specified plane with its center at the plane's origin
    and its start/end angles measured CCW from the plane's X axis.
    If "idEnt" is not NULL, the id of the new entity is output.

    @param [in] Plane insertion plane
    @param [in] Radius radius (mm)
    @param [in] Start start angle (deg) - CCW from X axis
    @param [in] End end angle (deg) - CCW from X axis
    @param [out] idEnt id of new 2D circle entity

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartArcRad(svxMatrix *Plane, double Radius, double Start, double End, int *idEnt);

    /**
    @ingroup zwapi_cmd_wireframe

    Initialize the parameters of the cvxPartArc().

    @note
    Do not assign a value to variable "arcData" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] arcData 3D arc data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartArcInit(svxArcData *arcData);

    /**
    @ingroup zwapi_cmd_wireframe

    Adds a 3D arc to the active part. If "idArc" is not
    NULL, the id of the new arc entity is output.

    @param [in] arcData 3D arc data
    @param [out] idArc id of new 3D arc

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartArc(const svxArcData *arcData, int *idArc);

    /**
    @ingroup zwapi_cmd_wireframe

    Initialize the parameters of the cvxPartCircle().

    @note
    Do not assign a value to variable "circleData" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] circleData 3D circle data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartCircleInit(svxCircleData *circleData);

    /**
    @ingroup zwapi_cmd_wireframe

    Adds a 3D circle to the active part. If "idCircle" is not
    NULL, the id of the new arc entity is output.

    @param [in] circleData 3D circle data
    @param [out] idCircle id of new 3D circle

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartCircle(const svxCircleData *circleData, int *idCircle);

    /**
    @ingroup zwapi_cmd_wireframe

    Initialize the parameters of the cvxPartRectangle().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data Rectangle data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW-API_MEMORY_ERROR
    */
    extern evxErrors cvxPartRectangleInit(svxRectangleData *data);

    /**
    @ingroup zwapi_cmd_wireframe

    Add a 3D rectangle to the active part.  The rectangle lies on
    the specified plane with the specified center.
    Commonly, the output number "iCnt" should be 4.
    If "idEnt" is not NULL, the id of 4 lines of the rectangle is output.

    @note
    Structure svxRectangleData can be initialized through interface cvxPartRectangleInit().

    @param [in] rectData rectangle input data
    @param [out] iCnt number of output entities
    @param [out] idEnt id of new 3D rectangle entities

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
    extern evxErrors cvxPartRectangle(svxRectangleData *rectData, int *iCnt, int **idEnt);

    /**
    @ingroup zwapi_cmd_wireframe

    Adds a 3D circle to the active part.   If "idEnt" is not
    NULL, the id of the new circle entity is output.

    @param [in] P1 first point on circle
    @param [in] P2 second point on circle
    @param [in] P3 third point on circle
    @param [out] idEnt id of new 3D circle entity

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INTI_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartCir3pt(svxPoint *P1, svxPoint *P2, svxPoint *P3, int *idEnt);

    /**
    @ingroup zwapi_cmd_wireframe

    Adds a 3D circle to the active part.  The circle lies on
    the specified plane with its center at the plane's origin.
    If "idEnt" is not NULL, the id of the new entity is output.

    @param [in] Plane insertion plane
    @param [in] Radius radius (mm)
    @param [out] idEnt id of new 2D circle entity

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartCirRad(svxMatrix *Plane, double Radius, int *idEnt);

    /**
    @ingroup zwapi_cmd_wireframe

    Initialize the parameters of the cvxPartEllipse().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data Ellipse data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartEllipseInit(svxRectangleData *data);

    /**
    @ingroup zwapi_cmd_wireframe

    Add a 3D ellipse to the active part.  The ellipse lies on
    the specified plane with the specified center.
    If "idEnt" is not NULL, the id of the new entity is output.

    @note
    Structure svxRectangleData can be initialized through interface cvxPartEllipseInit().

    @param [in] ellipseData ellipse input data
    @param [out] idEnt id of new 3D ellipse entity

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
    extern evxErrors cvxPartEllipse(svxRectangleData *ellipseData, int *idEnt);

    //====================================================================================================================
    /** @name Curve */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_wireframe

    Initialize the parameters of the cvxPartCrvInt().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data 3D interpolated curve data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartCrvIntInit(svxCrvIntData *data);

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
    extern evxErrors cvxPartCrvIntScaleInit(int nPnt, const svxPoint *pPnts, double *startScale, double *endScale);

    /**
    @ingroup zwapi_cmd_wireframe

    Adds a 3D curve interpolated through through the input
    points with the specified degree to the active part.
    If "idEnt" is not NULL, the id of the new curve entity
    is output.

    @note
    Structure svxCrvIntData can be initialized through interface cvxPartCrvIntInit().  
    The StartScale and EndScale of svxCrvIntData can be initialized through interface 
    cvxPartCrvIntScaleInit() by the interpolated points, or use the default value by 
    cvxPartCrvIntInit(), or set them by yourselves .

    @param [in] Crv input data interpolated curve
    @param [out] idEnt id of new 3D interpolated curve entity

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
    extern evxErrors cvxPartCrvInt(svxCrvIntData *Crv, int *idEnt);

    /**
    @ingroup zwapi_cmd_wireframe

    Initialize the parameters of the cvxPartSpline().
    If count > 0, this function allocates memory to data->Pnts based on the
    value of count and initializes the data->Pnts structure.
    Otherwise data->Pnts will be initialized to NULL.

    cvxSplinePntInit() can initialize struct svxSplinePnt (data->Pnts).

    If the user needs to clear "data" and count > 0, the cvxMemFree interface
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
    extern evxErrors cvxPartSplineInit(svxSplineData *data, int count);

    /**
    @ingroup zwapi_cmd_wireframe

    Initialize the svxSplinePnt structure.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data Spline point data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxSplinePntInit(svxSplinePnt *data);

    /**
    @ingroup zwapi_cmd_wireframe

    Adds a 3D curve interpolated through through the input points/control points with the
    specified data to the active part.

    If "idEnt" is not NULL, the id of the new curve entity is output.

    @note
    Structure svxSplineData can be initialized through interface cvxPartSplineInit().

    @param [in] PntData spline data
    @param [out] idEnt id of new 2D spline entity (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INTPUT
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartSpline(const svxSplineData *PntData, int *idEnt);

    /**
    @ingroup zwapi_cmd_wireframe

    Initialize the parameters of the cvxPartCrvProjToFace().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data project to face data 

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartCrvProjToFaceInit(svxCrvProjToFace *data);

    /**
    @ingroup zwapi_cmd_wireframe

    Use this command to project curves or a sketch onto faces and/or datum planes. By default,
    the curve is projected normal to the faces or planes. Use the Direction option to select a
    different project direction.

    You can also choose to limit the projected curve to the face's trim boundaries. If more
    than one curve is created, they become a single feature.

    @note
    Interface cvxPartCrvProjToFaceInit() can initialize variables of this function.
    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] data project to face data 
    @param [out] cntEnts count of new curve entities (NULL to ignore)
    @param [out] pEnts index of new curve entities (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartCrvProjToFace(const svxCrvProjToFace *data, int *cntEnts, int **pEnts);

    /**
    @ingroup zwapi_cmd_wireframe

    Initialize the parameters of the cvxPartInterXCurve().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data inter curve data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartInterXCurveInit(svxInterCrvData *data);

    /**
    @ingroup zwapi_cmd_wireframe

    Use this function to create a curve or curves at the intersection of two or more faces,
    open shapes, or solids.

    @note
    Interface cvxPartInterXCurveInit() can initialize variables of this function.

    @param [in] pSurf faces to intersect
    @param [out] idFtr id of new curves list (pass in NULL to ignore)

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
    extern evxErrors cvxPartInterXCurve(const svxInterCrvData *pSurf, int *idFtr);

    /**
    @ingroup zwapi_cmd_wireframe

    Initialize the parameters of the cvxPartCrvOnFaceThruPts().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data curve on face through points data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartCrvOnFaceThruPtsInit(svxCrvOnFaceThuPts *data);

    /**
    @ingroup zwapi_cmd_wireframe

    Use this command to create a curve through a series of points on a face.
    Both the points and the curve lie on the face.

    @note
    Interface cvxPartCrvOnFaceThruPtsInit() can initialize variables of this function.

    @param [out] data curve on face through points data
    @param [in] idEnt index of new curve entity (NULL to ignore) 

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartCrvOnFaceThruPts(const svxCrvOnFaceThuPts *data, int *idEnt);

    /**
    @ingroup zwapi_cmd_wireframe

    Initialize the parameters of the svxIsoCrvOnFaceData for cvxPartIsoCurveOnFace().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data iso-curve on face data
    @param [in] crvIsoType iso-curve on face methods

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartIsoCurveOnFaceInit(svxIsoCrvOnFaceData *data, evxCrvIsoType crvIsoType);

    /**
    @ingroup zwapi_cmd_wireframe

    Use this command to create iso-curves on a face using a variety of methods.
    The curves are independent wireframe features that associated with the face.
    The methods in At Points, At U/V Parameter and Multiple.

    The calling procedure MUST deallocate the output list with cvxMemFree() if cntEnts
    and idEnts are not NULL.

    @note
    Interface cvxPartIsoCurveOnFaceInit() can initialize variables of this function.

    @param [in] data iso-curve on face data
    @param [out] cntEnts count of new curve entities (NULL to ignore) 
    @param [out] idEnts index of new curve entities (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartIsoCurveOnFace(const svxIsoCrvOnFaceData *data, int *cntEnts, int **idEnts);

    /**
    @ingroup zwapi_cmd_wireframe

    Initialize the parameters of the svxIsoclineCrvData for cvxPartIsoclineCurve().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data isocline curve data
    @param [in] type create isocline curve's type (single angle or multiple angles)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartIsoclineCurveInit(svxIsoclineCrvData *data, evxIsoclineCrvType type);

    /**
    @ingroup zwapi_cmd_wireframe

    Use this command to create isocline curves on faces.

    @note
    Interface cvxPartIsoclineCurveInit() can initialize variables of this function.

    The calling procedure MUST deallocate the output list with cvxMemFree() if cntEnts
    and idEnts are not NULL.

    @param [in] data isocline curve data
    @param [out] cntEnts count of new curve entities (NULL to ignore)
    @param [out] idEnts index of new curve entities (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartIsoclineCurve(const svxIsoclineCrvData *data, int *cntEnts, int **idEnts);

    /**
    @ingroup zwapi_cmd_wireframe

    This command is helpful when creating general face curves for which functionality provided
    by the parting line commands is not needed. Face curves can be created quickly around
    selected faces or from the projections of sketches and 3D curves onto those faces.

    @note
    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] data face curve data
    @param [out] cntEnts count of new curve entities (NULL to ignore)
    @param [out] idEnts index of new curve entities (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartFaceCurve(const svxFaceCrvData *data, int *cntEnts, int **idEnts);

    /**
    @ingroup zwapi_cmd_wireframe

    Use this command to create one or more new curves by project two curves.
    Please note that the projections of two curves must intersect, otherwise
    ZW3D will alarm this command failed.

    @note
    The calling procedure MUST deallocate the output list with cvxMemFree() if cntEnts
    and idEnts are not NULL.

    @param [in] data combined projection data
    @param [out] cntEnts count of new curve entities (NULL to ignore)
    @param [out] idEnts index of new curve entities (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartCombinedProj(const svxCrvCombinedProjData *data, int *cntEnts, int **idEnts);

    /**
    @ingroup zwapi_cmd_wireframe

    Use this command to extract centerlines from an existing face. Cylinder, Cone
    and Torus faces are recognized and the appropriate curve type is created.

    @note
    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] cntFaces count of faces to create centerlines
    @param [in] idFaces index of faces to create centerlines
    @param [in] extractAxis 1 to display the axis, else 0
    @param [out] cntEnts count of new curve entities (NULL to ignore)
    @param [out] idEnts index of new curve entities (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartExtractCenterlines(int cntFaces, int *idFaces, int extractAxis, int *cntEnts, int **idEnts);

    /**
    @ingroup zwapi_cmd_wireframe

    Initialize the parameters of the svxCrvBlendCons for cvxPartBlendCrvs().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] consData curve blend constraints data
    @param [in] objType object type (curve or face)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartBlendCrvsConsInit(svxCrvBlendCons *consData, evxCrvBlendObjType objType);

    /**
    @ingroup zwapi_cmd_wireframe

    Initialize the parameters of the cvxPartBlendCrvs().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data curve blend data 

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartBlendCrvsInit(svxCrvBlendData *data);

    /**
    @ingroup zwapi_cmd_wireframe

    Use this command to create a curve blend between two curves, lines,
    arcs, face edges or points. If "idEnt" is not NULL, the id of the
    shape created by this function is output via "idEnt".

    @note
    Interface cvxPartBlendCrvsInit() can initialize variables of this function.

    @param [in] data curve blend data
    @param [out] idEnt id of blend curve (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartBlendCrvs(const svxCrvBlendData *data, int *idEnt);

    /**
    @ingroup zwapi_cmd_wireframe

    Offset a curve with distance "Dis".

    @param [in] idCurve curve id
    @param [in] Dis offset distance
    @param [out] idOut id of curve after offset (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INTI_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartCurveOffset(int idCurve, double Dis, int *idOut);

    /**
    @ingroup zwapi_cmd_wireframe

    Use this command to create a spiral curve on a plane. User can define the revolve
    direction to clockwise or anti-clockwise.

    @param [in] data spiral curve data
    @param [out] idEnt index of new curve entity (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartSpiralCurve(const svxSpiralCrvData *data, int *idEnt);

    /**
    @ingroup zwapi_cmd_wireframe

    Adds a 3D curve-list entity which groups the specified curves.
    Features like Sweep, Revolve and Extrude may be applied to 3D
    curve-lists as well as 2D sketches.  If "idEnt" is not NULL,
    the id of the new entity is output.

    @param [in] Count number of curves in curve-list
    @param [in] Curves pointer to list of 3D curve id's
    @param [out] idEnt id of new curve-list entity

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
    extern evxErrors cvxPartCrvList(int Count, int *Curves, int *idEnt);

    /**
    @ingroup zwapi_cmd_wireframe

    Adds a curve to the active part.   If "idEnt" is not
    NULL, the id of the new curve entity is output.

    @param [in] Crv curve data
    @param [out] idEnt id of new curve entity

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INTI_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartCurve(svxCurve *Crv, int *idEnt);

    /**
    @ingroup zwapi_cmd_wireframe

    Project a 2D curve along a direction, to find its silhouettes.
    This will split the curve on its self-intersections.
    Output new silhouette curves via "idList".

    @param [in] idCurve curve id
    @param [in] dir project direction
    @param [out] iCnt number of new curves (NULL to ignore)
    @param [out] idList id of new curves (NULL to ignore)

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
    extern evxErrors cvxPartCurveSilh(int idCurve, svxPoint *dir, int *iCnt, int **idList);

    /**
    @ingroup zwapi_cmd_wireframe

    Add a curve to the active part from fitting some points and smooth it.
    If "idEnt" is not NULL, the id of the new curve entity is output.

    @param [in] iCnt number of points
    @param [in] pnts points
    @param [in] tol tolerance value
    @param [in] smth smooth value
    @param [out] idEnt id of new curve entity

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
    extern evxErrors cvxPartFittingCrv(int iCnt, svxPoint *pnts, double tol, double smth, int *idEnt);

    //====================================================================================================================
    /** @name Edit Curve */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_wireframe

    Initialize the parameters of the cvxPartCrvFillet().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data fillet data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartCrvFilletInit(svxCrvFilletData *data);

    /**
    @ingroup zwapi_cmd_wireframe

    Use this function to create a fillet between two curves.

    @param [in] data fillet data
    @param [out] idFillet index of new fillet feature (NULL to ignore)

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
    extern evxErrors cvxPartCrvFillet(const svxCrvFilletData *data, int *idFillet);

    /**
    @ingroup zwapi_cmd_wireframe

    Initialize the parameters of the cvxPartCrvFilletChain().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data chain fillet data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartCrvFilletChainInit(svxCrvFilletChainData *data);

    /**
    @ingroup zwapi_cmd_wireframe

    Use this function to create fillets of a specified radius between a chain of curves.

    @param [in] data chain fillet data
    @param [out] idFilletChain index of new fillet feature (NULL to ignore)

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
    extern evxErrors cvxPartCrvFilletChain(const svxCrvFilletChainData *data, int *idFilletChain);

    /**
    @ingroup zwapi_cmd_wireframe

    Initialize the parameters of the cvxPartCrvChamfer().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data chamfer data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartCrvChamferInit(svxCrvChamferData *data);

    /**
    @ingroup zwapi_cmd_wireframe

    Use the function to create a chamfer between two boundary curves by specifying
    the setback(s) or setback value and angle. If a setback sets to "ZERO", the two
    curves are trimmed/extended to each other forming a corner.

    @param [in] data chamfer data
    @param [out] idChamfer index of new chamfer feature (NULL to ignore)

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
    extern evxErrors cvxPartCrvChamfer(const svxCrvChamferData *data, int *idChamfer);

    /**
    @ingroup zwapi_cmd_wireframe

    Initialize the parameters of the cvxPartCrvChamferChain().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data chain chamfer data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartCrvChamferChainInit(svxCrvChamferChainData *data);

    /**
    @ingroup zwapi_cmd_wireframe

    Use this function to create chamfers of equal setback around a chain of curves.
    There will be a chamfer between each adjacent curve in the chain.

    @note
    Interface cvxPartCrvChamferChainInit() can initialize variables of this function.

    @param [in] data chain chamfer data
    @param [out] idChamfer index of new chamfer feature (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartCrvChamferChain(const svxCrvChamferChainData *data, int *idChamfer);

    /**
    @ingroup zwapi_cmd_wireframe

    Use this function to trim curves or sketches to faces.

    @param [in] data trim to faces data
    @param [out] idTrim index of new feature (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartCrvTrimToFaces(const svxCrvTrimToFacesData *data, int *idTrim);

    /**
    @ingroup zwapi_cmd_wireframe

    Split a curve at specified points.
    Outputs a list of indices of the new curves after split.  The calling
    procedure MUST deallocate the internal memory of each element in the
    output list by calling cvxCurveFree(), after which the output list MUST
    be deallocated with cvxMemFree().

    @param [in] idCurve curve id
    @param [in] CountPnts number of points to split at
    @param [in] Points list of points to split at
    @param [out] CountCrvs number of curves after split (NULL to ignore)
    @param [out] NewCrvs list of curves after split (NULL to ignore)

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
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartCrvSplitAtPnts(int idCurve, int CountPnts, svxPoint *Points, int *CountCrvs, int **NewCrvs);

    /**
    @ingroup zwapi_cmd_wireframe

    Get the curve data of the idEnt and the reversed curve data will be output.

    @see cvxPartInqCurve().This interface can obtain curve data of curves,
    which is the opposite of this interface.

    @param [in] idEnt id of curvilinear entity
    @param [out] data curve data.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxPartInqReversedCurve(int idEnt, svxCurve *data);

    /**
    @ingroup zwapi_cmd_wireframe

    Trim or split curves to a set of boundary curves. First select the boundary Curves to
    split or trim to. Then select the curve Segments to delete, keep, or split. Curves can
    be split or trimmed by each curve in the set of boundary curves. At the part level you
    can trim 3D non-intersecting curves.

    @note
    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] data trim with curve data
    @param [out] CountCrvs count of new curve entities (NULL to ignore) 
    @param [out] NewCrvs index of new curve entities (NULL to ignore)

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
    extern evxErrors cvxPartCrvTrimWithCrv(const svxTrimWithCrvData *data, int *CountCrvs, int **NewCrvs);

    /**
    @ingroup zwapi_cmd_wireframe

    Use this command to create an arc that share the same arc center.

    @param [in] refArc id of reference 3D arc entity (can be edge/curve)
    @param [in] radius radius (mm)
    @param [out] idEnt index of new 3D arc entity (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartConcentricArc(int refArc, double radius, int *idEnt);

    /**
    @ingroup zwapi_cmd_wireframe

    Initialize the parameters of the cvxPartCrvConvertToArcs().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data curves convert to arc/line data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartCrvConvertToArcsInit(svxCrvConvertTocData *data);

    /**
    @ingroup zwapi_cmd_wireframe

    Initialize the parameters of the cvxPartCrvConvertToArcs().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] data curves convert to arc/line data
    @param [out] cntArcs count of arcs/lines after conversion (NULL to ignore)
    @param [out] idArcs id of arcs/lines after conversion (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartCrvConvertToArcs(const svxCrvConvertTocData *data, int *cntArcs, int **idArcs);

    //====================================================================================================================
    /** @name Basic Editing */
    //====================================================================================================================
/**********************************************************************
*! -Pattern Geometry- : zwapi_cmd_shape.h
*  extern int cvxPartPatternGeom(int Count, int* idEnts, const svxPtnGeom* Pattern, int* idPattern);
**********************************************************************/

/**********************************************************************
*! -Pattern Feature- : zwapi_cmd_shape.h
*  extern int cvxPartPatternFtr(int Count, int* idFtrs, const svxPtnFtr* Pattern, int* idPattern);
**********************************************************************/

/**********************************************************************
*! -Mirror Geometry- : zwapi_cmd_shape.h
*  extern int cvxPartMirrorGeom(svxMirrorGeom* Mirror, int* NumNewEnts, int** idNewEnts);
**********************************************************************/

/**********************************************************************
*! -Mirror Feature- : zwapi_cmd_shape.h
*  extern int cvxPartMirrorFtr(svxMirrorFtr* Mirror, int* idFtr);
**********************************************************************/

/**********************************************************************
*! -Move-  : zwapi_cmd_shape.h
*  extern int cvxPartMove(const svxMoveData *Move, int *idMove);
**********************************************************************/

/**********************************************************************
*! -Copy-  : zwapi_cmd_shape.h
*  extern int cvxPartCopy(const svxCopyData *Copy, int *idCopy);
**********************************************************************/

/**********************************************************************
*! -Scale-  : zwapi_cmd_shape.h
*  extern int cvxPartScale(int Count, int* idEnts, double X, double Y, double Z, int idDatum);
*  extern int cvxPartScale2(int Count, int* idEnts, double X, double Y, double Z, int idDatum, svxPoint* CentPnt);
**********************************************************************/

    //====================================================================================================================
    /** @name Datum */
    //====================================================================================================================
/**********************************************************************
*! -Datum Axis- : zwapi_cmd_datum.h
*  extern int cvxPartAxisNew(svxAxisData *Axis, int *idAxis);
**********************************************************************/

/**********************************************************************
*! -Datum Plane- : zwapi_cmd_datum.h
*  extern int cvxPartDatum(svxMatrix* Frame, int* idDatum);
*  extern int cvxPartDatum2(svxMatrix* Frame, int iCode, int* idDatum);
*  extern int cvxPartNewDatum(svxMatrix* Frame, int* idDatum);
*  extern int cvxPartPlnCrv(int idCrv, svxPoint* Origin, svxPoint* Xaxis, int* idPln);
*  extern int cvxPartPlnCrv2(int idCrv, svxData* Origin, svxData* Xaxis, int Flip, int* idPln);
*  extern int cvxPartPlnSrf(int idFace, svxPoint* Origin, int* idPln);
*  extern int cvxPartPlnSrf2(int idFace, svxPoint* Origin, svxPoint* XZ, int Flip, int* idPln);
*  extern int cvxPartPlaneNew(svxPlaneData* Plane, int* idPlane);
*  extern int cvxPartPlaneAddInit(evxNewPlaneMethods method, svxNewPlaneData* data);
*  extern int cvxPartPlaneAdd(const svxNewPlaneData* plane, int* idPlane);
**********************************************************************/

/**********************************************************************
*! -Datum CSYS- : zwapi_cmd_datum.h
*  extern int cvxPartCSYSNewInit(evxCSYSMethods method, svxCSYSData* data);
*  extern int cvxPartCSYSNew(svxCSYSData* CSYS, int* idCSYS);
**********************************************************************/

/**********************************************************************
*! -LCS- : zwapi_cmd_datum.h
*  extern int cvxPartActiveAsLCS(int id);
**********************************************************************/
/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_WIREFRAME_FTR_H */
