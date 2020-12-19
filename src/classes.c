/*****************************************************************************/
/*  LibreDWG - free implementation of the DWG file format                    */
/*                                                                           */
/*  Copyright (C) 2020 Free Software Foundation, Inc.                        */
/*                                                                           */
/*  This library is free software, licensed under the terms of the GNU       */
/*  General Public License as published by the Free Software Foundation,     */
/*  either version 3 of the License, or (at your option) any later version.  */
/*  You should have received a copy of the GNU General Public License        */
/*  along with this program.  If not, see <http://www.gnu.org/licenses/>.    */
/*****************************************************************************/

/*
 * classes.c: map type to name. classify into unstable, debugging and unhandled.
 * written by Reini Urban
 */

#include "config.h"
#include <string.h>
#include <stdlib.h>
#include "common.h"
#include "classes.h"
#include "dynapi.h"

static const Dwg_Object_Type _classes_unstable[] =
  {
   DWG_TYPE_ACSH_BREP_CLASS,
   DWG_TYPE_ACSH_CHAMFER_CLASS,
   DWG_TYPE_ACSH_PYRAMID_CLASS,
   DWG_TYPE_ARC_DIMENSION,
   DWG_TYPE_ASSOCACTION,
   DWG_TYPE_ASSOCNETWORK,
   DWG_TYPE_ASSOCDEPENDENCY,
   DWG_TYPE_ASSOCGEOMDEPENDENCY,
   DWG_TYPE_ASSOCVALUEDEPENDENCY,
   DWG_TYPE_ASSOCBLENDSURFACEACTIONBODY,
   DWG_TYPE_ASSOCEXTENDSURFACEACTIONBODY,
   DWG_TYPE_ASSOCEXTRUDEDSURFACEACTIONBODY,
   DWG_TYPE_ASSOCFILLETSURFACEACTIONBODY,
   DWG_TYPE_ASSOCLOFTEDSURFACEACTIONBODY,
   DWG_TYPE_ASSOCNETWORKSURFACEACTIONBODY,
   DWG_TYPE_ASSOCPATCHSURFACEACTIONBODY,
   DWG_TYPE_ASSOCPLANESURFACEACTIONBODY,
   DWG_TYPE_ASSOCREVOLVEDSURFACEACTIONBODY,
   DWG_TYPE_BACKGROUND,
   DWG_TYPE_BLOCKALIGNMENTGRIP,
   DWG_TYPE_BLOCKALIGNMENTPARAMETER,
   DWG_TYPE_BLOCKLINEARPARAMETER,
   DWG_TYPE_BLOCKLOOKUPGRIP,
   DWG_TYPE_BLOCKROTATIONGRIP,
   DWG_TYPE_BLOCKROTATIONPARAMETER,
   DWG_TYPE_BLOCKVISIBILITYPARAMETER,
   DWG_TYPE_BLOCKXYPARAMETER,
   DWG_TYPE_DBCOLOR,
   DWG_TYPE_EVALUATION_GRAPH,
   DWG_TYPE_HELIX,
   DWG_TYPE_LARGE_RADIAL_DIMENSION,
   DWG_TYPE_LIGHTLIST,
   DWG_TYPE_MATERIAL,
   DWG_TYPE_MENTALRAYRENDERSETTINGS,
   DWG_TYPE_OBJECT_PTR,
   DWG_TYPE_PROXY_OBJECT,
   DWG_TYPE_RAPIDRTRENDERSETTINGS,
   DWG_TYPE_RENDERSETTINGS,
   DWG_TYPE_SECTION_SETTINGS,
   DWG_TYPE_SPATIAL_INDEX,
   DWG_TYPE_SUN,
   DWG_TYPE_TABLESTYLE,
   DWG_TYPE_WIPEOUT,
  };
static const Dwg_Object_Type _classes_debugging[] =
  {
   DWG_TYPE_ACMECOMMANDHISTORY,
   DWG_TYPE_ACMESCOPE,
   DWG_TYPE_ACMESTATEMGR,
   DWG_TYPE_ACSH_EXTRUSION_CLASS,
   DWG_TYPE_ACSH_LOFT_CLASS,
   DWG_TYPE_ACSH_REVOLVE_CLASS,
   DWG_TYPE_ACSH_SWEEP_CLASS,
   DWG_TYPE_ALDIMOBJECTCONTEXTDATA,
   DWG_TYPE_ANGDIMOBJECTCONTEXTDATA,
   DWG_TYPE_ANNOTSCALEOBJECTCONTEXTDATA,
   DWG_TYPE_ASSOC2DCONSTRAINTGROUP,
   DWG_TYPE_ASSOCRESTOREENTITYSTATEACTIONBODY,
   DWG_TYPE_ASSOCMLEADERACTIONBODY,
   DWG_TYPE_ASSOC3POINTANGULARDIMACTIONBODY,
   DWG_TYPE_ASSOCALIGNEDDIMACTIONBODY,
   DWG_TYPE_ASSOCORDINATEDIMACTIONBODY,
   DWG_TYPE_ASSOCROTATEDDIMACTIONBODY,
   DWG_TYPE_ASSOCSWEPTSURFACEACTIONBODY,
   DWG_TYPE_ASSOCDIMDEPENDENCYBODY,
   DWG_TYPE_ASSOCPERSSUBENTMANAGER,
   DWG_TYPE_ASSOCVARIABLE,
   DWG_TYPE_ASSOCOSNAPPOINTREFACTIONPARAM,
   DWG_TYPE_ASSOCASMBODYACTIONPARAM,
   DWG_TYPE_ASSOCACTIONPARAM,
   DWG_TYPE_ASSOCCOMPOUNDACTIONPARAM,
   DWG_TYPE_ASSOCEDGEACTIONPARAM,
   DWG_TYPE_ASSOCFACEACTIONPARAM,
   DWG_TYPE_ASSOCOBJECTACTIONPARAM,
   DWG_TYPE_ASSOCPATHACTIONPARAM,
   DWG_TYPE_ASSOCPOINTREFACTIONPARAM,
   DWG_TYPE_ASSOCVERTEXACTIONPARAM,
   DWG_TYPE_ASSOCARRAYMODIFYPARAMETERS,
   DWG_TYPE_ASSOCARRAYPATHPARAMETERS,
   DWG_TYPE_ASSOCARRAYPOLARPARAMETERS,
   DWG_TYPE_ASSOCARRAYRECTANGULARPARAMETERS,
   DWG_TYPE_ARCALIGNEDTEXT,
   DWG_TYPE_BLKREFOBJECTCONTEXTDATA,
   DWG_TYPE_ASSOCDIMDEPENDENCYBODY,
   DWG_TYPE_BLOCKPARAMDEPENDENCYBODY,
   DWG_TYPE_CONTEXTDATAMANAGER,
   DWG_TYPE_CSACDOCUMENTOPTIONS,
   DWG_TYPE_CURVEPATH,
   DWG_TYPE_DATALINK,
   DWG_TYPE_DATATABLE,
   DWG_TYPE_DMDIMOBJECTCONTEXTDATA,
   DWG_TYPE_DIMASSOC,
   DWG_TYPE_EXTRUDEDSURFACE,
   DWG_TYPE_FCFOBJECTCONTEXTDATA,
   DWG_TYPE_GEOMAPIMAGE,
   DWG_TYPE_GEOPOSITIONMARKER,
   DWG_TYPE_LAYOUTPRINTCONFIG,
   DWG_TYPE_LEADEROBJECTCONTEXTDATA,
   DWG_TYPE_LOFTEDSURFACE,
   DWG_TYPE_MLEADEROBJECTCONTEXTDATA,
   DWG_TYPE_MOTIONPATH,
   DWG_TYPE_MPOLYGON,
   DWG_TYPE_MTEXTATTRIBUTEOBJECTCONTEXTDATA,
   DWG_TYPE_MTEXTOBJECTCONTEXTDATA,
   DWG_TYPE_NAVISWORKSMODEL,
   DWG_TYPE_NAVISWORKSMODELDEF,
   DWG_TYPE_NURBSURFACE,
   DWG_TYPE_ORDDIMOBJECTCONTEXTDATA,
   DWG_TYPE_PERSUBENTMGR,
   DWG_TYPE_PLANESURFACE,
   DWG_TYPE_POINTPATH,
   DWG_TYPE_RADIMOBJECTCONTEXTDATA,
   DWG_TYPE_RADIMLGOBJECTCONTEXTDATA,
   DWG_TYPE_RENDERENTRY,
   DWG_TYPE_RENDERENVIRONMENT,
   DWG_TYPE_RENDERGLOBAL,
   DWG_TYPE_REVOLVEDSURFACE,
   DWG_TYPE_RTEXT,
   DWG_TYPE_SUNSTUDY,
   DWG_TYPE_SWEPTSURFACE,
   DWG_TYPE_TABLE,
   DWG_TYPE_TABLECONTENT,
   DWG_TYPE_TEXTOBJECTCONTEXTDATA,
   DWG_TYPE_TVDEVICEPROPERTIES,
   DWG_TYPE_VISIBILITYGRIPENTITY,
   DWG_TYPE_ALIGNMENTPARAMETERENTITY,
   DWG_TYPE_BASEPOINTPARAMETERENTITY,
   DWG_TYPE_FLIPPARAMETERENTITY,
   DWG_TYPE_LINEARPARAMETERENTITY,
   DWG_TYPE_POINTPARAMETERENTITY,
   DWG_TYPE_ROTATIONPARAMETERENTITY,
   DWG_TYPE_VISIBILITYPARAMETERENTITY,
   DWG_TYPE_XYPARAMETERENTITY,
   DWG_TYPE_BLOCKALIGNEDCONSTRAINTPARAMETER,
   DWG_TYPE_BLOCKANGULARCONSTRAINTPARAMETER,
   DWG_TYPE_BLOCKARRAYACTION,
   DWG_TYPE_BLOCKDIAMETRICCONSTRAINTPARAMETER,
   DWG_TYPE_BLOCKHORIZONTALCONSTRAINTPARAMETER,
   DWG_TYPE_BLOCKLINEARCONSTRAINTPARAMETER,
   DWG_TYPE_BLOCKLOOKUPACTION,
   DWG_TYPE_BLOCKLOOKUPPARAMETER,
   DWG_TYPE_BLOCKPOINTPARAMETER,
   DWG_TYPE_BLOCKPOLARGRIP,
   DWG_TYPE_BLOCKPOLARPARAMETER,
   DWG_TYPE_BLOCKPOLARSTRETCHACTION,
   DWG_TYPE_BLOCKPROPERTIESTABLE,
   DWG_TYPE_BLOCKPROPERTIESTABLEGRIP,
   DWG_TYPE_BLOCKRADIALCONSTRAINTPARAMETER,
   DWG_TYPE_BLOCKREPRESENTATION,
   DWG_TYPE_BLOCKSTRETCHACTION,
   DWG_TYPE_BLOCKUSERPARAMETER,
   DWG_TYPE_BLOCKVERTICALCONSTRAINTPARAMETER,
   DWG_TYPE_BLOCKXYGRIP,
   DWG_TYPE_DYNAMICBLOCKPROXYNODE,
   DWG_TYPE_POINTCLOUD,
   DWG_TYPE_POINTCLOUDEX,
   DWG_TYPE_POINTCLOUDDEF,
   DWG_TYPE_POINTCLOUDDEFEX,
   DWG_TYPE_POINTCLOUDDEF_REACTOR,
   DWG_TYPE_POINTCLOUDDEF_REACTOR_EX,
   DWG_TYPE_POINTCLOUDCOLORMAP,
  };
static const Dwg_Object_Type _classes_unhandled[] =
  {
   DWG_TYPE_ACDSRECORD,
   DWG_TYPE_ACDSSCHEMA,
   DWG_TYPE_NPOCOLLECTION,
   DWG_TYPE_RAPIDRTRENDERENVIRONMENT,
   DWG_TYPE_XREFPANELOBJECT,
  };

#if 0
struct _obj_type_name {
  const Dwg_Object_Type type;
  const char *name;
};
#endif

// Now with direct O[1] access by type.
static const char *const _dwg_type_names_fixed[] =
  {
    "UNUSED",   	/* DWG_TYPE_UNUSED 0x00 */
    "TEXT",		/* DWG_TYPE_TEXT 0x01 */
    "ATTRIB",		/* DWG_TYPE_ATTRIB 0x02 */
    "ATTDEF",		/* DWG_TYPE_ATTDEF 0x03 */
    "BLOCK",		/* DWG_TYPE_BLOCK 0x04 */
    "ENDBLK",		/* DWG_TYPE_ENDBLK 0x05 */
    "SEQEND",		/* DWG_TYPE_SEQEND 0x06 */
    "INSERT",		/* DWG_TYPE_INSERT 0x07 */
    "MINSERT",		/* DWG_TYPE_MINSERT 0x08 */
    NULL, 		/* DWG_TYPE_<UNKNOWN> = 0x09, */
    "VERTEX_2D",	/* DWG_TYPE_VERTEX_2D 0x0a */
    "VERTEX_3D",	/* DWG_TYPE_VERTEX_3D 0x0b */
    "VERTEX_MESH",	/* DWG_TYPE_VERTEX_MESH 0x0c */
    "VERTEX_PFACE",	/* DWG_TYPE_VERTEX_PFACE 0x0d */
    "VERTEX_PFACE_FACE",/* DWG_TYPE_VERTEX_PFACE_FACE 0x0e */
    "POLYLINE_2D",	/* DWG_TYPE_POLYLINE_2D 0x0f */
    "POLYLINE_3D",	/* DWG_TYPE_POLYLINE_3D 0x10 */
    "ARC",		/* DWG_TYPE_ARC 0x11 */
    "CIRCLE",		/* DWG_TYPE_CIRCLE 0x12 */
    "LINE",		/* DWG_TYPE_LINE 0x13 */
    "DIMENSION_ORDINATE",/* DWG_TYPE_DIMENSION_ORDINATE 0x14 */
    "DIMENSION_LINEAR",	/* DWG_TYPE_DIMENSION_LINEAR 0x15 */
    "DIMENSION_ALIGNED",/* DWG_TYPE_DIMENSION_ALIGNED 0x16 */
    "DIMENSION_ANG3PT",	/* DWG_TYPE_DIMENSION_ANG3PT 0x17 */
    "DIMENSION_ANG2LN",	/* DWG_TYPE_DIMENSION_ANG2LN 0x18 */
    "DIMENSION_RADIUS",	/* DWG_TYPE_DIMENSION_RADIUS 0x19 */
    "DIMENSION_DIAMETER",/* DWG_TYPE_DIMENSION_DIAMETER 0x1A */
    "POINT",		/* DWG_TYPE_POINT 0x1b */
    "3DFACE",		/* DWG_TYPE__3DFACE 0x1c */
    "POLYLINE_PFACE",	/* DWG_TYPE_POLYLINE_PFACE 0x1d */
    "POLYLINE_MESH",	/* DWG_TYPE_POLYLINE_MESH 0x1e */
    "SOLID",		/* DWG_TYPE_SOLID 0x1f */
    "TRACE",		/* DWG_TYPE_TRACE 0x20 */
    "SHAPE",		/* DWG_TYPE_SHAPE 0x21 */
    "VIEWPORT",		/* DWG_TYPE_VIEWPORT 0x22 */
    "ELLIPSE",		/* DWG_TYPE_ELLIPSE 0x23 */
    "SPLINE",		/* DWG_TYPE_SPLINE 0x24 */
    "REGION",		/* DWG_TYPE_REGION 0x25 */
    "3DSOLID",		/* DWG_TYPE__3DSOLID 0x26 */
    "BODY",		/* DWG_TYPE_BODY 0x27 */
    "RAY",		/* DWG_TYPE_RAY 0x28 */
    "XLINE",		/* DWG_TYPE_XLINE 0x29 */
    "DICTIONARY",	/* DWG_TYPE_DICTIONARY 0x2a */
    "OLEFRAME",         /* DWG_TYPE_OLEFRAME = 0x2b */
    "MTEXT", 		/* DWG_TYPE_MTEXT = 0x2c */
    "LEADER",		/* DWG_TYPE_LEADER = 0x2d */
    "TOLERANCE",	/* DWG_TYPE_TOLERANCE = 0x2e */
    "MLINE",		/* DWG_TYPE_MLINE 0x2f */
    "BLOCK_CONTROL",	/* DWG_TYPE_BLOCK_CONTROL 0x30 */
    "BLOCK_HEADER",	/* DWG_TYPE_BLOCK_HEADER 0x31 */
    "LAYER_CONTROL",	/* DWG_TYPE_LAYER_CONTROL 0x32 */
    "LAYER",		/* DWG_TYPE_LAYER 0x33 */
    "STYLE_CONTROL",	/* DWG_TYPE_STYLE_CONTROL 0x34 */
    "STYLE",		/* DWG_TYPE_STYLE 0x35 */
    NULL, 		/* DWG_TYPE_<UNKNOWN> = 0x36, */
    NULL, 		/* DWG_TYPE_<UNKNOWN> = 0x37, */
    "LTYPE_CONTROL",	/* DWG_TYPE_LTYPE_CONTROL 0x38 */
    "LTYPE",		/* DWG_TYPE_LTYPE 0x39 */
    NULL, 		/* DWG_TYPE_<UNKNOWN> = 0x3a, */
    NULL, 		/* DWG_TYPE_<UNKNOWN> = 0x3b, */
    "VIEW_CONTROL",	/* DWG_TYPE_VIEW_CONTROL 0x3c */
    "VIEW",		/* DWG_TYPE_VIEW 0x3d */
    "UCS_CONTROL",	/* DWG_TYPE_UCS_CONTROL 0x3e */
    "UCS",		/* DWG_TYPE_UCS 0x3f */
    "VPORT_CONTROL",	/* DWG_TYPE_VPORT_CONTROL 0x40 */
    "VPORT",		/* DWG_TYPE_VPORT 0x41 */
    "APPID_CONTROL",	/* DWG_TYPE_APPID_CONTROL 0x42 */
    "APPID",		/* DWG_TYPE_APPID 0x43 */
    "DIMSTYLE_CONTROL",	/* DWG_TYPE_DIMSTYLE_CONTROL 0x44 */
    "DIMSTYLE",		/* DWG_TYPE_DIMSTYLE 0x45 */
    "VX_CONTROL",	/* DWG_TYPE_VX_CONTROL 0x46 */
    "VX_TABLE_RECORD",	/* DWG_TYPE_VX_TABLE_RECORD 0x47 */
    "GROUP",		/* DWG_TYPE_GROUP 0x48 */
    "MLINESTYLE",	/* DWG_TYPE_MLINESTYLE 0x49 */
    "OLE2FRAME",	/* DWG_TYPE_OLE2FRAME 0x4a */
    "DUMMY",		/* DWG_TYPE_DUMMY 0x4b */
    "LONG_TRANSACTION",	/* DWG_TYPE_LONG_TRANSACTION 0x4c */
    "LWPOLYLINE",	/* DWG_TYPE_LWPOLYLINE 0x4d */
    "HATCH",		/* DWG_TYPE_HATCH 0x4e */
    "XRECORD",		/* DWG_TYPE_XRECORD 0x4f */
    "PLACEHOLDER",	/* DWG_TYPE_PLACEHOLDER 0x50 */
    "VBA_PROJECT",	/* DWG_TYPE_VBA_PROJECT 0x51 */
    "LAYOUT",		/* DWG_TYPE_LAYOUT 0x52 */
  };

//  "PROXY_ENTITY" 0x1f2 498
//  "PROXY_OBJECT" 0x1f3 499

// auto-generated array of names starting at index 0x200, with direct access by fixedtype.
static const char *const _dwg_type_names_variable[] =
  {
    /* Start auto-generated variable */
    "ACDSRECORD",	/* 512 */
    "ACDSSCHEMA",	/* 513 */
    "ACMECOMMANDHISTORY",	/* 514 */
    "ACMESCOPE",	/* 515 */
    "ACMESTATEMGR",	/* 516 */
    "ACSH_BOOLEAN_CLASS",	/* 517 */
    "ACSH_BOX_CLASS",	/* 518 */
    "ACSH_BREP_CLASS",	/* 519 */
    "ACSH_CHAMFER_CLASS",	/* 520 */
    "ACSH_CONE_CLASS",	/* 521 */
    "ACSH_CYLINDER_CLASS",	/* 522 */
    "ACSH_EXTRUSION_CLASS",	/* 523 */
    "ACSH_FILLET_CLASS",	/* 524 */
    "ACSH_HISTORY_CLASS",	/* 525 */
    "ACSH_LOFT_CLASS",	/* 526 */
    "ACSH_PYRAMID_CLASS",	/* 527 */
    "ACSH_REVOLVE_CLASS",	/* 528 */
    "ACSH_SPHERE_CLASS",	/* 529 */
    "ACSH_SWEEP_CLASS",	/* 530 */
    "ACSH_TORUS_CLASS",	/* 531 */
    "ACSH_WEDGE_CLASS",	/* 532 */
    "ALDIMOBJECTCONTEXTDATA",	/* 533 */
    "ALIGNMENTPARAMETERENTITY",	/* 534 */
    "ANGDIMOBJECTCONTEXTDATA",	/* 535 */
    "ANNOTSCALEOBJECTCONTEXTDATA",	/* 536 */
    "ARC_DIMENSION",	/* 537 */
    "ASSOC2DCONSTRAINTGROUP",	/* 538 */
    "ASSOC3POINTANGULARDIMACTIONBODY",	/* 539 */
    "ASSOCACTION",	/* 540 */
    "ASSOCACTIONPARAM",	/* 541 */
    "ASSOCALIGNEDDIMACTIONBODY",	/* 542 */
    "ASSOCARRAYACTIONBODY",	/* 543 */
    "ASSOCARRAYMODIFYACTIONBODY",	/* 544 */
    "ASSOCARRAYMODIFYPARAMETERS",	/* 545 */
    "ASSOCARRAYPATHPARAMETERS",	/* 546 */
    "ASSOCARRAYPOLARPARAMETERS",	/* 547 */
    "ASSOCARRAYRECTANGULARPARAMETERS",	/* 548 */
    "ASSOCASMBODYACTIONPARAM",	/* 549 */
    "ASSOCBLENDSURFACEACTIONBODY",	/* 550 */
    "ASSOCCOMPOUNDACTIONPARAM",	/* 551 */
    "ASSOCDEPENDENCY",	/* 552 */
    "ASSOCDIMDEPENDENCYBODY",	/* 553 */
    "ASSOCEDGEACTIONPARAM",	/* 554 */
    "ASSOCEDGECHAMFERACTIONBODY",	/* 555 */
    "ASSOCEDGEFILLETACTIONBODY",	/* 556 */
    "ASSOCEXTENDSURFACEACTIONBODY",	/* 557 */
    "ASSOCEXTRUDEDSURFACEACTIONBODY",	/* 558 */
    "ASSOCFACEACTIONPARAM",	/* 559 */
    "ASSOCFILLETSURFACEACTIONBODY",	/* 560 */
    "ASSOCGEOMDEPENDENCY",	/* 561 */
    "ASSOCLOFTEDSURFACEACTIONBODY",	/* 562 */
    "ASSOCMLEADERACTIONBODY",	/* 563 */
    "ASSOCNETWORK",	/* 564 */
    "ASSOCNETWORKSURFACEACTIONBODY",	/* 565 */
    "ASSOCOBJECTACTIONPARAM",	/* 566 */
    "ASSOCOFFSETSURFACEACTIONBODY",	/* 567 */
    "ASSOCORDINATEDIMACTIONBODY",	/* 568 */
    "ASSOCOSNAPPOINTREFACTIONPARAM",	/* 569 */
    "ASSOCPATCHSURFACEACTIONBODY",	/* 570 */
    "ASSOCPATHACTIONPARAM",	/* 571 */
    "ASSOCPERSSUBENTMANAGER",	/* 572 */
    "ASSOCPLANESURFACEACTIONBODY",	/* 573 */
    "ASSOCPOINTREFACTIONPARAM",	/* 574 */
    "ASSOCRESTOREENTITYSTATEACTIONBODY",	/* 575 */
    "ASSOCREVOLVEDSURFACEACTIONBODY",	/* 576 */
    "ASSOCROTATEDDIMACTIONBODY",	/* 577 */
    "ASSOCSWEPTSURFACEACTIONBODY",	/* 578 */
    "ASSOCTRIMSURFACEACTIONBODY",	/* 579 */
    "ASSOCVALUEDEPENDENCY",	/* 580 */
    "ASSOCVARIABLE",	/* 581 */
    "ASSOCVERTEXACTIONPARAM",	/* 582 */
    "ARCALIGNEDTEXT",	/* 583 */
    "BACKGROUND",	/* 584 */
    "BASEPOINTPARAMETERENTITY",	/* 585 */
    "BLKREFOBJECTCONTEXTDATA",	/* 586 */
    "BLOCKALIGNEDCONSTRAINTPARAMETER",	/* 587 */
    "BLOCKALIGNMENTGRIP",	/* 588 */
    "BLOCKALIGNMENTPARAMETER",	/* 589 */
    "BLOCKANGULARCONSTRAINTPARAMETER",	/* 590 */
    "BLOCKARRAYACTION",	/* 591 */
    "BLOCKBASEPOINTPARAMETER",	/* 592 */
    "BLOCKDIAMETRICCONSTRAINTPARAMETER",	/* 593 */
    "BLOCKFLIPACTION",	/* 594 */
    "BLOCKFLIPGRIP",	/* 595 */
    "BLOCKFLIPPARAMETER",	/* 596 */
    "BLOCKGRIPLOCATIONCOMPONENT",	/* 597 */
    "BLOCKHORIZONTALCONSTRAINTPARAMETER",	/* 598 */
    "BLOCKLINEARCONSTRAINTPARAMETER",	/* 599 */
    "BLOCKLINEARGRIP",	/* 600 */
    "BLOCKLINEARPARAMETER",	/* 601 */
    "BLOCKLOOKUPACTION",	/* 602 */
    "BLOCKLOOKUPGRIP",	/* 603 */
    "BLOCKLOOKUPPARAMETER",	/* 604 */
    "BLOCKMOVEACTION",	/* 605 */
    "BLOCKPARAMDEPENDENCYBODY",	/* 606 */
    "BLOCKPOINTPARAMETER",	/* 607 */
    "BLOCKPOLARGRIP",	/* 608 */
    "BLOCKPOLARPARAMETER",	/* 609 */
    "BLOCKPOLARSTRETCHACTION",	/* 610 */
    "BLOCKPROPERTIESTABLE",	/* 611 */
    "BLOCKPROPERTIESTABLEGRIP",	/* 612 */
    "BLOCKRADIALCONSTRAINTPARAMETER",	/* 613 */
    "BLOCKREPRESENTATION",	/* 614 */
    "BLOCKROTATEACTION",	/* 615 */
    "BLOCKROTATIONGRIP",	/* 616 */
    "BLOCKROTATIONPARAMETER",	/* 617 */
    "BLOCKSCALEACTION",	/* 618 */
    "BLOCKSTRETCHACTION",	/* 619 */
    "BLOCKUSERPARAMETER",	/* 620 */
    "BLOCKVERTICALCONSTRAINTPARAMETER",	/* 621 */
    "BLOCKVISIBILITYGRIP",	/* 622 */
    "BLOCKVISIBILITYPARAMETER",	/* 623 */
    "BLOCKXYGRIP",	/* 624 */
    "BLOCKXYPARAMETER",	/* 625 */
    "CAMERA",	/* 626 */
    "CELLSTYLEMAP",	/* 627 */
    "CONTEXTDATAMANAGER",	/* 628 */
    "CSACDOCUMENTOPTIONS",	/* 629 */
    "CURVEPATH",	/* 630 */
    "DATALINK",	/* 631 */
    "DATATABLE",	/* 632 */
    "DBCOLOR",	/* 633 */
    "DETAILVIEWSTYLE",	/* 634 */
    "DGNDEFINITION",	/* 635 */
    "DGNUNDERLAY",	/* 636 */
    "DICTIONARYVAR",	/* 637 */
    "DICTIONARYWDFLT",	/* 638 */
    "DIMASSOC",	/* 639 */
    "DMDIMOBJECTCONTEXTDATA",	/* 640 */
    "DWFDEFINITION",	/* 641 */
    "DWFUNDERLAY",	/* 642 */
    "DYNAMICBLOCKPROXYNODE",	/* 643 */
    "DYNAMICBLOCKPURGEPREVENTER",	/* 644 */
    "EVALUATION_GRAPH",	/* 645 */
    "EXTRUDEDSURFACE",	/* 646 */
    "FCFOBJECTCONTEXTDATA",	/* 647 */
    "FIELD",	/* 648 */
    "FIELDLIST",	/* 649 */
    "FLIPPARAMETERENTITY",	/* 650 */
    "GEODATA",	/* 651 */
    "GEOMAPIMAGE",	/* 652 */
    "GEOPOSITIONMARKER",	/* 653 */
    "HELIX",	/* 654 */
    "IDBUFFER",	/* 655 */
    "IMAGE",	/* 656 */
    "IMAGEDEF",	/* 657 */
    "IMAGEDEF_REACTOR",	/* 658 */
    "INDEX",	/* 659 */
    "LARGE_RADIAL_DIMENSION",	/* 660 */
    "LAYERFILTER",	/* 661 */
    "LAYER_INDEX",	/* 662 */
    "LAYOUTPRINTCONFIG",	/* 663 */
    "LEADEROBJECTCONTEXTDATA",	/* 664 */
    "LIGHT",	/* 665 */
    "LIGHTLIST",	/* 666 */
    "LINEARPARAMETERENTITY",	/* 667 */
    "LOFTEDSURFACE",	/* 668 */
    "MATERIAL",	/* 669 */
    "MENTALRAYRENDERSETTINGS",	/* 670 */
    "MESH",	/* 671 */
    "MLEADEROBJECTCONTEXTDATA",	/* 672 */
    "MLEADERSTYLE",	/* 673 */
    "MOTIONPATH",	/* 674 */
    "MPOLYGON",	/* 675 */
    "MTEXTATTRIBUTEOBJECTCONTEXTDATA",	/* 676 */
    "MTEXTOBJECTCONTEXTDATA",	/* 677 */
    "MULTILEADER",	/* 678 */
    "NAVISWORKSMODEL",	/* 679 */
    "NAVISWORKSMODELDEF",	/* 680 */
    "NPOCOLLECTION",	/* 681 */
    "NURBSURFACE",	/* 682 */
    "OBJECT_PTR",	/* 683 */
    "ORDDIMOBJECTCONTEXTDATA",	/* 684 */
    "PDFDEFINITION",	/* 685 */
    "PDFUNDERLAY",	/* 686 */
    "PERSUBENTMGR",	/* 687 */
    "PLANESURFACE",	/* 688 */
    "PLOTSETTINGS",	/* 689 */
    "POINTCLOUD",	/* 690 */
    "POINTCLOUDCOLORMAP",	/* 691 */
    "POINTCLOUDDEF",	/* 692 */
    "POINTCLOUDDEFEX",	/* 693 */
    "POINTCLOUDDEF_REACTOR",	/* 694 */
    "POINTCLOUDDEF_REACTOR_EX",	/* 695 */
    "POINTCLOUDEX",	/* 696 */
    "POINTPARAMETERENTITY",	/* 697 */
    "POINTPATH",	/* 698 */
    "RADIMLGOBJECTCONTEXTDATA",	/* 699 */
    "RADIMOBJECTCONTEXTDATA",	/* 700 */
    "RAPIDRTRENDERENVIRONMENT",	/* 701 */
    "RAPIDRTRENDERSETTINGS",	/* 702 */
    "RASTERVARIABLES",	/* 703 */
    "RENDERENTRY",	/* 704 */
    "RENDERENVIRONMENT",	/* 705 */
    "RENDERGLOBAL",	/* 706 */
    "RENDERSETTINGS",	/* 707 */
    "REVOLVEDSURFACE",	/* 708 */
    "ROTATIONPARAMETERENTITY",	/* 709 */
    "RTEXT",	/* 710 */
    "SCALE",	/* 711 */
    "SECTIONOBJECT",	/* 712 */
    "SECTIONVIEWSTYLE",	/* 713 */
    "SECTION_MANAGER",	/* 714 */
    "SECTION_SETTINGS",	/* 715 */
    "SORTENTSTABLE",	/* 716 */
    "SPATIAL_FILTER",	/* 717 */
    "SPATIAL_INDEX",	/* 718 */
    "SUN",	/* 719 */
    "SUNSTUDY",	/* 720 */
    "SWEPTSURFACE",	/* 721 */
    "TABLE",	/* 722 */
    "TABLECONTENT",	/* 723 */
    "TABLEGEOMETRY",	/* 724 */
    "TABLESTYLE",	/* 725 */
    "TEXTOBJECTCONTEXTDATA",	/* 726 */
    "TVDEVICEPROPERTIES",	/* 727 */
    "VISIBILITYGRIPENTITY",	/* 728 */
    "VISIBILITYPARAMETERENTITY",	/* 729 */
    "VISUALSTYLE",	/* 730 */
    "WIPEOUT",	/* 731 */
    "WIPEOUTVARIABLES",	/* 732 */
    "XREFPANELOBJECT",	/* 733 */
    "XYPARAMETERENTITY",	/* 734 */
  /* End auto-generated variable */
};

// after 1.0 add new types here for binary compat
/*
  { DWG_TYPE_FREED      , "FREED      " }, // 0xfffd
  { DWG_TYPE_UNKNOWN_ENT, "UNKNOWN_ENT" }, // 0xfffe
  { DWG_TYPE_UNKNOWN_OBJ, "UNKNOWN_OBJ" }, // 0xffff
*/

/* Fast type -> name */
const char *dwg_type_name (const Dwg_Object_Type type)
{
#if 1
  if (type <= DWG_TYPE_LAYOUT)
    return _dwg_type_names_fixed[type];
  else if ((unsigned)type >= 0x200 && type <= DWG_TYPE_XYPARAMETERENTITY)
    return _dwg_type_names_variable[type - 0x200];
  else if (type == DWG_TYPE_UNKNOWN_ENT)
    return "UNKNOWN_ENT";
  else if (type == DWG_TYPE_UNKNOWN_OBJ)
    return "UNKNOWN_OBJ";
  else if (type == DWG_TYPE_PROXY_ENTITY)
    return "ACAD_PROXY_ENTITY";
  else if (type == DWG_TYPE_PROXY_OBJECT)
    return "ACAD_PROXY_OBJECT";
  else if (type == DWG_TYPE_FREED)
    return "FREED";
  else
    return NULL;
#else
  const struct _obj_type_name *s = (struct _obj_type_name *)_dwg_type_name;
  // linear, TODO better binary search. Or a switch jumptable, as in free.
  // just 12 unhandled are missing in objects.inc
  for (; s->type != DWG_TYPE_UNKNOWN_OBJ; s++)
    {
      if (type == s->type)
        return s->name;
    }
  return NULL;
#endif
}

// gperf lookup: name -> type, dxfname
Dwg_Object_Type dwg_name_type (const char *name)
{
#if 1
  const char *dxfname;
  Dwg_Object_Type type;
  int isent;
  if (dwg_object_name (name, &dxfname, &type, &isent))
    {
      return type;
    }
  else
    return DWG_TYPE_UNUSED;
#else
  struct _obj_type_name *s = (struct _obj_type_name *)_dwg_type_name;
  for (; s->type != DWG_TYPE_UNKNOWN_OBJ; s++)
    {
      if (strEQ (name, s->name))
        return s->type;
    }
  return DWG_TYPE_UNUSED;
#endif
}

bool
is_type_stable (const Dwg_Object_Type type)
{
  // clang-format off
  return !is_type_unstable (type)
      && !is_type_debugging (type)
      && !is_type_unstable (type)
      && type != DWG_TYPE_UNKNOWN_OBJ
      && type != DWG_TYPE_UNKNOWN_ENT
      && type != DWG_TYPE_FREED;
  // clang-format on
}

bool
is_type_unstable_all (const Dwg_Object_Type type)
{
  return is_type_unstable (type)
      || is_type_debugging (type);
}

bool is_type_unstable (const Dwg_Object_Type type)
{
  // unsorted, only linear
  for (int i = 0; i < ARRAY_SIZE(_classes_unstable); i++)
    {
      if (type == _classes_unstable[i])
        return true;
    }
  return false;
}
bool is_type_debugging (const Dwg_Object_Type type)
{
  // unsorted, only linear
  for (int i = 0; i < ARRAY_SIZE(_classes_debugging); i++)
    {
      if (type == _classes_debugging[i])
        return true;
    }
  return false;
}
bool is_type_unhandled (const Dwg_Object_Type type)
{
  // unsorted, only linear
  for (int i = 0; i < ARRAY_SIZE(_classes_unhandled); i++)
    {
      if (type == _classes_unhandled[i])
        return true;
    }
  return false;
}

bool is_class_stable (const char* name)
{
  return is_type_stable (dwg_name_type (name));
}
bool is_class_unstable (const char* name)
{
  return is_type_unstable (dwg_name_type (name));
}
bool is_class_debugging (const char* name)
{
  return is_type_debugging (dwg_name_type (name));
}
bool is_class_unhandled (const char* name)
{
  return is_type_unhandled (dwg_name_type (name));
}

bool dwg_find_class (const Dwg_Data *restrict dwg, const char* dxfname, BITCODE_BS *numberp)
{
  // linear search is good enough, with ~20 classes
  for (BITCODE_BS i = 0; i < dwg->num_classes; i++)
    {
      // ->dxfname is always ASCII/UTF-8, dxfname_u is the TU counterpart
      if (strEQ (dwg->dwg_class[i].dxfname, dxfname))
        {
          if (numberp)
            *numberp = dwg->dwg_class[i].number;
          return true;
        }
    }
  return false;
}

// Similar to _dwg_type_name, just with immediate access, no linear/binary search.
// TODO auto-generate from objects.in
static const char *_dwg_dxfnames_fixed[] = {
  NULL, /* UNUSED = 0x00, */
  "TEXT", /* 0x01 */
  "ATTRIB", /* 0x02 */
  "ATTDEF", /* 0x03, */
  "BLOCK", /* 0x04, */
  "ENDBLK", /* 0x05, */
  "SEQEND", /* 0x06, */
  "INSERT", /* 0x07, */
  "INSERT", /* MINSERT 0x08, */
  "TRACE",  /* TRACE_old = 0x09, old TRACE r10-r11 only */
  "VERTEX", /* _2D 0x0a, */
  "VERTEX", /* _3D 0x0b, */
  "VERTEX", /* _MESH 0x0c, */
  "VERTEX", /* _PFACE 0x0d, */
  "VERTEX", /* _PFACE_FACE 0x0e, */
  "POLYLINE", /* _2D 0x0f, */
  "POLYLINE", /* _3D 0x10, */
  "ARC",      /* 0x11, */
  "CIRCLE",   /* 0x12, */
  "LINE",     /* 0x13, */
  "DIMENSION", /* _ORDINATE 0x14, */
  "DIMENSION", /* _LINEAR 0x15, */
  "DIMENSION", /* _ALIGNED 0x16, */
  "DIMENSION", /* _ANG3PT 0x17, */
  "DIMENSION", /* _ANG2LN 0x18, */
  "DIMENSION", /* _RADIUS 0x19, */
  "DIMENSION", /* _DIAMETER 0x1A, */
  "POINT", /* 0x1b, */
  "3DFACE", /* 0x1c, */
  "POLYLINE", /* POLYLINE_PFACE 0x1d, */
  "POLYLINE", /* POLYLINE_MESH 0x1e, */
  "SOLID", /* 0x1f, */
  "TRACE", /* 0x20, */
  "SHAPE", /* 0x21, */
  "VIEWPORT", /* 0x22, */
  "ELLIPSE", /* 0x23, */
  "SPLINE", /* 0x24, */
  "REGION", /* 0x25, */
  "3DSOLID", /* 0x26, */
  "BODY", /* 0x27, */
  "RAY", /* 0x28, */
  "XLINE", /* 0x29, */
  "DICTIONARY", /* 0x2a, */
  "OLEFRAME", /* 0x2b, */
  "MTEXT", /* 0x2c, */
  "LEADER", /* 0x2d, */
  "TOLERANCE", /* 0x2e, */
  "MLINE", /* 0x2f, */
  "BLOCK_CONTROL", /* 0x30, */
  "BLOCK_HEADER", /* 0x31, */
  "LAYER_CONTROL", /* 0x32, */
  "LAYER",         /* 0x33, */
  "STYLE_CONTROL", /* 0x34, 52 SHAPEFILE_CONTROL */
  "STYLE", /* 0x35, */
  NULL, /* DWG_TYPE_<UNKNOWN> = 0x36, */
  NULL, /* DWG_TYPE_<UNKNOWN> = 0x37, */
  "LTYPE_CONTROL", /* 0x38, */
  "LTYPE", /* 0x39, */
  NULL, /* DWG_TYPE_<UNKNOWN> = 0x3a, */
  NULL, /* DWG_TYPE_<UNKNOWN> = 0x3b, */
  "VIEW_CONTROL", /* 0x3c, */
  "VIEW", /* 0x3d, */
  "UCS_CONTROL", /* 0x3e, */
  "UCS", /* 0x3f, */
  "VPORT_CONTROL", /* 0x40, */
  "VPORT", /* 0x41, */
  "APPID_CONTROL", /* 0x42, */
  "APPID", /* 0x43, */
  "DIMSTYLE_CONTROL", /* 0x44, */
  "DIMSTYLE", /* 0x45, */
  "VX_CONTROL", /* 0x46, */
  "VX_TABLE_RECORD", /* 0x47, */
  "GROUP", /* 0x48, */
  "MLINESTYLE", /* 0x49, */
  "OLE2FRAME", /* 0x4a, */
  "DUMMY", /* 0x4b, */
  "LONG_TRANSACTION", /* 0x4c, */
  "LWPOLYLINE", /* 0x4d */
  "HATCH", /* 0x4e, */
  "XRECORD", /* 0x4f, */
  "ACDBPLACEHOLDER", /* 0x50, */
  "VBA_PROJECT", /* 0x51, */
  "LAYOUT" /* 0x52 */
};

/* non-fixed types > 500. not stored as type, but as fixedtype */
// TODO auto-generate from objects.in
static const char *_dwg_dxfnames_variable[] = {
  "ACDSRECORD",
  "ACDSSCHEMA",
  "ACMECOMMANDHISTORY",
  "ACMESCOPE",
  "ACMESTATEMGR",
  "ACSH_BOOLEAN_CLASS",
  "ACSH_BOX_CLASS",
  "ACSH_BREP_CLASS",
  "ACSH_CHAMFER_CLASS",
  "ACSH_CONE_CLASS",
  "ACSH_CYLINDER_CLASS",
  "ACSH_EXTRUSION_CLASS",
  "ACSH_FILLET_CLASS",
  "ACSH_HISTORY_CLASS",
  "ACSH_LOFT_CLASS",
  "ACSH_PYRAMID_CLASS",
  "ACSH_REVOLVE_CLASS",
  "ACSH_SPHERE_CLASS",
  "ACSH_SWEEP_CLASS",
  "ACSH_TORUS_CLASS",
  "ACSH_WEDGE_CLASS",
  "ACDB_ALDIMOBJECTCONTEXTDATA_CLASS",
  "ALIGNMENTPARAMETERENTITY",
  "ACDB_ANGDIMOBJECTCONTEXTDATA_CLASS",
  "ACDB_ANNOTSCALEOBJECTCONTEXTDATA_CLASS",
  "ARC_DIMENSION",
  "ACDBASSOC2DCONSTRAINTGROUP",
  "ACDBASSOC3POINTANGULARDIMACTIONBODY",
  "ACDBASSOCACTION",
  "ACDBASSOCACTIONPARAM",
  "ACDBASSOCALIGNEDDIMACTIONBODY",
  "ACDBASSOCARRAYACTIONBODY",
  "ACDBASSOCARRAYMODIFYACTIONBODY",
  "ACDBASSOCARRAYMODIFYPARAMETERS",
  "ACDBASSOCARRAYPATHPARAMETERS",
  "ACDBASSOCARRAYPOLARPARAMETERS",
  "ACDBASSOCARRAYRECTANGULARPARAMETERS",
  "ACDBASSOCASMBODYACTIONPARAM",
  "ACDBASSOCBLENDSURFACEACTIONBODY",
  "ACDBASSOCCOMPOUNDACTIONPARAM",
  "ACDBASSOCDEPENDENCY",
  "ACDBASSOCDIMDEPENDENCYBODY",
  "ACDBASSOCEDGEACTIONPARAM",
  "ACDBASSOCEDGECHAMFERACTIONBODY",
  "ACDBASSOCEDGEFILLETACTIONBODY",
  "ACDBASSOCEXTENDSURFACEACTIONBODY",
  "ACDBASSOCEXTRUDEDSURFACEACTIONBODY",
  "ACDBASSOCFACEACTIONPARAM",
  "ACDBASSOCFILLETSURFACEACTIONBODY",
  "ACDBASSOCGEOMDEPENDENCY",
  "ACDBASSOCLOFTEDSURFACEACTIONBODY",
  "ACDBASSOCMLEADERACTIONBODY",
  "ACDBASSOCNETWORK",
  "ACDBASSOCNETWORKSURFACEACTIONBODY",
  "ACDBASSOCOBJECTACTIONPARAM",
  "ACDBASSOCOFFSETSURFACEACTIONBODY",
  "ACDBASSOCORDINATEDIMACTIONBODY",
  "ACDBASSOCOSNAPPOINTREFACTIONPARAM",
  "ACDBASSOCPATCHSURFACEACTIONBODY",
  "ACDBASSOCPATHACTIONPARAM",
  "ACDBASSOCPERSSUBENTMANAGER",
  "ACDBASSOCPLANESURFACEACTIONBODY",
  "ACDBASSOCPOINTREFACTIONPARAM",
  "ACDBASSOCRESTOREENTITYSTATEACTIONBODY",
  "ACDBASSOCREVOLVEDSURFACEACTIONBODY",
  "ACDBASSOCROTATEDDIMACTIONBODY",
  "ACDBASSOCSWEPTSURFACEACTIONBODY",
  "ACDBASSOCTRIMSURFACEACTIONBODY",
  "ACDBASSOCVALUEDEPENDENCY",
  "ACDBASSOCVARIABLE",
  "ACDBASSOCVERTEXACTIONPARAM",
  "ARCALIGNEDTEXT",
  NULL, /* SOLID_BACKGROUND, ... */
  "BASEPOINTPARAMETERENTITY",
  "ACDB_BLKREFOBJECTCONTEXTDATA_CLASS",
  "BLOCKALIGNEDCONSTRAINTPARAMETER",
  "BLOCKALIGNMENTGRIP",
  "BLOCKALIGNMENTPARAMETER",
  "BLOCKANGULARCONSTRAINTPARAMETER",
  "BLOCKARRAYACTION",
  "BLOCKBASEPOINTPARAMETER",
  "BLOCKDIAMETRICCONSTRAINTPARAMETER",
  "BLOCKFLIPACTION",
  "BLOCKFLIPGRIP",
  "BLOCKFLIPPARAMETER",
  "BLOCKGRIPLOCATIONCOMPONENT",
  "BLOCKHORIZONTALCONSTRAINTPARAMETER",
  "BLOCKLINEARCONSTRAINTPARAMETER",
  "BLOCKLINEARGRIP",
  "BLOCKLINEARPARAMETER",
  "BLOCKLOOKUPACTION",
  "BLOCKLOOKUPGRIP",
  "BLOCKLOOKUPPARAMETER",
  "BLOCKMOVEACTION",
  "BLOCKPARAMDEPENDENCYBODY",
  "BLOCKPOINTPARAMETER",
  "BLOCKPOLARGRIP",
  "BLOCKPOLARPARAMETER",
  "BLOCKPOLARSTRETCHACTION",
  "BLOCKPROPERTIESTABLE",
  "BLOCKPROPERTIESTABLEGRIP",
  "BLOCKRADIALCONSTRAINTPARAMETER",
  "ACDB_BLOCKREPRESENTATION_DATA",
  "BLOCKROTATEACTION",
  "BLOCKROTATIONGRIP",
  "BLOCKROTATIONPARAMETER",
  "BLOCKSCALEACTION",
  "BLOCKSTRETCHACTION",
  "BLOCKUSERPARAMETER",
  "BLOCKVERTICALCONSTRAINTPARAMETER",
  "BLOCKVISIBILITYGRIP",
  "BLOCKVISIBILITYPARAMETER",
  "BLOCKXYGRIP",
  "BLOCKXYPARAMETER",
  "CAMERA",
  "CELLSTYLEMAP",
  "CONTEXTDATAMANAGER",
  "CSACDOCUMENTOPTIONS",
  "ACDBCURVEPATH",
  "DATALINK",
  "DATATABLE",
  "DBCOLOR",
  "ACDBDETAILVIEWSTYLE",
  "DGNDEFINITION",
  "DGNUNDERLAY",
  "DICTIONARYVAR",
  "ACDBDICTIONARYWDFLT",
  "DIMASSOC",
  "ACDB_DMDIMOBJECTCONTEXTDATA_CLASS",
  "DWFDEFINITION",
  "DWFUNDERLAY",
  "ACDB_DYNAMICBLOCKPROXYNODE",
  "ACDB_DYNAMICBLOCKPURGEPREVENTER_VERSION",
  "ACAD_EVALUATION_GRAPH",
  "EXTRUDEDSURFACE",
  "ACDB_FCFOBJECTCONTEXTDATA_CLASS",
  "FIELD",
  "FIELDLIST",
  "FLIPPARAMETERENTITY",
  "GEODATA",
  "GEOMAPIMAGE",
  "POSITIONMARKER", /*GEOPOSITIONMARKER */
  "HELIX",
  "IDBUFFER",
  "IMAGE",
  "IMAGEDEF",
  "IMAGEDEF_REACTOR",
  "INDEX",
  "LARGE_RADIAL_DIMENSION",
  "LAYERFILTER",
  "LAYER_INDEX",
  "LAYOUTPRINTCONFIG",
  "ACDB_LEADEROBJECTCONTEXTDATA_CLASS",
  "LIGHT",
  "LIGHTLIST",
  "LINEARPARAMETERENTITY",
  "LOFTEDSURFACE",
  "MATERIAL",
  "MENTALRAYRENDERSETTINGS",
  "MESH",
  "ACDB_MLEADEROBJECTCONTEXTDATA_CLASS",
  "MLEADERSTYLE",
  "MOTIONPATH",
  "MPOLYGON",
  "ACDB_MTEXTATTRIBUTEOBJECTCONTEXTDATA_CLASS",
  "ACDB_MTEXTOBJECTCONTEXTDATA_CLASS",
  "MULTILEADER",
  "COORDINATION_MODEL", /* NAVISWORKSMODEL ? */
  "ACDBNAVISWORKSMODELDEF",
  "NPOCOLLECTION",
  "NURBSURFACE",
  "OBJECT_PTR",
  "ACDB_ORDDIMOBJECTCONTEXTDATA_CLASS",
  "PDFDEFINITION",
  "PDFUNDERLAY",
  "ACDBPERSSUBENTMANAGER",
  "PLANESURFACE",
  "PLOTSETTINGS",
  "ACDBPOINTCLOUD",
  "ACDBPOINTCLOUDEX",
  "ACDBPOINTCLOUDDEF",
  "ACDBPOINTCLOUDDEFEX",
  "ACDBPOINTCLOUDDEF_REACTOR",
  "ACDBPOINTCLOUDDEF_REACTOR_EX",
  "ACDBPOINTCLOUDCOLORMAP",
  "POINTPARAMETERENTITY",
  "ACDBPOINTPATH",
  "ACDB_RADIMLGOBJECTCONTEXTDATA_CLASS",
  "ACDB_RADIMOBJECTCONTEXTDATA_CLASS",
  "RAPIDRTRENDERENVIRONMENT",
  "RAPIDRTRENDERSETTINGS",
  "RASTERVARIABLES",
  "RENDERENTRY",
  "RENDERENVIRONMENT",
  "RENDERGLOBAL",
  "RENDERSETTINGS",
  "REVOLVEDSURFACE",
  "ROTATIONPARAMETERENTITY",
  "RTEXT",
  "SCALE",
  "SECTIONOBJECT",
  "ACDBSECTIONVIEWSTYLE",
  "SECTION_MANAGER",
  "SECTION_SETTINGS",
  "SORTENTSTABLE",
  "SPATIAL_FILTER",
  "SPATIAL_INDEX",
  "SUN",
  "SUNSTUDY",
  "SWEPTSURFACE",
  "ACAD_TABLE",
  "TABLE", /* TABLECONTENT */
  "TABLEGEOMETRY",
  "TABLESTYLE",
  "ACDB_TEXTOBJECTCONTEXTDATA_CLASS",
  "TVDEVICEPROPERTIES",
  "VISIBILITYGRIPENTITY",
  "VISIBILITYPARAMETERENTITY",
  "VISUALSTYLE",
  "WIPEOUT",
  "WIPEOUTVARIABLES",
  "EXACXREFPANELOBJECT",
  "XYPARAMETERENTITY"
};

/* Find the dxfname for our internal object/entity name.
 * The reverse of the _alias() functions, replaces dxf_encode_alias (name).
 * Only needed for the add API.
 * Some names return either NULL or one of many possibilities,
 * like UNDERLAY => PDFUNDERLAY.
 */
const char* dwg_type_dxfname (const Dwg_Object_Type type)
{
  if (type <= DWG_TYPE_LAYOUT)
    return _dwg_dxfnames_fixed[type];
  else if ((unsigned)type >= 0x200 && type <= DWG_TYPE_XYPARAMETERENTITY)
    return _dwg_dxfnames_variable[type - 0x200];
  // DWG_TYPE_PROXY_ENTITY = 0x1f2, /* 498 */
  // DWG_TYPE_PROXY_OBJECT = 0x1f3, /* 499 */
  else if (type == DWG_TYPE_PROXY_ENTITY)
    return "ACAD_PROXY_ENTITY";
  else if (type == DWG_TYPE_PROXY_OBJECT)
    return "ACAD_PROXY_OBJECT";
  else if (type == DWG_TYPE_FREED || DWG_TYPE_UNKNOWN_ENT || DWG_TYPE_UNKNOWN_OBJ)
    return NULL;
  else
    {
      //LOG_ERROR ("Unkown object type %d", type)
      return NULL;
    }
}

// dxfname => name
void
object_alias (char *restrict name)
{
  const int len = strlen (name);
  // check aliases (dxfname => name)
  if (len == strlen ("PDFDEFINITION") && strEQc (&name[3], "DEFINITION"))
    strcpy (name, "UNDERLAYDEFINITION");
  else if (strEQc (name, "ACAD_PROXY_OBJECT"))
    strcpy (name, "PROXY_OBJECT");
  else if (strEQc (name, "ACDBPERSSUBENTMANAGER"))
    strcpy (name, "PERSUBENTMGR");
  else if (strEQc (name, "ACDB_DYNAMICBLOCKPURGEPREVENTER_VERSION"))
    strcpy (name, "DYNAMICBLOCKPURGEPREVENTER");
  else if (strEQc (name, "EXACXREFPANELOBJECT"))
    strcpy (name, "XREFPANELOBJECT");
  else if (strstr (name, "_BACKGROUND"))
    strcpy (name, "BACKGROUND");
  // ACDB_*OBJECTCONTEXTDATA_CLASS => *OBJECTCONTEXTDATA
  else if (memBEGINc (name, "ACAD_") && len > 28 && strEQc (&name[len-6], "_CLASS"))
    {
      name[len-6] = '\0';
      if (is_dwg_object (&name[5]))
        memmove (name, &name[5], len - 4);
      else
        name[len-6] = '_';
    }
  // strip ACAD_ prefix
  else if (memBEGINc (name, "ACAD_") && is_dwg_object (&name[5]))
    memmove (name, &name[5], len - 4);
  // strip the ACDB prefix
  else if (memBEGINc (name, "ACDB") && is_dwg_object (&name[4]))
    memmove (name, &name[4], len - 3);
}

// dxfname => name
void
entity_alias (char *restrict name)
{
  const int len = strlen (name);
  // check aliases (dxfname => name)
  if (strEQc (name, "ACAD_TABLE"))
    strcpy (name, "TABLE");
  else if (strEQc (name, "ACAD_PROXY_ENTITY"))
    strcpy (name, "PROXY_ENTITY");
  /* else if (strEQc (name, "ACAD_PROXY_ENTITY_WRAPPER"))
    strcpy (name, "PROXY_ENTITY_WRAPPER"); */
  else if (strEQc (name, "ACDBPLACEHOLDER"))
    strcpy (name, "PLACEHOLDER");
  else if (strEQc (name, "POLYLINE"))
    strcpy (name, "POLYLINE_2D"); // other POLYLINE_* by flag or subclass?
  else if (strEQc (name, "VERTEX"))
    strcpy (name, "VERTEX_2D"); // other VERTEX_* by flag?
  else if (len == strlen ("PDFUNDERLAY") && strEQc (&name[3], "UNDERLAY"))
    strcpy (name, "UNDERLAY");
  else if (strEQc (name, "SURFACE"))
    strcpy (name, "PLANESURFACE");
  else if (strEQc (name, "COORDINATION_MODEL")) //??
    strcpy (name, "NAVISWORKSMODEL");
  else if (strEQc (name, "POSITIONMARKER"))
    strcpy (name, "GEOPOSITIONMARKER");
  // if (strEQc (name, "BLOCK"))
  //  strcpy (name, "BLOCK_HEADER");
  // else if (strEQc (name, "VERTEX_MESH") || strEQc (name, "VERTEX_PFACE"))
  //  strcpy (name, "VERTEX_3D");
  // else if (strEQc (name, "DIMENSION"))
  //  strcpy (name, "DIMENSION_ANG2LN");   // allocate room for the largest
  // strip a ACAD_ prefix
  else if (memBEGINc (name, "ACAD_") && is_dwg_entity (&name[5]))
    memmove (name, &name[5], len - 4);
  // strip the ACDB prefix
  else if (memBEGINc (name, "ACDB") && is_dwg_entity (&name[4]))
    memmove (name, &name[4], len - 3);
}
