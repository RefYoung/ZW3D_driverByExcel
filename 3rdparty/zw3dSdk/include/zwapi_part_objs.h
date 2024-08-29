/**
@file zwapi_part_objs.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Part Objects Query API
*/
/**
@defgroup zwapi_part_objs Part Objects API
@ingroup PartObjectsModel
@brief
@details THE MODULE FOR THE ZW3D Part Objects Query API
*/

#pragma once
#ifndef ZW_API_PART_OBJ_QUERY /* this ifndef surrounds entire header */
#define ZW_API_PART_OBJ_QUERY

#include "zwapi_part_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Curve */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_objs

    Outputs a list of indices of the curves that belong to  
    the active part.  The calling procedure MUST deallocate  
    the output list with cvxMemFree().

    @param [out] Count number of curves
    @param [out] Curves list of curve id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxPartInqCurves(int *Count, int **Curves);

    /**
    @ingroup zwapi_part_objs

    Outputs a list of indices of the curve list that belong to  
    the active part.  The calling procedure MUST deallocate  
    the output list with cvxMemFree().

    @param [out] Count number of curves
    @param [out] CrvLists list of curve list id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxPartInqCrvLists(int *Count, int **CrvLists);

    /**
    @ingroup zwapi_part_objs

    Outputs a list of the curve or edge entities referenced by the  
    specified curve-list entity within the active part. The curve  
    references are output using the "svxEntPick" data structure  
    so that parent sketches can be identified for sketch curves  
    instanced by the curve list.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] idCrvList id of curve-list entity in active part
    @param [out] Count number of curves (0 if there are no curves)
    @param [out] Curves list of curves (NULL if there are no curves)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartInqCrvList(int idCrvList, int *Count, svxEntPick **Curves);

    /**
    @ingroup zwapi_part_objs

    Gets curve geometry for the specified curvilinear entity, including  
    face edges.  If "Nurb" is input as 1, NURBS data is output for  
    analytic curve types (e.g. line, arc, circle).  NURBS data is output  
    via "Crv" using memory allocated by this function.  The memory MUST  
    be deallocated by the calling procedure using cvxCurveFree().  It  
    is assumed the curve geometry resides in the active part.

    @param [in] idEntity id of curvilinear entity (includes edges)
    @param [in] Nurb 1=get NURBS data for all curve types; else 0
    @param [out] Crv curve data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartInqCurve(int idEntity, int Nurb, svxCurve *Crv);

    /**
    @ingroup zwapi_part_objs

    Frees memory associated with the specified curve structure.

    @param [in] Crv curve structure

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxCurveFree(svxCurve *Crv);


    //====================================================================================================================
    /** @name Point */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_objs

    Outputs a list of indices of point objects that belong to  
    the active part.  The calling procedure MUST deallocate the  
    output list with cvxMemFree().

    @param [out] count number of points
    @param [out] pointIdx list of points' indices

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxPartInqPoints(int *count, int **pointIdx);


    //====================================================================================================================
    /** @name Text Query */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_objs

    Outputs a list of indices of the text that belong to  
    the active part.  The calling procedure MUST deallocate  
    the output list with cvxMemFree().

    @note
    See cvxPartInqTexts() to get both annotation text and balloon text entities.

    @param [out] Count number of curves
    @param [out] Texts list of text id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxPartInqAnnoTexts(int *Count, int **Texts);

    /**
    @ingroup zwapi_part_objs

    Outputs a list of id of the text that belong to the active part,  
    including annotation, balloon, normal, bit-mapped and ready type.  
    The calling procedure MUST deallocate the output list with cvxMemFree.

    @note
    See cvxPartInqAnnoTexts() for a similar function that collects only annotation text entities.

    @param [out] count number of texts
    @param [out] idTexts list of text id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxPartInqTexts(int *count, int **idTexts);

    //====================================================================================================================
    /** @name Other Objects */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_objs

    Outputs a list of indices of the constraints in the specified component.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] File object file name (File[0]=0 or NULL for active file)
    @param [in] Part root object name (Part[0]=0 or NULL for active target object)
    @param [out] count number of constraints
    @param [out] cons list of constraint ids

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_FILE_LOCATE_FAIL
    */
    extern evxErrors cvxPartInqConstraints(const vxLongPath File, const vxRootName Part, int *count, int **cons);

    /**
    @ingroup zwapi_part_objs

    Get the temp data of the specified part or active part.  
    Such as the curves' id of the Section View.

    The memory referenced by "datas" is allocated by this function.  
    The calling procedure is responsible to free it (cvxMemFree((void**)datas)).

    @param [in] idPart part id (-1 to use the active part)
    @param [out] count count of datas
    @param [out]  datas temp datas

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_YPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartInqTempData(int idPart, int *count, int **datas);

    //====================================================================================================================
    /** @name Publish Set */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_objs

    Outputs a list of indices of the publication set in the specified part.  
    The calling procedure MUST deallocate the output list with cvxMemFree().

    If the specified file is not already open, this function will open it  
    to query publish sets, and will then close the file.  If you want to  
    keep the file open, use the cvxFileKeep function, before calling this  
    function, to set a flag that prevents this function from closing the  
    files that it opens.  (Files that are already open before this function  
    is called are never closed by this function.)  If you will be calling  
    several functions to access data in the same file, keeping the file open  
    between calls is more efficient than letting each function open and close  
    the file.  However, you must remember to call cvxFileKeep again to reset  
    the flag after you have finished all of the function calls that need to  
    access the specified file, and you also become responsible for closing the  
    file, for example by using one of the cvxFileClose or cvxFileSave functions.

    @see cvxPartPublishSet(): create a publication set to publish the specified entities.
    @see cvxPartInqPublishSet(): query data of the specified publication set.
    @see cvxPartPublishSetDel(): delete the specified publication sets.

    @param [in] File file name (File[0]=0 or NULL for active file)
    @param [in] Part root object name (Part[0]=0 or NULL for active target object or single object file)
    @param [out] Count number of publication sets
    @param [out] idPubSets list of publication set ids

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_FILE_LOCATE_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartInqPublishSets(const vxLongPath File, const vxRootName Part, int *Count, int **idPubSets);

    /**
    @ingroup zwapi_part_objs

    Query data of the specified publication set in the specified part.  
    The calling procedure MUST deallocate the output list with cvxMemFree().

    If the specified file is not already open, this function will open it  
    to query publish sets, and will then close the file.  If you want to  
    keep the file open, use the cvxFileKeep function, before calling this  
    function, to set a flag that prevents this function from closing the  
    files that it opens.  (Files that are already open before this function  
    is called are never closed by this function.)  If you will be calling  
    several functions to access data in the same file, keeping the file open  
    between calls is more efficient than letting each function open and close  
    the file.  However, you must remember to call cvxFileKeep again to reset  
    the flag after you have finished all of the function calls that need to  
    access the specified file, and you also become responsible for closing the  
    file, for example by using one of the cvxFileClose or cvxFileSave functions.

    @see cvxPartPublishSet(): create a publication set to publish the specified entities.
    @see cvxPartInqPublishSets(): get a list of indices of the publication set.
    @see cvxPartPublishSetDel(): delete the specified publication sets.

    @param [in] File file name (File[0]=0 or NULL for active file)
    @param [in] Part root object name (Part[0]=0 or NULL for active target object or single object file)
    @param [in] idPubSet id of publication set to query
    @param [out] Name name of publication set (NULL to ignore)
    @param [out] Count number of entities published by publication set (NULL to ignore)
    @param [out] idEnts list of ids of the entities published by publication set (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_FILE_LOCATE_FAIL
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartInqPublishSet(const vxLongPath File, const vxRootName Part, int idPubSet, vxName Name, int *Count, int **idEnts);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_PART_OBJ_QUERY */
