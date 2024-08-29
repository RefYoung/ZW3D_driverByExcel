/**
@file zwapi_ui_form.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Form API
*/
/**
@defgroup zwapi_ui_form Form
@ingroup UIModel
@brief
@details THE MODULE FOR THE ZW3D Form API
*/

#pragma once
#ifndef ZW_API_FORM_H /* this ifndef surrounds entire header */
#define ZW_API_FORM_H

#include "zwapi_ui_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Form Creation */
    //====================================================================================================================
    /**
    @ingroup zwapi_ui_form

    Creates the specified form in memory and displays it if requested.

    @param [in] Form GUI form name
    @param [in] Display 1 to display form after it is created; else 0

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_CREATE_FAIL
    -        ZW_API_FORM_SHOW_FAIL
    */
    extern evxErrors cvxFormCreate(char *Form, int Display);

    /**
    @ingroup zwapi_ui_form

    Shows (i.e. display) the specified GUI form.

    Input "OptForm" to apply this function to an "Options" form.

    @param [in] Form GUI form name

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    extern void cvxFormShow(char *Form);

    /**
    @ingroup zwapi_ui_form

    Hide the specified GUI form.

    @param [in] Form GUI form name

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern void cvxFormHide(char *Form);

    /**
    @ingroup zwapi_ui_form

    Kills (i.e. cancel and undisplay) the specified GUI form.

    Input "OptForm" to apply this function to an "Options" form.

    @param [in] Form GUI form name

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern void cvxFormKill(char *Form);

    /**
    @ingroup zwapi_ui_form

    Log specified form, the form will be auto kill when root object exit.

    @param [in] Form form name

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern void cvxFormLogKill(char *Form);

    /**
    @ingroup zwapi_ui_form

    Refreshes display of the specified GUI form.  
    Input "OptForm" to apply this function to the active "Options" form.

    @param [in] Form GUI form name

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern void cvxFormRefresh(char *Form);

    /**
    @ingroup zwapi_ui_form

    This function displays the specified GUI form and waits for the  
    user to press the "Okay", "Apply" or "Cancel" button on the form.  
    It returns 0 if the user pressed "Cancel", 1 if the user pressed  
    "Okay" or 2 if the user pressed "Apply".

    If you want to cause another widget on the form to cause cvxFormWait()  
    to return, attach a callback function that invokes cvxFormWaitExit() to  
    the widget. Whatever integer value is passed to cvxFormWaitExit() will  
    be returned by this function.

    If "Okay" or "Cancel" are pressed, the GUI form is automatically  
    undisplayed.  If this functions returns because the user pressed "Apply"  
    or because cvxFormWaitExit() was called, the GUI form remains displayed  
    until the calling application undisplays it using cvxFormKill().

    @note
    cvxFormKill() can be applied to a form that has already been  
    undisplayed without any bad consequences.

    @param [in] Form GUI form name (null-terminated ascii string)

    */
    extern int cvxFormWait(char *Form);

    /**
    @ingroup zwapi_ui_form

    When a GUI form is displayed with cvxFormWait(), invoking this function  
    will cause cvxFormWait() to exit and return the integer value passed to  
    this function. Ordinarily, this function would be invoked from a callback  
    function associated with the form actively displayed by cvxFormWait().  
    @param [in] ReturnValue integer value to pass to cvxFormWait ()

    */
    extern void cvxFormWaitExit(int ReturnValue);

    /**
    @ingroup zwapi_ui_form

    Get the size of specified GUI form.

    @param [in] Form form name
    @param [out] Width width of the form
    @param [out] Height height of the form

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern evxErrors cvxFormGetSize(const char *Form, int *Width, int *Height);

    /**
    @ingroup zwapi_ui_form

    Set the size of specified form.

    @param [in] Form form name
    @param [in] Width width of the form
    @param [in] Height height of the form

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern evxErrors cvxFormResize(char *Form, int Width, int Height);

    /**
    @ingroup zwapi_ui_form

    Auto adjust the form size when its children are changed (hidden or modified).

    @param [in] Form form name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern evxErrors cvxFormAdjustSize(const char *Form);


    //====================================================================================================================
    /** @name Form Add To */
    //====================================================================================================================
    /**
    @ingroup zwapi_ui_form

    Add specified form to file browser.

    @param [in] Form form name
    @param [in] addTo form type that the "Form" add to

    @warning
    -        ZW_API_INVALID_NAME
    */
    extern void cvxFormAddTo(const char *Form, evxFormAddTo addTo);

    /**
    @ingroup zwapi_ui_form

    Add specified form to file browser or ui manager. We show in all environments as default.  
    If want to hide in some environment, please use cvxFormVisibleSet.

    @param [in] FormInfo form information that the "Form" add to
    @param [in] Index position that the form insert to
    @param [in] AddTo form type that the "Form" add to

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    evxErrors cvxFormInsertTo(const svxFormInfo *FormInfo, int Index, evxFormAddTo AddTo);

    /**
    @ingroup zwapi_ui_form

    Remove specified form to file browser.

    @param [in] Form form name
    @param [in] removeFrom form type that the "Form" add to

    @warning
    -        ZW_API_INVALID_NAME
    */
    extern void cvxFormRemoveFrom(const char *Form, evxFormAddTo removeFrom);


    //====================================================================================================================
    /** @name Form Set */
    //====================================================================================================================
    /**
    @ingroup zwapi_ui_form

    Gets the specified form's caption title (if it has one) and stores it  
    as a null-terminated string in the memory referenced by "Title".  If  
    the string is longer than "NumBytes", it is truncated.

    @param [in] Form GUI form name
    @param [in] NumBytes number of bytes of memory referenced by "Title"
    @param [out] Title form title (null-terminated text string)

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern void cvxFormTitleGet(char *Form, int NumBytes, char *Title);

    /**
    @ingroup zwapi_ui_form

    Assigns the specified text to the specified form's title bar.

    @param [in] Form GUI form name
    @param [in] Title form title (null-terminated text string)

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern void cvxFormTitleSet(char *Form, char *Title);

    /**
    @ingroup zwapi_ui_form

    Encodes the data associated with the specified GUI form in a  
    null-terminated ascii string.  Memory for the output string  
    is allocated by this function and should be deallocated by  
    the calling procedure.  Only field items numbered 1 or more  
    are encoded.

    The string has the following format:

    Version,FormName,Field_Id,ItemCnt,IsOn,ItemData,IsOn,ItemData...,  
    Field_Id,ItemCnt,...

    It is assumed no item exceeds 1024 bytes in its text-encoded form.  

    If a field is flagged with the "is_distance" option, the text string  
    associated with it is converted from user to database units if the  
    string contains a constant value.

    @param [in] Form GUI form name
    @param [out] Data  GUI data encoded in a null-terminated string

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern evxErrors cvxFormDataGet(char *Form, char **Data);

    /**
    @ingroup zwapi_ui_form

    Uses the data encoded in "text" to initialize the specified GUI form.

    @see cvxFormDataGet().

    @param [in] Form GUI form name
    @param [in] Data  GUI data encoded in a null-terminated string

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern evxErrors cvxFormDataSet(char *Form, char *Data);


    //====================================================================================================================
    /** @name Form Function */
    //====================================================================================================================
    /**
    @ingroup zwapi_ui_form

    Registers a function referenced by the "function=" field in  
    a GUI form template definition.

    Callback functions should be registered in the "Init" function  
    called when your library is dynamically loaded by ZW3D at runtime.

    The function should be the following type:

    int FormFunction(int FormAction, int *UnusedInteger)

    See evxFormAction for possible values of "int FormAction".

    See the "Gui Forms" section of the API documentation for a  
    description of how to define a GUI form using a text-based  
    template.

    If developer wants to unload the DLL plug in file dynamically.  
    It is a MUST to run cvxCmdFuncUnload() in the exit function.

    @param [in] Name function name
    @param [in] Function function pointer
    @param [in] Code ZW3D licensing code or 0.0

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxFormFunc(vxName Name, void *Function, double Code);

    /**
    @ingroup zwapi_ui_form

    Registers a pointer to a callback function referenced by name  
    in the definition of a GUI form template field (e.g. "callback=MyCallback").

    Function pointers should be registered in the "Init" function  
    called when your library is dynamically loaded by ZW3D at runtime.

    The callback function should be of the following type:

    int Callback(char *FormName, int idField, int idItem)

    If developer wants to unload the DLL plug in file dynamically.  
    It is a MUST to run cvxCmdFuncUnload() in the exit function.

    @param [in] Name function name
    @param [in] Function function pointer

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxFormCallback(vxName Name, void *Function);

    /**
    @ingroup zwapi_ui_form

    Get callback function of specified field.

    @param [in] form form name
    @param [in] field field
    @param [out] callback callback function

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    extern evxErrors cvxFormFieldGetCallback(const char *form, int field, void **callback);


    //====================================================================================================================
    /** @name Form State */
    //====================================================================================================================
    /**
    @ingroup zwapi_ui_form

    Outputs the ID of the active field of the active template-driven GUI form.  
    Outputs "idField = 0" if the active field cannot be determined.  
    @param [out] idField active field id

    */
    extern void cvxFormActiveField(int *idField);

    /**
    @ingroup zwapi_ui_form

    Determine form state.

    @param [in] Form GUI form name

    @retval return
    -      0 if the specified form has not been created in memory.
    -      1 if the form is created but not displayed.
    -      2 if the form is created and displayed.
    @warning
    -        ZW_API_INVALID_NAME
    */
    extern int cvxFormState(char *Form);

    /**
    @ingroup zwapi_ui_form

    edit the page config about whether to be show in particular environment. the function  
    currently only supports VX_UI_MANAGER;

    ZW3D has entire 13 environments. the corresponding type can see evxEnvironment


    @param [in] Environment environments
    @param [in] Form GUI form name
    @param [in] State visibility of form (1: visible; 0: invisible)
    @param [in] Type form type that the "Form" set visible

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxFormVisibleSet(evxEnvironment Environment, const char *Form, int State, evxFormAddTo Type);

    /**
    @ingroup zwapi_ui_form

    Set the visibility of the specified field in the form.

    @param [in] form form name
    @param [in] field field id
    @param [in] state (1/0)visible or not

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxFormFieldVisSet(const char *form, int field, int state);


    //====================================================================================================================
    /** @name Form Field */
    //====================================================================================================================
    /**
    @ingroup zwapi_ui_form

    Gets abbreviated information about the fields associated  
    with a GUI form template.  The calling procedure MUST  
    deallocate the output list.

    @param [in] Name template name
    @param [out] Count number of template fields
    @param [out] Fields list of template fields

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern evxErrors cvxFormInqFld(vxName Name, int *Count, svxTplFld **Fields);

    /**
    @ingroup zwapi_ui_form

    Outputs a list of indices of the fields for the specified template.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] Name template name
    @param [out] NumFld number of fields
    @param [out] idFields list of fields id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxTplInqFields(const vxName Name, int *NumFld, int **idFields);

    /**
    @ingroup zwapi_ui_form

    Gets the type of the specified field for the specified template.

    @param [in] Name template name
    @param [in] idField index of field
    @param [out] Type  type of field

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxTplInqFieldType(const vxName Name, int idField, evxCmdFldClass *Type);

    /**
    @ingroup zwapi_ui_form

    Gets the string of the &quot;options&quot; of the specified field for the specified template.

    @param [in] Name template name
    @param [in] idField index of field
    @param [in] NumBytes no. bytes of option string
    @param [out] Options option string

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxTplInqFieldOptions(const vxName Name, int idField, int NumBytes, char *Options);

    /**
    @ingroup zwapi_ui_form

    Updates the specified field of the active "Options" form to  
    display the numeric input associated with the corresponding  
    field of the form's data container (i.e. VDATA).

    @param [in] idField field id

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxFormUpdate(int idField);

    /**
    @ingroup zwapi_ui_form

    If possible, sets the focus for user input to the specified field
    of the specified form.

    If this function does not work, especially for a command form displayed  
    in the ZW3D Manager area, try calling cvxCmdSend("@@idField"),  
    where "idField" is the actual integer value of the variable "idField".  
    For example, if "idField=3", call cvxCmdSend("@@3").

    @param [in] Form GUI form name
    @param [in] idField field id

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern void cvxFieldFocusSet(char *Form, int idField);

    /**
    @ingroup zwapi_ui_form

    Gets the number of items associated with a field. This is  
    primarily for querying the number of items associated with a  
    w_list, w_opt, w_btn, w_tree, w_combo, w_tab, or w_table widget.  

    Input "OptForm" to apply this function to an "Options" form.

    @param [in] Form GUI form name
    @param [in] idField field id
    @param [out] NumItems number of items associated with the field

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern void cvxFieldNumItems(char *Form, int idField, int *NumItems);

    /**
    @ingroup zwapi_ui_form

    Deletes all text items contained in the specified "w_list",
    or "w_combo" field.

    Input "OptForm" to apply this function to an "Options" form.

    @param [in] Form GUI form name
    @param [in] idField field id

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern void cvxFieldClear(char *Form, int idField);

    /**
    @ingroup zwapi_ui_form

    Disable the specified GUI form field.

    Input "OptForm" to apply this function to an "Options" form.

    @param [in] Form GUI form name
    @param [in] idField field id

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern void cvxFieldDisable(char *Form, int idField);

    /**
    @ingroup zwapi_ui_form

    Enable the specified GUI form field.

    Input "OptForm" to apply this function to an "Options" form.

    @param [in] Form GUI form name
    @param [in] idField field id

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern void cvxFieldEnable(char *Form, int idField);

    /**
    @ingroup zwapi_ui_form

    Get the enable state of the specified form field.

    Input "OptForm" to apply this function to an "Options" form.

    @param [in] Form GUI form name
    @param [in] idField field id

    @retval return
    -        1 - the field is enable
    -        0 - the field is not enable or function fails
    @warning
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern int cvxFieldEnableGet(char *Form, int idField);

    /**
    @ingroup zwapi_ui_form

    Apply the specified filter item to the current command's field. Make sure  
    that "filterItem" could be found.  

    @note
    Use the API cvxFilterListGet to get the filter list of active filter panel.

    @see cvxFilterListGet

    @param [in] filterItem Filter item name

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern void cvxFilterItemApply(const char *filterItem);

    /**
    @ingroup zwapi_ui_form

    Assigns the specified image to the specified label field.  
    ZW3D looks in the default search paths for the image file.  
    See cvxPathFind().

    Input "OptForm" to apply this function to an "Options" form.

    @param [in] Form GUI form name
    @param [in] idField label field id
    @param [in] Image image file name

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern void cvxFieldImageSet(char *Form, int idField, char *Image);

    /**
    @ingroup zwapi_ui_form

    Sets the position of the text caret (i.e. cursor) in the text string  
    associated with the specified GUI form field.

    @param [in] Form GUI form name
    @param [in] idField field id
    @param [in] Position character position numbered from zero (-1 to set caret at end)

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxFieldCaretSet(char *Form, int idField, int Position);

    /**
    @ingroup zwapi_ui_form

    Set tip to specified item of the form.

    @param [in] sForm form name
    @param [in] idField field id
    @param [in] tip tip for setting

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxFieldTipSet(const char *sForm, int idField, const char *tip);

    /**
    @ingroup zwapi_ui_form

    Initializes an input field for selecting a font.  This function is  
    intended for use when initializing a form.  It can be called during  
    initialization of a GUI form or from the "init_after" callback  
    function of an "Options" form.

    It is assumed the form has an option (integer) field "idField" that  
    has a combo box widget.  Any prior contents of the combo box list are  
    discarded, and the combo box list is filled with the names of fonts  
    currently available on the local computer.  If "Name" is a non-empty  
    string that matches the name of one of those fonts, that font becomes  
    the default selection in the combo box.

    To apply this function to an "Options" form, input "OptForm" as the  
    value of the "Form" argument.

    It is recommended that the form's field "idField" should reference the  
    global variable "VgRdTxtFont" to hold the index of the selected item.  
    This will synchronize the default font selection with the font  
    selection fields in native ZW3D commands.  This function updates  
    "VgRdTxtFont" if a match to "Name" is found.  If "Name" does not match  
    any font name, the current value of "VgRdTxtFont" selects the default  
    item in the combo box list.

    When working with an "Options" form, the usual practice for managing a  
    font input field is to use an option field having a combo box for the  
    font names, and to use a hidden text field in the form's data  
    container to hold the name of the selected font.  In the form's  
    "init_after" callback, call this function with the contents of the  
    hidden field as the "Name" argument.  In the form's "function"  
    callback, query the combo box for the text of the selected item, save  
    the text to the hidden field, and use the text wherever the font name  
    is needed.  If the combo box cannot be queried because the "Options"  
    form is not active (such as during regeneration), use whatever text  
    was previously saved in the hidden field as the font name.  For  
    example, an "init_after" callback might include this snippet of code  
    to initialize a font selection combo box in field 5, with a hidden  
    text field 4 that might contain the name of a previously selected font  
    (the data container is specified by "idData").

    @note
    The font name will be an empty string if field 4 does not exist:  
    @code
       svxData dataFontName;
       cvxDataGet(idData, 4, &dataFontName);
       cvxFieldInitFont("OptForm", 5, dataFontName.Text);
    @endcode
    The command's "function" callback might include this snippet to get
    the font name:  
    @code
       svxData dataFontIndex, dataFontName;
       char font[sizeof(dataFontName.Text)];

       // Get previously saved font name (will be an empty string if
       // hidden field 4 does not exist) and index of selected font.
       if (cvxDataGet(idData, 4, &dataFontName))
          dataFontName.isText = 1;
       if (cvxDataGet(idData, 5, &dataFontIndex)
          return 1;

       // Look up name of selected font.
       cvxItemGet("OptForm", 5, (int)dataFontIndex.Num, font);
       if (strlen(font) > 0)
          strcpy(dataFontName.Text, font);

       // Replace contents of hidden field with selected font name.
       cvxDataDel(idData, 4);
       cvxDataSet(idData, 4, dataFontName);
       cvxDataToFeature(idData, 0, 1);
    @endcode

    @param [in] Form GUI form name
    @param [in] idField id of form field for font combo box
    @param [in] Name name of default font, may be NULL
    @param [in] hasZwFont judge if fonts have ZW fonts.1:include ZW fonts,0:no ZW fonts

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern evxErrors cvxFieldInitFont(const char *Form, int idField, const char *Name, int hasZwFont);


    //====================================================================================================================
    /** @name Form Item */
    //====================================================================================================================
    /**
    @ingroup zwapi_ui_form

    Adds a new item to the end of the list associated with
    the specified "w_list" or "w_combo" field.

    Input "OptForm" to apply this function to an "Options" form.

    @param [in] Form GUI form name
    @param [in] idField field id
    @param [in] Text item text (NULL to Ignore)

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern void cvxItemAdd(char *Form, int idField, const char *Text);

    /**
    @ingroup zwapi_ui_form

    Gets the text string associated with the specified item of  
    the specified field.  It is assumed that "Text" references  
    sufficient memory to hold the output string.  See cvxItemSet()  
    for the meaning of "idItem" for each field type.

    Input "OptForm" to apply this function to an "Options" form.

    @param [in] Form GUI form name
    @param [in] idField field id
    @param [in] idItem item id
    @param [in,out] Text item text

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern void cvxItemGet(char *Form, int idField, int idItem, char *Text);

    /**
    @ingroup zwapi_ui_form

    Set the text associated with the specified item.

    Form: set Form to "OptForm" to use currently active form.  
    idField: use "$report" to get the value of the specific field.  
    idItem: the meaning of "idItem" for each field type is documented below.

    @verbatim
    1. idField with a label and an input(output) item, such as "ZsCc::Number":
       item = 0: label.
       item = 1: input(output) item.

    2. idField with a label and multiple items in a list, such as "ZsCc::ComboBox":
       item = 0: label.
       item = N: insert "Text" into Nth(start from 1),
                 and the following items move backward in turn.

    3. idField with multiple radio buttons(one as well):
       item = N: Nth item label.
    @endverbatim

    @param [in] Form GUI form name
    @param [in] idField field id
    @param [in] idItem item id
    @param [in] Text item text (can be NULL)

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern void cvxItemSet(char *Form, int idField, int idItem, char *Text);

    /**
    @ingroup zwapi_ui_form

    Modifies the text associated with the specified item.  See  
    cvxItemSet() for the meaning of "idItem" for each field type.

    If the field is a w_list, this function changes the item's icon (if  
    Text is recognized as the path to an image file) or it changes the  
    item's text (if Text is not an image file path) without otherwise  
    re-initializing the item as cvxItemSet() would do.  A typical use for  
    this function is to augment cvxItemAdd() or cvxItemSet() to create a  
    list item that has both text and an icon: specify the path to the icon  
    image file as the Text argument using one of the latter two functions,  
    then call this function to add text to the item.

    For all other field types, this function is the same as cvxItemSet().

    Input "OptForm" as the form name to apply this function to an
    "Options" form.

    @param [in] Form GUI form name
    @param [in] idField field id
    @param [in] idItem item id
    @param [in] Text item text

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern void cvxItemModify(const char *Form, int idField, int idItem, const char *Text);

    /**
    @ingroup zwapi_ui_form

    Deletes the specified item from the specified
    "w_list" or "w_combo" field.

    Input "OptForm" to apply this function to an "Options" form.

    @param [in] Form GUI form name
    @param [in] idField field id
    @param [in] idItem item id

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern void cvxItemDel(char *Form, int idField, int idItem);

    /**
    @ingroup zwapi_ui_form

    Searches the specified "w_list" or "w_combo" field for  
    the specified text and outputs the corresponding item id.  
    "idItem" is set to zero if the specified text is not found.

    For "Options" form, the id starts form 1, and 0 means it is not set.
    So item returns 0, indicating that it is not found.

    For ListWidget and ComboCheck, the position of the item is transmitted
    through +1 processing. Therefore, the minimum transmitted position is 0 + 1 =1.
    Therefore, if the item is 0 ,it means that it is not found.

    @param [in] Form GUI form name
    @param [in] idField field id
    @param [in] Text item text
    @param [out] idItem item id

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern void cvxItemFind(char *Form, int idField, char *Text, int *idItem);

    /**
    @ingroup zwapi_ui_form

    This function is similar to cvxItemSet(), the difference is, this function  
    is only for checkbox control.  
    If the field is list widget,add a checkbox for the item.

    @note
    For different controls,the processing methods are different when the item is -1.

    @param [in] Form GUI form name
    @param [in] idField field id
    @param [in] idItem item id
    @param [in] isOn is on or not

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern void cvxItemCbxSet(char *Form, int idField, int idItem, int isOn);

    /**
    @ingroup zwapi_ui_form

    Selects the specified item.

    Input "OptForm" to apply this function to an "Options" form.

    @param [in] Form GUI form name
    @param [in] idField field id
    @param [in] idItem item id

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern void cvxItemSelect(char *Form, int idField, int idItem);

    /**
    @ingroup zwapi_ui_form

    Selects the specified item.

    Input "OptForm" to apply this function to an "Options" form.

    @param [in] Form GUI form name
    @param [in] idField field id
    @param [in] Text item text

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern void cvxItemSelectText(char *Form, int idField, char *Text);

    /**
    @ingroup zwapi_ui_form

    Outputs the id of the item currently selected in the specified field.  
    Items are numbered from 1.  Outputs 0 if there isn't a selected item.

    Input "OptForm" to apply this function to an "Options" form.

    @param [in] Form GUI form name
    @param [in] idField field id
    @param [out] idItem item id

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern void cvxItemSelected(char *Form, int idField, int *idItem);

    /**
    @ingroup zwapi_ui_form

    Gets the ON/OFF status of a GUI item.  
    Input "OptForm" to apply this function to an "Options" form.

    @param [in] Form GUI form name
    @param [in] idField field id
    @param [in] idItem item id
    @param [out] isOn 1 if item is ON; 0 if it is OFF

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern void cvxItemStateGet(char *Form, int idField, int idItem, int *isOn);

    /**
    @ingroup zwapi_ui_form

    Gets the ON/OFF status of a GUI item.  
    Input "OptForm" to apply this function to an "Options" form.

    @param [in] Form GUI form name
    @param [in] idField field id
    @param [in] idItem item id
    @param [in] isOn 1 if item is ON; 0 if it is OFF

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern void cvxItemStateSet(char *Form, int idField, int idItem, int isOn);

    /**
    @ingroup zwapi_ui_form

    Get item check state of list Widget or tree view.

    @param [in] Form GUI form name
    @param [in] idField field id
    @param [in] idItem item id
    @param [out] checkState 0:Unchecked, 1:PartiallyChecked, 2:Checked

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern evxErrors cvxItemGetCheckState(char *Form, int idField, int idItem, int *checkState);

    /**
    @ingroup zwapi_ui_form

    Set the visibility of the field's specialized item.

    @param [in] Form form name
    @param [in] idField field id
    @param [in] idItem item number
    @param [in] state 1 is visible ,0 is hide

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxItemVisibleSet(const char *Form, int idField, int idItem, int state);

    /**
    @ingroup zwapi_ui_form

    Get the visibility of the field's specialized item.

    @param [in] Form form name
    @param [in] idField field id
    @param [in] idItem item number
    @param [out] state 1 is visible ,0 is hide

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxItemVisibleGet(const char *Form, int idField, int idItem, int *state);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_FORM_H */
