/**
@file zwapi_userinput.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D User Input API
*/
/**
@defgroup zwapi_userinput User Input
@ingroup CommonModel
@brief
@details THE MODULE FOR THE ZW3D User Input API
*/

#pragma once
#ifndef ZW_API_USER_INPUT_H /* this ifndef surrounds entire header */
#define ZW_API_USER_INPUT_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Get Entity Data */
    //====================================================================================================================
    /**
    @brief entity input options
    @ingroup zwapi_userinput
    */
    typedef enum evxEntInpOpt
    {
        VX_INP_UNDEFINED     = 0,  /**<@brief  undefined */
        VX_INP_GENERAL_3D    = 1,  /**<@brief  pick 3d general entity */
        VX_INP_GENERAL_2D    = 2,  /**<@brief  pick 2d general entity */
        VX_INP_SHAPE         = 3,  /**<@brief  pick shape */
        VX_INP_FACE          = 4,  /**<@brief  pick face */
        VX_INP_SHAPE_OR_FACE = 5,  /**<@brief  pick shape or face */
        VX_INP_EDGE          = 6,  /**<@brief  pick edge */
        VX_INP_CURVE         = 7,  /**<@brief  pick curve */
        VX_INP_EDGE_OR_CURVE = 8,  /**<@brief  pick edge or curve */
        VX_INP_CURVE_LIST    = 9,  /**<@brief  pick curve list */
        VX_INP_PARTING_CURVE = 10, /**<@brief  pick parting curve */
        VX_INP_POINT         = 11, /**<@brief  pick point */
        VX_INP_FEATURE       = 12, /**<@brief  pick feature */
        VX_INP_SKETCH        = 13, /**<@brief  pick sketch */
        VX_INP_DATUM_PLANE   = 14, /**<@brief  pick datum plane */
        VX_INP_REF_PLANE     = 15, /**<@brief  pick reference plane */
        VX_INP_3D_BLOCK      = 16, /**<@brief  pick 3d block */
        VX_INP_LIGHT         = 17, /**<@brief  pick light */
        VX_INP_LAYER         = 18, /**<@brief  pick layer */
        VX_INP_REF_GEOM      = 19, /**<@brief  pick reference geometry */
        VX_INP_WIREFRAME     = 20, /**<@brief  pick wireframe */
        VX_INP_MOVE          = 21, /**<@brief  pick move */
        VX_INP_BLANK         = 22, /**<@brief  pick blank */
        VX_INP_ERASE         = 23, /**<@brief  pick erase */
        VX_INP_INQUIRE       = 24, /**<@brief  pick inquire */
        VX_INP_3D_GEOM       = 25, /**<@brief  pick 3d geometry */
        VX_INP_TEXT          = 26, /**<@brief  pick text */
        VX_INP_PROF          = 27, /**<@brief  pick profile */
        VX_INP_COMP          = 28, /**<@brief  select the top-level component */
        VX_INP_ASM_SHAPE     = 29, /**<@brief  pick shape in the assembly */
        VX_INP_FACE_ON_SHAPE = 30, /**<@brief  pick face on shape */
        VX_INP_SUB_COMP      = 31, /**<@brief  pick sub-component in pick-path, instead of the top-level component */
        VX_INP_CSYS          = 32, /**<@brief  pick CSYS */
        VX_INP_AXIS_3D       = 33, /**<@brief  pick 3d axis */
        VX_INP_AXIS_2D       = 34, /**<@brief  pick 2d axis */
    } evxEntInpOpt;

    //====================================================================================================================
    /** @name Get Point Data */
    //====================================================================================================================
    /**
    @brief point input options
    @ingroup zwapi_userinput
    */
    typedef enum evxPntInpOpt
    {
        VX_INP_PNT_GENERAL          = 0,  /**<@brief  general point */
        VX_INP_PNT_ON_ENTITY        = 1,  /**<@brief  point on entity */
        VX_INP_PNT_ON_CURVE         = 2,  /**<@brief  point on curve */
        VX_INP_PNT_ON_EDGE          = 3,  /**<@brief  point on edge  */
        VX_INP_PNT_ON_CURVE_OR_EDGE = 4,  /**<@brief  point on curve or edge */
        VX_INP_PNT_ON_ANY_FACE      = 5,  /**<@brief  point on any face */
        VX_INP_PNT_ON_FIELD_1_FACE  = 6,  /**<@brief  point on fidle 1 face(specifial face) */
        VX_INP_PNT_END              = 7,  /**<@brief  point end */
        VX_INP_PNT_ASSEMBLY         = 8,  /**<@brief  point in assembly environment */
        VX_INP_PNT_DIRECTION        = 9,  /**<@brief  point direction */
        VX_INP_PNT_ON_CRV_OR_PROF   = 10, /**<@brief  point on curve or profile */
        VX_INP_PNT_ASSEM_FACE       = 11, /**<@brief  point on assembly face */
        VX_INP_PNT_ASSEM_EDGE       = 12, /**<@brief  point on assembly edge  */
        VX_INP_PNT_ASSEM_CURVE      = 13  /**<@brief  point on assembly curve */
    } evxPntInpOpt;

    //====================================================================================================================
    /** @name Get Number */
    //====================================================================================================================
    /**
    @ingroup zwapi_userinput

    Gets angle input from the user, using the specified prompt.

    @param [in] Prompt text prompt
    @param [out] Angle angle (deg)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxGetAngle(const char *Prompt, double *Angle);

    /**
    @ingroup zwapi_userinput

    Gets distance input from the user, using the specified prompt.

    @param [in] Prompt text prompt
    @param [out] Distance distance (mm)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxGetDistance(const char *Prompt, double *Distance);

    /**
    @ingroup zwapi_userinput

    Gets numeric input from the user, using the specified prompt.

    @param [in] Prompt text prompt
    @param [out] Number number (dimensionless)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxGetNumber(const char *Prompt, double *Number);


    //====================================================================================================================
    /** @name Get Entity */
    //====================================================================================================================
    /**
    @ingroup zwapi_userinput

    Displays the specified "Prompt" and waits for the user to pick
    an entity whose id is output via "idEntity".

    @param [in] Prompt text prompt
    @param [in] Opt entity input option
    @param [in] EmptyOk 1 if <middle-click> without input is okay; else 0
    @param [out] idEntity entity id (0 if undefined)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR : error or user-escape
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxGetEnt(const char *Prompt, evxEntInpOpt Opt, int EmptyOk, int *idEntity);

    /**
    @ingroup zwapi_userinput

    Displays the specified "Prompt" and waits for the user to pick  
    a list of entities, which is output via "idEnts".  The calling  
    procedure is responsible for deallocating the entity list.

    @param [in] Prompt text prompt
    @param [in] Opt entity input option
    @param [in] EmptyOk 1 if <middle-click> without input is okay; else 0
    @param [out] Count number of entity picks
    @param [out] idEnts list of entity id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR : error or user-escape
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxGetEnts(const char *Prompt, evxEntInpOpt Opt, int EmptyOk, int *Count, int **idEnts);

    /**
    @ingroup zwapi_userinput

    Displays the specified "Prompt" and waits for the user to pick
    an entity whose path is output via "Path".

    @param [in] Prompt text prompt
    @param [in] Opt entity input option
    @param [in] EmptyOk 1 if <middle-click> without input is okay; else 0
    @param [out] Path entity path

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR : error or user-escape
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxGetEntPath(const char *Prompt, evxEntInpOpt Opt, int EmptyOk, svxEntPath *Path);

    /**
    @ingroup zwapi_userinput

    Displays the specified "Prompt" and waits for the user to pick  
    a list of entities, which is output via "Paths".  The calling  
    procedure is responsible for deallocating the entity path list.

    @param [in] Prompt text prompt
    @param [in] Opt entity input option
    @param [in] EmptyOk 1 if <middle-click> without input is okay; else 0
    @param [out] Count number of entity picks
    @param [out] Paths list of entity path

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR : error or user-escape
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxGetEntPaths(const char *Prompt, evxEntInpOpt Opt, int EmptyOk, int *Count, svxEntPath **Paths);

    /**
    @ingroup zwapi_userinput

    Displays the specified "Prompt" and waits for the user to pick  
    a list of entities whose type already exists in the entity option array by himself, which is output via "idEnts".  The calling  
    procedure is responsible for deallocating the entity list.

    @param [in] Prompt text prompt
    @param [in] pOpt entity input option array pointer
    @param [in] npOpt entity input option array elements` number
    @param [in] EmptyOk 1 if <middle-click> without input is okay; else 0
    @param [out] Count number of entity picks
    @param [out]  idEnts list of entity id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR : error or user-escape
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxGetEntsMultiFilter(const char *Prompt, evxEntInpOpt *pOpt, int npOpt, int EmptyOk, int *Count, int **idEnts);

    /**
    @ingroup zwapi_userinput

    Displays the specified "Prompt" and waits for the user to pick  
    a list of entities whose type already exists in the entity option array by himself, which is output via "Paths".  
    The calling procedure is responsible for deallocating the entity path list.

    @param [in] Prompt text prompt
    @param [in] pOpt entity input option array pointer
    @param [in] npOpt entity input option array elements` number
    @param [in] EmptyOk 1 if <middle-click> without input is okay; else 0
    @param [out] Count number of entity picks
    @param [out] Paths list of entity path

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxGetEntPathsMultiFilter(const char *Prompt, evxEntInpOpt *pOpt, int npOpt, int EmptyOk, int *Count, svxEntPath **Paths);

    /**
    @ingroup zwapi_userinput

    Displays the specified "prompt" and waits for the user to select  
    a point based on the input option (evxPntInpOpt).  This function  
    is especially designed to manage the selection of points on entities  
    that lie outside of the active target object, such as a point on a  
    face of an assembly component.  Your objective may be to get the  
    coordinates of a point that lies external to the active object (e.g. part),  
    the pick-path of an external entity (e.g. an assembly face), or both.

    The selected point's coordinates are output in the local space of the point's  
    parent entity.  "Matrix" may be used to transform the point (and entity)  
    coordinates from their local space to the space of the target object that  
    was active at the time the point was selected (see cvxPntTransform(),  
    cvxCrvTransform()and cvxSrfTransform()).

    If the point was selected by snapping to an entity, the pick-path of the  
    entity is output via "EntPath".  A pick-path defines the sequence of object  
    references (i.e. nested assembly components) that locate the entity relative  
    to the active target object.  A pick-path could lead to an entity that lies  
    in a different file or object than the active file/object.

    API functions for querying entities generally require that an entity's parent  
    file and object(i.e. part, sketch, plan, drawing) be active. If you want to  
    query information about an entity, such as its geometry, use cvxEntPathActivate()  
    to activate the entity's parent file and object, and to get the entity's id.  
    Query the geometry and, if desired, transform it into the space of the original  
    target object using "Matrix".  When you are done querying the geometry, restore  
    the original target file and object with cvxEntPathActivate().

    @param [in] Prompt text prompt
    @param [in] Opt point input option
    @param [in] EmptyOk 1 if <middle-click> without input is okay; else 0
    @param [out] Point point defined in the local space of its parent entity
    @param [out] EntPath entity pick-path (Entity->Count=0 if undefined)
    @param [out] Matrix transform that maps point from local space to space of active target

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxGetExternalPick(const char *Prompt, evxPntInpOpt Opt, int EmptyOk, svxPoint *Point, svxEntPath *EntPath, svxMatrix *Matrix);


    //====================================================================================================================
    /** @name Get Point */
    //====================================================================================================================
    /**
    @ingroup zwapi_userinput

    Displays the specified "prompt" and waits for the user to input  
    a point, which is output via "Point".  If the user used a  
    "point-on-entity" option, the entity index is output via "idEntity".

    @param [in] Prompt text prompt
    @param [in] Opt point input option
    @param [in] EmptyOk 1 if <middle-click> without input is okay; else 0
    @param [out] Point point input
    @param [out] idEntity entity id (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR : error or user-escape
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxGetPoint(const char *Prompt, evxPntInpOpt Opt, int EmptyOk, svxPoint *Point, int *idEntity);

    /**
    @ingroup zwapi_userinput

    Displays the specified "Prompt" and waits for the user to input  
    a list of points, which is output via "Points".  The calling  
    procedure is responsible for deallocating the point list.

    @param [in] Prompt text prompt
    @param [in] Opt point input option
    @param [in] EmptyOk 1 if <middle-click> without input is okay; else 0
    @param [out] Count number of point picks
    @param [out] Points list of points

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR : error or user-escape
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxGetPoints(const char *Prompt, evxPntInpOpt Opt, int EmptyOk, int *Count, svxPoint **Points);

    /**
    @ingroup zwapi_userinput

    Displays the specified "prompt" and waits for the user to input  
    a point, which is output via "Point".  
    If the user used a "point-on-entity" option, the entity index is output via "path".

    @param [in] prompt text prompt
    @param [in] opt point input option
    @param [in] emptyOk 1 if <middle-click> without input is okay; else 0
    @param [out] point point input
    @param [out] path entity path (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR : error or user-escape
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxGetPointOnEnt(const char *prompt, evxPntInpOpt opt, int emptyOk, svxPoint *point, svxEntPath *path);

    /**
    @ingroup zwapi_userinput

    Displays the specified "Prompt" and waits for the user to input  
    a list of points and paths, which is output via "points" and "paths".  
    The calling procedure is responsible for deallocating the point and path list.

    @param [in] prompt text prompt
    @param [in] opt point input option
    @param [in] emptyOk 1 if <middle-click> without input is okay; else 0
    @param [out] count number of point picks
    @param [out] points list of points
    @param [out] paths list of paths(path of point on entity, NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR : error or user-escape
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxGetPointsOnEnts(const char *prompt, evxPntInpOpt opt, int emptyOk, int *count, svxPoint **points, svxEntPath **paths);


    //====================================================================================================================
    /** @name Get File */
    //====================================================================================================================
    /**
    @ingroup zwapi_userinput

    Displays the file browser with the specified "Prompt" and initialized  
    to the "Default" folder.  The browser will display the files specified  
    by "Filter", which is a string like the following examples:

    Show all files:            "All Files (*.*)|*.*|"  
    Show DXF and DWG files:    "DWG File (*.dwg)|*.dwg|DXF File (*.dxf)|*.dxf|"  

    If "Open = 1", the file browser will come up in the configuration  
    used to select a file to be opened.

    If "Open = 0", the file browser will come up in the configuration  
    used to specify a file to be saved.  If the file already exists, the  
    user will be asked whether he wants to overwrite it.

    To initialize the file browser to both a default directory and file
    selection, input "Default" as the desired directory, followed
    by a comma, followed by the desired file name.

    @note
    The path of the file selected by the user is output via the string  
    variable "Path".  If there is an error, or the user presses cancel,  
    an empty string is output.  
    "Path" must reference 512 bytes of memory.  
    Better to use cvxGetFileByLongPath(), this function needs to set the 
    length of the path.

    @see cvxGetFileActiveField().

    @param [in] Open 1 to open files, 0 to save files
    @param [in] Prompt null-terminated text prompt
    @param [in] Default default directory (null-terminated string)
    @param [in] Filter file filter (null-terminated string)
    @param [out] Path user-selected file path(must be 512 bytes)

    @warning
    -        ZW_API_OUT_OF_RANGE
    */
    extern void cvxGetFile(int Open, const char *Prompt, const char *Default, const char *Filter, char *Path);

    /**
    @ingroup zwapi_userinput

    Displays the file browser with the specified "Prompt" and initialized
    to the "Default" folder.  The browser will display the files specified
    by "Filter", which is a string like the following examples:

    Show all files:            "All Files (*.*)|*.*|"
    Show DXF and DWG files:    "DWG File (*.dwg)|*.dwg|DXF File (*.dxf)|*.dxf|"

    If "Open = 1", the file browser will come up in the configuration
    used to select a file to be opened.

    If "Open = 0", the file browser will come up in the configuration
    used to specify a file to be saved.  If the file already exists, the
    user will be asked whether he wants to overwrite it.

    The path of the file selected by the user is output via the string
    variable "Path".  If there is an error, or the user presses cancel,
    an empty string is output.  It is assumed that "Path" references
    sufficient memory to hold the output path (max = 512 bytes).

    To initialize the file browser to both a default directory and file
    selection, input "Default" as the desired directory, followed
    by a comma, followed by the desired file name.

    A Path that is too long (longer than "sizePath") is truncated.

    It is assumed that the input "Path" is no longer than 512 bytes.

    @see cvxGetFileActiveField().
    @param [in] Open 1 to open files, 0 to save files
    @param [in] Prompt null-terminated text prompt
    @param [in] Default default directory (null-terminated string)
    @param [in] Filter file filter (null-terminated string)
    @param [out] Path user-selected file path
    @param [int] sizePath max size of Path user-selected file path

    @warning
    -        ZW_API_OUT_OF_RANGE
    */
    extern void cvxGetFileByLongPath(int Open, const char *Prompt, const char *Default, const char *Filter, char *Path, int sizePath);

    /**
    @ingroup zwapi_userinput

    Similar to cvxGetFile(), this function is intended for use when a form  
    is open and a string field is active.  The file browser is initialized  
    using the parent folder of the file path from the active field.  If  
    the active field is empty, the file browser is initialized using the  
    "Default" folder string.  The specified "Prompt" is shown to the user  
    when the file browser opens, and the browser displays the files  
    specified by "Filter".  Refer to cvxGetFile() for more information about  
    the syntax of the "Filter" string.

    When the user closes the file browser, the path to the file selected  
    by the user is sent to the active field.  If the user cancels the  
    browser, or if an error occurs, the active field is not changed.  

    If "Open = 1", the file browser will be configured to select a file to
    be opened.

    If "Open = 0", the file browser will be configured to select or name a  
    file to be saved.  If the file already exists, the user will be asked  
    to confirm that the file is to be replaced.

    A default will be provided if the "Prompt", "Default" or "Filter"  
    argument is NULL.  When "Open" is 1, the default filter allows any  
    file to be selected, but when "Open" is 0 the caller should always  
    provide the filter, although this function will use a default in this  
    case, too, if necessary guessing at the type of file to be saved.

    When saving ("Open" is 0), the file browser can be configured to show  
    a default folder and also pre-select a specified file.  Do this by  
    assigning the path to the desired folder to "Default", followed by a  
    comma, followed by the desired file name.

    Unlike the cvxGetFile() function, this function does not allow multiple  
    selections.  Only a single file selection is sent to the active field  
    when the user closes the file browser.

    This function is particularly helpful for implementing command  
    functions that automatically display the file browser when the user  
    activates a string input field.  For example, a function that displays  
    the file browser to open a text file might look like this:

    @code
       void TextFileCB(void) {
          cvxGetFileActiveField(1,"Select a text file",NULL,
             "Text Files|*.txt|All Files|*.*|");
       }
    @endcode

    and after installing a symbol with the same name as the function,  
    using the cvxCmdFunc() function, it can be referenced in the string  
    field's options property by preceding the symbol name with a tilde  
    character:

       ~TextFileCb,

    @see cvxGetFile().
    @param [in] Open 1 to open files, 0 to save files
    @param [in] Prompt null-terminated text prompt
    @param [in] Default default directory (null-terminated string)
    @param [in] Filter file filter (null-terminated string)

    */
    extern void cvxGetFileActiveField(int Open, const char *Prompt, const char *Default, const char *Filter);

    /**
    @ingroup zwapi_userinput

    Displays a dialogue for browsing and selecting a file folder.  
    This function grabs all events and does not return until "OK" or "Cancel" is selected.

    The path of the folder selected by the user is output via the string  
    variable "Path".  If there is an error, or the user presses cancel,  
    an empty string is output.  It is assumed that "Path" references  
    sufficient memory to hold the output path (max = 512 bytes).

    @see cvxGetFolderActiveField().

    @param [in] Prompt prompt displayed on directory browser title bar
    @param [in] Default default folder (null-terminated string)
    @param [out] Path path of selected folder (outputs NULL pointer if "Cancel" is selected)

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern void cvxGetFolder(const char *Prompt, char *Default, vxPath path);

    /**
    @ingroup zwapi_userinput

    Displays a dialogue for browsing and selecting a file folder.
    This function grabs all events and does not return until "OK" or "Cancel" is selected.

    The path of the folder selected by the user is output via the string
    variable "Path".  If there is an error, or the user presses cancel,
    an empty string is output.  It is assumed that "Path" references
    sufficient memory to hold the output path (max = 512 bytes).

    A Path that is too long (longer than "sizePath") is truncated.

    It is assumed that the input "Path" is no longer than 512 bytes.

    @see cvxGetFolderActiveField().

    @param [in] Prompt prompt displayed on directory browser title bar
    @param [in] Default default folder (null-terminated string)
    @param [out] Path path of selected folder (outputs NULL pointer if "Cancel" is selected)
    @param [in] sizePath max size of path

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern void cvxGetFolderByLongPath(const char *Prompt, char *Default, char *Path, int sizePath);

    /**
    @ingroup zwapi_userinput

    Similar to cvxGetFolder(), this function is intended for use when a form  
    is open and a string field is active.  The folder browser is  
    initialized using the path found in the active field.  If the active  
    field is empty, the folder browser is initialized using the "Default"  
    folder string.  The specified "Prompt" is shown to the user when the  
    folder browser opens.

    When the user closes the folder browser, the path to the folder  
    selected by the user is sent to the active field.  If the user cancels  
    the browser, or if an error occurs, the active field is not changed.  

    If the "Prompt" or "Default" argument is NULL, a default will be
    provided.

    This function is particularly helpful for implementing command  
    functions that automatically display the folder browser when the user  
    activates a string input field.  For example, a function that displays  
    the browser for selecting an output folder might look like this:

    @code
       void OutputDirCB(void) {
          cvxGetFolderActiveField("Select output folder",NULL);
       }
    @endcode

    and after installing a symbol with the same name as the function,  
    using the cvxCmdFunc() function, it can be referenced in the string  
    field's options property by preceding the symbol name with a tilde  
    character:

       ~OutputDirCb,

    @see cvxGetFolder().
    @param [in] Prompt prompt displayed on folder browser title bar
    @param [in] Default default folder (null-terminated string)

    */
    extern void cvxGetFolderActiveField(const char *Prompt, const char *Default);


    //====================================================================================================================
    /** @name Get Message */
    //====================================================================================================================
    /**
    @ingroup zwapi_userinput

    Displays the input message string in a GUI window and waits for a user  
    response based on "Option".  Occurrences of the "@" character  
    in the message string will be replaced with a newline character.  

    A numeric value indicating the user's response is returned.   
    Valid options and corresponding return values are shown below:

    Option=1: Display "Continue".  Return 1 when the user selects "Continue".  
    Option=2: Display "Yes" and "No".  Return 1 for "Yes", 0 for "No".  
    Option=3: Display "Yes", "No" and "Cancel".  Return 1 for "Yes",
              0 for "No" and -1 for "Cancel".  
    Option=4: Display "Yes", "Yes All", "No" and "Cancel".  Return 1 for "Yes",
              2 for "Yes All", 0 for "No" and -1 for "Cancel".
    @param [in] Option see "DESCRIPTION"
    @param [in] Message null-terminated text message

    */
    extern int cvxGetResponse(int Option, const char *Message);

    /**
    @ingroup zwapi_userinput

    Gets string input from the user.  
    The string input is placed in the memory referenced by "String".  
    If necessary, the input string is truncated to fit the memory.

    @param [in] Prompt null-terminated text prompt
    @param [in] Default default input string (or empty string)
    @param [in] NumBytes no. bytes of storage referenced by "String"
    @param [out] String user input text string

    @retval return
    -        0 - user pressed "Cancel" or did not input a string
    -        1 - otherwise
    */
    extern int cvxGetString(const char *Prompt, const char *Default, int NumBytes, char *String);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_USER_INPUT_H */
