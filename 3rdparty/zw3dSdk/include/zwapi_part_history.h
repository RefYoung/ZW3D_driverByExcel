/**
@file zwapi_part_history.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Part History Object API
*/
/**
@defgroup zwapi_part_history History API
@ingroup PartObjectsModel
@brief
@details THE MODULE FOR THE ZW3D Part History Object API
*/

#pragma once
#ifndef ZW_API_HISTORY_H /* this ifndef surrounds entire header */
#define ZW_API_HISTORY_H

#include "zwapi_part_data.h"


#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
    //====================================================================================================================
    /** @name History Regeneration */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_history

    Determine whether a part is currently regenerating.


    @retval return
    -       1 - if a part feature is currently regenerating.
    -       0 - Otherwise .
    */
    extern int cvxPartRegenIsActive(void);

    /**
    @ingroup zwapi_part_history

    Determine whether a part is currently being redefined.


    @retval return
    -       1 - if a part feature is currently being redefined.
    -       0 - Otherwise.
    */
    extern int cvxPartRedefineIsActive(void);

    /**
    @ingroup zwapi_part_history

    Regenerates triangle facet data used to display the specified faces (Count and idFaces).

    If no faces are specified (Count=0 and idFaces=NULL), all faces in the active part are  
    re-tessellated at the specified tolerance (Tol).  If "Assembly != 0", all faces in the
    active assembly are re-tessellated.

    If "Tol" is input as zero, a tolerance based on the active view extent is used.

    If "LOD != 0", levels of detail are calculated for faces that are retessellated. That  
    means that facet data is generated at a tight tolerance, then organized into several  
    levels of detail from coarse to fine. Level-of-Detail generates more data for each  
    face, but the speed and quality of face display can be optimized based on the size  
    of a face relative to the active view extent.

    @param [in] Count number of faces
    @param [in] idFaces list of face id's in active part
    @param [in] Assembly 1 to regenerate facets for active assembly, else 0
    @param [in] LOD 1 to generate level-of-detail, else 0
    @param [in] Tol chord-height tolerance for facet generation (0.0 for default)

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
    extern evxErrors cvxPartRegenFacets(int Count, int *idFaces, int Assembly, int LOD, double Tol);

    /**
    @ingroup zwapi_part_history

    Passing 1 to this function disables the prompt for partial fillet results and  
    causes a failed fillet to exit rather than attempt to generate partial results.

    Passing 0 to this function re-enables the prompt for partial fillet results.

    This function MUST be called in pairs, first with "iDisable=1", then with  
    "iDisable=0".  Otherwise partial results could become permanently disabled  
    during the active session.

    @param [in] Disable 1 to disable partial results, 0 to re-enable it

    */
    extern void cvxPartPartialResults(int Disable);


    //====================================================================================================================
    /** @name History Query */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_history

    Gets a list of history operations in the active part as specified by the
    input "Option".

    The memory referenced by "HistList" is allocated by this function.  
    The calling procedure is responsible to free it (cvxMemFree((void**)HistList)).

    @param [in] Option Option=0 : get history operations that have been played  
                       Option=1 : get history operations that have not been played  
                       Option=2 : get played and unplayed history operations
    @param [out] Cnts number of history operations
    @param [out] HistList list of history operations

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartHistList(int Option, int *Cnts, int **HistList);

    /**
    @ingroup zwapi_part_history

    Outputs a list of database id's of features in the active part's history in the order they are
    listed there (including hidden operations).Operations that are not of feature type will not included
    in the list, such as coordinate system. If there are no features, "*Count" is output as zero and 
    "*Features" as NULL.

    This function allocates memory for the array output via "Features". The calling  
    procedure is responsible for deallocating the memory.

    @param [out] Count number of features in the active part
    @param [out] Features list of database id's of features in the active part's history(including hidden operations)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartInqFtrList(int *Count, int **Features);


    //====================================================================================================================
    /** @name Feature Query */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_history

    Determine whether the feature is a sub-part.

    @param [in] idFtr feature id

    @retval return
    -        1 - the feature is sub-part
    -        0 - the feature is not sub-part
    @retval fail
    -       -1 - function fails
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern int cvxFtrIsSubPart(int idFtr);

    /**
    @ingroup zwapi_part_history

    Determines whether a reference feature has lost external references.

    @param [in] idFeature reference feature id
    @param [out] status feature status. 1 is miss reference, 0 is no miss reference.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    @retval other
    -       -1 - idFeature is not a external reference feature
    */
    extern int cvxPartFtrIsMissRef(int idFeature, char *status);

    /**
    @ingroup zwapi_part_history

    Get information about the source file associated with the specified  
    external reference feature, including file name, root name.

    @param [in] idFeature index of external feature in active part
    @param [out] file associated external file name (NULL to ignore)
    @param [out] part associated external root name (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        Zw_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OUT+OF_RANGE
    @retval other
    -       -1 - feature is not an external reference feature
    */
    extern int cvxPartInqFtrAssoPart(int idFeature, vxPath file, vxRootName rootName);

    /**
    @ingroup zwapi_part_history

    Get information about the source file associated with the specified
    external reference feature, including file name, root name.

    A file that is too long (longer than "sizeFile") is truncated.
    A rootName that is too long (longer than "sizeRName") is truncated.

    It is assumed that the input "file" is no longer than 512 bytes.
    It is assumed that the input "rootName" is no longer than 256 bytes.

    @param [in] idFeature index of external feature in active part
    @param [out] fileName associated external file name (NULL to ignore)
    @param [in] sizePath max size of fileName
    @param [out] rootName associated external root name (NULL to ignore)
    @param [in] sizeRName max size of rootName

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        Zw_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OUT+OF_RANGE
    @retval other
    -       -1 - feature is not an external reference feature
    */
    extern int cvxPartInqFtrAssoPartByLongPath(int idFeature, char *file, int sizeFile, char *rootName, int sizeRName);

    /**
    @ingroup zwapi_part_history

    Outputs the id of a copy of the specified feature's data container.  
    The calling procedure MUST deallocate "idData" using cvxDataFree()  
    after it is done querying "idData" with the cvxDataXXX() functions.  

    The data associated with a feature is stored in a "persistent" format.  
    Entity references in the data are stored in a format that uses entity  
    labels that were current at the time the feature operation was executed.  
    Before the data can be queried for current entity id's, it must be  
    re-evaluated.  This can fail if it references entities that no longer  
    exist.  Point selections that reference entities (e.g. entity endpoint)  
    can also fail to re-evaluate if the referenced entities no longer exist.

    Re-evaluation of the feature data is done without rolling the history  
    back to the specified feature.  For this reason, the success or failure  
    of this function is very sensitive to whether the current state of the  
    model contains all of the geometry that existed at the time that the  
    feature was originally executed.

    If you know that the feature data will not re-evaluate based on the  
    current state of the model, you can get the last evaluated state of  
    point and numeric inputs by calling this function with "iNoEval=1".  
    In this case, you will not be able to successfully query any entity  
    data fields in "idData".

    @param [in] idFeature feature id
    @param [in] iNoEval 1 to get unevaluated data; else 0
    @param [out] idData id of feature data container

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    @retval other
    -       -1 - feature data is undefined
    */
    extern int cvxPartInqFtrData(int idFeature, int iNoEval, int *idData);

    /**
    @ingroup zwapi_part_history

    Gets a list of auxiliary features for the specified feature.

    The memory referenced by "idAuxFtrs" is allocated by this function.  
    The calling procedure is responsible to free it (cvxMemFree((void**)idAuxFtrs)).

    @param [in] idFtr id feature
    @param [out] count count of idAuxFtrs
    @param [out] idAuxFtrs list of auxiliary feature id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    @retval other
    -       -1 - not found auxiliary feature
    */
    extern int cvxPartFtrInqAuxFtrs(int idFtr, int *count, int **idAuxFtrs);

    /**
    @ingroup zwapi_part_history

    Outputs the name of the command template that defines the input  
    parameters of the specified feature.

    @param [in] idFeature feature id
    @param [out] Template feature command template name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxPartInqFtrTemplate(int idFeature, vxName Template);

    /**
    @ingroup zwapi_part_history

    Outputs tolerance used by the specified feature.

    @param [in] idFeature feature id
    @param [out] Tolerance feature tolerance

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxPartInqFtrTol(int idFeature, double *Tolerance);

    /**
    @ingroup zwapi_part_history

    Outputs the regen state of a feature.  
    Judge the suppression state of the feature.

    @note
    The functions of cvxPartInqFtrRegenStat() interface and cvxPartInqFtrRegenStatus()  
    interface are completely different.

    @param [in] idFeature feature index
    @param [out] stat feature regen status as below:  
                      0, regen the feature without suppression  
                      1, feature is manually suppressed  
                      2, feature is automatically suppressed due to the failure of regen  
                      4, feature have suppress condition

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartInqFtrRegenStat(int idFeature, char *stat);

    /**
    @ingroup zwapi_part_history

    Get the missing state or constraint state of the feature.

    @note
    The functions of cvxPartInqFtrRegenStat() interface and cvxPartInqFtrRegenStatus()
    interface are completely different.

    @param [in] idFtr feature index
    @param [out] status feature regen status

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartInqFtrRegenStatus(int idFtr, evxFtrRegenStatus *status);

    /**
    @ingroup zwapi_part_history

    Outputs the product version number associated with the specified  
    feature.  If "idFeature < 1", outputs the version number of the  
    "active" feature (i.e. the feature currently regenerating).

    @param [in] idFeature feature id
    @param [out] Version feature version number

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxPartInqFtrVersion(int idFeature, int *Version);

    /**
    @ingroup zwapi_part_history

    Output the index of the feature group where the specified  
    feature is located.  Output -1 if the specified feature is not  
    in any feature group.

    @param [in] idFeature feature id
    @param [out] idGroup feature group id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxPartInqFtrGroup(int idFeature, int *idGroup);


    //====================================================================================================================
    /** @name Group Features */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_history

    Output all feature_id within the specified feature group.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] idGroup feature group id
    @param [out] count number of elements in the Feature list
    @param [out]  ftrList list of feature id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartInqGroupFtrs(int idGroup, int *count, int **ftrList);

    /**
    @ingroup zwapi_part_history

    Outputs a list of database id's of feature groups in the active part's history  
    in the order they are listed there. If there are no groups,  
    "*count" is output as zero and "*groups" as NULL.

    This function allocates memory for the array output via "groups". The calling  
    procedure is responsible for deallocating the memory.

    @param [out] count number of features in the active part
    @param [out]  groups list of id's of groups in the active part history

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartInqGroupList(int *count, int **groups);


    //====================================================================================================================
    /** @name Feature's Parent/Child Features */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_history

    Get a list of parent features upon with the specified feature is dependent.

    The feature list (list) is allocated by this function and must be  
    deallocated by the calling procedure.

    @param [in] idFeature index of feature in active part
    @param [in] getAll 1 to get all parent features (parents and grandparents)  
                             0 to get just the immediate parent features
    @param [out] cnt no. of parent features
    @param [out] list list of indices of parent features

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxPartInqFtrParentFtrs(int idFeature, int getAll, int *cnt, int **list);

    /**
    @ingroup zwapi_part_history

    Get the child features of specified feature.

    The feature list (list) is allocated by this function and must be  
    deallocated by the calling procedure.

    @param [in] idFeature index of feature in active part
    @param [out] cnt no. of children
    @param [out] list list of indices of feature's children

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxPartInqFtrChildFtrs(int idFeature, int *cnt, int **list);


    //====================================================================================================================
    /** @name Feature's Entities */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_history

    Get the specified entities of the specified feature.
    These entities are in the VDATA of the feature.

    @note
    Usually we need to call cvxPartFtrPlayTo() to rollback to "idFeature" first,   
    and then call this function to get the input entities.  
    The feature list (list) is allocated by this function and must be  
    deallocated by the calling procedure.  
    Some of evxEntType(VX_ENT_BREP, VX_ENT_OP, VX_ENT_POINT, VX_ENT_WIRE) are banned in this function.

    @param [in] idFeature index of feature in active bin
    @param [in] type entity type id
    @param [out] cnt no. of specified entities
    @param [out] list list of entities

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartFtrInqInpEnts(int idFeature, evxEntType type, int *cnt, int **list);


    /**
    @ingroup zwapi_part_history

    Outputs a list of indices of the entity IDs that belong to  
    the specified feature in the active file.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    Right now, this function only support to get shape, face, curve, point, dimension form the feature.

    @param [in] idFeature feature id
    @param [in] EntType entity type id
    @param [out] Count number of entities
    @param [out] Ents list of the entity IDs

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartInqFtrEnts(int idFeature, evxEntType EntType, int *Count, int **Ents);


    //====================================================================================================================
    /** @name Feature/Sketch Attribute */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_history

    Retrieves user attribute data of the specified feature or sketch in the current active part.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] idFeature index of feature or sketch
    @param [out] Count number of user attributes
    @param [out]  UserAt list of user attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_aPI_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartFtrUserAtGet(int idFeature, int *Count, svxAttribute **UserAt);

    /**
    @ingroup zwapi_part_history

    Set user attribute data of the specified feature or sketch in the current active part.  
    a new user attribute is inserted if the user attribute for the specified label
    does not exist.

    @param [in] idFeature index of feature or sketch
    @param [in] Count number of user attributes
    @param [in] UserAt list of user attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartFtrUserAtSet(int idFeature, int Count, svxAttribute *UserAt);

    /**
    @ingroup zwapi_part_history

    Delete user attribute of the specified feature or sketch in the current active part.  
    the function does not delete any attributes if the specified label is an empty string  
    or the attribute specified label is not found.

    @param [in] idFeature index of feature or sketch
    @param [in] Count number of user attributes (0 to delete all user attributes)
    @param [in] UserAt list of user attributes (NULL to delete all user attributes)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxPartFtrUserAtDel(int idFeature, int Count, svxAttribute *UserAt);
/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_HISTORY_H */
