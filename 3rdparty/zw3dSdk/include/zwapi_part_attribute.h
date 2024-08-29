/**
@file zwapi_part_attribute.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Part Attribute  API
*/
/**
@defgroup zwapi_part_attribute Part Attribute
@ingroup PartObjectsModel
@brief
@details THE MODULE FOR THE ZW3D Part Attribute  API
*/

#pragma once
#ifndef ZW_API_PART_AT_H /* this ifndef surrounds entire header */
#define ZW_API_PART_AT_H

#include "zwapi_part_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Part Physical Attribute */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_attribute

    Appends an operation to the history of the active part to  
    calculate mass properties for the part, assigning the results  
    to the variables named Part_Area, Part_Volume and Part_Mass.


    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartMassProp(void);

    /**
    @ingroup zwapi_part_attribute

    Calculate length,width,hight,volume,area,mass of part specified by index

    @param [in] idPart index of part in database
    @param [out] attr calculate attribute of part

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxPartCalcAttrGet(int idPart, svxPartCalcAttrData *attr);

    /**
    @ingroup zwapi_part_attribute

    Calculate physical attributes of the specified part.  
    If Name = "" or NULL, it will calculate current active  
    part's physical attributes. 

    @param [in] Name part name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    */
    extern evxErrors cvxPartPhyAttrCalc(vxRootName Name);

    /**
    @ingroup zwapi_part_attribute

    Output volume and mass data from the specified part in the active file.  
    Before you use it, you need to use function cvxPartPhyAttrCalc() to calculate  
    physical attributes.

    @param [in] Name name of part in active file(Name[0]=0 or NULL for active part)
    @param [out] dVolume volume of part,unit:mm^3
    @param [out] dMass mass of part,unit:kg

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartVolumAndMassGet(vxRootName Name, double *dVolume, double *dMass);

    /**
    @ingroup zwapi_part_attribute

    Obtain the material information in the specified file.  
    Attributes->Material corresponding to platform functions.  
    The obtained density is in kg/m^3.

    This interface obtains the data in the material list of the specified file.  
    If the user wants to get material's attribute of the part file, interface cvxPartAtItemGet can be used.

    @note
    fileName can only have a file name, or it can be a file name  
    that contains a file path.  
    If fileName only has a file name, user can add a search path  
    through the cvxPathSearchFirst() interface.

    @param [in] fileName file name(fileName[0]=0 or NULL for active file)
    @param [in] rootName root name(rootName[0]=0 or NULL for active target object)
    @param [in] material material name
    @param [out] data material attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_FILE_LOCATE_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartMaterialGet(const vxLongPath fileName, const vxRootName rootName, const vxLongName material, svxPartMaterial *data);

    /**
    @ingroup zwapi_part_attribute

    This interface is used to add materials to the material list of the specified document.   
    (Attributes->Material...)

    If the user wants to set material's attribute of the part file, interface cvxPartAtItemSet can be used.

    If the material exists,modify the density corresponding to the existing
    material name.  
    Otherwise, add the material name and density that did not exist before.  
    The unit of density is kg/m^3.

    @note
    fileName can only have a file name, or it can be a file name
    that contains a file path.  
    If fileName only has a file name, user can add a search path
    through the cvxPathSearchFirst() interface.

    @param [in] fileName file name(fileName[0]=0 or NULL for active file)
    @param [in] rootName root name(rootName[0]=0 or NULL for active target object)
    @param [in] material material name
    @param [in] data material attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_FILE_LOCATE_FAIL
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxPartMaterialSet(const vxLongPath fileName, const vxRootName rootName, const vxLongName material, const svxPartMaterial *data);

    /**
    @ingroup zwapi_part_attribute

    This interface is used to delete the specified materials in the material list of 
    the specified file. (Attributes->Material...)

    @note
    fileName can only have a file name, or it can be a file name
    that contains a file path.  
    If fileName only has a file name, user can add a search path
    through the cvxPathSearchFirst() interface.

    @param [in] fileName file name(fileName[0]=0 or NULL for active file)
    @param [in] rootName root name(rootName[0]=0 or NULL for active target object)
    @param [in] material material name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_FILE_LOCATE_FAIL
    */
    extern evxErrors cvxPartMaterialDel(const vxLongPath fileName, const vxRootName rootName, const vxLongName material);


    //====================================================================================================================
    /** @name Part Attribute */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_attribute

    Retrieves attribute data from the specified part in the active file.  
    If "Name" is NULL or an empty string, the active target part is used.

    @param [in] Name name of part in active file
    @param [out] At part attribute data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_DATA_GET_eRROR
    */
    extern evxErrors cvxPartAtGet(vxRootName Name, svxPartAttribute *At);

    /**
    @ingroup zwapi_part_attribute

    Selectively updates attributes of the specified part with the  
    fields in "At" that have valid ascii strings in their "data"  
    variables. Any attribute whose "data" is a blank string is  
    ignored.  The "label" strings associated with modified fields  
    are not reflected into the specified part's attribute info  
    with the exception of user attributes and driving dimensions.

    For this function to update a user attribute, both "label" and "data"  
    must be defined for "At->UserAttribute[n]". If a user attribute with  
    the specified "label" already exists in the part's current attribute  
    info, then the corresponding "data" is updated. If not, then a new  
    user-attribute is added to part's attribute info.

    Entries in "At->Dimen[]" that have blank labels are skipped.  
    Dimensions listed in "At->Dimen[]" that are not already listed in  
    the part's attribute info are added. Entries in "At->Dimen[]" with  
    blank labels are ignored.

    It is assumed that labels of driving dimensions listed in "At->Dimen[]"  
    identify valid dimension or variables in the parent part. It is also  
    assumed that dimension values stored in "At->Dimen[].data" fields are  
    within valid ranges. No checking is done to ensure it. When driving  
    dimension values are changed, the parent part is automatically  
    regenerated by this function.

    You cannot use this function to delete pre-existing dimension names  
    from a part's attribute info. To do that, you have to get the existing  
    attribute data with cvxPartAtGet(), clear the "label" and "data" variables  
    of the driving dimensions you no longer want recorded in the part attributes,  
    then reset all attributes using cvxPartAtSet().

    If "Name" is NULL or an empty string, the active target part is used.

    @param [in] Name name of part in active file
    @param [in] At part attribute data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxPartAtMod(vxRootName Name, svxPartAttribute *At);

    /**
    @ingroup zwapi_part_attribute

    Assigns the specified part attribute data to the specified part.  
    Existing part attribute data is replaced with the contents of  
    the input attribute data structure.

    This function reflects back into the specified part all of the  
    attribute data in "At", even the blank strings (excluding the  
    part name field). So, generally speaking, you would want to  
    initialize "At" by passing it to cvxPartAtGet(), modify select  
    fields of "At", then pass "At" back into this function.

    It is assumed that labels of driving dimensions listed in "At->Dimen[]"  
    identify valid dimension or variables in the parent part. It is also  
    assumed that dimension values stored in "At->Dimen[].data" fields are  
    within valid ranges. No checking is done to ensure it. When driving  
    dimension values are changed, the parent part is automatically  
    regenerated by this function.

    Use cvxPartAtMod() to selectively update part attribute data.

    If "Name" is NULL or an empty string, the active target part is used.

    @param [in] Name name of part in active file
    @param [in] At part attribute data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartAtSet(vxRootName Name, svxPartAttribute *At);

    /**
    @ingroup zwapi_part_attribute

    Display the part attributes form for specified root object.

    @see cvxPartClosePartAt().

    @param [in] File file name (NULL for active file)   
                     1. loaded file and newly created file need only file name  
                     2. unloaded file need the full path of file  
    @param [in] Root root object name (NULL for active root object)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxPartShowPartAt(const vxLongPath File, const vxRootName Root);

    /**
    @ingroup zwapi_part_attribute

    Close the part attributes form.

    @see cvxPartShowPartAt().

    */
    extern void cvxPartClosePartAt();

    /**
    @ingroup zwapi_part_attribute

    Outputs the specified attribute from the active part.

    The itemId includes part items of evxAtItemId (VX_AT_USER~VX_AT_HEIGHT).

    When itemId is VX_AT_USER, the name of the user-defined attribute must  
    be assigned to At->label before calling this function.  For all other  
    itemId values, At->label can be an empty string (At->label[0]=0) when  
    this function is called.

    @param [in] itemId item id
    @param [in,out] At part item attribute

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxPartAtItemGet(evxAtItemId itemId, svxAttribute *At);

    /**
    @ingroup zwapi_part_attribute

    Sets the value of the specified attribute in the active part.

    The itemId includes part items of evxAtItemId (VX_AT_USER~VX_AT_HEIGHT).

    When itemId is VX_AT_USER, the name of the user-defined attribute must  
    be assigned to At->label before calling this function.  For all other  
    itemId values, At->label can be an empty string (At->label[0]=0) when  
    this function is called.

    @param [in] itemId item id
    @param [in] At part item attribute

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxPartAtItemSet(evxAtItemId itemId, svxAttribute *At);

    /**
    @ingroup zwapi_part_attribute

    Outputs an attribute from a specified part.

    The itemId includes part items of evxAtItemId (VX_AT_USER~VX_AT_HEIGHT).

    When itemId is VX_AT_USER, the name of the user-defined attribute must  
    be assigned to At->label before calling this function.  For all other  
    itemId values, At->label can be an empty string (At->label[0]=0) when  
    this function is called.

    If the specified file is not already open, this function will open it  
    to access the attribute, and will then close the file.  If you want to  
    keep the file open, use the cvxFileKeep() function, before calling this  
    function, to set a flag that prevents cvxPartAtItemSetInFile() and  
    cvxPartAtItemGetInFile() from closing the files that they open.  (Files  
    that are already open before cvxPartAtItemSetInFile() or  
    cvxPartAtItemGetInFile() is called are never closed by these functions.)  
    Keeping files open is a more efficient way to access multiple  
    attributes in a file, but you must remember to call cvxFileKeep() again  
    to reset the flag after you have finished your calls to  
    cvxPartAtItemGetInFile() and cvxPartAtItemSetInFile(), and you also become  
    responsible for closing the files, for example by using one of the  
    cvxFileClose() or cvxFileSave() functions.

    @param [in] File object file name (File[0]=0 or NULL for active file)
    @param [in] Root root object name (Root[0]=0 or NULL for active target object)
    @param [in] itemId item id
    @param [in,out] At part item attribute

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_FILE_LOCATE_FAIL
    */
    extern evxErrors cvxPartAtItemGetInFile(const vxLongPath File, const vxRootName Root, evxAtItemId itemId, svxAttribute *At);

    /**
    @ingroup zwapi_part_attribute

    Sets an attribute value in a specified part.

    The itemId includes part items of evxAtItemId (VX_AT_USER~VX_AT_HEIGHT).

    When itemId is VX_AT_USER, the name of the user-defined attribute must  
    be assigned to At->label before calling this function.  For all other  
    itemId values, At->label can be an empty string (At->label[0]=0) when  
    this function is called.

    If the specified file is not already open, this function will open it  
    to access the attribute, and will then close the file.  If you want to  
    keep the file open, use the cvxFileKeep() function, before calling this   
    function, to set a flag that prevents cvxPartAtItemSetInFile() and  
    cvxPartAtItemGetInFile() from closing the files that they open.  (Files  
    that are already open before cvxPartAtItemSetInFile() or  
    cvxPartAtItemGetInFile() is called are never closed by these functions.)  
    Keeping files open is a more efficient way to access multiple  
    attributes in a file, but you must remember to call cvxFileKeep() again  
    to reset the flag after you have finished your calls to  
    cvxPartAtItemGetInFile() and cvxPartAtItemSetInFile(), and you also become  
    responsible for closing the files, for example by using one of the  
    cvxFileClose() or cvxFileSave() functions.  

    @param [in] File object file name (File[0]=0 or NULL for active file)
    @param [in] Root root object name (Root[0]=0 or NULL for active target object)
    @param [in] itemId item id
    @param [in] At part item attribute

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_FILE_LOCATE_FAIL
    */
    extern evxErrors cvxPartAtItemSetInFile(const vxLongPath File, const vxRootName Root, evxAtItemId itemId, svxAttribute *At);

    /**
    @ingroup zwapi_part_attribute

    Delete the attribute of specified item.

    If the itemId = VX_AT_USER,  the label can not be NULL and the attribute will  
    be delete, otherwise it will set the data of At to NULL.

    The itemId includes part items of evxAtItemId(VX_AT_USER~VX_AT_HEIGHT).

    @param [in] itemId item id
    @param [in] label lable of item attribute

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxPartAtItemDel(evxAtItemId itemId, vxLongName label);

    /**
    @ingroup zwapi_part_attribute

    Get the description of the specified attribute item.

    If the itemId = VX_AT_USER, the parameter AtLable can not be NULL.  
    The itemId includes part items of evxAtItemId(VX_AT_USER~VX_AT_HEIGHT).

    @param [in] itemId attribute item id
    @param [in] AtLable attribute item name
    @param [out] AtDes attribute item description
    @param [in] nBytes string max size of attribute item description

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxPartAtItemDesGet(evxAtItemId itemId, const char *AtLable, char *AtDes, int nBytes);

    /**
    @ingroup zwapi_part_attribute

    Set the description of the specified attribute item.

    If the itemId = VX_AT_USER, the parameter AtLable can not be NULL.  
    The itemId includes part items of evxAtItemId(VX_AT_USER~VX_AT_HEIGHT).

    @param [in] itemId attribute item id
    @param [in] AtLable attribute item name
    @param [in] AtDes attribute item description

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    */
    extern evxErrors cvxPartAtItemDesSet(evxAtItemId itemId, const char *AtLable, const char *AtDes);

    /**
    @ingroup zwapi_part_attribute

    Get the locking state of the specified attribute item.  
    only custom attribute item are supported.

    @param [in] AtLable custom attribute name
    @param [out] AtLockState locking state of attribute item

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartAtItemLockGet(char *AtLable, evxAtItemLockStatus *AtLockState);

    /**
    @ingroup zwapi_part_attribute

    Set the locking state of the specified attribute item.  
    only custom attribute item are supported.

    @param [in] AtLable custom attribute name
    @param [in] AtLockState locking state of attribute item

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    */
    extern evxErrors cvxPartAtItemLockSet(char *AtLable, evxAtItemLockStatus AtLockState);

    /**
    @ingroup zwapi_part_attribute

    Get the locking state of the specified attribute item.  
    only custom attribute item are supported.

    If the specified file is not already open, this function will open it  
    to access attributes, and will then close the file.  If you want to  
    keep the file open, use the cvxFileKeep() function, before calling this  
    function, to set a flag that prevents this function from closing the   
    files that it opens.  (Files that are already open before this function  
    is called are never closed by this function.)  If you will be calling  
    several functions to access data in the same file, keeping the file open  
    between calls is more efficient than letting each function open and close  
    the file.  However, you must remember to call cvxFileKeep() again to reset  
    the flag after you have finished all of the function calls that need to  
    access the specified file, and you also become responsible for closing the  
    file, for example by using one of the cvxFileClose() or cvxFileSave() functions.

    @param [in] File object file name (File[0]=0 or NULL for active file)
    @param [in] Root root object name (Root[0]=0 or NULL for active target object)
    @param [in] AtLable custom attribute name
    @param [out] AtLockState locking state of attribute item

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_FILE_LOCATE_FAIL
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxPartAtItemLockGetInFile(const vxLongPath File, const vxRootName Root, char *AtLable, evxAtItemLockStatus *AtLockState);

    /**
    @ingroup zwapi_part_attribute

    Set the locking state of the specified attribute item.  
    only custom attribute item are supported.

    If the specified file is not already open, this function will open it  
    to access attributes, and will then close the file.  If you want to  
    keep the file open, use the cvxFileKeep() function, before calling this  
    function, to set a flag that prevents this function from closing the  
    files that it opens.  (Files that are already open before this function  
    is called are never closed by this function.)  If you will be calling  
    several functions to access data in the same file, keeping the file open  
    between calls is more efficient than letting each function open and close  
    the file.  However, you must remember to call cvxFileKeep() again to reset  
    the flag after you have finished all of the function calls that need to  
    access the specified file, and you also become responsible for closing the  
    file, for example by using one of the cvxFileClose() or cvxFileSave() functions.

    @param [in] File object file name (File[0]=0 or NULL for active file)
    @param [in] Root root object name (Root[0]=0 or NULL for active target object)
    @param [in] AtLable custom attribute name
    @param [in] AtLockState locking state of attribute item

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_FILE_LOCATE_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    */
    extern evxErrors cvxPartAtItemLockSetInFile(const vxLongPath File, const vxRootName Root, const char *AtLable, evxAtItemLockStatus AtLockState);

    /**
    @ingroup zwapi_part_attribute

    Retrieves user attribute data from the specified part in the specified file.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    If the specified file is not already open, this function will open it  
    to access attributes, and will then close the file.  If you want to  
    keep the file open, use the cvxFileKeep() function, before calling this  
    function, to set a flag that prevents this function from closing the  
    files that it opens.  (Files that are already open before this function  
    is called are never closed by this function.)  If you will be calling  
    several functions to access data in the same file, keeping the file open  
    between calls is more efficient than letting each function open and close  
    the file.  However, you must remember to call cvxFileKeep() again to reset  
    the flag after you have finished all of the function calls that need to  
    access the specified file, and you also become responsible for closing the  
    file, for example by using one of the cvxFileClose() or cvxFileSave() functions.

    @param [in] File object file name (File[0]=0 or NULL for active file)
    @param [in] Root root object name (Root[0]=0 or NULL for active target object)
    @param [out] Count number of user attributes
    @param [out]  UserAt list of user attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_FILE_LOCATE_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxPartUserAtGet(const vxLongPath File, const vxRootName Root, int *Count, svxAttribute **UserAt);

    /**
    @ingroup zwapi_part_attribute

    Assigns the specified part attribute data to the specified part.  
    Existing part attribute data is replaced with the contents of  
    the input attribute data structure.

    If the specified file is not already open, this function will open it  
    to access attributes, and will then close the file.  If you want to  
    keep the file open, use the cvxFileKeep() function, before calling this   
    function, to set a flag that prevents this function from closing the  
    files that it opens.  (Files that are already open before this function  
    is called are never closed by this function.)  If you will be calling  
    several functions to access data in the same file, keeping the file open  
    between calls is more efficient than letting each function open and close  
    the file.  However, you must remember to call cvxFileKeep() again to reset  
    the flag after you have finished all of the function calls that need to  
    access the specified file, and you also become responsible for closing the  
    file, for example by using one of the cvxFileClose() or cvxFileSave() functions.

    @param [in] File object file name (File[0]=0 or NULL for active file)
    @param [in] Root root object name (Root[0]=0 or NULL for active target object)
    @param [in] DelOrgAt whether to clear original user attribute
    @param [in] Count number of user attributes
    @param [in] UserAt list of user attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_FILE_LOCATE_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxPartUserAtSet(const vxLongPath File, const vxRootName Root, int DelOrgAt, int Count, svxAttribute *UserAt);

    /**
    @ingroup zwapi_part_attribute

    Export the part user attribute data to the specified file 'filePath'.

    @param [in] filePath path of excel file to export

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartUserAtExport(const vxLongPath filePath);

    //====================================================================================================================
    /** @name Part Custom String */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_attribute

    Set custom string attached to a entity.

    @param [in] idEnt part id
    @param [in] CustomString custom string
    @param [out] idStr custom string id, NULL to ignore

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxPartSetCustomStr(int idEnt, const char *CustomString, int *idStr);

    /**
    @ingroup zwapi_part_attribute

    Get custom string attached to a entity.

    The calling procedure MUST deallocate the output string with cvxMemFree().

    @param [in] idEnt part id
    @param [out] idStr custom string id, can be NULL
    @param [out] CustomString custom string

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        Zw_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxPartGetCustomStr(int idEnt, int *idStr, char **CustomString);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_PART_AT_H */
