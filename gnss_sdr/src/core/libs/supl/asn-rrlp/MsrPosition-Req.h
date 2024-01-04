/*
 * SPDX-FileCopyrightText: (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * SPDX-License-Identifier: BSD-1-Clause
 * Generated by asn1c-0.9.22 (http://lionet.info/asn1c)
 * From ASN.1 module "RRLP-Components"
 *     found in "../rrlp-components.asn"
 */

#ifndef _MsrPosition_Req_H
#define _MsrPosition_Req_H

#include <asn_application.h>

/* Including external dependencies */
#include "ExtensionContainer.h"
#include "PositionInstruct.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /* Forward declarations */
    struct ReferenceAssistData;
    struct MsrAssistData;
    struct SystemInfoAssistData;
    struct GPS_AssistData;
    struct Rel98_MsrPosition_Req_Extension;
    struct Rel5_MsrPosition_Req_Extension;

    /* MsrPosition-Req */
    typedef struct MsrPosition_Req
    {
        PositionInstruct_t positionInstruct;
        struct ReferenceAssistData *referenceAssistData /* OPTIONAL */;
        struct MsrAssistData *msrAssistData /* OPTIONAL */;
        struct SystemInfoAssistData *systemInfoAssistData /* OPTIONAL */;
        struct GPS_AssistData *gps_AssistData /* OPTIONAL */;
        ExtensionContainer_t *extensionContainer /* OPTIONAL */;
        /*
         * This type is extensible,
         * possible extensions are below.
         */
        struct Rel98_MsrPosition_Req_Extension
            *rel98_MsrPosition_Req_extension /* OPTIONAL */;
        struct Rel5_MsrPosition_Req_Extension
            *rel5_MsrPosition_Req_extension /* OPTIONAL */;

        /* Context for parsing across buffer boundaries */
        asn_struct_ctx_t _asn_ctx;
    } MsrPosition_Req_t;

    /* Implementation */
    extern asn_TYPE_descriptor_t asn_DEF_MsrPosition_Req;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "GPS-AssistData.h"
#include "MsrAssistData.h"
#include "ReferenceAssistData.h"
#include "Rel5-MsrPosition-Req-Extension.h"
#include "Rel98-MsrPosition-Req-Extension.h"
#include "SystemInfoAssistData.h"

#endif /* _MsrPosition_Req_H_ */
#include <asn_internal.h>
