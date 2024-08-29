/**
@file zwapi_part_data.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the functions
of Part objects.
*/
/**
@defgroup zwapi_part_data Part Data
@ingroup PartObjectsModel
@brief
@details THE MODULE FOR THE ZW3D Data Types and Structures of the functions
of Part objects.
*/

#pragma once
#ifndef zwapi_part_data_H /* this ifndef surrounds entire header */
#define zwapi_part_data_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Feature Query Data */
    //====================================================================================================================
    /**
    @brief regen status of feature
    @ingroup zwapi_part_data
    */
    typedef enum evxFtrRegenStatus
    {
        VX_FTR_REGEN_DEFAULT,          /**<@brief  default value */
        VX_FTR_REGEN_LINK_LOST,        /**<@brief  weak association data loss. */
        VX_FTR_REGEN_PARTIAL_INP_LOST, /**<@brief  some strong correlation input data is lost. */
        VX_FTR_REGEN_VAR_LOST,         /**<@brief  variable data loss. */
        VX_FTR_REGEN_ENT_LOST,         /**<@brief  weak association entity reference data is lost. */
        VX_FTR_REGEN_OVER_CONSTRAINT,  /**<@brief  over constrain(mainly the constraints in the sketch) */
        VX_FTR_REGEN_UNDER_CONSTRAINT, /**<@brief  under constrain(mainly the constraints in the sketch) */
    } evxFtrRegenStatus;

    //====================================================================================================================
    /** @name Part Physical Attribute Data */
    //====================================================================================================================
    /**
    @brief part physical attributes  data
    @ingroup zwapi_part_data
    */
    typedef struct svxPartCalcAttrData
    {
        double Length;     /**<@brief  length of part */
        double Width;      /**<@brief  width of part */
        double Height;     /**<@brief  hight of part */
        double Volume;     /**<@brief  volume of part */
        double Area;       /**<@brief  surface area of part */
        double Mass;       /**<@brief  mass of part*/
        double Density;    /**<@brief  density of part(kg/mm3) */
        svxPoint Centroid; /**<@brief  center of gravity of part */
    } svxPartCalcAttrData;

    /**
    @brief Part material physical attributes
    @ingroup zwapi_part_data
    */
    typedef struct svxPartMaterial
    {
        /*  At present,there is only on property of material density. */
        double density; /**<@brief  material density(kg/m3) */
    } svxPartMaterial;

    /**
    @brief Locking state of attribute item
    @ingroup zwapi_part_data
    */
    typedef enum evxAtItemLockStatus
    {
        VX_AT_ITEM_UNLOCKED = 0, /**<@brief  attribute item unlocked */
        VX_AT_ITEM_LOCKED,       /**<@brief  lock attribute item and value */
        VX_AT_ITEM_LIMITED,      /**<@brief  lock attribute item but not value */
    } evxAtItemLockStatus;

    //====================================================================================================================
    /** @name Block Data */
    //====================================================================================================================
    /**
    @brief 3D STL facets
    @ingroup zwapi_part_data
    */
    typedef struct svxSTL
    {
        char *name;          /**<@brief  name                                             */
        int nFacet;          /**<@brief  number of facet                                  */
        svxTriangle *facets; /**<@brief  Array of STLfacet                                */
        /**<@brief  When users create triangular patches through interface cvxPartFacetsBySTL,  
           They need to ensure that the incoming normal matches the normal calculated  
           through the tree points of the triangle.  
           If the normal contradicts each other, the calculated normal will be used.  
           Calculate the normal of the triangle according to the order of incoming points.  
           The three points should be transmitted counterclockwise.  
           @verbatim
           A
           | \
           B -C
           @endverbatim
           The value of variable facets[i].Pnt should be passed in the order of  ABC or BCA or CAB,not CBA. */
        double dTol; /**<@brief  Tolerance to use when extracting facets          */
    } svxSTL;

    /**
    @brief 3D Block Type
    @ingroup zwapi_part_data
    */
    typedef enum evxBlockType
    {
        VX_BLOCK_UNDEFINED = 0, /**<@brief  undefined 3D block type */
        VX_BLOCK_FACETS    = 1, /**<@brief  block of 3D triangular facets */
        VX_BLOCK_POINTS    = 2  /**<@brief  block of 3D points (i.e. point cloud) */
    } evxBlockType;

    /**
    @brief tolerance type of refine facets
    @ingroup zwapi_part_data
    */
    typedef enum evxRefineFacetsTolType
    {
        VX_FACETS_TOL_PIXEL,    /**<@brief pixel */
        VX_FACETS_TOL_DISTANCE, /**<@brief distance */
        VX_FACETS_TOL_ANGLE,    /**<@brief angle */
    } evxRefineFacetsTolType;

    /**
    @brief refine facets data
    @ingroup zwapi_part_data
    */
    typedef struct svxRefineFacets
    {
        int idFace;                  /**<@brief face id */
        evxRefineFacetsTolType type; /**<@brief tolerance type.default:VX_FACETS_TOL_PIXEL */

        double edgeTol;  /**<@brief edge tolerance.min=0.001,default:1. apply it if type=VX_FACETS_TOL_DISTANCE or VX_FACETS_TOL_ANGLE. */
        double facetTol; /**<@brief facet tolerance.min=0.001.default:1. apply it if type=VX_FACETS_TOL_DISTANCE. */
        double angleTol; /**<@brief angle tolerance.min=1,max=30,default:5. apply it if type=VX_FACETS_TOL_ANGLE. */
    } svxRefineFacets;

    //====================================================================================================================
    /** @name Part Config Info Data */
    //====================================================================================================================
    /**
    @brief Hole type
    @ingroup zwapi_part_data
    */
    typedef enum evxCfgThreadCmd
    {
        VX_NO_CMD      = 0, /**<@brief  null */
        VX_FTHOLEMAIN  = 1, /**<@brief  Create holes */
        VX_FTTWKHOLE   = 2, /**<@brief  Change the parameters of a hole without a history regen whether or not the hole is a native ZW3D feature. */
        VX_FTASSEMHOLE = 3, /**<@brief  Create hole in assembly */
        VX_FTHOLEASGN  = 4, /**<@brief  puts a feature into the active part's history to identify a hole from selected geometry */
        VX_CDHOLEPLUG  = 5, /**<@brief  Create new holes centered in existing holes */
        VX_CDTHRDADD   = 6, /**<@brief  Add multiple/single thread attribute to cylindrical face */
    } evxCfgThreadCmd;

    /**
    @brief conversion factor
    @ingroup zwapi_part_data
    */
    typedef struct svxCf
    {
        double value;     /**<@brief  value */
        double offset;    /**<@brief  offset value */
        vxName name;      /**<@brief  name (null-terminated string) */
        evxNumType klass; /**<@brief  class */
        unsigned char id; /**<@brief  unique id ( see evxUnitType , evxAngUnitType and evxMassUnitType) */
        char isEdit;      /**<@brief  1 if it is the editing unit, else 0 */
    } svxCf;

    /**
    @brief config table infos
    @ingroup zwapi_part_data
    */
    typedef struct svxPartCfgInfo
    {
        vxName ConfigName; /**<@brief  configuration name */
        int CfgIdx;        /**<@brief  configuration id */
        int ConfigId;      /**<@brief  the row number of the table(0,1,...) */
        svxColor colorval; /**<@brief  color of attributes or config table*/
        int fCfged;        /**<@brief  1 if colorval exist,else 0 */

        struct svxRegenObjs /**<@brief regen object infos */
        {
            int idx;        /**<@brief  index of regenerate object */
            int suppressed; /**<@brief  -1 if undefined.0 is unsuppressed, 1 is suppressed. */
            vxName expr;    /**<@brief  the expression of condition suppressed*/
        } *RegenObjs;
        int CntRO; /**<@brief  numbers of "RegenObjs" */

        struct svxFtrDimensions /**<@brief feature dimension infos */
        {
            svxUid uid;   /**<@brief  feature uid of the dimension */
            int DataId;   /**<@brief  dimension's data id in the feature */
            int DimIdx;   /**<@brief  index of dimension */
            int fAssm;    /**<@brief  1,the dimension should be in assembly tree*/
            vxName value; /**<@brief  value of the dimension */
            svxCf unit;   /**<@brief  unit for value */
            int ftr;      /**<@brief  auxiliary data */
        } *FtrDim;
        int CntFD; /**<@brief  numbers of "FtrDim" */

        struct svxProfDimensions /**<@brief profile dimension infos */
        {
            int DimIdx;   /**<@brief  index of dimension */
            vxName value; /**<@brief  value of dimension */
            svxCf unit;   /**<@brief  unit for value */
        } *ProfDim;
        int CntPD; /**<@brief  numbers of "ProfDim" */

        struct svxVariables /**<@brief  equation manager infos */
        {
            int EqIdx;      /**<@brief  index of Variables */
            char type;      /**<@brief  type of Variables */
            vxVarExp value; /**<@brief  value of Variables */
            svxCf unit;     /**<@brief  unit for value */
        } *var;
        int CntVar; /**<@brief  numbers of "var" */

        struct svxAttributes /**<@brief attribute properties infos */
        {
            int AttrIdx;        /**<@brief  index of Attributes */
            evxAtItemId itemId; /**<@brief  The standard id of the part attribute item. */
            char type;          /**<@brief  type of Attributes */
            char SubType;       /**<@brief  subtype of Attributes */
            double dvalue;      /**<@brief  0 if undefined */
            vxLongName expr;    /**<@brief  the expression of condition suppressed*/
            int fCfged;         /**<@brief  0 if undefined */
            int fUserDefined;   /**<@brief  1 if the value is user defined, else 0, only used for calculated attributes */
            svxCf unit;         /**<@brief  unit for value */
        } *attr;
        int CntAttr; /**<@brief  numbers of "attr" */

        struct svxComponents /**<@brief component infos */
        {
            int CompIdx;     /**<@brief  index of component */
            int suppressed;  /**<@brief  -1 if undefined.0 is unsuppressed, 1 is suppressed. */
            vxName expr;     /**<@brief  the expression of condition suppressed*/
            int PartStateId; /**<@brief  -1 if undefined */
            vxName CfgName;  /**<@brief  the CfgName, alway is empty*/
            svxColor color;  /**<@brief  color of components */
            int fCfged;      /**<@brief  1 if color exist,else 0 */
        } *comp;
        int CntComp; /**<@brief  numbers of "comp" */

        struct svxThreads /**<@brief thread infos */
        {
            svxUid uid;           /**<@brief  feature uid of the dimension */
            int FtrIdx;           /**<@brief  index of feature */
            evxCfgThreadCmd fCmd; /**<@brief  1: FTHOLEMAIN, 2: FTTWKHOLE, 3: FTASSEMHOLE, 4: FTHOLEASGN, 5: CDHOLEPLUG, 6:CDTHRDADD */
            vxName threadType;    /**<@brief  thread Type */
            vxName threadsize;    /**<@brief  thread size */
            vxName threadDia;     /**<@brief  thread Diameter */
            vxName pitch;         /**<@brief  pitch */
            vxName threadUnit;    /**<@brief  Thread Unit */
        } *threads;
        int CntThreads; /**<@brief  numbers of "threads" */

        struct svxThreadDeps /**<@brief thread depth infos */
        {
            svxUid uid;           /**<@brief  feature uid of the dimension */
            int FtrIdx;           /**<@brief  index of feature */
            evxCfgThreadCmd fCmd; /**<@brief  1: FTHOLEMAIN, 2: FTTWKHOLE, 3: FTASSEMHOLE, 4: FTHOLEASGN, 5: CDHOLEPLUG, 6:CDTHRDADD */
            int deptype;          /**<@brief  depth type of thread */
            vxName depth;         /**<@brief   depth of thread */
        } *ThreadDeps;
        int CntTD; /**<@brief  numbers of "ThreadDeps" */

        struct svxAligns /**<@brief constraint of component or assembly infos */
        {
            int AlignIdx;   /**<@brief  index of component */
            int suppressed; /**<@brief  -1 if undefined.0 is unsuppressed, 1 is suppressed. */
            vxName expr;    /**<@brief  expression of align */
        } *align;
        int CntAlign; /**<@brief  numbers of "align" */

        struct svxAlignValue /**<@brief constraint value infos */
        {
            int AlignIdx;    /**<@brief  index of component */
            svxUid uid;      /**<@brief  feature uid of the dimension */
            int DataId;      /**<@brief  the value's data id in the feature */
            vxName ValValue; /**<@brief  value of align */
            svxCf unit;      /**<@brief  unit for value */
        } *AlignValue;
        int CntAV; /**<@brief  numbers of "AlignValue" */

        struct svxFtrVdataVal /**<@brief feature's vdata infos */
        {
            svxUid uid;   /**<@brief  feature uid of the vdata */
            int DataId;   /**<@brief  data id in the feature */
            int idx_ftr;  /**<@brief  index of feature */
            int fAssm;    /**<@brief  1, the feature is a assembly feature*/
            vxName value; /**<@brief  value of feature */
            int ftr;      /**<@brief  auxiliary data */
            svxCf unit;   /**<@brief  unit for value */
        } *FtrVdataValue;
        int CntFVV; /**<@brief  numbers of "FtrVdataValue" */

        /* outside defined infos */
        struct svxOutDefVal /**<@brief variables preceded by "*" are not used to drive the seed part */
        {
            vxName key;   /**<@brief  key of outside defined value */
            vxName value; /**<@brief  value of outside defined value */
        } *OutDefVal;
        int CntODV; /**<@brief  numbers of "OutDefVal" */

        int *RegenObjsFailed; /**<@brief list of regen object failed */
        int CntROF;           /**<@brief  numbers of "RegenObjsFailed" */
    } svxPartCfgInfo;

    /**
    @brief configuration item method
    @ingroup zwapi_part_data
    */
    typedef enum evxCfgTblMethod
    {
        VX_CFGTBL_MEHTOD_FTR,         /**<@brief  feature */
        VX_CFGTBL_MEHTOD_FTRDIM,      /**<@brief  feature dimension */
        VX_CFGTBL_MEHTOD_FTRVDATA,    /**<@brief  feature vdata */
        VX_CFGTBL_MEHTOD_PROFDIM,     /**<@brief  profile dimension */
        VX_CFGTBL_MEHTOD_VAR,         /**<@brief  variable */
        VX_CFGTBL_MEHTOD_ATTR,        /**<@brief  attribute */
        VX_CFGTBL_MEHTOD_PARTCOLOR,   /**<@brief  part color */
        VX_CFGTBL_MEHTOD_THREAD,      /**<@brief  thread */
        VX_CFGTBL_MEHTOD_THREADDEP,   /**<@brief  thread depth */
        VX_CFGTBL_MEHTOD_COMPPARTCFG, /**<@brief  part config of the component */
        VX_CFGTBL_MEHTOD_COMPSUPP,    /**<@brief  suppress of component */
        VX_CFGTBL_MEHTOD_COMPCOLOR,   /**<@brief  component color */
        VX_CFGTBL_MEHTOD_ALIGNSUPP,   /**<@brief  align suppress */
        VX_CFGTBL_MEHTOD_ALIGNVALUE,  /**<@brief  align value */
    } evxCfgTblMethod;

    /**
    @brief PMI entity type
    @ingroup zwapi_part_data
    */
    typedef enum evxPMIEntType
    {
        VX_PMI_ALL     = 0x0000, /**<@brief  all type */
        VX_PMI_DIM     = 0x0001, /**<@brief  dimension */
        VX_PMI_NOTE    = 0x0002, /**<@brief  note */
        VX_PMI_DTMF    = 0x0004, /**<@brief  datum feature */
        VX_PMI_DTMT    = 0x0008, /**<@brief  datum target */
        VX_PMI_FCS     = 0x0010, /**<@brief  feature control symbol */
        VX_PMI_CLCM    = 0x0020, /**<@brief  center mark and centerline */
        VX_PMI_SYMSRF  = 0x0040, /**<@brief  symbol surface */
        VX_PMI_SYMWELD = 0x0080, /**<@brief  symbol WELD */
        VX_PMI_TABLE   = 0x0100, /**<@brief  PMI table */
        VX_PMI_SYMBLK  = 0x0200  /**<@brief  symbol block */
    } evxPMIEntType;

    //====================================================================================================================
    /** @name Sheet Metal Attribute Data */
    //====================================================================================================================
    /**
    @brief Sheet Metal surface type
    @ingroup zwapi_part_data
    */
    typedef enum evxSmdSurfaceType
    {
        VX_SMD_SURF_NONE,             /**<@brief  undefined */
        VX_SMD_SURF_OTHER,            /**<@brief  other type */
        VX_SMD_SURF_SIDE,             /**<@brief  side of sheet metal */
        VX_SMD_SURF_FLANGE_STAT,      /**<@brief  flange face on one side of stationary face */
        VX_SMD_SURF_FLANGE_STAT_PAIR, /**<@brief  the flange face of the opposite side of the stationary face */
    } evxSmdSurfaceType;

    //====================================================================================================================
    /** @name Edge Display Data */
    //====================================================================================================================
    /**
    @brief edge display data
    @ingroup zwapi_part_data
    */
    typedef struct svxEdgeDispData
    {
        int wireCnt;              /**<@brief  count of wireDispData */
        svxPoint *wireDispData;   /**<@brief  display data of wireframe */
        int shadeCnt1;            /**<@brief  count of shadeDispData1 */
        svxPoint *shadeDispData1; /**<@brief  display data1 of shade.
                                This is the display data of one of the two faces adjacent to the edge on the edge. */
        int shadeCnt2;            /**<@brief  count of shadeDispData2 */
        svxPoint *shadeDispData2; /**<@brief  display data2 of shade.
                                This is the display data of the other of the two faces adjacent to the edge on the edge. */
    } svxEdgeDispData;

    //====================================================================================================================
    /** @name Datum Data */
    //====================================================================================================================
    /**
    @brief type of plane
    @ingroup zwapi_part_data
    */
    typedef enum evxPlaneType
    {
        VX_PLANE_TYPE_XY = 1,
        VX_PLANE_TYPE_YZ = 2,
        VX_PLANE_TYPE_XZ = 3
    } evxPlaneType;

/*
@brief Quick edit display entity data
@ingroup zwapi_part_data
*/
    typedef struct svxQuickEditDisplayData
    {
        evxColor colorId;         /**<@brief  index of color of shapes. */
        int transparency;         /**<@brief  transparency of shapes. It should be between 0 to 100. */
        evxLineStyle lineStyle;   /**<@brief  index of line style*/
        evxLineWidth lineWidth;   /**<@brief  index of line style */
        evxPointStyle pointStyle; /**<@brief  index of point style */
        evxPointSize pointSize;   /**<@brief  size of point */
        vxName layerName;         /**<@brief  layer name, NULL to use defult layer. 
                                                         If the giving layer isn't existing in file, funcion will use it to create one */
    } svxQuickEditDisplayData;

/*
@brief Quick edit display entity type choose
@ingroup zwapi_part_data
*/
    typedef enum evxQuickEditDisplayEntityType
    {
        VX_QUICKEDITDISPLAY_SHAPE       = 1, /* <@brief  entities are shape */
        VX_QUICKEDITDISPLAY_FACE        = 2, /* <@brief  entities are face*/
        VX_QUICKEDITDISPLAY_EDGE        = 3, /* <@brief  entities are edge */
        VX_QUICKEDITDISPLAY_CURVE       = 4, /* <@brief  entities are curve */
        VX_QUICKEDITDISPLAY_POINT       = 5, /* <@brief  entities are point */
        VX_QUICKEDITDISPLAY_SKETCH      = 6, /* <@brief  entities are sketch */
        VX_QUICKEDITDISPLAY_DATUM_CSYS  = 7, /* <@brief  entities are datum csys */
        VX_QUICKEDITDISPLAY_DATUM_PLANE = 8, /* <@brief  entities are datum plane */
        VX_QUICKEDITDISPLAY_DATUM_AXIS  = 9, /* <@brief  entities are datum axis */
    } evxQuickEditDisplayEntityType;

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* zwapi_part_data_H */
