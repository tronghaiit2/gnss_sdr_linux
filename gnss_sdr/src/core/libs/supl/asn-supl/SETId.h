/*
 * SPDX-FileCopyrightText: (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * SPDX-License-Identifier: BSD-1-Clause
 * Generated by asn1c-0.9.22 (http://lionet.info/asn1c)
 * From ASN.1 module "ULP-Components"
 *     found in "../supl-common.asn"
 */

#ifndef _SETId_H
#define _SETId_H

#include <asn_application.h>

/* Including external dependencies */
#include "IPAddress.h"
#include <BIT_STRING.h>
#include <IA5String.h>
#include <OCTET_STRING.h>
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /* Dependencies */
    typedef enum SETId_PR
    {
        SETId_PR_NOTHING, /* No components present */
        SETId_PR_msisdn,
        SETId_PR_mdn,
        SETId_PR_min,
        SETId_PR_imsi,
        SETId_PR_nai,
        SETId_PR_iPAddress,
        /* Extensions may appear below */
    } SETId_PR;

    /* SETId */
    typedef struct SETId
    {
        SETId_PR present;
        union SETId_u
        {
            OCTET_STRING_t msisdn;
            OCTET_STRING_t mdn;
            BIT_STRING_t min;
            OCTET_STRING_t imsi;
            IA5String_t nai;
            IPAddress_t iPAddress;
            /*
             * This type is extensible,
             * possible extensions are below.
             */
        } choice;

        /* Context for parsing across buffer boundaries */
        asn_struct_ctx_t _asn_ctx;
    } SETId_t;

    /* Implementation */
    extern asn_TYPE_descriptor_t asn_DEF_SETId;

#ifdef __cplusplus
}
#endif

#endif /* _SETId_H_ */
#include <asn_internal.h>
