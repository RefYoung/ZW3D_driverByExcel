/**
@file zwapi_asm_data.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the functions
for the assembly's objects.
*/
/**
@defgroup zwapi_asm_data Assembly Data
@ingroup AssemblyObjectsModel
@brief
@details THE MODULE FOR THE ZW3D Data Types and Structures of the functions
for the assembly's objects.
*/

#pragma once
#ifndef ZW_API_ASM_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_ASM_DATA_H

#include "zwapi_util.h"
#include "zwapi_cmd_assembly_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Assembly Component Data */
    //====================================================================================================================
    /**
    @brief Reorder location
    @ingroup zwapi_asm_data
    */
    typedef enum evxReorderLoc
    {
        VX_REORDER_FIRST = 0, /**<@brief  insert the object as the first object */
        VX_REORDER_LAST  = 1, /**<@brief  insert the object as the last object */
        VX_REORDER_AFTER = 2, /**<@brief  insert the object after the specified object */
    } evxReorderLoc;

    /**
    @brief level display settings.
    @note In the part environment, 3D BOM supports only managing shape attributes.
    @ingroup zwapi_asm_data
    */
    typedef enum evx3DBomLevelDispMode
    {
        VX_3DBOM_TOP_LEVEL_ONLY = 1, /**<@brief Select this item to display only the top-level components. */
        VX_3DBOM_PARTS_ONLY     = 2, /**<@brief Select this item to display only parts. */
        VX_3DBOM_INDENTED       = 3, /**<@brief Select this item and indent it by assembly level. */
        VX_3DBOM_SHAPE_ONLY     = 4, /**<@brief Select this item to display only the shapes. */
        VX_3DBOM_ALLCOMPONENTS  = 5, /**<@brief Select this item to display all components that belong to the same level. */
    } evx3DBomLevelDispMode;

    /**
    @brief 3D BOM display settings data
    @ingroup zwapi_asm_data
    */
    typedef struct svx3DBomSettingsData
    {
        evx3DBomLevelDispMode mode; /**<@brief display mode */
        int countColumn;            /**<@brief number of columns display */
        struct svxBomColumn
        {
            vxLongName attrName; /**<@brief The name of the column attribute that will be displayed in the 3d bom table. */
            int isCheck;         /**<@brief 1 if set the specified property name to display, else 0 */
            int isTotal;         /**<@brief isTotal indicates whether to select to display totals(1 or 0).default:0. 
                                 Totals are usually displayed only if the content is numeric. */
        } *listColumnData;

    } svx3DBomSettingsData;

    /**
    @brief 3d BOM row data
    @ingroup zwapi_asm_data
    */
    typedef struct svx3DBomData
    {
        int cntRow;        /**<@brief the total number of row in the table. */
        int cntCol;        /**<@brief the total number of column in the table. */
        vxLongName **list; /**<@brief table data. */
    } svx3DBomData;

    /**
    @brief flexible design driven data
    @ingroup zwapi_asm_data
    */
    typedef union uvxFlexbleDrivenData
    {
        int drivenDimId;             /**<@brief idx of dim that you want to set on svxAsmFlexDesignDimData.dimId. */
        double value;                /**<@brief value that you want to set on svxAsmFlexDesignDimData.dimId. */
        vxLongName drivenExpression; /**<@brief name of expression that you want to set on svxAsmFlexDesignDimData.dimId. */
    } uvxFlexbleDrivenData;

    /**
    @brief flexible design driven type
    @ingroup zwapi_asm_data
    */
    typedef enum evxAsmDrivenDataType
    {
        VX_ASM_DRIVEN_DATA_DIMID = 0, /**<@brief id of dimension */
        VX_ASM_DRIVEN_DATA_VALUE,     /**<@brief value. */
        VX_ASM_DRIVEN_DATA_EXPRSSION, /**<@brief expression name. */
    } evxAsmDrivenDataType;

    /**
    @brief flexible design dimension data
    @ingroup zwapi_asm_data
    */
    typedef struct svxAsmFlexDesignDimData
    {
        int dimId;                       /**<@brief idx of dimension you want to change. */
        evxAsmDrivenDataType unionType;  /**<@brief type of driven data. */
        uvxFlexbleDrivenData drivenData; /**<@brief driven data set to dimension. */
    } svxAsmFlexDesignDimData;

    /**
    @brief flexible design expression data
    @ingroup zwapi_asm_data
    */
    typedef struct svxAsmFlexDesignExpressionData
    {
        vxLongName expressionName;       /**<@brief name of expression you want to change. */
        evxAsmDrivenDataType unionType;  /**<@brief type of driven data. */
        uvxFlexbleDrivenData drivenData; /**<@brief driven data set to expression. */
    } svxAsmFlexDesignExpressionData;

    /**
    @brief flexible design data
    @ingroup zwapi_asm_data
    */
    typedef struct svxAsmFlexDesignData
    {
        svxAsmFlexDesignExpressionData *varibaleList; /**<@brief list of variable data. NULL if no expression to set */
        int cntVariable;                              /**<@brief number of variable data. 0 if no expression to set */
        svxAsmFlexDesignDimData *dimList;             /**<@brief list of dimension data. NULL if no dimension to set */
        int cntDim;                                   /**<@brief number of dimension data. 0 if no dimension to set */
    } svxAsmFlexDesignData;

    //====================================================================================================================
    /** @name Assembly operation Data */
    //====================================================================================================================
    /**
    @brief group as sub-assembly data
    @ingroup zwapi_asm_opts_data
    */
    typedef struct svxAsmGrpCompData
    {
        vxPath file;       /**<@brief  the file which the grouped sub-assembly to be created belongs to
                            If isPartOnly = 0, user need to set this parameter. */
        vxRootName part;   /**<@brief  the name of the grouped sub-assembly to be created (part[0]=0 to use default) */
        int isVirtual;     /**<@brief  1-the grouped sub-assembly is virtual assembly, else 0 */
        int isPartOnly;    /**<@brief  1-create part only, 0-create file and part(only use for Z3) */
        int count;         /**<@brief  count of paths */
        svxEntPath *paths; /**<@brief  the components to be grouped */
    } svxAsmGrpCompData;

    /**
    @brief Render mode
    @ingroup zwapi_asm_opts_data
    */
    typedef enum evxRenderMode
    {
        VX_RENDER_NONE        = 0, /**<@brief  no render mode */
        VX_RENDER_WIRE        = 1, /**<@brief  wireframe */
        VX_RENDER_SHADE       = 2, /**<@brief  shaded */
        VX_RENDER_HIDD_APPROX = 3, /**<@brief  hidden line */
        VX_RENDER_ANALYZE     = 4, /**<@brief  analyze */
        VX_RENDER_TRANSPARENT = 9  /**<@brief  transparent */
    } evxRenderMode;

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_ASM_DATA_H */
