/**
@file zwapi_dwg_data.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the functions
for Drawing objects.
*/
/**
@defgroup zwapi_dwg_data Drawing Data
@ingroup DrawingObjectsModel
@brief
@details THE MODULE FOR THE ZW3D Data Types and Structures of the functions
for Drawing objects.
*/

#pragma once
#ifndef zwapi_dwg_data_H /* this ifndef surrounds entire header */
#define zwapi_dwg_data_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Drawing Attribute Data */
    //====================================================================================================================
    /**
    @brief Sheet Format Attributes structure
    @ingroup zwapi_dwg_data
    */
    typedef struct svxDrawingAt
    {
        vxLongName templateName;         /**<@brief template name*/
        int idDwgTpl;                    /**<@brief  0 to ignore this.   
                               If there are multiple drawing pages in the template file of a drawing and
                               user want to use the specified drawing as the template, user should use the
                               id of the corresponding drawing.    
                               Because the ZW3D platform does not support specifying sheet in drawing template
                               temporarily, this parameter can only be used for setting.    
                               The value of this variable cannot be obtained through the corresponding interface. */
        vxLongName configName;           /**<@brief  configuration name for drawing format */
        char paper[16];                  /**<@brief  paper size name */
        char useTemplate;                /**<@brief  1-use template,0-use custom */
        char useConfig;                  /**<@brief  1-use config,else 0 */
        double width;                    /**<@brief  drawing width */
        double height;                   /**<@brief  drawing height */
        char useBorder;                  /**<@brief  1: use border created by the parameters,else 0 */
        double margin[4];                /**<@brief  margin[0] the margin of the top;   
                               margin[1] the margin of the right;   
                               margin[2] the margin of the bottom;   
                               margin[3] the margin of the left;*/
        char bound;                      /**<@brief  0: no bound line;1: have bound line*/
        char centerMark;                 /**<@brief  0: have no centering marks;1: have centering marks*/
        char partition;                  /**<@brief  0: do not divide the border, 1: divide the border */
        int partNum[2];                  /**<@brief  partNum[0]: the number of the partitions in the direction of horizontal;
                               partNum[1]: the number of the partitions in the direction of vertical;*/
        char trimmingMark;               /**<@brief  0: no trimming mark; 1:have trimming mark;*/
        vxLongName blockTemplateName[3]; /**<@brief  template name of drawing block,   
                              blockTemplateName[0]: template name of title block,   
                              blockTemplateName[1]: template name of additional list block,   
                              blockTemplateName[2]: template name of code list block*/
    } svxDrawingAt;

    //====================================================================================================================
    /** @name Drawing Geometry Query/Set Data */
    //====================================================================================================================
    /**
    @brief reference entity data.

    fileName,partName and entClass parameters of this structure must be filled in, 
    and other parameters are optional according to whether the referenced part or assembly.

    if entClass=0,compPath and depth must be entered.
    if entClass>0,shellName must be entered.
    @ingroup zwapi_dwg_data
    */
    typedef struct svxRefEntData
    {
        vxPath fileName;      /**<@brief  file name */
        vxRootName partName;  /**<@brief  part name */
        vxLongName shellName; /**<@brief  shape name, format: shape_name(feature_name) */
        svxEntPath compPath;  /**<@brief  pick-path of the component */
        char entClass;        /**<@brief  0: component; 1: solid shell; 2: surface shell */
        int depth;            /**<@brief  depth of the component (top=0,1,2...) */
    } svxRefEntData;

    //====================================================================================================================
    /** @name View Query/Set Data */
    //====================================================================================================================
    /**
    @brief view type
    @ingroup zwapi_dwg_data
    */
    typedef enum evxViewType
    {
        VX_VIEW_ALL  = 0, /**<@brief  any view type */
        VX_VIEW_BASE = 1, /**<@brief  base view */
        VX_VIEW_PROJ = 2, /**<@brief  project view */
        VX_VIEW_SECT = 3, /**<@brief  section view */
        VX_VIEW_DET  = 4, /**<@brief  detail view */
        VX_VIEW_DEFN = 5  /**<@brief  definition view */
    } evxViewType;

    /**
    @brief drawing view projection angle
    @ingroup zwapi_dwg_data
    */
    typedef enum evxViewProjAngle
    {
        VX_VIEW_PROJ_ANG_ALL = 0,  /**<@brief  any view type */
        VX_VIEW_3RD_UP       = 1,  /**<@brief  view projected 3rd angle from above */
        VX_VIEW_3RD_DN       = 2,  /**<@brief  view projected 3rd angle from below */
        VX_VIEW_3RD_RT       = 3,  /**<@brief  view projected 3rd angle from right */
        VX_VIEW_3RD_LT       = 4,  /**<@brief  view projected 3rd angle from left */
        VX_VIEW_1ST_UP       = 5,  /**<@brief  view projected 1st angle from above */
        VX_VIEW_1ST_DN       = 6,  /**<@brief  view projected 1st angle from below */
        VX_VIEW_1ST_RT       = 7,  /**<@brief  view projected 1st angle from right */
        VX_VIEW_1ST_LT       = 8,  /**<@brief  view projected 1st angle from left */
        VX_VIEW_3RD_PRJ_ANG  = 9,  /**<@brief  view projected at angle, 3rd angle projection */
        VX_VIEW_1ST_PRJ_ANG  = 10, /**<@brief  view projected at angle, 1st angle projection */
    } evxViewProjAngle;

    /**
    @brief break Line style
    @ingroup zwapi_dwg_data
    */
    typedef enum evxBrkLineCutSty
    {
        VX_ZEROZIGZAG_BRKLINE = 0, /**<@brief  line */
        VX_ONEZIGZAG_BRKLINE,      /**<@brief  single ZigZag of broken line */
        VX_TWOZIGZAG_BRKLINE,      /**<@brief  double ZigZag of broken line */
        VX_CURVE_BRKLINE           /**<@brief  curve */
    } evxBrkLineCutSty;

    /**
    @brief attribute of break line
    @ingroup zwapi_dwg_data
    */
    typedef struct svxDwgBrkLineAt
    {
        double gap;                   /**<@brief  gap size */
        evxBrkLineCutSty brkLnCutSty; /**<@brief  cut style of break line */
        svxLineAt lineAtr;            /**<@brief  line attributes */
        vxName layerName;             /**<@brief  name of layer */
        int styleIndex;               /**<@brief  index of style of break line */
    } svxDwgBrkLineAt;

    //====================================================================================================================
    /** @name Symbol Query Data */
    //====================================================================================================================
    /**
    @brief symbol object type
    @ingroup zwapi_dwg_data
    */
    typedef enum evxSymbolType
    {
        VX_SYM_ALL       = -1, /**<@brief  any symbol */
        VX_SYM_USER      = 0,  /**<@brief  user defined symbol */
        VX_SYM_SURF      = 1,  /**<@brief  surface finish */
        VX_SYM_WELD      = 2,  /**<@brief  weld */
        VX_SYM_IMAGE     = 3,  /**<@brief  image */
        VX_SYM_ORIGIN    = 4,  /**<@brief  origin symbol */
        VX_SYM_BEAD      = 5,  /**<@brief  caterpillar */
        VX_SYM_ENDTRT    = 6,  /**<@brief  end treatment */
        VX_SYM_OPEN_LINK = 7,  /**<@brief  OLE object */
        VX_SYM_HOLE_MARK = 8,  /**<@brief  hole mark */
    } evxSymbolType;

    /**
    @brief symbol attributes structure
    @ingroup zwapi_dwg_data
    */
    typedef struct svxSymAttr
    {
        int allCir;           /**<@brief  all round circle (0-suppressed) */
        int extLine;          /**<@brief  extender line (0-suppressed) */
        double extLineSize;   /**<@brief  extender line size */
        evxTermType termType; /**<@brief  terminator type */
        double termSize;      /**<@brief  terminator size */
        char fontName[37];    /**<@brief  font name */
        char fontName2[37];   /**<@brief  secondary font name */
        int textTyp;          /**<@brief  text orientation (0-horizontal, 1-align) */
        int bold;             /**<@brief  text bold flag: 0-normal, 1-bold */
        int underLine;        /**<@brief  text underline flag: 0-normal, 1-underline */
        int autoTxtFlg;       /**<@brief  auto change text direction flag */
        double charHgt;       /**<@brief  text height */
        double charAsp;       /**<@brief  text character aspect = width / height */
        double charSpacing;   /**<@brief  text character spacing */
        evxColor textClr;     /**<@brief  text color */
        double scaleFac;      /**<@brief  scale factor */
        svxLineAt symAttr;    /**<@brief  general symbol attribute*/
        svxLineAt leaderAttr; /**<@brief  leader line attributes*/
    } svxSymAttr;

    //====================================================================================================================
    /** @name Table Query/Set */
    //====================================================================================================================
    /**
    @brief table type
    @ingroup zwapi_dwg_data
    */
    typedef enum evxTableType
    {
        VX_TABLE_ALL   = 0, /**<@brief  any table type */
        VX_TABLE_USER  = 1, /**<@brief  User table */
        VX_TABLE_BOM   = 2, /**<@brief  BOM table */
        VX_TABLE_HOLE  = 3, /**<@brief  Hole table */
        VX_TABLE_TRODE = 4, /**<@brief  Electrode table */
        VX_TABLE_WDSEG = 5, /**<@brief  Structural BOM table */
        VX_TABLE_WELD  = 6, /**<@brief  Weld table */
        VX_TABLE_PNT   = 7, /**<@brief  Point table*/
        VX_TABLE_DIM   = 8, /**<@brief  Dimension table*/
        VX_TABLE_REV   = 9  /**<@brief  Revision table */
    } evxTableType;

    /**
    @brief data of dimension bundle
    @ingroup zwapi_dwg_data
    */
    typedef struct svxDwgBundleDimData
    {
        int dimBundleId; /**<@brief  dimension bundle id */
        int count;       /**<@brief  count of points */
        svxPoint2 *pnts; /**<@brief  list of point */
        double dimValue; /**<@brief  dimension value */
    } svxDwgBundleDimData;

    //====================================================================================================================
    /** @name Style Manager Data */
    //====================================================================================================================

    /**
    @brief style manager type
    @ingroup zwapi_dwg_data
    */
    typedef enum evxDwgStyleManagerMethod
    {
        VX_STYLEMANAGER_TEXT, /**<@brief text */

        VX_STYLEMANAGER_ANNO_LEADER,          /**<@brief leader label */
        VX_STYLEMANAGER_ANNO_BALLOON,         /**<@brief balloon label */
        VX_STYLEMANAGER_ANNO_DATUM_FEATURE,   /**<@brief datum feature */
        VX_STYLEMANAGER_ANNO_DATUM_TARGET,    /**<@brief datum target */
        VX_STYLEMANAGER_ANNO_FEATURE_CONTROL, /**<@brief feature control symbol */

        VX_STYLEMANAGER_DIM_LINEAR,      /**<@brief linear */
        VX_STYLEMANAGER_DIM_ANGULAR,     /**<@brief angular */
        VX_STYLEMANAGER_DIM_RADIAL,      /**<@brief radial/diametric */
        VX_STYLEMANAGER_DIM_ARC,         /**<@brief arc length */
        VX_STYLEMANAGER_DIM_CHAMFER,     /**<@brief chamfer */
        VX_STYLEMANAGER_DIM_HOLECALLOUT, /**<@brief hole callout */
        VX_STYLEMANAGER_DIM_ORDINATE,    /**<@brief ordinate */

        VX_STYLEMANAGER_SYM_WELD,       /**<@brief weld symbol */
        VX_STYLEMANAGER_SYM_SRF_FINISH, /**<@brief surface finish symbol */

        VX_STYLEMANAGER_TABLE_USER,       /**<@brief user table */
        VX_STYLEMANAGER_TABLE_BOM,        /**<@brief bom table */
        VX_STYLEMANAGER_TABLE_HOLE,       /**<@brief hole table */
        VX_STYLEMANAGER_TABLE_EDM,        /**<@brief edm table */
        VX_STYLEMANAGER_TABLE_STRUCTURAL, /**<@brief structural table */
        VX_STYLEMANAGER_TABLE_WELD,       /**<@brief weld table */
        VX_STYLEMANAGER_TABLE_REVISION,   /**<@brief revision table */

        VX_STYLEMANAGER_VIEW_BASE,       /**<@brief base view */
        VX_STYLEMANAGER_VIEW_PROJECTION, /**<@brief projection view */
        VX_STYLEMANAGER_VIEW_AUXILIARY,  /**<@brief auxiliary view */
        VX_STYLEMANAGER_VIEW_SECTION,    /**<@brief section view */
        VX_STYLEMANAGER_VIEW_DETAIL,     /**<@brief detail view */
        VX_STYLEMANAGER_VIEW_ALTERNATE,  /**<@brief alternate view */
    } evxDwgStyleManagerMethod;

    /**
    @brief font type
    @ingroup zwapi_dwg_data
    */
    typedef enum evxTextFontType
    {
        VX_FONTTYPE_NORMAL,       /**<@brief none */
        VX_FONTTYPE_PROPORTIONAL, /**<@brief proportional  */
        VX_FONTTYPE_FIXED,        /**<@brief fixed */
    } evxTextFontType;

    /**
    @brief text precision
    @ingroup zwapi_dwg_data
    */
    typedef enum evxTextStroke
    {
        VX_STROKE_COARSE, /**<@brief coarse */
        VX_STROKE_MEDIUM, /**<@brief medium */
        VX_STROKE_FINE,   /**<@brief fine */
    } evxTextStroke;

    /**
    @brief fit method
    @ingroup zwapi_dwg_data
    */
    typedef enum evxTextAlignWordWrap
    {
        VX_TEXTALIGN_NONE,         /**<@brief none */
        VX_TEXTALIGN_WORDWRAP,     /**<@brief word wrap */
        VX_TEXTALIGN_AUTOSIZETEXT, /**<@brief auto size text */
    } evxTextAlignWordWrap;

    /**
    @brief horizontal method
    @ingroup zwapi_dwg_data
    */
    typedef enum evxHorizontalMethod
    {
        VX_HORIZONTAL_NORMAL, /**<@brief normal */
        VX_HORIZONTAL_LEFT,   /**<@brief left */
        VX_HORIZONTAL_CENTER, /**<@brief center */
        VX_HORIZONTAL_RIGHT,  /**<@brief right */
    } evxHorizontalMethod;

    /**
    @brief vertical method
    @ingroup zwapi_dwg_data
    */
    typedef enum evxVerticalMethod
    {
        VX_VERTICAL_NORMAL, /**<@brief normal */
        VX_VERTICAL_TOP,    /**<@brief top */
        VX_VERTICAL_CAP,    /**<@brief cap */
        VX_VERTICAL_HALF,   /**<@brief half */
        VX_VERTICAL_BASE,   /**<@brief base */
        VX_VERTICAL_BOTTOM, /**<@brief bottom */
    } evxVerticalMethod;

    /**
    @brief the text attribute of the text in the style manager.
    @ingroup zwapi_dwg_data
    */
    typedef struct svxDwgStyleManagerText
    {
        vxLongName fontName;            /**<@brief font name */
        vxLongName fontName2;           /**<@brief secondary font name */
        int underline;                  /**<@brief underline flag: 0x01,    
                                       overline flag: 0x02,    
                                       delete line flag 0x04.    
                                       if underline and overline, underline=0x01|0x02. */
        int color;                      /**<@brief text color(see evxColor/evxColorAppFlag) */
        evxLineWidth width;             /**<@brief line size */
        evxTextFontType fontType;       /**<@brief font type */
        evxTextStroke stroke;           /**<@brief text precision */
        evxTextAlignWordWrap fitMethod; /**<@brief fit method */
        evxHorizontalMethod horizontal; /**<@brief horizontal text alignment */
        int horizontalType;             /**<@brief horizontal text alignment type: 0 is line, 1 is paragraph. */
        evxVerticalMethod vertical;     /**<@brief vertical text alignment */
        int verticalType;               /**<@brief vertical text alignment type:0 is line, 1 is paragraph. */

        double charHeight;     /**<@brief text height */
        double charAspect;     /**<@brief character aspect = width /height */
        double multiLineSpace; /**<@brief spacing between multiple lines of text. */
        double charSpacing;    /**<@brief character spacing. */
        double charSlant;      /**<@brief slant angle of each character.*/
        double textAngle;      /**<@brief text angle. 0 degress to the right. */
        double charPath;       /**<@brief text path as angle 0.0 - 360.0 degrees.*/
        double textExpansion;  /**<@brief factor of text expansion along path. */
    } svxDwgStyleManagerText;

    /**
    @brief justification
    @ingroup zwapi_dwg_data
    */
    typedef enum evxTextAlignment
    {
        VX_ALIGNMENT_LEFT = 1, /**<@brief align left */
        VX_ALIGNMENT_CENTER,   /**<@brief align center */
        VX_ALIGNMENT_RIGHT,    /**<@brief aling right*/
    } evxTextAlignment;

    /**
    @brief the text attribute of the annotation/dimension in the style manager.
    @ingroup zwapi_dwg_data
    */
    typedef struct svxDwgStyleManagerAnnoDimText
    {
        vxLongName fontName;    /**<@brief font name */
        vxLongName fontName2;   /**<@brief secondary font name */
        int underline;          /**<@brief underline flag: 0x01,    
                              overline flag: 0x02,     
                              delete line flag 0x04.     
                              if underline and overline, underline=0x01|0x02. */
        int bold;               /**<@brief 1 is bold text, else 0. */
        int color;              /**<@brief text color(see evxColor/evxColorAppFlag) */
        evxTextAlignment align; /**<@brief text alignment */

        double charHeight;     /**<@brief text height */
        double charAspect;     /**<@brief character aspect = width /height */
        double multiLineSpace; /**<@brief spacing between multiple lines of text. */
        double charSpacing;    /**<@brief character spacing. */
        double charSlant;      /**<@brief slant angle of each character. */
        double tolchHgtFac;    /**<@brief tolerance of char height factor.(only dimension can use this variable.) */
    } svxDwgStyleManagerAnnoDimText;

    /**
    @brief the text attribute of the table in the style manager.
    @ingroup zwapi_dwg_data
    */
    typedef struct svxDwgStyleManagerTableText
    {
        vxLongName fontName;            /**<@brief font name */
        vxLongName fontName2;           /**<@brief secondary font name */
        int underline;                  /**<@brief underline flag: 0x01,     
                                       overline flag: 0x02,      
                                       delete line flag 0x04.      
                                       if underline and overline, underline=0x01|0x02. */
        int bold;                       /**<@brief 1 is bold text, else 0. */
        int color;                      /**<@brief text color(see evxColor/evxColorAppFlag) */
        evxTextFontType fontType;       /**<@brief font type */
        evxTextAlignWordWrap fitMethod; /**<@brief fit method */
        evxHorizontalMethod horizontal; /**<@brief horizontal text alignment */
        evxVerticalMethod vertical;     /**<@brief vertical text alignment */

        double charHeight;     /**<@brief text height */
        double charAspect;     /**<@brief character aspect = width /height */
        double multiLineSpace; /**<@brief spacing between multiple lines of text. */
        double charSpacing;    /**<@brief character spacing. */
        double charSlant;      /**<@brief slant angle of each character. */
    } svxDwgStyleManagerTableText;

    /**
    @brief the text attribute of the weld(or surface finish) in the style manager.
    @ingroup zwapi_dwg_data
    */
    typedef struct svxDwgStyleManagerSymText
    {
        vxLongName fontName;  /**<@brief font name */
        vxLongName fontName2; /**<@brief secondary font name */
        int underline;        /**<@brief underline flag: 0x01,     
                                       overline flag: 0x02,     
                                       delete line flag 0x04.     
                                       if underline and overline, underline=0x01|0x02. */
        int color;            /**<@brief text color(see evxColor/evxColorAppFlag) */
        double charHeight;    /**<@brief text height */
        double charAspect;    /**<@brief character aspect = width /height */
        double charSpacing;   /**<@brief character spacing. */
    } svxDwgStyleManagerSymText;

    /**
    @brief the text attribute of the view in the style manager.
    @ingroup zwapi_dwg_data
    */
    typedef struct svxDwgStyleManagerViewText
    {
        vxLongName fontName;    /**<@brief font name */
        vxLongName fontName2;   /**<@brief secondary font name */
        int underline;          /**<@brief 1 if underline flag, else 0. */
        int color;              /**<@brief text color(see evxColor/evxColorAppFlag) */
        evxTextAlignment align; /**<@brief text align */
        double charHeight;      /**<@brief text height */
        double charAspect;      /**<@brief character aspect = width /height */
        double multiLineSpace;  /**<@brief spacing between multiple lines of text. */
        double charSpacing;     /**<@brief character spacing. */
        double charSlant;       /**<@brief slant angle of each character. */
    } svxDwgStyleManagerViewText;

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* zwapi_dwg_data_H */
