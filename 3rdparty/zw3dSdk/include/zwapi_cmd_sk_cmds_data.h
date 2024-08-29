/**
@file zwapi_cmd_sk_cmds_data.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the All
Commands of Sketch functions.
*/
/**
@defgroup zwapi_cmd_sk_cmds_data Sketch Commands Data
@ingroup SketchCommands
@brief
@details THE MODULE FOR THE ZW3D Data Types and Structures of the All
Commands of Sketch functions.
*/

#pragma once
#ifndef ZW_API_SK_CMD_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_SK_CMD_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Drawing Data */
    //====================================================================================================================
    /**
    @brief Create Sketch Axis Methods
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef enum evxSkAxisMethods
    {
        VX_SK_AXIS_TWO_PNT       = 0, /**<@brief  Two Point */
        VX_SK_AXIS_PARAPT        = 1, /**<@brief  Parallel and a pin point */
        VX_SK_AXIS_PERPENDICULAR = 2, /**<@brief  Perpendicular and a pin point */
        VX_SK_AXIS_ANGLE         = 3, /**<@brief  Angle */
        VX_SK_AXIS_PARAOFF       = 4, /**<@brief  Parallel and Offset */
        VX_SK_AXIS_HORIZ         = 5, /**<@brief  Horizontal */
        VX_SK_AXIS_VERT          = 6, /**<@brief  Vertical */
    } evxSkAxisMethods;

    /**
    @brief data of sketch Axis
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef struct svxSkAxisData
    {
        evxSkAxisMethods Method;    /**<@brief  Sketch Axis Methods */
        int idEnt1;                 /**<@brief  id of the First Point parent entity(0 to ignore) */
        svxPoint2 Pnt1;             /**<@brief  first Point.   
                                       if type = VX_SK_AXIS_TWO_PNT, the axis is through Pnt1 and Pnt2.   
                                       if type = VX_SK_AXIS_PARAPT, the axis is the line parallel to reference line and through Pnt1.   
                                       if type = VX_SK_AXIS_ANGLE, the axis is the line vertical to reference line and through Pnt1.   
                                       if type = VX_SK_AXIS_PARAOFF, the axis and the reference line form angle Angle, and the axis through Pnt1.   
                                       if type = VX_SK_AXIS_HORIZ, the axis is parallel to x-axis and through Pnt1.   
                                       if type = VX_SK_AXIS_VERT, the axis is vertical to x-axis and through Pnt1.   
                                       if type = VX_SK_AXIS_PERPENDICULAR, can be null. */
        int idRefEnt;               /**<@brief  id of the RefLine parent entity.
                                       if type = VX_SK_AXIS_PARAPT, the axis is the line parallel to reference line and through Pnt1.   
                                       if type = VX_SK_AXIS_ANGLE, the axis is the line vertical to reference line and through Pnt1.   
                                       if type = VX_SK_AXIS_PARAOFF, the axis and the reference line form angle Angle, and the axis through Pnt1.   
                                       other type can be null */
        svxPoint2 RefPnt;           /**<@brief  Ref Line point */
        union evxSkAxisMethodsUnion /**<@brief union of sketch axis data */
        {
            struct SkAxis2Pnt /**<@brief  Two Points */
            {
                int idEnt2;     /**<@brief  id of the Second Parent entity (0 to ignore) */
                svxPoint2 Pnt2; /**<@brief  second point.
                                       if type = VX_SK_AXIS_TWO_PNT, the axis is through Pnt1 and Pnt2.
                                       other type can be null */
            } axis2pnt;
            struct SkAxisParaOff /**<@brief  Parallel and Offset */
            {
                double Offset; /**<@brief  Offset.
                                       if type = VX_SK_AXIS_PARAOFF, the axis is parallel to reference line,
                                       and the distance between axis and reference line is Offset.
                                       other type can be null */
            } axisParaOff;
            struct SkAxisAngle /**<@brief  Angle */
            {
                double Angle; /**<@brief  Angle.
                                       if type = VX_SK_AXIS_ANGLE, it is the angle between axis and reference line.
                                       other type can be null */
            } axisAng;
        } inpUnion;
        int ConstGeom; /**<@brief  1-Construction Geometry, else 0 (1 as default)*/
    } svxSkAxisData;

    /**
    @brief data of ellipse
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef struct svxEllipse
    {
        svxPoint centroid;  /**<@brief  centroid of ellipse */
        double width;       /**<@brief  width of ellipse */
        double height;      /**<@brief  height of ellipse */
        double startAng;    /**<@brief  start angle of ellipse (deg - CCW from X axis).
                         the arc is the part of ellipse from start angle to end angle*/
        double endAng;      /**<@brief  end angle of ellipse (deg - CCW from the first decided axis of ellipse) */
        double rotationAng; /**<@brief  rotation angle of ellipse (deg - CCW from the first decided axis of ellipse) */
    } svxEllipse;

    /**
    @brief Create Sketch ready text Methods
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef enum evxReadyTextMethods
    {
        VX_ON_CRV = 1, /**<@brief  on curve text */
        VX_BOX    = 2, /**<@brief  box text */
    } evxReadyTextMethods;

    /**
    @brief data of ready sketch text
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef struct svxReadyText
    {
        char *text;      /**<@brief  text string */
        vxLongName font; /**<@brief  font name */
        double size;     /**<@brief  text height */
        int style;       /**<@brief  text style(1:Regular; 2:Italic; 3:Bold; 4.Bold Italic) */
        double spacing;  /**<@brief  character space */

        svxPoint origin; /**<@brief  text position */
        int flipY;       /**<@brief  Horizontal flip*/
        int mirror;      /**<@brief  Mirror */

        evxReadyTextMethods methods; /**<@brief  ready text methods */

        double WidthText;       /**<@brief  Text width*/
        double VerticalSpacing; /**<@brief  Vertical Spacing */

        union evxSkTextMethodsUnion /**<@brief union of sketch text data */
        {
            struct OnCrvText /**<@brief On curve text data */
            {
                int reverseCurve;   /**<@brief  Reverse curve */
                int placeTextAtOrg; /**<@brief  Place text at origin */
                int reduceTxtDat;   /**<@brief  Reduce text data */
                int KeepTextShape;  /**<@brief  Keep Text Shape */
                int idxCurve;       /**<@brief  curve index */
            } oncrvtext;
            struct BoxText /**<@brief box text data */
            {
                svxPoint AlignPoint;  /**<@brief  Align Point */
                double WidthSetting;  /**<@brief  Setting Width */
                double HeightSetting; /**<@brief  Setting Height */
            } boxtext;
        } methodsUnion;
    } svxReadyText;

    /**
    @brief sketch polygon method
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef enum evxSkNgonsType
    {
        VX_SK_NGONS_IN_R,       /**<@brief  inscribed radius */
        VX_SK_NGONS_CIR_R,      /**<@brief  circumscribed radius */
        VX_SK_NGONS_SIDE_LEN,   /**<@brief  side length */
        VX_SK_NGONS_IN_BOUND,   /**<@brief  inscribed boundary */
        VX_SK_NGONS_CIR_BOUND,  /**<@brief  circumscribed boundary */
        VX_SK_NGONS_SIDE_BOUND, /**<@brief  side boundary */
    } evxSkNgonsType;

    /**
    @brief sketch polygon data
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef struct svxSkNgons
    {
        evxSkNgonsType type; /**<@brief  polygon option */
        svxPoint2 center;    /**<@brief  the center point of polygon.
                                            if type != VX_SK_NGONS_SIDE_LEN, and type != VX_SK_NGONS_SIDE_BOUND, the point should be given.
                                            other type can be null */
        double R;            /**<@brief  the radius or length of polygon.default:10.   
                                            if type = VX_SK_NGONS_IN_R, it is radius of circle have inscribed polygon.   
                                            if type = VX_SK_NGONS_CIR_R, it is radius of circle have outer polygon.   
                                            if type = VX_SK_NGONS_SIDE_LEN, it is the length of polygon's sides.   
                                            other type can be null */
        int numSide;         /**<@brief  number of sides.default:6 */
        double angle;        /**<@brief  the rotate angle.default:0 */
        svxPoint2 corner;    /**<@brief  corner point of polygon.
                                            if type = VX_SK_NGONS_SIDE_LEN or VX_SK_NGONS_SIDE_BOUND, the point should be given.
                                            other type can be null */
        svxPoint2 boundary;  /**<@brief  boundary point of polygon .
                                            if type = VX_SK_NGONS_IN_BOUND or VX_SK_NGONS_SIDE_BOUND, the point is a vertex of polygon.   
                                            if type = VX_SK_NGONS_CIR_BOUND, the point is the midpoint of an side on polygon.   
                                            other type can be null */
    } svxSkNgons;

    /**
    @brief sketch reference geometry method
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef enum evxSkRefMethod
    {
        VX_SK_REF_PROJECTION,   /**<@brief  projection method */
        VX_SK_REF_INTERSECTION, /**<@brief  intersection method */
    } evxSkRefMethod;

    /**
    @brief sketch reference type
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef enum evxSkRefOption
    {
        VX_SK_REF_SINGLE, /**<@brief  single */
        VX_SK_REF_CHAIN,  /**<@brief  chain  */
        VX_SK_REF_LOOPS,  /**<@brief  loops  */
        VX_SK_REF_POINT,  /**<@brief  point  */
    } evxSkRefOption;

    /**
    @brief sketch reference chain option
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef enum evxSkChainOption
    {
        VX_SK_CHAIN_PICK,          /**<@brief  chain pick */
        VX_SK_CHAIN_BETWEEN_PICKS, /**<@brief  chain between picks */
    } evxSkChainOption;

    /**
    @brief sketch reference loop option
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef enum evxSkLoopOption
    {
        VX_SK_LOOP_ALL,                 /**<@brief  all loops of surface */
        VX_SK_LOOP_BOUNDARY,            /**<@brief  boundary of surface */
        VX_SK_LOOP_SHARED,              /**<@brief  shared edges between multiple surfaces */
        VX_SK_LOOP_INNER,               /**<@brief  inner loop of surface */
        VX_SK_LOOP_OUTER,               /**<@brief  outer loop of surface */
        VX_SK_LOOP_OPEN_BOUNDARY,       /**<@brief  open boundary of surface */
        VX_SK_LOOP_NON_SHARED_BOUNDARY, /**<@brief  non-shared boundary of the picked surfaces */
        VX_SK_LOOP_SILHOUETTE,          /**<@brief  silhouette of the picked surface */
    } evxSkLoopOption;

    /**
    @brief  sketch reference geometry data
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef struct svxSkRefData
    {
        evxSkRefMethod method; /**<@brief  reference method (VX_SK_REF_PROJECTION as default) */
        evxSkRefOption option; /**<@brief  reference option (VX_SK_REF_SINGLE as default) */

        union evxSkRefInpUnion
        {
            struct ReferenceSingle
            {
                int numEnt;           /**<@brief  number of entities to reference */
                svxEntPath *entPaths; /**<@brief  list paths of entities to reference */
            } single;
            struct ReferenceChain
            {
                evxSkChainOption option; /**<@brief  chain option (VX_SK_CHAIN_PICK as default) */
                int numEnt;              /**<@brief  number of entities to reference */
                svxEntPath *entPaths;    /**<@brief  list paths of entities to reference */
            } chain;
            struct ReferenceLoop
            {
                evxSkLoopOption option; /**<@brief  loop option (VX_SK_LOOP_ALL as default) */
                int numEnt;             /**<@brief  number of entities to reference */
                svxEntPath *entPaths;   /**<@brief  list paths of entities to reference */
            } loop;
            struct ReferencePoint
            {
                svxPntOnEntPath pnt; /**<@brief  reference point */
            } point;
        } inpUnion;

        int constructGeom; /**<@brief  whether to create construction geometry (1 or 0, 1 as default) */
        int recordState;   /**<@brief  whether to record the state of the history of the part from which the reference geometry is extracted (0 as default) */
    } svxSkRefData;

    //====================================================================================================================
    /** @name Curve Data */
    //====================================================================================================================
    /**********************************************************************
    *! -svxCrvIntData-
    *  defined in "zwapi_util.h", its also the input data of cvxPartCrvInt
    **********************************************************************/

    //====================================================================================================================
    /** @name Edit Curve Data */
    //====================================================================================================================
    /**
    @brief 3 Point Conic type
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef enum evxConic3PntType
    {
        VX_CONIC_SHOULDER = 0, /**<@brief  Shoulder, 3 Point Conic default value */
        VX_CONIC_TANGENT  = 1, /**<@brief  Tangent */
    } evxConic3PntType;

    /**
    @brief 3 Point Conic command data
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef struct svxConic3ptData
    {
        svxPntOnEnt StartPnt;       /**<@brief  Start point */
        svxPntOnEnt EndPnt;         /**<@brief  End point */
        svxPntOnEnt Point;          /**<@brief  Point */
        evxConic3PntType PointType; /**<@brief  Point type */
        double Ratio;               /**<@brief  Conic Ratio, Range of this value is: 0.01 <= Ratio <= 0.99 */
    } svxConic3ptData;

    /**
    @brief option of chamfer in sheeting or sketch
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef enum evxSkChamferOpt
    {
        VX_CHMOPT_SETBACK = 0,  /**<@brief  a chamfer of equal setback values between two curves */
        VX_CHMOPT_TWOSETBACK,   /**<@brief  a chamfer with different setback values between two curves */
        VX_CHMOPT_SETBACKANDDIS /**<@brief  a chamfer by specifying the setback and an angle */
    } evxSkChamferOpt;

    /**
    @brief option of trim in chamfer/fillet of sheeting or sketch
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef enum evxSkChamferTrimOpt
    {
        VX_CHMTRIM_NO = 0, /**<@brief  No trim/extend is performed */
        VX_CHMTRIM_BOTH,   /**<@brief  Trim/Extend both curves */
        VX_CHMTRIM_FIRST,  /**<@brief  Trim/Extend only the first selected curve */
        VX_CHMTRIM_SECOND  /**<@brief  Trim/extend only the second selected curve */
    } evxSkChamferTrimOpt;

    /**
    @brief control the path of extended curves in chamfer/fillet of sheeting or sketch
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef enum evxSkChamferExtenOpt
    {
        VX_CHMEXT_LINEAR = 1, /**<@brief  The extension follows a linear path */
        VX_CHMEXT_CIRCULAR,   /**<@brief  The extension follows an arc path in the direction of curvature */
        VX_CHMEXT_REFLECT     /**<@brief  The extension follows a reflective path opposite the direction of curvature */
    } evxSkChamferExtenOpt;

    /**
    @brief information of fillet in sheeting or sketch
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef struct svxSkFilletData
    {
        int idFirCurve;                 /**<@brief  first specified curve */
        svxPoint2 firPnt;               /**<@brief  a point on the first curve */
        int idSecCurve;                 /**<@brief  second specified curve */
        svxPoint2 secPnt;               /**<@brief  a point on the second curve */
        double radius;                  /**<@brief  radius of fillet */
        int designArc;                  /**<@brief  flag to use design arc, 0 no else yes */
        evxSkChamferTrimOpt fltTrimOpt; /**<@brief  trim (or extend) curves */
        evxSkChamferExtenOpt fltExtOpt; /**<@brief  control the path of extended curves */
    } svxSkFilletData;

    /**
    @brief information of chamfer in sheeting or sketch
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef struct svxSkChamferData
    {
        evxSkChamferOpt chamferOpt;     /**<@brief  option of chamfer */
        int idFirCurve;                 /**<@brief  first setback value.
                                        if type = VX_CHMOPT_SETBACK, it is setback value for 2 curves.
                                        if type != VX_CHMOPT_SETBACK, it is setback value for 1st curve */
        svxPoint2 firPnt;               /**<@brief  a point on the first curve */
        int idSecCurve;                 /**<@brief  second setback value.
                                        if type = VX_CHMOPT_TWOSETBACK,it is setback value for 2nd curve.
                                        other type can be null */
        svxPoint2 secPnt;               /**<@brief  a point on the second curve */
        double firSetBack;              /**<@brief  first setback value, when chamferOpt is VX_CHMOPT_SETBACK it represents setback value */
        double secSetBack;              /**<@brief  second setback value, only needed when chamferOpt is VX_CHMOPT_TWOSETBACK */
        double angValue;                /**<@brief  specifying the angle of the first curve,
                                        if type = VX_CHMOPT_SETBACKANDDIS, the setback value for 2nd curve is decided by the line form by 
                                        first setback position and the angle.
                                        other type can be null */
        evxSkChamferTrimOpt chmTrimOpt; /**<@brief  trim (or extend) curves */
        evxSkChamferExtenOpt chmExtOpt; /**<@brief  control the path of extended curves */
    } svxSkChamferData;

    /**
    @brief trim/extend extension method
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef enum evxTrimExtension
    {
        VX_EXT_LINEAR = 1, /**<@brief linear option */
        VX_EXT_ARC,        /**<@brief arc option */
        VX_EXT_REFLECT,    /**<@brief reflect option */
        VX_EXT_CRV_DIM     /**<@brief curvature diminishing option */
    } evxTrimExtension;

    /**
    @brief trim/extend extension method
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef enum evxTrimSplit
    {
        VX_SPLIT_KEEP,   /**<@brief keep option */
        VX_SPLIT_DELETE, /**<@brief delete option */
        VX_SPLIT_BREAK,  /**<@brief berak option */
    } evxTrimSplit;

    /**
    @brief trim/split to corner option method
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef enum evxTrimSplitCor
    {
        VX_SPLIT_COR_LINEAR,  /**<@brief lionear option */
        VX_SPLIT_COR_ARC,     /**<@brief arc option */
        VX_SPLIT_COR_REFLECT, /**<@brief reflect option */
    } evxTrimSplitCor;

    /**
    @brief sketch power trim data
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef struct svxSkPowerTrim
    {
        svxPoint2 startPnt; /**<@brief start point of power trim */
        svxPoint2 endPnt;   /**<@brief end point of power trim */
    } svxSkPowerTrim;

    /**
    @brief sketch trim or extend data
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef struct svxSkTrimExt
    {
        int numCrv;                 /**<@brief the number of the curve need to trim of extend */
        svxPntOnEnt *curves;        /**<@brief the start points of the curves need to trim or extend */
        svxPntOnEnt dest;           /**<@brief the destination point of the trim or extend */
        evxTrimExtension extension; /**<@brief the extension type.default:VX_EXT_ARC */
    } svxSkTrimExt;

    /**
    @brief sketch trim or split data
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef struct svxSkTrimSplit
    {
        int count;               /**<@brief the number of the entities */
        int *idEnts;             /**<@brief the id of the entities */
        int numSeg;              /**<@brief the number of segments */
        svxPntOnEnt *segments;   /**<@brief the list points of segments */
        evxTrimSplit trimOption; /**<@brief the trim type.default:VX_SPLIT_DELETE */
    } svxSkTrimSplit;

    /**
    @brief sketch trim or split at point data
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef struct svxSkTrimSplitPnt
    {
        int idCrv;             /**<@brief the id of the curve */
        int numPnt;            /**<@brief the number of point */
        svxPntOnEnt *pnts;     /**<@brief the list points */
        int numSeg;            /**<@brief the number of segments*/
        svxPntOnEnt *segments; /**<@brief the list points of segments */
    } svxSkTrimSplitPnt;

    /**
    @brief sketch trim or split to corner data
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef struct svxSkTrimSplitCor
    {
        svxPntOnEnt firstPnt;      /**<@brief the first point */
        svxPntOnEnt secondPnt;     /**<@brief the second point */
        evxTrimSplitCor extension; /**<@brief the extension type.default:VX_SPLIT_COR_REFLECT */
    } svxSkTrimSplitCor;

    /**
    @brief sketch split at intersection data
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef struct svxSkSplitIsect
    {
        int Count;     /**<@brief the number of the entities */
        int *idEnts;   /**<@brief the id of the entities */
        int SelfIsect; /**<@brief whether split at self intersections (0 = no, 1 = yes).default:1 */
        int CrvIsect;  /**<@brief whether split at curve-curve intersections (0 = no, 1 = yes).default:1 */
    } svxSkSplitIsect;

    //====================================================================================================================
    /** @name Constraint Data */
    //====================================================================================================================
    /**
    @brief data of sketch geometry constraint object
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef struct svxConsGeom
    {
        int isAxis;             /**<@brief  whether to use axis, 1 to use axis; 0 to use entity or point */
        svxPoint2 axis;         /**<@brief  specify axis, only X(1,0) and Y(0,1) axis of sketch are supported */
        int idEntity;           /**<@brief  index of entity */
        evxGeomCritPnt critPnt; /**<@brief  critical point, if you want to set an entity such as line rather than
                               a critical point on the entity, set the variable to VX_NO_POINT */
        int idPoint;            /**<@brief  used to indicate the control point of the spline (starting from 0)
                               only used when pntType is VX_SPLINE_DEFINING_POINT */
    } svxConsGeom;

    /**
    @brief sub type of sketch geometry constraint
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef enum evxGeomConsSubType
    {
        VX_SK_CONS_XY_COORDS_CONS = 0, /**<@brief  both the X and Y coordinates are constrained, used to VX_SK_CONS_FIX */
        VX_SK_CONS_X_COORD_CONS,       /**<@brief  only the X coordinate is constrained, used to VX_SK_CONS_FIX */
        VX_SK_CONS_Y_COORD_CONS,       /**<@brief  only the Y coordinate is constrained, used to VX_SK_CONS_FIX */
        VX_SK_PNT_TO_ARC_MIDPNT_CONS,  /**<@brief  point to arc midpoint constraint, used to VX_SK_CONS_MID */
        VX_SK_PNTS_SYMMETRY_CONS,      /**<@brief  mark as points symmetry, used to VX_SK_CONS_SYM */
    } evxGeomConsSubType;

    /**
    @brief type of sketch geometry constraint
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef enum evxGeomConsType
    {
        VX_SK_CONS_UNKNOWN,
        VX_SK_CONS_FIX,           /**<@brief  point fixed constraint */
        VX_SK_CONS_ALI_Y,         /**<@brief  points horizontal constraint */
        VX_SK_CONS_ALI_X,         /**<@brief  points vertical constraint */
        VX_SK_CONS_MID,           /**<@brief  point to midpoint constraint */
        VX_SK_CONS_ON_CRV,        /**<@brief  point to line/curve constraint */
        VX_SK_CONS_ISECT,         /**<@brief  point to intersection constraint */
        VX_SK_CONS_COIN,          /**<@brief  point coincident constraint */
        VX_SK_CONS_HOR,           /**<@brief  line horizontal constraint */
        VX_SK_CONS_VER,           /**<@brief  line vertical constraint */
        VX_SK_CONS_SYM,           /**<@brief  entity symmetrical constraint */
        VX_SK_CONS_PERP,          /**<@brief  line perpendicular constraint */
        VX_SK_CONS_PARA,          /**<@brief  line parallel constraint */
        VX_SK_CONS_COLINLN,       /**<@brief  line collinear constraint */
        VX_SK_CONS_TANG,          /**<@brief  line tangent constraint */
        VX_SK_CONS_EQL_LEN,       /**<@brief  line equal length constraint */
        VX_SK_CONS_EQL_CURVATURE, /**<@brief  line equal curvature constraint */
        VX_SK_CONS_CONC,          /**<@brief  point to center constraint */
        VX_SK_CONS_EQL_RAD,       /**<@brief  arc or circle equal radius constraint */

        /*  the following constraint types are created automatically by command and cannot be created by constraint command */
        VX_SK_CONS_SYM_DST, /**<@brief  distance symmetrical constraint, created by mirror command */
        VX_SK_CONS_SYM_ANG, /**<@brief  angle symmetrical constraint, created by mirror command */
        VX_SK_CONS_PTN,     /**<@brief  pattern constraint, created by pattern command */
        VX_SK_CONS_OFFSET   /**<@brief  offset constraint, created by offset command */
    } evxGeomConsType;

    //====================================================================================================================
    /** @name Dimension Data */
    //====================================================================================================================
    /**
    @brief type of sketch constraint dimension
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef enum evxConsDimType
    {
        VX_SK_CONSDIM_UNKNOW = -1,   /**<@brief  undefine. */
        VX_SK_CONSDIM_LINEAR,        /**<@brief  type of linear dimension */
        VX_SK_CONSDIM_LINEAR_OFFSET, /**<@brief  type of linear offset dimension */
        VX_SK_CONSDIM_ANGULAR,       /**<@brief  type of angular dimension */
        VX_SK_CONSDIM_RADIAL,        /**<@brief  type of radial/diametric dimension */
        VX_SK_CONSDIM_ARC_LENGTH,    /**<@brief  type of arc length dimension */
        VX_SK_CONSDIM_SYMMETRY,      /**<@brief  type of symmetry dimension */
        VX_SK_CONSDIM_PERIMETER,     /**<@brief  type of perimeter dimension */
    } evxConsDimType;

    /**
    @brief data of constraint dimension
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef struct svxConsDim
    {
        svxPoint firstPnt;  /**<@brief  first point */
        svxPoint secondPnt; /**<@brief  second point, NULL if it doesn't need */
        svxPoint textPnt;   /**<@brief  text point */
        int type;           /**<@brief  sub type of dimension   
                           linear dimension: 1 = horizontal method, 2 = vertical method, 3 = aligned method   
                           linear offset dimension: 1 = offset method, 2 = projected distance method   
                           angular dimension: 1 = 2 curve method, 2 = horizontal method, 3 = vertical method, 4 = arc method   
                           radial dimension: 1 = radial method, 2 = diameter method   
                           arc length dimension: the value can be ignored */
        int firstEnt;       /**<@brief  entity id which the first point on it, NULL if it doesn't need*/
        int secondEnt;      /**<@brief  entity id which the second point on it, NULL if it doesn't need*/
    } svxConsDim;

    /**
    @brief data of perimeter dimension
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef struct svxPerimeterDimData
    {
        int cnt;          /**<@brief count of listCrvId */
        int *listCrvId;   /**<@brief list of curve id */
        svxPoint textPnt; /**<@brief text point */
        int variant;      /**<@brief 0 is auto,the system will atutomatically modify the selected curves' length according to the perimeter. 
                         1 is manual,the perimeter is defined by moved curve field.user can modify the length of the selected 
                         curve to define the perimeter. */
        int variantCrvId; /**<@brief variant curve id.apply it if variant = 1. */
    } svxPerimeterDimData;

    //====================================================================================================================
    /** @name Basic Editing Data */
    //====================================================================================================================
    /**
    @brief Move and Copy Methods(2D)
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef enum evxMoveType2D
    {
        VX_PNT_TO_PNT_2D, /**<@brief  copy/move entities along a direction (2D) */
        VX_ALONG_DIR_2D,  /**<@brief  copy/move entities form point to point (2D) */
    } evxMoveType2D;

    /**
    @brief copy/move entities along a direction (2D)
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef struct svxAlongDir2D
    {
        svxVector2 dir;      /**<@brief  move direction */
        double distance;     /**<@brief  distance */
        svxPoint2 BasePoint; /**<@brief  base point */
        double angle;        /**<@brief  angle */
        double scale;        /**<@brief  scale */
    } svxAlongDir2D;

    /**
    @brief Sketch/Drawing move direction type
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef enum evxDrawingMoveDirType
    {
        VX_DRAWING_TWOPOINTS,  /**<@brief  two points */
        VX_DRAWING_HORIZONTAL, /**<@brief  horizontal */
        VX_DRAWING_VERTICAL,   /**<@brief  vertical */
    } evxDrawingMoveDirType;

    /**
    @brief copy/move entities form point to point (2D)
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef struct svxMovePntToPnt2D
    {
        svxPoint2 FromPoint;        /**<@brief  from point */
        svxPoint2 ToPoint;          /**<@brief  to point */
        evxDrawingMoveDirType type; /**<@brief  direction type */
        double angle;               /**<@brief  angle */
        double scale;               /**<@brief  scale */
    } svxMovePntToPnt2D;

    /**
    @brief template command Move data(2D)
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef struct svxMoveData2D
    {
        evxMoveType2D methods;  /**<@brief  Move Methods */
        int cntEnt;             /**<@brief  Entity count */
        int *pEnts;             /**<@brief  Entities ID */
        union evxMethodsUnion2D /**<@brief  move data */
        {
            svxAlongDir2D AlongDir2D;     /**<@brief  along direction data(2D) */
            svxMovePntToPnt2D PntToPnt2D; /**<@brief  point to point(2D) */
        } MethodUnion2D;
    } svxMoveData2D;

    /**
    @brief rotate type
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef enum evxRotateType
    {
        VX_ROTATE_ANGLE = 0, /**<@brief  Angle, default value */
        VX_ROTATE_POINTS,    /**<@brief  Points */
    } evxRotateType;

    /**
    @brief rotate setting
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef enum evxRotateSetting
    {
        VX_ROTATE_MOVE = 1, /**<@brief  Move, default value */
        VX_ROTATE_COPY,     /**<@brief  Copy */
    } evxRotateSetting;

    /**
    @brief template command Rotate data
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef struct svxRotateData2D
    {
        int cntEnt;               /**<@brief  Entity count */
        int *pEnts;               /**<@brief  Entities ID */
        svxPntOnEnt Pnt;          /**<@brief  Base point */
        evxRotateType Type;       /**<@brief  Option to set rotate type, VX_ROTATE_ANGLE is default */
        double Angle;             /**<@brief  Rotate angle, 0 if Type is VX_POTATE_POINTS */
        svxPntOnEnt Start;        /**<@brief  Start point for rotating, use cvxMemZero() set this value if Type is VX_ROTATE_ANGLE */
        svxPntOnEnt End;          /**<@brief  End point for rotating, use cvxMemZero() set this value if Type is VX_ROTATE_ANGLE */
        evxRotateSetting Setting; /**<@brief  Rotate settings, VX_ROTATE_MOVE is default */
        int cntCopy;              /**<@brief  Copy count, 0 if Setting is VX_ROTATE_MOVE */
    } svxRotateData2D;

    /**
    @brief template command Mirror data(2D)
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef struct svxMirrData2D
    {
        int cntEnt;      /**<@brief  Entity count */
        int *pEnts;      /**<@brief  Entities ID */
        int Line;        /**<@brief  Line(Symmetry axis) ID */
        int KeepOrigEnt; /**<@brief  Flag to use "Keep original entities" ,1 is default  */
    } svxMirrData2D;

    /**
    @brief sketch pattern method
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef enum evxSkPatternType
    {
        VX_SKPATTERN_LINEAR,    /**<@brief linear pattern */
        VX_SKPATTERN_CIRCULAR,  /**<@brief circular pattern */
        VX_SKPATTERN_AT_CURVES, /**<@brief pattern in space using one or more input curves */
    } evxSkPatternType;

    /**
    @brief sketch pattern spacing method
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef enum evxSkSpacingType
    {
        VX_NUMBER_PITCH, /**<@brief number and pitch option */
        VX_NUMBER_SPAN,  /**<@brief number and span option */
        VX_PITCH_SPAN,   /**<@brief pitch and span option */
    } evxSkSpacingType;

    /**
    @brief sketch pattern data
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef struct svxSkPtnData
    {
        evxSkPatternType type; /**<@brief pattern method */
        int count;             /**<@brief number of entities for pattern */
        int *idEnts;           /**<@brief list of id's of entities */
        int addDim;            /**<@brief whether to add dimension (0 = no, 1 = yes).default:1  */
        union SkPtnData        /**<@brief union of sketch pattern data */
        {
            struct svxSkLinear /**<@brief linear pattern */
            {
                int useSecondDir;            /**<@brief 0 if user don't use second direction,else 1.default:0 */
                svxVector dir[2];            /**<@brief first and second direction.the second direction is ignored if useSecondDir = 0. */
                int num[2];                  /**<@brief pattern number in both direction, the second direction is ignored if useSecondDir = 0.default:(2,1) */
                evxSkSpacingType spacing[2]; /**<@brief pattern spacing type in both direction, the second direction is ignored if useSecondDir = 0.default:(VX_NUMBER_PITCH,VX_NUMBER_PITCH) */
                double pitch[2];             /**<@brief pattern pitch dist in both direction, the second direction is ignored if useSecondDir = 0.default:(5,5) */
                double span[2];              /**<@brief pattern span dist in both direction, the second direction is ignored if useSecondDir = 0.default:(100,100) */
            } linear;
            struct svxSkCircular /**<@brief circular pattern */
            {
                svxPntOnEnt center;       /**<@brief rotation center point for the pattern. */
                int num;                  /**<@brief pattern number.default:2 */
                evxSkSpacingType spacing; /**<@brief pattern spacing type.default:VX_NUMBER_PITCH */
                double pitch;             /**<@brief spacing between the instances measured in pitch angle degrees.default:60 */
                double span;              /**<@brief spacing between the instances measured in span angle degrees.default:360 */
            } circular;
            struct svxSkPtnCrv /**<@brief curve pattern */
            {
                svxPntOnEnt crvid;        /**<@brief pattern curve id */
                int num;                  /**<@brief pattern number.default:2 */
                evxSkSpacingType spacing; /**<@brief pattern spacing type.default:VX_NUMBER_PITCH */
                double pitch;             /**<@brief pattern pitch dist.default:5 */
            } ptnCrv;
        } ptnData;
        int cntSkip;          /**<@brief number of the instances to be skipped */
        int *firstTogglePos;  /**<@brief the position id of the patterned entities in the first direction (start form 0, the nTH position in the first direction) */
        int *secondTogglePos; /**<@brief the position id of the patterned entities in the second direction (start form 0, the nTH position in the second direction)  
                                          can be null if just pattern the first direction.    
                                          such as: linear.num = {3,2}, linear.dir[0]  = {1,0,0}, linear.dir[1] = {0, 1, 0}    
                                          y     
                                          ^ O O *      if the '*' should be skipped, firstTogglePos[0] = 2, secondTogglePos[0] = 1    
                                          | O & O      if the '&' should be skipped, firstTogglePos[0] = 1, secondTogglePos[0] = 0    
                                          |-------> x     
                                       */
    } svxSkPtnData;

    /**
    @brief sketch copy method
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef enum evxSkCopyType
    {
        VX_SK_COPY_PNT, /**<@brief  copy entities from point to point */
        VX_SK_COPY_DIR, /**<@brief  copy entities along a direction */
    } evxSkCopyType;

    /**
    @brief sketch copy from point to point direction method
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef enum evxSkCopyDir
    {
        VX_SK_COPY_DIR_TWO,        /**<@brief  two points */
        VX_SK_COPY_DIR_HORIZONTAL, /**<@brief  horizontal */
        VX_SK_COPY_DIR_VERTICAL,   /**<@brief  vertical */
    } evxSkCopyDir;

    /**
    @brief  sketch copy data
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef struct svxSkCopy
    {
        evxSkCopyType type; /**<@brief  copy option */
        int numEnt;         /**<@brief  number of entities to copy */
        int *idEnts;        /**<@brief  list id of entities to copy */
        int numCpy;         /**<@brief  copy number */
        double angle;       /**<@brief  the rotate angle.default:0 */
        double scale;       /**<@brief  the scale of copy entities.default:1 */
        union svxSkCopyData /**<@brief  union of sketch copy data */
        {
            struct svxSkCopyPnt /**<@brief  point to point copy type */
            {
                svxPoint2 fromPnt;      /**<@brief  from point */
                svxPoint2 toPnt;        /**<@brief  to point */
                evxSkCopyDir dirOption; /**<@brief  direction option.default:VX_SK_COPY_DIR_TWO */
            } pnt;
            struct svxSkCopyDir /**<@brief  along a direction type */
            {
                svxPntOnEnt dir;   /**<@brief  direction of copy */
                double distance;   /**<@brief  distance of copy.default:10 */
                svxPoint2 basePnt; /**<@brief  base point of copy */
            } dir;
        } cpy;
    } svxSkCopy;

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_SK_CMD_DATA_H */
