/*
 * SPDX-FileCopyrightText: (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * SPDX-License-Identifier: BSD-1-Clause
 * Generated by asn1c-0.9.22 (http://lionet.info/asn1c)
 * From ASN.1 module "ULP-Components"
 *     found in "../supl-common.asn"
 */

#include "NMRelement.h"

static int memb_aRFCN_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
    asn_app_constraint_failed_f *ctfailcb,
    void *app_key)
{
    long value;

    if (!sptr)
        {
            _ASN_CTFAIL(app_key, td, sptr, "%s: value not given (%s:%d)",
                td->name, __FILE__, __LINE__);
            return -1;
        }

    value = *(const long *)sptr;

    if ((value >= 0 && value <= 1023))
        {
            /* Constraint check succeeded */
            return 0;
        }
    else
        {
            _ASN_CTFAIL(app_key, td, sptr, "%s: constraint failed (%s:%d)",
                td->name, __FILE__, __LINE__);
            return -1;
        }
}

static int memb_bSIC_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
    asn_app_constraint_failed_f *ctfailcb,
    void *app_key)
{
    long value;

    if (!sptr)
        {
            _ASN_CTFAIL(app_key, td, sptr, "%s: value not given (%s:%d)",
                td->name, __FILE__, __LINE__);
            return -1;
        }

    value = *(const long *)sptr;

    if ((value >= 0 && value <= 63))
        {
            /* Constraint check succeeded */
            return 0;
        }
    else
        {
            _ASN_CTFAIL(app_key, td, sptr, "%s: constraint failed (%s:%d)",
                td->name, __FILE__, __LINE__);
            return -1;
        }
}

static int memb_rxLev_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
    asn_app_constraint_failed_f *ctfailcb,
    void *app_key)
{
    long value;

    if (!sptr)
        {
            _ASN_CTFAIL(app_key, td, sptr, "%s: value not given (%s:%d)",
                td->name, __FILE__, __LINE__);
            return -1;
        }

    value = *(const long *)sptr;

    if ((value >= 0 && value <= 63))
        {
            /* Constraint check succeeded */
            return 0;
        }
    else
        {
            _ASN_CTFAIL(app_key, td, sptr, "%s: constraint failed (%s:%d)",
                td->name, __FILE__, __LINE__);
            return -1;
        }
}

static asn_per_constraints_t ASN_PER_MEMB_A_RFCN_CONSTR_2 = {
    {APC_CONSTRAINED, 10, 10, 0, 1023} /* (0..1023) */,
    {APC_UNCONSTRAINED, -1, -1, 0, 0},
    0,
    0 /* No PER value map */
};
static asn_per_constraints_t ASN_PER_MEMB_B_SIC_CONSTR_3 = {
    {APC_CONSTRAINED, 6, 6, 0, 63} /* (0..63) */,
    {APC_UNCONSTRAINED, -1, -1, 0, 0},
    0,
    0 /* No PER value map */
};
static asn_per_constraints_t ASN_PER_MEMB_RX_LEV_CONSTR_4 = {
    {APC_CONSTRAINED, 6, 6, 0, 63} /* (0..63) */,
    {APC_UNCONSTRAINED, -1, -1, 0, 0},
    0,
    0 /* No PER value map */
};
static asn_TYPE_member_t asn_MBR_NMRelement_1[] = {
    {ATF_NOFLAGS, 0, offsetof(struct NMRelement, aRFCN),
        (ASN_TAG_CLASS_CONTEXT | (0 << 2)), -1, /* IMPLICIT tag at current level */
        &asn_DEF_NativeInteger, memb_aRFCN_constraint_1,
        &ASN_PER_MEMB_A_RFCN_CONSTR_2, 0, "aRFCN"},
    {ATF_NOFLAGS, 0, offsetof(struct NMRelement, bSIC),
        (ASN_TAG_CLASS_CONTEXT | (1 << 2)), -1, /* IMPLICIT tag at current level */
        &asn_DEF_NativeInteger, memb_bSIC_constraint_1,
        &ASN_PER_MEMB_B_SIC_CONSTR_3, 0, "bSIC"},
    {ATF_NOFLAGS, 0, offsetof(struct NMRelement, rxLev),
        (ASN_TAG_CLASS_CONTEXT | (2 << 2)), -1, /* IMPLICIT tag at current level */
        &asn_DEF_NativeInteger, memb_rxLev_constraint_1,
        &ASN_PER_MEMB_RX_LEV_CONSTR_4, 0, "rxLev"},
};
static ber_tlv_tag_t asn_DEF_NMRelement_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))};
static asn_TYPE_tag2member_t asn_MAP_NMRelement_tag2el_1[] = {
    {(ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0}, /* aRFCN at 140 */
    {(ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0}, /* bSIC at 141 */
    {(ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0}  /* rxLev at 142 */
};
static asn_SEQUENCE_specifics_t asn_SPC_NMRelement_specs_1 = {
    sizeof(struct NMRelement),
    offsetof(struct NMRelement, _asn_ctx),
    asn_MAP_NMRelement_tag2el_1,
    3, /* Count of tags in the map */
    0,
    0,
    0, /* Optional elements (not needed) */
    2, /* Start extensions */
    4  /* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_NMRelement = {
    "NMRelement",
    "NMRelement",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    SEQUENCE_decode_uper,
    SEQUENCE_encode_uper,
    0, /* Use generic outmost tag fetcher */
    asn_DEF_NMRelement_tags_1,
    sizeof(asn_DEF_NMRelement_tags_1) /
        sizeof(asn_DEF_NMRelement_tags_1[0]), /* 1 */
    asn_DEF_NMRelement_tags_1,                /* Same as above */
    sizeof(asn_DEF_NMRelement_tags_1) /
        sizeof(asn_DEF_NMRelement_tags_1[0]), /* 1 */
    0,                                        /* No PER visible constraints */
    asn_MBR_NMRelement_1,
    3,                          /* Elements count */
    &asn_SPC_NMRelement_specs_1 /* Additional specs */
};