/**
@file zwapi_layer.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D  Layer API
*/
/**
@defgroup zwapi_layer Layer
@ingroup CommonModel
@brief
@details THE MODULE FOR THE ZW3D  Layer API
*/

#pragma once
#ifndef ZW_API_LAYER_H /* this ifndef surrounds entire header */
#define ZW_API_LAYER_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Layer Info Data */
    //====================================================================================================================
    /**
    @brief layer mask information
    @ingroup zwapi_layer
    */
    typedef enum evxInfoLayerFlag
    {
        VX_LAYER_INFOR_NAME      = 0x00000001,  /**<@brief  find layer name */
        VX_LAYER_INFOR_DESC      = 0x00000002,  /**<@brief  find layer description */
        VX_LAYER_INFOR_ID        = 0x00000004,  /**<@brief  find layer id */
        VX_LAYER_INFOR_VISIBLE   = 0x00000008,  /**<@brief  find layer visible */
        VX_LAYER_INFOR_FREEZE    = 0x000000010, /**<@brief  find layer freeze */
        VX_LAYER_INFOR_DISABLE   = 0x00000020,  /**<@brief  find layer disable */
        VX_LAYER_INFOR_COLOR     = 0x00000040,  /**<@brief  find layer color */
        VX_LAYER_INFOR_LINETYPE  = 0x00000080,  /**<@brief  find layer linetype */
        VX_LAYER_INFOR_LINEWIDTH = 0x0000100,   /**<@brief  find layer linewidth */
        VX_LAYER_INFOR_NUMOBJ    = 0x0000200,   /**<@brief  find layer numble object */
        VX_LAYER_INFOR_FLTR      = 0x0000400,   /**<@brief  find layer filter info */
        VX_LAYER_INFOR_ALL       = 0xFFFFFFFF,  /**<@brief  find layer all info */
    } evxInfoLayerFlag;

    /**
    @brief layer information
    @ingroup zwapi_layer
    */
    typedef struct svxLayerInfo
    {
        int mask;                 /**<@brief  obtain specified information from mask (evxInfoLayerFlag).
                               obtain sName and sDesc infos if mask = VX_LAYER_INFOR_NAME|VX_LAYER_INFOR_DESC */
        char sName[32];           /**<@brief  layer name */
        char sDesc[512];          /**<@brief  layer description */
        unsigned char uLayerId;   /**<@brief  layer id */
        unsigned char uVisible;   /**<@brief  layer visible */
        unsigned char uFrozen;    /**<@brief  layer freeze */
        unsigned char uDisable;   /**<@brief  layer disable */
        unsigned char uColor;     /**<@brief  layer color */
        unsigned char uLineType;  /**<@brief  layer linetype */
        unsigned char ulineWidth; /**<@brief  layer linewidth */
        char category[512];       /**<@brief  category, like this CURVES;SHEETS */
        int iNumObj;              /**<@brief  layer number object */
    } svxLayerInfo;

    //====================================================================================================================
    /** @name Layer Operation */
    //====================================================================================================================
    /**
    @ingroup zwapi_layer

    Creates a new layer with the specified name.

    @param [in] Name layer name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OBJ
    */
    extern evxErrors cvxLayerAdd(char *Name);

    /**
    @ingroup zwapi_layer

    Create a layer entity with layer info.

    @param [in] psLayerInfo layer info
    @param [out] Number layer number (0-255)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxLayerAdd2(const svxLayerInfo *psLayerInfo, int *Number);

    /**
    @ingroup zwapi_layer

    Deletes the specified layer.

    @param [in] Name layer name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OBJ
    */
    extern evxErrors cvxLayerDel(vxName Name);

    /**
    @ingroup zwapi_layer

    Delete a layer.

    @param [in] Number layer number (0-255)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    */
    extern evxErrors cvxLayerDel2(int Number);

    /**
    @ingroup zwapi_layer

    Activates the specified layer so that newly-created entities are
    automatically assigned to it.

    @param [in] Name layer name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OBJ
    */
    extern evxErrors cvxLayerActivate(vxName Name);

    /**
    @ingroup zwapi_layer

    Synchronizes entity visibility with layer visibility.


    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxLayerSync(void);

    /**
    @ingroup zwapi_layer

    Makes all layers visible.


    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxLayerShowAll(void);

    /**
    @ingroup zwapi_layer

    Modify the layer id of layer and related objects, source
    layer id and target layer id must be 0-255.

    @note
    The function does not allow layer id 0 to be modified.

    @param [in] srcNumber  source layer id
    @param [in] tarNumber  target layer id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxLayerIdModify(int srcNumber, int tarNumber);


    //====================================================================================================================
    /** @name Layer Query/Set */
    //====================================================================================================================
    /**
    @ingroup zwapi_layer

    Outputs the name of the active layer.

    @param [out] Name active layer name

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern void cvxLayerInqActive(vxName Name);

    /**
    @ingroup zwapi_layer

    Determine whether the layer exists in the active target object by name.

    @param [in] Name layer name

    @retval succeeds
    -        1 - the layer exists in the active target object
    -        0 - it does not exist or function fails
    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    extern int cvxLayerExists(vxName Name);

    /**
    @ingroup zwapi_layer

    The number(layer id) must be 0-255.

    @param [in] Number layer id

    @retval succeeds
    -        1 - the layer exists in the active target object
    -        0 - it does not exist or function fails
    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern int cvxLayerExists2(int Number);

    /**
    @ingroup zwapi_layer

    Output the layer id of a specified name.

    @param [in] name name
    @param [out] id layer id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxLayerId(vxName name, int *id);

    /**
    @ingroup zwapi_layer

    Get all entities on the specified layer.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] Number layer number (0-255)
    @param [out] numEnt no. of entities on the specified layer
    @param [out] Paths pick-path list of entities on the specified layer

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxLayerInqEnts(int Number, int *numEnt, svxEntPath **Paths);

    /**
    @ingroup zwapi_layer

    Assigns the specified entities to the specified layer.

    @param [in] Name layer name
    @param [in] numEnt no. of entities to assign to layer
    @param [in] idEnts list of id's of entities to assign to layer

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OBJ
    */
    extern evxErrors cvxLayerAssign(char *Name, int numEnt, int *idEnts);

    /**
    @ingroup zwapi_layer

    Outputs a list of all layers in the active part or sheet.  
    The calling procedure must deallocate the output list.

    @param [out] Count layer count
    @param [out] Names list of layers

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxLayerList(int *Count, vxName **Names);

    /**
    @ingroup zwapi_layer

    Outputs the name of the layer with the specified number.

    @param [in] Number layer number (0-255)
    @param [out] Name layer name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_OBJ
    */
    extern evxErrors cvxLayerName(int Number, vxName Name);

    /**
    @ingroup zwapi_layer

    Outputs the number of the layer with the specified name.
    Outputs "Number = -1" if the layer is not found.

    @param [in] Name layer name
    @param [out] Number layer number (0-255)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_OBJ
    */
    extern evxErrors cvxLayerNum(vxName Name, int *Number);

    /**
    @ingroup zwapi_layer

    Get all categories in layer manager.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [out] numCate number of categories
    @param [out]  categories name of categories

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxLayerGetAllCategory(int *numCate, vxLongName **categories);

    /**
    @ingroup zwapi_layer

    Get the activate layer number.

    @param [out] Number layer number (0-255)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxActiveLayerNumGet(int *Number);

    /**
    @ingroup zwapi_layer

    Set the activate layer.

    @param [in] Number layer number (0-255)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxActiveLayerNumSet(int Number);

    /**
    @ingroup zwapi_layer

    Gets the state of the specified layer.

    @param [in] Name layer name
    @param [out] isVisible 1 = visible; 0 = blanked
    @param [out] isFrozen 1 = frozen, 0 = not frozen

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_OBJ
    */
    extern evxErrors cvxLayerStateGet(vxName Name, int *isVisible, int *isFrozen);

    /**
    @ingroup zwapi_layer

    Sets the state of the specified layer.

    The input argument "isFrozen" can be overloaded (set it to -2) to
    prevent this function from logging a "LayerState" history operation
    to record a change in layer visibility if a part is active.   
    In this case, the frozen status of the specified layer remains the same.

    @note
    Some history and entity selection operations are only
    applied to visible entities, so be careful using "isFrozen = -2".  
    This function will redraw the screen, if you will call this function many times,
    you can call cvxDispState() to disable the display and update the display later.
    @code
      vxDispState state ={};
      cvxDispState(0, state);
      for(;;) cvxLayerStateSet();
      cvxDispState(2, state);
    @endcode


    @param [in] Name layer name
    @param [in] isVisible 1 = visible, 0 = blanked, -1 = leave the same
    @param [in] isFrozen 1 = frozen, 0 = not frozen, -1 = leave the same

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OBJ
    */
    extern evxErrors cvxLayerStateSet(vxName Name, int isVisible, int isFrozen);


    //====================================================================================================================
    /** @name Layer Information */
    //====================================================================================================================
    /**
    @ingroup zwapi_layer

    Get the layer info.

    You should initialze the 'mask' of 'pLayerInfo' to get the specified information of
    the input layer. If pLayerInfo->mask = 0, it will be set to VX_LAYER_INFOR_ALL in this
    function to get all information.

    @param [in] Number layer number (0-255)
    @param [in,out] pLayerInfo layer info

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxLayerInfoGet(int Number, svxLayerInfo *pLayerInfo);

    /**
    @ingroup zwapi_layer

    Set the layer info.

    @note This function will redraw the screen, if you will call this function many times,
    you can call cvxDispState() to disable the display and update the display later.
    @code
      vxDispState state ={};
      cvxDispState(0, state);
      for(;;) cvxLayerInfoSet();
      cvxDispState(2, state);
    @endcode

    @param [in] Number layer number (0-255)
    @param [in] pLayerInfo layer info

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxLayerInfoSet(int Number, const svxLayerInfo *pLayerInfo);

    /**
    @ingroup zwapi_layer

    Export layers information to specified file.

    @param [in] file export target file full path with extension "zwlyr"

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxLayerInfoExport(const vxLongPath file);

    /**
    @ingroup zwapi_layer

    Import layers information from specified file.

    @param [in] file import target file full path with extension "zwlyr"
    @param [in] overWrite 1 to overwrite existing layers; 0 to append existing layers

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxLayerInfoImport(const vxLongPath file, int overWrite);

    /**
    @ingroup zwapi_layer

    Refreshes display of the layer manager form.
    */
    extern void cvxLayerRefresh();

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_LAYER_H */
