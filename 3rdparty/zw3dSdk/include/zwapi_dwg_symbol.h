/**
@file zwapi_dwg_symbol.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Drawing Dimension API
*/
/**
@defgroup zwapi_dwg_symbol Drawing Symbol API
@ingroup DrawingObjectsModel
@brief
@details THE MODULE FOR THE ZW3D Drawing Dimension API
*/

#pragma once
#ifndef ZW_API_DWG_SYMBOL_H /* this ifndef surrounds entire header */
#define ZW_API_DWG_SYMBOL_H

#include "zwapi_dwg_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */


    //====================================================================================================================
    /** @name Symbol Query */
    //====================================================================================================================
    /**
    @ingroup zwapi_dwg_symbol

    Outputs a list of indices of specified type symbol entities
    in the active sheet.

    The calling procedure MUST deallocate the output list.

    @param [in] type symbol object type (VX_SYM_ALL to get all)
    @param [out] Count number of symbol entities
    @param [out] idEnts list of symbol entity id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxShtInqSymbol(evxSymbolType type, int *Count, int **idEnts);

    /**
    @ingroup zwapi_dwg_symbol

    Gets a list of symbol objects.

    @param [in] idSym id of symbol
    @param [out] count count of listId
    @param [out]  listId list of symbol object id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_ERROR
    */
    extern evxErrors cvxDwgInqSymObjList(int idSym, int *count, int **listId);

    /**
    @ingroup zwapi_dwg_symbol

    Get the type(evxSymbolType) of specified symbol.
    It can't get the corresponding type if "*type = VX_SYM_ALL".

    @param [in] idSym the index of symbol
    @param [out] type the type of specified symbol

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxDwgInqSymType(int idSym, evxSymbolType *type);

    /**
    @ingroup zwapi_dwg_symbol

    Outputs the id list of entities associated with the specified symbol.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] idSym index of symbol
    @param [out] Count number of list
    @param [out] idEnts pointer to pointer of entities array

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxDwgInqSymEnts(int idSym, int *Count, int **idEnts);


    //====================================================================================================================
    /** @name Symbol Attribute */
    //====================================================================================================================
    /**
    @ingroup zwapi_dwg_symbol

    Gets the attributes data of specified symbol. the function supports
    the following 4 symbol types: VX_SYM_SURF, VX_SYM_WELD, VX_SYM_BEAD,
    VX_SYM_ENDTRT.

    @param [in] idSym index of symbol
    @param [out] symAttr symbol attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxDwgSymAtGet(int idSym, svxSymAttr *symAttr);

    /**
    @ingroup zwapi_dwg_symbol

    Sets the attributes data of specified symbol. the function supports
    the following 4 symbol types: VX_SYM_SURF, VX_SYM_WELD, VX_SYM_BEAD,
    VX_SYM_ENDTRT.

    @param [in] idSym index of symbol
    @param [in] symAttr symbol attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxDwgSymAtSet(int idSym, svxSymAttr *symAttr);

    /**
    @ingroup zwapi_dwg_symbol

    Gets the symbol image data of specified image.

    @param [in] idSymImg image id
    @param [out] data image data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxDwgSymImgAtGet(int idSymImg, svxSymImg *data);

    /**
    @ingroup zwapi_dwg_symbol

    Sets the symbol image data of specified image.

    @param [in] idSymImg image id
    @param [in] data image data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxDwgSymImgAtSet(int idSymImg, const svxSymImg *data);


    //====================================================================================================================
    /** @name Symbol Data */
    //====================================================================================================================
    /**
    @ingroup zwapi_dwg_symbol

    Get the surface roughness data of specified symbol.

    @param [in] idSymSurf symbol id
    @param [out] data surface roughness data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxDwgSymSurfDataGet(int idSymSurf, svxSymSurf *data);

    /**
    @ingroup zwapi_dwg_symbol

    Set the surface roughness data of specified symbol.

    @param [in] idSymSurf symbol id
    @param [in] data surface roughness data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_MEMORY_EROR
    */
    extern evxErrors cvxDwgSymSurfDataSet(int idSymSurf, svxSymSurf *data);

    /**
    @ingroup zwapi_dwg_symbol

    Get the weld data of special symbol.

    This function allocates memory for "jogPoints" and "leaderPoints"
    in svxSymWeld struct. The memory MUST be deallocated by the calling
    procedure using cvxSymWeldFree().

    @param [in] idSymWeld symbol id
    @param [out] data weld data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxDwgSymWeldDataGet(const int idSymWeld, svxSymWeld *data);

    /**
    @ingroup zwapi_dwg_symbol

    Set the weld data of special symbol.

    @param [in] idSymWeld symbol id
    @param [in] data weld data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxDwgSymWeldDataSet(const int idSymWeld, const svxSymWeld *data);

    /**
    @ingroup zwapi_dwg_symbol

    Frees memory associated with the specified weld structure.

    @param [in] WeldData weld data structure

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxSymWeldFree(svxSymWeld *WeldData);

    /**
    @ingroup zwapi_dwg_symbol

    Get a list of indices of the  objects in the  User Symbol.

    This function allocates memory for "list".  The calling procedure is
    responsible for deallocating the memory.

    @param [in] idSymUser id of user symbol
    @param [out] nObj number of objects in group
    @param [out] idObjs list of object indices

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_aPI_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxDwgUserSymObjGet(const int idSymUser, int *nObj, int **idObjs);

    /**
    @ingroup zwapi_dwg_symbol

    Get the insertion position of the symbol.

    @param [in] idSym id of symbol
    @param [out] pnt symbol insertion point

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_eRROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxDwgSymInsPointGet(int idSym, svxPoint2 *pnt);

    /**
    @ingroup zwapi_dwg_symbol

    Set the insertion position of the symbol.

    @note
    Because this function has an internal call to the "cvxDispRedraw()" function,
    it must be called on the main thread.

    @param [in] idSym id of symbol
    @param [in] pnt symbol insertion point

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxDwgSymInsPointSet(int idSym, svxPoint2 *pnt);

    /**
    @ingroup zwapi_dwg_symbol

    Get the linked file path with special symbol.

    @param [in] idSymLink index of OLE object symbol
    @param [out] filePath the linked file path with symbol

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_PATH
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxDwgSymLinkGet(const int idSymLink, vxPath filePath);

    /**
    @ingroup zwapi_dwg_symbol

    Get the linked file path with special symbol.

    A filePath that is too long (longer than "sizePath") is truncated.

    It is assumed that the input "filePath" is no longer than 512 bytes.

    @param [in] idSymLink index of OLE object symbol
    @param [out] filePath the linked file path with symbol
    @param [in] sizePath max size of filePath

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_PATH
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxDwgSymLinkGetByLongPath(const int idSymLink, char *filePath, int sizePath);

    /**
    @ingroup zwapi_dwg_symbol

    Export embedded file from symbol openLink object to specified path.
    if only the export path is specified, the file uses the original
    file name.

    @param [in] idSymLink the index of symbol openLink object
    @param [in,out] filePath path of export file

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_PATH
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxDwgSymLinkExport(const int idSymLink, vxPath filePath);
    /**
    @ingroup zwapi_dwg_symbol

    Export embedded file from symbol openLink object to specified path.
    if only the export path is specified, the file uses the original
    file name.

    A filePath that is too long (longer than "sizePath") is truncated.

    It is assumed that the input "Path" is no longer than 512 bytes.

    @param [in] idSymLink the index of symbol openLink object
    @param [in,out] filePath path of export file
    @param [in] sizePath max size of filePath

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_PATH
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxDwgSymLinkExportByLongPath(const int idSymLink, char *filePath, int sizePath);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_DWG_SYMBOL_H */
