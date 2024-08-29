/**
@file zwapi_cmd_assembly_data.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the Assembly
Command functions.
*/
/**
@defgroup zwapi_cmd_assembly_data Assembly Commands Data
@ingroup PartandAssemblyCommands
@brief
@details THE MODULE FOR THE ZW3D Data Types and Structures of the Assembly
Command functions.
*/

#pragma once
#ifndef ZW_API_ASSEMBLY_FTR_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_ASSEMBLY_FTR_DATA_H

#include "zwapi_util.h"
#include "zwapi_cmd_shape_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Component Insert Data */
    //====================================================================================================================
    /**
    @brief component insertion layout type
    @ingroup zwapi_cmd_assembly_data
    */
    typedef enum evxLayoutType
    {
        VX_COMP_INSERT_LAYOUT_CIRCULAR = 1, /**<@brief  circular */
        VX_COMP_INSERT_LAYOUT_LINEARE  = 2, /**<@brief  linear */
    } evxLayoutType;

    /**
    @brief component insertion position type
    @ingroup zwapi_cmd_assembly_data
    */
    typedef enum evxPositionType
    {
        VX_COMP_INSERT_POSITION_DIAMETER     = 1, /**<@brief  diameter */
        VX_COMP_INSERT_POSITION_CENTERTPOINT = 1, /**<@brief  center point */
        VX_COMP_INSERT_POSITION_OFFSET       = 2, /**<@brief  offset */
    } evxPositionType;

    /**
    @brief component insertion auto hole match filter type
    @ingroup zwapi_cmd_assembly_data
    */
    typedef enum evxCompInsHoleFilterType
    {
        VX_COMP_INSERT_HOLE_FILTER_ALL          = 0, /**<@brief  offset */
        VX_COMP_INSERT_HOLE_FILTER_SIMPLE       = 1, /**<@brief  diameter */
        VX_COMP_INSERT_HOLE_FILTER_TAPERED      = 2, /**<@brief  center point */
        VX_COMP_INSERT_HOLE_FILTER_COUNTER_BORE = 3, /**<@brief  offset */
        VX_COMP_INSERT_HOLE_FILTER_COUNTER_SINK = 4, /**<@brief  offset */
        VX_COMP_INSERT_HOLE_FILTER_SPOT_FACE    = 5, /**<@brief  offset */
    } evxCompInsHoleFilterType;

    /**
    @brief component insertion instance data
    @ingroup zwapi_cmd_assembly_data
    */
    typedef struct svxCompInsInstanceData
    {
        int AutoRegen;  /**<@brief  0 is default. 0 to set manual regen
                                       ** 1 to set auto regen before insert
                                       ** 2 to set auto regen after insert
                                       */
        int AutoDelete; /**<@brief  0 is default. 1 to delete component when parent is deleted, or 0 */

        int CopyPart;               /**<@brief  0 is default. 1 to copy "Part" before instancing, or 0. */
        vxLongName CopyName;        /**<@brief  name to assign to copied part
                                       ** if no name is given, the default name is output
                                       ** this param will take effect only when CopyPart = 1.
                                       */
        int CopyEntireAssemblyPart; /**<@brief  0 is default. 1 to copy "Part" before instancing, or 0
                                       ** this param will take effect only when CopyPart = 1.
                                       */
        int Overwrite;              /**<@brief  1(default) to prompt whether to overwrite existing part
                                       ** 0 to automatically avoid overwriting existing part
                                       ** -1 to automatically overwrite existing part
                                       */
    } svxCompInsInstanceData;

    /**
    @brief component insertion settings data
    @ingroup zwapi_cmd_assembly_data
    */
    typedef struct svxCompInsSettingsData
    {
        int Pocket;                    /**<@brief  set pocket component. 0 is default, not to pocket. 1 to pocket */
        int PocketColorFromPart;       /**<@brief  set color of pocket component.
                                       ** 0 is default, use user specified color. 1 to user color from part.
                                       ** this param will take effect only when Pocket = 1.
                                       */
        svxColor Color;                /**<@brief  set color of pocket component
                                       ** this param will take effect only when PocketColorFromPart = 0.
                                       */
        int *IntersectionEntityIdList; /**<@brief  intersection entities id list
                                       ** this param will take effect only when Pocket = 1.
                                       */
        int NumIntersectionEntity;     /**<@brief  number of intersection entities id in list.
                                       ** this param will take effect only when Pocket = 1.
                                       */

        int Envelope;      /**<@brief  envelope component. 0 is default, not to envelope. 1 to envelope. */
        int InsertToLayer; /**<@brief  insert component into specified layer, 0 is default.
                                       ** 0 - insert to active layer
                                       ** 1 - insert to specified layer
                                       */
        vxName LayerName;  /**<@brief  name of layer that component insert to.
                                       ** this param will take effect only when InsertToLayer = 1.
                                       */
        int InheritLayer;  /**<@brief  inherit component's layer, 1 is default.
                                       ** this param will take effect only when assembly layer is open.
                                       */
        int AutoActivated; /**<@brief  auto activate new inserted component, 1 is default.
                                       ** this param will take effect only when inserting a new component.
                                       */
        int Virtual;       /**<@brief  make new inserted component virtual, 0 is default.
                                       ** this param will take effect only when inserting a new component.
                                       */
    } svxCompInsSettingsData;

    /**
    @brief component data
    @ingroup zwapi_cmd_assembly_data
    */
    typedef struct svxCompData
    {
        /* Required */
        vxLongPath Dir;          /**<@brief  pathname of directory that contains "File"
                                          **  set "Dir[0]=0" to search default pathnames
                                          */
        vxLongPath File;         /**<@brief  name of file that contains "Part" */
        vxRootName Part;         /**<@brief  name of part to instance as a component */
        vxName CfgName;          /**<@brief  config name, set "CfgName[0]=0" to use active config */
        vxLongName TemplateName; /**<@brief  template name, set "TemplateName[0]=0" to use system template
                                          **taking effect only when inserting a new component.
                                          */

        /* Placement */
        int Anchor;            /**<@brief  0 is default. 1 to anchor component, or 0 */
        int IdxAlignFaceDatum; /**<@brief  index of face or datum insert to. 0 to ignore. */
        svxMatrix Frame;       /**<@brief  frame to locate component's position. */
        /* Instance */
        svxCompInsInstanceData InstanceData; /**<@brief  instance data */
        /* Settings */
        svxCompInsSettingsData SettingsData; /**<@brief  settings data */
    } svxCompData;

    /**
    @brief component insertion data(with layout)
    @ingroup zwapi_cmd_assembly_data
    */
    typedef struct svxCompInsWithLayoutData
    {
        /* Required */
        vxLongPath Dir;  /**<@brief  pathname of directory that contains "File"
                                          **  set "Dir[0]=0" to search default pathnames
                                          */
        vxLongPath File; /**<@brief  name of file that contains "Part" */
        vxRootName Part; /**<@brief  name of part to instance as a component */
        vxName CfgName;  /**<@brief  config name, set "CfgName[0]=0" to use active config */

        /* Placement */
        int Anchor;                   /**<@brief  0 is default. 1 to anchor component, or 0 */
        evxLayoutType LayoutType;     /**<@brief  layout type */
        evxPositionType PositionType; /**<@brief  position type. */
        union LayoutData
        {
            struct Circular /**<@brief  circular, taking effect only when LayoutType = VX_COMP_INSERT_LAYOUT_CIRCULAR. */
            {
                int IdxAlignFaceDatum; /**<@brief  index of face or datum to align, 0 to ignore */
                svxVector LayoutXDir;  /**<@brief  X-direction of layout */
                int Number;            /**<@brief  number of component to insert in layout */
                double Span;           /**<@brief  span of each component in layout */
                double OffsetZ;        /**<@brief  Z-direction offset of layout's coordinate system */
                /* Diameter */
                svxPoint LayoutCenter; /**<@brief  center point of layout,
                                       ** taking effect only when PositionType = VX_COMP_INSERT_POSITION_DIAMETER
                                       */
                double Diameter;       /**<@brief  distance between layout center and component center,
                                       ** taking effect only when PositionType = VX_COMP_INSERT_POSITION_DIAMETER
                                       */
                /* Offset */
                int idxArcCircle; /**<@brief  index of arc or circle,
                                       ** taking effect only when PositionType = VX_COMP_INSERT_POSITION_OFFSET
                                       */
                double Offset;    /**<@brief  layout offset from are or circle,
                                       ** taking effect only when PositionType = VX_COMP_INSERT_POSITION_OFFSET.
                                       */
            } circular;
            struct Linear /**<@brief  linear, taking effect only when LayoutType = VX_COMP_INSERT_LAYOUT_LINEARE. */
            {
                svxPoint LayoutCenter; /**<@brief  center point of layout */
                double OffsetZ;        /**<@brief  Z-direction offset of layout's coordinate system */
                int IdxAlignFaceDatum; /**<@brief  index of face or datum to align, 0 to ignore */
                svxVector LayoutXDir;  /**<@brief  X-direction of layout */
                double SpanX;          /**<@brief  span in X-direction of each component in layout */
                int NumberX;           /**<@brief  number of component in X-direction to insert in layout */
                double SpanY;          /**<@brief  span in Y-direction of each component in layout */
                int NumberY;           /**<@brief  number of component in Y-direction to insert in layout */
                /* Offset */
                svxVector LayoutYDir; /**<@brief  Y-direction of layout
                                       ** taking effect only when PositionType = VX_COMP_INSERT_POSITION_OFFSET.
                                       */
                double OffsetX;       /**<@brief  layout offset in X-direction from layout center,
                                       ** taking effect only when PositionType = VX_COMP_INSERT_POSITION_OFFSET.
                                       */
                double OffsetY;       /**<@brief  layout offset in Y-direction from layout center,
                                       ** taking effect only when PositionType = VX_COMP_INSERT_POSITION_OFFSET.
                                       */
            } linear;
        } layoutData;

        /* Instance */
        svxCompInsInstanceData InstanceData; /**<@brief  instance data */

        /* Settings */
        svxCompInsSettingsData SettingsData; /**<@brief  settings data */
    } svxCompInsWithLayoutData;

    /**
    @brief component insertion data(auto hole match)
    @ingroup zwapi_cmd_assembly_data
    */
    typedef struct svxCompInsHoleMatchData
    {
        /* Required */
        vxLongPath Dir;  /**<@brief  pathname of directory that contains "File"
                                          **  set "Dir[0]=0" to search default pathnames
                                          */
        vxLongPath File; /**<@brief  name of file that contains "Part" */
        vxRootName Part; /**<@brief  name of part to instance as a component */
        vxName CfgName;  /**<@brief  config name, set "CfgName[0]=0" to use active config */

        /* Placement */
        int Anchor;                          /**<@brief  0 is default. 1 to anchor component, or 0 */
        int IdFace;                          /**<@brief  index of location face */
        evxCompInsHoleFilterType holeFilter; /**<@brief  hole filter 0 is default and is to consider all types of hole. */
        int OnlyCylindricalBore;             /**<@brief  0 is default. 1 to only match cylindrical bores. */
        int Diameter;                        /**<@brief  0 is default. 1 to limit the matching bore in specified range. */
        double maxDiameter;                  /**<@brief  maximum diameter of matching bore. this param will take effect only when Diameter = 1 */
        double minDiameter;                  /**<@brief  minimum diameter of matching bore. this param will take effect only when Diameter = 1 */

        /* Instance */
        svxCompInsInstanceData InstanceData; /**<@brief  instance data */

        /* Settings */
        svxCompInsSettingsData SettingsData; /**<@brief  settings data */
    } svxCompInsHoleMatchData;
    /**
    @brief include component data
    @ingroup zwapi_cmd_assembly_data
    */
    typedef struct svxCompIncludeData
    {
        vxLongPath Dir;  /**<@brief pathname of directory that contains "File",
                                   set "Dir[0]=0" to search default pathnames */
        vxLongPath File; /**<@brief name of file that contains "Part", set "File[0]=0 to use current file name" */
        vxRootName Part; /**<@brief name of part to instance as a component */
        vxName CfgName;  /**<@brief config name, set "CfgName[0]=0" to use active config */
        vxName LayName;  /**<@brief layer to insert, set "LayName[0]=0" to use active layer */
    } svxCompIncludeData;

    /**
    @brief geometry export
    @ingroup zwapi_cmd_assembly_data
    */
    typedef struct svxGeomExport
    {
        int numEnts;      /**<@brief  number of geometry entities to export */
        int *idEnts;      /**<@brief  id's of geometry entities to export */
        vxLongPath File;  /**<@brief  destination file (set File[0]=0 to use active file) */
        vxRootName Part;  /**<@brief  name of destination part (new or existing) */
        svxMatrix Frame;  /**<@brief  local coordinate frame */
        int Option;       /**<@brief  0 - add import operation to destination part.  
                     ** 1 - add import operation and then "encapsulate" history.  
                     ** 2 - add import operation and then "backup" history.
                     ** (Option 1 is recommended)
                     */
        int AddComponent; /**<@brief  1 to instance part as component; else 0 . For Z3PRt, it not valid*/
        int NoExportOp;   /**<@brief  1 to disable logging of "Export" operation; else 0 */
        int Unblank;      /**<@brief  1 to unblank exported entities in destination part */
    } svxGeomExport;

    /**
    @brief copy external part data
    @ingroup zwapi_cmd_assembly_data
    */
    typedef struct svxPartInstData
    {
        vxLongPath Dir;  /**<@brief  pathname of directory that contains "File"
                     **  set "Dir[0]=0" to search default pathnames
                     */
        vxLongPath File; /**<@brief  name of ZW3D file that contains "Part" */
        vxRootName Part; /**<@brief  name of part that to be copied*/
        svxMatrix Frame; /**<@brief  insertion frame for sub-part,the insert point
                     ** is the original point of frame
                     */
        int CopyWire;    /**<@brief  1 to copy wireframe, or 0 */
        int CopyDim;     /**<@brief  1 to copy dimension, or 0 */
        int Option;      /**<@brief  0 - sub-part with associative copy.
                                 1 - sub-part with history.  
                                 2 - history copied into this part.  
                                 3 - associative copy in this part. */
    } svxPartInstData;

    /**
    @brief response to user prompt
    @ingroup zwapi_cmd_assembly_data
    */
    typedef enum evxResponse
    {
        VX_CANCEL  = -1, /**<@brief  cancel */
        VX_NO      = 0,  /**<@brief  no */
        VX_YES     = 1,  /**<@brief  yes */
        VX_YES_ALL = 2   /**<@brief  yes all */
    } evxResponse;

    //====================================================================================================================
    /** @name Assembly Constraint Data */
    //====================================================================================================================
    /**
    @brief part component/shape alignment
    @ingroup zwapi_cmd_assembly_data
    */
    typedef enum evxAlignType
    {
        VX_ALIGN_COINCIDENT    = 0, /**<@brief  coincident */
        VX_ALIGN_TANGENT       = 1, /**<@brief  tangent */
        VX_ALIGN_CONCENTRIC    = 2, /**<@brief  concentric */
        VX_ALIGN_PARALLEL      = 3, /**<@brief  parallel */
        VX_ALIGN_PERPENDICULAR = 4, /**<@brief  perpendicular */
        VX_ALIGN_ANGLE         = 5  /**<@brief  angle */
    } evxAlignType;

    /**
    @brief interference type
    @ingroup zwapi_cmd_assembly_data
    */
    typedef enum evxAlignInterference
    {
        VX_INTERFERENCE_NONE      = 0, /**<@brief  do not check for interference when dragging a component */
        VX_INTERFERENCE_HIGHLIGHT = 1, /**<@brief  when you drag a component, it will pause when interference
                                  ** is detected and the intersecting faces will highlight
                                  */
        VX_INTERFERENCE_STOP_AT   = 2, /**<@brief  this is similar to the VX_INTERFERENCE_HIGHLIGHT option 
                                  ** but the component is stopped at the point of intersection
                                  */
        VX_INTERFERENCE_ADD_ALIGN = 3  /**<@brief  add constraint */
    } evxAlignInterference;

    /**
    @brief Alignment constraint
    @ingroup zwapi_cmd_assembly_data
    */
    typedef struct svxAlign
    {
        svxData Entity1;                   /**<@brief  "isPntOnCrv" or "isPntOnFace" required */
        svxData Entity2;                   /**<@brief  "isPntOnCrv" or "isPntOnFace" required
                                      ** point must be defined in active part space
                                      ** (see cvxPntOnFace())
                                      */
        evxAlignType Type;                 /**<@brief  alignment type */
        double Offset;                     /**<@brief  distance between alignment entities */
        double Angle;                      /**<@brief  angle between alignment entities */
        int isOpposite;                    /**<@brief  1 to make entities opposite facing, else 0 */
        int ShowExistingAlign;             /**<@brief  1 to display of existing alignment constraints for the active component, else 0 */
        evxAlignInterference Interference; /**<@brief  interference options */
    } svxAlign;

    /**
    @brief assembly constraint type
    @ingroup zwapi_cmd_assembly_data
    */
    typedef enum evxConsType
    {
        VX_NONE              = 0x00000L,
        VX_CONCENTRIC        = 0x00001L,   /**<@brief  Concentric constraint */
        VX_COINCIDENT        = 0x00002L,   /**<@brief  Coincident constraint */
        VX_TANGENT           = 0x00004L,   /**<@brief  Tangent constraint */
        VX_PARALLEL          = 0x00008L,   /**<@brief  Parallel constraint */
        VX_PERPENDICULAR     = 0x00010L,   /**<@brief  Perpendicular constraint */
        VX_AT_DISTANCE       = 0x00040L,   /**<@brief  Distance constraint */
        VX_AT_ANGLE_FULL     = 0x00080L,   /**<@brief  At angle constraint */
        VX_GEAR              = 0x00100L,   /**<@brief  Gear constraint */
        VX_SYMMETRIC         = 0x00200L,   /**<@brief  Symmetry constraint */
        VX_ADV_LOCKED        = 0x00400L,   /**<@brief  Lock constraint */
        VX_ADV_MIDDLE        = 0x00800L,   /**<@brief  Middle constraint */
        VX_ADV_FRAME         = 0x01000L,   /**<@brief  Frame constraint */
        VX_ADV_PATH          = 0x02000L,   /**<@brief  Path constraint */
        VX_MC_LINEAR_COUPLER = 0x04000L,   /**<@brief  Linear couple constraint */
        VX_MC_RACK_PINION    = 0x08000L,   /**<@brief  Rack and pinion constraint */
        VX_MC_SCREW          = 0x10000L,   /**<@brief  Screw constraint */
        VX_MC_SLOT           = 0x2000000L, /**<@brief  Slot constraint */
        VX_MC_CAM            = 0x4000000L, /**<@brief  Cam constraint */
        VX_MC_UNIV_JOINT     = 0x00104L,   /**<@brief  universal joint constraint */
    } evxConsType;

    /**
    @brief custom data for assembly common constraint
    @ingroup zwapi_cmd_assembly_data
    */
    typedef struct svxConsData
    {
        int useRange;     /**<@brief  whether to apply constraint range (0-default) */
        double value;     /**<@brief  exact value: offset distance or constraint angle (0.0-default) */
        svxLimit range;   /**<@brief  constraint range: offset distance or constraint angle */
        int sameDir;      /**<@brief  same direction (0-default) */
        int posOnly;      /**<@brief  only move position without creating constraint (0-default) */
        int lockRotation; /**<@brief  whether to lock rotation (0-default) */
    } svxConsData;

    /**
    @brief custom data for assembly gear constraint
    @ingroup zwapi_cmd_assembly_data
    */
    typedef struct svxGearConsData
    {
        double angle;    /**<@brief  constraint angle (0.0-default) */
        int ratioType;   /**<@brief  ratio type (0: ratio; 1: teeth; 0-default) */
        double ratio;    /**<@brief  ratio value, used when type is ratio (1.0-default) */
        double teeth[2]; /**<@brief  teeth, used when type is teeth (0.0-default) */
        int flip;        /**<@brief  whether to flip the direction (0-default) */
    } svxGearConsData;

    /**
    @brief path constraint type
    @ingroup zwapi_cmd_assembly_data
    */
    typedef enum evxPathConsType
    {
        VX_PATH_CONS_FREE     = 0, /**<@brief  component can move along the path */
        VX_PATH_CONS_DISTANCE = 1, /**<@brief  constraint component to a specified distance from the end of the path */
        VX_PATH_CONS_PERCENT  = 2, /**<@brief  constraint component to a distance specified by a percentage from the end of the path */
    } evxPathConsType;

    /**
    @brief pitch/yaw type
    @ingroup zwapi_cmd_assembly_data
    */
    typedef enum evxPitchYawType
    {
        VX_PITCH_YAW_FREE        = 0, /**<@brief  component can move along the path */
        VX_PITCH_YAW_FOLLOW_PATH = 1, /**<@brief  constraint an axis of component to be tangent to the path */
    } evxPitchYawType;

    /**
    @brief roll control type
    @ingroup zwapi_cmd_assembly_data
    */
    typedef enum evxRollCtrlType
    {
        VX_ROLL_CTRL_FREE   = 0, /**<@brief  the roll of component is not constrained */
        VX_ROLL_CTRL_UP_VEC = 1, /**<@brief  constraint an axis of component to align with the specified vector */
    } evxRollCtrlType;

    /**
    @brief custom data for assembly path constraint
    @ingroup zwapi_cmd_assembly_data
    */
    typedef struct svxPathConsData
    {
        evxPathConsType pathConsType; /**<@brief  path constraint type (VX_PATH_CONS_FREE-default) */
        double distance;              /**<@brief  distance from the end of the path (0.0-default) */
        double percent;               /**<@brief  distance percent from the end of the path (0.0-default) */
        int flipDim;                  /**<@brief  whether to flip dimension (0-default) */

        evxPitchYawType pitchYawType; /**<@brief  pitch/yaw type (VX_PITCH_YAW_FREE-default) */
        evxAxisType axisToTangent;    /**<@brief  specify axis tangent to path (VX_AXIS_X-default) */
        int flipTangentDir;           /**<@brief  whether to flip the tangential direction (0-default) */

        evxRollCtrlType rollCtrlType; /**<@brief  roll control type (VX_ROLL_CTRL_FREE-default) */
        svxEntPath upVector;          /**<@brief  entity to specify up vector (edge, curve, face, datum plane, point) */
        evxAxisType axisToAlign;      /**<@brief  specify axis to align to the up vector (VX_AXIS_X-default) */
        int flipAlignDir;             /**<@brief  whether to flip the alignment direction (0-default) */
    } svxPathConsData;

    /**
    @brief custom data for assembly linear couple constraint
    @ingroup zwapi_cmd_assembly_data
    */
    typedef struct svxLinearCpData
    {
        int ratioType;      /**<@brief  ratio type (0: ratio; 1: distance; 0-default) */
        double ratio;       /**<@brief  ratio value, used when type is ratio (1.0-default) */
        double distance[2]; /**<@brief  distance, used when type is distance (0.0-default) */
        int flip;           /**<@brief  whether to flip the direction (0-default) */
    } svxLinearCpData;

    /**
    @brief custom data for assembly rack and pinion constraint
    @ingroup zwapi_cmd_assembly_data
    */
    typedef struct svxRackPinionData
    {
        int transType; /**<@brief  translate type (0: revolutions/distance; 1: distance/revolutions; 0-default) */
        double value;  /**<@brief  translate value (1.0-default) */
        int flip;      /**<@brief  whether to flip the direction (0-default) */
    } svxRackPinionData;

    /**
    @brief custom data for assembly screw constraint
    @ingroup zwapi_cmd_assembly_data
    */
    typedef struct svxScrewConsData
    {
        int transType; /**<@brief  translate type (0: revolutions/distance; 1: distance/revolutions; 0-default) */
        double value;  /**<@brief  translate value (1.0-default) */
        int flip;      /**<@brief  whether to flip the direction (0-default) */
        int faceDir;   /**<@brief  face direction (0: opposite; 1: same facing; 0-default) */
    } svxScrewConsData;

    /**
    @brief slot constraint type
    @ingroup zwapi_cmd_assembly_data
    */
    typedef enum evxSlotConsType
    {
        VX_SLOT_CONS_FREE     = 0, /**<@brief  component can move along the slot */
        VX_SLOT_CONS_CENTER   = 1, /**<@brief  constraint component in the center of slot */
        VX_SLOT_CONS_DISTANCE = 2, /**<@brief  constraint component to a specified distance from the end of slot */
        VX_SLOT_CONS_PERCENT  = 3, /**<@brief  constraint component to a distance specified by a percentage from the end of slot */
    } evxSlotConsType;

    /**
    @brief custom data for assembly slot constraint
    @ingroup zwapi_cmd_assembly_data
    */
    typedef struct svxSlotConsData
    {
        evxSlotConsType slotConsType; /**<@brief  slot constraint type (VX_SLOT_CONS_FREE-default) */
        double distance;              /**<@brief  distance from the end of the path (0.0-default) */
        double percent;               /**<@brief  distance percent from the end of the path (0.0-default) */
        int flip;                     /**<@brief  whether to flip dimension (0-default) */
    } svxSlotConsData;

    /**
    @brief custom data for assembly universal joint constraint
    @ingroup zwapi_cmd_assembly_data
    */
    typedef struct svxUniJointData
    {
        int jointConsType; /**<@brief  universal joint constraint type (0: constant velocity; 1: variable velocity; 1-default) */
        int flip;          /**<@brief  whether to flip dimension (0-default) */
    } svxUniJointData;

    /**
    @brief constraint state of component
    @ingroup zwapi_cmd_assembly_data
    */
    typedef enum evxConsState
    {
        VX_UNKNOWN,           /**<@brief  unknown */
        VX_UN_CONSTRAINED,    /**<@brief  the component is not constrained */
        VX_UNDER_CONSTRAINED, /**<@brief  the component can still move */
        VX_WELL_CONSTRAINED,  /**<@brief  the component is completely and correctly constrained */
        VX_FIXED,             /**<@brief  the component is fixed and will not move */
        VX_OVER_CONSTRAINED,  /**<@brief  the component has conflicting or redundant constraints */
    } evxConsState;

    //====================================================================================================================
    /** @name Basic Editing Data */
    //====================================================================================================================

    /**
    @brief assembly pattern method
    @ingroup zwapi_cmd_assembly_data
    */
    typedef enum evxAsmPatternType
    {
        VX_ASM_PTN_LINEAR,   /**<@brief linear option */
        VX_ASM_PTN_CIRCULAR, /**<@brief circular option */
        VX_ASM_PTN_POINT,    /**<@brief piont to point option */
        VX_ASM_PTN_PATTERN,  /**<@brief at pattern option */
        VX_ASM_PTN_CRV,      /**<@brief at curves option */
        VX_ASM_PTN_FACE,     /**<@brief at face option */
    } evxAsmPatternType;

    /**
    @brief  assembly pattern stagger method
    @ingroup zwapi_cmd_assembly_data
    */
    typedef enum evxAsmPtnStagger
    {
        VX_ASM_PTN_NO_STAGGER, /**<@brief no stagger option */
        VX_ASM_PTN_STAGGER,    /**<@brief stagger pattern option */
    } evxAsmPtnStagger;

    /**
    @brief assembly pattern derive method
    @ingroup zwapi_cmd_assembly_data
    */
    typedef enum evxAsmPtnDrv
    {
        VX_ASM_PTN_DRV_NONE,    /**<@brief none option */
        VX_ASM_PTN_DRV_SPACING, /**<@brief spacing option */
        VX_ASM_PTN_DRV_NUM,     /**<@brief number option */
    } evxAsmPtnDrv;

    /**
    @brief assembly pattern alignment method
    @ingroup zwapi_cmd_assembly_data
    */
    typedef enum evxAsmPtnAlg
    {
        VX_ASM_PTN_ALG_BASE, /**<@brief align with base option*/
        VX_ASM_PTN_ALG_PTN,  /**<@brief align with pattern option */
    } evxAsmPtnAlg;

    /**
    @brief assembly pattern curves method
    @ingroup zwapi_cmd_assembly_data
    */
    typedef enum evxAsmPtnCrv
    {
        VX_ASM_PTN_CRV1,        /**<@brief 1 curve option */
        VX_ASM_PTN_CRV2_TOG,    /**<@brief 2 cruves together option */
        VX_ASM_PTN_CRV2_ACROSS, /**<@brief 2 cruves across option */
        VX_ASM_PTN_CRV3,        /**<@brief 3-4 curves option */
    } evxAsmPtnCrv;

    /**
    @brief assembly pattern boundary method
    @ingroup zwapi_cmd_assembly_data
    */
    typedef enum evxAsmPtnBnd
    {
        VX_ASM_PTN_BND_AUTO,  /**<@brief move option */
        VX_ASM_PTN_BND_PALCE, /**<@brief in palce option */
        VX_ASM_PTN_BND_MOVE,  /**<@brief move option */
    } evxAsmPtnBnd;

    /**
    @brief assembly move method
    @ingroup zwapi_cmd_assembly_data
    */
    typedef enum evxAsmMoveType
    {
        VX_ASM_MOVE_PNT = 1,    /**<@brief point to point option*/
        VX_ASM_MOVE_ALONG_DIR,  /**<@brief along direction option */
        VX_ASM_MOVE_ALIGN,      /**<@brief align frames option */
        VX_ASM_MOVE_SWEEP,      /**<@brief sweep option */
        VX_ASM_MOVE_AROUND_DIR, /**<@brief around direction option */
        VX_ASM_MOVE_DYNAMIC,    /**<@brief dynamic move option */
    } evxAsmMoveType;

    /**
    @brief assembly move frame method
    @ingroup zwapi_cmd_assembly_data
    */
    typedef enum evxAsmMoveFrame
    {
        VX_ASM_MOVE_FRAME_NTR,  /**<@brief natural option */
        VX_ASM_MOVE_FRAME_PATH, /**<@brief at path option */
        VX_ASM_MOVE_FRAME_SLC,  /**<@brief selected option */
    } evxAsmMoveFrame;

    /**
    @brief assembly move z-spine method
    @ingroup zwapi_cmd_assembly_data
    */
    typedef enum evxAsmMoveZSpine
    {
        VX_ASM_MOVE_Z_NTR,      /**<@brief natural option */
        VX_ASM_MOVE_Z_SPINE,    /**<@brief spine option */
        VX_ASM_MOVE_Z_PARALLEL, /**<@brief paallel option */
    } evxAsmMoveZSpine;

    /**
    @brief assembly move x-orient method
    @ingroup zwapi_cmd_assembly_data
    */
    typedef enum evxAsmMoveXOrnt
    {
        VX_ASM_MOVE_X_NTR,   /**<@brief natural option */
        VX_ASM_MOVE_X_GUIDE, /**<@brief guide plane option */
        VX_ASM_MOVE_X_AXIS,  /**<@brief x-axis curve option */
    } evxAsmMoveXOrnt;

    /**
    @brief assembly mirror method
    @ingroup zwapi_cmd_assembly_data
    */
    typedef enum evxAsmMirrorType
    {
        VX_ASM_MIRROR_COPY, /**<@brief copy option */
        VX_ASM_MIRROR_DUP,  /**<@brief duplicate option */
    } evxAsmMirrorType;

    /**
    @brief assembly mirror self-symmetric method
    @ingroup zwapi_cmd_assembly_data
    */
    typedef enum evxAsmMirrorSymm
    {
        VX_ASM_MIRROR_SYMM_XZ,   /**<@brief XZ option */
        VX_ASM_MIRROR_SYMM_YZ,   /**<@brief YZ option */
        VX_ASM_MIRROR_SYMM_XY,   /**<@brief XY option */
        VX_ASM_MIRROR_SYMM_C,    /**<@brief C option */
        VX_ASM_MIRROR_SYMM_XCZC, /**<@brief XcZc option */
        VX_ASM_MIRROR_SYMM_YCZC, /**<@brief YcZc option */
        VX_ASM_MIRROR_SYMM_XCYC, /**<@brief XcYc option */
        VX_ASM_MIRROR_SYMM_NONE, /**<@brief none option */
    } evxAsmMirrorSymm;

    /**<@brief assembly mirror center method */
    /**
    @brief assembly mirror center method
    @ingroup zwapi_cmd_assembly_data
    */
    typedef enum evxAsmMirrorCenter
    {
        VX_ASM_MIRROR_CTR_BOX,   /**<@brief bounding box option */
        VX_ASM_MIRROR_CTR_MASS,  /**<@brief mass option */
        VX_ASM_MIRROR_CTR_FRAME, /**<@brief frame option */
    } evxAsmMirrorCenter;

    /**
    @brief assembly mirror category method
    @ingroup zwapi_cmd_assembly_data
    */
    typedef enum evxAsmMirrorCategory
    {
        VX_ASM_MIRROR_CAT_COPY, /**<@brief copy option */
        VX_ASM_MIRROR_CAT_DUP,  /**<@brief duplicate option */
        VX_ASM_MIRROR_CAT_DEL,  /**<@brief delete option */
    } evxAsmMirrorCategory;

    /**
    @brief assembly fillet arc method
    @ingroup zwapi_cmd_assembly_data
    */
    typedef enum evxAsmFlltArc
    {
        VX_ASM_FLLT_ARC_CIR,   /**<@brief circular arc type */
        VX_ASM_FLLT_ARC_CONIC, /**<@brief conic arc type */
    } evxAsmFlltArc;

    /**
    @brief assembly fillet base faces method
    @ingroup zwapi_cmd_assembly_data
    */
    typedef enum evxAsmFlltBase
    {
        VX_ASM_FLLT_BASE_NO,   /**<@brief no action option */
        VX_ASM_FLLT_BASE_DIV,  /**<@brief divide option */
        VX_ASM_FLLT_BASE_TRIM, /**<@brief trim option */
        VX_ASM_FLLT_BASE_SEW,  /**<@brief sew option */
    } evxAsmFlltBase;

    /**
    @brief assembly fillet fillet face method
    @ingroup zwapi_cmd_assembly_data
    */
    typedef enum evxAsmFlltFace
    {
        VX_ASM_FLLT_FACE_MAX,   /**<@brief maximal option */
        VX_ASM_FLLT_FACE_MIN,   /**<@brief minimal option */
        VX_ASM_FLLT_FACE_MATCH, /**<@brief tangent match option */
    } evxAsmFlltFace;

    /**
    @brief assembly fillet loop method
    @ingroup zwapi_cmd_assembly_data
    */
    typedef enum evxAsmFlltLoop
    {
        VX_ASM_FLLT_LOOP_IN,     /**<@brief inner option */
        VX_ASM_FLLT_LOOP_OUT,    /**<@brief outer option */
        VX_ASM_FLLT_LOOP_SHARE,  /**<@brief shared option */
        VX_ASM_FLLT_LOOP_BOUND,  /**<@brief boundary option */
        VX_ASM_FLLT_LOOP_ALL,    /**<@brief all option */
        VX_ASM_FLLT_LOOP_SELECT, /**<@brief selected option */
    } evxAsmFlltLoop;

    /**
    @brief assembly chamfer method
    @ingroup zwapi_cmd_assembly_data
    */
    typedef enum evxAsmChmfType
    {
        VX_ASM_CHMF_EDGE,       /**<@brief edge chamfer type */
        VX_ASM_CHMF_VERTEX = 2, /**<@brief vertex chamfer type */
    } evxAsmChmfType;

    /**
    @brief assembly chamfer base faces method
    @ingroup zwapi_cmd_assembly_data
    */
    typedef enum evxAsmChmfBase
    {
        VX_ASM_CHMF_BASE_NO,   /**<@brief no action option */
        VX_ASM_CHMF_BASE_DIV,  /**<@brief divide option */
        VX_ASM_CHMF_BASE_TRIM, /**<@brief trim option */
        VX_ASM_CHMF_BASE_SEW,  /**<@brief sew option */
    } evxAsmChmfBase;

    /**
    @brief assembly chamfer fillet face method
    @ingroup zwapi_cmd_assembly_data
    */
    typedef enum evxAsmChmfFace
    {
        VX_ASM_CHMF_FACE_MAX,   /**<@brief maximal option */
        VX_ASM_CHMF_FACE_MIN,   /**<@brief minimal option */
        VX_ASM_CHMF_FACE_MATCH, /**<@brief tangent match option */
    } evxAsmChmfFace;

    /**
    @brief assembly pattern data
    @ingroup zwapi_cmd_assembly_data
    */
    typedef struct svxAsmPtnData
    {
        evxAsmPatternType type; /**<@brief pattern method */
        int Count;              /**<@brief number of base components for pattern */
        int *idEnts;            /**<@brief list of id's of base components */
        int useDir;             /**<@brief whether to use second direction (0 = no, 1 = yes).default:0  */
        int num[2];             /**<@brief the number of pattern on two directions.default:(2,1) */
        int insComp;            /**<@brief whether instanced as component (0 = no, 1 = yes).default:0 */
        int ihrCons;            /**<@brief whether inherit constraints (0 = no, 1 = yes).default:1 */
        int atParent;           /**<@brief whether is instances' attributes at parent (0 = no, 1 = yes).default:0 */
        union svxAsmPtn         /**<@brief union of assembly Pattern data */
        {
            struct svxAsmLinear /**<@brief linear pattern */
            {
                svxVector dir[2];         /**<@brief first and second directions */
                double spacing[2];        /**<@brief the spacing of pattern in first and second directions.default:(20,20) */
                int seedOnly;             /**<@brief whether pattern seed only.(0=no,1=yes).default:0 */
                evxAsmPtnStagger stagger; /**<@brief the method of stagger.default:VX_ASM_PTN_NO_STAGGER */
            } linear;
            struct svxAsmCircular /**<@brief circular pattern */
            {
                svxVector dir;            /**<@brief first directions */
                double spacing;           /**<@brief the spacing of pattern in the directions.default:20 */
                double angle;             /**<@brief the angle of the direction.default:45 */
                evxAsmPtnDrv derive;      /**<@brief the method of derive.default:VX_ASM_PTN_DRV_NONE */
                double minimum;           /**<@brief the minimum of derive.default:0 */
                evxAsmPtnStagger stagger; /**<@brief the method of stagger.default:VX_ASM_PTN_ALG_PTN */
                evxAsmPtnAlg alignment;   /**<@brief the alignment method.default:VX_ASM_PTN_NO_STAGGER */
            } circular;
            struct svxAsmPntToPnt /**<@brief point to point pattern */
            {
                svxPntOnEnt basePnt; /**<@brief base point */
                int cnt;             /**<@brief count of toPnt */
                svxPntOnEnt *toPnt;  /**<@brief to point */
            } point;
            struct svxAsmPattern /**<@brief at pattern pattern */
            {
                svxEntPath ptnFtrPath; /**<@brief the path of pattern entity */
            } pattern;
            struct svxAsmAtCrv /**<@brief at curves pattern */
            {
                evxAsmPtnCrv crvOption;   /**<@brief the method of curves.default:VX_ASM_PTN_CRV1 */
                int numBnd;               /**<@brief the number of boundary entities, if curve option is 1 curve, numBnd = 1;
                                       if curve option is 2 curves, numBnd = 2; if curve option is 3-4 curves,
                                       numBnd is 3 or 4. */
                int *idBnd;               /**<@brief the list id of boundary entities. */
                double spacing[2];        /**<@brief the spacing of pattern in first and second directions.default:(20,20) */
                evxAsmPtnDrv derive;      /**<@brief the method of derive.default:VX_ASM_PTN_DRV_NONE */
                double minimum;           /**<@brief the minimum of derive.default:0 */
                evxAsmPtnStagger stagger; /**<@brief the method of stagger.default:VX_ASM_PTN_ALG_PTN */
                evxAsmPtnAlg alignment;   /**<@brief the alignment method.default:VX_ASMpTN_NO_STAGGER */
                int idFace;               /**<@brief the id of face(idFace<=0 to ignore) */
                int useFromPnt;           /**<@brief 1 is use fromPnt, else 0.default:0 */
                svxPntOnEnt fromPnt;      /**<@brief from point */
                evxAsmPtnBnd boundary;    /**<@brief the boundary option.default:VX_ASM_PTN_BND_AUTO */
            } curve;
            struct svxAsmAtFace /**<@brief at face pattern */
            {
                int idFace;               /**<@brief the id of face */
                double spacing[2];        /**<@brief the spacing of pattern in first and second directions.default:(20,20) */
                evxAsmPtnDrv derive;      /**<@brief the method of derive.default:VX_ASM_PTN_DRV_NONE */
                double minimum;           /**<@brief the minimum of derive.default:0 */
                evxAsmPtnStagger stagger; /**<@brief the method of stagger.default:VX_ASM_PTN_NO_STAGGER */
                evxAsmPtnAlg alignment;   /**<@brief the alignment method.default:VX_ASM_PTN_ALG_PTN */
                int useFromPnt;           /**<@brief 1 is use fromPnt, else 0.default:0 */
                svxPntOnEnt fromPnt;      /**<@brief from point */
                evxAsmPtnBnd boundary;    /**<@brief the boundary option.default:VX_ASM_PTN_BND_AUTO */
            } face;
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
    } svxAsmPtnData;

    /**
    @brief assembly move data
    @ingroup zwapi_cmd_assembly_data
    */
    typedef struct svxAsmMove
    {
        evxAsmMoveType type; /**<@brief move method */
        int Count;           /**<@brief number of base entities for move */
        int *idEnts;         /**<@brief list of id's of base entities */
        int copy;            /**<@brief whether to copy (0 = no, 1 = yes).default:0 */
        union AsmMoveData    /**<@brief union of assembly Move data */
        {
            struct svxAsmDynamic /**<@brief dynamic move */
            {
                int handle;           /**<@brief whether to move handle only (0 = no, 1 = yes).default:0 */
                svxPntOnEnt position; /**<@brief the point of position */
                svxVector xAxis;      /**<@brief the vector of x axis */
                svxVector yAxis;      /**<@brief the vector of y axis */
                svxVector zAxis;      /**<@brief the vector of z axis */
            } dynamic;
            struct svxAsmPnt /**<@brief point to point */
            {
                svxPntOnEnt fromPnt; /**<@brief from point */
                int numToPnt;        /**<@brief the number of to points */
                svxPntOnEnt *toPnt;  /**<@brief the list of to points */
                int useVec;          /**<@brief 1 if use vector,else 0. default:0 */
                svxVector fromVec;   /**<@brief from vector */
                svxVector toVec;     /**<@brief to vector */
            } pnt;
            struct svxAsmAlongDir /**<@brief along direction */
            {
                svxVector dir; /**<@brief direction vector */
                double dist;   /**<@brief distance.default:0 */
                double angle;  /**<@brief angle.default:0 */
                int useAng;    /**<@brief whether to use angle (0 = no, 1 = yes).default:1 */
                int numCopy;   /**<@brief the number of copies.default:1 */
            } alongDir;
            struct svxAsmAroundDir /**<@brief around direction */
            {
                svxVector dir;        /**<@brief direction vector */
                svxPntOnEnt location; /**<@brief axis location */
                double angle;         /**<@brief angle.default:0 */
                int numCopy;          /**<@brief the number of copies.default:1 */
            } aroundDir;
            struct svxAsmAlignFrame /**<@brief align frame */
            {
                int fromFrame; /**<@brief the id of from frame entity */
                int toFrame;   /**<@brief the id of to frame entity */
            } align;
            struct svxAsmSweep /**<@brief sweep */
            {
                svxPntOnEnt path;        /**<@brief the point of path */
                int numToPnt;            /**<@brief the number of to points */
                svxPntOnEnt *toPnts;     /**<@brief the list of to points */
                evxAsmMoveFrame frame;   /**<@brief the frame option.default:VX_ASM_MOVE_FRAME_PATH */
                evxAsmMoveZSpine zSpine; /**<@brief the z-spine option.default:VX_ASM_MOVE_Z_NTR */
                int spineCrv;            /**<@brief the id of spine curve entity */
                svxVector parallel;      /**<@brief the vector of parallel plane */
                evxAsmMoveXOrnt xOrient; /**<@brief the x-orient option.default:VX_ASM_MOVE_X_NTR */
                svxVector guide;         /**<@brief the vector of guide plane */
                int xAxisCrv;            /**<@brief the id of x-axis curve entity */
                int idSwp;               /**<@brief the id of sweep frame entity */
            } sweep;
        } move;
    } svxAsmMove;

    /**
    @brief assembly mirror data
    @ingroup zwapi_cmd_assembly_data
    */
    typedef struct svxAsmMirror
    {
        evxAsmMirrorType type;     /**<@brief mirror method */
        int Count;                 /**<@brief number of base entities for mirror */
        svxEntPath *pEnts;         /**<@brief list of path's of base entities */
        svxEntPath pPlane;         /**<@brief the path of mirror plane entity */
        int erase;                 /**<@brief whether to erase source geometry(0 = no, 1 = yes).default:0 */
        evxAsmMirrorCenter center; /**<@brief center option.default:VX_ASM_MIRROR_CTR_BOX */
        union AsmMirrorData        /**<@brief union of assembly Mirror data */
        {
            struct svxAsmCopy /**<@brief copy type */
            {
                int isDissolve;        /**<@brief 1 if dissolve mirror relation, else 0. default:0 */
                int whole;             /**<@brief whether as a whole to mirror(0 = no, 1 = yes).default:0 */
                int atParent;          /**<@brief whether instances' attributes as parent(0 = no, 1 = yes).default:0 */
                evxAsmMirrorSymm symm; /**<@brief self-symmetric option.default:VX_ASM_MIRROR_SYMM_XZ */
                svxEntPath idDatum;    /**<@brief the path of datum plane entity */
            } copy;
            struct AsmDup /**<@brief duplicate type */
            {
                int geometry;             /**<@brief whether to keep geometry associative(0 = no, 1 = yes).default:1 */
                int position;             /**<@brief whether to keep position associative(0 = no, 1 = yes).default:1 */
                evxAsmMirrorCategory cat; /**<@brief category option.default:VX_ASM_MIRROR_CAT_COPY */
                evxAsmMirrorSymm symm;    /**<@brief self-symmetric option.default:VX_ASM_MIRROR_SYMM_XZ */
                svxEntPath idDatum;       /**<@brief the path of datum plane entity */
            } duplicate;
        } mirror;
    } svxAsmMirror;

    /**
    @brief assembly cut data
    @ingroup zwapi_cmd_assembly_data
    */
    typedef struct svxAsmCut
    {
        int numCut;         /**<@brief number of cutter entities */
        svxEntPath *pCuts;  /**<@brief list of path's of cutter entities */
        int numComp;        /**<@brief number of component entities */
        svxEntPath *pComps; /**<@brief list of path's of component entities */
        int propagate;      /**<@brief whether to propagate feature to components(0 = no, 1 = yes).default:0 */
        int hide;           /**<@brief whether to hide cutter(0 = no, 1 = yes).default:0 */
    } svxAsmCut;

    /**
    @brief assembly fillet data
    @ingroup zwapi_cmd_assembly_data
    */
    typedef struct svxAsmFllt
    {
        evxChamFlltType type;    /**<@brief fillet type, "type" cannot be equal to VX_CHAMFLLT_ASYMMETRIC */
        int undercut;            /**<@brief whether to search for undercuts(0 = no, 1 = yes).default:0 */
        int blend;               /**<@brief whether to blend corners(0 = no, 1 = yes).default:0 */
        int sample;              /**<@brief whether to use specify sample density(0 = no, 1 = yes).default:0 */
        int density;             /**<@brief density.default:10 */
        evxAsmFlltBase baseFace; /**<@brief base faces option.default:VX_ASM_FLLT_BASE_SEW */
        int propagate;           /**<@brief whether to propagate feature to components(0 = no, 1 = yes).default:0 */
        int numEnt;              /**<@brief the number of entities */
        svxEntPath *pEnts;       /**<@brief the list path of entities*/
        int *vertex;             /**<@brief list of endpoints for edges (0-starting vertex, 1-end vertex),
                                         like idEdge, the number of data in this list should also be nEdges,
                                         only for VX_ASM_FLLT_VERTEX type, other types can be set to NULL */
        union svxAsmFlltData     /**<@brief union of assembly fillet data */
        {
            struct svxAsmEdge /**<@brief edge fillet type */
            {
                double R;                  /**<@brief radius.default:5 */
                double relief;             /**<@brief relief.default:0 */
                evxAsmFlltArc arc;         /**<@brief arc option.default:VX_ASM_FLLT_ARC_CIR */
                double conic;              /**<@brief conic ratio.default:0.5 */
                int hold;                  /**<@brief whether to hold fillet to edge(0 = no, 1 = yes).default:0 */
                int force;                 /**<@brief whether to force local corner(0 = no, 1 = yes).default:0 */
                int mitred;                /**<@brief whether to mitred corners(0 = no, 1 = yes).default:0 */
                int trace;                 /**<@brief whether to trace corners(0 = no, 1 = yes).default:0 */
                evxAsmFlltFace filletFace; /**<@brief fillet face option.default:VX_ASM_FLLT_FACE_MATCH */
            } edge;
            struct svxAsmLoop /**<@brief loop fillet type */
            {
                int numSel;                /**<@brief the number of selected edges entities */
                svxEntPath *pSels;         /**<@brief the list path of selected edges entities*/
                double R;                  /**<@brief radius.default:5 */
                double relief;             /**<@brief relief.default:0 */
                evxAsmFlltLoop loop;       /**<@brief loop option.default:VX_ASM_FLLT_LOOP_OUT */
                evxAsmFlltArc arc;         /**<@brief arc option.default:VX_ASM_FLLT_ARC_CIR */
                double conic;              /**<@brief conic ratio.default:0.5 */
                int hold;                  /**<@brief whether to hold fillet to edge(0 = no, 1 = yes).default:0 */
                int force;                 /**<@brief whether to force local corner(0 = no, 1 = yes).default:0 */
                int mitred;                /**<@brief whether to mitred corners(0 = no, 1 = yes).default:0 */
                int trace;                 /**<@brief whether to trace corners(0 = no, 1 = yes).default:0 */
                evxAsmFlltFace filletFace; /**<@brief fillet face option.default:VX_ASM_FLLT_FACE_MATCH */
            } loop;
            struct svxAsmVertex /**<@brief vertex fillet type */
            {
                double setback; /**<@brief setback.default:5 */
            } vertex;
        } fillet;
    } svxAsmFllt;

    /**
    @brief assembly chamfer data
    @ingroup zwapi_cmd_assembly_data
    */
    typedef struct svxAsmChmf
    {
        evxAsmChmfType type;     /**<@brief chamfer type */
        evxAsmChmfBase baseFace; /**<@brief base faces option.default:VX_ASM_CHMF_BASE_SEM */
        int propagate;           /**<@brief whether to propagate feature to components(0 = no, 1 = yes).default:0 */
        int numEnt;              /**<@brief the number of entities */
        svxEntPath *pEnts;       /**<@brief the list path of entities*/
        union svxAsmChmfData     /**<@brief assembly chamfer data */
        {
            struct svxAsmEdgeChmf /**<@brief edge chamfer type */
            {
                double S;                  /**<@brief setback.default:5 */
                int patch;                 /**<@brief whether to use patch for tight corners(0 = no, 1 = yes).default:0 */
                int force;                 /**<@brief whether to force local corner(0 = no, 1 = yes).default:0 */
                int mitred;                /**<@brief whether to mitred corners(0 = no, 1 = yes).default:0 */
                int trace;                 /**<@brief whether to trace corners(0 = no, 1 = yes).default:0 */
                int undercut;              /**<@brief whether to search for undercuts(0 = no, 1 = yes).default:0 */
                int blend;                 /**<@brief whether to blend corners(0 = no, 1 = yes).default:0 */
                int sample;                /**<@brief whether to use specify sample density(0 = no, 1 = yes).default:0 */
                int density;               /**<@brief density.default:10 */
                evxAsmChmfFace filletFace; /**<@brief fillet face option.default:VX_ASM_CHMF_FACE_MATCH */
            } edge;
            struct svxAsmVertexChmf /**<@brief vertex chamfer type */
            {
                double S; /**<@brief setback.default:10 */
            } vertex;
        } chamfer;
    } svxAsmChmf;

    //====================================================================================================================
    /** @name Inquire */
    //====================================================================================================================
    /**
    @brief Interference check result data
    @ingroup zwapi_cmd_assembly_data
    */
    typedef struct svxIferChkResData
    {
        svxEntPath BaseCompPath; /**<@brief  base component pick path for interference check */
        vxLongName BaseCompName; /**<@brief  base component name for interference check */
        svxEntPath ChkCompPath;  /**<@brief  check component pick path for interference check */
        vxLongName ChkCompName;  /**<@brief  check component name for interference check */
        double IferVolme;        /**<@brief  volume of interference (mm^3) */
        int geometryCount;       /**<@brief  count of interference geometries */
        int *geometries;         /**<@brief  index list of interference geometries */
    } svxIferChkResData;

    /**
    @brief clearance check result data
    @ingroup zwapi_cmd_assembly_data
    */
    typedef struct svxClrChkData
    {
        svxEntPath BaseCompPath; /**<@brief  base component pick path for clearance check */
        svxEntPath ChkCompPath;  /**<@brief  check component pick path for clearance check */
        svxPoint Pnt[2];         /**<@brief  points of component */
        double ClrValue;         /**<@brief  clearance value */
        int IferFlag;            /**<@brief  flag of interference */
    } svxClrChkData;

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_ASSEMBLY_FTR_DATA_H */
