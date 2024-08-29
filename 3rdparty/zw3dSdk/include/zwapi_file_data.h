/**
@file zwapi_file_data.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of File and
Path functions.
*/
/**
@defgroup zwapi_file_data File Data
@ingroup FileModel
@brief
@details THE MODULE FOR THE ZW3D Data Types and Structures of File and
Path functions.
*/

#pragma once
#ifndef ZW_API_FILE_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_FILE_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
    //====================================================================================================================
    /** @name File New Data */
    //====================================================================================================================
    /**
    @brief file type
    @ingroup zwapi_file_data
    */
    typedef enum evxFileType
    {
        VX_FILE_ALL  = 0, /**<@brief  all file */
        VX_FILE_PART = 1, /**<@brief  Z3PRT file */
        VX_FILE_ASSEMBLY, /**<@brief  Z3ASM file */
        VX_FILE_SHEET,    /**<@brief  Z3DRW file */
        VX_FILE_SKETCH,   /**<@brief  Z3SKH file */
        VX_FILE_CAMPLAN,  /**<@brief  Z3CAM file */
    } evxFileType;

    /**
    @brief file sub-type
    @ingroup zwapi_file_data
    */
    typedef enum evxFileSubtype
    {
        VX_SUBTYPE_NONE = 0,  /**<@brief  no subtype */
        VX_NORMAL_PART,       /**<@brief  subtype normal part for Z3PRT file */
        VX_ECAD_BOARD_PART,   /**<@brief  subtype ECAD part for Z3PRT file */
        VX_NORMAL_ASSEMBLY,   /**<@brief  subtype normal assembly for Z3ASM file */
        VX_ECAD_ASSEMBLY,     /**<@brief  subtype ECAD assembly for Z3ASM file */
        VX_ROUTING_ASSEMBLY,  /**<@brief  subtype routing assembly for Z3ASM file */
        VX_SMD_PART,          /**<@brief  subtype sheet metal part for Z3PRT file */
        VX_HARNESS_ASSEMBLY,  /**<@brief  subtype harness assembly for Z3ASM file */
        VX_HARNESS_PART,      /**<@brief  subtype harness part for Z3PRT file */
        VX_MASTERLAYOUT_PART, /**<@brief  subtype master layout part for Z3PRT file */
    } evxFileSubtype;

    //====================================================================================================================
    /** @name File Import/Export Data */
    //====================================================================================================================
    /**
    @brief export image color mode
    @ingroup zwapi_file_data
    */
    typedef enum evxImgColorMode
    {
        VX_EXPORT_IMG_COLOR_MODE_24BITS     = 0, /**<@brief  24bits mode */
        VX_EXPORT_IMG_COLOR_MODE_8BITS      = 1, /**<@brief  8bits mode */
        VX_EXPORT_IMG_COLOR_MODE_COlORIZED  = 0, /**<@brief  colorizeo mode */
        VX_EXPORT_IMG_COLOR_MODE_MONOCHROME = 2, /**<@brief  monochrome mode */
        VX_EXPORT_IMG_COLOR_MODE_GRAYSCALE  = 3  /**<@brief  grayscale mode */
    } evxImgColorMode;

    /**
    @brief export image background mode
    @ingroup zwapi_file_data
    */
    typedef enum evxImgBkgndMode
    {
        VX_EXPORT_IMG_BKGND_MODE_CURRENT = 0, /**<@brief  use current graphic window background color as the image background color */
        VX_EXPORT_IMG_BKGND_MODE_CUSTOM       /**<@brief  use the Color to define your favorite image background color */
    } evxImgBkgndMode;

    /**
    @brief export image range mode
    @ingroup zwapi_file_data
    */
    typedef enum evxImgRangeMode
    {
        VX_EXPORT_IMG_RANGE_MODE_NORMAL = 0, /**<@brief  exports what is displayed currently in the geographic window */
        VX_EXPORT_IMG_RANGE_MODE_EXTENTS,    /**<@brief  use a max envelope box of all entities as the export extent to export a snap image with its size defined by Paper Size */
        VX_EXPORT_IMG_RANGE_MODE_CUSTOM      /**<@brief  select a area to export through window-picking */
    } evxImgRangeMode;

    /**
    @brief export image type
    @ingroup zwapi_file_data
    */
    typedef enum evxImgType
    {
        VX_EXPORT_IMG_TYPE_BMP = 1, /**<@brief  bmp */
        VX_EXPORT_IMG_TYPE_GIF,     /**<@brief  gif */
        VX_EXPORT_IMG_TYPE_PNG,     /**<@brief  png */
        VX_EXPORT_IMG_TYPE_TIFF,    /**<@brief  tiff */
        VX_EXPORT_IMG_TYPE_JPEG     /**<@brief  jpeg */
    } evxImgType;

    /**
    @brief export pdf type
    @ingroup zwapi_file_data
    */
    typedef enum evxPdfType
    {
        VX_EXPORT_PDF_TYPE_RASTER = 1, /**<@brief  load the raster image into pdf */
        VX_EXPORT_PDF_TYPE_VECTOR,     /**<@brief  create the vector graphic data into pdf (set this value to Sheet file)*/
        VX_EXPORT_PDF_TYPE_OBJECT      /**<@brief  export type is 3D */
    } evxPdfType;

    /**
    @brief export pdf range mode
    @ingroup zwapi_file_data
    */
    typedef enum evxPdfRangeMode
    {
        VX_EXPORT_PDF_RANGE_MODE_NORMAL = 0, /**<@brief  export are-display */
        VX_EXPORT_PDF_RANGE_MODE_EXTENTS,    /**<@brief  export are-extent */
        VX_EXPORT_PDF_RANGE_MODE_CUSTOM      /**<@brief  export are-windows */
    } evxPdfRangeMode;

    /**
    @brief data of export image file
    @ingroup zwapi_file_data
    */
    typedef struct svxImgData
    {
        evxImgType Type;           /**<@brief  image type */
        evxImgColorMode ColorMode; /**<@brief  set color */
        unsigned int Width;        /**<@brief  width for the paper */
        unsigned int Height;       /**<@brief  height for the paper */
        unsigned int Quality;      /**<@brief  only if the jpeg format is selected to output.
                                  set image quality between 0 and 100 */
        evxImgBkgndMode BkgndMode; /**<@brief  background color  */
        svxColor Background;       /**<@brief  set it if BkgndMode is VX_EXPORT_IMG_BKGND_MODE_CUSTOM */
        evxImgRangeMode RangeMode; /**<@brief  export area mode */
        svxBndBox Rect;            /**<@brief  set it if RangeMode is VX_EXPORT_IMG_RANGE_MODE_CUSTOM */
    } svxImgData;

    /**
    @brief data of export pdf file
    @ingroup zwapi_file_data
    */
    typedef struct svxPdfData
    {
        evxPdfType Type;           /**<@brief export pdf type*/
        int Color;                 /**<@brief all black color or not, 1- MONOCHROME, 2-GRAYSCALE, 3-COLORIZED*/
        int Font;                  /**<@brief embed font or not, can be ignored */
        int Dpi;                   /**<@brief DPI of pdf*/
        int TextOutStyle;          /**<@brief  text output 1:text, 0:polygon lines */
        float LineWidthScale;      /**<@brief  line width scale factor(0.01~10) */
        float PaperWidth;          /**<@brief width of page*/
        float PaperHeight;         /**<@brief height of the page*/
        evxPdfRangeMode RangeMode; /**<@brief export mode, VX_EXPORT_PDF_RANGE_MODE_NORMAL-Rect can be ignored*/
        svxBndBox Rect;            /**<@brief export extent*/
        char Author[128];          /**<@brief author of pdf*/
        char Title[128];           /**<@brief title of pdf*/
        char Subject[128];         /**<@brief subject of pdf*/
        char Password[128];        /**<@brief password of pdf*/
        char Description[8192];    /**<@brief description of pdf*/
        int ExportMultiSheet;      /**<@brief  export multiple sheets to one pdf file, 1- active sheet, 2-one pdf for each, 3-one pdf for all (default: 1)*/
    } svxPdfData;

    /**
    @brief data of export STL file
    @ingroup zwapi_file_data
    */
    typedef struct svxSTLData
    {
        int Coordinate;         /**<@brief  coordinate, 0-world, 1-local (0-default) */
        int FileFormat;         /**<@brief  1 is ASCII file format, else 0. default:0 */
        int Translate;          /**<@brief  1 is translate to positive quadrant, else 0. default:0 */
        int RefineFacets;       /**<@brief  1 is refine facets to close volume, else 0. default:0  */
        int TwistAnalysis;      /**<@brief  1 is apply twist analysis, else 0. default:0 */
        double TessellationTol; /**<@brief  chord height tessellation tolerance.default:0.01 */
        double MeshSize;        /**<@brief  maximum mesh size.default:0 */

        int ExportType; /**<@brief  0-All objects, 1-Specified entities (0-default) */
        int EntCnt;     /**<@brief  the count of export entities if ExportType = 1 */
        int *EntList;   /**<@brief  the specified entities id list if ExportType = 1 */

        int ExportLayer; /**<@brief  0-All layers, 1- Specified layers (0-default) */
        int LayerCnt;    /**<@brief  the count of export layers if ExportLayer = 1 */
        int *LayerList;  /**<@brief  the specified layers id list if ExportLayer = 1 */

        int ExcludeGeom; /**<@brief  filter geometry type(evxExportExcludeGeom),
                                 like this: VX_EXCLUDE_CURVE | VX_EXCLUDE_SURFACE
                                 (default: ExcludeGeom=VX_EXCLUDE_BLANKED)*/
    } svxSTLData;

    /**
    @brief version of DWG
    @ingroup zwapi_file_data
    */
    typedef enum evxDWGVer
    {
        VX_DWG_VERSION_2018 = 1, /**<@brief  version 2018 */
        VX_DWG_VERSION_2013 = 2, /**<@brief  version 2013 */
        VX_DWG_VERSION_2010 = 3, /**<@brief  version 2010 */
        VX_DWG_VERSION_2007,     /**<@brief  version 2007 */
        VX_DWG_VERSION_2004,     /**<@brief  version 2004 */
        VX_DWG_VERSION_2000,     /**<@brief  version 2000 */
        VX_DWG_VERSION_R14,      /**<@brief  version r14 */
        VX_DWG_VERSION_R13,      /**<@brief  version r13 */
        VX_DWG_VERSION_R11_R12,  /**<@brief  version r11 or r12 */
    } evxDWGVer;

    /**
    @brief data type of idf for exporting
    @ingroup zwapi_file_data
    */
    typedef enum evxIDFDataType
    {
        VX_IDF_PART_DATA = 0, /**<@brief  part data*/
        VX_IDF_ASM_DATA  = 1, /**<@brief  assemble data */
    } evxIDFDataType;

    /**
    @brief data of export GRP file
    @ingroup zwapi_file_data
    */
    typedef struct svxGRPData
    {
        char ExportType; /**<@brief  0-All objects, 1-Specified entities */
        int EntCnt;      /**<@brief  the count of export entities if ExportType = 1 */
        int *EntList;    /**<@brief  the specified entities id list if ExportType = 1 */
        int ExcludeGeom; /**<@brief  filter geometry type(evxExportExcludeGeom),
                            like this: VX_EXCLUDE_CURVE | VX_EXCLUDE_SURFACE */
    } svxGRPData;

    /**
    @brief exclude attribute(no color) of *.dwg/*.dxf
    @ingroup zwapi_file_data
    */
    typedef enum evxExportExcludeWidthStyle
    {
        VX_EXCLUDE_WIDTH_STYLE_1 = 0x1,  /**<@brief  width-Light  |  style-Solid */
        VX_EXCLUDE_WIDTH_STYLE_2 = 0x2,  /**<@brief  width-Thin   |  style-Dot */
        VX_EXCLUDE_WIDTH_STYLE_3 = 0x4,  /**<@brief  width-Medium |  style-Dash-Dot */
        VX_EXCLUDE_WIDTH_STYLE_4 = 0x8,  /**<@brief  width-Thick  |  style-Long-Dash */
        VX_EXCLUDE_WIDTH_STYLE_5 = 0x10, /**<@brief  width-Heavy  |  style-Dash */
    } evxExportExcludeWidthStyle;

    /**
    @brief exclude attribute(color) of *.dwg/*.dxf
    @ingroup zwapi_file_data
    */
    typedef enum evxExportExcludeColor
    {
        VX_EXCLUDE_COLOR_GREEN         = 0x1,    /**<@brief  The color of the 1st row,1st column (R=0,   G=255, B=0) */
        VX_EXCLUDE_COLOR_RED           = 0x2,    /**<@brief  The color of the 1st row,2nd column (R=255, G=0,   B=0) */
        VX_EXCLUDE_COLOR_BROWN         = 0x4,    /**<@brief  The color of the 1st row,3rd column (R=160, G=96,  B=0) */
        VX_EXCLUDE_COLOR_GOLDENROD     = 0x8,    /**<@brief  The color of the 2nd row,1st column (R=255, G=188, B=0) */
        VX_EXCLUDE_COLOR_MED_BLUE      = 0x10,   /**<@brief  The color of the 2nd row,2nd column (R=0,   G=255, B=255) */
        VX_EXCLUDE_COLOR_DARK_MAGENTA  = 0x20,   /**<@brief  The color of the 2nd row,3rd column (R=255, G=0,   B=255) */
        VX_EXCLUDE_COLOR_DARK_GREY     = 0x40,   /**<@brief  The color of the 3rd row,1st column (R=96,  G=96,  B=96)  */
        VX_EXCLUDE_COLOR_DARK_BLUE     = 0x80,   /**<@brief  The color of the 3rd row,2nd column (R=0,   G=0,   B=255) */
        VX_EXCLUDE_COLOR_VIOLET        = 0x100,  /**<@brief  The color of the 3rd row,3rd column (R=140, G=140, B=235) */
        VX_EXCLUDE_COLOR_LIGHT_GREEN   = 0x200,  /**<@brief  The color of the 4th row,1st column (R=160, G=255, B=160) */
        VX_EXCLUDE_COLOR_LIGHT_BLUE    = 0x400,  /**<@brief  The color of the 4th row,2nd column (R=160, G=255, B=255) */
        VX_EXCLUDE_COLOR_ROSE          = 0x800,  /**<@brief  The color of the 4th row,3rd column (R=255, G=160, B=160) */
        VX_EXCLUDE_COLOR_LIGHT_MAGENTA = 0x1000, /**<@brief  The color of the 5th row,1st column (R=255, G=160, B=255) */
        VX_EXCLUDE_COLOR_LIGHT_GREY    = 0x2000, /**<@brief  The color of the 5th row,2nd column (R=160, G=160, B=160) */
        VX_EXCLUDE_COLOR_WHITE         = 0x4000, /**<@brief  The color of the 5th row,3rd column (R=255, G=255, B=255) */
    } evxExportExcludeColor;

    /**
    @brief remove text font info type.
    @ingroup zwapi_file_data
    */
    typedef enum evxRemoveTextFontType
    {
        VX_TEXT_FONT_TYPE_NONE    = 0, /**<@brief  none */
        VX_TEXT_FONT_TYPE_ALL     = 1, /**<@brief  all */
        VX_TEXT_FONT_TYPE_EXCLUDE = 2, /**<@brief  exclude sheet format and table. */
    } evxRemoveTextFontType;

    /**
    @brief data of export DWG file
    @ingroup zwapi_file_data
    */
    typedef struct svxDWGData
    {
        evxDWGVer Version; /**<@brief  version of DWG */
        char FileType;     /**<@brief  export type of file. 0-DWG, 1- DFX(ASCLL), 2-DFX(Binary)
                            make sure the file extension type is same with FileType */

        char ExportType; /**<@brief  0-All objects, 1-Specified entities */
        int EntCnt;      /**<@brief  the count of export entities if ExportType = 1 */
        int *EntList;    /**<@brief  the specified entities id list if ExportType = 1 */

        char ExportLayer; /**<@brief  0-All layers, 1- Specified layers */
        int LayerCnt;     /**<@brief  the count of export layers if ExportLayer = 1 */
        int *LayerList;   /**<@brief  the specified layers id list if ExportLayer = 1 */

        int ExcludeGeom;                    /**<@brief  filter geometry type(evxExportExcludeGeom),
                            like this: VX_EXCLUDE_CURVE | VX_EXCLUDE_SURFACE */
        int ExcludeWidth;                   /**<@brief  filter width type(evxExportExcludeWidthStyle),
                            like this: VX_EXCLUDE_WIDTH_STYLE_1 | VX_EXCLUDE_WIDTH_STYLE_2 */
        int ExcludeStyle;                   /**<@brief  filter style type(evxExportExcludeWidthStyle),
                            like this: VX_EXCLUDE_WIDTH_STYLE_1 | VX_EXCLUDE_WIDTH_STYLE_2 */
        int ExcludeColor;                   /**<@brief  filter color type(evxExportExcludeColor),
                            like this: VX_EXCLUDE_COLOR_GREEN | VX_EXCLUDE_COLOR_RED */
        int reduceData;                     /**<@brief  1 if reduce data,else 0.default:1 */
        int trimSurface;                    /**<@brief  1 if trim surface,else 0.default:1 */
        int freeSurface;                    /**<@brief  1 if free surface,else 0.default:0 */
        int mergeArc;                       /**<@brief  1 if merge arc,else 0.default:0 */
        double tolUVCurve;                  /**<@brief  tolerance of UV curve.default:0.01 */
        double tolCurve;                    /**<@brief  tolerance of curve.default:0.01 */
        double tolSurface;                  /**<@brief  tolerance of surface.default:0.01 */
        int isTrueColor;                    /**<@brief  1 if true color,else 0. */
        int exportSheetOnly;                /**<@brief  1 if export active sheet only, else export all sheets(0).default:1 */
        int toModelSpace;                   /**<@brief  1 if export to model space,else export to layout space(0).default:1 */
        int individualFiles;                /**<@brief  1 if export as individual files,else 0.default:0. */
        int dimStyleByBlock;                /**<@brief  1 if dimension style by block,else 0.default:0 */
        int exportShtFmtEnts;               /**<@brief  1 if export sheet format entities,else 0.default:1 */
        int drawingView;                    /**<@brief  1 if export as curves, 2 if export as block, else export as block for each component(3).default:1 */
        int toNewLayer;                     /**<@brief  1 if export to new layer for each part,else 0.default:0. apply it if drawingView=3. */
        double scale;                       /**<@brief  scale output.default:1 */
        evxRemoveTextFontType textFontType; /**<@brief  remove text font info type.default:VX_TEXT_FONT_TYPE_NONE */
        int explodeHatch;                   /**<@brief  1 if explode hatch as single line,else 0.default:0 */
        int explodeText;                    /**<@brief  1 if explode text as single line,else 0.default:0 */
    } svxDWGData;

    /**
    @brief data of export IGEES file
    @ingroup zwapi_file_data
    */
    typedef struct svxIGESData
    {
        char Coordinate; /**<@brief  0-World, 1- Local (0-default)*/
        char ExportType; /**<@brief  0-All objects, 1-Specified entities */
        int EntCnt;      /**<@brief  the count of export entities if ExportType = 1 */
        int *EntList;    /**<@brief  the specified entities id list if ExportType = 1 */
        int ExcludeGeom; /**<@brief  filter geometry type(evxExportExcludeGeom),
                            like this: VX_EXCLUDE_CURVE | VX_EXCLUDE_SURFACE */
    } svxIGESData;

    /**
    @brief data of export STEP file
    @ingroup zwapi_file_data
    */
    typedef struct svxSTEPData
    {
        char AppProtocol; /**<@brief  0-AP203, 1-AP214 (1-default), 2-AP242 */
        char OutPut;      /**<@brief  0-PART, 1-Assembly (1-default) */
        char ExportType;  /**<@brief  0-All objects, 1-Specified entities */
        int EntCnt;       /**<@brief  the count of export entities if ExportType = 1 */
        int *EntList;     /**<@brief  the specified entities id list if ExportType = 1 */
        int ExcludeGeom;  /**<@brief  filter geometry type(evxExportExcludeGeom),
                            like this: VX_EXCLUDE_CURVE | VX_EXCLUDE_SURFACE */
    } svxSTEPData;

    /**
    @brief version of JT
    @ingroup zwapi_file_data
    */
    typedef enum evxJTVer
    {
        VX_JT_VER_6_4,  /**<@brief  version: 6.4 */
        VX_JT_VER_7_0,  /**<@brief  version: 7.0 */
        VX_JT_VER_8_0,  /**<@brief  version: 8.0 */
        VX_JT_VER_8_1,  /**<@brief  version: 8.1 */
        VX_JT_VER_8_2,  /**<@brief  version: 8.2 */
        VX_JT_VER_8_3,  /**<@brief  version: 8.3 */
        VX_JT_VER_9_0,  /**<@brief  version: 9.0 */
        VX_JT_VER_9_1,  /**<@brief  version: 9.1 */
        VX_JT_VER_9_2,  /**<@brief  version: 9.2 */
        VX_JT_VER_9_3,  /**<@brief  version: 9.3 */
        VX_JT_VER_9_4,  /**<@brief  version: 9.4 */
        VX_JT_VER_9_5,  /**<@brief  version: 9.5 */
        VX_JT_VER_10_0, /**<@brief  version: 10.0 */
        VX_JT_VER_10_1, /**<@brief  version: 10.1 */
        VX_JT_VER_10_2, /**<@brief  version: 10.2 */
        VX_JT_VER_10_3, /**<@brief  version: 10.3 */
        VX_JT_VER_10_4, /**<@brief  version: 10.4 */
    } evxJTVer;

    /**
    @brief version of IDF
    @ingroup zwapi_file_data
    */
    typedef enum evxIDFVersion
    {
        VX_IDF_3, /**<@brief  version: 3.0 */
    } evxIDFVersion;
    /**
    @brief data of export JT file
    @ingroup zwapi_file_data
    */
    typedef struct svxJTData
    {
        evxJTVer Version; /**<@brief  JT version (VX_JT_VER_10_0-default) */
        char Structure;   /**<@brief  0-Monolithic, 1-Per part, 2-Full shatter (0-default) */
        char Writetype;   /**<@brief  0-All, 1-Parts only, 2-Assembly only (0-default) */
        char ExportType;  /**<@brief  0-All objects, 1-Specified entities */
        int EntCnt;       /**<@brief  the count of export entities if ExportType = 1 */
        int *EntList;     /**<@brief  the specified entities id list if ExportType = 1 */
        int ExcludeGeom;  /**<@brief  filter geometry type(evxExportExcludeGeom),
                           like this: VX_EXCLUDE_CURVE | VX_EXCLUDE_SURFACE */
        int ExportPMI;    /**<@brief  0-None, 1-All (0-default) */
    } svxJTData;

    /**
    @brief data of export PARA file
    @ingroup zwapi_file_data
    */
    typedef struct svxPARAData
    {
        char Coordinate;  /**<@brief  0-World, 1-Local (0-default)*/
        char OutPut;      /**<@brief  0-Assembly, 1-Part (1-default) */
        int FileVer;      /**<@brief  file version (7 ~ 30, 19-default) */
        int WriteFreeCrv; /**<@brief  whether to write free curve (1 = yes, 0 = no) */
        int WriteFreePnt; /**<@brief  whether to write free point (1 = yes, 0 = no) */
        int HealErr;      /**<@brief  whether to auto heal topology error (1 = yes, 0 = no) */
        char ExportType;  /**<@brief  0-All objects, 1-Specified entities */
        int EntCnt;       /**<@brief  the count of export entities if ExportType = 1 */
        int *EntList;     /**<@brief  the specified entities id list if ExportType = 1 */
        int ExcludeGeom;  /**<@brief  filter geometry type(evxExportExcludeGeom),
                            like this: VX_EXCLUDE_CURVE | VX_EXCLUDE_SURFACE */
    } svxPARAData;

    /**
    @brief data of export CAT5 file
    @ingroup zwapi_file_data
    */
    typedef struct svxCAT5Data
    {
        int FileVer;     /**<@brief  file version (15 ~ 28, 24-default) */
        char ExportType; /**<@brief  0-All objects, 1-Specified entities */
        int EntCnt;      /**<@brief  the count of export entities if ExportType = 1 */
        int *EntList;    /**<@brief  the specified entities id list if ExportType = 1 */
        int ExcludeGeom; /**<@brief  filter geometry type(evxExportExcludeGeom),
                            like this: VX_EXCLUDE_CURVE | VX_EXCLUDE_SURFACE */
    } svxCAT5Data;

    /**
    @brief data of export HTML file
    @ingroup zwapi_file_data
    */
    typedef struct svxHTMLData
    {
        int AutoZip;        /**<@brief  auto zip (1 = yes, 0 = no) */
        char Password[128]; /**<@brief  password of html file */
    } svxHTMLData;

    /**
    @brief data of exporting intermediate data format
    @ingroup zwapi_file_data
    */
    typedef struct svxIDFData
    {
        evxIDFDataType datatype; /**<@brief  type of IDF data for exporting */
        union uvxIDfData
        {
            struct svxIDFPartData
            {
                int idxCoord;          /**<@brief  idx of Coordinate */
                int idxTopSideFace;    /**<@brief  idx of face on top side */
                int idxBottomSideFace; /**<@brief  idx of face on bottom side */
                int outputAs;          /**<@brief  output type, 1-Board 2-Panel 3-Component, 1 is default. */
            } partData;                /**<@brief  part data for exporting */
            struct svxIDFAsmData
            {
                int onlyExportBoard; /**<@brief  flag to only export board file 0 is default. */
            } asmData;               /**<@brief  assemble data for exporting */
        } idfData;
        evxIDFVersion Version; /**<@brief  version of IDF */
        int showLog;           /**<@brief  show output log 1 to show export log, and is default. */
    } svxIDFData;

    /**
    @brief dwg dxf file import of convert polygon mesh to
    @ingroup zwapi_file_data
    */
    typedef enum evxDWGDXFConvertMeshTo
    {
        VX_DWGDXF_MESHTO_STL_BLOCKS   = 1, /**<@brief  convert all polygon meshes into STL Blocks */
        VX_DWGDXF_MESHTO_LINES        = 2, /**<@brief  convert all polygon meshing into line segments interconnected at each vertex,
                                           similar to how the mesh was originally defined. This is the "light weight" option */
        VX_DWGDXF_MESHTO_PLANAR_FACES = 3, /**<@brief  convert all polygon meshing into line segments interconnected at each vertex
                                           but also connected with planar faces */
    } evxDWGDXFConvertMeshTo;

    /**
    @brief import dwg dxf file, exclude color
    @ingroup zwapi_file_data
    */
    typedef enum evxDWGDXFExcludeColor
    {
        VX_DWGDXF_IMPORT_EXCLUDE_COLOR_RED     = 0x1,  /**<@brief  R=255, G=0,   B=0 */
        VX_DWGDXF_IMPORT_EXCLUDE_COLOR_GREEN   = 0x2,  /**<@brief  R=0,   G=255, B=0 */
        VX_DWGDXF_IMPORT_EXCLUDE_COLOR_BLUE    = 0x4,  /**<@brief  R=0,   G=255, B=255 */
        VX_DWGDXF_IMPORT_EXCLUDE_COLOR_YELLOW  = 0x8,  /**<@brief  R=255, G=188, B=0 */
        VX_DWGDXF_IMPORT_EXCLUDE_COLOR_MAGENTA = 0x10, /**<@brief  R=255, G=0,   B=255 */
        VX_DWGDXF_IMPORT_EXCLUDE_COLOR_RCYAN   = 0x20, /**<@brief  R=160, G=255, B=255 */
        VX_DWGDXF_IMPORT_EXCLUDE_COLOR_WHITE   = 0x40, /**<@brief  R=255, G=255, B=255 */
    } evxDWGDXFExcludeColor;

    /**
    @brief file import type
    @ingroup zwapi_file_data
    */
    typedef enum evxImportType
    {
        VX_IMPORT_TYPE_ALL       = 0, /**<@brief  import all files types */
        VX_IMPORT_TYPE_PARASOLID = 1, /**<@brief  import .x_t file */
        VX_IMPORT_TYPE_DWG_DXF   = 2, /**<@brief  import .dwg/.dxf file */
        VX_IMPORT_TYPE_STEP,          /**<@brief  import .stp/.step file */
        VX_IMPORT_TYPE_SAT,           /**<@brief  import .sat/.sab file */
        VX_IMPORT_TYPE_IGES,          /**<@brief  import .igs/.iges file */
        VX_IMPORT_TYPE_CATIA4,        /**<@brief  import .model/.exp... file */
        VX_IMPORT_TYPE_CATIA5,        /**<@brief  import .CATPart/.CATProduct file */
        VX_IMPORT_TYPE_INVENTOR,      /**<@brief  import .ipt/.iam file */
        VX_IMPORT_TYPE_JT,            /**<@brief  import .jt file */
        VX_IMPORT_TYPE_PROE_CERO,     /**<@brief  import .prt/.asm file */
        VX_IMPORT_TYPE_SOLIDEDGE,     /**<@brief  import .par/.psm... file */
        VX_IMPORT_TYPE_SOLIDWORKS,    /**<@brief  import .sldprt/.sldasm file */
        VX_IMPORT_TYPE_UG,            /**<@brief  import .prt file */
        VX_IMPORT_TYPE_STL,           /**<@brief  import .stl file */
        VX_IMPORT_TYPE_GPH,           /**<@brief  import .3rd graphic format file */
        VX_IMPORT_PTS_FROM_FILE,      /**<@brief  import points form ASCII file (.txt, .asc, .csv, .dat, .exp, .pts, .xyz are supported) */
        VX_IMPORT_TYPE_IDF,           /**<@brief  import Intermediate data form */
    } evxImportType;

    /**
    @brief setting general properties if import stp/step file
    @ingroup zwapi_file_data
    */
    typedef struct svxImportSTEPData
    {
        int isAll;            /**<@brief  1 is select all options, else 0 */
        int isAutoSew;        /**<@brief  1 is auto sew geometry, else 0 */
        int isActivatePart;   /**<@brief  1 is auto activate part, else 0. */
        int isSubPart;        /**<@brief  1 is auto create sub-part, else 0. */
        int isTrimEdges;      /**<@brief  1 is break trim edges, else 0. */
        int isForceClose;     /**<@brief  1 is Force close, else 0. */
        int isSewParts;       /**<@brief  1 is sew unique parts, else 0. */
        int isHiddenEnts;     /**<@brief  1 is read hidden entities, else 0. */
        int isKeepDire;       /**<@brief  1 is keep origin face direction, else 0. */
        vxLongName placement; /**<@brief  CSYS name. if placement[0] = 0 or placement="", use default CSYS.
                             plancement[0]=0 if isAll=1. */
    } svxImportSTEPData;

    /**
    @brief setting properties if import prt file
    @ingroup zwapi_file_data
    */
    typedef struct svxImportUGData
    {
        int isAll;          /**<@brief  1 is select all options, else 0 */
        int isActivatePart; /**<@brief  1 is auto activate part, else 0. */
        int isSubPart;      /**<@brief  1 is auto create sub-part, else 0. */
        int isAssoImport;   /**<@brief  1 is associative import, else 0. */
        int importMode;     /**<@brief  1 is normal, else 2 is quick import. */
        int isFreeCrv;      /**<@brief  1 is free curve, else 0. */
        int isFreePnt;      /**<@brief  1 is free point, else 0. */
        int isSheetBody;    /**<@brief  1 is sheet body, else 0. */
        int isHiddenEnt;    /**<@brief  1 is hidden entity, else 0. */
        int isSuppComp;     /**<@brief  1 is suppressed component, else 0. */
        int PMI;            /**<@brief  1 is none, 2 is visual, 3 is semantic. */
    } svxImportUGData;

    /**
    @brief dwg dxf import options of read as units
    @ingroup zwapi_file_data
    */
    typedef enum evxDWGDXFReadAsUnits
    {
        VX_UNIT_DWGDXF_INCHES       = 1,  /**<@brief  inches */
        VX_UNIT_DWGDXF_FEET         = 2,  /**<@brief  feet */
        VX_UNIT_DWGDXF_MILES        = 3,  /**<@brief  miles */
        VX_UNIT_DWGDXF_MILIMETERS   = 4,  /**<@brief  milimeters */
        VX_UNIT_DWGDXF_CENTIMETERS  = 5,  /**<@brief  centimeters */
        VX_UNIT_DWGDXF_METERS       = 6,  /**<@brief  meters */
        VX_UNIT_DWGDXF_KILOMETERS   = 7,  /**<@brief  kilometers */
        VX_UNIT_DWGDXF_MICROINCHES  = 8,  /**<@brief  microinches */
        VX_UNIT_DWGDXF_MILS         = 9,  /**<@brief  mils */
        VX_UNIT_DWGDXF_YARDS        = 10, /**<@brief  yards */
        VX_UNIT_DWGDXF_ANGSTROMS    = 11, /**<@brief  angstroms */
        VX_UNIT_DWGDXF_NANOMETERS   = 12, /**<@brief  nanometers */
        VX_UNIT_DWGDXF_MICRONS      = 13, /**<@brief  microns */
        VX_UNIT_DWGDXF_DECIMETERS   = 14, /**<@brief  decimeters */
        VX_UNIT_DWGDXF_DEKAMETERS   = 15, /**<@brief  dekameters */
        VX_UNIT_DWGDXF_HECTOMETERS  = 16, /**<@brief  hectometers */
        VX_UNIT_DWGDXF_GIGAMETERS   = 17, /**<@brief  gigameters */
        VX_UNIT_DWGDXF_ASTRONOMICAL = 18, /**<@brief  astronomical */
        VX_UNIT_DWGDXF_LIGHTYEARS   = 19, /**<@brief  lightyears */
        VX_UNIT_DWGDXF_PARSECS      = 20, /**<@brief  parsecs */
    } evxDWGDXFReadAsUnits;

    /**
    @brief setting properties if import dwg/dxf file
    @ingroup zwapi_file_data
    */
    typedef struct svxImportDwgDxfData
    {
        int isAutoSew;                        /**<@brief  1 is auto sew geometry, else 0. */
        int isAutoAct;                        /**<@brief  1 is auto activate part, else 0. */
        int isAutoSubPart;                    /**<@brief  1 is auto create sub-part, else 0. */
        int isConvertPolylines;               /**<@brief  1 is convert polylines into curves, else 0. */
        int isRefine;                         /**<@brief  1 is refine polyline curves, else 0. */
        int isReadLayers;                     /**<@brief  1 is read empty layers, else 0. */
        int isExplodeDim;                     /**<@brief  1 is explode dimension, else 0. */
        evxDWGDXFConvertMeshTo convertMeshTo; /**<@brief  convert polygon mesh to. */
        vxName placement;                     /**<@brief  CSYS name. if placement[0] = 0 or placement="", use default CSYS. */
        int isUnitFile;                       /**<@brief  1 use file units, else 0. */
        int isUnitReadAs;                     /**<@brief  1 read as, else 0. */
        evxDWGDXFReadAsUnits fileUnits;       /**<@brief  units. */
        int isConvertToUnits;                 /**<@brief  convert to ZW3D units. evxUnitType(no apply VX_UNIT_FOOT) */
        int isModelSpace;                     /**<@brief  1 is model space, else 0. */
        int isPaperSpace;                     /**<@brief  1 is paper space, else 0. */
        int excludeGeom;                      /**<@brief  exclude geometry(evxExportExcludeGeom)
                               like this: VX_EXCLUDE_CURVE | VX_EXCLUDE_SURFACE */
        int excludeWidth;                     /**<@brief  exclude width(evxExportExcludeWidthStyle)
                               like this: VX_EXCLUDE_WIDTH_STYLE_1 | VX_EXCLUDE_WIDTH_STYLE_2 */
        int excludeStyle;                     /**<@brief  exclude style(evxExportExcludeWidthStyle)
                               like this: VX_EXCLUDE_WIDTH_STYLE_1 | VX_EXCLUDE_WIDTH_STYLE_2 */
        int excludeColor;                     /**<@brief  exclude color(evxDWGDXFExcludeColor)
                               like this: VX_DWGDXF_IMPORT_EXCLUDE_COLOR_RED | VX_DWGDXF_IMPORT_EXCLUDE_COLOR_GREEN */
    } svxImportDwgDxfData;

    /**
    @brief setting properties if import stl file
    @ingroup zwapi_file_data
    */
    typedef struct svxImportSTLData
    {
        int isAutoSubPart; /**<@brief  1 is auto create sub-part, else 0. */
        int isAutoAct;     /**<@brief  1 is auto activate part, else 0. */
        int isTrimEdges;   /**<@brief  1 is break trim edges, else 0. */
    } svxImportSTLData;

    /**
    @brief IDF import options of units
    @ingroup zwapi_file_data
    */
    typedef enum evxIDFUnits
    {
        VX_UNIT_IDF_Default     = 0, /**<@brief  default */
        VX_UNIT_IDF_INCHES      = 1, /**<@brief  in */
        VX_UNIT_IDF_FEET        = 2, /**<@brief  ft */
        VX_UNIT_IDF_MILS        = 3, /**<@brief  mil */
        VX_UNIT_IDF_MILIMETERS  = 4, /**<@brief  mm */
        VX_UNIT_IDF_CENTIMETERS = 5, /**<@brief  cm */
        VX_UNIT_IDF_METERS      = 6, /**<@brief  m */
        VX_UNIT_IDF_DECIMETERS  = 7, /**<@brief  dm */
        VX_UNIT_IDF_YARDS       = 8, /**<@brief  yd */
        VX_UNIT_IDF_MICRONS     = 9, /**<@brief  mic */
    } evxIDFUnits;

    /**
    @brief IDF import options of alternate name
    @ingroup zwapi_file_data
    */
    typedef enum evxIDFAlternateName
    {
        VX_ALTERNATE_NAME_NONE    = 1, /**<@brief  none */
        VX_ALTERNATE_NAME_PACKAGE = 2, /**<@brief  package name */
        VX_ALTERNATE_NAME_MODEL   = 3, /**<@brief  model name */
    } evxIDFAlternateName;

    /**
    @brief IDF mapping type
    @ingroup zwapi_file_data
    */
    typedef enum evxIDFMapType
    {
        VX_IDF_MAP_COMP    = 0, /**<@brief  replace the specified component. */
        VX_IDF_IGNORE_COMP = 1, /**<@brief  not to import specified component. */
    } evxIDFMapType;

    /**
    @brief filter properties if import IDF file
    @ingroup zwapi_file_data
    */
    typedef struct svxImportIDFFilterData
    {
        int onlyImportBoard;       /**<@brief  1 to only import board, else 0. 0 is default */
        int importComponentInLib;  /**<@brief  1 to import component in library firstly, else 0. 0 is default */
        int insteadBoardThickness; /**<@brief  1 to instead thickness of board, else 0. 0 is default */
        double BoardThickness;     /**<@brief  value of board thickness, take effect when "insteadBoardThickness" is 1. */
        int showLog;               /**<@brief  1 to show the import result dialog, else 0. 1 is default */
    } svxImportIDFFilterData;

    /**
    @brief mapping data of importing IDF file
    @ingroup zwapi_file_data
    */
    typedef struct svxImportIDFMappingData
    {
        vxLongName oldCompName;           /**<@brief  name of component need to be replaced in emn file. */
        vxLongName oldCompName_Alternate; /**<@brief  alternate name of old component in emn file. */
        vxLongName newCompName;           /**<@brief  name of new component to replace specified component. */
        evxIDFMapType type;               /**<@brief  map type. */
    } svxImportIDFMappingData;

    /**
    @brief setting properties if import IDF file
    @note When imports IDF files, the value of importTo from svxImportData should be 2.
    @ingroup zwapi_file_data
    */
    typedef struct svxImportIDFData
    {
        vxLongPath libraryFile;            /**<@brief  full path of library file. */
        double defaultBoardThickness;      /**<@brief  default board thickness. 0.0 is default */
        double defaultComponentHeight;     /**<@brief  default component height. 0.0 is default */
        double defaultHoleDiameter;        /**<@brief  default hole diameter. 0.0 is default */
        evxIDFUnits unit;                  /**<@brief  unit of board and component. */
        evxIDFAlternateName alternateName; /**<@brief  alternate name to search, used when the model can't be found by the mapping name. */
        int autoCorrectSketch;             /**<@brief  1 to auto correct sketch, else 0. 0 is default */
        int addCoincidenceConstraint;      /**<@brief  1 to add coincidence constraint between board and component, else 0. 0 is default */
        vxLongPath mapFile;                /**<@brief  full path of .map file. NULL to ignore. */
        svxImportIDFMappingData *mapping;  /**<@brief  replace the specified component in IDF file, or not to import specified component to file.
                                                   NULL if using an existing .map file or ignore */
        int numMappingFile;                /**<@brief  number of mapping file. 0 if using an existing .map file or ignore*/
        svxImportIDFFilterData filter;     /**<@brief  filter properties of IDF. */
    } svxImportIDFData;

    /**
    @brief operation type stored in part's history
    @ingroup zwapi_file_data
    */
    typedef enum evxPTSHistoryType
    {
        VX_PTS_HISTORY_SUBPART     = 0, /**<@brief  sub-part */
        VX_PTS_HISTORY_BACKUP      = 1, /**<@brief  backup */
        VX_PTS_HISTORY_ENCAPSULATE = 2, /**<@brief  encapsulate */
        VX_PTS_HISTORY_NOBACKUP    = 3, /**<@brief  no backup */
    } evxPTSHistoryType;

    /**
    @brief setting properties if import points form ASCII file
    @ingroup zwapi_file_data
    */
    typedef struct svxImportPTSData
    {
        vxLongName groupName;      /**<@brief  the group name of points to import (groupName[0] = 0 to import all points) */
        int createPtBlock;         /**<@brief  1 to create point block, else 0. */
        int reducePtSet;           /**<@brief  1 to reduce point set, else 0. */
        int manual;                /**<@brief  method for removing points (1: remove according to the tolerance; 0: automatic; 1 as default) */
        double tolerance;          /**<@brief  tolerance used with the manual method (0.01 as default) */
        evxPTSHistoryType history; /**<@brief  operation type stored in part's history (VX_PTS_HISTORY_NOBACKUP as default) */
    } svxImportPTSData;

    /**
    @brief file import data
    @ingroup zwapi_file_data
    */
    typedef struct svxImportData
    {
        evxImportType type;  /**<@brief  import type */
        vxLongPath filePath; /**<@brief  import file path */
        int importTo;        /**<@brief  0-current object, 1-new object, 2-new file */
        int importTarget;    /**<@brief  0-default, 1-part,2-sheet,3-sketch,
                          if it doesn't need this param, use the default value.*/
        void *reserved;      /**<@brief  reserved for future (should be NULL for API developers currently) */
        void *general;       /**<@brief  setting general properties.NULL to use default.  
                          if the Type is VX_IMPORT_TYPE_UG, the data is svxImportUGData,  
                          if the Type is VX_IMPORT_TYPE_STEP, the data is svxImportSTEPData.  
                          if the Type is VX_IMPORT_TYPE_DWG_DXF, the data is svxImportDwgDxfData.  
                          if the Type is VX_IMPORT_TYPE_STL, the data is svxImportSTLData.  
                          if the Type is VX_IMPORT_PTS_FROM_FILE, the data is svxImportPTSData.  
                          if the Type is VX_IMPORT_TYPE_IDF, the data is svxImportIDFData. */
    } svxImportData;

    /**
    @brief data of export obj file
    @ingroup zwapi_file_data
    */
    typedef struct svxOBJData
    {
        int ExportMaterial;  /**<@brief  whether to export the material file(*.mtl file) (1-default) */
        int OptimizeVertex;  /**<@brief  whether to optimize vertex (1-default) */
        int CopyTextureFile; /**<@brief  whether to export the texture file to output directory (0-default) */
        double ChordHeight;  /**<@brief  chord height tessellation tolerance (0.01-default) */
        int OutputDecimal;   /**<@brief  decimal in *.obj file (4-default) */

        int ExportType; /**<@brief  0-All objects, 1-Specified entities (0-default) */
        int EntCnt;     /**<@brief  the count of export entities if ExportType = 1 */
        int *EntList;   /**<@brief  the specified entities id list if ExportType = 1 */

        int ExcludeGeom; /**<@brief  filter geometry type(only support VX_EXCLUDE_BLANKED),
                                 (default: ExcludeGeom=VX_EXCLUDE_BLANKED)*/
    } svxOBJData;

    /**
    @brief export file type
    @ingroup zwapi_file_data
    */
    typedef enum evxExportType
    {
        VX_EXPORT_TYPE_IMG = 1,     /**<@brief  the data is defined by struct svxImgData */
        VX_EXPORT_TYPE_PDF,         /**<@brief  the data is defined by struct svxPdfData */
        VX_EXPORT_TYPE_GRP,         /**<@brief  the data is defined by struct svxGRPData */
        VX_EXPORT_TYPE_DWG,         /**<@brief  the data is defined by struct svxDWGData */
        VX_EXPORT_TYPE_IGES,        /**<@brief  the data is defined by struct svxIGESData */
        VX_EXPORT_TYPE_STEP,        /**<@brief  the data is defined by struct svxSTEPData */
        VX_EXPORT_TYPE_JT,          /**<@brief  the data is defined by struct svxJTData */
        VX_EXPORT_TYPE_PARA_TEXT,   /**<@brief  the data is defined by struct svxPARAData */
        VX_EXPORT_TYPE_PARA_BINARY, /**<@brief  the data is defined by struct svxPARAData */
        VX_EXPORT_TYPE_CAT5_PART,   /**<@brief  the data is defined by struct svxCAT5Data */
        VX_EXPORT_TYPE_CAT5_ASM,    /**<@brief  the data is defined by struct svxCAT5Data */
        VX_EXPORT_TYPE_HTML,        /**<@brief  the data is defined by struct svxHTMLData */
        VX_EXPORT_TYPE_STL,         /**<@brief  the data is defined by struct svxSTLData */
        VX_EXPORT_TYPE_OBJ,         /**<@brief  the data is defined by struct svxOBJData */
        VX_EXPORT_TYPE_IDF_PART,    /**<@brief  the data is defined by struct svxIDFData */
        VX_EXPORT_TYPE_IDF_ASM,     /**<@brief  the data is defined by struct svxIDFData */

    } evxExportType;

    /**
    @brief export exclude geometry
    @ingroup zwapi_file_data
    */
    typedef enum evxExportExcludeGeom
    {
        VX_EXCLUDE_CURVE   = 0x1,  /**<@brief  exclude curve */
        VX_EXCLUDE_SURFACE = 0x2,  /**<@brief  exclude surface */
        VX_EXCLUDE_SOLID   = 0x4,  /**<@brief  exclude solid */
        VX_EXCLUDE_PLANE   = 0x8,  /**<@brief  exclude plane */
        VX_EXCLUDE_HATCH   = 0x10, /**<@brief  exclude hatch */
        VX_EXCLUDE_DIMEN   = 0x20, /**<@brief  exclude dimen */
        VX_EXCLUDE_TEXT    = 0x40, /**<@brief  exclude text */
        VX_EXCLUDE_BLANKED = 0x80, /**<@brief  exclude blanked */
    } evxExportExcludeGeom;

    /**
    @brief file action type
    @ingroup zwapi_file_data
    */
    typedef enum _evxDocAction
    {
        VX_DOC_CREATED = 0, /**<@brief  called after file created (notify only) */
        VX_DOC_SAVING,      /**<@brief  called before file saving */
        VX_DOC_SAVED,       /**<@brief  called after file saved (notify only) */
        VX_DOC_PRECHANGE,   /**<@brief  called before file tab changes to another one (notify only) */
        VX_DOC_CHANGED,     /**<@brief  called after file tab changed to another one (notify only) */
        VX_DOC_PREOPEN,     /**<@brief  called before file open */
        VX_DOC_OPENED,      /**<@brief  called after file opened (notify only) */
        VX_DOC_TITLEUPDATE, /**<@brief  called before the window title updating after file changed (notify only) */
        VX_DOC_PREMODIFY,   /**<@brief  called before file modifies */
        VX_DOC_MODIFIED,    /**<@brief  called after file modified (notify only) */
    } evxDocAction;

    /**
    @brief file action parameters
    @ingroup zwapi_file_data
    */
    typedef struct svxDocActionParam
    {
        int (*pfn)(void *, const char *, const char *); /**<@brief  callback function. when set a callback for a file action,  
                                                   this parameter should be a valid function pointer, to cancel
                                                   the callback, this parameter should be NULL. */
        void *param;                                    /**<@brief  parameter passed to pfn, if no need to pass parameters,   
                                                it should be NULL */
    } svxDocActionParam;

    /**
    @brief file print format type
    @ingroup zwapi_file_data
    */
    typedef enum evxPrintFormat
    {
        VX_PRINT_FORMAT_HPGL1 = 0, /**<@brief  HP graphics language files */
        VX_PRINT_FORMAT_HPGL2,     /**<@brief  HP graphics language 2 files */
        VX_PRINT_FORMAT_EPS,       /**<@brief  Encapsulated PostScript files */
        VX_PRINT_FORMAT_PS,        /**<@brief  PostScript files */
        VX_PRINT_FORMAT_PCL,       /**<@brief  printer control language files */
        VX_PRINT_FORMAT_TIFF,      /**<@brief  tagged image files */
        VX_PRINT_FORMAT_EMF,       /**<@brief  enhanced metafile file */
        VX_PRINT_FORMAT_BMP,       /**<@brief  bitmap file */
    } evxPrintFormat;

    /**
    @brief file print area type
    @ingroup zwapi_file_data
    */
    typedef enum evxPrintAreaType
    {
        VX_PRINT_AREA_LAYOUT = 0,   /**<@brief  only print the area in the drawing border */
        VX_PRINT_AREA_CUSTOM,       /**<@brief  print the custom area */
        VX_PRINT_AREA_DISPLAY,      /**<@brief  print the display area */
        VX_PRINT_AREA_FIXED_ORIGIN, /**<@brief  select view origin to print */
    } evxPrintAreaType;

    /**
    @brief file print range type
    @ingroup zwapi_file_data
    */
    typedef enum evxPrintRangeType
    {
        VX_PRINT_ALL_SHEET = 0,   /**<@brief  print all sheets */
        VX_PRINT_CURRENT_SHEET,   /**<@brief  print current active sheet */
        VX_PRINT_SPECIFIED_SHEET, /**<@brief  print the specified sheets */
    } evxPrintRangeType;

    /**
    @brief file print color type
    @ingroup zwapi_file_data
    */
    typedef enum evxPrintColorType
    {
        VX_PRINT_COLORED = 0,     /**<@brief  colored */
        VX_PRINT_GRAYSCALE,       /**<@brief  gray scale */
        VX_PRINT_BLACK_AND_WHITE, /**<@brief  black and white */
    } evxPrintColorType;

    /**
    @brief data of file print
    @ingroup zwapi_file_data
    */
    typedef struct svxFilePrintData
    {
        /* print/plotter configuration */
        vxLongPath printerName;     /**<@brief  printer name */
        int printToFile;            /**<@brief  whether to print to a file (0: no; 1: yes) */
        int nCopies;                /**<@brief  the total number of copies that wish to output */
        vxLongPath filePath;        /**<@brief  file name, enter the full file path if printing to a file, and ignore it if printing to a printer */
        evxPrintFormat printFormat; /**<@brief  print file format, used only when printerName is "file" */

        /* paper setting */
        double paperWidth;  /**<@brief  paper width (unit: mm) */
        double paperHeight; /**<@brief  paper height (unit: mm) */

        /* paper margins setting */
        svxRectangle paperMargin; /**<@brief  paper margins (unit: mm) */
        int centerToPrint;        /**<@brief  whether to let the print position as the center */

        /* print area setting */
        evxPrintAreaType areaType; /**<@brief  print area type */
        svxPoint printArea[2];     /**<@brief  the upper left corner and the lower right corner of print area, when areaType is VX_PRINT_AREA_CUSTOM  
                                                       center of print area, when areaType is VX_PRINT_AREA_FIXED_ORIGIN */
        int scaleToFit;            /**<@brief  whether to scale the plot to fit the paper size */
        double scale;              /**<@brief  scale, used only when scaleToFit is 0 */

        /* print range setting, used only for the sheet level */
        evxPrintRangeType rangeType; /**<@brief  print range type */
        int nSheets;                 /**<@brief  number of sheets to print, used only when rangeType is VX_PRINT_SPECIFIED_SHEET */
        int *idSheets;               /**<@brief  list of index of sheets to print, used only when rangeType is VX_PRINT_SPECIFIED_SHEET */

        /* print attributes setting */
        evxPrintColorType colorType; /**<@brief  color type */
        int printBackground;         /**<@brief  whether to print background */
    } svxFilePrintData;

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_FILE_DATA_H */
