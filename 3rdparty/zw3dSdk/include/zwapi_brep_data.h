/**
@file zwapi_brep_data.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the Brep
objects.
*/
/**
@defgroup zwapi_brep_data Brep Data
@ingroup BrepEntityModel
@brief
@details THE MODULE FOR THE ZW3D Data Types and Structures of the Brep
objects.
*/

#pragma once
#ifndef ZW_API_BREP_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_BREP_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
    //====================================================================================================================
    /** @name pre-edge Query Data */
    //====================================================================================================================
    /**
    @brief pre-edge information
    @ingroup zwapi_brep_data
    */
    typedef struct svxPreEdge
    {
        svxLimit Limits; /**<@brief  limits of pre-edge within its parameter space */
        int idLoop;      /**<@brief  id of parent loop */
        int idEdge;      /**<@brief  id of parent edge */
        int idNext;      /**<@brief  id of next pre-edge in loop direction */
        int idGeom;      /**<@brief  id of uv curve geometry */
        int EdgeDir;     /**<@brief  direction relative to edge (1=same, -1=opposite) */
        int LoopDir;     /**<@brief  direction relative to loop (1=same, -1=opposite) */
    } svxPreEdge;

    /**
    @brief mass attributes
    @ingroup zwapi_brep_data
    */
    typedef struct svxMassProp
    {
        double Density;    /**<@brief  Density (kg/m^3) */
        double Area;       /**<@brief  Area (mm^2) */
        double Volume;     /**<@brief  Volume (mm^3) */
        double Mass;       /**<@brief  Mass (kg) */
        svxPoint Center;   /**<@brief  Centroid (i.e. Center of Gravity) */
        svxVector Axis[3]; /**<@brief  Principal axes relative to global xyz frame */
        double Im[6];      /**<@brief  Moments of inertia relative to xyz axes */
        double Ip[3];      /**<@brief  Moments of inertia relative to principal axes */
        double Rad[3];     /**<@brief  Radii of gyration relative to principal axes */
    } svxMassProp;

    /**
    @brief weldment attribute
    @ingroup zwapi_brep_data
    */
    typedef struct svxWeldAttr
    {
        svxAttribute spec;        /**<@brief  spec */
        svxAttribute description; /**<@brief  description */
        svxAttribute material;    /**<@brief  material */
        svxAttribute mass;        /**<@brief  mass */
        svxAttribute length;      /**<@brief  length */
    } svxWeldAttr;

    /**
    @brief surface evaluate
    @ingroup zwapi_brep_data
    */
    typedef struct svxEvalSurf
    {
        int level;             /**<@brief  level of evaluation                       */
        svxPoint pnt;          /**<@brief  level 0 - x,y,z on surface                */
        svxPoint normal;       /**<@brief  level 1 - unit normal vector              */
        svxPoint partial_u;    /**<@brief  level 1 - tangential component w/r u      */
        svxPoint partial_v;    /**<@brief  level 1 - tangential component w/r v      */
        svxPoint partial_uu;   /**<@brief  level 2 - 2nd partial w/r u               */
        svxPoint partial_uv;   /**<@brief  level 2 - 2nd partial w/r uv              */
        svxPoint partial_vv;   /**<@brief  level 2 - 2nd partial w/r v               */
        svxPoint partial_uuu;  /**<@brief  level 3 - 3rd partial w.r.t u             */
        svxPoint partial_vuu;  /**<@brief  level 3 - 3rd partial w.r.t uv            */
        svxPoint partial_uvv;  /**<@brief  level 3 - 3rd partial w.r.t uv            */
        svxPoint partial_vvv;  /**<@brief  level 3 - 3rd partial w.r.t v             */
        svxPoint partial_uuuu; /**<@brief  level 4 - 4th partial w.r.t u             */
        svxPoint partial_vuuu; /**<@brief  level 4 - 4th partial w.r.t uv            */
        svxPoint partial_uuvv; /**<@brief  level 4 - 4th partial w.r.t uv            */
        svxPoint partial_uvvv; /**<@brief  level 4 - 4th partial w.r.t vv            */
        svxPoint partial_vvvv; /**<@brief  level 4 - 4th partial w.r.t v             */
    } svxEvalSurf;

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_BREP_DATA_H */
