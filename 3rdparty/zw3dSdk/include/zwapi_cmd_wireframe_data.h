/**
@file zwapi_cmd_wireframe_data.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the Wireframe
Command functions.
*/
/**
@defgroup zwapi_cmd_wireframe_data Wireframe Commands Data
@ingroup PartandAssemblyCommands
@brief
@details THE MODULE FOR THE ZW3D Data Types and Structures of the Wireframe
Command functions.
*/

#pragma once
#ifndef ZW_API_WIREFRAME_FTR_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_WIREFRAME_FTR_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Wireframe Feature Data */
    //====================================================================================================================
    /**
    @brief 3D line type
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef enum evxLineType
    {
        VX_LINE_2PT       = 0, /**<@brief  create a line between two points */
        VX_LINE_ALONG_DIR = 1, /**<@brief  create a line in the same direction as the reference by start point and length */
        VX_LINE_PARALLEL  = 2, /**<@brief  create a line parallel to the reference direction by point and length */
        VX_LINE_PERP      = 3, /**<@brief  create a line between two points and perpendicular to the reference direction */
        VX_LINE_ANGLE     = 4, /**<@brief  create a line between two points and at an angle to the reference direction */
        VX_LINE_MIDDDLE   = 5, /**<@brief  create a line by conforming the middle point and a end point */
    } evxLineType;

    /**
    @brief 3D line data
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef struct svxLineData
    {
        evxLineType lineType;   /**<@brief  type to create line */
        svxDirOnEntPath refDir; /*!<@brief  reference direction, used when type is VX_LINE_ALONG_DIR, VX_LINE_PARALLEL, VX_LINE_PERP, VX_LINE_ANGLE */
        svxPntOnEntPath point1; /*!<@brief  start point or middle point */
        svxPntOnEntPath point2; /*!<@brief  the end point, used when type is VX_LINE_2PT, VX_LINE_PERP, VX_LINE_ANGLE, VX_LINE_MIDDDLE */
        double length;          /**<@brief  length of line, used when type is VX_LINE_ALONG_DIR, VX_LINE_PARALLEL */
        double offset;          /**<@brief  offset distance from the reference direction, used when type is VX_LINE_PARALLEL */
        double angle;           /**<@brief  angle from the reference direction, used when type is VX_LINE_ANGLE */

        int idAlignPln; /**<@brief  id of the alignment datum plane or planar face(0 to ignore), used when type is VX_LINE_2PT, VX_LINE_MIDDDLE */
        int prjToPln;   /**<@brief  whether to project line to alignment plane, used when type is VX_LINE_2PT, VX_LINE_MIDDDLE */
    } svxLineData;

    /**
    @brief 3D arc type
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef enum evxArcType
    {
        VX_ARC_THROUGH = 0, /**<@brief  create an arc by defining its two endpoints and a third point that arc passes through */
        VX_ARC_RADIUS  = 1, /**<@brief  create an arc by defining its two endpoints and radius */
        VX_ARC_CENTER  = 2, /**<@brief  create an arc by defining its center and two endpoints */
        VX_ARC_ANGLE   = 3, /**<@brief  create an arc by defining its center, radius, start angle and arc angle */
    } evxArcType;

    /**
    @brief 3D arc data
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef struct svxArcData
    {
        evxArcType arcType;        /**<@brief  type to create an arc */
        svxPntOnEntPath startPnt;  /*!<@brief  start point of arc, used when type isn't VX_ARC_ANGLE */
        svxPntOnEntPath endPnt;    /*!<@brief  end point of arc, used when type isn't VX_ARC_ANGLE */
        svxPntOnEntPath centerPnt; /*!<@brief  through point or center point of arc, used when type is VX_ARC_THROUGH or VX_ARC_CENTER */
        double radius;             /**<@brief  radius of arc, used when type is VX_ARC_RADIUS */
        double startAngle;         /**<@brief  start angle of arc (deg), used when type is VX_ARC_ANGLE */
        double arcAngle;           /**<@brief  angle of arc (deg), used when type is VX_ARC_ANGLE */

        int idAlignPln;            /**<@brief  id of the alignment datum plane or planar face(0 to ignore) */
        int prjToPln;              /**<@brief  whether to project arc to alignment plane */
        int arcDir;                /**<@brief  indicate the direction for angular input (0: counter; 1: clockwise), used when type is VX_ARC_CENTER or VX_ARC_CENTER */
        svxPntOnEntPath *location; /*!<@brief  indicate arc, used when type is VX_ARC_RADIUS */
    } svxArcData;

    /**
    @brief 3D circle type
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef enum evxCircleType
    {
        VX_CIRCLE_BOUNDARY   = 1, /**<@brief  create a circle by defining its center and a boundary point */
        VX_CIRCLE_RADIUS     = 2, /**<@brief  create a circle by defining its center and radius or diameter */
        VX_CIRCLE_THROUGH    = 0, /**<@brief  create a circle by defining 3 boundary points */
        VX_CIRCLE_2PT_RADIUS = 3, /**<@brief  create a circle by defining 2 boundary points and radius */
        VX_CIRCLE_2POINT     = 4, /**<@brief  create a circle by defining 2 boundary points */
    } evxCircleType;

    /**
    @brief 3D circle data
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef struct svxCircleData
    {
        evxCircleType type;         /**<@brief  type to create a circle */
        svxPntOnEntPath centerPnt;  /*!<@brief  center point of circle, used when type is VX_CIRCLE_BOUNDARY or VX_CIRCLE_RADIUS */
        svxPntOnEntPath bndPnts[3]; /*!<@brief  boundary points of circle, fill the array with the number of bounding points required by type */
        int useDiameter;            /**<@brief  indicate radius or diameter (0: radius; 1: diameter), used when type is VX_CIRCLE_RADIUS */
        double radOrDia;            /**<@brief  radius or diameter of circle, used when type is VX_CIRCLE_RADIUS or VX_CIRCLE_2PT_RADIUS */

        int idAlignPln;            /**<@brief  id of the alignment datum plane or planar face(0 to ignore) */
        int prjToPln;              /**<@brief  whether to project circle to alignment plane */
        svxPntOnEntPath *location; /*!<@brief  indicate circle, used when type is VX_CIRCLE_2PT_RADIUS */
    } svxCircleData;

    /**
    @brief 3D polyline data
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef struct svxPolylineData
    {
        int numPoint;         /**<@brief  number of points to construct polyline */
        svxPntOnEnt *pPoints; /**<@brief  pointer to list of points to construct polyline */
        int idAligPln;        /**<@brief  id of Align plane, -1 as default*/
        int projectToPln;     /**<@brief  1-project to the align plane, else 0 (1 as default) */
        int pntOnPln;         /**<@brief  1-points on align plane, else 0 (0 as default) */
    } svxPolylineData;

    /**
    @brief 3D ellipse & rectangle type
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef enum evxRectangleType
    {
        VX_RECT_2PT          = 0, /**<@brief  two points */
        VX_RECT_WIDTH_HEIGHT = 1, /**<@brief  width and height */
        VX_RECT_3PT          = 2  /**<@brief  three points */
    } evxRectangleType;

    /**
    @brief 3D ellipse & rectangle data
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef struct svxRectangleData
    {
        /*  required inputs */
        evxRectangleType type; /**<@brief  type to make rectangle */
        int idPlane;           /**<@brief  not required if "type" is VX_RECT_3PT */
        int firstPtType;       /**<@brief  type of 1st input point (0 corner, 1 center) */
        svxPoint pts[3];       /**<@brief  3 input points depend on "type" */
        double width;          /**<@brief  width if "type" is VX_RECT_WIDTH_HEIGHT */
        double height;         /**<@brief  height if "type" is VX_RECT_WIDTH_HEIGHT */

        /*  optional inputs */
        double angle;      /**<@brief  rotation angle */
        int prjFirstPt;    /**<@brief  1 to project first point to plane, 0 not */
        int parallelogram; /**<@brief  0 rectangle, 1 parallelogram */
    } svxRectangleData;

    //====================================================================================================================
    /** @name Curve Data */
    //====================================================================================================================
    /**
    @brief project to face data
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef struct svxCrvProjToFace
    {
        int cntCrvs;     /**<@brief  count of curves */
        int *pCrvs;      /**<@brief  a sketch or curves */
        int cntFaces;    /**<@brief  count of faces */
        int *pFaces;     /**<@brief  faces or datum planes to project curves onto */
        svxVector *pDir; /**<@brief  By default, the projection direction is normal to the surface. Use this
                                 option to define a different direction to project onto the surface. (NULL
                                 to ignore) */
        int biDir;       /**<@brief  Use this option to project the curves in both the positive and the negative
                                 directions relative to the direction of projection. */
        int trim;        /**<@brief  Use this option to project only to the trim boundaries of a face. If you
                                 are projecting onto a trimmed face, set it to 0 will produce a curve that extends
                                 to the entire untrimmed boundary of the face, else set it to 1 (1 as default)*/
    } svxCrvProjToFace;

    /**
    @brief inter curve
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef struct svxInterCrvData
    {
        int iEntCout1; /**<@brief  The number of faces selected for the first field */
        int iEntCout2; /**<@brief  The number of faces selected for the second field */
        int *idEnt1;   /**<@brief  Select all face ids for the first field */
        int *idEnt2;   /**<@brief  Select all face ids for the second field */
        int trim;      /**<@brief  1 to trim intersection curves to face boundaries; 0 does not not trim the curve, 1 default*/
    } svxInterCrvData;


    /**
    @brief curve on face through points constraint
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef struct svxCrvOnFaceThuPtsCons
    {
        evxContinuityTyp continuity; /**<@brief  continuity method used for creating curves, between
                                                VX_CONTIN_NONE and VX_CONTIN_G2 (VX_CONTIN_NONE as default) */
        svxVector tan;               /**<@brief  tangent direction for the start or end of the curve */
        int flip;                    /**<@brief  whether to reverse the tangent direction */
        double weight;               /**<@brief  tangent weight if an tangent direction is specified, between 0.1 and 10 */
    } svxCrvOnFaceThuPtsCons;

    /**
    @brief curve on face through points data
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef struct svxCrvOnFaceThuPts
    {
        int face;                          /**<@brief  face to create the curve on */
        int cntPts;                        /**<@brief  number of points */
        svxPoint *pts;                     /**<@brief  points on the face for the curve to pass through */
        int isOpen;                        /**<@brief  whether to create open curve, 1 as default */
        evxFairingType fairing;            /**<@brief  fairing mode, VX_FAIRING_NONE as default */
        svxCrvOnFaceThuPtsCons *startCons; /**<@brief  start constraints (NULL to ignore) */
        svxCrvOnFaceThuPtsCons *endCons;   /**<@brief  end constraints (NULL to ignore) */
    } svxCrvOnFaceThuPts;

    /**
    @brief iso-curve type
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef enum evxCrvIsoType
    {
        VX_CRV_ISO_AT_POINT = 0, /**<@brief  at point */
        VX_CRV_ISO_AT_UV    = 1, /**<@brief  ar U/V parameter */
        VX_CRV_ISO_MULTIPLE = 2, /**<@brief  multiple */
    } evxCrvIsoType;

    /**
    @brief iso-curve U or V settings
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef enum evxCrvIsoUVType
    {
        VX_CRV_ISO_UV_U    = 0, /**<@brief  U-isoline */
        VX_CRV_ISO_UV_V    = 1, /**<@brief  V-isoline */
        VX_CRV_ISO_UV_BOTH = 2, /**<@brief  both */
    } evxCrvIsoUVType;

    /**
    @brief iso-curve on face data
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef struct svxIsoCrvOnFaceData
    {
        evxCrvIsoType crvIsoType; /**<@brief  iso-curve on face methods */
        int face;                 /**<@brief  face from which the U and V curves will be extracted */
        union uvxCrvIsoData
        {
            struct svxCrvIsoAtPoint
            {
                svxPoint point;       /**<@brief  a point on the face for the iso-curve to pass through  */
                evxCrvIsoUVType type; /**<@brief  to create only the U, the V or create both iso-curves. VX_CRV_ISO_UV_BOTH as default */
            } atPoint;
            struct svxCrvIsoAtUVParam
            {
                double U;             /**<@brief  U parameter where the iso-curve(s) will be located */
                double V;             /**<@brief  V parameter where the iso-curve(s) will be located */
                evxCrvIsoUVType type; /**<@brief  to create only the U, the V or create both iso-curves. VX_CRV_ISO_UV_BOTH as default */
            } UVParam;
            struct svxCrvIsoMultiple
            {
                int numU;       /**<@brief  number of U iso-curves */
                int numV;       /**<@brief  number of V iso-curves */
                double offsetU; /**<@brief  place the U iso-curves at an offset distance from their default location */
                double offsetV; /**<@brief  place the V iso-curves at an offset distance from their default location */
            } multiple;
        } inpUion;
    } svxIsoCrvOnFaceData;

    /**
    @brief create isocline curve with a single angle/multiple angles
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef enum evxIsoclineCrvType
    {
        VX_CRV_ISOCLINE_SINGLE   = 0, /**<@brief  single angle */
        VX_CRV_ISOCLINE_MULTIPLE = 1, /**<@brief  multiple angles */
    } evxIsoclineCrvType;

    /**
    @brief isocline curve data
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef struct svxIsoclineCrvData
    {
        int *idFaces;               /**<@brief  id of faces to create isocline curves */
        int cntFaces;               /**<@brief  number of faces to create isocline curves */
        svxVector direction;        /**<@brief  reference direction */
        evxIsoclineCrvType crvType; /**<@brief  isocline curve's creation type, VX_CRV_ISOCLINE_SINGLE as default */
        union uvxCrvIsoclineData
        {
            struct svxIsoclineCrvSingle
            {
                double angle; /**<@brief  angle between the reference direction and the face normal (between -90 to 90) */
            } single;         /**<@brief  create isocline curve with a single angle */
            struct svxIsoclineCrvMultiple
            {
                double interval; /**<@brief  angle between the isocline (between 0.01 to 90) */
                double start;    /**<@brief  start angle between the reference direction and the face normal (between -90 to 90) */
                double end;      /**<@brief  end angle between the reference direction and the face normal (between -90 to 90) */
            } multiple;          /**<@brief  create isocline curves with multiple angles */
        } inpUion;
    } svxIsoclineCrvData;

    /**
    @brief face curve data
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef struct svxFaceCrvData
    {
        int method;      /**<@brief  create face curves method (0-from edges, 1-from projected curves) */
        int cntFaces;    /**<@brief  count of faces on which to create the face curves */
        int *pFaces;     /**<@brief  index of faces on which to create the face curves */
        int partingLine; /**<@brief  1 to add the selected Edges as parting line, else 0 */
        union uvxFaceCrvData
        {
            struct uvxFromEdges
            {
                int cntEdge; /**<@brief  count of edges */
                int *pEdge;  /**<@brief  If this field is empty, face curves are created surrounding the region
                                       formed by the selected faces. If you pick specific edges for this field,
                                       face curves are created only from those selected edges, but a selected edge
                                       will be ignored if it is not adjacent to one of the selected faces, or if
                                       it is adjacent to several selected faces. */
                int seam;    /**<@brief  1 to create face curves along seam edges, 0 to ignore */
            } fromEdge;      /**<@brief  create face curves from edges data */
            struct uvxFromProjCrv
            {
                int cntCrv;     /**<@brief  count of curves */
                int *pCrv;      /**<@brief  curves, sketches, curve lists and edges to project onto the selected faces */
                svxVector *dir; /**<@brief  direction curves are projected onto (NULL to projected in the direction of
                                       minimum distance from the curve to that face) */
            } fromProjCrv;      /**<@brief  create face curves from projected curves data */
        } inpUion;
    } svxFaceCrvData;

    /**
    @brief combined projection data
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef struct svxCrvCombinedProjData
    {
        int firstCrv;        /**<@brief  the first curve to project */
        svxVector firstDir;  /**<@brief  the projection direction for the 1st curve */
        int secondCrv;       /**<@brief  the second curve to project */
        svxVector secondDir; /**<@brief  the projection direction for the 2nd curve */
    } svxCrvCombinedProjData;
    /**
    @brief trim (or extend) curves type of curve blend
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef enum evxCrvBlendTrimType
    {
        VX_CURVE_BLEND_NO_TRIM     = 0, /**<@brief  Add the fillet or chamfer without modifying the existing curves.  No trim/extend is performed. */
        VX_CURVE_BLEND_TRIM_BOTH   = 1, /**<@brief  Trim/Extend both curves.  */
        VX_CURVE_BLEND_TRIM_FIRST  = 2, /**<@brief  Trim/Extend only the first selected curve. */
        VX_CURVE_BLEND_TRIM_SECOND = 3, /**<@brief  Trim/extend only the second selected curve. */
    } evxCrvBlendTrimType;

    /**
    @brief blend location type for curve to blend
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef enum evxCrvBlendPosType
    {
        VX_CURVE_BLEND_POS_ARC_LENGTH         = 0, /**<@brief  location to blend is defined by arc length */
        VX_CURVE_BLEND_POS_PERCENT_ARC_LENGTH = 1, /**<@brief  location to blend is defined by % of arc length */
        VX_CURVE_BLEND_POS_THROUGH_POINT      = 2, /**<@brief  Picking a pick on curve as the blend location */
    } evxCrvBlendPosType;

    /**
    @brief blend location type for face to blend
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef enum evxCrvBlendDirType
    {
        VX_CURVE_BLEND_DIR_SECTIONAL = 0, /**<@brief  An angle relative to ISO U is defined to set up blend direction */
        VX_CURVE_BLEND_DIR_ISO_U     = 1, /**<@brief  ISO U works as the blend direction and a % of iso u can defined to settle the blend location */
        VX_CURVE_BLEND_DIR_ISO_V     = 2, /**<@brief  ISO V works as the blend direction and a % of iso v can defined to settle the blend location */
    } evxCrvBlendDirType;

    /**
    @brief curve blend constraints
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef struct svxCrvBlendCons
    {
        evxContinuityTyp continuity; /**<@brief  continuity method used for refitting and blending the curves, VX_CONTIN_G1 as default */
        int tangentDirFlip;          /**<@brief  1 to flip tangent direction, else 0 */
        double weight;               /**<@brief  the weight factor, between 0.10 and 5.00 */
        union uvxCrvBlendCons
        {
            struct svxCrvBlendCrv
            {
                evxCrvBlendPosType pos;     /**<@brief  define specific location to blend, VX_CURVE_BLEND_POS_THROUGH_POINT as default */
                int keepside;               /**<@brief  0-long, 1-short */
                double value;               /**<@brief  arc length for VX_CURVE_BLEND_POS_ARC_LENGTH, or percentage
                                    of arc length for VX_CURVE_BLEND_POS_PERCENT_ARC_LENGTH */
                svxPntOnEntPath throughPnt; /*!<@brief  pick a point on curve as the blend location, for VX_CURVE_BLEND_POS_THROUGH_POINT */
            } crv;
            struct svxCrvBlendFace
            {
                evxCrvBlendDirType blendDir; /**<@brief  define specific location to blend. VX_CURVE_BLEND_DIR_ISO_U as default */
                double value;                /**<@brief  percentage or angle */
            } face;
        } inpUion;
    } svxCrvBlendCons;

    /**
    @brief select a curve or face as object to start/end blended
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef enum evxCrvBlendObjType
    {
        VX_CURVE_BLEND_CURVE = 0, /**<@brief  curve */
        VX_CURVE_BLEND_FACE  = 1, /**<@brief  face */
    } evxCrvBlendObjType;

    /**
    @brief curve blend data
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef struct svxCrvBlendData
    {
        evxCrvBlendObjType startObjType; /**<@brief  start object type, VX_CURVE_BLEND_CURVE as default */
        svxPntOnEntPath startObj;        /*!<@brief  start object */
        int startObjFlip;                /**<@brief  1 to flip start object position, else 0 */
        evxCrvBlendObjType endObjType;   /**<@brief  end object type, VX_CURVE_BLEND_CURVE as default */
        svxPntOnEntPath endObj;          /*!<@brief  end object */
        int endObjFlip;                  /**<@brief  1 to flip end object position, else 0 */

        evxCrvBlendTrimType trim; /**<@brief  trim type, VX_CURVE_BLEND_TRIM_BOTH as default */
        int curvature;            /**<@brief  1 to display curvature, else 0 */
        int endpointPick;         /**<@brief  1 to pick endpoint by default, else 0. 1 as default */

        svxCrvBlendCons *startCons; /**<@brief  start constraints (NULL to ignore) */
        svxCrvBlendCons *endCons;   /**<@brief  end constraints (NULL to ignore) */
    } svxCrvBlendData;

    /**
    @brief spiral curve data
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef struct svxSpiralCrvData
    {
        svxPoint startPnt;  /**<@brief  the start point */
        svxVector axis;     /**<@brief  the spiral axis, it can be the coordinate axis, line or point */
        double turns;       /**<@brief  the number of turns */
        double offset;      /**<@brief  the value the turn offset, that is the distance between two turns. A positive
                                       value indicates an external offset. A negative value indicates an internal offset. */
        int revolve;        /**<@brief  1 to revolve the curve clockwise about the specified axis, else revolve the curve
                                       anti-clockwise.  */
        svxVector *pRefDir; /**<@brief  the reference direction for spiral curve (NULL to ignore) */
        double ang;         /**<@brief  the angle of spiral curve */
    } svxSpiralCrvData;

    //====================================================================================================================
    /** @name Edit Curve Data */
    //====================================================================================================================

    /**
    @brief curve trim type
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef enum evxCrvTrimType
    {
        VX_CRV_TRIM_NONE   = 0, /**<@brief  no trim */
        VX_CRV_TRIM_BOTH   = 1, /**<@brief  trim both curves */
        VX_CRV_TRIM_FIRST  = 2, /**<@brief  trim only the first curves */
        VX_CRV_TRIM_SECOND = 3, /**<@brief  trim only the second curves */
    } evxCrvTrimType;

    /**
    @brief curve fillet method
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef enum evxCrvFilletMethods
    {
        VX_CRV_FILLET_RADIUS   = 0, /**<@brief  radius */
        VX_CRV_FILLET_BOUNDARY = 1, /**<@brief  boundary */
    } evxCrvFilletMethods;

    /**
    @brief curve fillet data
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef struct svxCrvFilletData
    {
        evxCrvFilletMethods method; /**<@brief  method to create a fillet (VX_CRV_FILLET_RADIUS as default) */
        svxPntOnEntPath firstPnt;   /*!<@brief  the first curve to fillet */
        svxPntOnEntPath secondPnt;  /*!<@brief  the second curve to fillet */
        union evxCrvFilletInpUnion
        {
            double radius;              /**<@brief  radius to fillet if method is VX_CRV_FILLET_RADIUS */
            svxPntOnEntPath settingPnt; /*!<@brief  point between the two picked curves to create a full fillet if method is VX_CRV_FILLET_BOUNDARY */
        } inpUnion;
        evxCrvTrimType trimType;    /**<@brief  curve trim type (VX_CRV_TRIM_BOTH as default) */
        evxExtendOpt extensionType; /**<@brief  extension type (VX_EXTEND_LINEAR as default) */
        int designerArc;            /**<@brief  whether to use designer arc (0 as default) */
    } svxCrvFilletData;

    /**
    @brief curve fillet chain data
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef struct svxCrvFilletChainData
    {
        int count;        /**<@brief  count of curves */
        int *curves;      /**<@brief  list ids of curves */
        double radius;    /**<@brief  radius to fillet */
        int designerArc;  /**<@brief  whether to use designer arc (0 as default) */
        int trimOriginal; /**<@brief  whether to trim original curves (1 as default) */
    } svxCrvFilletChainData;

    /**
    @brief curve chamfer method
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef enum evxCrvChamferMethods
    {
        VX_CRV_CHAMFER_SETBACK           = 0, /**<@brief  setback */
        VX_CRV_CHAMFER_TWO_SETBACKS      = 1, /**<@brief  two setbacks */
        VX_CRV_CHAMFER_SETBACK_AND_ANGLE = 2, /**<@brief  setback and angle */
    } evxCrvChamferMethods;

    /**
    @brief curve chamfer data
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef struct svxCrvChamferData
    {
        evxCrvChamferMethods method; /**<@brief  method to create a chamfer (VX_CRV_CHAMFER_SETBACK as default) */
        svxPntOnEntPath firstPnt;    /*!<@brief  the first curve to chamfer */
        svxPntOnEntPath secondPnt;   /*!<@brief  the second curve to chamfer */
        union evxCrvChamferInpUnion
        {
            double setback; /**<@brief  setback is a straight line distance between the vertex and the new setback point */

            struct CrvChamferTwoSetbacks
            {
                double firstSetback;  /**<@brief  the first setback */
                double secondSetback; /**<@brief  the second setback */
            } twoSetbacks;

            struct CrvChamferSetbackAndAngle
            {
                double setback; /**<@brief  the first setback */
                double angle;   /**<@brief  angle of the first curve */
            } setbackAndAngle;
        } inpUnion;
        evxCrvTrimType trimType;    /**<@brief  trim type (VX_CRV_TRIM_BOTH as default) */
        evxExtendOpt extensionType; /**<@brief  extension type (VX_EXTEND_CIRCULAR as default) */
    } svxCrvChamferData;

    /**
    @brief chamfer chain data
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef struct svxCrvChamferChainData
    {
        int cnt;          /**<@brief  number of edges/curves to chamfer */
        int *curves;      /**<@brief  I: pointer to list of edge/curve id's */
        double setback;   /**<@brief  setback (mm) */
        int trimOriginal; /**<@brief  1 to trim original curves, else 0. 1 as default */
    } svxCrvChamferChainData;

    /**
    @brief trim with curve mode
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef enum evxTrimWithCrvType
    {
        VX_TRIM_WITH_CRV_KEEP   = 0, /**<@brief  The segment of the trimmed curves selected will be kept. */
        VX_TRIM_WITH_CRV_DELETE = 1, /**<@brief  The segment of the trimmed curves selected will be deleted. */
        VX_TRIM_WITH_CRV_SPLIT  = 2, /**<@brief  The trimmed curves will be split at the boundary curves (or point). */
    } evxTrimWithCrvType;

    /**
    @brief trim with curve data
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef struct svxTrimWithCrvData
    {
        int cntCrvs;                 /**<@brief  number of curves */
        int *pCrvs;                  /**<@brief  curves to use as boundaries */
        int cntDelSeg;               /**<@brief  number of curve segments */
        svxPntOnEntPath *pDelSeg;    /**<@brief  curve segments where you want them to be trimmed away */
        evxTrimWithCrvType trimMode; /**<@brief  trim mode */
        svxPntOnEntPath *pPln;       /*!<@brief  Use this option to trim non-intersection 3D curves. You can project
                                             the curves onto a plane and determine the intersection. The intersection
                                             points are then projected back to the trimming curves.    
                                             If you do not
                                             select a plane, then the minimum distance between the curves is used for
                                             the trimming points. (NULL to ignore) */
    } svxTrimWithCrvData;

    /**
    @brief trim to faces data
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef struct svxCrvTrimToFacesData
    {
        int cntCrvs;  /**<@brief  count of curves or sketches to trim */
        int *pCrvs;   /**<@brief  index of curves or sketches to trim */
        int cntFaces; /**<@brief  count of the trimming faces or shapes */
        int *pFaces;  /**<@brief  index of the trimming faces or shapes */
        int flip;     /**<@brief  1 to flip the arrows to keep the opposite side, else 0 */
    } svxCrvTrimToFacesData;

    /**
    @brief create arc and line segments from existing curves data 
    @ingroup zwapi_cmd_wireframe_data
    */
    typedef struct svxCrvConvertTocData
    {
        int cntCrvs;      /**<@brief  count of curves to convert */
        int *idCrvs;      /**<@brief  id of curves to convert */
        double tolerance; /**<@brief  allowable tolerance for the conversion (0.5 as default) */
        int keep;         /**<@brief  1 to keep original curves, else 0 (0 as default) */
    } svxCrvConvertTocData;
/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_WIREFRAME_FTR_DATA_H */
