/**
@file zwapi_cmd_sheetmetal_data.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the Sheet
Metal Command functions.
*/
/**
@defgroup zwapi_cmd_sheetmetal_data Sheet Metal Commands Data
@ingroup PartandAssemblyCommands
@brief
@details THE MODULE FOR THE ZW3D Data Types and Structures of the Sheet
Metal Command functions.
*/

#pragma once
#ifndef ZW_API_SHEET_METAL_FTR_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_SHEET_METAL_FTR_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Sheet Metal Attribute Data */
    //====================================================================================================================
    /**
    @brief Smd Flange Parameters Position
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef enum evxSmdPosition
    {
        VX_POSITION_MATERIAL_INSIDE,  /**<@brief  Material inside */
        VX_POSITION_MATERIAL_OUTSIDE, /**<@brief  Material outside */
        VX_POSITION_NATURAL,          /**<@brief  Natural */
        VX_POSITION_OFFSET,           /**<@brief  Offset */
        VX_POSITION_VIRTUAL_SHARP,    /**<@brief  Virtual sharp */
    } evxSmdPosition;

    /**
    @brief Smd Bend Attributes Length type
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef enum evxSmdBendLengthType
    {
        VX_BEND_STANDARD_LENGTH,     /**<@brief  Standard length */
        VX_BEND_OUTER_HEIGHT,        /**<@brief  Outer height */
        VX_BEND_INNER_HEIGHT,        /**<@brief  Inner height */
        VX_BEND_EXTRAPOLATED_LENGTH, /**<@brief  Extrapolated length */
    } evxSmdBendLengthType;

    /**
    @brief K-factor Definition type
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef enum evxSmdKFactorType
    {
        VX_SMD_KTYPE_CUSTOM,                 /**<@brief  custom */
        VX_SMD_KTYPE_FROM_MATERIAL,          /**<@brief  from material */
        VX_SMD_KTYPE_BEND_TABLE,             /**<@brief  bend table */
        VX_SMD_KTYPE_BEND_ALLOWANCE_TABLE,   /**<@brief  bend allowance table */
        VX_SMD_KTYPE_BEND_ALLOWANCE_FORMULA, /**<@brief  bend allowance formula */
        VX_SMD_KTYPE_BEND_DEDUCTION_TABLE,   /**<@brief  bend deduction table */
        VX_SMD_KTYPE_BEND_DEDUCTIOIN,        /**<@brief  bend deduction */
        VX_SMD_KTYPE_BEND_ALLOWANCE,         /**<@brief  bend allowance, svxExtrudeFlangeData::kType do not apply it. */
    } evxSmdKFactorType;

    /**
    @brief Smd Relief type
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef enum evxSmdRelief
    {
        VX_RELIEF_RECTANGLE = 0, /**<@brief  Rectangle */
        VX_RELIEF_OBROUND   = 1, /**<@brief  Obround */
        VX_RELIEF_NONE      = 2, /**<@brief  None */
        VX_RELIEF_STRETCH   = 3, /**<@brief  Stretch */
    } evxSmdRelief;

    /**
    @brief Smd Relief type of Corner Attributes
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef enum evxSmdCornerRelief
    {
        VX_CORNER_RELIEF_CLOSED,             /**<@brief  closed */
        VX_CORNER_RELIEF_CIRCULAR_CUTOUT,    /**<@brief  circular cutout */
        VX_CORNER_RELIEF_RECTANGULAR_CUTOUT, /**<@brief  rectangular cutout */
        VX_CORNER_RELIEF_U_CUTOUT,           /**<@brief  U cutout */
        VX_CORNER_RELIEF_V_CUTOUT,           /**<@brief  V cutout */
    } evxSmdCornerRelief;

    /**
    @brief sheet metal attribute
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef struct svxSmdAt
    {
        /*  Global Value */
        double dThick;  /**<@brief  thickness (1.0 as default)*/
        double dRadius; /**<@brief  radius (5.0 as default) */
        /*  Flange Parameters */
        evxSmdPosition position;         /**<@brief  sheet metal position.default:VX_POSITION_NATURAL */
        double dOffset;                  /**<@brief  specify the offset value of the flange if position = VX_POSITION_OFFSET, else ignore.default:0 */
        evxSmdBendLengthType lengthType; /**<@brief  length type.default:VX_BEND_STANDARD_LENGTH */
        double dLength;                  /**<@brief  flange length.default:40 */
        /*  K-factor */
        evxSmdKFactorType kType; /**<@brief  active sheet metal K factor type*/
        double dKFactor;         /**<@brief  K-Factor (0.41 as default) */
        double dKBendDed;        /**<@brief  bend deduction.default:3.5 */
        double dKBendAllow;      /**<@brief  bend allowance.default:8.5 */
        /*  Relief */
        evxSmdRelief reliefType; /**<@brief  relief type.default:VX_RELIEF_OBROUND */
        double dWidRatio;        /**<@brief  relief width ratio.default:1.5 */
        double dWidValue;        /**<@brief  relief width value.default:1 */
        double dDepRatio;        /**<@brief  relief depth ratio.default:0 */
        double dDepValue;        /**<@brief  relief depth value.default:1 */
        /*  Corner Attributes */
        int isCloseCorner;                /**<@brief  corner close type.default:0 */
        int isMiter;                      /**<@brief  corner miter type.default:1 */
        evxSmdCornerRelief reliefCorType; /**<@brief  corner relief type.default:VX_CORNER_RELIEF_CLOSED */
        double dCorGap;                   /**<@brief  corner gap.default:0.1 */
        int iCorOrigin;                   /**<@brief  corner origin.default:0 */
        double dCorOffset;                /**<@brief  corner offset.default:-1 */
        double dCorLength;                /**<@brief  corner length.default:4 */
        double dCorWidth;                 /**<@brief  corner width.default:4 */
        double dCorDiameter;              /**<@brief  corner diameter.default:4 */
        double dCorAngle1;                /**<@brief  corner angle 1.default:30 */
        double dCorAngle2;                /**<@brief  corner angle 2.default:30 */
        /*  setting */
        double dFlatTol; /**<@brief  flat tolerance.default:0.1 */
    } svxSmdAt;

    /**
    @brief the enumeration is used to determine whether the values in the "svxSmdReliefData" are custom
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef enum evxSmdCalCustom
    {
        VX_CUSTOM_RELIEF       = 0x00000001, /**<@brief  "relief" is a custom value */
        VX_CUSTOM_ISWIDTHRATIO = 0x00000002, /**<@brief  "isWidthRatio" is a custom value */
        VX_CUSTOM_RELIEFWIDTH  = 0x00000004, /**<@brief  "ReliefWidth" is a custom value */
        VX_CUSTOM_ISDEPTHRATIO = 0x00000008, /**<@brief  "isDepthRatio" is a custom value */
        VX_CUSTOM_RELIEFDEPTH  = 0x00000010, /**<@brief  "ReliefDepth" is a custom value */
    } evxSmdCalCustom;

    /**
    @brief Smd Relief Length Type of Flange
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef enum evxSmdReliefLengthType
    {
        VX_RELIEF_LENGTH_TYPE_TO_EDGE,     /**<@brief  to edge */
        VX_RELIEF_LENGTH_TYPE_THROUGH_ALL, /**<@brief  through all */
        VX_RELIEF_LENGTH_TYPE_VALUE        /**<@brief  value */
    } evxSmdReliefLengthType;

    /**
    @brief Smd Relief data, use cvxPartSmdReliefDataInit to initialize it
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef struct svxSmdReliefData
    {
        int isCustom;        /**<@brief  the value of "isCustom" indicates whether the following variables use custom values(evxSmdCalCustom)
                                       ( 1 ~~ 31 )
                                       if isCustom = VX_CUSTOM_ISWIDTHRATIO | VX_CUSTOM_RELIEFWIDTH,
                                       "isWidthRatio" and "ReliefWidth" are custom value, other values use global default.
                                       you can ignore this parameter when initializing it with cvxPartSmdReliefDataInit() */
        evxSmdRelief relief; /**<@brief  relief type. default is global value */
        /* length */
        int upToBend;                      /**<@brief  1 if up to bend. default is 0 */
        evxSmdReliefLengthType lengthType; /**<@brief  length type. default is VX_RELIEF_LENGTH_TYPE_TO_EDGE */
        double lengthVal;                  /**<@brief  length value. when lengthType = VX_RELIEF_LENGTH_TYPE_VALUE, apply it. */
        /* width */
        int isWidthRatio;   /**<@brief  1 if relief width ratio, else 2 is value. default is global value */
        double ReliefWidth; /**<@brief  ratio or value. default is global value */
        /* depth */
        int isDepthRatio;   /**<@brief  1 if relief depth ratio, else 2 is value. default is global value */
        double ReliefDepth; /**<@brief  ratio or value. default is global value */
    } svxSmdReliefData;

    //====================================================================================================================
    /** @name Base Data */
    //====================================================================================================================
    /**
    @brief Smd extrude type
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef enum evxExtFlangeType
    {
        VX_EXTFLANGE_1SIDE,       /**<@brief  1 side */
        VX_EXTFLANGE_2SIDES,      /**<@brief  2 sides */
        VX_EXTFLANGE_SYMMETRICAL, /**<@brief  symmetrical */
    } evxExtFlangeType;

    /**
    @brief template command Smd Extrude Tab data
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef struct svxSmdExtrudeTabData
    {
        int idProfile;     /**<@brief  id of profile */
        double *Thickness; /**<@brief  thickness. NULL to use global default */
        int isMerge;       /**<@brief  1 if merge, else 0 as default */
        int isOpposite;    /**<@brief  1 if opposite the direction of the tab, else 0 as default */
        int idMergeShape;  /**<@brief  id of the shape to be merged.
                            Note:since 2700, this parameter must be set, if you don't set this parameter before,
                            you can find the shape where the profile is located as the base shape. */
    } svxSmdExtrudeTabData;

    /**
    @brief template command Smd Extrude Flange data
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef struct svxExtrudeFlangeData
    {
        int idProfile;            /**<@brief  id of profile */
        evxExtFlangeType extType; /**<@brief  extrude type */
        double start;             /**<@brief  start distance */
        double end;               /**<@brief  end distance */
        double *thickness;        /**<@brief  thickness. NULL to use default */
        int isOpposite;           /**<@brief  1 if opposite the direction of the flange, else 0 (default:0) */
        double *radius;           /**<@brief  radius NULL to use default */
        evxSmdKFactorType *kType; /**<@brief  k_factor definition type. NULL to use default
                                   K-Factor indicates the location of the neutral axis within the thickness of the sheet metal,
                                   and is affected by multiple factors.*/
        double *kValue;           /**<@brief  k_factor. NULL to use default */
        svxPntOnEnt *PntOnCrv;    /**<@brief  rip point, point on curve, (NULL to ignore) */
        double RipSize;           /**<@brief  rip size. the minimum value of "RipSize" is twice the tolerance */
    } svxExtrudeFlangeData;

    /**
    @brief Smd Bend Type of Flange
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef enum evxSmdBendType
    {
        VX_BEND_SIMPLE        = 0,  /**<@brief  Simple */
        VX_BEND_S_BEND        = 1,  /**<@brief  S bend */
        VX_BEND_CLOSED        = 5,  /**<@brief  Closed */
        VX_BEND_OPEN          = 6,  /**<@brief  Open */
        VX_BEND_JOGGLE        = 4,  /**<@brief  Joggle */
        VX_BEND_CURL          = 2,  /**<@brief  Curl */
        VX_BEND_Z_BEND        = 7,  /**<@brief  Z bend */
        VX_BEND_CLOSED_LOOP   = 8,  /**<@brief  Closed loop */
        VX_BEND_OPEN_LOOP     = 9,  /**<@brief  Open loop */
        VX_BEND_CENTERED_LOOP = 10, /**<@brief  Centered loop */
        VX_BEND_USER_DEFINED  = 11  /**<@brief  user defined */
    } evxSmdBendType;

    /**
    @brief template command Smd Flange data
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef struct svxSmdFlangeData
    {
        /* Required */
        int count;     /**<@brief  count of idEdges */
        int *idEdges;  /**<@brief  list of idEdges */
        int widthType; /**<@brief  width type: 0 = use start and end, 1 = use start and length, default = 0 */
        double start;  /**<@brief  start */
        double end;    /**<@brief  end */
        double length; /**<@brief  length */
        int isFlip;    /**<@brief  flip flanges direction: 1 = flip, default = 0 */
        /* Flange Parameters */
        evxSmdPosition position; /**<@brief  flange parameters position. default = global value */
        double positionOffset;   /**<@brief  position offset. if position = VX_POSITION_OFFSET, apply it. default = global value */
        /* Bend Attributes */
        /*
           evxSmdBendType            |                        the following variables is valid
        VX_BEND_SIMPLE               |       radius1, length1, angle, lengthType
        VX_BEND_S_BEND               |       radius1, radius2(isEqualR), length1, length2, height, lengthType, sBendSize,
        VX_BEND_CLOSED               |       length1
        VX_BEND_OPEN                 |       radius1, length1
        VX_BEND_JOGGLE               |       length1, length2
        VX_BEND_CURL                 |       radius1, radius2, length1, length2
        VX_BEND_Z_BEND               |       radius1, radius2(isEqualR), length1, length2
        VX_BEND_CLOSED_LOOP          |       radius1, length1
        VX_BEND_OPEN_LOOP            |       radius1, angle
        VX_BEND_CENTERED_LOOP        |       radius1, radius2(isEqualR), angle
        VX_BEND_USER_DEFINED         |       radius1, idProfile
        */
        evxSmdBendType bendType;         /**<@brief  bend type. default = VX_BEND_SIMPLE */
        double radius1;                  /**<@brief  radius1. default = global value */
        double radius2;                  /**<@brief  radius2. default = global value */
        double length1;                  /**<@brief  length1 */
        double length2;                  /**<@brief  length2 */
        double angle;                    /**<@brief  angle */
        double height;                   /**<@brief  height */
        evxSmdBendLengthType lengthType; /**<@brief  length type. default = global value */
        int sBendSize;                   /**<@brief  s bend size. 0 = use height, 1 = use length2, default = 0 */
        int isEqualR;                    /**<@brief  judge if radius2 equals radius1. 1 = equal, default = 0 */
        int isTrim;                      /**<@brief  trim adjacent bends. 1 = trim, default = 0 */
        int idProfile;                   /**<@brief  id of profile */
        /* K-factor Definition */
        /*
             evxSmdKFactorType            |           kValue
        VX_SMD_KTYPE_CUSTOM               |     VsSmdAt.k_factor
        VX_SMD_KTYPE_BEND_DEDUCTIOIN      |     VsSmdAt.d_k_bend_ded
        VX_SMD_KTYPE_BEND_ALLOWANCE       |     VsSmdAt.d_k_bend_allow
                 others                   |              0
        */
        evxSmdKFactorType kType; /**<@brief  k-factor definition type. default = global value
                                              K-Factor indicates the location of the neutral axis within the thickness of the sheet metal,
                                              and is affected by multiple factors.*/
        double kValue;           /**<@brief  k_factor depends on kType. default = global value */
        /* Relief */
        int isRelief;                 /**<@brief  relief for insufficient length. 1 = relief, default = 0 */
        int isDefine;                 /**<@brief  define each side separately. 0 = use startRelief only,
                                              1 = use both startRelief and endRelief, default = 0 */
        svxSmdReliefData startRelief; /**<@brief  relief of start. default = global value */
        svxSmdReliefData endRelief;   /**<@brief  relief of end. default = global value */
        /* Flange Interface */
        int isResolve;          /**<@brief  resolve flange interface. 1 = resolve, default = 0 */
        double interfaceGap;    /**<@brief  interface gap. default = 0.5 */
        double interfaceOffset; /**<@brief  interface offset. default = 0.5 */
        int interfaceType;      /**<@brief  interface type. 1 = open, 0 = closed, default = 0 */
        /*  Corner Attributes */
        /*
             evxSmdCornerRelief               |                 the following variables is valid
        VX_CORNER_RELIEF_CLOSED               |     isMiter, corGap
        VX_CORNER_RELIEF_CIRCULAR_CUTOUT      |     isMiter, corGap, corOrigin, corOffset, corDiameter
        VX_CORNER_RELIEF_RECTANGULAR_CUTOUT   |     isMiter, corGap, corOrigin, corOffset, corLength, corWidth
        VX_CORNER_RELIEF_U_CUTOUT             |     isMiter, corGap, corOrigin, corOffset, corDiameter
        VX_CORNER_RELIEF_V_CUTOUT             |     isMiter, corGap, corOrigin, corOffset, corDiameter, corAngle1, corAngle2
        */
        int isCorner;                 /**<@brief  1 = close corner, 0 = ignore corner attributes, default = global value.  */
        int isMiter;                  /**<@brief  1 = miter corner, default = global value.
                                              if set to 0, use straight lines to form the outline of the cuter which is going to cut the corner on the unfold pattern
                                              if set to 1, use curves to form the outli8ne of the cuter which is trying to meet the defined Gap around the corner. */
        evxSmdCornerRelief corRelief; /**<@brief  corner relief type. default = global value */
        double corGap;                /**<@brief  corner Gap. default = global value */
        int corOrigin;                /**<@brief  0 = bend center, 1 = corner point. default = global value */
        double corOffset;             /**<@brief  offset. default = global value */
        double corLength;             /**<@brief  length. default = global value */
        double corWidth;              /**<@brief  width. default = global value */
        double corDiameter;           /**<@brief  diameter. default = global value */
        double corAngle1;             /**<@brief  angle 1. default = global value */
        double corAngle2;             /**<@brief  angle 2. default = global value */
        /* Settings */
        double tol; /**<@brief  Flat Tolerance. (Refers to the flat tolerance allowed for
                                              sheet metal parts in their unfolded state.) default = global value */
    } svxSmdFlangeData;

    //====================================================================================================================
    /** @name Flange Data */
    //====================================================================================================================
    /**
    @brief template command Smd Full Flange data
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef struct svxSmdFullFlangeData
    {
        int count;                /**<@brief  count of "idEdges" */
        int *idEdges;             /**<@brief  list of idEdge*/
        int isFlip;               /**<@brief  indicate flange direction: 1 if flip the flanges, else 0 as default */
        evxSmdPosition *position; /**<@brief  flange parameters position. NULL to use global default */
        double *offset;           /**<@brief  offset, if position = VX_POSITION_OFFSET,apply it. NULL to use global default */
        evxSmdKFactorType *kType; /**<@brief  k_factor definition type. NULL to use global default
                                              K-Factor indicates the location of the neutral axis within the thickness of the sheet metal,
                                              and is affected by multiple factors.*/
        double *kValue;           /**<@brief  k_factor. NULL to use global default */
        double *tol;              /**<@brief  Flat Tolerance. (Refers to the flat tolerance allowed for
                                              sheet metal parts in their unfolded state.) NULL to use global default */
        int isResolve;            /**<@brief  1 if resolve flange interference ,else 0 as default
                                              1-to make the flanges not intersect when the created flanges are intersected. */
        double gap;               /**<@brief  Gap. 0.5 is default */
        /*  Bend Attributes */
        int bend;                         /**<@brief  bend, 0 if simple, 1 if S bend. default is 0 */
        double *radius1;                  /**<@brief  radius r1. NULL to use global default */
        double angle;                     /**<@brief  angle (> 0). 90 as default */
        evxSmdBendLengthType *lengthType; /**<@brief  length type. NULL to use global default */
        double *length;                   /**<@brief  length. NULL to use global default */
        double *radius2;                  /**<@brief  radius r2, if bend = 0, ignore this. NULL to use global default */
        int sBendSize;                    /**<@brief  S bend size (1 is length, 0 is height), if bend = 0, ignore this. */
        double Size;                      /**<@brief  size (height or length), if bend = 0, ignore this */
        /*  Relief */
        int isDefSepa;                 /**<@brief  1 if define each side separately, else 0 as default */
        svxSmdReliefData *startRelief; /**<@brief  relief of start */
        svxSmdReliefData *endRelief;   /**<@brief  relief of end. if isDefineSeparately = 0, ignore this */
        /*  Corner Attributes */

        /**
        @brief corner relief type. NULL to use global default
        @verbatim
             evxSmdCornerRelief               |     the following variables is valid 
        VX_CORNER_RELIEF_CLOSED               |  isMiter,corGap 
        VX_CORNER_RELIEF_CIRCULAR_CUTOUT      |  isMiter,corGap,corOrigin,corOffset,corDiameter 
        VX_CORNER_RELIEF_RECTANGULAR_CUTOUT   |  isMiter,corGap,corOrigin,corOffset,corLength,corWidth 
        VX_CORNER_RELIEF_U_CUTOUT             |  isMiter,corGap,corOrigin,corOffset,corDiameter 
        VX_CORNER_RELIEF_V_CUTOUT             |  isMiter,corGap,corOrigin,corOffset,corDiameter,corAngle1,corAngle2
        @endverbatim
        */
        evxSmdCornerRelief *corRelief;
        int *isCorner;       /**<@brief  1 if close corner, else 0.   
                                              NULL to use global default   
                                              if isCorner = 0, ignore the following variables */
        int *isMiter;        /**<@brief  1 if miter corner, else 0. NULL to use global default    
                                              if set to 0, use straight lines to form the outline of the cuter which is going to cut the corner on the unfold pattern    
                                              if set to 1, use curves to form the outli8ne of the cuter which is trying to meet the defined Gap around the corner. */
        double *corGap;      /**<@brief  corner Gap. NULL to use global default */
        int *corOrigin;      /**<@brief  0 is bend center, 1 is corner point. NULL to use global default */
        double *corOffset;   /**<@brief  offset. NULL to use global default */
        double *corLength;   /**<@brief  length. NULL to use global default */
        double *corWidth;    /**<@brief  width. NULL to use global default */
        double *corDiameter; /**<@brief  diameter. NULL to use global default */
        double *corAngle1;   /**<@brief  angle 1. NULL to use global default */
        double *corAngle2;   /**<@brief  angle 2. NULL to use global default */
    } svxSmdFullFlangeData;

    /**
    @brief template command Smd Flange with Profile data
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef struct svxSmdFlangeProfData
    {
        int idEdge;               /**<@brief  id of edge */
        int *idProfile;           /**<@brief  id of profile, NULL to ignore */
        evxSmdPosition *position; /**<@brief  position type. NULL to use global default */
        double *offset;           /**<@brief  offset, specify the offset value of the flange.
                                              if *position = VX_POSITION_OFFSET, using this. NULL to use global default */
        /*  Bend Attributes */
        double *radius;                   /**<@brief  radius. NULL to use global default */
        double angle;                     /**<@brief  angle (0-180). 90 as default */
        evxSmdBendLengthType *lengthType; /**<@brief  length type. NULL to use global default */
        double *length;                   /**<@brief  length. NULL to use global default */
        /*  K-factor Definition */
        evxSmdKFactorType *kType; /**<@brief  k_factor definition type. NULL to use global default
                                              K-Factor indicates the location of the neutral axis within the thickness of the sheet metal,
                                              and is affected by multiple factors.*/
        double *kValue;           /**<@brief  k_factor. NULL to use global default */
        /*  Relief */
        int isRelief;                  /**<@brief  1 if relief for insufficient length , else 0 as default
                                              if set to 1, user can create relief for partial flange even the length between
                                              the bound of the flange and the end of the picked edge which is insufficient.*/
        int isDefSepa;                 /**<@brief  1 if define each side separately ,else 0 as default */
        svxSmdReliefData *startRelief; /**<@brief  relief of start */
        svxSmdReliefData *endRelief;   /**<@brief  relief of end. if isDefineSeparately = 0, ignore this */

        double *tol; /**<@brief  Flat Tolerance. NULL to use global default */
    } svxSmdFlangeProfData;

    /**
    @brief template command Smd Partial Flange data
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef struct svxSmdPartialFlangeData
    {
        int idEdge;               /**<@brief  id of edge */
        int isRevert;             /**<@brief  1 if switch start point, else 0 as default */
        int isFlip;               /**<@brief  1 if flip the flange, else 0 as default */
        int widthType;            /**<@brief  0 is Start-Width, 1 is Start-End. default is 0 */
        double start;             /**<@brief  start(>=0) */
        double end;               /**<@brief  end(!=start). if widthType = 1, using this */
        double width;             /**<@brief  width(>=start). if widthType = 0, using this */
        evxSmdPosition *position; /**<@brief  position type. NULL to use global default */
        double *offset;           /**<@brief  offset. if *position = VX_POSITION_OFFSET, using this. NULL to use global default */
        /*  Bend Attributes */
        int bend;                         /**<@brief  bend, 0 if simple, 1 if S bend. default is 0 */
        double *radius1;                  /**<@brief  radius r1. NULL to use global default */
        double angle;                     /**<@brief  angle (>0). 90 as default */
        evxSmdBendLengthType *lengthType; /**<@brief  length type. NULL to use global default */
        double *length;                   /**<@brief  length. NULL to use global default */
        double *radius2;                  /**<@brief  radius r2, if bend = 0, ignore this. NULL to use global default */
        int sBendSize;                    /**<@brief  S bend size (1 is length, 0 is height), if bend = 0, ignore this. */
        double Size;                      /**<@brief  size (height or length), if bend = 0, ignore this */
        /*  K-factor Definition */
        evxSmdKFactorType *kType; /**<@brief  k_factor definition type. NULL to use global default
                                              K-Factor indicates the location of the neutral axis within the thickness of the sheet metal,
                                              and is affected by multiple factors.*/
        double *kValue;           /**<@brief  k_factor. NULL to use global default */
        /*  Relief */
        int isRelief;                  /**<@brief  1 if relief for insufficient length , else 0 as default */
        int isDefSepa;                 /**<@brief  1 if define each side separately ,else 0 as default */
        svxSmdReliefData *startRelief; /**<@brief  relief of start */
        svxSmdReliefData *endRelief;   /**<@brief  relief of end. if isDefSepa = 0, ignore this */

        double *tol; /**<@brief  Flat Tolerance. NULL to use global default */
    } svxSmdPartialFlangeData;

    /**
    @brief Smd Bend Type of Hem Flange
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef enum evxSmdHemBendType
    {
        VX_SMD_HEM_BEND_CLOSED,       /**<@brief  Close */
        VX_SMD_HEM_BEND_OPEN,         /**<@brief  Open */
        VX_SMD_HEM_BEND_CLOSEDLOOP,   /**<@brief  Closed loop */
        VX_SMD_HEM_BEND_OPENLOOP,     /**<@brief  Open loop */
        VX_SMD_HEM_BEND_CENTEREDLOOP, /**<@brief  Centered loop */
        VX_SMD_HEM_BEND_SBEND,        /**<@brief  S bend */
        VX_SMD_HEM_BEND_CURL,         /**<@brief  Curl */
    } evxSmdHemBendType;

    /**
    @brief template command Smd Hem Flange data
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef struct svxSmdHemFlangeData
    {
        int hemType;        /**<@brief  0 is Full hem, 1 is Partial hem. default is 0 */
        int isFlip;         /**<@brief  1 if flip the hems, else 0 as default */
        union uvxSmdHemData /**<@brief union of smd hem data */
        {
            struct svxSmdFullHemData /**<@brief  if hemType = 0, using the following variables */
            {
                int count;    /**<@brief  count of idEdges */
                int *idEdges; /**<@brief  list of idEdge.*/
                /* Miter */
                int isMiterHem; /**<@brief  1 if miter hem, else 0 as default */
                double gapSize; /**<@brief  miter gap size. if isMiterHem = 1, apply it. default is 0.1 */
            } full;
            struct svxSmdPartHemData /**<@brief   if hemType = 1, using the following variables */
            {
                int idEdge;    /**<@brief   id of edge */
                int widthType; /**<@brief   0 is Start-Width, 1 is Start-End. default is 0 */
                double start;  /**<@brief   start(>=0) */
                double end;    /**<@brief   end(>=start). if widthType = 1, using this */
                double width;  /**<@brief   width(>=start). if widthType = 0 ,using this */
                int isRelief;  /**<@brief   1 if relief for insufficient length, else 0 as default */

                svxPntOnEnt *startPnt; /**<@brief   use "To Point" to get the value of "start" (NULL to use start) */
                svxPntOnEnt *endPnt;   /**<@brief   use "To Point" to get the value of "end" (NULL to use end) */
                svxPntOnEnt *widthPnt; /**<@brief   use "To Point" to get the value of "width" (NULL to use width) */
            } partial;
        } hemData;

        evxSmdPosition *position; /**<@brief   position type. NULL to use global default */
        double *offset;           /**<@brief   offset. if *position = VX_POSITION_OFFSET, using this. NULL to use global default */
        /**
        @brief   bend type. default is VX_SMD_HEM_BEND_CLOSED
        @verbatim
              bendType                 |       apply variables 
        VX_SMD_HEM_BEND_CLOSED         |         length1 
        VX_SMD_HEM_BEND_OPEN           |      length1,radius1 
        VX_SMD_HEM_BEND_CLOSEDLOOP     |      length1,radius1 
        VX_SMD_HEM_BEND_OPENLOOP       |      radius1,angle 
        VX_SMD_HEM_BEND_CENTEREDLOOP   | isEqualRadii,radius1,radius2,angle 
        VX_SMD_HEM_BEND_SBEND          | isEqualRadii,length1,length2,radius1,radius2 
        VX_SMD_HEM_BEND_CURL           | length1,length2,radius1,radius2
        @endverbatim
        */
        evxSmdHemBendType bendType;
        int isEqual;     /**<@brief   1 if equal radii ,else 0 as default */
        double length1;  /**<@brief   Length L1 */
        double length2;  /**<@brief   Length L2 */
        double *radius1; /**<@brief   Radius R1. NULL to use global default */
        double *radius2; /**<@brief   Radius R2. NULL to use global default */
        double angle;    /**<@brief   angle( >1). 270 as default */
        /*  K-factor Definition */
        evxSmdKFactorType *kType; /**<@brief   k_factor definition type. NULL to use global default
                                              K-Factor indicates the location of the neutral axis within the thickness of the sheet metal,
                                              and is affected by multiple factors.*/
        double *kValue;           /**<@brief   k_factor. NULL to use global default */
        /*  Relief */
        int isDefSepa;                 /**<@brief   1 if define each side separately ,else 0 as default */
        svxSmdReliefData *startRelief; /**<@brief   relief of start */
        svxSmdReliefData *endRelief;   /**<@brief   relief of end. if isDefSepa = 0, ignore this */
    } svxSmdHemFlangeData;

    /**
    @brief Lofted Flange method
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef enum evxSmdLftFlangeMethod
    {
        VX_SMD_GENERAL_LOFTING,     /**<@brief  The surfaces generated are the same as those generated by solid lofting. */
        VX_SMD_FLATTENABLE_LOFTING, /**<@brief  Open - loop contour and bending lofting. */
        VX_SMD_BENDING_LOFTING,     /**<@brief  The number of segments of the arc is controlled according to the maximum arc height,
                                      bending number, maximum chord length and maximum chord angle.
                                      When lofting, bend lofting according to the contour after section. */
    } evxSmdLftFlangeMethod;

    /**
    @brief Lofted Flange Cutting Method
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef enum evxSmdLftCutMethod
    {
        VX_SMD_LFG_MAX_ARC_HEIGHT,      /**<@brief  This method requires that the arc/ellipse corresponding to each segment line of
                                     the graph arc have the same arc height (the arc height of different arcs can be different),
                                     and not greater than the control value. The default unit is mm. */
        VX_SMD_LFG_NUMBER_BEND,         /**<@brief  The control value is the number of line segments in each arc/ellipse.
                                     It has no unit and is an integer value. */
        VX_SMD_LFG_MAX_CHORD_LENGTH,    /**<@brief  This method requires that the chord length of each arc/ellipse arc is equal
                                     (the chord length of different arcs can be different), and the length is
                                     not greater than the control value. The default unit is mm. */
        VX_SMD_LFG_MAX_ARC_CHORD_ANGLE, /**<@brief  This method requires that the maximum Angle between the tangent vector of the two ends of the arc
                                     and the chord is the same (the Angle of the chord of different arcs may be different),
                                     and is not greater than the control value. The default unit is degree. */
    } evxSmdLftCutMethod;

    /**
    @brief template command Smd Lofted Flange data
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef struct svxSmdLoftedFlangeData
    {
        evxSmdLftFlangeMethod method; /**<@brief  Lofted Flange method.default:VX_SMD_FLATTENABLE_LOFTING */
        double thickness;             /**<@brief  Specifies the thickness for the profile.default:1.
                                           Recommended minimum value is not less than two times of Part Tolerance. */
        int isOpposite;               /**<@brief  1 is Flip the direction of lofted flange, else 0.default:0 */
        double radius;                /**<@brief  Specifies the bend radius of profile.default:5 */
        union uvxLftFlange            /**<@brief union of smd lofted flange data */
        {
            struct svxSmdLftGeneral /**<@brief  VX_SMD_GENERAL_LOFTING */
            {
                int count1;      /**<@brief  count of listLines1 */
                int *listLines1; /**<@brief  list of line(edge/curve) id*/
                int flip1;       /**<@brief  1 is flip, else 0.default:0 */

                int count2;      /**<@brief  count of listLines2 */
                int *listLines2; /**<@brief  list of line(edge/curve) id*/
                int flip2;       /**<@brief  1 is flip, else 0.default:0 */

                int cntShps;               /**<@brief  count of boolShps,cntShps=0 to use default.*/
                int *boolShps;             /**<@brief  Specify the boolean operation and the boolean shapes. */
                svxLoftBndCons bndCons[2]; /**<@brief  boundary constraints */
                int scale;                 /**<@brief  An additional scale factor that is applied to the Weight slider bar.
                                           This is only needed when the extreme position of the slider bar is
                                           insufficient for your design task. */
            } general;
            struct svxSmdLftFlat /**<@brief  VX_SMD_FLATTENABLE_LOFTING */
            {
                int idProf1;         /**<@brief  id of profile1 */
                int flip1;           /**<@brief  1 is flip profile1, else 0.default:0 */
                svxPntOnEnt cutPnt1; /**<@brief  Specify that a pointcut is selected in profile 1.
                                           No setup is required when the profile is closed. */

                int idProf2;         /**<@brief  id of profile2 */
                int flip2;           /**<@brief  1 is flip profile1, else 0.default:0 */
                svxPntOnEnt cutPnt2; /**<@brief  Specify that a pointcut is selected in profile 2.
                                           No setup is required when the profile is closed. */

                double cutLength;        /**<@brief  Specify the cut length.default:1 */
                int isUseGlobal;         /**<@brief  1 is use global setting(the following parameters are not to set),else 0.default:1 */
                evxSmdKFactorType kType; /**<@brief  k_factor definition type.default:VX_SMD_KTYPE_CUSTOM */
                double kValue;           /**<@brief  k_factor. default:0.41 */
            } flattenable;
            struct svxSmdLftBend /**<@brief  VX_SMD_BENDING_LOFTING */
            {
                int idProf1;         /**<@brief  id of profile1 */
                int flip1;           /**<@brief  1 is flip profile1, else 0.default:0 */
                svxPntOnEnt cutPnt1; /**<@brief  Specify that a pointcut is selected in profile 1.
                                           No setup is required when the profile is closed. */

                int idProf2;         /**<@brief  id of profile2 */
                int flip2;           /**<@brief  1 is flip profile1, else 0.default:0 */
                svxPntOnEnt cutPnt2; /**<@brief  Specify that a pointcut is selected in profile 2.
                                           No setup is required when the profile is closed. */

                double cutLength;             /**<@brief  Specify the cut length.default:1 */
                evxSmdLftCutMethod cutMethod; /**<@brief  Pick the position to place the cut point.default:VX_SMD_LFG_MAX_ARC_HEIGHT */
                double cutValue;              /**<@brief  cutting value.default:1 */
                int isUseGlobal;              /**<@brief  1 is use global setting(the following parameters are not to set),else 0.default:1 */
                evxSmdKFactorType kType;      /**<@brief  k_factor definition type.default:VX_SMD_KTYPE_CUSTOM */
                double kValue;                /**<@brief  k_factor. default:0.41 */
            } bending;
        } inpUnion;
    } svxSmdLoftedFlangeData;

    /**
    @brief template command Smd Swept Flange data
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef struct svxSmdSweptFlangeData
    {
        int idFace;     /**<@brief  This face remains stationary when the part is folded or unfolded. */
        int idProfile;  /**<@brief  Set the open, non-intersecting profile sketch used to create the sweep. */
        int count;      /**<@brief  count of sweptPath */
        int *sweptPath; /**<@brief  Set the path along which the profile sweeps. You can select a series of
                                         existing sheet metal edges for the path.
                                         The start point of the path must lie on the plane of the profile. */

        evxSmdPosition position; /**<@brief  Use this option to specify the position of the added sheet metal flange.
                                         The position of the flange is specified relative to the selected edge.
                                         VX_POSITION_VIRTUAL_SHARP cannot be used here. */
        double offset;           /**<@brief  specify the offset value of the flange if position = VX_POSITION_OFFSET, else ignore.default:0 */
        double radius;           /**<@brief  Specifies the inner bend radius applied to flange features. */
        int keepMerged;          /**<@brief  1 is keep merged edges, else 0. default:0 */

        int isUseGlobal;         /**<@brief  1 is use global setting(the following parameters are not to set),else 0.default:1 */
        evxSmdKFactorType kType; /**<@brief  k_factor definition type.default:VX_SMD_KTYPE_CUSTOM */
        double kValue;           /**<@brief  k_factor. default:0.41 */

        evxSmdCornerRelief relief; /**<@brief  Use this option to trim the adjoining flanges. */
        int miterCorner;           /**<@brief  1 is miter corner, else 0. default:1. */
        union uvxSmdSweptFlange    /**<@brief union of smd swept flange data */
        {
            struct svxSmdReliefClosed /**<@brief  VX_CORNER_RELIEF_CLOSED */
            {
                double gap; /**<@brief  Specify the gap for the closed corner.default:0. */
            } closed;

            struct svxSmdReliefCircular /**<@brief  VX_CORNER_RELIEF_CIRCULAR_CUTOUT */
            {
                double gap;      /**<@brief  Specify the gap for the closed corner.default:0. */
                int origin;      /**<@brief  0 is bend center, 1 is corner point.default:1 */
                double offset;   /**<@brief  Specify an offset distance from the origin of the Cutout.default:0 */
                double diameter; /**<@brief  Specify the diameter of Circular Cutout, U Cutout, V Cutout.default:4 */
            } circular;

            struct svxSmdReliefRectangular /**<@brief  VX_CORNER_RELIEF_RECTANGULAR_CUTOUT */
            {
                double gap;    /**<@brief  Specify the gap for the closed corner.default:0. */
                int origin;    /**<@brief  0 is bend center, 1 is corner point.default:1 */
                double offset; /**<@brief  Specify an offset distance from the origin of the Cutout.default:0 */
                double length; /**<@brief  Specify the length of the Rectangular Cutout.default:4 */
                double width;  /**<@brief  Specify the width of the Rectangular Cutout.default:4 */
            } rectangular;

            struct svxSmdReliefUCutout /**<@brief  VX_CORNER_RELIEF_U_CUTOUT */
            {
                double gap;      /**<@brief  Specify the gap for the closed corner.default:0. */
                int origin;      /**<@brief  0 is bend center, 1 is corner point.default:1 */
                double offset;   /**<@brief  Specify an offset distance from the origin of the Cutout.default:0 */
                double diameter; /**<@brief  Specify the diameter of Circular Cutout, U Cutout, V Cutout.default:4 */
            } uCutout;

            struct svxSmdReliefVCutout /**<@brief  VX_CORNER_RELIEF_V_CUTOUT */
            {
                double gap;      /**<@brief  Specify the gap for the closed corner.default:0. */
                int origin;      /**<@brief  0 is bend center, 1 is corner point.default:1 */
                double offset;   /**<@brief  Specify an offset distance from the origin of the Cutout.default:0 */
                double diameter; /**<@brief  Specify the diameter of Circular Cutout, U Cutout, V Cutout.default:4 */
                double angle1;   /**<@brief  Specify the angle of the V Cutout.default:30 */
                double angle2;   /**<@brief  Specify the angle of the V Cutout.default:30 */
            } vCutout;
        } inpUnion;
    } svxSmdSweptFlangeData;

    /**
    @brief Smd Jog Parameters Position
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef enum evxSmdJogPosition
    {
        VX_SMD_JOG_OUTER,            /**<@brief  Bend is farther from stationary point than line. */
        VX_SMD_JOG_INNER,            /**<@brief  Bend is close to stationary point than line. */
        VX_SMD_JOG_MIDDLE,           /**<@brief  The line stays in the middle of bend. */
        VX_SMD_JOG_MATERIAL_INSIDE,  /**<@brief  In form state, fold line at the outside face of the fold region. */
        VX_SMD_JOG_MATERIAL_OUTSIDE, /**<@brief  In form state, fold line at the inside face of the fold region. */
    } evxSmdJogPosition;

    /**
    @brief template command Smd Fold by Line data
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef struct svxSmdFoldByLineData
    {
        int idLine;                 /**<@brief  Select a line. It can be a 3 dimensional line or a sketch line. */
        int idProfile;              /**<@brief  id of sketch, if idLine is one curve of the sketch (-1/0 if idLine is a line or a sketch)*/
        int idFace;                 /**<@brief  Specify the plane face where inner bends are created. */
        int flipSide;               /**<@brief  bend direction, 1- flip side to keep, else 0 (default:0) */
        evxSmdJogPosition position; /**<@brief  Specify the position relationship between bend and line.default:VX_SMD_JOG_INNER */
        double angle;               /**<@brief  Specify the bend angle.default:90 */
        double radius;              /**<@brief  Specify the inner radius value of bend.default:5 */
        int isUseGlobal;            /**<@brief  1 is use global setting(the following parameters are not to set),else 0.default:1 */
        evxSmdKFactorType kType;    /**<@brief  k_factor definition type.default:VX_SMD_KTYPE_CUSTOM */
        double kValue;              /**<@brief  k_factor. default:0.41 */
    } svxSmdFoldByLineData;

    /**
    @brief template command Smd Jog data
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef struct svxSmdJogData
    {
        int idLine;                 /**<@brief  id line. Make sure it is a straight line.*/
        int idFace;                 /**<@brief  id face.Specify the plane face where inner bends are created. */
        int reverseSide;            /**<@brief 1 is reverse the stationary side, else 0.default:0 */
        int heightType;             /**<@brief  0 is inner: Measure the height from the sketch plane of the fold line,
                                     extend to the total height. Then offset a distance according to the
                                     thickeness of the material.    
                                     1 is outer: Measure the height from the sketch plane of the fold line,
                                     extend to the total height. default:0 */
        double height;              /**<@brief  input a value to define the height of the jog.default:40 */
        int keepProjLen;            /**<@brief  1 is keep the projection length, else 0.default:1 */
        evxSmdJogPosition position; /**<@brief  Specify the position relationship between bend and line.default:VX_SMD_JOG_INNER */
        double radius;              /**<@brief  Specify the inner radius value of bend.default:5 */
        int isUseGlobal;            /**<@brief  1 is use global setting(the following parameters are not to set),else 0.default:1 */
        evxSmdKFactorType kType;    /**<@brief  k_factor definition type.default:VX_SMD_KTYPE_CUSTOM */
        double kValue;              /**<@brief  k_factor. default:0.41 */
    } svxSmdJogData;

    //====================================================================================================================
    /** @name Editing Data */
    //====================================================================================================================
    /**
    @brief extend flange method
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef enum evxSmdExtendFlangeMethod
    {
        VX_SMD_EXTEND_BY_VALUE,      /**<@brief  Extends by a specfied value. */
        VX_SMD_EXTEND_THROUGH_UNTIL, /**<@brief  Extends to intersect the plane. */
        VX_SMD_EXTEND_TO_SELECTED,   /**<@brief  Extends up to the plane. */
    } evxSmdExtendFlangeMethod;

    /**
    @brief extend flange side method
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef enum evxSmdExtendSideMethod
    {
        VX_SMD_EXTEND_SIDE_NORMAL, /**<@brief  Extend the flange normal to the edge. */
        VX_SMD_EXTEND_SIDE_ALONG,  /**<@brief  Extend along the edge. */
    } evxSmdExtendSideMethod;

    /**
    @brief template command Smd Extend Flange data
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef struct svxSmdExtendFlangeData
    {
        evxSmdExtendFlangeMethod type; /**<@brief  extend type.default:VX_SMD_EXTEND_BY_VALUE */
        int idEdge;                    /**<@brief  Select a edge to extend. */
        union uvxExtFlangeData         /**<@brief union of smd extend flange data */
        {
            double distance;        /**<@brief  Specify a value to extend.default:0.1
                                          The flange will stretch out when you enter a positive number,
                                          and will be cut when you enter negative number.
                                          Apply it if type = VX_SMD_EXTEND_BY_VALUE */
            struct svxExtFlangeData /**<@brief  apply it if type != VX_SMD_EXTEND_BY_VALUE */
            {
                int idPlane;   /**<@brief  Specify a plane or datum as reference object. */
                double offset; /**<@brief  Specify the distance between the plane and the edge.default:0
                                          The flange will extend beyond the plane when you enter a negative number.  */
            } nonByValue;
        } inpUnion;

        evxSmdExtendSideMethod sideType1; /**<@brief  Specify a method to controls the start and end sides of the flange extension.
                                          default:VX_SMD_EXTEND_SIDE_NORMAL */
        int extendSrfToEdge1;             /**<@brief  Check this box to extend the bend adjacent to the edge together.default:0 */
        evxSmdExtendSideMethod sideType2; /**<@brief  Specify a method to controls the start and end sides of the flange extension.
                                          default:VX_SMD_EXTEND_SIDE_NORMAL */
        int extendSrfToEdge2;             /**<@brief  Check this box to extend the bend adjacent to the edge together.default:0 */
    } svxSmdExtendFlangeData;

    /**
    @brief smd bend web taper type
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef enum evxSmdWebTaperType
    {
        VX_SMD_TAPER_WEB_NONE,       /**<@brief  Tapers only the bend. */
        VX_SMD_TAPER_WEB_FACE,       /**<@brief  Tapers the bend and the adjacent web.
                                    The web taper is terminated at the next bend.
                                    You can specify a different value for the taper angle of the web. */
        VX_SMD_TAPER_WEB_FACE_CHAIN, /**<@brief  Tapers the selected bend and all the webs and bends in the chain using the specified taper angle value.
                                    You can specify a different value for the taper angle of the web. */
    } evxSmdWebTaperType;

    /**
    @brief smd bend taper definition side data
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef struct svxSmdBendTaperDefData
    {
        int taperType;            /**<@brief  0 is linear,Use an angle value or a distance value to taper the bend.    
                                        1 is tangent,Use a distance value to taper the bend. The edge of the bend is tangent to the web.
                                        default:0.*/
        union uvxSmdTaperDefInfos /**<@brief union of smd bend taper definition data */
        {
            struct svxSmdLinear /**<@brief smd linear data */
            {
                int method;   /**<@brief  0 is setback,Specify a distance value to taper the bend.   
                                        1 is end radius,Specify an angle value to taper the bend.
                                        default:0*/
                double value; /**<@brief  Angle or setback.default:5 */
            } linear;
            struct svxSmdTangent /**<@brief smd tangent data */
            {
                double setback;    /**<@brief  Specify the distance value to taper.default:5 */
                int isAutoCompute; /**<@brief  1 is auto compute radius,else 0. default:1 */
                double sRadius;    /**<@brief  start radius. apply it if isAutoCompute=0. default:2 */
                double eRadius;    /**<@brief  end radius. apply it if isAutoCompute=0. default:2 */
            } tangent;
        } inpUnion;

        evxSmdWebTaperType webTaperType; /**<@brief  Creates tapers that start from the web.default:VX_SMD_TAPER_WEB_NONE */
        double angle;                    /**<@brief  apply it if webTaperType != VX_SMD_TAPER_WEB_NONE, else ignore it.default:5 */
    } svxSmdBendTaperDefData;

    /**
    @brief smd bend taper sides
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef enum evxSmdTaperSideMethod
    {
        VX_SMD_TAPER_SIDES_BOTH,     /**<@brief  Tapers both sides of the flange. You can set different values for each side. */
        VX_SMD_TAPER_SIDES_SIDE1,    /**<@brief  Tapers the first side of the flange. You can see a preview of the result. */
        VX_SMD_TAPER_SIDES_SIDE2,    /**<@brief  Tapers the second side of the flange. You can see a preview of the result. */
        VX_SMD_TAPER_SIDES_SYMMETRY, /**<@brief  Tapers both sides equally of the flange. */
    } evxSmdTaperSideMethod;

    /**
    @brief template command Smd bend taper data
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef struct svxSmdBendTaperData
    {
        int idBend;                      /**<@brief  Select a bend face to taper one or both sides of the flange.
                                        The edges of the flange are tapered in the direction of the arrow. */
        int opposite;                    /**<@brief  Check(opposite=1) this box to flip the arrows, and system will reset the stationary face.default:0  */
        evxSmdTaperSideMethod method;    /**<@brief  Specify the side you want to taper.default:VX_SMD_TAPER_SIDES_BOTH */
        svxSmdBendTaperDefData defData;  /**<@brief  bend taper definition side data */
        svxSmdBendTaperDefData defData2; /**<@brief  apply it if method = VX_SMD_TAPER_SIDES_BOTH,else ignore it. */
    } svxSmdBendTaperData;

    /**
    @brief extrude type
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef enum evxExtrudeType
    {
        VX_EXTRUDE_TYPE_ONESIDE = 0, /**<@brief  1 side */
        VX_EXTRUDE_TYPE_TWOSIDE = 1, /**<@brief  2 side */
        VX_EXTRUDE_TYPE_SYMMETRICAL, /**<@brief  Symmetrical */
    } evxExtrudeType;

    /**
    @brief Normal Cut command
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef enum evxNormCutTyp
    {
        VX_NORMCUT_BOTHSIDES = 0, /**<@brief  Normal to Both Sides */
        VX_NORMCUT_MIDDLE    = 1, /**<@brief  Normal to Middle */
    } evxNormCutTyp;

    /**
    @brief template command Smd Normal Cut data
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef struct svxNormalCutData
    {
        evxNormCutTyp cutType;  /**<@brief  normal cut option, default value:VX_NORMCUT_BOTHSIDES */
        int idProfile;          /**<@brief  Profile P */
        int cntShape;           /**<@brief  Cut Shapes count */
        int *shapeList;         /**<@brief  Cut Shapes List */
        evxExtrudeType extType; /**<@brief  extrude type, default value:VX_EXTRUDE_TYPE_ONESIDE*/
        double dStart;          /**<@brief  Start S, default value:10.0 */
        double dEnd;            /**<@brief  End E, default value:-10.0 */
        svxVector *Dir;         /**<@brief  Direction (NULL can be ignored)*/
        int Flip;               /**<@brief  Flip side to cut, default value:0 */

        evxDistanceMethod startType; /**<@brief  start type (0 = input value, 1 = through all, 2= to point, 5 = to face) */
        evxDistanceMethod endType;   /**<@brief  end type (0 = input value, 1 = through all, 2= to point, 5 = to face) */
        int idStartEnt;              /**<@brief  the entity id of start field if startType > 1 */
        int idEndEnt;                /**<@brief  the entity id of end field if endType > 1 */
        svxPoint *startToPnt;        /**<@brief  if startType = 2, NULL to ignore */
        svxPoint *endToPnt;          /**<@brief  if endType = 2, NULL to ignore */
    } svxNormalCutData;

    //====================================================================================================================
    /** @name Corner Data */
    //====================================================================================================================
    /**
    @brief corner relief type
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef enum evxCornerReliefTyp
    {
        VX_CORNER_CLOSED = 0,   /**<@brief  closed */
        VX_CORNER_CIRCL_CUTOUT, /**<@brief  circular cutout */
        VX_CORNER_RECT_CUTOUT,  /**<@brief  rectangular cutout*/
        VX_CORNER_U_CUTOUT,     /**<@brief  U cutout */
        VX_CORNER_V_CUTOUT,     /**<@brief  V cutout */
    } evxCornerReliefTyp;

    /**
    @brief corner overlap type
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef enum evxCornerOverlapTyp
    {
        VX_CORNER_UNDERLAP = 0, /**<@brief  underlap */
        VX_CORNER_OVERLAP,      /**<@brief  overlap */
        VX_CONER_NATURAL,       /**<@brief  natural */
    } evxCornerOverlapTyp;

    /**
    @brief template command Smd Close Corner data (Note: if you don't care some parameters, set them as default values)
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef struct svxCloseCornerData
    {
        int type;        /**<@brief  method, 0-close by edge, 1- close by bend(face)(0 as default) */
        union CornerData /**<@brief  union of close corner data */
        {
            struct svxByEdge /**<@brief  linear pattern */
            {
                svxPntOnEnt Edg1Pnt; /**<@brief  first face edge */
                svxPntOnEnt Edg2Pnt; /**<@brief  second face edge */
            } byEdge;

            struct svxByFace /**<@brief  circular pattern */
            {
                int idBend1;               /**<@brief  first bend face */
                int idBend2;               /**<@brief  second bend face */
                int CloseFlange;           /**<@brief  close the whole flange or not(1 as default)
                             if set to 1, it closes all sub corners with the basic one.
                             if set to 0, it only close basic one.*/
                int Miter;                 /**<@brief  miter corner or not (1 as default)
                             if set to 0, use straight lines to form the outline of the cuter which is going to cut the corner on the unfold pattern.
                             if set to 1, use curves to form the outline of the cuter. */
                evxCornerReliefTyp Relief; /**<@brief  to trim the adjoining flanges (VX_CORNER_CLOSED as default)*/
                int OrgType;               /**<@brief  0-bend center, 1-corner point(1 as default, and it works when Relief != VX_CORNER_CLOSED) */
                double dOffset;            /**<@brief  specify offset distance for origin (0.0 as default, use it when Relief!=VX_CORNER_CLOSED) */
                double dDiam;              /**<@brief  diameter(4.0 as default,  use it when Relief!=VX_CORNER_CLOSED && Relief!=VX_CORNER_RECT_CUTOUT) */
                double dLength;            /**<@brief  specify length for rectangular cut (4.0 as default, use it when Relief=VX_CORNER_RECT_CUTOUT) */
                double dWidth;             /**<@brief  specify width for rectangular cut (4.0 as default, use it when Relief=VX_CORNER_RECT_CUTOUT) */
                double dAng1;              /**<@brief  specify first angle for V cut (30 as default, use it when Relief=VX_CORNER_V_CUTOUT)*/
                double dAng2;              /**<@brief  specify second angle for V cut (30 as default, use it when Relief=VX_CORNER_V_CUTOUT)*/
            } byFace;
        } cornerData;

        evxCornerOverlapTyp Overlp; /**<@brief  (VX_CONER_NATURAL as default)*/
        double dGap;                /**<@brief  (0.1mm as default) */
    } svxCloseCornerData;

    //====================================================================================================================
    /** @name Form Data */
    //====================================================================================================================
    /**
    @brief Punch type
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef enum evxPunchTyp
    {
        VX_PUNCH_SHAPE = 0, /**<@brief  Punch from Shape */
        VX_PUNCH_FILE  = 1, /**<@brief  Punch from File */
    } evxPunchTyp;

    /**
    @brief location type of punch command
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef enum evxPunchLocType
    {
        VX_LOCATION_POINT      = 0, /**<@brief  Point */
        VX_LOCATION_CONSTRAINT = 1, /**<@brief  Constraint */
    } evxPunchLocType;

    /**
    @brief punch constraint
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef struct svxPunchCons
    {
        evxConsType alignTyp; /**<@brief  alignment type (default value: VX_CONCENTRIC)*/
        /*  note: one of entities must form the insert punch file */
        svxEntPath pathEnt1; /**<@brief  first entity path (initialize as(2,-1,idEnt)) */
        int ent1FormFile;    /**<@brief  1 if the first entity from the punch file, else 0 (default value:0) */
        svxEntPath pathEnt2; /**<@brief  second entity path (initialize as(2,-1,idEnt)) */
        int ent2FormFile;    /**<@brief  1 if the second entity from the punch file, else 0 (default value:0) */
        /*   The following parameter is used when  alignTyp = VX_COINCIDENT/VX_TANGENT */
        double dOffset; /**<@brief  offset value (default value: 0) */
        /*   The following parameter is used when  alignTyp = VX_GEAR */
        double dAng; /**<@brief  angle value (default value: 0) */
                     /*   The following parameter is used when  alignTyp ! VX_ADV_FRAME/ */
        int Flip;    /**<@brief  1-flip the alignment direction, else 0 (default value:0)*/
    } svxPunchCons;

    /**
    @brief Punch data
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef struct svxPunchData
    {
        evxPunchTyp punchTyp; /**<@brief  Punch option, default value:VX_PUNCH_SHAPE */
        int idBase;           /**<@brief  boundary face on base (face id)*/
        int cntOpen;          /**<@brief  count of open faces (0 to ignore)*/
        int *pOpenList;       /**<@brief  open faces from punch shape (NULL to ignore)
                                       if punchTyp = VX_PUNCH_FILE, pOpenList must from the punch file */
        int addFillet;        /**<@brief  fillet placement edges,default value:0
                                       if set to 1, user can set the fillet radius of intersected edge between punch and sheet metal*/
        double dRadius;       /**<@brief  radius for dRadius, default value:5 */
        int addFillet2;       /**<@brief  fillet non placement edges,default value:0 */
        double dRadius2;      /**<@brief  radius for addFillet2, default value:5 */
        /*  The following parameters are used when  punchTyp = VX_PUNCH_SHAPE */
        int idPunch; /**<@brief  a punch shape (shape id)*/
        /*  The following parameters are used when  punchTyp = VX_PUNCH_FILE */
        vxLongPath pathPunch;   /**<@brief  punch file path, used option in VX_PUNCH_FILE*/
        evxPunchLocType locTyp; /**<@brief  location Type, default value:VX_LOCATION_POINT */
        svxPoint localPnt;      /**<@brief  punch point, used option in VX_PUNCH_FILE(default:(0,0,0))*/
        int relation;           /**<@brief  Related with source, default value:1, used option in VX_PUNCH_FILE
                                       if set to 1, the punch result changes as the punch in source changes
                                       if set to 0, the change of punch will not effect the existing punch */
        union LocData           /**<@brief union of punch data */
        {
            struct ByPnt /**<@brief  point + frame */
            {
                int idFrame; /**<@brief  Frame, used option in VX_PUNCH_FILE (-1/0 to ignored)*/
            } byPnt;

            struct ByCons /**<@brief  point + constraint */
            {
                int cntCons;             /**<@brief  count of constraint data (0 to ignore)*/
                svxPunchCons *punchCons; /**<@brief  constraint data list(NUll to ignore) */
            } byCons;
        } locData;
    } svxPunchData;

    /**
    @brief dimple position type
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef enum evxDimplePostion
    {
        VX_MATERIAL_OUTSIDE = 0, /**<@brief  material outside: set the dimple outside the sketch */
        VX_MATERIAL_INSIDE,      /**<@brief  material inside: set the dimple inside  the sketch */
        VX_BEND_OUTSIDE,         /**<@brief  bend outside: set the dimple outside  the sketch */
    } evxDimplePostion;

    /**
    @brief dimple data
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef struct svxDimpleData
    {
        int dimpleType; /**<@brief  dimple type (0 = Plain Dimple, 1 = Flared Hole) */
        int idPlane;    /**<@brief  id of planar face to place the dimple */
        int idProfile;  /**<@brief  id of sketch defining the dimple perimeter, the sketch must be a
                          closed sketch with one or more tangent continuous loops */

        int notSew;    /**<@brief  flag whether sew shapes or not. 0 = to sew (default)  
                                   since R2024, it doesn't sew the new shapes and if user set it to 0, it will create a 'Sew' feature to sew the shapes */
        int numShapes; /**<@brief  number of shapes to sew */
        int *idShapes; /**<@brief  list of id's of shapes to sew */

        double height;  /**<@brief  height measured from the selected face to the outside face of the dimple */
        double angle;   /**<@brief  the side angle measured from the selected face */
        double radius1; /**<@brief  inner radius around the perimeter height of the dimple */
        double radius2; /**<@brief  outer radius around the perimeter of the dimple and tangent to the selected face */
        double radius3; /**<@brief  the outer fillet radius of the outside wall (default:1.0, 0.0-disable)
                          doesn't use if dimpleType = 1 */

        int flipFlange;           /**<@brief  1-flip the normal direction of the plane where the dimple is placed, else 0 (default:0) */
        int prfOnDimpleTop;       /**<@brief  1-the top of the dimple is the size of the outline, and the bottom changes with the angle;
                          0-the bottom of the dimple is the size of the contour, and the top changes with the angle
                          (default:1) */
        evxDimplePostion postion; /**<@brief  postion type (default: VX_MATERIAL_OUTSIDE)
                                 dimpleType = 1, VX_BEND_OUTSIDE does not contain */

        vxName ftrName; /**<@brief  feature name for "SmdDimple", 0 default */
    } svxDimpleData;

    /**
    @brief template command Smd Louver data
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef struct svxLouverData
    {
        int idPlane;    /**<@brief  id of planar face for louver placement */
        int idProf;     /**<@brief  id of profile */
        double dHeight; /**<@brief  louver height (3.0mm as default)*/
        double dAng;    /**<@brief  louver angle (45deg as default) */
        double dR1;     /**<@brief  1st louver radius (1.0mm as default) */
        double dR2;     /**<@brief  2nd louver radius (1.0mm as default) */
        double dWidth;  /**<@brief  louver width (6.0mm as default) */
        int Flip;       /**<@brief  whether to flip the louver 180 degrees about the sketch line(0-no as default, 1-yes)*/
        int notSew;     /**<@brief  flag whether sew shapes or not. 0 = to sew (default)  
                               since R2024, it doesn't sew the new shapes and if user set it to 0, it will create a 'Sew' feature to sew the shapes */
        int cntSew;     /**<@brief  count of sew shapes */
        int *pSewShape; /**<@brief  id list of sew shapes (NULL to sew with all shapes)*/
    } svxLouverData;

    //====================================================================================================================
    /** @name Bend Data */
    //====================================================================================================================
    /**
    @brief template command Smd Fold data
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef struct svxFoldData
    {
        int idShape;      /**<@brief  shape id */
        int idStationary; /**<@brief  Stationary face id (0/-1 to ignored) */
        int BendFaceCnts; /**<@brief  Bend face counts(0 to ignored) */
        int *idBendFace;  /**<@brief  Bend faces id (NULL to ignored)*/
        int CrvCnts;      /**<@brief  Curve list counts(0 to ignored) */
        int *idCrv;       /**<@brief  curve list on the sheet metal(NULL to ignored) */
    } svxFoldData;

    /**
    @brief template command Smd Unfold data
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef struct svxUnfoldData
    {
        int idShape;      /**<@brief  shape id */
        int idStationary; /**<@brief  Stationary face id */
        int BendFaceCnts; /**<@brief  Bend face counts */
        int *idBendFace;  /**<@brief  Bend faces id*/
        int CrvCnts;      /**<@brief  Curve list counts(0 to ignored) */
        int *idCrv;       /**<@brief  curve list on the sheet metal(NULL to ignored) */
    } svxUnfoldData;

    /**
    @brief template command Smd flatten data
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef struct svxSmdFlattenData
    {
        int idShape;         /**<@brief  shape id */
        int idFace;          /**<@brief  Select the bend faces to flatten.0/-1 to ignore it. */
        double offset;       /**<@brief  Set the offset distance between the flatten entity and the flatten pattern.default:20 */
        int useDir;          /**<@brief  1 is use direction, else 0.default:0 */
        svxVector direction; /**<@brief  Select the direction for offset. */
        int includePattern;  /**<@brief  Check(=1) this option if user wants to quickly project to
                            the generated flat view of sheet metal model by the flat pattern.
                            Flatten pattern can be exported as DWG or DXF for applying to other production process.
                            default:0 */
        int ignoreTangent;   /**<@brief  Check(=1) this option if user wants to adjsut the tangent edges from flat pattern
                            that can be shown or hidden.default:0.
                            if includePattern = 0, the ignoreTangent can't be changed.
                            if includePattern = 1, the ignoreTangent can be given by user. */
        int useDirPMI;       /**<@brief  1 is use PMI direction, else 0. default:0 */
        svxVector dirPMI;    /**<@brief  linear PMI direction. */
    } svxSmdFlattenData;

    /**
    @brief template command Smd linear unfold data
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef struct svxSmdLinearUnfoldData
    {
        int idFace;   /**<@brief  Specify the face to fix.0/-1 to ignore it. */
        int cnt;      /**<@brief  count of bendFcs */
        int *bendFcs; /**<@brief  Specify bend faces to lay out. */
        double angle; /**<@brief  Specify the angle to unfold.default:90 */

        int isUseGlobal;         /**<@brief  1 is use global setting(the following parameters are not to set),else 0.default:1 */
        evxSmdKFactorType kType; /**<@brief  k_factor definition type.default:VX_SMD_KTYPE_CUSTOM */
        double kValue;           /**<@brief  k_factor. default:0.41 */

        int addStatus;   /**<@brief  Check(=1) this option to create a newly copied part which is associative with the original one.default:0 */
        svxVector dir;   /**<@brief  Select linear unfold direction.default:{1,0,0} */
        double distance; /**<@brief  Enter distance along linear unfold direction.default:0.1 */
    } svxSmdLinearUnfoldData;

    /**
    @brief change bend type
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef enum evxSmdChangeBendType
    {
        VX_SMD_CHANGE_BEND_DEFAULT,       /**<@brief  Both bend radius and angle can be changed. */
        VX_SMD_CHANGE_BEND_FOLD_LENGTH,   /**<@brief  Only bend radius of picked bends and geometries nearby will be
                                         changed keeping other dimensions of the fold shape unchanged.
                                         The unfold length is changed. */
        VX_SMD_CHANGE_BEND_UNFOLD_LENGTH, /**<@brief  Both bend radius and angle can be changed keep the over all unfold length of the shape unchanged.*/
    } evxSmdChangeBendType;

    /**
    @brief template command Smd change bend data
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef struct svxSmdChangeBendData
    {
        evxSmdChangeBendType type; /**<@brief  Specify change bend type from the following.default:VX_SMD_CHANGE_BEND_DEFAULT */
        int cnt;                   /**<@brief  count of bendFcs */
        int *bendFcs;              /**<@brief  Select the bend faces to change.*/
        double radius;             /**<@brief  Set the radius of bends.default:5 */
        union uvxSmdChangeBend     /**<@brief union of smd change bend data */
        {
            struct svxChangeBendDefault /**<@brief  VX_SMD_CHANGE_BEND_DEFAULT */
            {
                double angle;            /**<@brief  Set the angle of bends.default:90 */
                int isUseGlobal;         /**<@brief  1 is use global setting(the following parameters are not to set),else 0.default:1 */
                evxSmdKFactorType kType; /**<@brief  k_factor definition type.default:VX_SMD_KTYPE_CUSTOM */
                double kValue;           /**<@brief  k_factor. default:0.41 */
            } defaultInfo;
            struct svxChangeBendFold /**<@brief  VX_SMD_CHANGE_BEND_FOLD_LENGTH */
            {
                int isUseGlobal;         /**<@brief  1 is use global setting(the following parameters are not to set),else 0.default:1 */
                evxSmdKFactorType kType; /**<@brief  k_factor definition type.default:VX_SMD_KTYPE_CUSTOM */
                double kValue;           /**<@brief  k_factor. default:0.41 */
            } fold;
            struct svxChangeBendUnfold /**<@brief  VX_SMD_CHANGE_BEND_UNFOLD_LENGTH */
            {
                int stationary; /**<@brief  This face remains stationary when the part is folded or unfolded. */
                double angle;   /**<@brief  Set the angle of bends.default:90 */
            } unfold;
        } inpUnion;
    } svxSmdChangeBendData;

    //====================================================================================================================
    /** @name Convert Data */
    //====================================================================================================================
    /**
    @brief smd rip type
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef enum evxSmdRipType
    {
        VX_SMD_RIP_BOTH_SIDES, /**<@brief  two sides */
        VX_SMD_RIP_LEFT_SIDE,  /**<@brief  left side */
        VX_SMD_RIP_RIGHT_SIDE, /**<@brief  right side */
    } evxSmdRipType;

    /**
    @brief template command Smd rip data
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef struct svxSmdRipData
    {
        evxSmdRipType type; /**<@brief  rip type.default:VX_SMD_RIP_BOTH_SIDES */
        int cnt;            /**<@brief  count of ids */
        int *ids;           /**<@brief  Choose edges/lines to create a rip.*/
        double gap;         /**<@brief  Set the gap size.default:0.1 */
    } svxSmdRipData;

    /**
    @brief template command Smd mark bend data
    @ingroup zwapi_cmd_sheetmetal_data
    */
    typedef struct svxSmdMarkBendData
    {
        int idFace;              /**<@brief  This face remains stationary when the part is folded or unfolded. */
        int cnt;                 /**<@brief  count of bendFcs */
        int *bendFcs;            /**<@brief  Select the inner or outer bend faces.
                                  Bend faces can be marked while the sheet metal part is in its unfolded state. */
        int isUseGlobal;         /**<@brief  1 is use global setting(the following parameters are not to set),else 0.default:1 */
        evxSmdKFactorType kType; /**<@brief  k_factor definition type.default:VX_SMD_KTYPE_CUSTOM */
        double kValue;           /**<@brief  k_factor. default:0.41 */
        double thickness;        /**<@brief  sheet metal thickness.default:1.0 */
        double flatTol;          /**<@brief  Refers to the flat tolerance allowed for sheet metal parts in their unfolded state.default:0.10. */
    } svxSmdMarkBendData;

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_SHEET_METAL_FTR_DATA_H */
