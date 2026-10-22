/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Users/vboxuser/Desktop/Files/s8_alu.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static unsigned int ng3[] = {5U, 0U};
static unsigned int ng4[] = {2U, 0U};
static unsigned int ng5[] = {3U, 0U};
static unsigned int ng6[] = {4U, 0U};
static unsigned int ng7[] = {6U, 0U};
static unsigned int ng8[] = {7U, 0U};
static unsigned int ng9[] = {8U, 0U};
static unsigned int ng10[] = {9U, 0U};
static unsigned int ng11[] = {10U, 0U};
static unsigned int ng12[] = {11U, 0U};



static void Always_57_0(char *t0)
{
    char t6[8];
    char t14[8];
    char t17[8];
    char t40[8];
    char t55[8];
    char t66[8];
    char t74[8];
    char t90[8];
    char t98[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    int t13;
    char *t15;
    char *t16;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    char *t39;
    char *t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    char *t47;
    char *t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    char *t52;
    char *t53;
    char *t54;
    char *t56;
    char *t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    char *t64;
    char *t65;
    char *t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    char *t75;
    char *t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    char *t89;
    char *t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    char *t97;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    char *t102;
    char *t103;
    char *t104;
    unsigned int t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    char *t112;
    char *t113;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    unsigned int t119;
    unsigned int t120;
    unsigned int t121;
    int t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t125;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    char *t129;
    int t130;
    int t131;

LAB0:    t1 = (t0 + 5440U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(57, ng0);
    t2 = (t0 + 5760);
    *((int *)t2) = 1;
    t3 = (t0 + 5472);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(57, ng0);

LAB5:    xsi_set_current_line(59, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t0 + 3400);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 8);
    xsi_set_current_line(60, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3560);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(61, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3720);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(62, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3880);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(63, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4040);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(64, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4200);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 9);
    xsi_set_current_line(65, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4360);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(66, ng0);
    t2 = (t0 + 2840U);
    t3 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t4 = (t3 + 4);
    t7 = *((unsigned int *)t3);
    t8 = (t7 >> 0);
    *((unsigned int *)t6) = t8;
    t9 = *((unsigned int *)t4);
    t10 = (t9 >> 0);
    *((unsigned int *)t2) = t10;
    t11 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t11 & 7U);
    t12 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t12 & 7U);
    t5 = (t0 + 4520);
    xsi_vlogvar_assign_value(t5, t6, 0, 0, 3);
    xsi_set_current_line(68, ng0);
    t2 = (t0 + 3000U);
    t3 = *((char **)t2);

LAB6:    t2 = ((char*)((ng1)));
    t13 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t13 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng2)));
    t13 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t13 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng3)));
    t13 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t13 == 1)
        goto LAB11;

LAB12:    t4 = ((char*)((ng4)));
    t122 = xsi_vlog_unsigned_case_compare(t3, 4, t4, 4);
    if (t122 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng5)));
    t13 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t13 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng6)));
    t13 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t13 == 1)
        goto LAB17;

LAB18:    t2 = ((char*)((ng7)));
    t13 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t13 == 1)
        goto LAB19;

LAB20:    t2 = ((char*)((ng8)));
    t13 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t13 == 1)
        goto LAB21;

LAB22:    t2 = ((char*)((ng9)));
    t13 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t13 == 1)
        goto LAB23;

LAB24:    t2 = ((char*)((ng10)));
    t13 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t13 == 1)
        goto LAB25;

LAB26:    t2 = ((char*)((ng11)));
    t13 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t13 == 1)
        goto LAB27;

LAB28:    t2 = ((char*)((ng12)));
    t13 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t13 == 1)
        goto LAB29;

LAB30:
LAB32:
LAB31:    xsi_set_current_line(190, ng0);

LAB226:
LAB33:    goto LAB2;

LAB7:    xsi_set_current_line(69, ng0);

LAB34:    xsi_set_current_line(70, ng0);
    t4 = (t0 + 2680U);
    t5 = *((char **)t4);
    t4 = ((char*)((ng1)));
    xsi_vlogtype_concat(t6, 9, 9, 2U, t4, 1, t5, 8);
    t15 = (t0 + 2840U);
    t16 = *((char **)t15);
    t15 = ((char*)((ng1)));
    xsi_vlogtype_concat(t14, 9, 9, 2U, t15, 1, t16, 8);
    memset(t17, 0, 8);
    xsi_vlog_unsigned_add(t17, 9, t6, 9, t14, 9);
    t18 = (t0 + 4200);
    xsi_vlogvar_assign_value(t18, t17, 0, 0, 9);
    xsi_set_current_line(71, ng0);
    t2 = (t0 + 4200);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t15 = (t6 + 4);
    t16 = (t5 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (t7 >> 0);
    *((unsigned int *)t6) = t8;
    t9 = *((unsigned int *)t16);
    t10 = (t9 >> 0);
    *((unsigned int *)t15) = t10;
    t11 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t11 & 255U);
    t12 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t12 & 255U);
    t18 = (t0 + 3400);
    xsi_vlogvar_assign_value(t18, t6, 0, 0, 8);
    xsi_set_current_line(72, ng0);
    t2 = (t0 + 4200);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t15 = (t6 + 4);
    t16 = (t5 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (t7 >> 8);
    t9 = (t8 & 1);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t16);
    t11 = (t10 >> 8);
    t12 = (t11 & 1);
    *((unsigned int *)t15) = t12;
    t18 = (t0 + 3720);
    xsi_vlogvar_assign_value(t18, t6, 0, 0, 1);
    xsi_set_current_line(73, ng0);
    t2 = (t0 + 3400);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t15 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t16 = (t5 + 4);
    t18 = (t15 + 4);
    t7 = *((unsigned int *)t5);
    t8 = *((unsigned int *)t15);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t16);
    t11 = *((unsigned int *)t18);
    t12 = (t10 ^ t11);
    t19 = (t9 | t12);
    t20 = *((unsigned int *)t16);
    t21 = *((unsigned int *)t18);
    t22 = (t20 | t21);
    t23 = (~(t22));
    t24 = (t19 & t23);
    if (t24 != 0)
        goto LAB38;

LAB35:    if (t22 != 0)
        goto LAB37;

LAB36:    *((unsigned int *)t6) = 1;

LAB38:    t26 = (t0 + 3560);
    xsi_vlogvar_assign_value(t26, t6, 0, 0, 1);
    xsi_set_current_line(74, ng0);
    t2 = (t0 + 3400);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t15 = (t6 + 4);
    t16 = (t5 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (t7 >> 7);
    t9 = (t8 & 1);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t16);
    t11 = (t10 >> 7);
    t12 = (t11 & 1);
    *((unsigned int *)t15) = t12;
    t18 = (t0 + 3880);
    xsi_vlogvar_assign_value(t18, t6, 0, 0, 1);
    xsi_set_current_line(76, ng0);
    t2 = (t0 + 2680U);
    t4 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t5 = (t4 + 4);
    t7 = *((unsigned int *)t4);
    t8 = (t7 >> 7);
    t9 = (t8 & 1);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t5);
    t11 = (t10 >> 7);
    t12 = (t11 & 1);
    *((unsigned int *)t2) = t12;
    t15 = (t0 + 2840U);
    t16 = *((char **)t15);
    memset(t14, 0, 8);
    t15 = (t14 + 4);
    t18 = (t16 + 4);
    t19 = *((unsigned int *)t16);
    t20 = (t19 >> 7);
    t21 = (t20 & 1);
    *((unsigned int *)t14) = t21;
    t22 = *((unsigned int *)t18);
    t23 = (t22 >> 7);
    t24 = (t23 & 1);
    *((unsigned int *)t15) = t24;
    memset(t17, 0, 8);
    t25 = (t6 + 4);
    t26 = (t14 + 4);
    t27 = *((unsigned int *)t6);
    t28 = *((unsigned int *)t14);
    t29 = (t27 ^ t28);
    t30 = *((unsigned int *)t25);
    t31 = *((unsigned int *)t26);
    t32 = (t30 ^ t31);
    t33 = (t29 | t32);
    t34 = *((unsigned int *)t25);
    t35 = *((unsigned int *)t26);
    t36 = (t34 | t35);
    t37 = (~(t36));
    t38 = (t33 & t37);
    if (t38 != 0)
        goto LAB42;

LAB39:    if (t36 != 0)
        goto LAB41;

LAB40:    *((unsigned int *)t17) = 1;

LAB42:    memset(t40, 0, 8);
    t41 = (t17 + 4);
    t42 = *((unsigned int *)t41);
    t43 = (~(t42));
    t44 = *((unsigned int *)t17);
    t45 = (t44 & t43);
    t46 = (t45 & 1U);
    if (t46 != 0)
        goto LAB43;

LAB44:    if (*((unsigned int *)t41) != 0)
        goto LAB45;

LAB46:    t48 = (t40 + 4);
    t49 = *((unsigned int *)t40);
    t50 = *((unsigned int *)t48);
    t51 = (t49 || t50);
    if (t51 > 0)
        goto LAB47;

LAB48:    memcpy(t98, t40, 8);

LAB49:    t129 = (t0 + 4040);
    xsi_vlogvar_assign_value(t129, t98, 0, 0, 1);
    goto LAB33;

LAB9:    xsi_set_current_line(80, ng0);

LAB61:    xsi_set_current_line(81, ng0);
    t4 = (t0 + 2680U);
    t5 = *((char **)t4);
    t4 = ((char*)((ng1)));
    xsi_vlogtype_concat(t6, 9, 9, 2U, t4, 1, t5, 8);
    t15 = (t0 + 2840U);
    t16 = *((char **)t15);
    t15 = ((char*)((ng1)));
    xsi_vlogtype_concat(t14, 9, 9, 2U, t15, 1, t16, 8);
    memset(t17, 0, 8);
    xsi_vlog_unsigned_minus(t17, 9, t6, 9, t14, 9);
    t18 = (t0 + 4200);
    xsi_vlogvar_assign_value(t18, t17, 0, 0, 9);
    xsi_set_current_line(82, ng0);
    t2 = (t0 + 4200);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t15 = (t6 + 4);
    t16 = (t5 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (t7 >> 0);
    *((unsigned int *)t6) = t8;
    t9 = *((unsigned int *)t16);
    t10 = (t9 >> 0);
    *((unsigned int *)t15) = t10;
    t11 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t11 & 255U);
    t12 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t12 & 255U);
    t18 = (t0 + 3400);
    xsi_vlogvar_assign_value(t18, t6, 0, 0, 8);
    xsi_set_current_line(83, ng0);
    t2 = (t0 + 4200);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t14, 0, 8);
    t15 = (t14 + 4);
    t16 = (t5 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (t7 >> 8);
    t9 = (t8 & 1);
    *((unsigned int *)t14) = t9;
    t10 = *((unsigned int *)t16);
    t11 = (t10 >> 8);
    t12 = (t11 & 1);
    *((unsigned int *)t15) = t12;
    memset(t6, 0, 8);
    t18 = (t14 + 4);
    t19 = *((unsigned int *)t18);
    t20 = (~(t19));
    t21 = *((unsigned int *)t14);
    t22 = (t21 & t20);
    t23 = (t22 & 1U);
    if (t23 != 0)
        goto LAB65;

LAB63:    if (*((unsigned int *)t18) == 0)
        goto LAB62;

LAB64:    t25 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t25) = 1;

LAB65:    t26 = (t6 + 4);
    t39 = (t14 + 4);
    t24 = *((unsigned int *)t14);
    t27 = (~(t24));
    *((unsigned int *)t6) = t27;
    *((unsigned int *)t26) = 0;
    if (*((unsigned int *)t39) != 0)
        goto LAB67;

LAB66:    t32 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t32 & 1U);
    t33 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t33 & 1U);
    t41 = (t0 + 3720);
    xsi_vlogvar_assign_value(t41, t6, 0, 0, 1);
    xsi_set_current_line(84, ng0);
    t2 = (t0 + 3400);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t15 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t16 = (t5 + 4);
    t18 = (t15 + 4);
    t7 = *((unsigned int *)t5);
    t8 = *((unsigned int *)t15);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t16);
    t11 = *((unsigned int *)t18);
    t12 = (t10 ^ t11);
    t19 = (t9 | t12);
    t20 = *((unsigned int *)t16);
    t21 = *((unsigned int *)t18);
    t22 = (t20 | t21);
    t23 = (~(t22));
    t24 = (t19 & t23);
    if (t24 != 0)
        goto LAB71;

LAB68:    if (t22 != 0)
        goto LAB70;

LAB69:    *((unsigned int *)t6) = 1;

LAB71:    t26 = (t0 + 3560);
    xsi_vlogvar_assign_value(t26, t6, 0, 0, 1);
    xsi_set_current_line(85, ng0);
    t2 = (t0 + 3400);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t15 = (t6 + 4);
    t16 = (t5 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (t7 >> 7);
    t9 = (t8 & 1);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t16);
    t11 = (t10 >> 7);
    t12 = (t11 & 1);
    *((unsigned int *)t15) = t12;
    t18 = (t0 + 3880);
    xsi_vlogvar_assign_value(t18, t6, 0, 0, 1);
    xsi_set_current_line(87, ng0);
    t2 = (t0 + 2680U);
    t4 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t5 = (t4 + 4);
    t7 = *((unsigned int *)t4);
    t8 = (t7 >> 7);
    t9 = (t8 & 1);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t5);
    t11 = (t10 >> 7);
    t12 = (t11 & 1);
    *((unsigned int *)t2) = t12;
    t15 = (t0 + 2840U);
    t16 = *((char **)t15);
    memset(t14, 0, 8);
    t15 = (t14 + 4);
    t18 = (t16 + 4);
    t19 = *((unsigned int *)t16);
    t20 = (t19 >> 7);
    t21 = (t20 & 1);
    *((unsigned int *)t14) = t21;
    t22 = *((unsigned int *)t18);
    t23 = (t22 >> 7);
    t24 = (t23 & 1);
    *((unsigned int *)t15) = t24;
    memset(t17, 0, 8);
    t25 = (t6 + 4);
    t26 = (t14 + 4);
    t27 = *((unsigned int *)t6);
    t28 = *((unsigned int *)t14);
    t29 = (t27 ^ t28);
    t30 = *((unsigned int *)t25);
    t31 = *((unsigned int *)t26);
    t32 = (t30 ^ t31);
    t33 = (t29 | t32);
    t34 = *((unsigned int *)t25);
    t35 = *((unsigned int *)t26);
    t36 = (t34 | t35);
    t37 = (~(t36));
    t38 = (t33 & t37);
    if (t38 != 0)
        goto LAB73;

LAB72:    if (t36 != 0)
        goto LAB74;

LAB75:    memset(t40, 0, 8);
    t41 = (t17 + 4);
    t42 = *((unsigned int *)t41);
    t43 = (~(t42));
    t44 = *((unsigned int *)t17);
    t45 = (t44 & t43);
    t46 = (t45 & 1U);
    if (t46 != 0)
        goto LAB76;

LAB77:    if (*((unsigned int *)t41) != 0)
        goto LAB78;

LAB79:    t48 = (t40 + 4);
    t49 = *((unsigned int *)t40);
    t50 = *((unsigned int *)t48);
    t51 = (t49 || t50);
    if (t51 > 0)
        goto LAB80;

LAB81:    memcpy(t98, t40, 8);

LAB82:    t129 = (t0 + 4040);
    xsi_vlogvar_assign_value(t129, t98, 0, 0, 1);
    goto LAB33;

LAB11:    goto LAB9;

LAB13:    xsi_set_current_line(90, ng0);

LAB94:    xsi_set_current_line(91, ng0);
    t5 = (t0 + 2680U);
    t15 = *((char **)t5);
    t5 = (t0 + 2840U);
    t16 = *((char **)t5);
    t7 = *((unsigned int *)t15);
    t8 = *((unsigned int *)t16);
    t9 = (t7 & t8);
    *((unsigned int *)t6) = t9;
    t5 = (t15 + 4);
    t18 = (t16 + 4);
    t25 = (t6 + 4);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t18);
    t12 = (t10 | t11);
    *((unsigned int *)t25) = t12;
    t19 = *((unsigned int *)t25);
    t20 = (t19 != 0);
    if (t20 == 1)
        goto LAB95;

LAB96:
LAB97:    t41 = (t0 + 3400);
    xsi_vlogvar_assign_value(t41, t6, 0, 0, 8);
    xsi_set_current_line(92, ng0);
    t2 = (t0 + 3400);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t15 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t16 = (t5 + 4);
    t18 = (t15 + 4);
    t7 = *((unsigned int *)t5);
    t8 = *((unsigned int *)t15);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t16);
    t11 = *((unsigned int *)t18);
    t12 = (t10 ^ t11);
    t19 = (t9 | t12);
    t20 = *((unsigned int *)t16);
    t21 = *((unsigned int *)t18);
    t22 = (t20 | t21);
    t23 = (~(t22));
    t24 = (t19 & t23);
    if (t24 != 0)
        goto LAB101;

LAB98:    if (t22 != 0)
        goto LAB100;

LAB99:    *((unsigned int *)t6) = 1;

LAB101:    t26 = (t0 + 3560);
    xsi_vlogvar_assign_value(t26, t6, 0, 0, 1);
    xsi_set_current_line(93, ng0);
    t2 = (t0 + 3400);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t15 = (t6 + 4);
    t16 = (t5 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (t7 >> 7);
    t9 = (t8 & 1);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t16);
    t11 = (t10 >> 7);
    t12 = (t11 & 1);
    *((unsigned int *)t15) = t12;
    t18 = (t0 + 3880);
    xsi_vlogvar_assign_value(t18, t6, 0, 0, 1);
    goto LAB33;

LAB15:    xsi_set_current_line(96, ng0);

LAB102:    xsi_set_current_line(97, ng0);
    t4 = (t0 + 2680U);
    t5 = *((char **)t4);
    t4 = (t0 + 2840U);
    t15 = *((char **)t4);
    t7 = *((unsigned int *)t5);
    t8 = *((unsigned int *)t15);
    t9 = (t7 | t8);
    *((unsigned int *)t6) = t9;
    t4 = (t5 + 4);
    t16 = (t15 + 4);
    t18 = (t6 + 4);
    t10 = *((unsigned int *)t4);
    t11 = *((unsigned int *)t16);
    t12 = (t10 | t11);
    *((unsigned int *)t18) = t12;
    t19 = *((unsigned int *)t18);
    t20 = (t19 != 0);
    if (t20 == 1)
        goto LAB103;

LAB104:
LAB105:    t39 = (t0 + 3400);
    xsi_vlogvar_assign_value(t39, t6, 0, 0, 8);
    xsi_set_current_line(98, ng0);
    t2 = (t0 + 3400);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t15 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t16 = (t5 + 4);
    t18 = (t15 + 4);
    t7 = *((unsigned int *)t5);
    t8 = *((unsigned int *)t15);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t16);
    t11 = *((unsigned int *)t18);
    t12 = (t10 ^ t11);
    t19 = (t9 | t12);
    t20 = *((unsigned int *)t16);
    t21 = *((unsigned int *)t18);
    t22 = (t20 | t21);
    t23 = (~(t22));
    t24 = (t19 & t23);
    if (t24 != 0)
        goto LAB109;

LAB106:    if (t22 != 0)
        goto LAB108;

LAB107:    *((unsigned int *)t6) = 1;

LAB109:    t26 = (t0 + 3560);
    xsi_vlogvar_assign_value(t26, t6, 0, 0, 1);
    xsi_set_current_line(99, ng0);
    t2 = (t0 + 3400);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t15 = (t6 + 4);
    t16 = (t5 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (t7 >> 7);
    t9 = (t8 & 1);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t16);
    t11 = (t10 >> 7);
    t12 = (t11 & 1);
    *((unsigned int *)t15) = t12;
    t18 = (t0 + 3880);
    xsi_vlogvar_assign_value(t18, t6, 0, 0, 1);
    goto LAB33;

LAB17:    xsi_set_current_line(102, ng0);

LAB110:    xsi_set_current_line(103, ng0);
    t4 = (t0 + 2680U);
    t5 = *((char **)t4);
    t4 = (t0 + 2840U);
    t15 = *((char **)t4);
    t7 = *((unsigned int *)t5);
    t8 = *((unsigned int *)t15);
    t9 = (t7 ^ t8);
    *((unsigned int *)t6) = t9;
    t4 = (t5 + 4);
    t16 = (t15 + 4);
    t18 = (t6 + 4);
    t10 = *((unsigned int *)t4);
    t11 = *((unsigned int *)t16);
    t12 = (t10 | t11);
    *((unsigned int *)t18) = t12;
    t19 = *((unsigned int *)t18);
    t20 = (t19 != 0);
    if (t20 == 1)
        goto LAB111;

LAB112:
LAB113:    t25 = (t0 + 3400);
    xsi_vlogvar_assign_value(t25, t6, 0, 0, 8);
    xsi_set_current_line(104, ng0);
    t2 = (t0 + 3400);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t15 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t16 = (t5 + 4);
    t18 = (t15 + 4);
    t7 = *((unsigned int *)t5);
    t8 = *((unsigned int *)t15);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t16);
    t11 = *((unsigned int *)t18);
    t12 = (t10 ^ t11);
    t19 = (t9 | t12);
    t20 = *((unsigned int *)t16);
    t21 = *((unsigned int *)t18);
    t22 = (t20 | t21);
    t23 = (~(t22));
    t24 = (t19 & t23);
    if (t24 != 0)
        goto LAB117;

LAB114:    if (t22 != 0)
        goto LAB116;

LAB115:    *((unsigned int *)t6) = 1;

LAB117:    t26 = (t0 + 3560);
    xsi_vlogvar_assign_value(t26, t6, 0, 0, 1);
    xsi_set_current_line(105, ng0);
    t2 = (t0 + 3400);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t15 = (t6 + 4);
    t16 = (t5 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (t7 >> 7);
    t9 = (t8 & 1);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t16);
    t11 = (t10 >> 7);
    t12 = (t11 & 1);
    *((unsigned int *)t15) = t12;
    t18 = (t0 + 3880);
    xsi_vlogvar_assign_value(t18, t6, 0, 0, 1);
    goto LAB33;

LAB19:    xsi_set_current_line(108, ng0);

LAB118:    xsi_set_current_line(109, ng0);
    t4 = (t0 + 2840U);
    t5 = *((char **)t4);
    t4 = (t0 + 3400);
    xsi_vlogvar_assign_value(t4, t5, 0, 0, 8);
    xsi_set_current_line(110, ng0);
    t2 = (t0 + 3400);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t15 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t16 = (t5 + 4);
    t18 = (t15 + 4);
    t7 = *((unsigned int *)t5);
    t8 = *((unsigned int *)t15);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t16);
    t11 = *((unsigned int *)t18);
    t12 = (t10 ^ t11);
    t19 = (t9 | t12);
    t20 = *((unsigned int *)t16);
    t21 = *((unsigned int *)t18);
    t22 = (t20 | t21);
    t23 = (~(t22));
    t24 = (t19 & t23);
    if (t24 != 0)
        goto LAB122;

LAB119:    if (t22 != 0)
        goto LAB121;

LAB120:    *((unsigned int *)t6) = 1;

LAB122:    t26 = (t0 + 3560);
    xsi_vlogvar_assign_value(t26, t6, 0, 0, 1);
    xsi_set_current_line(111, ng0);
    t2 = (t0 + 3400);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t15 = (t6 + 4);
    t16 = (t5 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (t7 >> 7);
    t9 = (t8 & 1);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t16);
    t11 = (t10 >> 7);
    t12 = (t11 & 1);
    *((unsigned int *)t15) = t12;
    t18 = (t0 + 3880);
    xsi_vlogvar_assign_value(t18, t6, 0, 0, 1);
    goto LAB33;

LAB21:    xsi_set_current_line(114, ng0);

LAB123:    xsi_set_current_line(115, ng0);
    t4 = (t0 + 2840U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t6 + 4);
    t15 = (t5 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (~(t7));
    *((unsigned int *)t6) = t8;
    *((unsigned int *)t4) = 0;
    if (*((unsigned int *)t15) != 0)
        goto LAB125;

LAB124:    t19 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t19 & 255U);
    t20 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t20 & 255U);
    t16 = (t0 + 3400);
    xsi_vlogvar_assign_value(t16, t6, 0, 0, 8);
    xsi_set_current_line(116, ng0);
    t2 = (t0 + 3400);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t15 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t16 = (t5 + 4);
    t18 = (t15 + 4);
    t7 = *((unsigned int *)t5);
    t8 = *((unsigned int *)t15);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t16);
    t11 = *((unsigned int *)t18);
    t12 = (t10 ^ t11);
    t19 = (t9 | t12);
    t20 = *((unsigned int *)t16);
    t21 = *((unsigned int *)t18);
    t22 = (t20 | t21);
    t23 = (~(t22));
    t24 = (t19 & t23);
    if (t24 != 0)
        goto LAB129;

LAB126:    if (t22 != 0)
        goto LAB128;

LAB127:    *((unsigned int *)t6) = 1;

LAB129:    t26 = (t0 + 3560);
    xsi_vlogvar_assign_value(t26, t6, 0, 0, 1);
    xsi_set_current_line(117, ng0);
    t2 = (t0 + 3400);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t15 = (t6 + 4);
    t16 = (t5 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (t7 >> 7);
    t9 = (t8 & 1);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t16);
    t11 = (t10 >> 7);
    t12 = (t11 & 1);
    *((unsigned int *)t15) = t12;
    t18 = (t0 + 3880);
    xsi_vlogvar_assign_value(t18, t6, 0, 0, 1);
    goto LAB33;

LAB23:    xsi_set_current_line(120, ng0);

LAB130:    xsi_set_current_line(121, ng0);
    t4 = (t0 + 2680U);
    t5 = *((char **)t4);
    t4 = (t0 + 4520);
    t15 = (t4 + 56U);
    t16 = *((char **)t15);
    memset(t6, 0, 8);
    xsi_vlog_unsigned_lshift(t6, 8, t5, 8, t16, 3);
    t18 = (t0 + 4360);
    xsi_vlogvar_assign_value(t18, t6, 0, 0, 8);
    xsi_set_current_line(122, ng0);
    t2 = (t0 + 4360);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t15 = (t0 + 3400);
    xsi_vlogvar_assign_value(t15, t5, 0, 0, 8);
    xsi_set_current_line(124, ng0);
    t2 = (t0 + 4520);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);

LAB131:    t15 = ((char*)((ng2)));
    t13 = xsi_vlog_unsigned_case_compare(t5, 3, t15, 3);
    if (t13 == 1)
        goto LAB132;

LAB133:    t2 = ((char*)((ng4)));
    t13 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t13 == 1)
        goto LAB134;

LAB135:    t2 = ((char*)((ng5)));
    t13 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t13 == 1)
        goto LAB136;

LAB137:    t2 = ((char*)((ng6)));
    t13 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t13 == 1)
        goto LAB138;

LAB139:    t2 = ((char*)((ng3)));
    t13 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t13 == 1)
        goto LAB140;

LAB141:    t2 = ((char*)((ng7)));
    t13 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t13 == 1)
        goto LAB142;

LAB143:    t2 = ((char*)((ng8)));
    t13 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t13 == 1)
        goto LAB144;

LAB145:
LAB147:
LAB146:    xsi_set_current_line(132, ng0);
    t2 = ((char*)((ng1)));
    t4 = (t0 + 3720);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);

LAB148:    xsi_set_current_line(134, ng0);
    t2 = (t0 + 3400);
    t4 = (t2 + 56U);
    t15 = *((char **)t4);
    t16 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t18 = (t15 + 4);
    t25 = (t16 + 4);
    t7 = *((unsigned int *)t15);
    t8 = *((unsigned int *)t16);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t18);
    t11 = *((unsigned int *)t25);
    t12 = (t10 ^ t11);
    t19 = (t9 | t12);
    t20 = *((unsigned int *)t18);
    t21 = *((unsigned int *)t25);
    t22 = (t20 | t21);
    t23 = (~(t22));
    t24 = (t19 & t23);
    if (t24 != 0)
        goto LAB152;

LAB149:    if (t22 != 0)
        goto LAB151;

LAB150:    *((unsigned int *)t6) = 1;

LAB152:    t39 = (t0 + 3560);
    xsi_vlogvar_assign_value(t39, t6, 0, 0, 1);
    xsi_set_current_line(135, ng0);
    t2 = (t0 + 3400);
    t4 = (t2 + 56U);
    t15 = *((char **)t4);
    memset(t6, 0, 8);
    t16 = (t6 + 4);
    t18 = (t15 + 4);
    t7 = *((unsigned int *)t15);
    t8 = (t7 >> 7);
    t9 = (t8 & 1);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t18);
    t11 = (t10 >> 7);
    t12 = (t11 & 1);
    *((unsigned int *)t16) = t12;
    t25 = (t0 + 3880);
    xsi_vlogvar_assign_value(t25, t6, 0, 0, 1);
    goto LAB33;

LAB25:    xsi_set_current_line(138, ng0);

LAB153:    xsi_set_current_line(139, ng0);
    t4 = (t0 + 2680U);
    t15 = *((char **)t4);
    t4 = (t0 + 4520);
    t16 = (t4 + 56U);
    t18 = *((char **)t16);
    memset(t6, 0, 8);
    xsi_vlog_unsigned_rshift(t6, 8, t15, 8, t18, 3);
    t25 = (t0 + 4360);
    xsi_vlogvar_assign_value(t25, t6, 0, 0, 8);
    xsi_set_current_line(140, ng0);
    t2 = (t0 + 4360);
    t4 = (t2 + 56U);
    t15 = *((char **)t4);
    t16 = (t0 + 3400);
    xsi_vlogvar_assign_value(t16, t15, 0, 0, 8);
    xsi_set_current_line(142, ng0);
    t2 = (t0 + 4520);
    t4 = (t2 + 56U);
    t15 = *((char **)t4);

LAB154:    t16 = ((char*)((ng2)));
    t13 = xsi_vlog_unsigned_case_compare(t15, 3, t16, 3);
    if (t13 == 1)
        goto LAB155;

LAB156:    t2 = ((char*)((ng4)));
    t13 = xsi_vlog_unsigned_case_compare(t15, 3, t2, 3);
    if (t13 == 1)
        goto LAB157;

LAB158:    t2 = ((char*)((ng5)));
    t13 = xsi_vlog_unsigned_case_compare(t15, 3, t2, 3);
    if (t13 == 1)
        goto LAB159;

LAB160:    t2 = ((char*)((ng6)));
    t13 = xsi_vlog_unsigned_case_compare(t15, 3, t2, 3);
    if (t13 == 1)
        goto LAB161;

LAB162:    t2 = ((char*)((ng3)));
    t13 = xsi_vlog_unsigned_case_compare(t15, 3, t2, 3);
    if (t13 == 1)
        goto LAB163;

LAB164:    t2 = ((char*)((ng7)));
    t13 = xsi_vlog_unsigned_case_compare(t15, 3, t2, 3);
    if (t13 == 1)
        goto LAB165;

LAB166:    t2 = ((char*)((ng8)));
    t13 = xsi_vlog_unsigned_case_compare(t15, 3, t2, 3);
    if (t13 == 1)
        goto LAB167;

LAB168:
LAB170:
LAB169:    xsi_set_current_line(150, ng0);
    t2 = ((char*)((ng1)));
    t4 = (t0 + 3720);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);

LAB171:    xsi_set_current_line(152, ng0);
    t2 = (t0 + 3400);
    t4 = (t2 + 56U);
    t16 = *((char **)t4);
    t18 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t25 = (t16 + 4);
    t26 = (t18 + 4);
    t7 = *((unsigned int *)t16);
    t8 = *((unsigned int *)t18);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t25);
    t11 = *((unsigned int *)t26);
    t12 = (t10 ^ t11);
    t19 = (t9 | t12);
    t20 = *((unsigned int *)t25);
    t21 = *((unsigned int *)t26);
    t22 = (t20 | t21);
    t23 = (~(t22));
    t24 = (t19 & t23);
    if (t24 != 0)
        goto LAB175;

LAB172:    if (t22 != 0)
        goto LAB174;

LAB173:    *((unsigned int *)t6) = 1;

LAB175:    t41 = (t0 + 3560);
    xsi_vlogvar_assign_value(t41, t6, 0, 0, 1);
    xsi_set_current_line(153, ng0);
    t2 = (t0 + 3400);
    t4 = (t2 + 56U);
    t16 = *((char **)t4);
    memset(t6, 0, 8);
    t18 = (t6 + 4);
    t25 = (t16 + 4);
    t7 = *((unsigned int *)t16);
    t8 = (t7 >> 7);
    t9 = (t8 & 1);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t25);
    t11 = (t10 >> 7);
    t12 = (t11 & 1);
    *((unsigned int *)t18) = t12;
    t26 = (t0 + 3880);
    xsi_vlogvar_assign_value(t26, t6, 0, 0, 1);
    goto LAB33;

LAB27:    xsi_set_current_line(156, ng0);

LAB176:    xsi_set_current_line(157, ng0);
    t4 = (t0 + 4520);
    t16 = (t4 + 56U);
    t18 = *((char **)t16);

LAB177:    t25 = ((char*)((ng1)));
    t122 = xsi_vlog_unsigned_case_compare(t18, 3, t25, 3);
    if (t122 == 1)
        goto LAB178;

LAB179:    t2 = ((char*)((ng2)));
    t13 = xsi_vlog_unsigned_case_compare(t18, 3, t2, 3);
    if (t13 == 1)
        goto LAB180;

LAB181:    t2 = ((char*)((ng4)));
    t13 = xsi_vlog_unsigned_case_compare(t18, 3, t2, 3);
    if (t13 == 1)
        goto LAB182;

LAB183:    t2 = ((char*)((ng5)));
    t13 = xsi_vlog_unsigned_case_compare(t18, 3, t2, 3);
    if (t13 == 1)
        goto LAB184;

LAB185:    t2 = ((char*)((ng6)));
    t13 = xsi_vlog_unsigned_case_compare(t18, 3, t2, 3);
    if (t13 == 1)
        goto LAB186;

LAB187:    t2 = ((char*)((ng3)));
    t13 = xsi_vlog_unsigned_case_compare(t18, 3, t2, 3);
    if (t13 == 1)
        goto LAB188;

LAB189:    t2 = ((char*)((ng7)));
    t13 = xsi_vlog_unsigned_case_compare(t18, 3, t2, 3);
    if (t13 == 1)
        goto LAB190;

LAB191:    t2 = ((char*)((ng8)));
    t13 = xsi_vlog_unsigned_case_compare(t18, 3, t2, 3);
    if (t13 == 1)
        goto LAB192;

LAB193:
LAB195:
LAB194:    xsi_set_current_line(166, ng0);
    t2 = (t0 + 2680U);
    t4 = *((char **)t2);
    t2 = (t0 + 3400);
    xsi_vlogvar_assign_value(t2, t4, 0, 0, 8);

LAB196:    xsi_set_current_line(168, ng0);
    t2 = (t0 + 3400);
    t4 = (t2 + 56U);
    t16 = *((char **)t4);
    t25 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t26 = (t16 + 4);
    t39 = (t25 + 4);
    t7 = *((unsigned int *)t16);
    t8 = *((unsigned int *)t25);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t26);
    t11 = *((unsigned int *)t39);
    t12 = (t10 ^ t11);
    t19 = (t9 | t12);
    t20 = *((unsigned int *)t26);
    t21 = *((unsigned int *)t39);
    t22 = (t20 | t21);
    t23 = (~(t22));
    t24 = (t19 & t23);
    if (t24 != 0)
        goto LAB200;

LAB197:    if (t22 != 0)
        goto LAB199;

LAB198:    *((unsigned int *)t6) = 1;

LAB200:    t47 = (t0 + 3560);
    xsi_vlogvar_assign_value(t47, t6, 0, 0, 1);
    xsi_set_current_line(169, ng0);
    t2 = (t0 + 3400);
    t4 = (t2 + 56U);
    t16 = *((char **)t4);
    memset(t6, 0, 8);
    t25 = (t6 + 4);
    t26 = (t16 + 4);
    t7 = *((unsigned int *)t16);
    t8 = (t7 >> 7);
    t9 = (t8 & 1);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t26);
    t11 = (t10 >> 7);
    t12 = (t11 & 1);
    *((unsigned int *)t25) = t12;
    t39 = (t0 + 3880);
    xsi_vlogvar_assign_value(t39, t6, 0, 0, 1);
    goto LAB33;

LAB29:    xsi_set_current_line(173, ng0);

LAB201:    xsi_set_current_line(174, ng0);
    t4 = (t0 + 4520);
    t16 = (t4 + 56U);
    t25 = *((char **)t16);

LAB202:    t26 = ((char*)((ng1)));
    t122 = xsi_vlog_unsigned_case_compare(t25, 3, t26, 3);
    if (t122 == 1)
        goto LAB203;

LAB204:    t2 = ((char*)((ng2)));
    t13 = xsi_vlog_unsigned_case_compare(t25, 3, t2, 3);
    if (t13 == 1)
        goto LAB205;

LAB206:    t2 = ((char*)((ng4)));
    t13 = xsi_vlog_unsigned_case_compare(t25, 3, t2, 3);
    if (t13 == 1)
        goto LAB207;

LAB208:    t2 = ((char*)((ng5)));
    t13 = xsi_vlog_unsigned_case_compare(t25, 3, t2, 3);
    if (t13 == 1)
        goto LAB209;

LAB210:    t2 = ((char*)((ng6)));
    t13 = xsi_vlog_unsigned_case_compare(t25, 3, t2, 3);
    if (t13 == 1)
        goto LAB211;

LAB212:    t2 = ((char*)((ng3)));
    t13 = xsi_vlog_unsigned_case_compare(t25, 3, t2, 3);
    if (t13 == 1)
        goto LAB213;

LAB214:    t2 = ((char*)((ng7)));
    t13 = xsi_vlog_unsigned_case_compare(t25, 3, t2, 3);
    if (t13 == 1)
        goto LAB215;

LAB216:    t2 = ((char*)((ng8)));
    t13 = xsi_vlog_unsigned_case_compare(t25, 3, t2, 3);
    if (t13 == 1)
        goto LAB217;

LAB218:
LAB220:
LAB219:    xsi_set_current_line(183, ng0);
    t2 = (t0 + 2680U);
    t4 = *((char **)t2);
    t2 = (t0 + 3400);
    xsi_vlogvar_assign_value(t2, t4, 0, 0, 8);

LAB221:    xsi_set_current_line(185, ng0);
    t2 = (t0 + 3400);
    t4 = (t2 + 56U);
    t16 = *((char **)t4);
    t26 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t39 = (t16 + 4);
    t41 = (t26 + 4);
    t7 = *((unsigned int *)t16);
    t8 = *((unsigned int *)t26);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t39);
    t11 = *((unsigned int *)t41);
    t12 = (t10 ^ t11);
    t19 = (t9 | t12);
    t20 = *((unsigned int *)t39);
    t21 = *((unsigned int *)t41);
    t22 = (t20 | t21);
    t23 = (~(t22));
    t24 = (t19 & t23);
    if (t24 != 0)
        goto LAB225;

LAB222:    if (t22 != 0)
        goto LAB224;

LAB223:    *((unsigned int *)t6) = 1;

LAB225:    t48 = (t0 + 3560);
    xsi_vlogvar_assign_value(t48, t6, 0, 0, 1);
    xsi_set_current_line(186, ng0);
    t2 = (t0 + 3400);
    t4 = (t2 + 56U);
    t16 = *((char **)t4);
    memset(t6, 0, 8);
    t26 = (t6 + 4);
    t39 = (t16 + 4);
    t7 = *((unsigned int *)t16);
    t8 = (t7 >> 7);
    t9 = (t8 & 1);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t39);
    t11 = (t10 >> 7);
    t12 = (t11 & 1);
    *((unsigned int *)t26) = t12;
    t41 = (t0 + 3880);
    xsi_vlogvar_assign_value(t41, t6, 0, 0, 1);
    goto LAB33;

LAB37:    t25 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB38;

LAB41:    t39 = (t17 + 4);
    *((unsigned int *)t17) = 1;
    *((unsigned int *)t39) = 1;
    goto LAB42;

LAB43:    *((unsigned int *)t40) = 1;
    goto LAB46;

LAB45:    t47 = (t40 + 4);
    *((unsigned int *)t40) = 1;
    *((unsigned int *)t47) = 1;
    goto LAB46;

LAB47:    t52 = (t0 + 3400);
    t53 = (t52 + 56U);
    t54 = *((char **)t53);
    memset(t55, 0, 8);
    t56 = (t55 + 4);
    t57 = (t54 + 4);
    t58 = *((unsigned int *)t54);
    t59 = (t58 >> 7);
    t60 = (t59 & 1);
    *((unsigned int *)t55) = t60;
    t61 = *((unsigned int *)t57);
    t62 = (t61 >> 7);
    t63 = (t62 & 1);
    *((unsigned int *)t56) = t63;
    t64 = (t0 + 2680U);
    t65 = *((char **)t64);
    memset(t66, 0, 8);
    t64 = (t66 + 4);
    t67 = (t65 + 4);
    t68 = *((unsigned int *)t65);
    t69 = (t68 >> 7);
    t70 = (t69 & 1);
    *((unsigned int *)t66) = t70;
    t71 = *((unsigned int *)t67);
    t72 = (t71 >> 7);
    t73 = (t72 & 1);
    *((unsigned int *)t64) = t73;
    memset(t74, 0, 8);
    t75 = (t55 + 4);
    t76 = (t66 + 4);
    t77 = *((unsigned int *)t55);
    t78 = *((unsigned int *)t66);
    t79 = (t77 ^ t78);
    t80 = *((unsigned int *)t75);
    t81 = *((unsigned int *)t76);
    t82 = (t80 ^ t81);
    t83 = (t79 | t82);
    t84 = *((unsigned int *)t75);
    t85 = *((unsigned int *)t76);
    t86 = (t84 | t85);
    t87 = (~(t86));
    t88 = (t83 & t87);
    if (t88 != 0)
        goto LAB51;

LAB50:    if (t86 != 0)
        goto LAB52;

LAB53:    memset(t90, 0, 8);
    t91 = (t74 + 4);
    t92 = *((unsigned int *)t91);
    t93 = (~(t92));
    t94 = *((unsigned int *)t74);
    t95 = (t94 & t93);
    t96 = (t95 & 1U);
    if (t96 != 0)
        goto LAB54;

LAB55:    if (*((unsigned int *)t91) != 0)
        goto LAB56;

LAB57:    t99 = *((unsigned int *)t40);
    t100 = *((unsigned int *)t90);
    t101 = (t99 & t100);
    *((unsigned int *)t98) = t101;
    t102 = (t40 + 4);
    t103 = (t90 + 4);
    t104 = (t98 + 4);
    t105 = *((unsigned int *)t102);
    t106 = *((unsigned int *)t103);
    t107 = (t105 | t106);
    *((unsigned int *)t104) = t107;
    t108 = *((unsigned int *)t104);
    t109 = (t108 != 0);
    if (t109 == 1)
        goto LAB58;

LAB59:
LAB60:    goto LAB49;

LAB51:    *((unsigned int *)t74) = 1;
    goto LAB53;

LAB52:    t89 = (t74 + 4);
    *((unsigned int *)t74) = 1;
    *((unsigned int *)t89) = 1;
    goto LAB53;

LAB54:    *((unsigned int *)t90) = 1;
    goto LAB57;

LAB56:    t97 = (t90 + 4);
    *((unsigned int *)t90) = 1;
    *((unsigned int *)t97) = 1;
    goto LAB57;

LAB58:    t110 = *((unsigned int *)t98);
    t111 = *((unsigned int *)t104);
    *((unsigned int *)t98) = (t110 | t111);
    t112 = (t40 + 4);
    t113 = (t90 + 4);
    t114 = *((unsigned int *)t40);
    t115 = (~(t114));
    t116 = *((unsigned int *)t112);
    t117 = (~(t116));
    t118 = *((unsigned int *)t90);
    t119 = (~(t118));
    t120 = *((unsigned int *)t113);
    t121 = (~(t120));
    t13 = (t115 & t117);
    t122 = (t119 & t121);
    t123 = (~(t13));
    t124 = (~(t122));
    t125 = *((unsigned int *)t104);
    *((unsigned int *)t104) = (t125 & t123);
    t126 = *((unsigned int *)t104);
    *((unsigned int *)t104) = (t126 & t124);
    t127 = *((unsigned int *)t98);
    *((unsigned int *)t98) = (t127 & t123);
    t128 = *((unsigned int *)t98);
    *((unsigned int *)t98) = (t128 & t124);
    goto LAB60;

LAB62:    *((unsigned int *)t6) = 1;
    goto LAB65;

LAB67:    t28 = *((unsigned int *)t6);
    t29 = *((unsigned int *)t39);
    *((unsigned int *)t6) = (t28 | t29);
    t30 = *((unsigned int *)t26);
    t31 = *((unsigned int *)t39);
    *((unsigned int *)t26) = (t30 | t31);
    goto LAB66;

LAB70:    t25 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB71;

LAB73:    *((unsigned int *)t17) = 1;
    goto LAB75;

LAB74:    t39 = (t17 + 4);
    *((unsigned int *)t17) = 1;
    *((unsigned int *)t39) = 1;
    goto LAB75;

LAB76:    *((unsigned int *)t40) = 1;
    goto LAB79;

LAB78:    t47 = (t40 + 4);
    *((unsigned int *)t40) = 1;
    *((unsigned int *)t47) = 1;
    goto LAB79;

LAB80:    t52 = (t0 + 3400);
    t53 = (t52 + 56U);
    t54 = *((char **)t53);
    memset(t55, 0, 8);
    t56 = (t55 + 4);
    t57 = (t54 + 4);
    t58 = *((unsigned int *)t54);
    t59 = (t58 >> 7);
    t60 = (t59 & 1);
    *((unsigned int *)t55) = t60;
    t61 = *((unsigned int *)t57);
    t62 = (t61 >> 7);
    t63 = (t62 & 1);
    *((unsigned int *)t56) = t63;
    t64 = (t0 + 2680U);
    t65 = *((char **)t64);
    memset(t66, 0, 8);
    t64 = (t66 + 4);
    t67 = (t65 + 4);
    t68 = *((unsigned int *)t65);
    t69 = (t68 >> 7);
    t70 = (t69 & 1);
    *((unsigned int *)t66) = t70;
    t71 = *((unsigned int *)t67);
    t72 = (t71 >> 7);
    t73 = (t72 & 1);
    *((unsigned int *)t64) = t73;
    memset(t74, 0, 8);
    t75 = (t55 + 4);
    t76 = (t66 + 4);
    t77 = *((unsigned int *)t55);
    t78 = *((unsigned int *)t66);
    t79 = (t77 ^ t78);
    t80 = *((unsigned int *)t75);
    t81 = *((unsigned int *)t76);
    t82 = (t80 ^ t81);
    t83 = (t79 | t82);
    t84 = *((unsigned int *)t75);
    t85 = *((unsigned int *)t76);
    t86 = (t84 | t85);
    t87 = (~(t86));
    t88 = (t83 & t87);
    if (t88 != 0)
        goto LAB84;

LAB83:    if (t86 != 0)
        goto LAB85;

LAB86:    memset(t90, 0, 8);
    t91 = (t74 + 4);
    t92 = *((unsigned int *)t91);
    t93 = (~(t92));
    t94 = *((unsigned int *)t74);
    t95 = (t94 & t93);
    t96 = (t95 & 1U);
    if (t96 != 0)
        goto LAB87;

LAB88:    if (*((unsigned int *)t91) != 0)
        goto LAB89;

LAB90:    t99 = *((unsigned int *)t40);
    t100 = *((unsigned int *)t90);
    t101 = (t99 & t100);
    *((unsigned int *)t98) = t101;
    t102 = (t40 + 4);
    t103 = (t90 + 4);
    t104 = (t98 + 4);
    t105 = *((unsigned int *)t102);
    t106 = *((unsigned int *)t103);
    t107 = (t105 | t106);
    *((unsigned int *)t104) = t107;
    t108 = *((unsigned int *)t104);
    t109 = (t108 != 0);
    if (t109 == 1)
        goto LAB91;

LAB92:
LAB93:    goto LAB82;

LAB84:    *((unsigned int *)t74) = 1;
    goto LAB86;

LAB85:    t89 = (t74 + 4);
    *((unsigned int *)t74) = 1;
    *((unsigned int *)t89) = 1;
    goto LAB86;

LAB87:    *((unsigned int *)t90) = 1;
    goto LAB90;

LAB89:    t97 = (t90 + 4);
    *((unsigned int *)t90) = 1;
    *((unsigned int *)t97) = 1;
    goto LAB90;

LAB91:    t110 = *((unsigned int *)t98);
    t111 = *((unsigned int *)t104);
    *((unsigned int *)t98) = (t110 | t111);
    t112 = (t40 + 4);
    t113 = (t90 + 4);
    t114 = *((unsigned int *)t40);
    t115 = (~(t114));
    t116 = *((unsigned int *)t112);
    t117 = (~(t116));
    t118 = *((unsigned int *)t90);
    t119 = (~(t118));
    t120 = *((unsigned int *)t113);
    t121 = (~(t120));
    t13 = (t115 & t117);
    t122 = (t119 & t121);
    t123 = (~(t13));
    t124 = (~(t122));
    t125 = *((unsigned int *)t104);
    *((unsigned int *)t104) = (t125 & t123);
    t126 = *((unsigned int *)t104);
    *((unsigned int *)t104) = (t126 & t124);
    t127 = *((unsigned int *)t98);
    *((unsigned int *)t98) = (t127 & t123);
    t128 = *((unsigned int *)t98);
    *((unsigned int *)t98) = (t128 & t124);
    goto LAB93;

LAB95:    t21 = *((unsigned int *)t6);
    t22 = *((unsigned int *)t25);
    *((unsigned int *)t6) = (t21 | t22);
    t26 = (t15 + 4);
    t39 = (t16 + 4);
    t23 = *((unsigned int *)t15);
    t24 = (~(t23));
    t27 = *((unsigned int *)t26);
    t28 = (~(t27));
    t29 = *((unsigned int *)t16);
    t30 = (~(t29));
    t31 = *((unsigned int *)t39);
    t32 = (~(t31));
    t130 = (t24 & t28);
    t131 = (t30 & t32);
    t33 = (~(t130));
    t34 = (~(t131));
    t35 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t35 & t33);
    t36 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t36 & t34);
    t37 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t37 & t33);
    t38 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t38 & t34);
    goto LAB97;

LAB100:    t25 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB101;

LAB103:    t21 = *((unsigned int *)t6);
    t22 = *((unsigned int *)t18);
    *((unsigned int *)t6) = (t21 | t22);
    t25 = (t5 + 4);
    t26 = (t15 + 4);
    t23 = *((unsigned int *)t25);
    t24 = (~(t23));
    t27 = *((unsigned int *)t5);
    t122 = (t27 & t24);
    t28 = *((unsigned int *)t26);
    t29 = (~(t28));
    t30 = *((unsigned int *)t15);
    t130 = (t30 & t29);
    t31 = (~(t122));
    t32 = (~(t130));
    t33 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t33 & t31);
    t34 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t34 & t32);
    goto LAB105;

LAB108:    t25 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB109;

LAB111:    t21 = *((unsigned int *)t6);
    t22 = *((unsigned int *)t18);
    *((unsigned int *)t6) = (t21 | t22);
    goto LAB113;

LAB116:    t25 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB117;

LAB121:    t25 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB122;

LAB125:    t9 = *((unsigned int *)t6);
    t10 = *((unsigned int *)t15);
    *((unsigned int *)t6) = (t9 | t10);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t15);
    *((unsigned int *)t4) = (t11 | t12);
    goto LAB124;

LAB128:    t25 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB129;

LAB132:    xsi_set_current_line(125, ng0);
    t16 = (t0 + 2680U);
    t18 = *((char **)t16);
    memset(t6, 0, 8);
    t16 = (t6 + 4);
    t25 = (t18 + 4);
    t7 = *((unsigned int *)t18);
    t8 = (t7 >> 7);
    t9 = (t8 & 1);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t25);
    t11 = (t10 >> 7);
    t12 = (t11 & 1);
    *((unsigned int *)t16) = t12;
    t26 = (t0 + 3720);
    xsi_vlogvar_assign_value(t26, t6, 0, 0, 1);
    goto LAB148;

LAB134:    xsi_set_current_line(126, ng0);
    t4 = (t0 + 2680U);
    t15 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t6 + 4);
    t16 = (t15 + 4);
    t7 = *((unsigned int *)t15);
    t8 = (t7 >> 6);
    t9 = (t8 & 1);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t16);
    t11 = (t10 >> 6);
    t12 = (t11 & 1);
    *((unsigned int *)t4) = t12;
    t18 = (t0 + 3720);
    xsi_vlogvar_assign_value(t18, t6, 0, 0, 1);
    goto LAB148;

LAB136:    xsi_set_current_line(127, ng0);
    t4 = (t0 + 2680U);
    t15 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t6 + 4);
    t16 = (t15 + 4);
    t7 = *((unsigned int *)t15);
    t8 = (t7 >> 5);
    t9 = (t8 & 1);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t16);
    t11 = (t10 >> 5);
    t12 = (t11 & 1);
    *((unsigned int *)t4) = t12;
    t18 = (t0 + 3720);
    xsi_vlogvar_assign_value(t18, t6, 0, 0, 1);
    goto LAB148;

LAB138:    xsi_set_current_line(128, ng0);
    t4 = (t0 + 2680U);
    t15 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t6 + 4);
    t16 = (t15 + 4);
    t7 = *((unsigned int *)t15);
    t8 = (t7 >> 4);
    t9 = (t8 & 1);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t16);
    t11 = (t10 >> 4);
    t12 = (t11 & 1);
    *((unsigned int *)t4) = t12;
    t18 = (t0 + 3720);
    xsi_vlogvar_assign_value(t18, t6, 0, 0, 1);
    goto LAB148;

LAB140:    xsi_set_current_line(129, ng0);
    t4 = (t0 + 2680U);
    t15 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t6 + 4);
    t16 = (t15 + 4);
    t7 = *((unsigned int *)t15);
    t8 = (t7 >> 3);
    t9 = (t8 & 1);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t16);
    t11 = (t10 >> 3);
    t12 = (t11 & 1);
    *((unsigned int *)t4) = t12;
    t18 = (t0 + 3720);
    xsi_vlogvar_assign_value(t18, t6, 0, 0, 1);
    goto LAB148;

LAB142:    xsi_set_current_line(130, ng0);
    t4 = (t0 + 2680U);
    t15 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t6 + 4);
    t16 = (t15 + 4);
    t7 = *((unsigned int *)t15);
    t8 = (t7 >> 2);
    t9 = (t8 & 1);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t16);
    t11 = (t10 >> 2);
    t12 = (t11 & 1);
    *((unsigned int *)t4) = t12;
    t18 = (t0 + 3720);
    xsi_vlogvar_assign_value(t18, t6, 0, 0, 1);
    goto LAB148;

LAB144:    xsi_set_current_line(131, ng0);
    t4 = (t0 + 2680U);
    t15 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t6 + 4);
    t16 = (t15 + 4);
    t7 = *((unsigned int *)t15);
    t8 = (t7 >> 1);
    t9 = (t8 & 1);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t16);
    t11 = (t10 >> 1);
    t12 = (t11 & 1);
    *((unsigned int *)t4) = t12;
    t18 = (t0 + 3720);
    xsi_vlogvar_assign_value(t18, t6, 0, 0, 1);
    goto LAB148;

LAB151:    t26 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t26) = 1;
    goto LAB152;

LAB155:    xsi_set_current_line(143, ng0);
    t18 = (t0 + 2680U);
    t25 = *((char **)t18);
    memset(t6, 0, 8);
    t18 = (t6 + 4);
    t26 = (t25 + 4);
    t7 = *((unsigned int *)t25);
    t8 = (t7 >> 0);
    t9 = (t8 & 1);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t26);
    t11 = (t10 >> 0);
    t12 = (t11 & 1);
    *((unsigned int *)t18) = t12;
    t39 = (t0 + 3720);
    xsi_vlogvar_assign_value(t39, t6, 0, 0, 1);
    goto LAB171;

LAB157:    xsi_set_current_line(144, ng0);
    t4 = (t0 + 2680U);
    t16 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t6 + 4);
    t18 = (t16 + 4);
    t7 = *((unsigned int *)t16);
    t8 = (t7 >> 1);
    t9 = (t8 & 1);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t18);
    t11 = (t10 >> 1);
    t12 = (t11 & 1);
    *((unsigned int *)t4) = t12;
    t25 = (t0 + 3720);
    xsi_vlogvar_assign_value(t25, t6, 0, 0, 1);
    goto LAB171;

LAB159:    xsi_set_current_line(145, ng0);
    t4 = (t0 + 2680U);
    t16 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t6 + 4);
    t18 = (t16 + 4);
    t7 = *((unsigned int *)t16);
    t8 = (t7 >> 2);
    t9 = (t8 & 1);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t18);
    t11 = (t10 >> 2);
    t12 = (t11 & 1);
    *((unsigned int *)t4) = t12;
    t25 = (t0 + 3720);
    xsi_vlogvar_assign_value(t25, t6, 0, 0, 1);
    goto LAB171;

LAB161:    xsi_set_current_line(146, ng0);
    t4 = (t0 + 2680U);
    t16 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t6 + 4);
    t18 = (t16 + 4);
    t7 = *((unsigned int *)t16);
    t8 = (t7 >> 3);
    t9 = (t8 & 1);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t18);
    t11 = (t10 >> 3);
    t12 = (t11 & 1);
    *((unsigned int *)t4) = t12;
    t25 = (t0 + 3720);
    xsi_vlogvar_assign_value(t25, t6, 0, 0, 1);
    goto LAB171;

LAB163:    xsi_set_current_line(147, ng0);
    t4 = (t0 + 2680U);
    t16 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t6 + 4);
    t18 = (t16 + 4);
    t7 = *((unsigned int *)t16);
    t8 = (t7 >> 4);
    t9 = (t8 & 1);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t18);
    t11 = (t10 >> 4);
    t12 = (t11 & 1);
    *((unsigned int *)t4) = t12;
    t25 = (t0 + 3720);
    xsi_vlogvar_assign_value(t25, t6, 0, 0, 1);
    goto LAB171;

LAB165:    xsi_set_current_line(148, ng0);
    t4 = (t0 + 2680U);
    t16 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t6 + 4);
    t18 = (t16 + 4);
    t7 = *((unsigned int *)t16);
    t8 = (t7 >> 5);
    t9 = (t8 & 1);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t18);
    t11 = (t10 >> 5);
    t12 = (t11 & 1);
    *((unsigned int *)t4) = t12;
    t25 = (t0 + 3720);
    xsi_vlogvar_assign_value(t25, t6, 0, 0, 1);
    goto LAB171;

LAB167:    xsi_set_current_line(149, ng0);
    t4 = (t0 + 2680U);
    t16 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t6 + 4);
    t18 = (t16 + 4);
    t7 = *((unsigned int *)t16);
    t8 = (t7 >> 6);
    t9 = (t8 & 1);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t18);
    t11 = (t10 >> 6);
    t12 = (t11 & 1);
    *((unsigned int *)t4) = t12;
    t25 = (t0 + 3720);
    xsi_vlogvar_assign_value(t25, t6, 0, 0, 1);
    goto LAB171;

LAB174:    t39 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t39) = 1;
    goto LAB175;

LAB178:    xsi_set_current_line(158, ng0);
    t26 = (t0 + 2680U);
    t39 = *((char **)t26);
    t26 = (t0 + 3400);
    xsi_vlogvar_assign_value(t26, t39, 0, 0, 8);
    goto LAB196;

LAB180:    xsi_set_current_line(159, ng0);
    t4 = (t0 + 2680U);
    t16 = *((char **)t4);
    memset(t14, 0, 8);
    t4 = (t14 + 4);
    t25 = (t16 + 4);
    t7 = *((unsigned int *)t16);
    t8 = (t7 >> 7);
    t9 = (t8 & 1);
    *((unsigned int *)t14) = t9;
    t10 = *((unsigned int *)t25);
    t11 = (t10 >> 7);
    t12 = (t11 & 1);
    *((unsigned int *)t4) = t12;
    t26 = (t0 + 2680U);
    t39 = *((char **)t26);
    memset(t17, 0, 8);
    t26 = (t17 + 4);
    t41 = (t39 + 4);
    t19 = *((unsigned int *)t39);
    t20 = (t19 >> 0);
    *((unsigned int *)t17) = t20;
    t21 = *((unsigned int *)t41);
    t22 = (t21 >> 0);
    *((unsigned int *)t26) = t22;
    t23 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t23 & 127U);
    t24 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t24 & 127U);
    xsi_vlogtype_concat(t6, 8, 8, 2U, t17, 7, t14, 1);
    t47 = (t0 + 3400);
    xsi_vlogvar_assign_value(t47, t6, 0, 0, 8);
    goto LAB196;

LAB182:    xsi_set_current_line(160, ng0);
    t4 = (t0 + 2680U);
    t16 = *((char **)t4);
    memset(t14, 0, 8);
    t4 = (t14 + 4);
    t25 = (t16 + 4);
    t7 = *((unsigned int *)t16);
    t8 = (t7 >> 6);
    *((unsigned int *)t14) = t8;
    t9 = *((unsigned int *)t25);
    t10 = (t9 >> 6);
    *((unsigned int *)t4) = t10;
    t11 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t11 & 3U);
    t12 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t12 & 3U);
    t26 = (t0 + 2680U);
    t39 = *((char **)t26);
    memset(t17, 0, 8);
    t26 = (t17 + 4);
    t41 = (t39 + 4);
    t19 = *((unsigned int *)t39);
    t20 = (t19 >> 0);
    *((unsigned int *)t17) = t20;
    t21 = *((unsigned int *)t41);
    t22 = (t21 >> 0);
    *((unsigned int *)t26) = t22;
    t23 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t23 & 63U);
    t24 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t24 & 63U);
    xsi_vlogtype_concat(t6, 8, 8, 2U, t17, 6, t14, 2);
    t47 = (t0 + 3400);
    xsi_vlogvar_assign_value(t47, t6, 0, 0, 8);
    goto LAB196;

LAB184:    xsi_set_current_line(161, ng0);
    t4 = (t0 + 2680U);
    t16 = *((char **)t4);
    memset(t14, 0, 8);
    t4 = (t14 + 4);
    t25 = (t16 + 4);
    t7 = *((unsigned int *)t16);
    t8 = (t7 >> 5);
    *((unsigned int *)t14) = t8;
    t9 = *((unsigned int *)t25);
    t10 = (t9 >> 5);
    *((unsigned int *)t4) = t10;
    t11 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t11 & 7U);
    t12 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t12 & 7U);
    t26 = (t0 + 2680U);
    t39 = *((char **)t26);
    memset(t17, 0, 8);
    t26 = (t17 + 4);
    t41 = (t39 + 4);
    t19 = *((unsigned int *)t39);
    t20 = (t19 >> 0);
    *((unsigned int *)t17) = t20;
    t21 = *((unsigned int *)t41);
    t22 = (t21 >> 0);
    *((unsigned int *)t26) = t22;
    t23 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t23 & 31U);
    t24 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t24 & 31U);
    xsi_vlogtype_concat(t6, 8, 8, 2U, t17, 5, t14, 3);
    t47 = (t0 + 3400);
    xsi_vlogvar_assign_value(t47, t6, 0, 0, 8);
    goto LAB196;

LAB186:    xsi_set_current_line(162, ng0);
    t4 = (t0 + 2680U);
    t16 = *((char **)t4);
    memset(t14, 0, 8);
    t4 = (t14 + 4);
    t25 = (t16 + 4);
    t7 = *((unsigned int *)t16);
    t8 = (t7 >> 4);
    *((unsigned int *)t14) = t8;
    t9 = *((unsigned int *)t25);
    t10 = (t9 >> 4);
    *((unsigned int *)t4) = t10;
    t11 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t11 & 15U);
    t12 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t12 & 15U);
    t26 = (t0 + 2680U);
    t39 = *((char **)t26);
    memset(t17, 0, 8);
    t26 = (t17 + 4);
    t41 = (t39 + 4);
    t19 = *((unsigned int *)t39);
    t20 = (t19 >> 0);
    *((unsigned int *)t17) = t20;
    t21 = *((unsigned int *)t41);
    t22 = (t21 >> 0);
    *((unsigned int *)t26) = t22;
    t23 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t23 & 15U);
    t24 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t24 & 15U);
    xsi_vlogtype_concat(t6, 8, 8, 2U, t17, 4, t14, 4);
    t47 = (t0 + 3400);
    xsi_vlogvar_assign_value(t47, t6, 0, 0, 8);
    goto LAB196;

LAB188:    xsi_set_current_line(163, ng0);
    t4 = (t0 + 2680U);
    t16 = *((char **)t4);
    memset(t14, 0, 8);
    t4 = (t14 + 4);
    t25 = (t16 + 4);
    t7 = *((unsigned int *)t16);
    t8 = (t7 >> 3);
    *((unsigned int *)t14) = t8;
    t9 = *((unsigned int *)t25);
    t10 = (t9 >> 3);
    *((unsigned int *)t4) = t10;
    t11 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t11 & 31U);
    t12 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t12 & 31U);
    t26 = (t0 + 2680U);
    t39 = *((char **)t26);
    memset(t17, 0, 8);
    t26 = (t17 + 4);
    t41 = (t39 + 4);
    t19 = *((unsigned int *)t39);
    t20 = (t19 >> 0);
    *((unsigned int *)t17) = t20;
    t21 = *((unsigned int *)t41);
    t22 = (t21 >> 0);
    *((unsigned int *)t26) = t22;
    t23 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t23 & 7U);
    t24 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t24 & 7U);
    xsi_vlogtype_concat(t6, 8, 8, 2U, t17, 3, t14, 5);
    t47 = (t0 + 3400);
    xsi_vlogvar_assign_value(t47, t6, 0, 0, 8);
    goto LAB196;

LAB190:    xsi_set_current_line(164, ng0);
    t4 = (t0 + 2680U);
    t16 = *((char **)t4);
    memset(t14, 0, 8);
    t4 = (t14 + 4);
    t25 = (t16 + 4);
    t7 = *((unsigned int *)t16);
    t8 = (t7 >> 2);
    *((unsigned int *)t14) = t8;
    t9 = *((unsigned int *)t25);
    t10 = (t9 >> 2);
    *((unsigned int *)t4) = t10;
    t11 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t11 & 63U);
    t12 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t12 & 63U);
    t26 = (t0 + 2680U);
    t39 = *((char **)t26);
    memset(t17, 0, 8);
    t26 = (t17 + 4);
    t41 = (t39 + 4);
    t19 = *((unsigned int *)t39);
    t20 = (t19 >> 0);
    *((unsigned int *)t17) = t20;
    t21 = *((unsigned int *)t41);
    t22 = (t21 >> 0);
    *((unsigned int *)t26) = t22;
    t23 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t23 & 3U);
    t24 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t24 & 3U);
    xsi_vlogtype_concat(t6, 8, 8, 2U, t17, 2, t14, 6);
    t47 = (t0 + 3400);
    xsi_vlogvar_assign_value(t47, t6, 0, 0, 8);
    goto LAB196;

LAB192:    xsi_set_current_line(165, ng0);
    t4 = (t0 + 2680U);
    t16 = *((char **)t4);
    memset(t14, 0, 8);
    t4 = (t14 + 4);
    t25 = (t16 + 4);
    t7 = *((unsigned int *)t16);
    t8 = (t7 >> 1);
    *((unsigned int *)t14) = t8;
    t9 = *((unsigned int *)t25);
    t10 = (t9 >> 1);
    *((unsigned int *)t4) = t10;
    t11 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t11 & 127U);
    t12 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t12 & 127U);
    t26 = (t0 + 2680U);
    t39 = *((char **)t26);
    memset(t17, 0, 8);
    t26 = (t17 + 4);
    t41 = (t39 + 4);
    t19 = *((unsigned int *)t39);
    t20 = (t19 >> 0);
    t21 = (t20 & 1);
    *((unsigned int *)t17) = t21;
    t22 = *((unsigned int *)t41);
    t23 = (t22 >> 0);
    t24 = (t23 & 1);
    *((unsigned int *)t26) = t24;
    xsi_vlogtype_concat(t6, 8, 8, 2U, t17, 1, t14, 7);
    t47 = (t0 + 3400);
    xsi_vlogvar_assign_value(t47, t6, 0, 0, 8);
    goto LAB196;

LAB199:    t41 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t41) = 1;
    goto LAB200;

LAB203:    xsi_set_current_line(175, ng0);
    t39 = (t0 + 2680U);
    t41 = *((char **)t39);
    t39 = (t0 + 3400);
    xsi_vlogvar_assign_value(t39, t41, 0, 0, 8);
    goto LAB221;

LAB205:    xsi_set_current_line(176, ng0);
    t4 = (t0 + 2680U);
    t16 = *((char **)t4);
    memset(t14, 0, 8);
    t4 = (t14 + 4);
    t26 = (t16 + 4);
    t7 = *((unsigned int *)t16);
    t8 = (t7 >> 1);
    *((unsigned int *)t14) = t8;
    t9 = *((unsigned int *)t26);
    t10 = (t9 >> 1);
    *((unsigned int *)t4) = t10;
    t11 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t11 & 127U);
    t12 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t12 & 127U);
    t39 = (t0 + 2680U);
    t41 = *((char **)t39);
    memset(t17, 0, 8);
    t39 = (t17 + 4);
    t47 = (t41 + 4);
    t19 = *((unsigned int *)t41);
    t20 = (t19 >> 0);
    t21 = (t20 & 1);
    *((unsigned int *)t17) = t21;
    t22 = *((unsigned int *)t47);
    t23 = (t22 >> 0);
    t24 = (t23 & 1);
    *((unsigned int *)t39) = t24;
    xsi_vlogtype_concat(t6, 8, 8, 2U, t17, 1, t14, 7);
    t48 = (t0 + 3400);
    xsi_vlogvar_assign_value(t48, t6, 0, 0, 8);
    goto LAB221;

LAB207:    xsi_set_current_line(177, ng0);
    t4 = (t0 + 2680U);
    t16 = *((char **)t4);
    memset(t14, 0, 8);
    t4 = (t14 + 4);
    t26 = (t16 + 4);
    t7 = *((unsigned int *)t16);
    t8 = (t7 >> 2);
    *((unsigned int *)t14) = t8;
    t9 = *((unsigned int *)t26);
    t10 = (t9 >> 2);
    *((unsigned int *)t4) = t10;
    t11 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t11 & 63U);
    t12 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t12 & 63U);
    t39 = (t0 + 2680U);
    t41 = *((char **)t39);
    memset(t17, 0, 8);
    t39 = (t17 + 4);
    t47 = (t41 + 4);
    t19 = *((unsigned int *)t41);
    t20 = (t19 >> 0);
    *((unsigned int *)t17) = t20;
    t21 = *((unsigned int *)t47);
    t22 = (t21 >> 0);
    *((unsigned int *)t39) = t22;
    t23 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t23 & 3U);
    t24 = *((unsigned int *)t39);
    *((unsigned int *)t39) = (t24 & 3U);
    xsi_vlogtype_concat(t6, 8, 8, 2U, t17, 2, t14, 6);
    t48 = (t0 + 3400);
    xsi_vlogvar_assign_value(t48, t6, 0, 0, 8);
    goto LAB221;

LAB209:    xsi_set_current_line(178, ng0);
    t4 = (t0 + 2680U);
    t16 = *((char **)t4);
    memset(t14, 0, 8);
    t4 = (t14 + 4);
    t26 = (t16 + 4);
    t7 = *((unsigned int *)t16);
    t8 = (t7 >> 3);
    *((unsigned int *)t14) = t8;
    t9 = *((unsigned int *)t26);
    t10 = (t9 >> 3);
    *((unsigned int *)t4) = t10;
    t11 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t11 & 31U);
    t12 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t12 & 31U);
    t39 = (t0 + 2680U);
    t41 = *((char **)t39);
    memset(t17, 0, 8);
    t39 = (t17 + 4);
    t47 = (t41 + 4);
    t19 = *((unsigned int *)t41);
    t20 = (t19 >> 0);
    *((unsigned int *)t17) = t20;
    t21 = *((unsigned int *)t47);
    t22 = (t21 >> 0);
    *((unsigned int *)t39) = t22;
    t23 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t23 & 7U);
    t24 = *((unsigned int *)t39);
    *((unsigned int *)t39) = (t24 & 7U);
    xsi_vlogtype_concat(t6, 8, 8, 2U, t17, 3, t14, 5);
    t48 = (t0 + 3400);
    xsi_vlogvar_assign_value(t48, t6, 0, 0, 8);
    goto LAB221;

LAB211:    xsi_set_current_line(179, ng0);
    t4 = (t0 + 2680U);
    t16 = *((char **)t4);
    memset(t14, 0, 8);
    t4 = (t14 + 4);
    t26 = (t16 + 4);
    t7 = *((unsigned int *)t16);
    t8 = (t7 >> 4);
    *((unsigned int *)t14) = t8;
    t9 = *((unsigned int *)t26);
    t10 = (t9 >> 4);
    *((unsigned int *)t4) = t10;
    t11 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t11 & 15U);
    t12 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t12 & 15U);
    t39 = (t0 + 2680U);
    t41 = *((char **)t39);
    memset(t17, 0, 8);
    t39 = (t17 + 4);
    t47 = (t41 + 4);
    t19 = *((unsigned int *)t41);
    t20 = (t19 >> 0);
    *((unsigned int *)t17) = t20;
    t21 = *((unsigned int *)t47);
    t22 = (t21 >> 0);
    *((unsigned int *)t39) = t22;
    t23 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t23 & 15U);
    t24 = *((unsigned int *)t39);
    *((unsigned int *)t39) = (t24 & 15U);
    xsi_vlogtype_concat(t6, 8, 8, 2U, t17, 4, t14, 4);
    t48 = (t0 + 3400);
    xsi_vlogvar_assign_value(t48, t6, 0, 0, 8);
    goto LAB221;

LAB213:    xsi_set_current_line(180, ng0);
    t4 = (t0 + 2680U);
    t16 = *((char **)t4);
    memset(t14, 0, 8);
    t4 = (t14 + 4);
    t26 = (t16 + 4);
    t7 = *((unsigned int *)t16);
    t8 = (t7 >> 5);
    *((unsigned int *)t14) = t8;
    t9 = *((unsigned int *)t26);
    t10 = (t9 >> 5);
    *((unsigned int *)t4) = t10;
    t11 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t11 & 7U);
    t12 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t12 & 7U);
    t39 = (t0 + 2680U);
    t41 = *((char **)t39);
    memset(t17, 0, 8);
    t39 = (t17 + 4);
    t47 = (t41 + 4);
    t19 = *((unsigned int *)t41);
    t20 = (t19 >> 0);
    *((unsigned int *)t17) = t20;
    t21 = *((unsigned int *)t47);
    t22 = (t21 >> 0);
    *((unsigned int *)t39) = t22;
    t23 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t23 & 31U);
    t24 = *((unsigned int *)t39);
    *((unsigned int *)t39) = (t24 & 31U);
    xsi_vlogtype_concat(t6, 8, 8, 2U, t17, 5, t14, 3);
    t48 = (t0 + 3400);
    xsi_vlogvar_assign_value(t48, t6, 0, 0, 8);
    goto LAB221;

LAB215:    xsi_set_current_line(181, ng0);
    t4 = (t0 + 2680U);
    t16 = *((char **)t4);
    memset(t14, 0, 8);
    t4 = (t14 + 4);
    t26 = (t16 + 4);
    t7 = *((unsigned int *)t16);
    t8 = (t7 >> 6);
    *((unsigned int *)t14) = t8;
    t9 = *((unsigned int *)t26);
    t10 = (t9 >> 6);
    *((unsigned int *)t4) = t10;
    t11 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t11 & 3U);
    t12 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t12 & 3U);
    t39 = (t0 + 2680U);
    t41 = *((char **)t39);
    memset(t17, 0, 8);
    t39 = (t17 + 4);
    t47 = (t41 + 4);
    t19 = *((unsigned int *)t41);
    t20 = (t19 >> 0);
    *((unsigned int *)t17) = t20;
    t21 = *((unsigned int *)t47);
    t22 = (t21 >> 0);
    *((unsigned int *)t39) = t22;
    t23 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t23 & 63U);
    t24 = *((unsigned int *)t39);
    *((unsigned int *)t39) = (t24 & 63U);
    xsi_vlogtype_concat(t6, 8, 8, 2U, t17, 6, t14, 2);
    t48 = (t0 + 3400);
    xsi_vlogvar_assign_value(t48, t6, 0, 0, 8);
    goto LAB221;

LAB217:    xsi_set_current_line(182, ng0);
    t4 = (t0 + 2680U);
    t16 = *((char **)t4);
    memset(t14, 0, 8);
    t4 = (t14 + 4);
    t26 = (t16 + 4);
    t7 = *((unsigned int *)t16);
    t8 = (t7 >> 7);
    t9 = (t8 & 1);
    *((unsigned int *)t14) = t9;
    t10 = *((unsigned int *)t26);
    t11 = (t10 >> 7);
    t12 = (t11 & 1);
    *((unsigned int *)t4) = t12;
    t39 = (t0 + 2680U);
    t41 = *((char **)t39);
    memset(t17, 0, 8);
    t39 = (t17 + 4);
    t47 = (t41 + 4);
    t19 = *((unsigned int *)t41);
    t20 = (t19 >> 0);
    *((unsigned int *)t17) = t20;
    t21 = *((unsigned int *)t47);
    t22 = (t21 >> 0);
    *((unsigned int *)t39) = t22;
    t23 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t23 & 127U);
    t24 = *((unsigned int *)t39);
    *((unsigned int *)t39) = (t24 & 127U);
    xsi_vlogtype_concat(t6, 8, 8, 2U, t17, 7, t14, 1);
    t48 = (t0 + 3400);
    xsi_vlogvar_assign_value(t48, t6, 0, 0, 8);
    goto LAB221;

LAB224:    t47 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t47) = 1;
    goto LAB225;

}


extern void work_m_00000000000667220840_4192366798_init()
{
	static char *pe[] = {(void *)Always_57_0};
	xsi_register_didat("work_m_00000000000667220840_4192366798", "isim/tb_s8_cpu_programs_isim_beh.exe.sim/work/m_00000000000667220840_4192366798.didat");
	xsi_register_executes(pe);
}
