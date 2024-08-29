/**
@file zwapi_cmd_dwg_data.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the
drawing command functions.
*/
/**
@defgroup zwapi_cmd_dwg_data Drawing Commands Data
@ingroup DrawingCommands
@brief
@details THE MODULE FOR THE ZW3D Data Types and Structures of the
drawing command functions.
*/

#pragma once
#ifndef ZW_API_DWG_CMD_DATA_H /* *his ifndef surrounds entire header */
#define ZW_API_DWG_CMD_DATA_H

#include "zwapi_util.h"
#include "zwapi_cmd_sk_create_data.h"
#include "zwapi_dwg_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name View Data */
    //====================================================================================================================
    /**
    @brief drawing view location type
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxViewLocationType
    {
        VX_LOCATION_AUTO,   /**<@brief  automatic set-up */
        VX_LOCATION_CENTER, /**<@brief  set center point */
        VX_LOCATION_CORNER, /**<@brief  set corner points */
    } evxViewLocationType;

    /**
    @brief drawing view location data
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxViewLocationData
    {
        evxViewLocationType type; /**<@brief  drawing view location type */
        svxPoint2 FirstPoint;     /**<@brief  the first point
                                     (ignore this if type is VX_LOCATION_AUTO ) */
        svxPoint2 SecondPoint;    /**<@brief  the second point
                                     (ignore this if type is not VX_LOCATION_CORNER ) */
    } svxViewLocationData;

    /**
    @brief drawing view layout method
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxViewLayoutMethod
    {
        int projection;          /**<@brief  1 if the first perspective,  
                                      2 if the third perspective  
                                      default:2 */
        int count;               /**<@brief  The number of valid values for "StdMethod"   
                                      "count" has a maximum of 7 and a minimum of 1.    
                                      default:3 */
        evxViewStd StdMethod[7]; /**<@brief  StdMethod[0] is base view orientations, others are projection view orientations   
                                      StdMethod[0] is in the range of VX_VIEW_FRONT to VX_VIEW_LEFT   
                                      other StdMethod is in the range of VX_VIEW_FRONT to VX_VIEW_ISO   
                                      default:[0]= VX_VIEW_FRONT,[1]=VX_VIEW_TOP,[2]=VX_VIEW_RIGHT */
    } svxViewLayoutMethod;

    /**
    @brief View layout display attributes
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxViewAt
    {
        svxWireAt zWireAt;   /**<@brief  Attributes for wireframe */
        char fHLROn;         /**<@brief  display mode (0 ~ 3) */
        char fBiarc;         /**<@brief  convert curves to arc on(1)/off(0) */
        char fDupFlt;        /**<@brief  remove duplicated curves on(1)/off(0) */
        char fShwDim;        /**<@brief  show dimensions from part (1) or not(0) */
        char fShwLbl;        /**<@brief  show label (1) or not(0) */
        char fShwScl;        /**<@brief  show scale (1) or not(0) */
        char fShwPmi;        /**<@brief  show PMI entities inherited from part (1/2) or not(0) */
                             /**<@brief  1: inherit parallel PMI; 2: inherit all PMI */
        char fExplod;        /**<@brief  Explode mode (1) or not(0) */
        char fNoProp;        /**<@brief  hidden line check for intersecting shapes off (1)/on(0) */
        char fThread;        /**<@brief  show threads on (1)/off(0) */
        char fCentLin;       /**<@brief  show center lines on (1)/off(0) */
        char fBendLin;       /**<@brief  show bend lines from sheet metal on (1)/off(0) */
        char fWirefrm;       /**<@brief  show 3D curves from part on (1)/off(0) */
        char fNoRegen;       /**<@brief  do not Regen View on (1)/off(0) */
        char fAnno;          /**<@brief  show texts from part on (1)/off(0) */
        char fBeads;         /**<@brief  show weld beads from part (1) or not(0) */
        svxWireAt zLnAt[18]; /**<@brief  view line type (see evxViewLineAttrIdx) display attributes */
        char fShw3DOrig;     /**<@brief  show 3D zero point (1) or not (0) */
        char fHiddenLin;     /**<@brief  show hidden lines on(1)/off(0) */
        vxName label;        /**<@brief  view label */
        char fScaleType;     /**<@brief  scale type   
                        0 view scale explicitly assigned to view by user  
                        1 view scale comes from sheet preference  
                        2 view scale comes from parent view */
        double dSclRatioX;   /**<@brief  Scale ratio value X */
        double dSclRatioY;   /**<@brief  Scale ratio value Y */
        double dScale;       /**<@brief  decimal display scale */
    } svxViewAt;

    /**
    @brief drawing view layout data
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxViewLayoutData
    {
        vxPath name;                     /**<@brief  file name of the projected part or assembly (file that is unloaded must use the full path) */
        vxRootName root;                 /**<@brief  root name.(This parameter is required only when the z3 file is passed in.)*/
        svxViewLocationData location;    /**<@brief  location of the views */
        int isIgnoreLoc;                 /**<@brief  1 if ignore location and use default,else 0 */
        svxViewLayoutMethod method;      /**<@brief  layout method */
        int isIgnoreMethod;              /**<@brief  1 if ignore method and use default,else 0 */
        svxViewAt viewAttr;              /**<@brief  view attribute */
        int isIgnoreAttr;                /**<@brief  1 if ignore viewAttr and use default,else 0 */
        int coordinate;                  /**<@brief  projection coordinate system, default:1 to use the global coordinate system */
        vxName PartConfig;               /**<@brief  part config name ,PartConfig[0]=0 to ignore */
        vxName CompConfig;               /**<@brief  component configuration name, CompConfig[0]=0 to ignore */
        int ExplodedView;                /**<@brief  exploded view ,default:0 */
        int state;                       /**<@brief  index for the backup feature, default:-1 */
        int DimensionType;               /**<@brief  0 if projected, 1 if true. default:0. */
        int isCalculate;                 /**<@brief  1 if calculate part center ,else 0. default:1 */
        int cntBlankRefEnts;             /**<@brief  count of blankRefEntsData. 0 to ignore. */
        svxRefEntData *blankRefEntsData; /**<@brief  list of reference entity data.cntBlankRefEnts=0 to ignore it.
                                     This variable represents an entity hidden after the view is generated. */
        int cntBlankLayers;              /**<@brief  count of blankLayers. 0 to ignore. */
        int *blankLayers;                /**<@brief  list of blank layers, data.cntBlankLayers=0 to ignore it.
                                        the entities on the layers will be hidden after the view is generated. */
    } svxViewLayoutData;

    /**
    @brief View type, more detailed than evxViewType
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxViewTypeEx
    {
        VX_VU_NULL           = 0,  /**<@brief  undefined */
        VX_VU_TOP            = 1,  /**<@brief  top view */
        VX_VU_FRONT          = 2,  /**<@brief  front view */
        VX_VU_RIGHT          = 3,  /**<@brief  right view */
        VX_VU_BACK           = 4,  /**<@brief  back view */
        VX_VU_BOTTOM         = 5,  /**<@brief  bottom view */
        VX_VU_LEFT           = 6,  /**<@brief  left view */
        VX_VU_ISO_FRONT      = 7,  /**<@brief  front isometric view */
        VX_VU_AUX            = 8,  /**<@brief  "auxiliary" view */
        VX_VU_NAME           = 9,  /**<@brief  named view */
        VX_VU_3RD_UP         = 10, /**<@brief  view projected 3rd angle from above */
        VX_VU_3RD_DN         = 11, /**<@brief  view projected 3rd angle from below */
        VX_VU_3RD_RT         = 12, /**<@brief  view projected 3rd angle from right */
        VX_VU_3RD_LT         = 13, /**<@brief  view projected 3rd angle from left */
        VX_VU_1ST_UP         = 14, /**<@brief  view projected 1st angle from above */
        VX_VU_1ST_DN         = 15, /**<@brief  view projected 1st angle from below */
        VX_VU_1ST_RT         = 16, /**<@brief  view projected 1st angle from right */
        VX_VU_1ST_LT         = 17, /**<@brief  view projected 1st angle from left */
        VX_VU_3RD_PRJ_ANG    = 18, /**<@brief  view projected at angle, 3rd angle projection */
        VX_VU_DETAIL         = 19, /**<@brief  detail view */
        VX_VU_SECTION        = 20, /**<@brief  section view */
        VX_VU_DETAIL_DEF     = 21, /**<@brief  detail definition */
        VX_VU_SECTION_DEF    = 22, /**<@brief  section definition */
        VX_VU_REV_SECT_DEF   = 23, /**<@brief   revolved section definition */
        VX_VU_ROTATE         = 24, /**<@brief  rotated view */
        VX_VU_ALIGN_SECT_DEF = 25, /**<@brief  aligned section definition */
        VX_VU_PRJ_ANG_ARROWS = 26, /**<@brief  aux view arrows */
        VX_VU_BEND_SECT_DEF  = 27, /**<@brief  bend section definition */
        VX_VU_ISO_LFT        = 28, /**<@brief  left-front-top side isometric view */
        VX_VU_ISO_LBT        = 29, /**<@brief  left-back-top side isometric view */
        VX_VU_ISO_RBT        = 30, /**<@brief  right-back-top side isometric view */
        VX_VU_ISO_RFB        = 31, /**<@brief  right-front-bottom side isometric view */
        VX_VU_ISO_LFB        = 32, /**<@brief  left-front-bottom side isometric view */
        VX_VU_ISO_LBB        = 33, /**<@brief  left-back-bottom side isometric view */
        VX_VU_ISO_RBB        = 34, /**<@brief  right-back-bottom side isometric view */
        VX_VU_NAME_SECT_DEF  = 35, /**<@brief  3D named sect def'n  */
        VX_VU_1ST_PRJ_ANG    = 36, /**<@brief  view projected at angle, 1st angle projection */
        VX_VU_BRKSECT        = 37, /**<@brief  broken section */
        VX_VU_ISOSECT        = 38, /**<@brief  3D isometric section view */
        VX_VU_DIMETRIC       = 39, /**<@brief  dimetric view */
        VX_VU_SMD            = 40  /**<@brief  selected sheet metal flat item view */
    } evxViewTypeEx;

    /**
    @brief drawing view standard data
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxViewStandardData
    {
        vxLongPath path;      /**<@brief  file path */
        vxLongPath fileName;  /**<@brief  file name (including the extension) */
        vxRootName rootName;  /**<@brief  root name */
        int type;             /**<@brief  1 is use view manager custom view name(this manager in part environment),
                                       2 is use flattening feature name of a sheet metal module(this manager in part environment),  
                                       0 is use native type */
        union uvxViewTypeData /**<@brief  union of view type data */
        {
            vxName viewName;        /**<@brief  view Name. if type = 1,apply it. */
            vxName flatName;        /**<@brief  flatten Name. if type = 2, apply it. */
            evxViewTypeEx viewType; /**<@brief  View type(1-7,28-34,39). if type = 0,apply it. */
        } option;
        svxPoint2 location;              /**<@brief  location */
        int isIgnoreAttr;                /**<@brief  1 if ignore viewAttr and use default,else 0 */
        svxViewAt viewAttr;              /**<@brief  view attribute */
        int origin;                      /**<@brief  Origin ,default:1 */
        int coordinate;                  /**<@brief  coordinate,default:1 */
        vxName partConfig;               /**<@brief  part config name ,PartConfig[0]=0 to ignore */
        vxName compConfig;               /**<@brief  component configuration name, CompConfig[0]=0 to ignore */
        int explodedView;                /**<@brief  exploded view ,default:0 */
        int isDispTrails;                /**<@brief  1 if display exploded trails ,else 0.default:0 */
        int state;                       /**<@brief  index for the backup feature, default:1 */
        int dimensionType;               /**<@brief  0 if projected, 1 if true. default:0. */
        int isCalculate;                 /**<@brief  1 if calculate part center ,else 0. default:1 */
        int isOrientation;               /**<@brief  1 if view orientation from parent, else 0. default:1 */
        int cntBlankRefEnts;             /**<@brief  count of blankRefEntsData. 0 to ignore. */
        svxRefEntData *blankRefEntsData; /**<@brief  list of reference entity data.cntBlankRefEnts=0 to ignore it.
                                     This variable represents an entity hidden after the view is generated. */
        int cntBlankLayers;              /**<@brief  count of blankLayers. 0 to ignore. */
        int *blankLayers;                /**<@brief  list of blank layers, data.cntBlankLayers=0 to ignore it.
                                        the entities on the layers will be hidden after the view is generated. */
    } svxViewStandardData;

    /**
    @brief view projection type
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxViewPrjAngType
    {
        VX_VIEW_PRJANG1ST = 1, /**<@brief  1st angle */
        VX_VIEW_PRJANG3RD = 2, /**<@brief  3rd angle */
    } evxViewPrjAngType;

    /**
    @brief view dimension type
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxViewDimType
    {
        VX_VIEW_DIMTYPEPRJ  = 0, /**<@brief  dimension type : Projected */
        VX_VIEW_DIMTYPETRUE = 1, /**<@brief  dimension type : True */
    } evxViewDimType;

    /**
    @brief Projection or Auxiliary view's projection settings
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxPrjSetting
    {
        evxViewPrjAngType prjType; /**<@brief  Projection or Auxiliary view's projection angle (VX_VIEW_PRJANG3RD as default)*/
        evxViewDimType dimType;    /**<@brief  Projection or Auxiliary view's dimension type (VX_VIEW_DIMTYPEPRJ as default)*/
    } svxPrjSetting;

    /**
    @brief view projection arrow
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxViewArrow
    {
        double offset; /**<@brief  view line offset distance (20.0 as default)*/

        int iFlag;          /**<@brief  iFlag = 0, startPnt and entPnt will use default value (user input is invalid)
                                  iFlag > 0, startPnt and entPnt of user input are valid*/
        svxPoint2 startPnt; /**<@brief  arrow start location */
        svxPoint2 endPnt;   /**<@brief  arrow end location */
    } svxViewArrow;

    /**
    @brief Auxiliary view data
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxAuxViewData
    {
        int idView;             /**<@brief  the id of base view */
        int idLine;             /**<@brief  line to define auxiliary view plane (this must be a line)*/
        svxPoint2 locPnt;       /**<@brief  view location */
        svxPrjSetting settings; /**<@brief  projection settings */
        svxViewArrow arrowInfo; /**<@brief  view arrow */
    } svxAuxViewData;

    /**
    @brief section method type
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxSecMtdType
    {
        VX_METHOD_SECCURVE = 1, /**<@brief  Section Method : Sect Curves */
        VX_METHOD_TRIMPART = 2, /**<@brief  Section Method : Trimmed Part */
        VX_METHOD_TRIMSURF = 3, /**<@brief  Section Method : Trimmed Surface */
    } evxSecMtdType;

    /**
    @brief section location
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxLocType
    {
        VX_LOC_HORIZONTAL = 1, /**<@brief  Location : Horizontal */
        VX_LOC_VERTICAL   = 2, /**<@brief  Location : Vertical */
        VX_LOC_ORTHOGONAL = 3, /**<@brief  Location : Orthogonal */
        VX_LOC_NONE       = 4, /**<@brief  Location : None */
    } evxLocType;

    /**
    @brief location angle
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxLocAngType
    {
        VX_LOC_ANG_DEFAULT    = 0, /**<@brief  default */
        VX_LOC_ANG_HORIZONTAL = 1, /**<@brief  horizontal */
        VX_LOC_ANG_VERTICAL   = 2, /**<@brief  vertical */
        VX_LOC_ANG_CUSTOM     = 3, /**<@brief  custom */
    } evxLocAngType;

    /**
    @brief section method
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxViewSecMtd
    {
        evxSecMtdType mtdType;    /**<@brief  section method (VX_METHOD_TRIMPART as default)*/
        int iCloseOpenProf;       /**<@brief  close open profiles or not (1 as default)*/
        int iDynScalAng;          /**<@brief  dynamic hatch scaling and angle or not (1 as default)*/
        int inheritSecBasView;    /**<@brief  inherit section from base view or not
                                    if base view is not section view, this value can be ignored
                                    if base view is section view, this value equals to 0 or 1*/
        evxLocType locType;       /**<@brief  location type (VX_LOC_ORTHOGONAL as default)*/
        evxViewDimType dimType;   /**<@brief  dimension type (VX_VIEW_DIMTYPEPRJ as default)*/
        double dSecDepth;         /**<@brief  section depth (if mtdType = VX_METHOD_SECCURVE, this can be ignored.)
                                             this parameter would be ignored in aligned section view. */
        evxLocAngType locAngType; /**<@brief  location angle type */
        double dLocAng;           /**<@brief  location angle (only used when locAngType = VX_LOC_ANG_CUSTOM) */
    } svxViewSecMtd;

    /**
    @brief section line
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxViewSecLine
    {
        char *viewLabel;    /**<@brief  view label (example: "A" becomes "A-A")
                                    the label doesn't duplicate the existing label
                                    null or "" to use default label*/
        int iFlipArrow;     /**<@brief  flip arrow or not (0 as default)*/
        int iShowStepLines; /**<@brief  show step lines or not (0 as default)*/
    } svxViewSecLine;

    /**
    @brief section option
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxViewSecOp
    {
        int iSecState;   /**<@brief  component section state from part */
        int iHatchState; /**<@brief  component hatch state from part */
        int iHatchClr;   /**<@brief  hatch color from part */
    } svxViewSecOp;

    /**
    @brief full section view data
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxFulSecViewData
    {
        int idView; /**<@brief  the id of base view to section */

        int iCnt;         /**<@brief  the count of the points */
        svxPoint2 *pPnts; /**<@brief  points to define section */

        svxPoint2 locPnt;       /**<@brief  the location for section view */
        svxViewSecMtd secMtd;   /**<@brief  section method */
        svxViewSecLine secLine; /**<@brief  section line */
        svxViewSecOp secOp;     /**<@brief  section option */
    } svxFulSecViewData;

    /**
    @brief aligned section view data
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxAlignSecViewData
    {
        int idView;             /**<@brief  the id of base view to section */
        svxPoint2 basePnt;      /**<@brief  base point of the section */
        int cntBasePnts;        /**<@brief  the count of the base points */
        svxPoint2 *pBasePnts;   /**<@brief  points to define the section */
        int cntAlignPnts;       /**<@brief  the count of the align points */
        svxPoint2 *pAlignPnts;  /**<@brief  points to define aligned cutting plane */
        svxPoint2 locPnt;       /**<@brief  the location for section view */
        svxViewSecMtd secMtd;   /**<@brief  section method */
        svxViewSecLine secLine; /**<@brief  section line */
        svxViewSecOp secOp;     /**<@brief  section option */
    } svxAlignSecViewData;

    /**
    @brief Drawing Broken Section Boundary Method
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxDwgBndMethod
    {
        VX_RECTANGULAR_BOUNDARY = 1, /**<@brief  Rectangular boundary */
        VX_CIRCULAR_BOUNDARY,        /**<@brief  Circular boundary */
        VX_POLYLINE_BOUNDARY,        /**<@brief  Polyline boundary */
    } evxDwgBndMethod;

    /**
    @brief Drawing Broken Section Depth type
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxDwgDepthType
    {
        VX_DEPTH_POINT,         /**<@brief  point */
        VX_DEPTH_SECTION_PLANE, /**<@brief  section plane */
        VX_DEPTH_3D_NAMED,      /**<@brief  3d named */
    } evxDwgDepthType;

    /**
    @brief Drawing Broken Section input infos
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxDwgBrokenSectionData
    {
        evxDwgBndMethod method; /**<@brief  Boundary Method */
        int idView;             /**<@brief  Base view */
        svxPoint2 *bPoints;     /**<@brief  The boundary is made up of points */
        int countBPs;           /**<@brief  count of "bPoints" */
        evxDwgDepthType type;   /**<@brief  depth type */
        svxPoint2 dPoint;       /**<@brief  depth point */
        int idCrv;              /**<@brief  curve id.
                                      if type == VX_DEPTH_POINT, point "dPoint" must be on the curve "idCrv" */
        double dOffset;         /**<@brief  depth offset */
        int dView;              /**<@brief  depth view */
        vxName name;            /**<@brief  3D name */
        int isShow;             /**<@brief  show step lines */
        int isDynamicHatch;     /**<@brief  dynamic hatch scaling and angle */
        svxPoint2 *oPoints;     /**<@brief  offset points */
        int countOPs;           /**<@brief  count of "oPoints" */
    } svxDwgBrokenSectionData;

    /**
    @brief Drawing Detail Method
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxDwgDetailMethod
    {
        VX_RECTANGULAR_DETAIL = 1, /**<@brief  rectangular detail view */
        VX_CIRCULAR_DETAIL    = 2, /**<@brief  circular detail view */
        VX_POLYLINE_DETAIL,        /**<@brief  polyline detail view */
    } evxDwgDetailMethod;

    /**
    @brief Drawing Detail input infos
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxDwgDetailData
    {
        evxDwgDetailMethod method; /**<@brief  Detail Method */
        int idView;                /**<@brief  Base view */
        int PntCount;              /**<@brief  all points count */
        svxPntOnEnt *pPnts;        /**<@brief  pick points defining the detail boundary */
        svxPntOnEnt NotePnt;       /**<@brief  pick point for note */
        int iMultiplier;           /**<@brief  local magnification */
        svxPntOnEnt Location;      /**<@brief  local detail view position */
    } svxDwgDetailData;

    /**
    @brief option of break line
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxBrkLineType
    {
        VX_HOR_BRKLINE = 0, /**<@brief  Horizontal break line */
        VX_VER_BRKLINE,     /**<@brief  Vertical break line */
        VX_SLANT_BRKLINE    /**<@brief  Slant break line */
    } evxBrkLineType;

    /**
    @brief information we need when create break line
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxBrkLineData
    {
        int viewId;               /**<@brief  id of view */
        evxBrkLineType brkLnType; /**<@brief  option of break line */
        svxPntOnEnt pts[3];       /**<@brief  3 input points depend on option of break line.
                             only VX_SLANT_BRKLINE needs the third point, others need two points */
        double gap;               /**<@brief  gap size */
        svxPoint2 dir;            /**<@brief  direction setting, only required when evxBrkLineType is VX_SLANT_BRKLINE */
    } svxBrkLineData;

    //====================================================================================================================
    /** @name Table Data */
    //====================================================================================================================

    /**
    @brief level set
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxLevelSet
    {
        VX_TOP_LEVEL_ONLY = 0, /**<@brief  Top-level only */
        VX_PARTS_ONLY     = 1, /**<@brief  Parts only */
        VX_INDENTED       = 3, /**<@brief  Indented */
        VX_BALLOON_ONLY   = 4, /**<@brief  by balloon only */
    } evxLevelSet;

    /**
    @brief indent type
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxIndentedType
    {
        VX_NO_NUM       = 0, /**<@brief  No numbering */
        VX_DETAILED_NUM = 1, /**<@brief  Detailed numbering */
        VX_FLAT_NUM     = 2, /**<@brief  Flat numbering */
    } evxIndentedType;

    /**
    @brief order type
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxOrderType
    {
        VX_ORDER_BYNAME    = 0, /**<@brief  Order by name */
        VX_ORDER_REGEN_IDS = 1, /**<@brief  Regenerate IDs after sort */
        VX_ORDER_ASASM     = 2, /**<@brief  Order as assembly */
    } evxOrderType;

    /**
    @brief BOM set
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxBomset
    {
        VX_BOM_INVALID    = 0x0000, /**<@brief  all is not valid */
        VX_SET_DISP_CFG   = 0x0001, /**<@brief  Display configurations of the same as one item */
        VX_DERIVED_PARTS  = 0x0002, /**<@brief  Derived parts as instances of source part */
        VX_SYNC_BOM       = 0x0004, /**<@brief  Sync BOM table with part attributes */
        VX_KEEP_MISSING   = 0x0008, /**<@brief  Keep missing item */
        VX_STRIKE_THROUGH = 0x0010, /**<@brief  Strike through */
        VX_BOM_VALID      = 0xFFFF  /**<@brief  all is valid */
    } evxBomset;

    /**
    @brief dwg text condition
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxDwgTextCondition
    {
        VX_DWG_CON_STANDARD = 0, /**<@brief  standard attribute */
        VX_DWG_CON_PHYSICAL,     /**<@brief  physical attribute */
        VX_DWG_CON_FILE,         /**<@brief  file information */
        VX_DWG_CON_ECAD,         /**<@brief  ecad attribute */
        VX_DWG_CON_USER,         /**<@brief  user attribute */
        VX_DWG_CON_USER_TEXT,    /**<@brief  custom text */
    } evxDwgBalloonTextCondition, evxDwgBomTextCondition;

    /**
    @brief dwg text sub condition
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxDwgTextSubCondition
    {
        /* evxDwgTextCondition::VX_DWG_CON_STANDARD */
        VX_DWG_SUB_CON_ID          = 0,  /**<@brief  id */
        VX_DWG_SUB_CON_DERIVEDFROM = 1,  /**<@brief  derived from, merge support */
        VX_DWG_SUB_CON_NUMBER      = 2,  /**<@brief  number, merge support */
        VX_DWG_SUB_CON_DESIGNER    = 3,  /**<@brief  designer, merge support */
        VX_DWG_SUB_CON_MANAGER     = 4,  /**<@brief  manager, merge support */
        VX_DWG_SUB_CON_REMARKS     = 5,  /**<@brief  remarks */
        VX_DWG_SUB_CON_SUPPLIER    = 6,  /**<@brief  supplier, merge support */
        VX_DWG_SUB_CON_COST        = 7,  /**<@brief  cost, merge support */
        VX_DWG_SUB_CON_CLASS       = 8,  /**<@brief  class, merge support */
        VX_DWG_SUB_CON_KEYWORDS    = 9,  /**<@brief  keywords, merge support */
        VX_DWG_SUB_CON_DESCRIPTION = 10, /**<@brief  description, merge support */
        VX_DWG_SUB_CON_QUANTITY    = 11, /**<@brief  quantity */
        VX_DWG_SUB_CON_VISIBLE     = 12, /**<@brief  visible */

        /* evxDwgTextCondition::VX_DWG_CON_PHYSICAL */
        VX_DWG_SUB_CON_DENSITY   = 0, /**<@brief  density */
        VX_DWG_SUB_CON_MASS      = 1, /**<@brief  mass */
        VX_DWG_SUB_CON_AREA      = 2, /**<@brief  area */
        VX_DWG_SUB_CON_VOLUME    = 3, /**<@brief  volume */
        VX_DWG_SUB_CON_LENGTH    = 4, /**<@brief  length */
        VX_DWG_SUB_CON_WIDTH     = 5, /**<@brief  width */
        VX_DWG_SUB_CON_HEIGHT    = 6, /**<@brief  height */
        VX_DWG_SUB_CON_STOCKSIZE = 7, /**<@brief  stock size */
        VX_DWG_SUB_CON_SIZE      = 8, /**<@brief  size */
        VX_DWG_SUB_CON_MATERIAL  = 9, /**<@brief  material */

        /* evxDwgTextCondition::VX_DWG_CON_FILE */
        VX_DWG_SUB_CON_NAME      = 0, /**<@brief  legend */
        VX_DWG_SUB_CON_FILEPATH  = 1, /**<@brief  source file path */
        VX_DWG_SUB_CON_STARTDATE = 2, /**<@brief  start date */
        VX_DWG_SUB_CON_ENDDATE   = 3, /**<@brief  end date */

        /* evxDwgTextCondition::VX_DWG_CON_ECAD */
        VX_DWG_SUB_CON_ECAD_REF_DES    = 0, /**<@brief  ECAD_RefDes */
        VX_DWG_SUB_CON_ECAD_BOARD_SIDE = 1, /**<@brief  ECAD board side */

        /* evxDwgTextCondition::VX_DWG_CON_USER and evxDwgTextCondition::VX_DWG_CON_USER_TEXT */
        VX_DWG_SUB_CON_NULL = -1,
    } evxDwgBalloonTextSubCondition, evxDwgBomTextSubCondition;

    /**
    @brief BOM table format data
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxDwgBomTableElement
    {
        evxDwgBomTextCondition condition;       /**<@brief  dwg text condition. VX_DWG_CON_USER_TEXT won't take effect in this struct */
        evxDwgBomTextSubCondition subCondition; /**<@brief  dwg text sub condition */
        char attrName[64];                      /**<@brief  attribute item name, can't be empty when condition = VX_DWG_CON_USER */
    } svxDwgBomTableElement;

    /**
    @brief BOM table data
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxDwgBom
    {
        int idView;             /**<@brief  id of View */
        char *name;             /**<@brief  name */
        evxLevelSet level;      /**<@brief  Level Setting, default value:VX_TOP_LEVEL_ONLY*/
        evxIndentedType indent; /**<@brief  Indented type(default value:VX_DETAILED_NUM): to define how to number the components from the sub-assembly*/
        int checkMax;           /**<@brief  whether to use Max traverse depth: 0(default value) no, else yes*/
        int Maxdepthval;        /**<@brief  Max traverse depth value(default value:1): to define which assembly level BOM should read out up to*/
        int bomset;             /**<@brief  Settings by evxBomset, default value:VX_DERIVED_PARTS */
        int startID;            /**<@brief  starting ID, default value:1*/
        evxOrderType order;     /**<@brief  Order, default value:VX_ORDER_BYNAME*/

        /* Table format */
        vxLongPath templatePath; /**<@brief  the full path of table template file */
        int Inherit3DBom;        /**<@brief  whether to inherit 3D BOM (1: yes; 0: no) */

        int tableElementNum;                     /**<@brief  number of table elements in tableElement list */
        svxDwgBomTableElement *tableElement;     /**<@brief  table elements list VX_DWG_CON_USER_TEXT won't take effect in this struct */
        svxDwgBomTableElement *sortTableElement; /**<@brief  table element to sort BOM table, NULL to use the first table element.
                                                      VX_DWG_CON_USER_TEXT won't take effect in this struct */

        int sortOrderMode;                    /**<@brief  sort the attribute item in either ascending (0) or descending (1) order */
        int regenSort;                        /**<@brief  resort when regenerating (1: yes; 0: no) */
        svxDwgBomTableElement *mergeAttrItem; /**<@brief  attribute item to merge BOM table, can be NULL
                                                   only some standard condition support merging, for details, see the description of evxDwgTextSubCondition */

        /* Filter */
        int includeUnplacedComp;      /**<@brief  whether to include unplaced component (1: yes; 0: no) */
        int includeShape;             /**<@brief  whether to include shape (1: yes; 0: no) */
        int nFilterRefEnts;           /**<@brief  count of blankRefEntsData. 0 to ignore. */
        svxRefEntData *filterRefEnts; /**<@brief  list of reference entity data.cntBlankRefEnts=0 to ignore it.
                                                     This variable represents an entity filtered after the BOM is created. */
    } svxDwgBom;

    /**
    @brief origin type
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxOriginType
    {
        VX_TOP_LEFT   = 0, /**<@brief  Top-Left */
        VX_TOP_CENTER = 1, /**<@brief  Top-Center */
        VX_TOP_RIGHT  = 2, /**<@brief  Top-Right */
        VX_MID_LEFT,       /**<@brief  Mid-Left */
        VX_MID_CENTER,     /**<@brief  Mid-Center */
        VX_MID_RIGHT,      /**<@brief  Mid-Right */
        VX_BOTTOM_LEFT,    /**<@brief  Bottom-Left */
        VX_BOTTOM_CENTER,  /**<@brief  Bottom-Center */
        VX_BOTTOM_RIGHT,   /**<@brief  Bottom-Right */
    } evxOriginType;

    /**
    @brief insert Table
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxDwgTblInsert
    {
        int idTable;          /**<@brief  insert table id */
        svxPoint2 crtpnt;     /**<@brief  Point */
        evxOriginType origin; /**<@brief  Origin, default value:VX_TOP_LEFT*/
    } svxDwgTblInsert;

    //====================================================================================================================
    /** @name Edit View  Data */
    //====================================================================================================================
    /**
    @brief type of view
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxRotViewType
    {
        VX_ROTVIEW_TOP   = 1,     /**<@brief  top */
        VX_ROTVIEW_FRONT = 2,     /**<@brief  front */
        VX_ROTVIEW_RIGHT,         /**<@brief  right */
        VX_ROTVIEW_BACK,          /**<@brief  back */
        VX_ROTVIEW_BOTTOM,        /**<@brief  bottom */
        VX_ROTVIEW_LEFT,          /**<@brief  left */
        VX_ROTVIEW_ISOMETRIC,     /**<@brief  isometric */
        VX_ROTVIEW_ISOMETRIC_LFT, /**<@brief  isometric_left-front-top */
        VX_ROTVIEW_ISOMETRIC_LBT, /**<@brief  isometric_left-back-top */
        VX_ROTVIEW_ISOMETRIC_RBT, /**<@brief  isometric_right-back-top */
        VX_ROTVIEW_ISOMETRIC_RFB, /**<@brief  isometric_right-front-bottom */
        VX_ROTVIEW_ISOMETRIC_LFB, /**<@brief  isometric_left-front-bottom */
        VX_ROTVIEW_ISOMETRIC_LBB, /**<@brief  isometric_left-back-bottom */
        VX_ROTVIEW_ISOMETRIC_RBB, /**<@brief  isometric_right-back-bottom */
        VX_ROTVIEW_CUSTOM,        /**<@brief  custom view */
    } evxRotViewType;

    /**
    @brief Rotate View
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxDwgRotView
    {
        int idView;          /**<@brief  id of View */
        evxRotViewType view; /**<@brief  type of View (default value:VX_ROTVIEW_TOP): to set the view projection direction*/
        evxAxisType axis;    /**<@brief  type of Axis, default value:VX_AXIS_Z*/
        double angle;        /**<@brief  rotate angle default value:0*/
        int customViewId;    /**<@brief  id of custom view angle in part referenced by idView. taking effect only when view = VX_ROTVIEW_CUSTOM */
    } svxDwgRotView;

    //====================================================================================================================
    /** @name Dimension Data */
    //====================================================================================================================
    /**
    @brief select geometry entity type
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxAutoEntType
    {
        DIM_AUTO_ENT_ALL = 0,    /**<@brief  entity type is all */
        DIM_AUTO_ENT_ARC_CIRCLE, /**<@brief  entity type is all arc/circle */
        DIM_AUTO_ENT_PICKED      /**<@brief  entity type is picked by user */
    } evxAutoEntType;

    /**
    @brief auto dimension type
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxAutoDimType
    {
        DIM_AUTO_BASELINE         = 0, /**<@brief  baseline */
        DIM_AUTO_CONTINUOUS       = 1, /**<@brief  continuous */
        DIM_AUTO_ORDINATE         = 2, /**<@brief  ordinate dimension */
        DIM_AUTO_LABEL_COORDINATE = 3, /**<@brief  label ordinate dimension */
    } evxAutoDimType;

    /**
    @brief dimension position/placement
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxAutoPlacement
    {
        DIM_VIEW_ABOVE_LEFT = 0, /**<@brief  left or above of view */
        DIM_VIEW_BELOW_RIGHT,    /**<@brief  right or below of view */
        DIM_VIEW_BOTH,           /**<@brief  both of view */
    } evxAutoPlacement;

    /**
    @brief dimension position
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxAutoSet
    {
        int enable;                /**<@brief  svxAutoSet enabled or not */
        evxAutoDimType type;       /**<@brief  select auto dimension type */
        svxPntOnEnt refPnt;        /**<@brief  reference point, used when enable is 1*/
        evxAutoPlacement viewType; /**<@brief  dimensions position / placement, default value:DIM_VIEW_BELOW_RIGHT*/
        int asgrp;                 /**<@brief  1:auto dimensions are as group dimension* 0:not, default value:1*/
    } svxAutoSet;

    /**
    @brief auto dimension include
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxAutoInclude
    {
        VX_AUTOINC_INVALID      = 0x00000000, /**<@brief  all is not valid */
        VX_AUTOINC_ARC          = 0x00000001, /**<@brief  Include arc */
        VX_AUTOINC_CIRCLE       = 0x00000002, /**<@brief  Include circle */
        VX_AUTOINC_HOLE         = 0x00000004, /**<@brief  Include hole */
        VX_AUTOINC_LINE         = 0x00000008, /**<@brief  Include line */
        VX_AUTOINC_HOLE_CALLOUT = 0x00000010, /**<@brief  Include Hole callout  */
        VX_AUTOINC_CYLIND_DIM   = 0x00000020, /**<@brief  Include cylindrical dimensions */
        VX_AUTOINC_MAXIMUM_DIM  = 0x00000040, /**<@brief  Include maximum dimensions */
        VX_AUTOINC_VALID        = 0xFFFFFFFF  /**<@brief  all is valid */
    } evxAutoInclude;

    /**
    @brief auto dimension
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxDimAuto
    {
        int idView;             /**<@brief  index of View */
        evxAutoEntType entType; /**<@brief  select entity type, default value:DIM_AUTO_ENT_ALL*/
        int cntEnt;             /**<@brief  entity ID count.
                                          if type = DIM_AUTO_ENT_PICKED, number of entities need to be created dimension,
                                          other type can be null */
        int *pEntId;            /**<@brief  entity ID list.
                                          if type = DIM_AUTO_ENT_PICKED, list id of entities need to be created dimension,
                                          other type can be null */
        unsigned int incAuto;   /**<@brief  evxAutoInclude mask.
                                          whether to include arc, circle, hole, line, R/hole callout, cylindrical 
                                          dimensions and maximum dimensions(0 = no, 1 = yes) */
        int checkOrg;           /**<@brief  origin check flag, default value:1*/
        svxPntOnEnt pntOrg;     /**<@brief  origin reference point, member critPnt should be entity critical point */
        svxAutoSet horDim;      /**<@brief  horizontal dimensions position/placement */
        svxAutoSet verDim;      /**<@brief  vertical dimensions position/placement */
    } svxDimAuto;

    /**
    @brief dimension Line type
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxDimLineType
    {
        VX_DIM_LINE_LH = 1, /**<@brief  horizontal dimension */
        VX_DIM_LINE_LV = 2, /**<@brief  vertical dimension */
        VX_DIM_LINE_LA = 3, /**<@brief  aligned dimension */
        VX_DIM_LINE_LR = 4, /**<@brief  rotated dimension */
        VX_DIM_LINE_LP = 5, /**<@brief  projected dimension */
        VX_DIM_LINE_LO = 6, /**<@brief  ordinate dimension, only used in cvxDwgOrdinateDimAdd():
                                 create a linear ordinate horizontal dimension groups
                                 and the linear ordinate vertical dimension groups.*/
    } evxDimLineType;

    /**
    @brief data of constraint dimension
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxDwgConsDim
    {
        evxDimLineType type;   /**<@brief  type of dimension default value:horizontal method*/
        svxPntOnEnt firstPnt;  /**<@brief  first point */
        svxPntOnEnt secondPnt; /**<@brief  second point */
        svxPntOnEnt textPnt;   /**<@brief  text point: to locate the dimension text */
    } svxDwgConsDim;

    /**
    @brief Linear
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxDwgLineDim
    {
        svxDwgConsDim cons; /**<@brief  constraint dimension, 5 type of line dimension */
        double angle;       /**<@brief  dimension angle.
                                   if type = VX_DIM_LINE_LR, it is the angle between target line and vertical line,
                                   other type can be null */
        svxPntOnEnt dirPnt; /**<@brief  the point on the project line.
                                   if type = VX_DIM_LINE_LP, the point is on the project line, can regard as the entity of project line,
                                   other type can be null */
    } svxDwgLineDim;

    /**
    @brief Baseline, Continuous
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxDwgLineGrpDim
    {
        svxDwgLineDim sub;   /**<@brief  Linear constraint dimension */
        int cntCrv;          /**<@brief  no. of Points data items */
        svxPntOnEnt *Points; /**<@brief  list of "cntCrv"  Points */
    } svxDwgLineGrpDim;

    /**
    @brief Ordinate
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxDwgOrdinateDim
    {
        svxDwgLineDim sub;      /**<@brief  Linear constraint dimension, 6 type of line dimension */
        int cntCrv;             /**<@brief  no. of Points data items */
        svxPntOnEnt *Points;    /**<@brief  list of "cntCrv"  Points */
        int reverseAxis1;       /**<@brief  reverse direction, default value:0 */
        int reverseAxis2;       /**<@brief  reverse direction, default value:0 */
        int idEnt;              /**<@brief  Share origin (Group dimension), 0 to ignore */
        svxPntOnEnt textPnt[2]; /**<@brief  Horizontal(textPnt[0]) and Vertical(textPnt[1]) text point,
                                           used only for sub.cons.type is VX_DIM_LINE_LO */
    } svxDwgOrdinateDim;

    /**
    @brief symmetry dimension type
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxSymmetryDimType
    {
        VX_SYM_LINEAR  = 1, /**<@brief  linear dimension */
        VX_SYM_ANGULAR = 2, /**<@brief  angular dimension */
    } evxSymmetryDimType;

    /**
    @brief dimension off type
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxDimLineOffset
    {
        VX_DIM_OFFSET_LOL = 1, /**<@brief  line to line (Offset Method) */
        VX_DIM_OFFSET_LOP = 2, /**<@brief  point to line (Projected Distance Method) */
    } evxDimLineOffset;

    /**
    @brief Linear Offset
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxDwgLineOffsetDim
    {
        evxDimLineOffset type; /**<@brief  type of dimension default value:VX_DIM_OFFSET_LOL*/
        svxPntOnEnt firstPnt;  /**<@brief  VX_DIM_OFFSET_LOL: first line ; VX_DIM_OFFSET_LOP: first line*/
        svxPntOnEnt secondPnt; /**<@brief  VX_DIM_OFFSET_LOL: second line; VX_DIM_OFFSET_LOP: point*/
        svxPntOnEnt textPnt;   /**<@brief  text point: select a point to locate the dimension text */
    } svxDwgLineOffsetDim;

    /**
    @brief Symmetry dimension data
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxDwgSymmetryDimData
    {
        evxSymmetryDimType type;   /**<@brief  Symmetry dimension type */
        svxPntOnEnt Pnt;           /**<@brief  point coordinate of point on entity, just for type = 0 */
        svxPntOnEnt LinePnt;       /**<@brief  line point coordinates, just for type = 1*/
        svxPntOnEnt CenterLinePnt; /**<@brief  Center Line point coordinates */
        svxPntOnEnt txtPnt;        /**<@brief  text point */
        int autoSwitchAttr;        /**<@brief  1 is auto switch dimension attributes. else 0. 
                                 This parameter can only be used in the sketch environment. */
    } svxDwgSymmetryDimData;

    /**
    @brief type of linear chamfer dim in sheeting
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxDwgLnrChmDimType
    {
        VX_LEADER_CHAMFERDIM = 1, /**<@brief  leader linear chamfer dim */
        VX_ALIGNED_CHAMFERDIM,    /**<@brief  aligned linear chamfer dim */
        VX_HORZORVERT_CHAMFERDIM  /**<@brief  horizontal/vertical linear chamfer dim */
    } evxDwgLnrChmDimType;

    /**
    @brief text style of leader linear chamfer dim in sheeting
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxDwgLnrChmDimTexType
    {
        VX_TEXT_NOR_CHAMFERDIM = 0,       /**<@brief  normal */
        VX_TEXT_PERPENDICULAR_CHAMFERDIM, /**<@brief  always perpendicular */
        VX_TEXT_ALGMODLIN_CHAMFERDIM      /**<@brief  along the model line */
    } evxDwgLnrChmDimTexType;

    /**
    @brief the info of the linear chamfer dim
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxDwgLnrChmDimData
    {
        svxPntOnEnt LineEnt;               /**<@brief  ID and point data of line (the idEnt of "LineEnt" must be valid).
                                              if type = VX_LEADER_CHAMFERDIM, the arrow is point at LineEnt on the chamfer entity,
                                                 other type the LineEnt represent the specified chamfer*/
        evxDwgLnrChmDimType dimType;       /**<@brief  type of line linear chamfer Dim */
        evxDwgLnrChmDimTexType dimTexType; /**<@brief  type of Text, only required when "dimType" is VX_LEADER_CHAMFERDIM */
        svxPntOnEnt textPnt;               /**<@brief  point coordinate of text placement point.
                                                 When "dimType" is VX_HORZORVERT_CHAMFERDIM, this presents,
                                                 horizontal point coordinate of text placement point */
        svxPntOnEnt verTextPnt;            /**<@brief  point coordinate of vertical text placement point,
                                                 only required when "dimType" is VX_HORZORVERT_CHAMFERDIM */
    } svxDwgLnrChmDimData;

    /**
    @brief angular dimension type
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxAngDimType
    {
        VX_ANG_TWOCURVES  = 1, /**<@brief  2 curves angular dimension*/
        VX_ANG_HORIZONTAL = 2, /**<@brief  horizontal angular dimension */
        VX_ANG_VERTICAL   = 3, /**<@brief  vertical angular dimension */
        VX_ANG_THREEPOINT = 4, /**<@brief  3 point angular dimension*/
        VX_ANG_ARC        = 5, /**<@brief  arc angular dimension*/
    } evxAngDimType;

    /**
    @brief Angular dimension dim data
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxDwgAngDimData
    {
        evxAngDimType type; /**<@brief  Angular or diametric type */

        svxPntOnEnt Curve1;      /**<@brief get one entity and point coordinate.   
                                  if type = VX_ANG_TWOCURVES, the angle is between 1st curve and 2nd curve.   
                                  if type = VX_ANG_HORIZONTAL, the angle is between 1st curve and horizontal line.   
                                  if type = VX_ANG_VERTICAL, the angle is between 1st curve and vertical line.   
                                  other type can be null */
        svxPntOnEnt Curve2;      /**<@brief  get one entity and point coordinate.
                                   if type = VX_ANG_TWOCURVES, the angle is between 1st curve and 2nd curve.
                                   other can be null */
        svxPntOnEnt StartPnt;    /**<@brief  start point.
                                   if type = VX_ANG_THREEPOINT, the angle is between two line, 1st line through.
                                   StartPnt and BasePnt.
                                   other type can be null. */
        svxPntOnEnt BasePnt;     /**<@brief  base point.
                                   if type = VX_ANG_THREEPOINT, BasePnt is angle's vertex.
                                   other type can be null. */
        svxPntOnEnt EndPnt;      /**<@brief  end point.
                                   if type = VX_ANG_THREEPOINT, the angle is between two line, 2nd line through.
                                   BasePnt and EndPnt.
                                   other type can be null */
        svxPntOnEnt ArcPnt;      /**<@brief  arc point on arc.
                                   if type = VX_ANG_ARC, the angle is arc's angle.
                                   other type can be null */
        svxPntOnEnt QuadrantPnt; /**<@brief  quadrant point.
                                   if type != VX_ANG_ARC, the point is position of text of angle.*/
        svxPntOnEnt txtPnt;      /**<@brief  text point.
                                   if type = VX_ANG_ARC, the point is position of text of angle.
                                   other type can be null */
    } svxDwgAngDimData;

    /**
    @brief radial or diametric dim type
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxRadDimType
    {
        VX_RAD_RADIAL   = 1, /**<@brief  radial dimension */
        VX_RAD_BROKEN   = 2, /**<@brief  broken radial dimension */
        VX_RAD_LARGE    = 3, /**<@brief  large radial dimension */
        VX_RAD_LEADER   = 4, /**<@brief  leader radial dimension */
        VX_RAD_DIAMETER = 5, /**<@brief  diametric dimension */
        VX_RAD_LINEAR   = 6  /**<@brief  linear diameter */
    } evxRadDimType;

    /**
    @brief radial or diametric dim data
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxRadDimData
    {
        evxRadDimType type; /**<@brief  radial or diametric type */

        svxPntOnEnt arcPnt; /**<@brief  point coordinate of point on entity (entPnt will be projected to the entity if entPnt is not on entity).
                                 (the curve idEnt can't be a line) */

        svxPntOnEnt brkPnt; /**<@brief  break point.
                                 if type = VX_RAD_BROKEN, the line through arcPnt and the arc center will be cut at 
                                 the intersection of above line and the line through brkPnt vertical to 
                                 above line 
                                 other type can be null */
        svxPntOnEnt txtPnt; /**<@brief  text point: specify the location the dimension text */
    } svxRadDimData;

    /**
    @brief Arc dimension dim data
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxDwgArcDimData
    {
        svxPntOnEnt ArcEnt; /**<@brief  get arc one entity */
        svxPntOnEnt txtPnt; /**<@brief  text point : specify the location of the dimension text.*/
    } svxDwgArcDimData;

    /**
    @brief Callout Elements
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxCalloutEmt
    {
        VX_CALLOUTEMT_INVALID       = 0x00000000, /**<@brief  all is not valid */
        VX_CALLOUTEMT_QUALITY       = 0x00000001, /**<@brief  Quality */
        VX_CALLOUTEMT_DIAMETER      = 0x00000002, /**<@brief  Diameter */
        VX_CALLOUTEMT_DIAMETER_D2   = 0x00000004, /**<@brief  Diameter(D2) */
        VX_CALLOUTEMT_DEPTH         = 0x00000008, /**<@brief  Depth */
        VX_CALLOUTEMT_DEPTH_H2      = 0x00000010, /**<@brief  Depth(H2) */
        VX_CALLOUTEMT_THREAD_DIA    = 0x00000020, /**<@brief  Thread Diameter */
        VX_CALLOUTEMT_THREAD_PITCH  = 0x00000040, /**<@brief  Thread Pitch */
        VX_CALLOUTEMT_THREAD_DEPTH  = 0x00000080, /**<@brief  Thread Depth */
        VX_CALLOUTEMT_ANGLE         = 0x00000100, /**<@brief  Angle */
        VX_CALLOUTEMT_CALLOUT_LABEL = 0x00000200, /**<@brief  Callout Label */
        VX_CALLOUTEMT_MULTIPLE_LINE = 0x00000400, /**<@brief  Multiple Lines */
        VX_CALLOUTEMT_SLOT_LENGTH   = 0x00000800, /**<@brief  Slot Length */
        VX_CALLOUTEMT_VALID         = 0xFFFFFFFF  /**<@brief  all is valid */
    } evxCalloutEmt;

    /**
    @brief Hole Callout
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxDwgHoleCallOutDim
    {
        int idView;               /**<@brief  id of View */
        int cntCrv;               /**<@brief  number of pCrvs or Pnts.
                                    the layout view where the holes are displayed true to their diameters. */
        int *pCrvs;               /**<@brief  list of Holes data.
                                    the holes anywhere on their perimeter diameter */
        svxPoint2 *pnts;          /**<@brief  list of text point. NULL to use default value.
                                   (the new variable when the ZW_API_VERSION is 2730) */
        int ignoreDup;            /**<@brief  Ignore duplicate hole callout, 1 is ignored,0 not, default value:0
                                   1 - if you want to exclude the marked holes of the same specification*/
        unsigned int iCalloutemt; /**<@brief  Callout Elements by evxCalloutEmt combined, default value:VX_CALLOUTEMT_VALID*/
    } svxDwgHoleCallOutDim;

    //====================================================================================================================
    /** @name Annotation Data */
    //====================================================================================================================
    /**
    @brief label coordinate dim data
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxLabelCoorDimData
    {
        char type;          /**<@brief  label coordinate type */
                            /**<@brief  1-Auto text placement */
                            /**<@brief  2-Pick text placement */
        svxPntOnEnt orgPnt; /**<@brief  origin point of label coordinate dimension*/

        int cntPnt;            /**<@brief  count of the point need to give the coordinates */
        svxPntOnEnt *pPnts;    /**<@brief  point to the coordinate point of dimension(length of list must equal to cntPnt)*/
        svxPntOnEnt *pTxtPnts; /**<@brief  point to the text point of dimension
                                 if needs customization, the length of list must equal to cntPnt, pTxtPnts[i].idEnt = -1, use default text point.
                                 NULL, use default text point to be text point*/

        char *text; /**<@brief  text(NULL or empty to be formatted as <C_X>,<C_Y>,<C_Z>, you can also custom text) */
    } svxLabelCoorDimData;

    /**
    @brief Label
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxDimLabel
    {
        int localPntCnt;        /**<@brief  localPnts list count */
        svxPntOnEnt *localPnts; /**<@brief  localPnts info: specify the location of the arrow*/
        int leadPntCnt;         /**<@brief  leadPnts list count */
        svxPntOnEnt *leadPnts;  /**<@brief  leadPnts info: locate where additional leader arrow will point*/
        char *text;             /**<@brief  text content to be shown */
    } svxDimLabel;

    /**
    @brief Balloon
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxDwgBalloonDim
    {
        evxDwgBalloonTextCondition condition;       /**<@brief  Text condition, default value:VX_DWG_CON_STANDARD */
        evxDwgBalloonTextSubCondition subCondition; /**<@brief  Text sub condition, default value:VX_DWG_SUB_CON_ID */
        char *text;                                 /**<@brief  text string, taking effect only when condition = VX_DWG_CON_USER_TEXT or subCondition = VX_DWG_SUB_CON_ID */
        int cntCrv;                                 /**<@brief  no. of Location data items */
        svxPntOnEnt *Points;                        /**<@brief  list of "cntCrv"  points */
        int cntlead;                                /**<@brief  no. of Lead pnts data items: to locate where additional leader arrows will point*/
        svxPntOnEnt *leadPoints;                    /**<@brief  list of "cntlead"  points */
    } svxDwgBalloonDim;

    /**
    @brief Type of instances in auto balloon
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxDwgAtBlnInsTyp
    {
        VX_ATBLNINS_IGNMULINS = 0, /**<@brief  ignore multiple instances */
        VX_ATBLNINS_MULLEAINS = 1, /**<@brief  multi-leader for multiple instances */
        VX_ATBLNINS_EACHINS   = 2  /**<@brief  one for each instances */
    } evxDwgAtBlnInsTyp;

    /**
    @brief Pattern type of auto balloon
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxDwgAtBlnPtnType
    {
        VX_ATBLNPAT_CONVEXHULL = 1, /**<@brief  convex hull around the layout view */
        VX_ATBLNPAT_SQUARE     = 2, /**<@brief  square around the layout view */
        VX_ATBLNPAT_CIRCULAR   = 3  /**<@brief  circular around the layout view */
    } evxDwgAtBlnPtnType;

    /**
    @brief Leader attachment of auto balloon
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxDwgAtBlnLeadAttach
    {
        VX_ATBLNLEAATT_EDAGES = 1, /**<@brief  attach to edges */
        VX_ATBLNLEAATT_FACES  = 2  /**<@brief  attach to face */
    } evxDwgAtBlnLeadAttach;

    /**
    @brief Skip sides of auto balloon
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxDwgAtBlnSkpSd
    {
        VX_ATBLNSKPSD_NONE   = 0, /**<@brief  skip none */
        VX_ATBLNSKPSD_LEFT   = 1, /**<@brief  skip left */
        VX_ATBLNSKPSD_TOP    = 2, /**<@brief  skip top */
        VX_ATBLNSKPSD_RIGHT  = 4, /**<@brief  skip right */
        VX_ATBLNSKPSD_BOTTOM = 8  /**<@brief  skip bottom */
    } evxDwgAtBlnSkpSd;

    /**
    @brief Arrangement of auto balloon
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxDwgAtBlnArrg
    {
        VX_ATBLNARR_NEAREST = 1, /**<@brief  simply located nearest to the component being labeled */
        VX_ATBLNARR_CW      = 2, /**<@brief  arranged in clockwise order */
        VX_ATBLNARR_CCW     = 3  /**<@brief  arranged in counter - clockwise order */
    } evxDwgAtBlnArrg;

    /**
    @brief Information of creating auto balloon
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxDwgAtBlnData
    {
        int viewIdCnt;   /**<@brief  count of view id */
        int *viewIdList; /**<@brief  list of view id */

        evxDwgBalloonTextCondition condition;       /**<@brief  Text condition, default value:VX_DWG_CON_STANDARD */
        evxDwgBalloonTextSubCondition subCondition; /**<@brief  Text sub condition, default value:VX_DWG_SUB_CON_ID */
        vxLongName text;                            /**<@brief  text string, 
                                                taking effect only when condition = VX_DWG_CON_USER_TEXT or subCondition = VX_DWG_SUB_CON_ID */

        evxDwgAtBlnInsTyp instOpt;        /**<@brief  instances type
                                        (note: VX_ATBLNINS_IGNMULINS as default) */
        evxDwgAtBlnPtnType ptnType;       /**<@brief  pattern type
                                        (note: VX_ATBLNPAT_CONVEXHULL as default)*/
        evxDwgAtBlnLeadAttach leadAttach; /**<@brief  leader attachment
                                        (note: VX_ATBLNLEAATT_EDAGES as default) */
        vxUint32 offSet;                  /**<@brief  specify the offset */
        evxDwgAtBlnSkpSd skipSides;       /**<@brief  prevent placing balloon labels along one side of the view.
                                        Be unusable when ptnType is VX_ATBLNPAT_CIRCULAR
                                        (note: VX_ATBLNSKPSD_NONE as default). */
        evxDwgAtBlnArrg arrangement;      /**<@brief  how the balloon labels will be arranged around the layout view. Used when have bom in sheeting,
                                        but must be initialized any time.
                                        (note: VX_ATBLNARR_NEAREST as default) */
        int KepItem;                      /**<@brief  flag of keeping item (0 no, else yes), Used when arrangement is not VX_ATBLLNARR_NEAREST.
                                        (note: 0 as default) */
        int ItemId;                       /**<@brief  index of the kept curve,used when KepItem is not 0. */
        int OnlyBom;                      /**<@brief  Whether the excluded components from BOM should be labeled. Used when have bom in sheeting.
                                        (0 no, else yes. Note: 1 as default) */
        int OnlyWithoutBln;               /**<@brief  Whether label the components which are not labeled in any other views to eliminate duplicate balloons. Used when OnlyBom is not 0.
                                        (0 no, else yes. Note: 0 as default) */
    } svxDwgAtBlnData;

    /**
    @brief pattern of stack balloons
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxDwgStkBlnPtn
    {
        VX_STKBLNPAT_HORRIGHT = 1, /**<@brief  horizontal right */
        VX_STKBLNPAT_HORLEFT,      /**<@brief  horizontal left */
        VX_STKBLNPAT_VERUP,        /**<@brief  vertical up */
        VX_STKBLNPAT_VERDOWN       /**<@brief  vertical down */
    } evxDwgStkBlnPtn;

    /**
    @brief information of creating stack balloons
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxDwgStkBlnData
    {
        int idBlnDim;              /**<@brief  index of main balloon. It must be index of V_DM_BALL(not stack balloon) */
        int entCnt;                /**<@brief  count of input entity corresponding to pIndexEntityList */
        int *pEntIdList;           /**<@brief  input entity index list. Index must be VV3REF/VNCURV/VICURV/
                                     VLINE2/VCIRCLE2/VARC2/V_DM_BALL(not stack balloon) */
        evxDwgStkBlnPtn stkBlnPtn; /**<@brief  pattern of stack balloons */
        char autoSort;             /**<@brief  flag of auto sort (0-no, else yes. Note:0 as default)
                                     if set to non-zero, the balloons can be stacked in turn. */
    } svxDwgStkBlnData;

    /**
    @brief Datum Control
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxDwgFtrCtrl
    {
        char *text;              /**<@brief  FCS text name */
        int cntCrv;              /**<@brief  no. of Location data items */
        svxPntOnEnt *Points;     /**<@brief  list of "cntCrv"  points */
        int cntlead;             /**<@brief  no. of Lead pts data items */
        svxPntOnEnt *leadPoints; /**<@brief  list of "cntlead"  points */
        int cntauxiLoc;          /**<@brief  no. of Auxiliary location data items */
        svxPntOnEnt *auxiPoints; /**<@brief  list of "cntauxiLoc"  points */
    } svxDwgFtrCtrl;

    /**
    @brief datum dim type
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxDatumDimType
    {
        VX_DATUM_NORMAL = 1, /**<@brief  normal datum feature symbol */
        VX_DATUM_ANSI   = 2, /**<@brief  based on ANSI(per 1982) */
    } evxDatumDimType;

    /**
    @brief datum dim data(drawing)
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxDatumDimData
    {
        evxDatumDimType type; /**<@brief  datum type.
                                 (note: VX_DATUM_NORMAL as default) */
        char *text;           /**<@brief  datum label name */
        svxPntOnEnt leadPnt;  /**<@brief  point coordinate of point on entity.
                                 if type = VX_DATUM_NORMAL, leadPnt is the txtPnt's projection on the entity
                                 if type = VX_DATUM_ANSI, leadPnt is a point on entity. */
        svxPntOnEnt txtPnt;   /**<@brief  point coordinate of text placement point.
                                 if type = VX_DATUM_NORMAL, txtPnt can be given arbitrarily.
                                 if type = VX_DATUM_ANSI, txtPnt is on the parellel or vertical line through leadPnt */
    } svxDatumDimData;

    /**
    @brief datum target dim type
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxDatumTargDimType
    {
        VX_DATUMT_CIRCLE    = 0, /**<@brief  datum target - Circle */
        VX_DATUMT_RECTANGLE = 1, /**<@brief  datum target - Rectangle */
        VX_DATUMT_LINE      = 2, /**<@brief  datum target - Line */
        VX_DATUMT_POINT     = 3, /**<@brief  datum target - Point */
    } evxDatumTargDimType;

    /**
    @brief datum target dim data
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxDatumTargDimData
    {
        evxDatumTargDimType type; /**<@brief  datum target type.
                                 (Note: VX_DATUMT_POINT as default)*/

        svxPntOnEnt pnt;     /**<@brief  point coordinate of point on entity. */
        svxPntOnEnt textPnt; /**<@brief  text point */
        svxPntOnEnt secPnt;  /**<@brief  2nd point (if type = VX_DATUMT_POINT, secPnt is 2nd point of a line 
                                 other type can be ignored) */

        double diameter;   /**<@brief  diameter (just for type = VX_DATUMT_RECTANGLE, other type can be ignored).
                                          if type = VX_DATUMT_RECTANGLE, it is diameter of the circle. */
        double width;      /**<@brief  width (just for type = VX_DATUMT_LINE, other type can be ignored).
                                          if type = VX_DATUMT_LINE, it is width of the rectangle */
        double height;     /**<@brief  height (just for type = VX_DATUMT_LINE, other type can be ignored).
                                          if type = VX_DATUMT_LINE, it is height of the rectangle */
        char *text;        /**<@brief  datum text */
        char *text2;       /**<@brief  datum text2 (text2 is valid when text is not empty) */
        char *text3;       /**<@brief  datum text3 (text3 is valid when text2 is not empty) */
        int iAreaSizeText; /**<@brief  Area size text (0-Area size, 1-User text, 0 as default):
                                 to determine how the upper text of the datum target is generated*/
        char *userText;    /**<@brief  user text (userText is valid when iAreaSizeText equals to 1):
                                 defines the text that is displayed instead of the actual area information*/
    } svxDatumTargDimData;

    //====================================================================================================================
    /** @name Symbol Data */
    //====================================================================================================================
    /**
    @brief Center Mark Settings
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxCenterDim
    {
        double cmSize;   /**<@brief  center line/mark size (short dash), default value:4.254534*/
        double breakLen; /**<@brief  extension lines break length (gap), default value:1.5*/
        double overRun;  /**<@brief  extension lines overrun, default value:3.06324*/
        double scaleFac; /**<@brief  overall scale factor, default value:1*/
    } svxCenterDim;

    /**
    @brief center mark type
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxCentDimType
    {
        VX_DM_CENMARK = 1, /**<@brief  Center Mark: create a center mark at an arc or circle. */
        VX_DM_CENLINE,     /**<@brief  Center Mark Circle: place a centerline through a circular pattern such as bolt holes. */
        VX_DM_CENDLINE     /**<@brief  Center Line: create a centerline mark between lines, arcs or circle. */
    } evxCentDimType;

    /**
    @brief Center Mark
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxCenterMark
    {
        int idEntity;            /**<@brief  entity id */
        svxPoint zEntPnt;        /**<@brief  critical point of the entity */
        char useRotPnt;          /**<@brief  whether to rotate the center line/mark toward a selected point.(0: no, 1: yes) */
        svxPntOnEnt zRotPnt;     /**<@brief  rotation point, just for cmType = VX_DM_CENMARK */
        evxCentDimType cmType;   /**<@brief  center mark type, default value:VX_DM_CENLINE */
        svxCenterDim zCenterDim; /**<@brief  option param: center dimension attribute */
        int slotType;            /**<@brief  Slot center mark type, valid when entity is a hole, default value:1 */
                                 /**<@brief  1: Slot centers; */
                                 /**<@brief  2: Slot ends */
    } svxCenterMark;

    /**
    @brief center mark circle dim data
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxCenMarkCirDimData
    {
        int iCntCens;       /**<@brief  the count of the center marks */
        svxPntOnEnt *pCens; /**<@brief  point to the point for center marks(the length of list must equal to iCntCens) */

        int iflg;           /**<@brief  optional open/close flag
                                 0-Arc(open), 1-Circle(close)
                                 (note: 1 as default) */
        char flgCenter;     /**<@brief  flag to use "center" (0 as default)*/
        svxPntOnEnt center; /**<@brief  arc center or circle center(if flgCenter = 1, the value is valid)
                                 if iflg = 0, the center is the arc center
                                 if iflg = 1, the center is the circle center */
    } svxCenMarkCirDimData;

    /**
    @brief centerline type
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxCenterLineType
    {
        VX_CL_BY_TWO_LINES = 1, /**<@brief  draw by two lines(Based to curve) */
        VX_CL_BY_TWO_POINTS,    /**<@brief  draw by two points(Based on pick point) */
    } evxCenterLineType;

    /**
    @brief Center Line
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxCenterLine
    {
        evxCenterLineType iDimType; /**<@brief  start point.
                                     if type = VX_CL_BY_TWO_LINES, the start point is regarded as the entity line of the point,
                                     if type = VX_CL_BY_TWO_POINTS, it is the start point of centerline */
        svxPntOnEnt zPntStart;      /**<@brief  end point.
                                     if type = VX_CL_BY_TWO_LINES, the end point is regarded as the entity line of the point,
                                     if type = VX_CL_BY_TWO_POINTS, it is the end point of centerline */
        svxPntOnEnt zPntEnd;        /**<@brief  end point */
        svxCenterDim zCenterDim;    /**<@brief  option param: center dimension attribute */
    } svxCenterLine;

    /**
    @brief finish symbol of weld symbol
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxWeldFinishSym
    {
        VX_WELD_FINISH_NONE = 1,    /**<@brief  none */
        VX_WELD_FINISH_CHIPPING,    /**<@brief  chipping */
        VX_WELD_FINISH_GRINDING,    /**<@brief  grinding */
        VX_WELD_FINISH_HAMMERING,   /**<@brief  hammering */
        VX_WELD_FINISH_MACHINING,   /**<@brief  machining */
        VX_WELD_FINISH_ROLLING,     /**<@brief  rolling */
        VX_WELD_FINISH_UNSPECIFIED, /**<@brief  unspecified */
    } evxWeldFinishSym;

    /**
    @brief contour symbol of weld symbol
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxWeldContourSym
    {
        VX_WELD_COUNTOUR_NONE = 1,        /**<@brief  none */
        VX_WELD_COUNTOUR_FLAT,            /**<@brief  flat */
        VX_WELD_COUNTOUR_CONVEX,          /**<@brief  convex */
        VX_WELD_COUNTOUR_CONCAVE,         /**<@brief  concave */
        VX_WELD_COUNTOUR_BLEND_TOES,      /**<@brief  blended toes */
        VX_WELD_COUNTOUR_STRIP_PERMANENT, /**<@brief  backing strip permanent */
        VX_WELD_COUNTOUR_STRIP_REMOVABLE, /**<@brief  backing strip removable */
    } evxWeldContourSym;

    /**
    @brief Weld data
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxSymWeld
    {
        evxWeldFinishSym finishSymUp;    /**<@brief  finish symbol (other side) */
        evxWeldContourSym contourSymUp;  /**<@brief  contour symbol (other side) */
        int lineFlg;                     /**<@brief  line flag 0:plain, 1:below, 2:above */
        int stagger;                     /**<@brief  stagger (0: suppress; 1: enable) */
        int filletSecUp;                 /**<@brief  2nd fillet (other side) (0: suppress; 1: enable) */
        int weldSymUp;                   /**<@brief  weld symbol (other side) (1 ~ 35) */
        int fieldFlg;                    /**<@brief  field flag (0: suppress; 1: enable) */
        int aroundCir;                   /**<@brief  all round circle (0 ~ 2) */
        int tail;                        /**<@brief  tail (0 ~ 2) */
        int weldSymDwn;                  /**<@brief  weld symbol (arrow side) (1 ~ 35) */
        int filletSecDwn;                /**<@brief  2nd fillet (arrow side) (0: suppress; 1: enable) */
        evxWeldContourSym contourSymDwn; /**<@brief  contour symbol (arrow side) */
        evxWeldFinishSym finishSymDwn;   /**<@brief  finish symbol (arrow side) */
        int inWeldTbl;                   /**<@brief  include in weld table flag*/
        char GrooveAngUp[33];            /**<@brief  groove angle (arrow side) */
        char filleSecSzUp[33];           /**<@brief  2nd fillet size (other side) */
        char filletSecLenUp[33];         /**<@brief  2nd fillet length (other side) */
        char depthPrepUp[33];            /**<@brief  depth of preparation, size or strength,
                                                effective throat, or groove weld size */
        char weldLenPitchUp[33];         /**<@brief  length and pitch of weld */
        char tailRef[65];                /**<@brief  tail reference */
        char depthPrepDwn[33];           /**<@brief  depth of preparation, size or strength,
                                                effective throat, or groove weld size */
        char weldLenPitchDwn[33];        /**<@brief  length and pitch of weld */
        char filletSecSzDwn[33];         /**<@brief  2nd fillet size (arrow side) */
        char filletSecLenDwn[33];        /**<@brief  2nd fillet length (arrow side) */
        char weldRoot[33];               /**<@brief  root opening/depth of filling/number of weld */
        char grooveAngDwn[33];           /**<@brief  groove angle (other side) */
        char weldOtherRoot[33];          /**<@brief  root opening/depth of filling/number of weld (other side) */
        double gapSpacing;               /**<@brief  ratio for symbol gap */
        int useLocPoint;                 /**<@brief  whether to use location point setting, 0 to use default point */
        svxPoint2 locPoint;              /**<@brief  the coordinate of location point */
        int numJogs;                     /**<@brief  number of jog points */
        svxPoint2 *jogPoints;            /**<@brief  list of coordinate of jog points */
        int numLeaders;                  /**<@brief  number of leader points */
        svxPoint2 *leaderPoints;         /**<@brief  list of coordinate of leader points */
    } svxSymWeld;

    /**
    @brief symbol type of surface roughness
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxSymSurf
    {
        VX_SYMSURF_BAS = 0, /**<@brief  basic */
        VX_SYMSURF_MRR,     /**<@brief  material removal required */
        VX_SYMSURF_MRP,     /**<@brief  material removal prohibited */
        VX_SYMSURF_JIS1,    /**<@brief  JIS surface texture 1 */
        VX_SYMSURF_JIS2,    /**<@brief  JIS surface texture 2 */
        VX_SYMSURF_JIS3,    /**<@brief  JIS surface texture 3 */
        VX_SYMSURF_JIS4,    /**<@brief  JIS surface texture 4 */
        VX_SYMSURF_JISNM    /**<@brief  JIS no machining */
    } evxSymSurf;


    /**
    @brief pattern symbol of surface roughness
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxSurfPtnSym
    {
        VX_SURF_PTNSYM_NONE = 0,      /**<@brief  none */
        VX_SURF_PTNSYM_RADIAL,        /**<@brief  radial */
        VX_SURF_PTNSYM_PERPENDICULAR, /**<@brief  perpendicular */
        VX_SURF_PTNSYM_ANGULAR,       /**<@brief  angular */
        VX_SURF_PTNSYM_MULTI_DIR,     /**<@brief  multi-directional */
        VX_SURF_PTNSYM_CIRCULAR,      /**<@brief  circular */
        VX_SURF_PTNSYM_PARALLEL,      /**<@brief  parallel */
        VX_SURF_PTNSYM_PARTICULATE    /**<@brief  particulate */
    } evxSurfPtnSym;

    /**
    @brief surface finish data
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxSymSurf
    {
        evxSymSurf symTyp;   /**<@brief  symbol type */
        evxSurfPtnSym lay;   /**<@brief  surface pattern symbol */
        int grinding;        /**<@brief  grinding */
        char maxR[65];       /**<@brief  max roughness average (or =NULL) */
        char minR[65];       /**<@brief  min roughness average (or =NULL) */
        char procMeth[65];   /**<@brief  processing method/treatment (or =NULL) */
        char sampR[65];      /**<@brief  sampling length/roughness cutout (or =NULL) */
        char machAllow[65];  /**<@brief  machining allowance (or =NULL) */
        char R[65];          /**<@brief  Rz, roughness value (or =NULL) */
        char otherR[65];     /**<@brief  other roughness value/spacing (or =NULL) */
        char optStr[65];     /**<@brief  third row optional string (or =NULL) */
        int prepFlag;        /**<@brief  perpendicular flag (0-no, 1-perpendicular, 2-reverse) */
        double rotation;     /**<@brief  rotation angle(degree), only used when prepFlag = 0 */
        int useLeadPnt;      /**<@brief  whether to use leader point */
        svxPoint2 leadPoint; /**<@brief  coordinate of the leader point, only used when useleadPnt = 1 */
    } svxSymSurf;

    /**
    @brief image data
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxSymImg
    {
        /*  required inputs */
        vxPath path;      /**<@brief  image path or user define string */
        int firstPtType;  /**<@brief  type of 1st input point (0 corner, 1 center) */
        svxPoint2 pts[2]; /**<@brief  2 input points depend on "type" */
        double width;     /**<@brief  width */
        double height;    /**<@brief  height */
        double angle;     /**<@brief  rotation angle(degree) */
        double opaque;    /**<@brief  opaque factor */
        int flip;         /**<@brief  flip flag (0-none, 1-with, 2-with y ) */
        int locked;       /**<@brief  1-lock aspect ratio,0 not */
    } svxSymImg;

    /**
    @brief drawing intersection symbol data
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxDwgIsectSym
    {
        svxPntOnEnt fistEdge;   /**<@brief  point of the first line or arc, create intersection symbol between 
                                        two entity */
        svxPntOnEnt secondEdge; /**<@brief  point of the second line or arc*/
    } svxDwgIsectSym;

    /**
    @brief drawing sheet hole mark method
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxDwgHoleMarkType
    {
        VX_DWG_HOLE_MARK_AUTO,   /**<@brief  auto pick */
        VX_DWG_HOLE_MARK_MANUAL, /**<@brief  manual pick*/
    } evxDwgHoleMarkType;

    /**
    @brief drawing sheet hole mark pattern method
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxDwgHoleMarkPtn
    {
        VX_DWG_HOLE_MARK_UP_LEFT_4,      /**<@brief  up-left 1/4 */
        VX_DWG_HOLE_MARK_UP_RIGHT_4,     /**<@brief  up-right 1/4 */
        VX_DWG_HOLE_MARK_DOWN_LEFT_4,    /**<@brief  down-left 1/4 */
        VX_DWG_HOLE_MARK_DOWN_RIGHT_4,   /**<@brief  down-right 1/4 */
        VX_DWG_HOLE_MARK_LEFT_BEVEL_4,   /**<@brief  left-bevel 1/4 */
        VX_DWG_HOLE_MARK_RIGHT_BEVEL_4,  /**<@brief  right-bevel 1/4 */
        VX_DWG_HOLE_MARK_UP_LEFT_12,     /**<@brief  up-left 1/12 */
        VX_DWG_HOLE_MARK_UP_RIGHT_12,    /**<@brief  up-right 1/12 */
        VX_DWG_HOLE_MARK_DOWN_LEFT_12,   /**<@brief  down-left 1/12 */
        VX_DWG_HOLE_MARK_DOWN_RIGHT_12,  /**<@brief  down-right 1/12 */
        VX_DWG_HOLE_MARK_LEFT_BEVEL_12,  /**<@brief  left-bevel 1/12 */
        VX_DWG_HOLE_MARK_RIGHT_BEVEL_12, /**<@brief  right-bevel 1/12 */
    } evxDwgHoleMarkPtn;

    /**
    @brief drawing sheet hole mark data
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxDwgHoleMark
    {
        evxDwgHoleMarkType type;   /**<@brief  hole mark option */
        int numCir;                /**<@brief  number of circle entities need to be marked */
        int *idCirs;               /**<@brief  list id of circle entities need to be marked
                                            if type = VX_DWG_HOLE_MARK_DOWN_LEFT_4, the circle is given by user
                                            other type can be null */
        int idView;                /**<@brief  id of view
                                            if type = VX_DWG_HOLE_MARK_UP_RIGHT_4, auto mark the hole of the view
                                            other type can be null */
        int backface;              /**<@brief  whether to mark backfacing holes(0 = no, 1 = yes).default:0
                                            if type = VX_DWG_HOLE_MARK_UP_RIGHT_4, the option is available */
        int hidden;                /**<@brief  whether to mark hidden holes(0 = no, 1 = yes).default:0
                                            if type = VX_DWG_HOLE_MARK_UP_RIGHT_4, the option is available */
        int boolean;               /**<@brief  whether to mark boolean holes(0 = no, 1 = yes).default:0
                                            if type = VX_DWG_HOLE_MARK_UP_RIGHT_4, the option is available*/
        int sameD;                 /**<@brief  whether to filter same diameter(0 = no, 1 = yes).default:0
                                            if type = VX_DWG_HOLE_MARK_DOWN_LEFT_4, the option is available*/
        evxDwgHoleMarkPtn pattern; /**<@brief  pattern of manual hole mark(if type = 2, the option is available).default:VX_DWG_HOLE_MARK_UP_LEFT_4 */
    } svxDwgHoleMark;

    //====================================================================================================================
    /** @name Drawing Data */
    //====================================================================================================================

    /**
    @brief hatch type
    @ingroup zwapi_cmd_dwg_data
    */
    typedef enum evxHatchType
    {
        VX_HATCH_CUSTOM = -1, /**<@brief  custom hatch style */
        VX_HATCH_STANDARD,    /**<@brief  from standard */
        VX_HATCH_ANSI,        /**<@brief  hatch style (ANSI) */
        VX_HATCH_ISO,         /**<@brief  hatch style (ISO) */
        VX_HATCH_DIN,         /**<@brief  hatch style (DIN) */
        VX_HATCH_JIS,         /**<@brief  hatch style (JIS) */
        VX_HATCH_GB,          /**<@brief  hatch style (GB) */
    } evxHatchType;

    /**
    @brief hatch attributes
    @ingroup zwapi_cmd_dwg_data
    */
    typedef struct svxHatchAttr
    {
        evxHatchType type;       /**<@brief  hatch type
                                           default: VX_HATCH_STANDARD */
        evxHatchPtnType pattern; /**<@brief  hatch pattern method
                                           default: VX_HATCH_PATTERN_ANSI31 */
        double angle;            /**<@brief  angle attribute
                                           default: 0.0 */
        double space;            /**<@brief  spacing attribute
                                           default: 3.175 */
        svxPoint2 origin;        /**<@brief  origin point
                                           default: {0.0,0.0} */
        evxColor color;          /**<@brief  color attribute
                                           default: VX_COLOR_BLACK */
        evxLineWidth width;      /**<@brief  line width
                                           default: VX_WIDTH_018 */
    } svxHatchAttr;

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_DWG_CMD_DATA_H */
