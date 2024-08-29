/**
@file zwapi_cmd_datum_data.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the Datum/
Axis/CSYS Command functions.
*/
/**
@defgroup zwapi_cmd_datum_data Datum Commands Data
@ingroup PartandAssemblyCommands
@brief
@details THE MODULE FOR THE ZW3D Data Types and Structures of the Datum/
Axis/CSYS Command functions.
*/

#pragma once
#ifndef ZW_API_DATUM_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_DATUM_DATA_H

#include "zwapi_util.h"
#include "zwapi_cmd_subcmd_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Datum Axis Data */
    //====================================================================================================================
    /**
    @brief Axis Methods
    @ingroup zwapi_cmd_datum_data
    */
    typedef enum evxAxisMethods
    {
        VX_AXIS_GEOMETRY        = 0, /**<@brief  geometry */
        VX_AXIS_FACE_CENTER     = 1, /**<@brief  face center axis */
        VX_AXIS_XX              = 2, /**<@brief  X Axis */
        VX_AXIS_YY              = 3, /**<@brief  Y Axis */
        VX_AXIS_ZZ              = 4, /**<@brief  Z Axis */
        VX_AXIS_TWO_PNT         = 5, /**<@brief  Two Point */
        VX_AXIS_PNT_DIR         = 6, /**<@brief  point and Direction */
        VX_AXIS_INTERSECT_FACES = 7, /**<@brief  intersect faces */
    } evxAxisMethods;

    /**
    @brief template command Axis input data
    @ingroup zwapi_cmd_datum_data
    */
    typedef struct svxAxisData
    {
        double length;         /**<@brief  axis length */
        evxAxisMethods method; /**<@brief  axis methods */
        union evxAxisInpUnion  /**<@brief  union of Axis input data */
        {
            struct AxisPntAndDir /**<@brief point and direction */
            {
                int idOrgPnt;    /**<@brief  id of the origin parent entity */
                svxPoint OrgPnt; /**<@brief  origin point */
                svxVector Dir;   /**<@brief  direction */
            } pntDir;
            struct AxisGeomPnt /**<@brief  geometry */
            {
                svxPoint Pnt;    /**<@brief  picked Point */
                svxEntPath Path; /**<@brief  entity/object pick path */
            } geomPnt;
            struct AxisFaceCenter /**<@brief  face center Axis */
            {
                svxEntPath Face; /**<@brief  face */
            } facCenter;
            struct AxisIntersectFaces /**<@brief  intersect faces */
            {
                svxEntPath Face1; /**<@brief  1st face */
                svxEntPath Face2; /**<@brief  2nd face */
            } interFaces;
            struct AxisTwoPnts /**<@brief  Two Points */
            {
                int idPnt1;    /**<@brief  id of the point1 parent entity */
                svxPoint Pnt1; /**<@brief  1st point */
                int idPnt2;    /**<@brief  id of the point2 parent entity */
                svxPoint Pnt2; /**<@brief  2nd point */
            } twoPnts;
        } inpUnion;
        int FlipDir; /**<@brief  flip direction */
    } svxAxisData;

    //====================================================================================================================
    /** @name Datum Plane */
    //====================================================================================================================
    /**
    @brief Plane Methods
    @ingroup zwapi_cmd_datum_data
    */
    typedef enum evxPlaneMethods
    {
        VX_PLANE_GEOMETRY     = 0, /**<@brief  geometry */
        VX_PLANE_THREE_POINTS = 1, /**<@brief  three points */
        VX_PLANE_XY           = 2, /**<@brief  XY Plane */
        VX_PLANE_XZ           = 3, /**<@brief  XZ Plane */
        VX_PLANE_YZ           = 4, /**<@brief  YZ Plane */
        VX_PLANE_VIEW_PLANE   = 5, /**<@brief  view plane */
        VX_PLANE_TWO_ENTITIES = 6, /**<@brief  two entities */
        VX_PLANE_DYNAMIC      = 7, /**<@brief  dynamic */
    } evxPlaneMethods;

    /**
    @brief Plane Orientation Align type
    @ingroup zwapi_cmd_datum_data
    */
    typedef enum evxPlaneAlign
    {
        VX_PLANE_ALIGN_TO_XY = 1, /**<@brief  align to XY of geometry frame */
        VX_PLANE_ALIGN_TO_XZ = 2, /**<@brief  align to XZ of geometry frame */
        VX_PLANE_ALIGN_TO_YZ = 3, /**<@brief  align to YZ of geometry frame */
    } evxPlaneAlign;

    /**
    @brief template command Plane input data
    @ingroup zwapi_cmd_datum_data
    */
    typedef struct svxPlaneData
    {
        evxPlaneMethods method; /**<@brief  methods */
        union evxPlnInpUnion    /**<@brief  union of plane data */
        {
            struct PlnGeomPnt /**<@brief  geometry */
            {
                svxPoint Pnt;    /**<@brief  picked Point */
                svxEntPath Path; /**<@brief  entity/object pick path */
            } geomPnt;
            struct PlnThreePnts /**<@brief  three point */
            {
                int idOrgPnt;    /**<@brief  id of the origin parent entity */
                svxPoint OrgPnt; /**<@brief  origin */
                int idXPnt;      /**<@brief  id of the XPoint parent entity */
                svxPoint XPnt;   /**<@brief  XPoint */
                int idYPnt;      /**<@brief  id of the YPoint parent entity */
                svxPoint YPnt;   /**<@brief  YPoint */
            } threePnts;
            struct PlaneXYZ /**<@brief  use XY Plane/ XZ Plane/ YZ Plan */
            {
                double Offset; /**<@brief  offset */
            } xyz;
            struct viewPlane /**<@brief  view plane */
            {
                svxPoint OrgPnt; /**<@brief  origin */
            } viewPln;
            struct PlnTwoEnts /**<@brief  Two Entities */
            {
                int idEnt1;       /**<@brief  id of the Entity1 parent entity */
                svxPoint Ent1Pnt; /**<@brief  entity 1 point */
                int idEnt2;       /**<@brief  id of the Entity2 parent entity */
                svxPoint Ent2Pnt; /**<@brief  entity 2 point */
            } twoEnts;
            struct PlnDynamic /**<@brief  Dynamic */
            {
                int idPosPnt;    /**<@brief  id of the position parent entity */
                svxPoint PosPnt; /**<@brief  position */
                svxVector XAxis; /**<@brief  X Axis */
                svxVector YAxis; /**<@brief  Y Axis */
                svxVector ZAxis; /**<@brief  Z Axis */
            } dynamic;
        } inpUnion;

        evxPlaneAlign AlignType; /**<@brief  plane orientation align type*/

        /*  the follows can be set according to the requirements(Orientation) */
        double dOffset;  /**<@brief  offset value */
        int idOrgPnt;    /**<@brief  id of the origin parent entity */
        svxPoint OrgPnt; /**<@brief  origin */
        int idXPnt;      /**<@brief  id of the XPoint parent entity */
        svxPoint XPnt;   /**<@brief  XPoint */
        double XAng;     /**<@brief  angle value X direction */
        double YAng;     /**<@brief  angle value Y direction */
        double ZAng;     /**<@brief  angle value Z direction */
    } svxPlaneData;

    /**
    @brief New Plane Methods
    @ingroup zwapi_cmd_datum_data
    */
    typedef enum evxNewPlaneMethods
    {
        VX_NEW_PLANE_THREE_POINTS = 1,  /**<@brief  three points */
        VX_NEW_PLANE_VIEW_PLANE   = 5,  /**<@brief  view plane */
        VX_NEW_PLANE_DYNAMIC      = 7,  /**<@brief  dynamic */
        VX_NEW_PLANE_GEOMETRY     = 11, /**<@brief  geometry */
        VX_NEW_PLANE_OFFSET_PLANE = 12, /**<@brief  offset plane */
        VX_NEW_PLANE_ANGLE_FACE   = 13, /**<@brief  angle to face */
        VX_NEW_PLANE_ON_CURVE     = 14, /**<@brief  on curve */
    } evxNewPlaneMethods;

    /**
    @brief Plane direction type
    @ingroup zwapi_cmd_datum_data
    */
    typedef enum evxOnCrvDirType
    {
        VX_ONCRV_TANGENT,                /**<@brief  tangent */
        VX_ONCRV_PERPENDICULAR,          /**<@brief  perpendicular */
        VX_ONCRV_PERPENDICULAR_TO_CURVE, /**<@brief  perpendicular to curve */
        VX_ONCRV_TANGENT_TO_CURVE,       /**<@brief  tangent to curve */
    } evxOnCrvDirType;

    /**
    @brief New template command Plane input data
    @ingroup zwapi_cmd_datum_data
    */
    typedef struct svxNewPlaneData
    {
        evxNewPlaneMethods method;    /**<@brief  methods */
        union evxNewPlaneMethodsUnion /**<@brief union of plane input data */
        {
            struct NewPlaneGeometry /**<@brief  geometry :VX_NEW_PLANE_GEOMETRY */
            {
                /* Use (cnt, pnts, paths) if input multiple entities */
                svxPoint pnt;    /**<@brief  Picked Point */
                svxEntPath path; /**<@brief  entity/object pick path */

                /* don't need to set pnts and paths if cnt = 0 or use pnt and path to set "Geometry"
                 (suggest to use the following variables, pnt and path may be deprecated in the next version) */
                int cnt;           /**<@brief  count of pnts and paths */
                svxPoint *pnts;    /**<@brief  picked points */
                svxEntPath *paths; /**<@brief  entity/object pick paths */

                /* Results */
                double offset; /**<@brief  offset the new datum from the target geometry */
                double angle;  /**<@brief  angle (default: 45) */
            } geom;
            struct NewPlaneThreePnt /**<@brief  three point :VX_NEW_PLANE_THREE_POINTS */
            {
                svxPoint orgPnt;                /**<@brief  origin */
                svxPntByOffset *orgPntByOffset; /**<@brief  set the origin point by the offset sub-command (NULL to use orgPnt or orgPntBy2Lines)
                                              cvxPartPntByOffsetInit() can initialize this parameter */

                svxPntBy2Lines *orgPntBy2Lines; /**<@brief  set the origin point by the from 2 lines sub-command (NULL to use orgPnt or orgPntByOffset)
                                              cvxPartPntBy2LinesInit() can initialize this parameter */

                svxPoint xPnt;                /**<@brief  XPoint */
                svxPntByOffset *xPntByOffset; /**<@brief  set the XPoint by the offset sub-command (NULL to use xPnt or xPntBy2Lines)
                                              cvxPartPntByOffsetInit() can initialize this parameter */

                svxPntBy2Lines *xPntBy2Lines; /**<@brief  set the XPoint by the from 2 lines sub-command (NULL to use xPnt or xPntByOffset)
                                              cvxPartPntBy2LinesInit() can initialize this parameter */

                svxPoint yPnt;                /**<@brief  YPoint */
                svxPntByOffset *yPntByOffset; /**<@brief  set the YPoint by the offset sub-command (NULL to use yPnt or yPntBy2Lines)
                                              cvxPartPntByOffsetInit() can initialize this parameter */

                svxPntBy2Lines *yPntBy2Lines; /**<@brief  set the YPoint by the from 2 lines sub-command (NULL to use yPnt or yPntByOffset)
                                              cvxPartPntBy2LinesInit() can initialize this parameter */
            } threePnts;
            struct NewviewPlane /**<@brief  view plane :VX_NEW_PLANE_VIEW_PLANE */
            {
                svxPoint orgPnt;                /**<@brief  origin */
                svxPntByOffset *orgPntByOffset; /**<@brief  set the origin by the offset sub-command (NULL to use orgPnt or orgPntBy2Lines)
                                              cvxPartPntByOffsetInit() can initialize this parameter */

                svxPntBy2Lines *orgPntBy2Lines; /**<@brief  set the origin by the from 2 lines sub-command (NULL to use orgPnt or orgPntByOffset)
                                              cvxPartPntBy2LinesInit() can initialize this parameter */
            } view;
            struct NewPlaneDynamic /**<@brief  dynamic :VX_NEW_PLANE_DYNAMIC */
            {
                svxPoint posPnt;                /**<@brief  position */
                svxPntByOffset *posPntByOffset; /**<@brief  set the position point by the offset sub-command (NULL to use posPnt or PosPntBy2Lines)
                                              cvxPartPntByOffsetInit() can initialize this parameter */

                svxPntBy2Lines *posPntBy2Lines; /**<@brief  set the position point by the from 2 lines sub-command (NULL to use posPnt or PosPntByOffset)
                                              cvxPartPntBy2LinesInit() can initialize this parameter */
                svxVector xAxis;                /**<@brief  X Axis */
                svxVector yAxis;                /**<@brief  Y Axis */
                svxVector zAxis;                /**<@brief  Z Axis */
                int autoOrient;                 /**<@brief  1 if auto orientation, else 0 */
            } dynamic;
            struct NewPlaneOffset /**<@brief  offset plane :VX_NEW_PLANE_OFFSET_PLANE */
            {
                svxPoint orgPnt; /**<@brief  origin on "path" */
                svxEntPath path; /**<@brief  face path */
                double offset;   /**<@brief  offset */
            } pOffset;
            struct NewPlaneAngToFc /**<@brief  angle to face :VX_NEW_PLANE_ANGLE_FACE */
            {
                svxPoint orgPnt;     /**<@brief  origin on "path" */
                svxEntPath path;     /**<@brief  face path */
                svxPoint axis;       /**<@brief  point on line(or edge) */
                svxEntPath linePath; /**<@brief  line or edge path */
                double angle;        /**<@brief  angle (default: 45) */
            } angToFc;
            struct NewPlaneOnCurve /**<@brief  on curve :VX_NEW_PLANE_ON_CURVE */
            {
                svxPoint orgPnt;         /**<@brief  This variable is deprecated and can be ignored. This has no effect on the previous Settings. */
                svxEntPath path;         /**<@brief  Curve C path */
                int isPercent;           /**<@brief  1 if use percent, 2 if use distance */
                double num;              /**<@brief  if isPercent = 1, num is Percent; if isPercent = 2, num is distance. */
                evxOnCrvDirType dirType; /**<@brief  direction type */
                svxEntPath CrvPath;      /**<@brief  Curve path */
            } onCrv;
        } inpUnion;

        /* if "methods" = VX_NEW_PLANE_DYNAMIC, the following variables will not be applied. */
        int isFlipDir; /**<@brief  1 if flip direction, else 0   
                                              method = VX_NEW_PLANE_GEOMETRY, VX_NEW_PLANE_THREE_POINTS, VX_NEW_PLANE_ON_CURVE, VX_NEW_PLANE_VIEW_PLANE it means "Flip direction" option;   
                                              method = VX_NEW_PLANE_OFFSET_PLANE, VX_NEW_PLANE_ANGLE_FACE, it means "Flip the direction of face"
                                             */

        /* the follows can be set according to the requirements(Orientation) */
        double dOffset;   /**<@brief  offset */
        svxPoint *orgPnt; /**<@brief  origin (NULL to ignore) */
        svxPoint *xPoint; /**<@brief  X point (NULL to ignore) */
        double xAng;      /**<@brief  angle value X direction */
        double yAng;      /**<@brief  angle value Y direction */
        double zAng;      /**<@brief  angle value Z direction */
    } svxNewPlaneData;

    //====================================================================================================================
    /** @name Datum CSYS */
    //====================================================================================================================
    /**
    @brief CSYS Methods
    @ingroup zwapi_cmd_datum_data
    */
    typedef enum evxCSYSMethods
    {
        VX_CSYS_THREE_POINTS      = 1,  /**<@brief  three points */
        VX_CSYS_ONLY_MATRIX       = 6,  /**<@brief  only input CSYS matrix */
        VX_CSYS_DYNAMIC           = 7,  /**<@brief  dynamic */
        VX_CSYS_THREE_FACES       = 8,  /**<@brief  three faces */
        VX_CSYS_PNT_AND_TWO_DIR   = 9,  /**<@brief  point and two directions */
        VX_CSYS_PLANE_PNT_AND_DIR = 10, /**<@brief  plane point and direction */
        VX_CSYS_GEOMETRY          = 11, /**<@brief  geometry */
    } evxCSYSMethods;

    /**
    @brief Results axis
    @ingroup zwapi_cmd_datum_data
    */
    typedef enum evsResultsAxisMethod
    {
        VX_RESULTS_AXIS_X, /**<@brief  X direction */
        VX_RESULTS_AXIS_Y, /**<@brief  Y direction */
        VX_RESULTS_AXIS_Z, /**<@brief  Z direction */
    } evsResultsAxisMethod;

    /**
    @brief template command CSYS input data
    @ingroup zwapi_cmd_datum_data
    */
    typedef struct svxCSYSData
    {
        svxMatrix Frame;       /**<@brief  transformation matrix */
        evxCSYSMethods method; /**<@brief  CSYS methods */
        union evxCSYSInpUnion  /**<@brief  union of csys input data */
        {
            struct CSYSByGeom /**<@brief  geometry */
            {
                /* Use (cnt, OrgPnts, Paths) if input multiple entities */
                svxPoint OrgPnt; /**<@brief  Origin point */
                svxEntPath Path; /**<@brief  entity/object pick path */

                /* don't need to set OrgPnts and Paths if cnt = 0 or use OrgPnt and Path to set "Entities"
                 (suggest to use the following variables, OrgPnt and Path may be deprecated in the next version) */
                int cnt;           /**<@brief  count of OrgPnts and Paths. */
                svxPoint *OrgPnts; /**<@brief  origin points */
                svxEntPath *Paths; /**<@brief  entity/object pick paths */

                /* offset data when select a CSYS as input  */
                int offsetFirst; /**<@brief  0 is offset first,else 1.default:0 */
                double xOffset;  /**<@brief  x offset */
                double yOffset;  /**<@brief  y offset */
                double zOffset;  /**<@brief  z offset */

                /* the position of axes when select edges or faces */
                evsResultsAxisMethod firstAxis;  /**<@brief  1st axis(default:VX_RESULTS_AXIS_X) */
                evsResultsAxisMethod secondAxis; /**<@brief  2nd axis(default:VX_RESULTS_AXIS_Y). 1st axis and 2nd axis cannot be the same. */
            } byGeom;
            struct CSYSThreePnts /**<@brief  three points */
            {
                int idOrgPnt;                   /**<@brief  id of the origin parent entity */
                svxPoint OrgPnt;                /**<@brief  origin point */
                svxPntByOffset *OrgPntByOffset; /**<@brief  set the origin point by the offset sub-command (NULL to use (idOrgPnt, OrgPnt) or OrgPntByO2Lines)
                                           cvxPartPntByOffsetInit() can initialize this parameter */

                svxPntBy2Lines *OrgPntBy2Lines; /**<@brief  set the origin point by the from 2 lines sub-command (NULL to use (idOrgPnt, OrgPnt) or OrgPntByOffset)
                                           cvxPartPntBy2LinesInit() can initialize this parameter */

                int idPnt1;                   /**<@brief  id of the point1 parent entity */
                svxPoint Pnt1;                /**<@brief  point1 */
                svxPntByOffset *Pnt1ByOffset; /**<@brief  set the point1 by the offset sub-command (NULL to use (idPnt1, Pnt1) or Pnt1By2Lines)
                                           cvxPartPntByOffsetInit() can initialize this parameter */

                svxPntBy2Lines *Pnt1By2Lines;   /**<@brief  set the point2 by the from 2 lines sub-command (NULL to use (idPnt1, Pnt1) or Pnt1ByOffset)
                                           cvxPartPntBy2LinesInit() can initialize this parameter */
                evsResultsAxisMethod firstAxis; /**<@brief  1st axis(default:VX_RESULTS_AXIS_X) */
                int isFlip1;                    /**<@brief  1 is flip,else 0.default:0 */

                int idPnt2;                   /**<@brief  id of the point2 parent entity */
                svxPoint Pnt2;                /**<@brief  Point2 */
                svxPntByOffset *Pnt2ByOffset; /**<@brief  set the origin point by the offset sub-command (NULL to use (idPnt2, Pnt2) or Pnt2By2Lines)
                                           cvxPartPntByOffsetInit() can initialize this parameter */

                svxPntBy2Lines *Pnt2By2Lines;    /**<@brief  set the origin point by the from 2 lines sub-command (NULL to use (idPnt2, Pnt2) or Pnt2ByOffset)
                                           cvxPartPntBy2LinesInit() can initialize this parameter */
                evsResultsAxisMethod secondAxis; /**<@brief  2nd axis(default:VX_RESULTS_AXIS_Y). 1st axis and 2nd axis cannot be the same. */
                int isFlip2;                     /**<@brief  1 is flip,else 0.default:0 */
            } threePnts;
            struct CSYSThreeFaces /**<@brief  three faces */
            {
                svxEntPath Face1;           /**<@brief  face1 */
                evsResultsAxisMethod axis1; /**<@brief  axis1(default:VX_RESULTS_AXIS_X) */
                int isFlip1;                /**<@brief  1 is flip,else 0. default:0. */

                svxEntPath Face2;           /**<@brief  face2 */
                evsResultsAxisMethod axis2; /**<@brief  axis2(default:VX_RESULTS_AXIS_Y) */
                int isFlip2;                /**<@brief  1 is flip,else 0. default:0. */

                svxEntPath Face3;           /**<@brief  face3 */
                evsResultsAxisMethod axis3; /**<@brief  axis3(default:VX_RESULTS_AXIS_Z).The three axis cannot be the same. */
            } threeFaces;
            struct CSYSPntAnd2Dir /**<@brief  point and two directions */
            {
                /*  set origin point */
                int idOrgPnt;    /**<@brief  id of the origin parent entity */
                svxPoint OrgPnt; /**<@brief  origin point */

                svxPntByOffset *OrgPntByOffset; /**<@brief  set the origin point by the offset sub-command (NULL to use (idOrgPnt, OrgPnt) or OrgPntByO2Lines)
                                           cvxPartPntByOffsetInit() can initialize this parameter */

                svxPntBy2Lines *OrgPntBy2Lines; /**<@brief  set the origin point by the from 2 lines sub-command (NULL to use (idOrgPnt, OrgPnt) or OrgPntByOffset)
                                           cvxPartPntBy2LinesInit() can initialize this parameter */
                /* set first direction */
                svxVector Dir1;             /**<@brief  direction1, can use "DirOnEnt1" to set the direction1 on the specified entity and flip the direction, Dir1 can be deprecated and can be ignored*/
                svxPntOnEnt DirOnEnt1;      /**<@brief  direction1."DirOnEnt1.useDir" has to be equal to 1."DirOnEnt1.flipDir" can be set to reverse. */
                evsResultsAxisMethod axis1; /**<@brief  axis1(default:VX_RESULTS_AXIS_X) */

                /*  set second direction */
                svxVector Dir2;             /**<@brief  direction2, can use "DirOnEnt2" to set the direction2 on the specified entity and flip the direction, Dir2 can be deprecated and can be ignored*/
                svxPntOnEnt DirOnEnt2;      /**<@brief  direction2."DirOnEnt2.useDir" has to be equal to 1."DirOnEnt2.flipDir" can be set to reverse. */
                evsResultsAxisMethod axis2; /**<@brief  axis2(default:VX_RESULTS_AXIS_Y).The two axis cannot be the same. */
            } pntAnd2Dir;
            struct CSYSPlanAndDir /**<@brief  Plane and direction */
            {
                svxEntPath Face;             /**<@brief  face */
                evsResultsAxisMethod axisFc; /**<@brief  axis(default:VX_RESULTS_AXIS_Z) */
                int isFlipFc;                /**<@brief  1 is flip,else 0.default:0 */
                int idPnt;                   /**<@brief  id of the point parent entity */
                svxPoint Pnt;                /**<@brief  point */
                svxPntByOffset *PntByOffset; /**<@brief  set the point by the offset sub-command (NULL to use (idPnt, Pnt) or PntBy2Lines)
                                           cvxPartPntByOffsetInit() can initialize this parameter */

                svxPntBy2Lines *PntBy2Lines;  /**<@brief  set the point by the offset sub-command (NULL to use (idOrgPnt, OrgPnt) or PntByOffset)
                                           cvxPartPntBy2LinesInit() can initialize this parameter */
                svxVector Dir;                /**<@brief  direction, can use "DirOnEnt" to set the direction on the specified entity and flip the direction, Dir can be deprecated and can be ignored*/
                svxPntOnEnt DirOnEnt;         /**<@brief  direction."DirOnEnt.useDir" has to be equal to 1."DirOnEnt.flipDir" can be set to reverse. */
                evsResultsAxisMethod axisDir; /**<@brief  axis(default:VX_RESULTS_AXIS_X).The two axis cannot be the same. */
            } PlanAndDir;
            struct CSYSDynamic /**<@brief  dynamic */
            {
                int idPosPnt;                   /**<@brief  id of the position parent entity */
                svxPoint PosPnt;                /**<@brief  position point*/
                svxPntByOffset *PosPntByOffset; /**<@brief  set the position point by the offset sub-command (NULL to use (idPosPnt, PosPnt) or PosPntBy2Lines)
                                           cvxPartPntByOffsetInit can initialize this parameter */

                svxPntBy2Lines *PosPntBy2Lines; /**<@brief  set the position point by the offset sub-command (NULL to use (idPosPnt, PosPnt) or PosPntByOffset)
                                           cvxPartPntBy2LinesInit can initialize this parameter */
                svxVector Xaxis;                /**<@brief  A axis */
                svxVector Yaxis;                /**<@brief  Y axis */
                svxVector Zaxis;                /**<@brief  Z axis */
                int isAutoOrint;                /**<@brief  1 is auto orientation,else 0.default:1 */
            } dynamic;
        } inpUnion;

        /*  the follows can be set according to the requirements(Orientation) */
        double dOffset;  /**<@brief  offset value */
        int idOrgPnt;    /**<@brief  id of the origin parent entity */
        svxPoint OrgPnt; /**<@brief  origin */
        int idXPnt;      /**<@brief  id of the XPoint parent entity */
        svxPoint XPnt;   /**<@brief  XPoint */
        double XAng;     /**<@brief  angle value X direction */
        double YAng;     /**<@brief  angle value Y direction */
        double ZAng;     /**<@brief  angle value Z direction */
    } svxCSYSData;

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_DATUM_DATA_H */
