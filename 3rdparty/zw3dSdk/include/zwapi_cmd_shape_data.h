/**
@file zwapi_cmd_shape_data.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the Shape
Command functions of Part.
*/
/**
@defgroup zwapi_cmd_shape_data Shape Commands Data
@ingroup PartandAssemblyCommands
@brief
@details THE MODULE FOR THE ZW3D Data Types and Structures of the Shape
Command functions of Part.
*/

#pragma once
#ifndef ZW_API_SHAPE_FTR_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_SHAPE_FTR_DATA_H

#include "zwapi_util.h"
#include "zwapi_cmd_subcmd_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Basic Shape Data */
    //====================================================================================================================
    /**
    @brief boolean combination method
    @ingroup zwapi_cmd_shape_data
    */
    typedef enum evxBoolType
    {
        VX_BOOL_NONE      = 0, /**< @brief base */
        VX_BOOL_ADD       = 1, /**< @brief add */
        VX_BOOL_REMOVE    = 2, /**< @brief remove */
        VX_BOOL_INTERSECT = 3  /**< @brief intersect */
    } evxBoolType;

    /**
    @brief box data
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxBoxData
    {
        evxBoolType Combine; /**<@brief  combination method */
        int idPlane;         /**<@brief  optional datum plane, or 0 */
        int useAxis;         /**<@brief  flag to use axis, 0 default */
        svxAxis axis;        /**<@brief  optional axis */
        svxPoint Center;     /**<@brief  center of box volume */
        double X;            /**<@brief  length along X */
        double Y;            /**<@brief  length along Y */
        double Z;            /**<@brief  length along Z */
        vxName ftrName;      /**<@brief  feature name for "FtAllBox", 0 default */
    } svxBoxData;

    /**
    @brief cylinder
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxCylData
    {
        evxBoolType Combine; /**<@brief  combination method */
        int idPlane;         /**<@brief  optional datum plane (0 to use XY plane) */
        int useAxis;         /**<@brief  flag to use axis, 0 default */
        svxAxis axis;        /**<@brief  optional axis */
        svxPoint Center;     /**<@brief  center of bottom face */
        double Radius;       /**<@brief  radius (mm) in XY plane */
        double Length;       /**<@brief  length (mm) along Z */
        vxName ftrName;      /**<@brief  feature name for "FtAllCyl", 0 default */
    } svxCylData;

    /**
    @brief cone
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxConeData
    {
        evxBoolType Combine; /**<@brief  combination method */
        svxPoint Center;     /**<@brief  center of bottom face */
        double Radius1;      /**<@brief  the first radius (mm) in bottom face */
        double Length;       /**<@brief  length (mm) along Z */
        double Radius2;      /**<@brief  the second radius (mm), 0 default */

        int useAxis;  /**<@brief  flag to use axis (0 to use plane, 1 to use axis) */
        int idPlane;  /**<@brief  optional datum plane (0 to use XY plane) */
        svxAxis axis; /**<@brief  optional axis */

        vxName ftrName; /**<@brief  feature name for "FtAllCone", 0 default */
    } svxConeData;

    /**
    @brief sphere
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxSphereData
    {
        evxBoolType Combine; /**<@brief  combination method */
        svxPoint Center;     /**<@brief  sphere center point */
        double Radius;       /**<@brief  sphere radius (mm) */

        vxName ftrName; /**<@brief  feature name for "FtAllSph", 0 default */
    } svxSphereData;

    /**
    @brief ellipsoid
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxEllsoData
    {
        evxBoolType Combine; /**<@brief  combination method */
        svxPoint Center;     /**<@brief  sphere center point */
        double xLen;         /**<@brief  length of the ellipsoid along the x (mm) */
        double yLen;         /**<@brief  length of the ellipsoid along the y (mm) */
        double zLen;         /**<@brief  length of the ellipsoid along the z (mm) */

        int useAxis;  /**<@brief  flag to use axis (0 to use plane, 1 to use axis) */
        int idPlane;  /**<@brief  optional datum plane (0 to use XY plane) */
        svxAxis axis; /**<@brief  optional axis */

        vxName ftrName; /**<@brief  feature name for "FtAllEllso", 0 default */
    } svxEllsoData;

    /**
    @brief offset type
    @ingroup zwapi_cmd_shape_data
    */
    typedef enum evxOffsetType
    {
        VX_OFFSET_NONE         = 0, /**<@brief  none */
        VX_OFFSET_SHRINK       = 1, /**<@brief  Shrink / Expand */
        VX_OFFSET_THICKEN      = 2, /**<@brief  Thicken */
        VX_OFFSET_THICKEN_SAME = 3, /**<@brief  Thicken same */
    } evxOffsetType;

    /**
    @brief lead type
    @ingroup zwapi_cmd_shape_data
    */
    typedef enum evxLeadType
    {
        VX_LEAD_IN   = 0, /**<@brief  transitions the spiral in toward the center of the axis for spiral solids and threaded bosses */
        VX_LEAD_OUT  = 1, /**<@brief  transitions the spiral out away from the center of the axis for threaded cuts */
        VX_LEAD_NONE = 2, /**<@brief  no lead in/out applied */
    } evxLeadType;

    /**
    @brief End caps
    @ingroup zwapi_cmd_shape_data
    */
    typedef enum evxCapType
    {
        VX_END_CAP_BOTH  = 0, /**<@brief  both */
        VX_END_CAP_START = 1, /**<@brief  start */
        VX_END_CAP_END   = 2, /**<@brief  end */
        VX_END_CAP_NONE  = 3, /**<@brief  none */
    } evxCapType;

    /**
    @brief extruded shape
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxExtrudeData
    {
        evxBoolType Combine; /**<@brief  combination method */
        int idProfile;       /**<@brief  profile (sketch or curvelist) */
        double Start;        /**<@brief  start distance (mm) */
        double End;          /**<@brief  end distance (mm) */

        double Draft; /**<@brief  draft angle (deg) */
        int Blend;    /**<@brief  corner blend option */
                      /**<@brief  (0-variable, 1-constant, 2-round) */

        int UseDirection;    /**<@brief  1 to use optional extrusion direction, else 0 */
        svxVector Direction; /**<@brief  optional extrusion direction */

        double Twist;   /**<@brief  twist angle (deg) */
        svxPoint Pivot; /**<@brief  pivot point if twist is non-zero */

        double Offset;    /**<@brief  profile offset (mm) (0 if undefined) */
        double Thickness; /**<@brief  wall thickness (mm) (0 if undefined) */

        int iKeep; /**<@brief  keep profile (1-keep, 0-not keep, not use since 2400) */

        int numBooleanEnts; /**<@brief  count of shapes in BooleanEnts array, use 0 if BooleanEnts is NULL*/
        int *BooleanEnts;   /**<@brief  id list of shapes to combine with extrusion, use NULL if Combine is VX_BOOL_NONE or to
                                    combine extrusion with all visible shapes */
        vxName ftrName;     /**<@brief  feature name for "FtAllExt", 0 default */

        int FlipFaceDir;             /**<@brief  1-flip face direction, else 0 (0:default value, valid when the idProfile is open or CapType == VX_END_CAP_NONE) */
        int FlipRemoveArea;          /**<@brief  1-flip bool remove area, else 0 (0:default value, valid when Combine == VX_BOOL_REMOVE) */
        evxDistanceMethod StartType; /**<@brief  start type (0 = input value, 1 = through all, 2= to point, 3 = to faces, 4=to Extend Face) */
        evxDistanceMethod EndType;   /**<@brief  end type (0 = input value, 1 = through all, 2= to point, 3 = to faces, 4=to Extend Face) */
        int idStartEnt;              /**<@brief  the entity id of start field if StartType > 1 */
        int idEndEnt;                /**<@brief  the entity id of end field if EndType > 1 */
        double StartOffset;          /**<@brief  start offset value if StartType >= 3 */
        double EndOffset;            /**<@brief  end offset value if EndType >= 3 */
        svxPoint *StartToPnt;        /**<@brief  set the point if StartType > 1 , (NULL to ignore, it will use the start point of idStartEnt) */
        svxPoint *EndToPnt;          /**<@brief  set the point if EndType > 1 , (NULL to ignore, it will use the start point of idEndEnt) */

        evxOffsetType OffsetTyp; /**<@brief  option of offset(set the value of Offset and Thickness)*/
        evxCapType CapType;      /**<@brief  end cap type (VX_END_CAP_BOTH as default, invalid if the idProfile is open) */
        int cntCap;              /**<@brief  count cap face (0 to ignore;
                                    valid if Combine is VX_BOOL_ADD or VX_BOOL_Remove and the idProfile is open;
                                    valid if Combine is VX_BOOL_ADD and the idProfile is close) */
        int *CapFace;            /**<@brief  cap face id list (NULL to ignore) */
    } svxExtrudeData;

    /**
    @brief revolved shape
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxRevolveData
    {
        evxBoolType Combine; /**<@brief  combination method */
        int idProfile;       /**<@brief  profile (sketch or curvelist) */
        double Start;        /**<@brief  start angle (deg) */
        double End;          /**<@brief  end angle (deg) */
        svxAxis Axis;        /**<@brief  axis of revolution */

        double Offset;    /**<@brief  profile offset (mm) (0 if undefined) */
        double Thickness; /**<@brief  wall thickness (mm) (0 if undefined) */

        int idAxis;   /**<@brief  index of idAxis (-1/0 to ignore) */
        int idParent; /**<@brief  parent index if idAxis is a geometry of the profile (-1/0 to ignore) */

        evxOffsetType OffsetTyp; /**<@brief  option of offset(set the value of Offset and Thickness)*/

        /* To point/ To face/ To Extended Face for "Start" and "End" */
        evxDistanceMethod StartType; /**<@brief  start type (values: VX_INPU_VALUE, VX_BY_THROUGH_ALL, VX_TO_POINT,  VX_TO_EXTEND_FACE, VX_TO_FACE */
        evxDistanceMethod EndType;   /**<@brief  end type (values: VX_INPU_VALUE, VX_BY_THROUGH_ALL, VX_TO_POINT,  VX_TO_EXTEND_FACE, VX_TO_FACE */
        int idStartEnt;              /**<@brief  entity id if StartType != VX_INPU_VALUE (-1 to ignore) */
        int idEndEnt;                /**<@brief  entity id if EndType != VX_INPU_VALUE (-1 to ignore) */
        svxPoint *StartPnt;          /**<@brief  start point (NULL to ignore, it will get the point (umin,vmin) of the idStartEnt if StartType = VX_EXT_TO_FACE/VX_TO_EXTEND_FACE))*/
        svxPoint *EndPnt;            /**<@brief  end point (NULL to ignore, it will get the point (umin,vmin) of the idEndEnt if EndType = VX_EXT_TO_FACE/VX_TO_EXTEND_FACE))*/
        evxCapType CapType;          /**<@brief  end cap type (VX_END_CAP_BOTH as default, invalid if the idProfile is open) */
        int Flip;                    /**<@brief  flip face direction (0 as default, CapType=VX_END_CAP_NONE) */
    } svxRevolveData;

    /**
    @brief sweep option
    @ingroup zwapi_cmd_shape_data
    */
    typedef enum evxSweepOpt
    {
        VX_SWP_NATURAL    = 0, /**<@brief  Default frame */
        VX_SWP_AT_PATH    = 1, /**<@brief  At Path */
        VX_SWP_FRAME      = 2, /**<@brief  Selected */
        VX_SWP_AT_PROFILE = 3, /**<@brief  At intersection */
        VX_SWP_ALONG_PATH = 4  /**<@brief  Along Path */
    } evxSweepOpt;

    /**
    @brief sweep Xaxis option
    @ingroup zwapi_cmd_shape_data
    */
    typedef enum evxSweepXOpt
    {
        VX_SWP_X_MIN_TWIST   = 0, /**<@brief  minimum twist (default)*/
        VX_SWP_X_FIXED_DIR   = 1, /**<@brief  fixed direction */
        VX_SWP_X_XAXIS_CRV   = 2, /**<@brief  X-axis curve */
        VX_SWP_X_FACE_NORMAL = 3, /**<@brief  face normal */
    } evxSweepXOpt;

    /**
    @brief sweep Zaxis option
    @ingroup zwapi_cmd_shape_data
    */
    typedef enum evxSweepZOpt
    {
        VX_SWP_Z_TANG_TO_PATH = 0, /**<@brief  tangent to path (default) */
        VX_SWP_Z_TANG_TO_CRV  = 1, /**<@brief  tangent to curve */
        VX_SWP_Z_FIXED_DIR    = 2, /**<@brief  parallel with the fixed direction */
    } evxSweepZOpt;

    /**
    @brief swept shape
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxSweepData
    {
        evxBoolType Combine; /**<@brief  combination method */
        int idProfile;       /**<@brief  profile (sketch, curve, edge, curvelist) */
        int idPath;          /**<@brief  id of curve that identifies the sweep path */
        svxPoint StartPnt;   /**<@brief  point that identifies start of path curve */

        /* defined relative to curve's coordinate frame */
        int idParent;  /**<@brief  id of path curve's parent sketch or curvelist */
        int UseParent; /**<@brief  1 to use curve's parent as the sweep path, else 0 */

        evxSweepOpt Option; /**<@brief  sweep option(VX_SWP_AT_PROFILE as default) */

        int idFrame; /**<@brief  id of sweep frame if Option=VX_SWP_FRAME, else 0 */

        int idXaxis; /**<@brief  id of X-axis point, curve or plane (0 if undefined or tangent to path) */

        int idZaxis; /**<@brief  id of Z-axis point, curve or plane (0 if undefined or minimum twist) */

        double Offset;    /**<@brief  profile offset (mm) (0 if undefined) */
        double Thickness; /**<@brief  wall thickness (mm) (0 if undefined) */

        int useStartPnt; /**<@brief  1- user "StartPnt", else 0 it will get the start point of the "idPath" */
        /* set the type of Xaxis and Zaxis, set the following parameters or just set idXaxis and idZaxis */
        evxSweepXOpt xOpt; /**<@brief  type of X-axis */
        evxSweepZOpt zOpt; /**<@brief  type of Y-axis */
        svxPntOnEnt *xEnt; /**<@brief  entity data of x-axis (NULL to ignore or use idZaxis or xOpt = VX_SWP_X_MIN_TWIST)
                                 VX_SWP_X_FIXED_DIR- use direction (just direction or direction from an curve/edge)
                                 VX_SWP_X_XAXIS_CRV - point on curve(set parent if the curve from the sketch)
                                 VX_SWP_X_FACE_NORMAL - face */

        svxPntOnEnt *zEnt;       /**<@brief  entity data of z-axis (NULL to ignore or use idZaxis or zOpt = VX_SWP_Z_TANG_TO_PATH)
                                 VX_SWP_Z_TANG_TO_CRV- curve(set parent if the curve from the sketch)
                                 VX_SWP_Z_FIXED_DIR - use direction (just direction or direction from an curve/edge) */
                                 /**<@brief  offset type */
        evxOffsetType OffsetTyp; /**<@brief  option of offset(set the value of Offset and Thickness)*/

        evxCapType CapType; /**<@brief  end cap type (VX_END_CAP_BOTH as default, invalid if the idProfile is open) */
        int cntCap;         /**<@brief  count cap face (0 to ignore;
                                 valid if Combine is VX_BOOL_ADD or VX_BOOL_Remove and the idProfile is open;
                                 valid if Combine is VX_BOOL_ADD and the idProfile is close) */
        int *CapFace;       /**<@brief  cap face id list (NULL to ignore) */
        int MergeFc;        /**<@brief  merge tangent faces (0 as default) */
    } svxSweepData;

    /**
    @brief spiral swept shape
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxSpiralSweepData
    {
        /* Required */
        svxPntOnEntPath pntOnPro; /*!<@brief  a point at profile (sketch, curve, edge, curveList). If the type of profile is sketch, set useCritPnt to 1 for getting point automatically */
        svxVector axis;           /**<@brief  axis of spiral sweep */
        double turns;             /**<@brief  the number of turns */
        double dst;               /**<@brief  the distance along the axis for each turn */
        /* Boolean */
        evxBoolType combine; /**<@brief  combination method. (VX_BOOL_NONE as default) */
        int cntShapes;       /**<@brief  count of boolean shapes */
        int *idShapes;       /**<@brief  id of boolean shapes */
        /* Lead */
        evxLeadType leadType; /**<@brief  lead type(set the value of leadRad and leadAng). (VX_LEAD_NONE as default) */
        double leadRad;       /**<@brief  determines a pivot point while the angle specifies the number of degrees the profile is rotated. (0 if undefined) */
        double leadAng;       /**<@brief  for lead Out, the angle is measured from the point on the profile furthest away from the axis of rotation;  
                                         for lead In, the point closest to the axis is used. (0 if undefined) */
        evxCapType capType;   /**<@brief  end cap type(invalid if the idProfile is open). (VX_END_CAP_BOTH as default) */
        /* Offset */
        evxOffsetType offsetType; /**<@brief  option of offset(set the value of Offset and Thickness). (VX_OFFSET_NONE as default) */
        double offset;            /**<@brief  profile offset (mm) (0 if undefined) */
        double thickness;         /**<@brief  wall thickness (mm) (0 if undefined) */
        /* Settings */
        double taperAng; /**<@brief  taper angle used to create pipe threads, tapered coils, etc */
        int isClockwise; /**<@brief  judge the spiral to turn clockwise about the axis direction. (1 = clockwise, 0 as default) */
        int isFlipDir;   /**<@brief  flip the spiral direction of the thread. (1 = flip, 0 as default) */
    } svxSpiralSweepData;


    /**
    @brief loft profile data
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxLoftProfile
    {
        int idParent;      /**<@brief  id of profile curve's parent sketch or curve list */
        int idProfile;     /**<@brief  id of profile curve for loft (curve, edge, parting line) */
        int profDir;       /**<@brief  specify the orientation of the profile (0 = from start point to end point, otherwise 1) */
        int useStartPnt;   /**<@brief  1 = use the specified starting point, 0 = use the default starting point */
        svxPoint startPnt; /**<@brief  starting point coordinate, only setting when useStartPnt = 1 */
    } svxLoftProfile;

    /**
    @brief loft method
    @ingroup zwapi_cmd_shape_data
    */
    typedef enum evxLoftType
    {
        VX_LOFT_PROFS,           /**<@brief  loft profiles in the order of profiles selection */
        VX_LOFT_START_PNT_PROFS, /**<@brief  loft based on starting point and profiles */
        VX_LOFT_END_PNT_PROFS,   /**<@brief  loft based on ending point and profiles */
        VX_LOFT_BOTH_PNTS_PROFS  /**<@brief  loft based on both end points and profiles */
    } evxLoftType;

    /**
    @brief loft data
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxLoftData
    {
        evxBoolType combine;   /**<@brief  combination method */
        evxLoftType type;      /**<@brief  loft method */
        int idStartParent;     /**<@brief  id of the parent entity where the starting point is located */
        svxPoint startPnt;     /**<@brief  starting point coordinate */
        int numProfs;          /**<@brief  number of profiles for loft */
        svxLoftProfile *profs; /**<@brief  list of profiles data */
        int idEndParent;       /**<@brief  id of the parent entity where the ending point is located */
        svxPoint endPnt;       /**<@brief  ending point coordinate */

        svxLoftBndCons bndCons[2]; /**<@brief  boundary constraints data of start and end profiles */
        int endCap;                /**<@brief  end cap option (0-both, 1-start, 2-end, 3-none) */
        int close;                 /**<@brief  whether to generate a closed loft (1 = yes, 0 = no) */

        vxName ftrName; /**<@brief  feature name for "FtAllLft1", 0 default */
    } svxLoftData;

    //====================================================================================================================
    /** @name Engineering Feature Data */
    //====================================================================================================================
    /**
    @brief chamfer or fillet types
    @ingroup zwapi_cmd_shape_data
    */
    typedef enum evxChamFlltType
    {
        VX_CHAMFLLT_SYMMETRIC,     /**<@brief  symmetric chamfer or fillet: single offset chamfer at edge */
        VX_CHAMFLLT_ASYMMETRIC,    /**<@brief  asymmetric chamfer or fillet: double offset chamfer at edge */
        VX_CHAMFLLT_SETBACK_ANGLE, /**<@brief  asymmetric chamfer or fillet: offset and angle chamfer at edge */
        VX_CHAMFLLT_VERTEX         /**<@brief  vertex chamfer or fillet: single offset chamfer at vertex */
    } evxChamFlltType;

    /**
    @brief set-list data for chamfer or fillet command
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxChamFlltSetData
    {
        int nEdges;        /**<@brief  number of edges or vertexes to chamfer or fillet */
        int *idEdge;       /**<@brief  list of index of edges to chamfer or fillet */
        int *vertex;       /**<@brief  list of endpoints for edges (0-starting vertex, 1-end vertex),
                                 like idEdge, the number of data in this list should also be nEdges,
                                 only for VX_CHAMFILT_VERTEX type, other types can be set to NULL */
        int chordalFillet; /**<@brief  if set to 1, use chordal instead of radius for fillet, the variable 'setback1' will be treated as 'Chordal L' (0-default) */
        double setback1;   /**<@brief  the first setback distance or radius */
        double setback2;   /**<@brief  the second setback distance for VX_CHAMFILT_ASYMMETRIC type */
        double angle;      /**<@brief  the angle of the setback for VX_CHAMFILT_SEEDBACK_ANGLE type */

        int flip; /**<@brief  1-flip the edge direction, else 0 (type = VX_CHAMFLLT_ASYMMETRIC/VX_CHAMFLLT_SETBACK_ANGLE) */

        svxPntOnEnt *setback1Pnt; /**<@brief  setback1 value (NULL to ignore) */
        svxPntOnEnt *setback2Pnt; /**<@brief  setback2 value (NULL to ignore) */
    } svxChamFlltSetData;

    /**
    @brief chamfer or fillet data
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxChamFlltData
    {
        evxChamFlltType type; /**<@brief  chamfer or fillet type */

        int nEdges;  /**<@brief  number of edges or vertexes to chamfer or fillet */
        int *idEdge; /**<@brief  list of index of edges to chamfer or fillet */
        int *vertex; /**<@brief  list of endpoints for edges (0-starting vertex, 1-end vertex),
                         like idEdge, the number of data in this list should also be nEdges,
                         only for VX_CHAMFILT_VERTEX type, other types can be set to NULL */

        double setback1; /**<@brief  the first setback distance or radius */
        double setback2; /**<@brief  the second setback distance for VX_CHAMFILT_ASYMMETRIC type */
        double angle;    /**<@brief  the angle of the setback for VX_CHAMFILT_SEEDBACK_ANGLE type */

        /*  The following parameters are used to set shape of fillet, only used for fillet feature */
        double relief;     /**<@brief  specify the amount of smoothing at a corner patch. When set to zero (0.0-default),
                        the command decides where to trim the rails of the fillets meeting at a corner.
                        Values greater than 0 add additional relief to corners.*/
        int arcType;       /**<@brief  specify the fillet arc type (0-circular arc, 1-conic arc, 2-G2 blend) */
        double conicRatio; /**<@brief  conic ratio for conic arc type (0~0.999999, 0.5-default) */
        double weight[2];  /**<@brief  endpoint weights for G2 blend arc type (0.1~5.0, 1.0-default) */

        /*  The following parameters are used to set rollover control */
        int filletToEdge; /**<@brief  if set to 1, fillet held to nearby edges (0-default) */
        int usePatch;     /**<@brief  whether to use patches in tight corners (0-default) */
        int undercuts;    /**<@brief  if set to 1, the chamfer/fillet engine will look for cases where the
                         new chamfer/fillet are completely undercutting a pre-existing feature.
                         If found, the engine will attempt to extend and/or trim the old feature
                         against the new chamfer/fillet (0-default) */
        int localCorner;  /**<@brief  if set to 1, keep chamfering/filleting only to the edge, else the
                         chamfer/fillet will extend to the surface where the edge is (0-default) */
        int mitred;       /**<@brief  if set to 1, the chamfer/fillet engine will provide a mitred solution
                         at corners of uniform convexity , else a corner patch will be added when
                         all edges are chamfered (0-default) */
        int traceCorners; /**<@brief  if set to 1, the rails of the chamfer/fillet and corner patch faces are
                         traced onto the support faces rather than being projected (0-default) */
        int blendCorners; /**<@brief  if set to 1, create a single smooth trimmed planar face for each corner
                         via the FEM-based surface fitting method, else multiple tangent-continuous
                         faces are used to patch corners (0-default) */
        int continuity;   /**<@brief  continuous way (0-tangent, 1-curvature) */
        int desity;       /**<@brief  the average number of sampling points along the edges of the blended corners (2~200) */

        int baseFaces;  /**<@brief  base face processing method (0-sew, 1-trim, 2-divide, 3-no action) */
        int filletFace; /**<@brief  the tangency of the new chamfer/fillet faces (0-tangent match, 1-minimal, 2-maximal) */

        int flip;       /**<@brief  1-flip the edge direction, else 0 (type = VX_CHAMFLLT_ASYMMETRIC/VX_CHAMFLLT_SETBACK_ANGLE) */
        int offsetType; /**<@brief  method of offset, 0- offset distance, 1- offset surface(default:0, only used for Charmer feature) */

        /*  use To-point* to set the value */
        svxPntOnEnt *setback1Pnt; /**<@brief  setback1 value (NULL to ignore) */
        svxPntOnEnt *setback2Pnt; /**<@brief  setback2 value (NULL to ignore) */

        /*  use set-list to set the data (edges/setback/angle) to each list */
        int cntList;                           /**<@brief  count of set list, 0-to ignore */
        svxChamFlltSetData *pChamFlltDataList; /**<@brief  data of each list, NULL to ignore */
    } svxChamFlltData;

    /* face fillet type */
    typedef enum evxFaceFlltType
    {
        VX_FACE_FFLT_FACE   = 0, /* tangent face */
        VX_FACE_FFLT_RADIUS = 1, /* by radius */
    } evxFaceFlltType;

    /* face fillet base faces type*/
    typedef enum evxFaceFlltBaseType
    {
        VX_FACE_FFLT_BASE_FACE_NONE = 0, /* none */
        VX_FACE_FFLT_BASE_FACE_SEW  = 3, /* sew */
    } evxFaceFlltBaseType;

    /* face fillet data  */
    typedef struct svxFaceFlltData
    {
        int cntFace;                  /* count face to fillet */
        int *idFace;                  /* face id list to fillet */
        evxFaceFlltType faceFlltType; /* face fillet type (VX_FACE_FFLT_FACE as default)*/
        int idTangetFace;             /* tangent face id if faceFlltType = VX_FACE_FFLT_FACE */
        double radius;                /* fillet radius if faceFlltType =  VX_FACE_FFLT_RADIUS */
        int baseFaces;                /* base faces type (VX_FACE_FFLT_BASE_FACE_SEW as default) */
        int searchFlag;               /* 1-search for undercut, else 0 (1 as default) */
    } svxFaceFlltData;

    /**
    @brief draft methods
    @ingroup zwapi_cmd_shape_data
    */
    typedef enum evxDraftMethods
    {
        VX_EDGE_DRAFT         = 1, /**<@brief  Edge Draft */
        VX_FACE_DRAFT         = 2, /**<@brief  Face Draft */
        VX_PRATING_EDGE_DRAFT = 3  /**<@brief  Parting Edge Draft */
    } evxDraftMethods;

    /**
    @brief draft type
    @ingroup zwapi_cmd_shape_data
    */
    typedef enum evxDraftType
    {
        VX_DRAFT_TYPE_NONE = 0, /**<@brief  no draft type */
        /*  Edge Draft */
        VX_SYM_EDGE_DRAFT  = 1, /**<@brief  Symmetric draft */
        VX_ASYM_EDGE_DRAFT = 2, /**<@brief  Asymmetric draft */

        /*  Face Draft */
        VX_STATION_SYM_FACE_DRAFT     = 3, /**<@brief  Stationary symmetric */
        VX_STATION_ASYM_FACE_DRAFT    = 4, /**<@brief  Stationary Asymmetric */
        VX_STATION_PARTING_FACE_DRAFT = 5, /**<@brief  Stationary and parting */
    } evxDraftType;

    /**
    @brief template command Draft data
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxDraftData
    {
        evxDraftMethods Methods; /**<@brief  Draft Methods */
        evxDraftType Type;       /**<@brief  Draft Type in options can be picked */
        int iCntDataList;        /**<@brief  Picked Entity count will be filled in list */
        int *idEnt;              /**<@brief  List of picked Entity id */
        double AngleA1;          /**<@brief  Angle A1, if only one angle it is also Angle A */
        double AngleA2;          /**<@brief  Angle A2 */

        union svxDraftStationaryEnt /**<@brief  Stationary Entity such as Faces and Edges */
        {
            struct StationaryFaces /**<@brief  Stationary faces in STATION_SYM_FACE_DRAFT(evxDraftType) and STATION_ASYM_FACE_DRAFT(evxDraftType) */
            {
                int cnt;    /**<@brief  Stationary Faces count */
                int *idEnt; /**<@brief  List of stationary Faces id */
            } stationaryFaces;

            struct StationAndPrtingFace /**<@brief  Stationary faces and Parting faces in STATION_PARTING_FACE_DRAFT(evxDraftType) */
            {
                int *StationaryFaces2; /**<@brief  List of stationary faces in STATION_PARTING_FACE_DRAFT(evxDraftType) */
                int cntStaFaces2;      /**<@brief  Stationary faces cnt */
                int *PartingFaces;     /**<@brief  List of parting faces in STATION_PARTING_FACE_DRAFT(evxDraftType) */
                int cntPrtFaces;       /**<@brief  Parting faces cnt */
            } staAndPrtFace;

            struct StationaryPlane /**<@brief  Stationary plane in PRATING_EDGE_DRAFT(evxDraftMethods) */
            {
                int cnt;    /**<@brief  Stationary Plane count */
                int *idEnt; /**<@brief  List of stationary Plane id */
            } stationaryPlane;
        } StationEnt;

        svxVector DirP;      /**<@brief  Direction P */
        int DraftSideS;      /**<@brief  Draft Side S (0 = split, 1 = top, 2 = bottom, 3 = neutral, 0 for default) */
        int Extention;       /**<@brief  Extention type (0 = linear, 1 = circular, 2 = Reflect, 3 = curvature diminishing, 0 for default) */
        int iIsrecomputeflt; /**<@brief  Whether to recompute fillets (0 = no, 1 = yes, 0 for default) */
        int iIntersections;  /**<@brief  Whether to remove intersections (0 = do not remove, 1 = remove all, 0 for default) */
        int iIsRemivtrgns;   /**<@brief  Whether to remove inverted regions (0 = no, 1 = yes, 1 for default) */
    } svxDraftData;

    /**
    @brief hole option
    @ingroup zwapi_cmd_shape_data
    */
    typedef enum evxHoleOpt
    {
        VX_GENERAL_HOLE   = 0, /**<@brief  general hole */
        VX_CLEARANCE_HOLE = 1, /**<@brief  clearance hole */
        VX_THREAD_HOLE    = 2, /**<@brief  thread hole */
        VX_PROFILE_HOLE   = 3, /**<@brief  profile hole */
    } evxHoleOpt;

    /**
    @brief hole types
    @ingroup zwapi_cmd_shape_data
    */
    typedef enum evxHoleType
    {
        VX_HOLE_SHAPE_ALL    = -1, /**<@brief  all,used in "flag holes" */
        VX_HOLE_SIMPLE       = 0,  /**<@brief  simple */
        VX_HOLE_TAPERED      = 1,  /**<@brief  tapered */
        VX_HOLE_COUNTER_BORE = 2,  /**<@brief  counter_bore */
        VX_HOLE_COUNTER_SUNK = 3,  /**<@brief  counter_sunk */
        VX_HOLE_SPOT_FACE    = 4   /**<@brief  spot_face */
    } evxHoleType;

    /**
    @brief hole type of clearance hole
    @ingroup zwapi_cmd_shape_data
    */
    typedef enum evxClearHoleType
    {
        VX_CLEAR_HOLE_SIMPLE          = 0, /**<@brief  simple */
        VX_CLEAR_HOLE_COUNT_BORE      = 2, /**<@brief  counter-Bore */
        VX_CLEAR_HOLE_COUNT_SINK      = 3, /**<@brief  counter-sink*/
        VX_CLEAR_HOLE_SLOT            = 5, /**<@brief  slot */
        VX_CLEAR_HOLE_COUNT_SINK_SLOT = 6, /**<@brief  countersink slot */
        VX_CLEAR_HOLE_COUNT_BORE_SLOT = 7, /**<@brief  counterbore slot */
    } evxClearHoleType;

    /**
    @brief hole thread types
    @ingroup zwapi_cmd_shape_data
    */
    typedef enum evxThreadType
    {
        VX_THREAD_NONE   = 1,
        VX_THREAD_CUSTOM = 2,
        VX_THREAD_M      = 3,
        VX_THREAD_UNC    = 4,
        VX_THREAD_UNF    = 5,
        VX_THREAD_ISO7   = 6,
        VX_THREAD_ISO228 = 7,
        VX_THREAD_NPT    = 8,
        VX_THREAD_NPSM   = 9,
        VX_THREAD_MC     = 10,
        VX_THREAD_MF     = 11,
        VX_THREAD_UN     = 12,
        VX_THREAD_UNEF   = 13,
        VX_THREAD_UNJ    = 14,
        VX_THREAD_UNJC   = 15,
        VX_THREAD_UNJF   = 16,
        VX_THREAD_UNJEF  = 17,
        VX_THREAD_ACME   = 18,
        VX_THREAD_BSP    = 19,
        VX_THREAD_BSTP   = 20
    } evxThreadType;

    /**
    @brief Hole chamfer, added in 1900
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxHoleChams
    {
        int fCham;        /**<@brief  Flag if chamfer */
        int fChamSym;     /**<@brief  Flag if it is symmetric chamfer */
        double chamDst;   /**<@brief  Chamfer distance */
        double chamAngle; /**<@brief  Chamfer angle */
    } svxHoleChams;

    /**
    @brief hole end conditions
    @ingroup zwapi_cmd_shape_data
    */
    typedef enum evxEndCondition
    {
        VX_BLIND       = 0, /**<@brief  blind */
        VX_UNTIL_FACE  = 1, /**<@brief  until face */
        VX_THROUGH_ALL = 2  /**<@brief  through all */
    } evxEndCondition;

    /**
    @brief hole data
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxHoleData
    {
        /*  Geometry */
        evxHoleType Type;    /**<@brief  hole type (general hole or  thread hole)*/
        int idInsFace;       /**<@brief  id of insertion face. 0 to ignore */
        int Count;           /**<@brief  number of holes */
        svxPoint *Points;    /**<@brief  list of "Count" hole insertion points
                           (calling procedure must allocate/deallocate) */
        double Diameter1;    /**<@brief  1st diameter (mm) */
        double Depth1;       /**<@brief  1st depth (mm) */
        double Diameter2;    /**<@brief  2nd diameter (mm, countersunk holes) */
        double Depth2;       /**<@brief  2nd depth (mm, countersunk holes) */
        double TaperAngle;   /**<@brief  taper angle (degrees) */
        double TipAngle;     /**<@brief  tip angle (degrees) (0 is mapped to 180, 118 is default) */
        evxEndCondition End; /**<@brief  hole end condition */
        int idUntilFace;     /**<@brief  id of "until" face (0 if not required) */
        int UseDirection;    /**<@brief  1 to use "Direction" input ; 0 for default (the hole feature(s)
                           will be perpendicular to the face)*/
        svxVector Direction; /**<@brief  optional direction for hole centerline */
        int OpNoRemove;      /**<@brief  bool operation type (0 means remove for default, 1 is none) */
        int cntShps;         /**<@brief  count of shapes.
                           if OpNoRemove = 0,apply it.
                           if OpNoRemove=0 and cngShps=0, remove default. */
        int *idShapes;       /**<@brief  list of shape id. if OpNoRemove = 0 and cntShps > 0,apply it. */
        int NoProjPntLoc;    /**<@brief  1 not to project location point, 0 to project */
        double slotLength;   /**<@brief  slot length (mm)*/
        double slotAngle;    /**<@brief  slot angle (deg)*/

        /*  Thread */
        evxThreadType ThreadType; /**<@brief  thread type */
        vxLongName ThreadSize;    /**<@brief  thread size.
                                 The size of the data is very large ,so user can find it in file Thread.xml(zw3d/supp/Thread.xml)
                                 Copy the value of "SizeValue" to "ThreadSize"
                                 Custom if ThreadSize[0] == 0 .*/
        double ThreadDiameter;    /**<@brief  thread diameter (mm) */
        double ThreadLength;      /**<@brief  thread length (mm) */
        double ThreadsPerUnit;    /**<@brief  threads per unit (0 if not used) */
        double ThreadPitch;       /**<@brief  thread pitch (mm) (0 if not used) */
        int fThrdClass;           /**<@brief  T/F flag for thread class, added in 1900 version */
        int thrdClass;            /**<@brief  thread class 1B/2B/3B, added in 1900 version */

        svxHoleChams sCham; /**<@brief  Start chamfer */
        svxHoleChams mCham; /**<@brief  Middle chamfer for counter bore or spot face bore */
        svxHoleChams eCham; /**<@brief  End chamfer */
        int fExtTap;        /**<@brief  Flag if extend with taper direction for tapered or counter-sink hole */
        int fExtStart;      /**<@brief  Flag if extend the start of hole */
        /*  Tolerance */
        int UseTol;    /**<@brief  1 to use tolerances; or 0 */
        double TolIn;  /**<@brief  inner tolerance on Diameter 1 */
        double TolOut; /**<@brief  outer tolerance on Diameter 1 */

        int UseD2Tol;    /**<@brief  T/F flag for ID2 Tol input choice, add in 1900 version */
        double D2InTol;  /**<@brief  D2 tolerance lower limit, added in 1900 version */
        double D2OutTol; /**<@brief  D2 tolerance upper limit, added in 1900 version */

        /*  Other */
        char Callout[128]; /**<@brief  callout text string */
        int DoNotMachine;  /**<@brief  1 to ignore hole in CAM, or 0 */

        /*  clearance hole/ profile hole(2700)*/
        evxHoleOpt HoleOpt;             /**<@brief  different hole to create */
        evxClearHoleType ClearHoleType; /**<@brief  hole type (when HoleOpt = VX_CLEARANCE_HOLE) */
        vxLongName Standard;            /**<@brief  user can find it in file Simple.xml(zw3d/supp/Simple.xml) */
        vxLongName Screw;               /**<@brief  user can find it in file Simple.xml(zw3d/supp/Simple.xml) */
        vxLongName Size;                /**<@brief  user can find it in file Simple.xml(zw3d/supp/Simple.xml) */
        vxLongName Fit;                 /**<@brief  "Close","Normal","Loose","Custom" */
        int idSketch;                   /**<@brief  use sketch to create the hole (HoleOpt = VX_PROFILE_HOLE, 0 to ignore) */

        /*  if Type=VX_HOLE_TAPERED, apply it. */
        int AddBase; /**<@brief  1 is add base, else 0. default:1. */
    } svxHoleData;

    /**
    @brief thread class for flag holes
    @ingroup zwapi_cmd_shape_data
    */
    typedef enum evxThreadHoleClass
    {
        VX_THREAD_HOLE_UNDEFINED, /**<@brief  undefined */
        VX_THREAD_HOLE_1B,        /**<@brief  1B */
        VX_THREAD_HOLE_2B,        /**<@brief  2B */
        VX_THREAD_HOLE_3B,        /**<@brief  3B */
    } evxThreadHoleClass;

    /**
    @brief flagged as thread hole depth type
    @ingroup zwapi_cmd_shape_data
    */
    typedef enum evxFlagThreadDepthType
    {
        VX_FLAG_THREAD_UNDEFINED,         /**<@brief  undefined */
        VX_FLAG_THREAD_DEPTH_DEFAULT,     /**<@brief  default */
        VX_FLAG_THREAD_DEPTH_1XDIAMETER,  /**<@brief  1.0 x diameter */
        VX_FLAG_THREAD_DEPTH_15XDIAMETER, /**<@brief  1.5 x diameter */
        VX_FLAG_THREAD_DEPTH_2XDIAMETER,  /**<@brief  2.0 x diameter */
        VX_FLAG_THREAD_DEPTH_25XDIAMETER, /**<@brief  2.5 x diameter */
        VX_FLAG_THREAD_DEPTH_3XDIAMETER,  /**<@brief  3.0 x diameter */
        VX_FLAG_THREAD_DEPTH_FULL,        /**<@brief  full */
        VX_FLAG_THREAD_DEPTH_CUSTOM,      /**<@brief  custom */
    } evxFlagThreadDepthType;

    /**
    @brief flag hole data
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxFlagHoleData
    {
        int FaceId;   /**<@brief  face id */
        int count;    /**<@brief  count of "HolesId" */
        int *HolesId; /**<@brief  list of hole id */

        int isUseFilter;          /**<@brief  1 if use hole filter,else 0 */
        struct svxFilterCondition /**<@brief  filter condition data */
        {
            evxHoleType HoleShape; /**<@brief  hole shape */
            int isOnlyCylindrical; /**<@brief  1 if only whole cylindrical,else 0 */
            int isDiameter;        /**<@brief  1 if edit diameter,else 0 */
            double DiameterStart;  /**<@brief  diameter start */
            double DiameterEnd;    /**<@brief  diameter end */
            int isDepth;           /**<@brief  1 if edit depth ,else 0 */
            double DepthStart;     /**<@brief  depth start */
            double DepthEnd;       /**<@brief  depth end */
        } FilterData;

        int isUseFlaggedThread; /**<@brief   1 if use flagged as thread hole,else 0 */
        vxLongName type;        /**<@brief   flag thread hole type
                                          The size of the data is very large ,so user can find it in file Thread.xml(zw3d/supp/Thread.xml)
                                          Copy the value of "StandardValue" to "type" */
        vxLongName size;        /**<@brief   flag thread hole size
                                          The size of the data is very large ,so user can find it in file Thread.xml(zw3d/supp/Thread.xml)
                                          Copy the value of "SizeValue" to "size" */
        struct svxCustomData    /**<@brief   if type[0]==0, apply it. */
        {
            double diamter; /**<@brief   diameter */
            int isPitch;    /**<@brief   1 if pitch ,else thread/unit */
            double value;   /**<@brief   isPitch is 1,value is pitch value,else Thread/Unit value */
        } custom;
        evxFlagThreadDepthType DepthType; /**<@brief   depth type
                                          if DepthType = VX_FLAG_THREAD_DEPTH_FULL, the thread depth is the hole depth.*/
        double depth;                     /**<@brief   depth : if DepthType = VX_FLAG_THREAD_DEPTH_CUSTOM,
                                          users can specify the thread depth into the hole feature.*/
        svxPntOnEnt *DepthPnt;            /**<@brief   set the depth by "To point" */

        vxLongName CalloutLabel;        /**<@brief   callout label */
        int isAddD1;                    /**<@brief   1 if add D1 tolerance ,else 0 */
        double UpperLimit;              /**<@brief   upper limit */
        double LowerLimit;              /**<@brief   lower limit */
        evxThreadHoleClass ThreadClass; /**<@brief   thread class */
        int isMachine;                  /**<@brief   1 if do not machine,else 0 */

        int isCounter; /**<@brief   1 if counter sink hole as simple hole with chamfer */
    } svxFlagHoleData;

    /**
    @brief rib data
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxRibData
    {
        int idShape;     /**<@brief  id of boolean shape, -1 to auto boolean, but since R2024, only support one shape and 
                                 it will fail if there are multi-shapes intersect with the rib*/
        int idParent;    /**<@brief  id of profile curve's parent sketch or curvelist */
        int idProfile;   /**<@brief  index of profile curve */
        int direction;   /**<@brief  extrude direction (0 = Parallel to sketch(default), 1 = Vertical to sketch) */
        int widthType;   /**<@brief  thickness type (0 = Fist side, 1 = Two sides(default), 2 = Second side) */
        double width;    /**<@brief  rib thickness (mm) (default:10)*/
        double angle;    /**<@brief  draft angle (default:0)*/
        int idPlane;     /**<@brief  draft plane, set when angle > 0.0 */
        int numBndFaces; /**<@brief  number of rib boundary faces. */
        int *idBndFaces; /**<@brief  list of rib boundary faces */
        int flipDir;     /**<@brief  flip the material direction (1 = yes, 0 = no) */
        vxName ftrName;  /**<@brief  feature name for "FtRib", 0 default */
    } svxRibData;

    /**
    @brief flag ext thread data
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxFlagExtThreadData
    {
        int count;           /**<@brief  count of "Faces" */
        svxPoint *Faces;     /**<@brief  faces */
        int *IdFaces;        /**<@brief  id(IdFaces[0]) of face(Faces[0]) */
        vxLongName type;     /**<@brief  flag thread hole type
                                          The size of the data is very large ,so user can find it in file Thread.xml(zw3d/supp/Thread.xml)
                                          Copy the value of "StandardValue" to "type" */
        vxLongName size;     /**<@brief  flag thread hole size
                                          The size of the data is very large ,so user can find it in file Thread.xml(zw3d/supp/Thread.xml)
                                          Copy the value of "SizeValue" to "size" */
        struct svxCustomInfo /**<@brief  if type[0]==0, apply it. */
        {
            double diamter; /**<@brief  diameter */
            int isThread;   /**<@brief  1 if thread/unit ,else pitch */
            double value;   /**<@brief  isThread is 0, value is pitch value,else Thread/Unit value */
            int useDiam;    /**<@brief  1-use diameter, 0 use the diameter of the first input face (default: 0) */
        } custom;
        evxFlagThreadDepthType LengthType; /**<@brief   length type */
        /**<@brief  If LengthType = VX_FLAG_THREAD_DEPTH_FULL, the thread length is the length
           of the selected cylindrical face.*/
        double length; /**<@brief  length */
        int isChamfer; /**<@brief  1 if end chamfer ,else 0 */
        /* Input the SetBack and angle to create chamfer on the end of the face nearest the selection point.*/
        double SetBack; /**<@brief  SetBack */
        double angle;   /**<@brief  angle */
    } svxFlagExtThreadData;

    /**
    @brief thread definition
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxThreadData
    {
        evxThreadType Type; /**<@brief  thread type */
        double Diameter;    /**<@brief  thread diameter (mm) */
        double Length;      /**<@brief  thread length (mm) */
        double PerUnit;     /**<@brief  threads per unit (0 if not used) */
        double Pitch;       /**<@brief  thread pitch (mm) (0 if not used) */
        int EndChamfer;     /**<@brief  1=Yes; 0=No
                           Input the setback and the angle to create chamfer
                           on the end of the face nearest the selection point.*/
    } svxThreadData;

    /**
    @brief lip data
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxLipData
    {
        /*  specified lip edge, the edge and the face specifying the first side should be set in pairs */
        int numEdges; /**<@brief  number of edges to apply lip */
        int *idEdge;  /**<@brief  list of edges to apply lip */
        int *idFace;  /**<@brief  list of faces on first side, the face must be associated with lip edge */

        double offset1; /**<@brief  the first offset distance.  Lip setback distances are +/- relative to the face normal.
                        Only -/- setback lips on convex edges and +/+ offset lips on concave edges are supported at this time.*/
        double offset2; /**<@brief  the second offset distance */
        vxName ftrName; /**<@brief  feature name for "FtLip", 0 default */
    } svxLipData;

    /**
    @brief stock type
    @ingroup zwapi_cmd_shape_data
    */
    typedef enum evxStockOpt
    {
        VX_STOCK_BLOCK    = 1, /**<@brief  block type */
        VX_STOCK_CYLINDER = 2, /**<@brief  cylinder type */
    } evxStockOpt;

    /**
    @brief stock data
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxStockData
    {
        evxStockOpt option; /**<@brief  stock type(1:Block, 2:Cylinder) */
        int numEnts;        /**<@brief  number of entities to enclose */
        int *idEnts;        /**<@brief  list of entities to enclose (shape, face, block) */
        int adjustType;     /**<@brief  Type of adjust value (0 = By side, 1 = By total) */
        int decimal;        /**<@brief  number of decimal place */
        vxName ftrName;     /**<@brief  feature name for "FtExtStock2", 0 default */

        /*  the relevant setting for stock type VX_STOCK_BLOCK */
        int idPlane;      /**<@brief  id of reference plane to orient the stock, 0 to use default
                          plane paralleled to XY datum (datum, planar face, sketch) */
        double length[2]; /**<@brief  when adjustType = 0, increment of length in the positive and negative directions
                          when adjustType = 1, stock total length, just set the first value */
        double width[2];  /**<@brief  when adjustType = 0, increment of width in the positive and negative directions
                          when adjustType = 1, stock total width, just set the first value */
        double height[2]; /**<@brief  when adjustType = 0, increment of height in the positive and negative directions
                          when adjustType = 1, stock total height, just set the first value */

        /*  the relevant setting for stock type VX_STOCK_CYLINDER */
        svxAxis axis;     /**<@brief  spiral axis to specify the rotational center of the cylinder */
        int axisPos;      /**<@brief  specify the center axis position of the cylinder
                          (0 = on the setting axis, 1 = on the center of the shape */
        double radius;    /**<@brief  when adjustType = 0, increment of radius
                          when adjustType = 1, stock radius */
        double cylHgt[2]; /**<@brief  when adjustType = 0, increment of cylinder height in the positive and negative directions
                          when adjustType = 1, cylinder total height, just set the first value */
    } svxStockData;

    //====================================================================================================================
    /** @name Edit Shape Data */
    //====================================================================================================================
    /**
    @brief shape face offset data
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxFaceOffData
    {
        int type; /**<@brief  face offset type (0 = constant, 1 = variable) */

        /*  the relevant setting for constant type (type = 0) */
        int numFaces;  /**<@brief  number of faces for offset */
        int *idFaces;  /**<@brief  list of id's of faces for offset */
        double offset; /**<@brief  offset value */

        /*  the relevant setting for variable type (type = 1), face and offset value should be set in pairs */
        int numOffsetSet;  /**<@brief  number of face offset set */
        int *idFaceSet;    /**<@brief  list of id's of faces in offset set */
        double *offsetSet; /**<@brief  list of offset value in offset set */

        int sideFaces; /**<@brief  whether to create side faces (0 = do not create, 1 = create, 2 = force) */
        int extension; /**<@brief  extension type of offset face (0 = linear, 1 = circular, 2 = reflect, 3 = curvature diminishing) */
        int intersect; /**<@brief  whether to remove self intersecting faces (0 = do not remove, 1 = remove all) */

        vxName ftrName; /**<@brief  feature name for "FtOffsetFace1", 0 default */
    } svxFaceOffData;

    /**
    @brief template command Shell input data
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxShellData
    {
        int idShape;   /**<@brief  shape S id */
        double dThick; /**<@brief  thick T */
        /*  Select which faces if any should be deleted from offset consideration.These faces will reside in the new feature but will not be offset. */
        int cntOpenFace;  /**<@brief  open faces' count */
        int *pIdOpenFace; /**<@brief  open faces' id */

        /*  set the offset value to specified face */
        int cntList;     /**<@brief  the count of the sub_data will be filled in List */
        int *pIdFace;    /**<@brief  face F ids */
        double *pOffSet; /**<@brief  offset T array ,it must be correspond to pIdFaces one by one */

        /*  Settings */
        int sideFaces;    /**<@brief  create side faces
                        0 to no   
                        1 to yes (Generally 1) :create any required side faces during the offset to maintain a closed solid*/
        int KeepPrimFace; /**<@brief  Keep primitive faces
                        0 to no (Generally 1)   
                        1 to yes : primitive faces remaining as primitive after Shell*/
        int Intersect;    /**<@brief  intersections   
                        1 to do not remove. Ignore self intersecting faces.   
                        2 to remove fast. Limited to removing self intersections on or near faces that become completely inverted,
                          such as a fillet that is offset more than its radius.(Generally 2)   
                        3 to remove all. Remove self intersections and inverted regions (including inverted inner loop cases) as
                          well as can be done. Faces that intersect other faces in the shape will be split.*/
    } svxShellData;

    /**
    @brief thicken data
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxThickenData
    {
        int type;       /**<@brief  specify the selection of object (0 = sheet, 1 = Faces) */
        double thick;   /**<@brief  thicken thickness, the value cannot be zero
                       (negative: internal offset, positive: external offset)*/
        vxName ftrName; /**<@brief  feature name for "FtThicken", 0 default */

        /* the relevant setting for sheet type (type = 0) */
        int idShape; /**<@brief  id of shape to thicken */
        int keep;    /**<@brief  whether to keep the original sheet (1 = yes, 0 = no) */

        /* the relevant setting for Faces type (type = 1) */
        int numFaces; /**<@brief  number of faces to thicken */
        int *idFaces; /**<@brief  list of faces to thicken */

        /* set additional offset, the face and the thick must be set in pairs */
        int numOffset;   /**<@brief  number of additional offset */
        int *idOffFaces; /**<@brief  list of additional offset faces */
        double *thickT;  /**<@brief  list of additional offset value */
    } svxThickenData;

    /**
    @brief divide data
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxDivideData
    {
        int numBase;    /**<@brief  number of shapes to divide */
        int *idBase;    /**<@brief  id list  of shape to divide */
        int numCutter;  /**<@brief  number of dividing entities */
        int *idCutters; /**<@brief  list of dividing entities (shape, face, datum plane) */

        /* the relevant setting for sheet type (type = 0) */
        int keepCutter; /**<@brief  whether to keep dividing entities (0 = delete, 1 = keep, 2 = divide) */
        int trimCap;    /**<@brief  whether to cap shape at the trimmed edges (1 = cap, 0 = uncap) */
        int extend;     /**<@brief  extend method (1 = no extend, 0 = linear, 2 = circular) */

        vxName ftrName; /**<@brief  feature name for "FtSolidSoloDiv", 0 default */
    } svxDivideData;

    /**
    @brief Trim data
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxTrimData
    {
        int numBase;    /**<@brief  number of shapes to trimming */
        int *idBase;    /**<@brief  id list of shape to trimming */
        int numTrimm;   /**<@brief  number of trimming entities */
        int *idTrimmer; /**<@brief  list of trimming entities (shape, face, datum plane) */

        int flip;      /**<@brief  1-flip side to keep, else 0 */
        int trimType;  /**<@brief  1-trim with all simultaneously, else 0 */
        int trimCap;   /**<@brief  whether to cap shape at the trimming edges (0 = uncap, 1 = cap) */
        int keepTrimm; /**<@brief  whether to keep trimming shapes (0 = delete, 1 = keep) */
        int extend;    /**<@brief  extend method (1 = no extend, 0 = linear, 2 = circular) */

        vxName ftrName; /**<@brief  feature name for "FtSolidSoloTrm", 0 default */
    } svxTrimData;

    /**
    @brief overflow types
    @ingroup zwapi_cmd_shape_data
    */
    typedef enum evxOverflowType
    {
        VX_OF_AUTOMATIC  = 0, /**<@brief  automatically choose the faces to extend */
        VX_OF_CHANGE     = 1, /**<@brief  extend change face */
        VX_OF_STATIONARY = 2, /**<@brief  extend stationary face */
        VX_OF_CAP        = 3, /**<@brief  extend cap face */
    } evxOverflowType;

    /**
    @brief shape replace data
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxReplaceData
    {
        int numBases;                 /**<@brief  numbers of replaced base faces */
        int *idBases;                 /**<@brief  list of id's of replaced base faces */
        int idPlace;                  /**<@brief  id of face for displacement */
        double offset;                /**<@brief  offset value */
        evxOverflowType faceOverflow; /**<@brief  used to control face overflow behavior. VX_OF_AUTOMATIC default */
        int keepReplaceFace;          /**<@brief  whether to keep the displacement face (0 = not reserve, 1 = reserve. 0 default) */
    } svxReplaceData;

    /**
    @brief inlay data
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxInlayData
    {
        int numFaces;  /**<@brief  number of faces to receive the inlay */
        int *idFaces;  /**<@brief  list of id's of faces to receive the inlay */
        int numCrvs;   /**<@brief  number of curves that defines a inlay boundary */
        int *idCrvs;   /**<@brief  list of curves that defines a inlay boundary (sketch, curve, curve list, sketch block) */
        double offset; /**<@brief  offset distance, positive raises the faces while negative sinks the faces */

        int projType;       /**<@brief  projection method (0 = in place(none), 1 = face normal, 2 = directed, 3 = bi-directional) */
        svxVector projDir;  /**<@brief  projection direction, only used when projType = 2 */
        svxVector inlayDir; /**<@brief  inlay direction of curves */
        int draftAbout;     /**<@brief  specify which plane to draft about ( 0 = base, 1 = offset, 2 = middle) */
        double draftAngle;  /**<@brief  draft angle for the side faces */
        int filletType;     /**<@brief  fillet type ( 0 = circular, 1 = chamfer) */
        int filletAbout;    /**<@brief  specify which edges to fillet ( 0 = both, 1 = base, 2 = offset) */
        double filletRad;   /**<@brief  fillet radius */

        vxName ftrName; /**<@brief  feature name for "FtInlay", 0 default */
    } svxInlayData;

    /**
    @brief part resolveSelfX data
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxPartSelfX
    {
        int numEnt;  /**<@brief number of shape entities to resolve self intersection */
        int *idEnts; /**<@brief list of shape entities to resolve self intersection */
        int region;  /**<@brief whether to remove inverted regions (0 = no, 1 = yes).Default:1. */
    } svxPartSelfX;

    /**
    @brief part punch data
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxPunch
    {
        int numBase;      /**<@brief number of base entities */
        int *idBases;     /**<@brief list of base entities' id */
        int idPunch;      /**<@brief id of punch shape entity */
        int numBound;     /**<@brief number of boundary face entities */
        int *idBounds;    /**<@brief list of boundary faces' id */
        double thickness; /**<@brief thickness represents the shell offset.default:2 */
    } svxPunch;

    //====================================================================================================================
    /** @name Morph Data */
    //====================================================================================================================
    /**
    @brief shape twist data
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxTwistData
    {
        /* Required */
        int numShapes; /**<@brief  numbers of twisted shapes */
        int *idShapes; /**<@brief  specify the shapes that will be twisted */
        int idDatum;   /**<@brief  specify a plane that defines the XY coordinate system and the twist center */
        double range;  /**<@brief  the distance to the origin of the selected datum. 100 default */
        double angle;  /**<@brief  specify the largest rotate angle in twist range. 180 default */
        /* Settings */
        svxVector *axis;  /**<@brief  specify the optional taper axis. nullptr default */
        int keepOriginal; /**<@brief  whether to keep the original shape (0 = not reserve, 1 = reserve. 0 default) */
        int miniSurfData; /**<@brief  whether to minimize surface data (0 = not minimize, 1 = minimize. 1 default) */
    } svxTwistData;

    /**
    @brief shape taper data
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxTaperData
    {
        /* Required */
        int numShapes; /**<@brief  numbers of taper shapes */
        int *idShapes; /**<@brief  specify the shapes that will be tapered */
        int idDatum;   /**<@brief  specify a plane that defines the XY coordinate system of the geometry that is to be tapered */
        double range;  /**<@brief  specify the distance to the datum. */
        double factor; /**<@brief  specify the size of the smaller side of the tapered shape. */
        /* Settings */
        svxVector *axis;  /**<@brief  specify the optional taper axis. nullptr default */
        int keepOriginal; /**<@brief  whether to keep the original shape (0 = not reserve, 1 = reserve. 0 default) */
        int miniSurfData; /**<@brief  whether to minimize surface data (0 = not minimize, 1 = minimize. 1 default) */
    } svxTaperData;

    /**
    @brief shape stretch data
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxStretchData
    {
        /* Required */
        int numShapes; /**<@brief  numbers of stretched shapes */
        int *idShapes; /**<@brief  specify the shapes that will be stretched */
        int idDatum;   /**<@brief  specify a plane that defines the XY coordinate system and the stretch center */
        /* Range */
        double xRange; /**<@brief  specify the stretch range in X direction. 100 default */
        double yRange; /**<@brief  specify the stretch range in Y direction. 100 default */
        double zRange; /**<@brief  specify the stretch range in Z direction. 100 default */
        /* Scale */
        double xScale; /**<@brief  specify the scaling factor in X direction. 100 default */
        double yScale; /**<@brief  specify the scaling factor in Y direction. 100 default */
        double zScale; /**<@brief  specify the scaling factor in Z direction. 100 default */
        /* Settings */
        int framework;    /**<@brief  controls the shape of the stretch shape (0 = Box, 1 = Ellipsoid. 0 default) */
        int uniStress;    /**<@brief  whether to use the same scaling factor (0 = not use, 1 = use. 0 default) */
        int keepOriginal; /**<@brief  whether to keep the original shape (0 = not reserve, 1 = reserve. 0 default) */
        int miniSurfData; /**<@brief  whether to minimize surface data (0 = not minimize, 1 = minimize. 1 default) */
    } svxStretchData;

    /**
    @brief shape morph to curve data
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxMorphToCrvData
    {
        /* Required */
        int numGeometry; /**<@brief  numbers of morphed shapes */
        int *idGeometry; /**<@brief  select geometry to morph */
        int idFromCurve; /**<@brief  from curve is where the morph will start */
        int idToCurve;   /**<@brief  to curve is where the morph will end */
        /* Settings */
        int miniSurfData;    /**<@brief  whether to minimize surface data (0 = not minimize, 1 = minimize. 1 default) */
        int bendOrTranslate; /**<@brief  allow the morph transformation to be a straight translation or a bend (0 = bend, 1 = translate. default = 0) */
        /**<@brief  on the Move tab, you define the Geometry that will move and the parameters that affect how much nearby geometry will move.
           on the Lock tab, you define the Stationary geometry that will not move and the same transition parameters.
           ~[0] is in Move tab, ~[1] is in Lock tab */
        double infulence[2]; /**<@brief  specify radius of influence (min = 0. default = 20) */
        int rigid[2];        /**<@brief  specify radius for rigid motion (min = 0, max = 100, inc = 1. default = 0) */
        int bulge[2];        /**<@brief  specify bulge factor for transition region (min = 0, max = 100, inc = 1. default = 50) */
        int slope[2];        /**<@brief  specify slope for transition region (min = 0, max = 100, inc = 1. default = 50) */
        int flatOrPeak[2];   /**<@brief  this determines whether the surfaces at the new point location are rounded (flat) or sharp (peak) (0 = flat, 1 = peak. default = 1) */
        int numStationary;   /**<@brief  numbers of stationary shapes */
        int *idStationary;   /**<@brief  stationary shapes */
    } svxMorphToCrvData;

    //====================================================================================================================
    /** @name Basic Editing */
    //====================================================================================================================
    /*  */
    /**
    @brief pattern method
    @ingroup zwapi_cmd_shape_data
    */
    typedef enum evxPatternType
    {
        VX_PATTERN_LINEAR,       /**<@brief  linear pattern */
        VX_PATTERN_CIRCULAR,     /**<@brief  circular pattern */
        VX_PATTERN_PNT_TO_PNT,   /**<@brief  irregular pattern of objects from point to point */
        VX_PATTERN_AT_PATTERN,   /**<@brief  pattern of objects at locations defined by a previous pattern */
        VX_PATTERN_AT_CURVES,    /**<@brief  pattern in space using one or more input curves */
        VX_PATTERN_AT_FACE,      /**<@brief  pattern in space using an existing surface */
        VX_PATTERN_POLYGON,      /**<@brief  polygon pattern */
        VX_PATTERN_FILL_PATTERN, /**<@brief  fill pattern */
        VX_PATTERN_BY_VAR,       /**<@brief  feature pattern by variant parameters(just use pattern feature command) */
    } evxPatternType;

    /**
    @brief pattern data
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxPtnData
    {
        evxBoolType combine; /**<@brief  combination method */
        evxPatternType type; /**<@brief  pattern method */

        union PtnData /**<@brief  union of part pattern data */
        {
            struct svxLinear /**<@brief  linear pattern */
            {
                int useSecondDir;  /**<@brief  whether to use second direction (0 = no, 1 = yes) */
                svxVector dir[2];  /**<@brief  first and second direction, the second direction is ignored if useSecondDir = 0 */
                int num[2];        /**<@brief  pattern number in both direction, the second direction is ignored if useSecondDir = 0 */
                double spacing[2]; /**<@brief  pattern spacing in both direction, the second direction is ignored if useSecondDir = 0 */
            } linear;
            struct svxCircular /**<@brief  circular pattern */
            {
                svxAxis axis;     /**<@brief  rotation axis for the pattern */
                double diameter;  /**<@brief  rotation diameter for the pattern */
                int useSecondDir; /**<@brief  whether to use second direction (0 = no, 1 = yes) */
                int num[2];       /**<@brief  pattern number in both direction, the second direction is ignored if useSecondDir = 0 */
                double angle;     /**<@brief  spacing between the instances measured in degrees */
                double spacing;   /**<@brief  pattern spacing in second direction, the value is ignored if useSecondDir = 0 */
            } circular;
            struct svxPolygon /**<@brief  polygon pattern */
            {
                svxAxis axis; /**<@brief  central axis for the pattern */
                int numSides; /**<@brief  number of sides, it has to be greater than 2 */

                int spacingType; /**<@brief  pattern ways (0 = number per side, 1 = pitch between instances) */
                int number;      /**<@brief  number of per side, used only when spacingType = 0 */
                double pitch;    /**<@brief  pitch between instances, used only when spacingType = 1 */

                int useSecondDir;  /**<@brief  whether to use second direction (0 = no, 1 = yes) */
                int numConcentric; /**<@brief  number of concentric polygons, the value is ignored if useSecondDir = 0 */
                double spacing;    /**<@brief  spacing of between rings radiating outward, the value is ignored if useSecondDir = 0 */
            } polygon;
            struct svxPntToPnt /**<@brief  point to point pattern */
            {
                int numPnts;   /**<@brief  number of point, parent and point value should be set in pairs */
                int *idParPnt; /**<@brief  list of id's of the parent of point, set id to 0 when no parent object exists */
                svxPoint *pnt; /**<@brief  list of point coordinates */
            } PntToPnt;
            struct svxPattern /**<@brief  pattern based on pattern */
            {
                int idPtnFtr; /**<@brief  id of pattern feature */
            } pattern;
            struct svxPtnCrv /**<@brief  curve pattern */
            {
                int curveType; /**<@brief  curve method (0 = 1 curve, 1 = 2 curves together, 2 = 2 curves across, 3 = 3~4 curves) */
                int numCrvs;   /**<@brief  number of curves, can't go beyond 4 curves */
                int *idCrvs;   /**<@brief  list of id's of curves */

                int useSecondDir;  /**<@brief  whether to use second direction (0 = no, 1 = yes) */
                int num[2];        /**<@brief  pattern number in both direction, the second direction is ignored if useSecondDir = 0 */
                double spacing[2]; /**<@brief  pattern spacing in second direction, the second direction is ignored if useSecondDir = 0 */
            } ptnCrv;
            struct svxPtnFace /**<@brief  face pattern */
            {
                int idFace;        /**<@brief  id of face */
                int useSecondDir;  /**<@brief  whether to use second direction (0 = no, 1 = yes) */
                int num[2];        /**<@brief  pattern number in both direction, the second direction is ignored if useSecondDir = 0 */
                double spacing[2]; /**<@brief  pattern spacing in second direction, the second direction is ignored if useSecondDir = 0 */
            } ptnFace;
            struct svxPntFill /**<@brief  fill pattern */
            {
                int type;       /**<@brief  type (0 = square, 1 = diamond, 2 = hexagon, 3 = concentric, 4 = spiral, 5 = along sketch curves) */
                int idSketch;   /**<@brief  id of sketch */
                double spacing; /**<@brief  pattern spacing */
                double angle;   /**<@brief  rotation angle, the value is ignored when type = 5 */
                double border;  /**<@brief  border, the value is ignored when type = 5 */
                double radius;  /**<@brief  rotation radius, used only when type is 3 or 4 */
            } ptnFill;
            struct svxPntVar /**<@brief  feature pattern by variant parameters when inpData.type = VX_PATTERN_BY_VAR */
            {
                int useSecondDir; /**<@brief  whether to use second direction (0 = no, 1 = yes) */
                int num[2];       /**<@brief  pattern number in both direction, the second direction is ignored if useSecondDir = 0 */
            } ptnVar;
        } ptnData;

        int useBasePnt;   /**<@brief  whether to use base point (0 = no, 1 = yes) */
        int idParent;     /**<@brief  id of the parent entity of point, set id to 0 when no parent object exists */
        svxPoint basePnt; /**<@brief  base point, the value is ignored if useBasePnt = 0 */
        int relocateBase; /**<@brief  whether to relocate base object (0 = no, 1 = yes)
                         1 - ensure that the array base point is at the desired array location,
                         depending on the specified base point*/

        int deriveType; /**<@brief  derive method (0 = by spacing and number, 1 = by number, 2 = by spacing) */
        double minPer;  /**<@brief  percentage of the minimum spacing, instances less than this will be deleted */
        vxName ftrName; /**<@brief  feature name, 0 default */

        int cntSkip;          /**<@brief  number of the instances to be skipped */
        int *skipList;        /**<@brief  the instances position id (exp.(0,1)-(id:1),(0,2)-(id:2),(1,0)-(id:10000),(2,5)-(id:20005)  
                         note: the first direction is column, the second direction is row.  
                         since 2700 the first direction is row, the second direction is column.  
                         If you don't know how to set the skip id, you can set the following two parameters and initialize skipList = NULL */
        int *firstTogglePos;  /**<@brief  the position id of the patterned entities in the first direction (start form 0, the nTH position in the first direction) */
        int *secondTogglePos; /**<@brief  the position id of the patterned entities in the second direction (start form 0, the nTH position in the second direction)
                            can be null if just pattern the first direction.   
                            such as: linear.num = {3,2}, linear.dir[0]  = {1,0,0}, linear.dir[1] = {0, 1, 0}   
                            y   
                            ^ O O *      if the '*' should be skipped, firstTogglePos[0] = 2, secondTogglePos[0] = 1   
                            | O & O      if the '&' should be skipped, firstTogglePos[0] = 1, secondTogglePos[0] = 0   
                            |-------> x
                         */
    } svxPtnData;

    /**
    @brief pattern geometry data
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxPtnGeom
    {
        svxPtnData *inpData; /**<@brief  base input data of pattern geometry command */
        int nonAssoCopy;     /**<@brief  non-associative copy (0 = no, 1 = yes), used only for geometry pattern   
                          if set to 0, it will create explicit geometries which can't be redefined   
                          if set to 1, the pattern instances will be associative with the original entities*/
    } svxPtnGeom;

    /**
    @brief table dimension information
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxPtnVarTbl
    {
        vxName dimName; /**<@brief  the name of the dimension to change the value */
        int cntCell;    /**<@brief  count of cells to be set */
        int *pCell;     /**<@brief  the instances position id, such as: first direction x number is 3 and second direction y number is 2, B is the base feature   
                      -----------   
                      y
                      ^ * O O      if the '*' should be modified, pCell[i] = 1;   
                      | B & O      if the '&' should be modified, pCell[i] = 10000;    
                      |-------> x   

                      normally pCell[i] = x*10000+y; and B(0,0) can't be modified.
                    */

        double *pVal; /**<@brief  the dimension value to be set. */
    } svxPtnVarTbl;

    /**
    @brief pattern feature data
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxPtnFtr
    {
        svxPtnData *inpData;     /**<@brief  base input data of pattern feature command */
        int inc;                 /**<@brief  0-the value to be set, 1- the value to be increased */
        int cntDim;              /**<@brief  count dimension to change the value */
        svxPtnVarTbl *pTableVal; /**<@brief  the table dimension information,  */
    } svxPtnFtr;

    /**
    @brief mirror geometry data
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxMirrorGeom
    {
        int numEnts; /**<@brief  number of entities to mirror */
        int *idEnts; /**<@brief  list of geometry entity ids */
        int idPlane; /**<@brief  id of mirror plane (datum plane, planar face or sketch) */

        evxBoolType combine; /**<@brief  combination method */
        int numShapes;       /**<@brief  number of shapes to boolean */
        int *idShapes;       /**<@brief  list of id's of shapes to boolean */

        int keep;     /**<@brief  whether to keep the original entities (0 = no keep, 1 = keep) */
        int assoCopy; /**<@brief  whether to keep associated with the original entities (0 = no, 1 = yes) */

        vxName ftrName; /**<@brief  feature name for "FtMirrorGeom", 0 default */
    } svxMirrorGeom;

    /**
    @brief mirror feature data
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxMirrorFtr
    {
        int numFtrs; /**<@brief  number of features to mirror */
        int *idFtrs; /**<@brief  list of features ids */
        int idPlane; /**<@brief  id of mirror plane (datum plane, planar face or sketch) */

        evxBoolType combine; /**<@brief  combination method */
        int numShapes;       /**<@brief  number of shapes to boolean */
        int *idShapes;       /**<@brief  list of id's of shapes to boolean */

        int keep;       /**<@brief  whether to keep the original features (0 = no keep, 1 = keep) */
        vxName ftrName; /**<@brief  feature name for "FtMirrorFtr", 0 default */
    } svxMirrorFtr;

    /**
    @brief Move and Copy Methods
    @ingroup zwapi_cmd_shape_data
    */
    typedef enum evxMoveType
    {
        VX_PNT_TO_PNT       = 1, /**<@brief  copy/move entities form point to point */
        VX_ALONG_DIR        = 2, /**<@brief  copy/move entities along a direction */
        VX_ASLIGN_FRAMES    = 3, /**<@brief  copy/move entities by aligning frames */
        VX_SWEEP_ALONG_PATH = 4, /**<@brief  copy/move entities along path */
        VX_AROUND_DIR       = 5, /**<@brief  rotate entities around a direction */
        VX_DYNAMIC_MOVE     = 6, /**<@brief  dynamic copy/move entities */
    } evxMoveType;

    /**
    @brief dynamic copy/move entities
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxDymMove
    {
        int MoveHand;    /**<@brief  move handle only(default 0)*/
        svxPoint Pos;    /**<@brief  Position */
        svxVector XAxis; /**<@brief  X Axis */
        svxVector YAxis; /**<@brief  Y Axis */
        svxVector ZAxis; /**<@brief  Z Axis */
    } svxDymMove;

    /**
    @brief copy/move entities form point to point
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxMovePntToPnt
    {
        svxPntOnEnt FromPnt; /**<@brief  from point */
        svxPntOnEnt ToPnt;   /**<@brief  to point */
        /*modify the alignment while moving or copying*/
        svxPntOnEnt FromVector; /**<@brief  from vector */
        svxPntOnEnt ToVector;   /**<@brief  to vector */
    } svxMovePntToPnt;

    /**
    @brief copy/move entities along a direction
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxAlongDir
    {
        svxPntOnEnt Dir; /**<@brief  direction */
        double Dist;     /**<@brief  distance value */
        int UnuseAng;    /**<@brief  angle enable (default 0) */
        double Ang;      /**<@brief  angle value */
    } svxAlongDir;

    /**
    @brief rotate entities around a direction
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxAroundDir
    {
        svxPntOnEnt Dir; /**<@brief  direction */
        double Ang;      /**<@brief  angle value */
    } svxAroundDir;

    /**
    @brief copy/move entities by aligning frames
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxAlignFrame
    {
        int idFrom; /**<@brief  from frame*/
        int idTo;   /**<@brief  to frames*/
    } svxAlignFrame;

    /**
    @brief copy/move entities along path
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxAlongPath
    {
        svxPntOnEnt Path;       /**<@brief  path */
        int cntPnts;            /**<@brief  count of points */
        svxPntOnEnt *ToPnts;    /**<@brief  to points */
        int FrameOpt;           /**<@brief  frame option(0-default frame, 1-at path, 2-selected) */
        int IdFrame;            /**<@brief  frame is selected( if FrameOpt = 2) */
        evxSweepZOpt ZAxisOpt;  /**<@brief  Z Axis option*/
        svxPntOnEnt ZAxisCurve; /**<@brief  entity data of z-axis (ignore when zOpt = VX_SWP_Z_TANG_TO_PATH)
                                   VX_SWP_Z_TANG_TO_CRV- curve(set parent if the curve from the sketch)
                                   VX_SWP_Z_FIXED_DIR - use direction (just direction or direction from an curve/edge) */
        evxSweepXOpt XAxisOpt;  /**<@brief  X Axis option (exclude VX_SWP_X_FACE_NORMAL) */
        svxPntOnEnt XAxisCurve; /**<@brief  entity data of x-axis (ignore when XAxisOpt = VX_SWP_X_MIN_TWIST)
                                   VX_SWP_X_FIXED_DIR- use direction (just direction or direction from an curve/edge) */
    } svxAlongPath;

    /**
    @brief template command Move data
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxMoveData
    {
        evxMoveType method;   /**<@brief  move methods */
        int cntEnt;           /**<@brief  entity count */
        int *pEnts;           /**<@brief  entities ID */
        union evxMethodsUnion /**<@brief union of move data */
        {
            svxDymMove DymMove;       /**<@brief  dynamic move */
            svxMovePntToPnt PntToPnt; /**<@brief  point to point */
            svxAlongDir AlongDir;     /**<@brief  along direction data*/
            svxAroundDir AroundDir;   /**<@brief  around direction data*/
            svxAlignFrame AlignFrame; /**<@brief  copy entities by aligning frames */
            svxAlongPath Sweep;       /**<@brief  sweep along path */
        } MethodUnion;
    } svxMoveData;

    /**
    @brief template command Copy data
    @ingroup zwapi_cmd_shape_data
    */
    typedef struct svxCopyData
    {
        evxMoveType method;  /**<@brief  copy methods */
        int cntEnt;          /**<@brief  entity count */
        int *pEnts;          /**<@brief  entities ID */
        union evxMethodUnion /**<@brief  union of copy data */
        {
            svxDymMove DymCopy;       /**<@brief  dynamic copy */
            svxMovePntToPnt PntToPnt; /**<@brief  point to point */
            svxAlongDir AlongDir;     /**<@brief  along direction data*/
            svxAroundDir AroundDir;   /**<@brief  around direction data*/
            svxAlignFrame AlignFrame; /**<@brief  copy entities by aligning frames */
            svxAlongPath Sweep;       /**<@brief  sweep along path */
        } MethodUnion;
        int CpyNum;        /**<@brief  copy number (just method = VX_ALONG_DIR or VX_AROUND_DIR, and must initialize to 1)*/
        int isNonAssoCopy; /**<@brief  0-associative copy, 1-non associative copy(default 0)
                                    if set to 0, the duplicate will be associative with the original entities,
                                    else(set to 1) the duplicate and the original entities will be independent of each other*/
        vxName layName;    /**<@brief  layer to copy if isNonAssoCopy is 1 */
    } svxCopyData;

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_SHAPE_FTR_DATA_H */
