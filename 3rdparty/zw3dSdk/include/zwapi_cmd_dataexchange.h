/**
@file zwapi_cmd_dataexchange.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Exchange Command API
*/
/**
@defgroup zwapi_cmd_dataexchange Data Exchange Commands
@ingroup PartandAssemblyCommands
@brief
@details THE MODULE FOR THE ZW3D Data Exchange Command API
*/

#pragma once
#ifndef ZW_API_DATA_EXCHANGE_FTR_H /* this ifndef surrounds entire header */
#define ZW_API_DATA_EXCHANGE_FTR_H

#include "zwapi_cmd_dataexchange_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Import */
    //====================================================================================================================
    /**********************************************************************
    *! -Import- : zwapi_file.h
    *  extern evxErrors cvxFileImportInit(svxImportData* data, evxImportType type, void* general);
    *  extern evxErrors cvxFileImport(svxImportData* importData);
    **********************************************************************/
    /**********************************************************************
    *! -Multi-Import- : zwapi_file.h
    *  extern evxErrors cvxFileImportMulti(int Count, const vxLongName* PathList, int SubFolder, const vxPath SavePath, evxImportType Type, const void* Setting);
    **********************************************************************/
    /**
    @ingroup zwapi_cmd_dataexchange

    Creates a copy of the specified external geometry (face, shape, curve or edge) in the active
    target part. The input pick-path must give the full traversal path to the external geometry
    relative to the top-level part of the parent assembly of the active target part. The id of
    the new geometry created in the active part is output via "idGeom".

    @param [in] GeomPath pick-path of external geometry relative to top-level parent file
    @param [in] AssociativeCopy 0 for static copy;   
                                1 for associative copy;   
                                2 for time-stamped associative copy;   
                                3 for time-stamped associative copy - assembly position independent.
    @param [out] idGeom id of new geometry (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartRefGeom(svxEntPath *GeomPath, int AssociativeCopy, int *idGeom);

    /**
    @ingroup zwapi_cmd_dataexchange

    Use the function to create a publication set to publish the specified entity.

    @see cvxPartInqPublishSets(): get a list of indices of the publication set.
    @see cvxPartInqPublishSet(): query data of the specified publication set.
    @see cvxPartPublishSetDel(): delete the specified publication sets.

    @param [in] Name name of publication set (NULL to use default name)
    @param [in] Count number of entities to publish
    @param [in] idEnts list of entity ids to publish (shape, face, edge, curve, point, sketch, datum plane, datum axis, datum CSYS)
    @param [out] idPubSet id of new publication set (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartPublishSet(const vxName Name, int Count, const int *idEnts, int *idPubSet);

    //====================================================================================================================
    /** @name Export */
    //====================================================================================================================
/**********************************************************************
*! -Import- : zwapi_file.h
*  extern evxErrors cvxFileExportInit(evxExportType type, int imgType, void* data);
*  extern evxErrors cvxFileExport(evxExportType Type, vxPath Path, void* Data);
**********************************************************************/
/**********************************************************************
*! -Import- : zwapi_file.h
*  extern evxErrors cvxFileExportMulti(int Count, const vxLongName* FileList, evxFileType Filter, evxExportType Type, const vxPath Path, void* Data);
**********************************************************************/

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef V_VXAPILOC_H
#include "api/inc/VxApiLoc.h"
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_DATA_EXCHANGE_FTR_H */
