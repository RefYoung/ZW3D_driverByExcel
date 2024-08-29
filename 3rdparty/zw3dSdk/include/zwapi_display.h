/**
@file zwapi_display.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Display API and Generic Data Types and
Structures of these functions
*/
/**
@defgroup zwapi_display Display
@ingroup CommonModel
@brief
@details THE MODULE FOR THE ZW3D Display API and Generic Data Types and
Structures of these functions
*/

#pragma once
#ifndef ZW_API_DISPLAY_H /* this ifndef surrounds entire header */
#define ZW_API_DISPLAY_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Display Data */
    //====================================================================================================================
    /**
    @brief display state settings
    @ingroup zwapi_display
    */
    typedef int vxDispState[10];


    /**
    @brief display attribute types
    @ingroup zwapi_display
    */
    typedef enum evxDispAttrib
    {
        VX_DISP_POINT = 0,
        VX_DISP_LINE  = 1,
        VX_DISP_FACE  = 2
    } evxDispAttrib;

    /**
    @brief display mode
    @ingroup zwapi_display
    */
    typedef enum evxDispMode
    {
        VX_DISP_WIRE        = 1, /**<@brief  wireframe display without showing facet edges */
        VX_DISP_SHADE       = 2, /**<@brief  shaded surfaces */
        VX_DISP_HIDD_APPROX = 3, /**<@brief  approximate hidden line display */
        VX_DISP_HIDD_EXACT  = 4, /**<@brief  shade analyze mode (contour lines, etc) */
        VX_DISP_EDGE        = 5  /**<@brief  multiple mode (allows shade/wire/hidden/zebra at same time */
    } evxDispMode;

    /**
    @brief display (i.e. GUI) item
    @ingroup zwapi_display
    */
    typedef enum evxDispItem
    {
        VX_DISP_SCREEN  = 0, /**<@brief  screen */
        VX_DISP_PREVIEW = 1, /**<@brief  preview */
        VX_DISP_FORMS   = 2, /**<@brief  forms */
        VX_DISP_ALL     = 3  /**<@brief  all */
    } evxDispItem;

    /**
    @brief visual display item
    @ingroup zwapi_display
    */
    typedef enum evxVisualDispItem
    {
        VX_VISUAL_DISP_FRAME_TRIAD   = 0, /**<@brief  frame triad display in visual manager */
        VX_VISUAL_DISP_COMPASS_TRIAD = 1, /**<@brief  compass triad display in visual manager */
        VX_VISUAL_DISP_TRIAD_TRANS   = 2  /**<@brief  show hidden in visual manager */
    } evxVisualDispItem;


    //====================================================================================================================
    /** @name Lights Data */
    //====================================================================================================================
    /**
    @brief light source type
    @ingroup zwapi_display
    */
    typedef enum evxLightType
    {
        V_LIGHT_NULL = 0, /**<@brief  undefined */
        V_LIGHT_AMB  = 1, /**<@brief  ambient light source */
        V_LIGHT_DIR  = 2, /**<@brief  directional light source */
        V_LIGHT_POS  = 3, /**<@brief  positional light source */
        V_LIGHT_SPOT = 4, /**<@brief  spot light source */
        V_LIGHT_EYE  = 5  /**<@brief  light source located at view position */
    } evxLightType;

    /**
    @brief light source
    @ingroup zwapi_display
    */
    typedef struct svxLight
    {
        vxName name;         /**<@brief  light source name */
        evxLightType type;   /**<@brief  light source type */
        svxPoint pos;        /**<@brief  light position in definition space */
        svxPoint dir;        /**<@brief  light direction in definition space */
        svxPoint target_pnt; /**<@brief  target point for spot light */
        float intensity;     /**<@brief  light intensity (0.0-1.0) */
        float angle_1;       /**<@brief  spotlight cutoff angle (0-180 deg) */
        float angle_2;       /**<@brief  spotlight constant intensity angle (0-180 deg) */
        float exp;           /**<@brief  spotlight exponent (0-128)*/
        float c1, c2, c3;    /**<@brief  attenuation coefficients */
        svxColor color;      /**<@brief  light color (rgb) */
        char off;            /**<@brief  1-light is OFF, else ON */
        char shadow;         /**<@brief  1-cast shadows, else 0 */
    } svxLight;

    //====================================================================================================================
    /** @name Frame and Datum Data */
    //====================================================================================================================
    /**
    @brief display mode of datum plane
    @ingroup zwapi_display
    */
    typedef enum evxDatumDispMode
    {
        VX_DSP_PLN_XY           = 0, /**<@brief  display XY only */
        VX_DSP_PLN_RECT_XY      = 1, /**<@brief  display rectangle and XY axis */
        VX_DSP_PLN_RECT_XYZ     = 2, /**<@brief  display rectangle and XYZ axis */
        VX_DSP_PLN_RECT         = 3, /**<@brief  display rectangle only */
        VX_DSP_PLN_QURT         = 4, /**<@brief  display a quarter of rectangle only */
        VX_DSP_PLN_RECT_XY_FIX  = 5, /**<@brief  display rectangle and XY axis with fix size */
        VX_DSP_PLN_RECT_XYZ_FIX = 6, /**<@brief  display rectangle and XYZ axis with fix size */
        VX_DSP_PLN_RECT_FIX     = 7, /**<@brief  display (a quarter of) rectangle only with fix size */
        VX_DSP_PLN_XYZ          = 8  /**<@brief  display XYZ only */
    } evxDatumDispMode;

    /**
    @brief display mode of datum axis
    @ingroup zwapi_display
    */
    typedef enum evxAxisDispMode
    {
        VX_DSP_AXIS_ARROW_LINE = 0, /**<@brief  display arrow line */
        VX_DSP_AXIS_DASH_LINE  = 1  /**<@brief  display dash line without arrow */
    } evxAxisDispMode;

    //====================================================================================================================
    /** @name Display */
    //====================================================================================================================
    /**
    @ingroup zwapi_display

    Initiates a screen redraw if display update is not disabled
    and if a redraw is not going to be forced at the end of the
    current operation.

    Active inputs (i.e. picks and previews) are not redrawn.  If
    you desire a redraw that includes redisplay of active inputs,
    use cvxCmdSend("$CdRedrawAll").

    @note
    This function must be called on the main thread.

    */
    extern void cvxDispRedraw(void);

    /**
    @ingroup zwapi_display

    Calling this function during a command will cause the data
    used to display part faces and edges to update/regenerate
    at the end of the command.

    */
    extern void cvxDispDataUpdate(void);

    /**
    @ingroup zwapi_display

    Outputs the active display mode.

    @param [out] Mode active display mode

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern void cvxDispModeGet(evxDispMode *Mode);

    /**
    @ingroup zwapi_display

    Sets the active display mode.

    @param [in] Mode display mode

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxDispModeSet(evxDispMode Mode);

    /**
    @ingroup zwapi_display

    Gets the RGB components of the specified default point/wireframe/face
    color.

    @see cvxDispColorGet().

    @param [in] Type display attribute type
    @param [out] Rgb default color RGB components

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern void cvxDispRgbGet(evxDispAttrib Type, svxColor *Rgb);

    /**
    @ingroup zwapi_display

    Sets the default point/wireframe/face color from RGB components.

    @note
    Only faces support the full range of possible RGB colors.
    Points and wireframe entities can have only the colors corresponding
    to those predefined by the evxColor type.   
    If "Type" is VX_DISP_POINT
    or VX_DISP_LINE, this function finds the evxColor that is closest to
    the given RGB components and uses that standard color for the
    specified default.

    @see cvxDispColorSet().

    @param [in] Type display attribute type
    @param [in] Rgb color RGB components to use as default

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxDispRgbSet(evxDispAttrib Type, const svxColor *Rgb);

    /**
    @ingroup zwapi_display

    Gets the default point/wireframe/face color.

    Face colors may be defined over a broader range of RGB components than
    can be represented by the evxColor type.  If the default face color is
    not one of the standard colors, this function outputs the nearest
    evxColor value that approximates it.

    @see cvxDispRgbGet().

    @param [in] Type display attribute type
    @param [out] Color color id

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxDispColorGet(evxDispAttrib Type, evxColor *Color);

    /**
    @ingroup zwapi_display

    Sets the default point/wireframe/face color.

    @see cvxDispRgbSet().

    @param [in] Type display attribute type
    @param [in] Color color id to use as default

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxDispColorSet(evxDispAttrib Type, evxColor Color);

    /**
    @ingroup zwapi_display

    Switches OFF automatic display update of the specified GUI item
    when "isOn=0".  Switches it back ON when "isOn=1".

    Each call to this function with "isOn=0" MUST be paired with
    a subsequent call to this same function with the same "Item"
    setting and "isOn=1" in order to restore the setting to
    its original state.  This is CRITICAL for the ZW3D display to
    function properly after your application is done.

    By default, display update is ON, so this function should ALWAYS
    be called first with "isOn=0" followed by a call with "isOn=1".

    @param [in] Item display/gui item
    @param [in] isOn 0=OFF, 1=ON

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxDispSwitch(evxDispItem Item, int isOn);

    /**
    @ingroup zwapi_display

    Outputs the state of a switch set using cvxDispSwitch().
    If "Item = VX_DISP_ALL", "isOn" is output as zero unless
    VX_DISP_SCREEN, VX_DISP_PREVIEW and VX_DISP_FORMS are all ON.

    @param [in] Item display/gui item
    @param [out] isOn 0=OFF, 1=ON

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern void cvxDispSwitchGet(evxDispItem Item, int *isOn);

    /**
    @ingroup zwapi_display

    This function should ALWAYS be called in pairs to disable display/UI update (Option=0)
    and then to re-enable it (Option=1).   
    The first call to disable display/UI update records
    current display settings in "State", then disables them.   
    The second call uses the settings
    previously recorded in "State" to re-enable display/UI update.

    @note
    If this function is being used to re-enable display/UI update after an error
    occurred in application code, always use "Option = 1". In this case "Option = 2" could
    cause further errors by attempting to refresh the display from an erroneous database.

    @param [in] Option 0 to disable display/UI update;   
                       1 to re-enable display/UI update;   
                       2 to re-enable AND refresh the display/UI
    @param [in,out] State storage for display states

    */
    extern void cvxDispState(int Option, vxDispState State);

    /**
    @ingroup zwapi_display

    Get the current display status of specified visual display item .

    @param [in] Item  visual display Item
    @param [in] isOn  on = 1, off = 0

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern void cvxVisDispStatusGet(evxVisualDispItem Item, int *isOn);

    /**
    @ingroup zwapi_display

    After using the cvxCmdMacro() command and entering the new environment,
    user can use this interface to update various UI controls of the environment.

    @code
       void example()
       {
       // create new part file.
       char* partName = (char*)"Demo";
       cvxFileNew(partName);
       cvxRootAdd(VX_ROOT_PART, partName, NULL);
       // After this code is executed, it is in the environment of the part.

       // create new drawing file.
       char cmd[1024] = "\0";
       sprintf_s(cmd, sizeof(cmd), "%s\n%s\n%s\n%s\n%s\n%s", cmd,
       "[vxSend,\"$CdPartSheet\"]", "BUFFER", "[vxSendEvt, \"UiTplList\", 1, 2, 2]",
       "[vxSendEvt, \"UiTplList\", -1, 0, 0]", "ENDBUFFER");

       if (cvxCmdMacro(cmd, NULL)) {
          cvxMsgDisp((char*)"Failed to create drawing sheet!");
          return;
       }
       // After this code is executed,a drawing file will be created in the form of a macro,
       // and the environment will be switched to the drawing environment.

       // Because the previous code switched the environment through cvxCmdMacro(),
       // user need to call this interface to update.
       cvxDispSceneUpdate();

       cvxMsgDisp((char*)"Create drawing sheet successfully.");
       return;
       }
    @endcode

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxDispSceneUpdate();

    /**
    @ingroup zwapi_display

    Get the global or client coordinates of the active display window.

    @param [in] includeFrame  Include window frame; 0, Exclude window frame
    @param [in] isGlobal  Get the global coordinates; 0, Get the client coordinates
    @param [out] x top left X. If don't get this value, set it nullptr.
    @param [out] y top left Y. If don't get this value, set it nullptr.
    @param [out] w active display window's width. If don't get this value, set it nullptr.
    @param [out] h active display window's height. If don't get this value, set it nullptr.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    */
    extern evxErrors cvxDispWindowRectGet(const int includeFrame, const int isGlobal, int *x, int *y, int *w, int *h);


    //====================================================================================================================
    /** @name Lights */
    //====================================================================================================================
    /**
    @ingroup zwapi_display

    Gets a list of light sources associated with the active part or assembly.

    This function allocates memory for the list of light sources.
    This memory MUST be deallocated by the calling procedure.

    @code
       //Example
       int Count=0;
       svxLight *Lights=NULL;

       cvxLightGetAll(&Count, &Lights);
       for (int i=0; i < Count; i++) {Light[i]...}
       cvxMemFree((void**)&Lights);
    @endcode

    @param [out] Count number of light sources
    @param [out] Lights list of light sources

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
    extern evxErrors cvxDispGetLights(int *Count, svxLight **Lights);

    /**
    @ingroup zwapi_display

    Initialize the parameters of the cvxDispSetLights().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data light source data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxDispSetLightsInit(svxLight *data);

    /**
    @ingroup zwapi_display

    Set light sources associated with the active part or assembly.
    New light sources will replace the existing ones.

    @note
    Interface cvxDispSetLightsInit() can initialize variables of this function.

    @param [in] Count number of light sources
    @param [in] Lights list of light sources

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxDispSetLights(int Count, svxLight *Lights);


    //====================================================================================================================
    /** @name Show-n_Tell */
    //====================================================================================================================
    /**
    @ingroup zwapi_display

    Loads the specified "Show-n-Tell" file.
    Use cvxShowDisplay() to activate a specific "Show-n-Tell" slide.

    @param [in] File path to Show-n-Tell file

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    extern void cvxShowOpen(const vxLongPath File);

    /**
    @ingroup zwapi_display

    Displays the specified "Show-n-Tell" slide, numbered from 1.
    @param [in] SlideNumber Show-n-Tell slide number ( >= 1)

    */
    extern void cvxShowDisp(int SlideNumber);


    //====================================================================================================================
    /** @name Zoom */
    //====================================================================================================================
    /**
    @ingroup zwapi_display

    Sets active view to encompass all visible geometry.
    @param [in] Redraw 1 to redraw after zoom all; else 0

    */
    extern void cvxDispZoomAll(int Redraw);

    /**
    @ingroup zwapi_display

    Sets active view to encompass all visible geometry including dimensions.
    @param [in] Redraw 1 to redraw after zoom all; else 0

    */
    extern void cvxDispZoomAllIncludeDim(int Redraw);

    /**
    @ingroup zwapi_display

    Zoom at a specific location on the active view using the zoom factor.
    @param [in] point point to zoom at
    @param [in] factor the factor to zoom at, mostly to be 0.8

    */
    extern void cvxDispZoomAt(const svxPoint point, const float factor);

    /**
    @ingroup zwapi_display

    Set active view to construction limits of target object.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    */
    extern evxErrors cvxDispZoomLimits(void);

    /**
    @ingroup zwapi_display

    Window zoom in or out.
    StartPoint and endpoint are on the diagonal of the rectangle.

    @note
    Because this function has an internal call to the "cvxDispRedraw()" function,
    it must be called on the main thread.

    @param [in] ZoomIn 1 to zoom-in, 0 to zoom-out
    @param [in] StartPoint start point
    @param [in] EndPoint end point

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    */
    extern evxErrors cvxDispZoomIn(int ZoomIn, const svxPoint2f StartPoint, const svxPoint2f EndPoint);


    //====================================================================================================================
    /** @name Frame and Datum */
    //====================================================================================================================
    /**
    @ingroup zwapi_display

    Set visible of the local datum.
    @param [in] iVisible visible flag of local datum

    */
    extern void cvxDatumLocalVis(int iVisible);

    /**
    @ingroup zwapi_display

    Set display mode of the specified datum plane.

    @param [in] idDatum id of datum plane
    @param [in] DispMode display mode of datum plane

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOR_ENV
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern void cvxDatumDispModeSet(int idDatum, evxDatumDispMode DispMode);

    /**
    @ingroup zwapi_display

    Get display mode of the specified datum plane.

    @param [in] idDatum id of datum plane
    @param [out] DispMode display mode of datum plane

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxDatumDispModeGet(int idDatum, evxDatumDispMode *DispMode);

    /**
    @ingroup zwapi_display

    Get display attribute of the specified datum entity, including datum plane, datum
    axis and datum CSYS.

    @param [in] idDatum id of datum entity
    @param [out] DispAt display attribute of datum entity

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxDatumDispAttrGet(int idDatum, svxWireAt *DispAt);

    /**
    @ingroup zwapi_display

    Set display attribute of the specified datum entity, including datum plane, datum
    axis and datum CSYS.

    @param [in] idDatum id of datum entity
    @param [in] DispAt display attribute of datum entity

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxDatumDispAttrSet(int idDatum, const svxWireAt *DispAt);

    /**
    @ingroup zwapi_display

    Get display mode of the specified datum axis.

    @param [in] idAxis id of datum axis
    @param [out] DspMode display mode of datum axis

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxAxisDispModeGet(int idAxis, evxAxisDispMode *DspMode);

    /**
    @ingroup zwapi_display

    Set display mode of the specified datum axis.

    @param [in] idAxis id of datum axis
    @param [in] DspMode display mode of datum axis

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxAxisDispModeSet(int idAxis, evxAxisDispMode DspMode);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_DISPLAY_H */
