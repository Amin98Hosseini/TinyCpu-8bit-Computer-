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
static const char *ng0 = "C:/Users/vboxuser/Desktop/Files/tb_s8_cpu_programs.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {15U, 0U};
static unsigned int ng3[] = {1U, 0U};
static unsigned int ng4[] = {2U, 0U};
static unsigned int ng5[] = {4U, 0U};
static unsigned int ng6[] = {3U, 0U};



static void Always_442_0(char *t0)
{
    char t14[8];
    char t23[8];
    char t35[8];
    char t43[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    int t13;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;
    char *t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    char *t42;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    char *t47;
    char *t48;
    char *t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    char *t57;
    char *t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    char *t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    char *t80;
    char *t81;

LAB0:    t1 = (t0 + 4608U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(442, ng0);
    t2 = (t0 + 5176);
    *((int *)t2) = 1;
    t3 = (t0 + 4640);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(442, ng0);

LAB5:    xsi_set_current_line(443, ng0);
    t4 = (t0 + 1208U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(450, ng0);

LAB10:    xsi_set_current_line(451, ng0);
    t2 = (t0 + 2328U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB11;

LAB12:
LAB13:    xsi_set_current_line(455, ng0);
    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB15;

LAB16:
LAB17:    xsi_set_current_line(471, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    memset(t14, 0, 8);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB30;

LAB31:    if (*((unsigned int *)t2) != 0)
        goto LAB32;

LAB33:    t11 = (t14 + 4);
    t16 = *((unsigned int *)t14);
    t17 = *((unsigned int *)t11);
    t18 = (t16 || t17);
    if (t18 > 0)
        goto LAB34;

LAB35:    memcpy(t43, t14, 8);

LAB36:    t74 = (t43 + 4);
    t75 = *((unsigned int *)t74);
    t76 = (~(t75));
    t77 = *((unsigned int *)t43);
    t78 = (t77 & t76);
    t79 = (t78 != 0);
    if (t79 > 0)
        goto LAB48;

LAB49:
LAB50:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(443, ng0);

LAB9:    xsi_set_current_line(444, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 2888);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 4, 0LL);
    xsi_set_current_line(445, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3368);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 4, 0LL);
    xsi_set_current_line(446, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3528);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(447, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3688);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 8, 0LL);
    xsi_set_current_line(448, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 8, 0LL);
    xsi_set_current_line(449, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3208);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB8;

LAB11:    xsi_set_current_line(451, ng0);

LAB14:    xsi_set_current_line(452, ng0);
    t4 = (t0 + 2168U);
    t5 = *((char **)t4);
    t4 = (t0 + 3688);
    xsi_vlogvar_wait_assign_value(t4, t5, 0, 0, 8, 0LL);
    xsi_set_current_line(453, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3528);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB13;

LAB15:    xsi_set_current_line(455, ng0);

LAB18:    xsi_set_current_line(456, ng0);
    t4 = (t0 + 1688U);
    t5 = *((char **)t4);

LAB19:    t4 = ((char*)((ng1)));
    t13 = xsi_vlog_unsigned_case_compare(t5, 3, t4, 3);
    if (t13 == 1)
        goto LAB20;

LAB21:    t2 = ((char*)((ng4)));
    t13 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t13 == 1)
        goto LAB22;

LAB23:    t2 = ((char*)((ng5)));
    t13 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t13 == 1)
        goto LAB24;

LAB25:
LAB27:
LAB26:
LAB28:    goto LAB17;

LAB20:    xsi_set_current_line(457, ng0);
    t11 = (t0 + 1848U);
    t12 = *((char **)t11);
    memset(t14, 0, 8);
    t11 = (t14 + 4);
    t15 = (t12 + 4);
    t16 = *((unsigned int *)t12);
    t17 = (t16 >> 0);
    *((unsigned int *)t14) = t17;
    t18 = *((unsigned int *)t15);
    t19 = (t18 >> 0);
    *((unsigned int *)t11) = t19;
    t20 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t20 & 15U);
    t21 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t21 & 15U);
    t22 = (t0 + 2888);
    xsi_vlogvar_wait_assign_value(t22, t14, 0, 0, 4, 0LL);
    goto LAB28;

LAB22:    xsi_set_current_line(458, ng0);
    t3 = (t0 + 1848U);
    t4 = *((char **)t3);
    memset(t14, 0, 8);
    t3 = (t14 + 4);
    t11 = (t4 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (t6 >> 0);
    *((unsigned int *)t14) = t7;
    t8 = *((unsigned int *)t11);
    t9 = (t8 >> 0);
    *((unsigned int *)t3) = t9;
    t10 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t10 & 15U);
    t16 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t16 & 15U);
    t12 = (t0 + 3368);
    xsi_vlogvar_wait_assign_value(t12, t14, 0, 0, 4, 0LL);
    goto LAB28;

LAB24:    xsi_set_current_line(461, ng0);

LAB29:    xsi_set_current_line(462, ng0);
    t3 = (t0 + 1848U);
    t4 = *((char **)t3);
    t3 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t3, t4, 0, 0, 8, 0LL);
    xsi_set_current_line(463, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3208);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(464, ng0);
    t2 = (t0 + 1848U);
    t3 = *((char **)t2);
    t2 = (t0 + 3688);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 8, 0LL);
    xsi_set_current_line(465, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3528);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB28;

LAB30:    *((unsigned int *)t14) = 1;
    goto LAB33;

LAB32:    t4 = (t14 + 4);
    *((unsigned int *)t14) = 1;
    *((unsigned int *)t4) = 1;
    goto LAB33;

LAB34:    t12 = (t0 + 1688U);
    t15 = *((char **)t12);
    t12 = ((char*)((ng5)));
    memset(t23, 0, 8);
    t22 = (t15 + 4);
    t24 = (t12 + 4);
    t19 = *((unsigned int *)t15);
    t20 = *((unsigned int *)t12);
    t21 = (t19 ^ t20);
    t25 = *((unsigned int *)t22);
    t26 = *((unsigned int *)t24);
    t27 = (t25 ^ t26);
    t28 = (t21 | t27);
    t29 = *((unsigned int *)t22);
    t30 = *((unsigned int *)t24);
    t31 = (t29 | t30);
    t32 = (~(t31));
    t33 = (t28 & t32);
    if (t33 != 0)
        goto LAB40;

LAB37:    if (t31 != 0)
        goto LAB39;

LAB38:    *((unsigned int *)t23) = 1;

LAB40:    memset(t35, 0, 8);
    t36 = (t23 + 4);
    t37 = *((unsigned int *)t36);
    t38 = (~(t37));
    t39 = *((unsigned int *)t23);
    t40 = (t39 & t38);
    t41 = (t40 & 1U);
    if (t41 != 0)
        goto LAB41;

LAB42:    if (*((unsigned int *)t36) != 0)
        goto LAB43;

LAB44:    t44 = *((unsigned int *)t14);
    t45 = *((unsigned int *)t35);
    t46 = (t44 & t45);
    *((unsigned int *)t43) = t46;
    t47 = (t14 + 4);
    t48 = (t35 + 4);
    t49 = (t43 + 4);
    t50 = *((unsigned int *)t47);
    t51 = *((unsigned int *)t48);
    t52 = (t50 | t51);
    *((unsigned int *)t49) = t52;
    t53 = *((unsigned int *)t49);
    t54 = (t53 != 0);
    if (t54 == 1)
        goto LAB45;

LAB46:
LAB47:    goto LAB36;

LAB39:    t34 = (t23 + 4);
    *((unsigned int *)t23) = 1;
    *((unsigned int *)t34) = 1;
    goto LAB40;

LAB41:    *((unsigned int *)t35) = 1;
    goto LAB44;

LAB43:    t42 = (t35 + 4);
    *((unsigned int *)t35) = 1;
    *((unsigned int *)t42) = 1;
    goto LAB44;

LAB45:    t55 = *((unsigned int *)t43);
    t56 = *((unsigned int *)t49);
    *((unsigned int *)t43) = (t55 | t56);
    t57 = (t14 + 4);
    t58 = (t35 + 4);
    t59 = *((unsigned int *)t14);
    t60 = (~(t59));
    t61 = *((unsigned int *)t57);
    t62 = (~(t61));
    t63 = *((unsigned int *)t35);
    t64 = (~(t63));
    t65 = *((unsigned int *)t58);
    t66 = (~(t65));
    t13 = (t60 & t62);
    t67 = (t64 & t66);
    t68 = (~(t13));
    t69 = (~(t67));
    t70 = *((unsigned int *)t49);
    *((unsigned int *)t49) = (t70 & t68);
    t71 = *((unsigned int *)t49);
    *((unsigned int *)t49) = (t71 & t69);
    t72 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t72 & t68);
    t73 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t73 & t69);
    goto LAB47;

LAB48:    xsi_set_current_line(472, ng0);
    t80 = ((char*)((ng1)));
    t81 = (t0 + 3528);
    xsi_vlogvar_wait_assign_value(t81, t80, 0, 0, 1, 0LL);
    goto LAB50;

}

static void Always_476_1(char *t0)
{
    char t7[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;

LAB0:    t1 = (t0 + 4856U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(476, ng0);
    t2 = (t0 + 5192);
    *((int *)t2) = 1;
    t3 = (t0 + 4888);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(476, ng0);

LAB5:    xsi_set_current_line(477, ng0);
    t4 = (t0 + 1688U);
    t5 = *((char **)t4);

LAB6:    t4 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t4, 3);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng3)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng4)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng6)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng5)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB15;

LAB16:
LAB18:
LAB17:    xsi_set_current_line(484, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2728);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);

LAB19:    goto LAB2;

LAB7:    xsi_set_current_line(478, ng0);
    t8 = (t0 + 2888);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = ((char*)((ng1)));
    xsi_vlogtype_concat(t7, 8, 8, 2U, t11, 4, t10, 4);
    t12 = (t0 + 2728);
    xsi_vlogvar_assign_value(t12, t7, 0, 0, 8);
    goto LAB19;

LAB9:    xsi_set_current_line(479, ng0);
    t3 = (t0 + 2008U);
    t4 = *((char **)t3);
    t3 = ((char*)((ng1)));
    xsi_vlogtype_concat(t7, 8, 8, 2U, t3, 4, t4, 4);
    t8 = (t0 + 2728);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 8);
    goto LAB19;

LAB11:    xsi_set_current_line(480, ng0);
    t3 = (t0 + 3368);
    t4 = (t3 + 56U);
    t8 = *((char **)t4);
    t9 = ((char*)((ng1)));
    xsi_vlogtype_concat(t7, 8, 8, 2U, t9, 4, t8, 4);
    t10 = (t0 + 2728);
    xsi_vlogvar_assign_value(t10, t7, 0, 0, 8);
    goto LAB19;

LAB13:    xsi_set_current_line(482, ng0);
    t3 = (t0 + 3528);
    t4 = (t3 + 56U);
    t8 = *((char **)t4);
    t9 = ((char*)((ng3)));
    t10 = ((char*)((ng1)));
    xsi_vlogtype_concat(t7, 8, 8, 3U, t10, 6, t9, 1, t8, 1);
    t11 = (t0 + 2728);
    xsi_vlogvar_assign_value(t11, t7, 0, 0, 8);
    goto LAB19;

LAB15:    xsi_set_current_line(483, ng0);
    t3 = (t0 + 3688);
    t4 = (t3 + 56U);
    t8 = *((char **)t4);
    t9 = (t0 + 2728);
    xsi_vlogvar_assign_value(t9, t8, 0, 0, 8);
    goto LAB19;

}


extern void work_m_00000000001483178833_0040532021_init()
{
	static char *pe[] = {(void *)Always_442_0,(void *)Always_476_1};
	xsi_register_didat("work_m_00000000001483178833_0040532021", "isim/tb_s8_cpu_programs_isim_beh.exe.sim/work/m_00000000001483178833_0040532021.didat");
	xsi_register_executes(pe);
}
