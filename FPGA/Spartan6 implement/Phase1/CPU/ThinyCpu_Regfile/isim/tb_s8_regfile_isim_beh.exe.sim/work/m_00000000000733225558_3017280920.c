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
static const char *ng0 = "C:/Users/vboxuser/Documents/ThinyCpu/ThinyCpu_Regfile/ThinyRegfile_tb.v";
static int ng1[] = {1, 0};
static const char *ng2 = "FAIL %0s: ra=%0d rb=%0d -> got a=%02h b=%02h, exp a=%02h b=%02h";
static int ng3[] = {0, 0};
static int ng4[] = {3, 0};
static unsigned int ng5[] = {0U, 0U};
static unsigned int ng6[] = {7U, 0U};
static int ng7[] = {1700885107, 0, 1948279660, 0, 1919251301, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng8[] = {8, 0};
static unsigned int ng9[] = {16U, 0U};
static int ng10[] = {7, 0};
static int ng11[] = {1650549611, 0, 1919246692, 0, 1769235759, 0, 30578, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng12[] = {2U, 0U};
static unsigned int ng13[] = {170U, 0U};
static unsigned int ng14[] = {18U, 0U};
static const char *ng15 = "FAIL read-during-write: got %02h/%02h, exp old 12/12";
static int ng16[] = {1634497893, 0, 1702305910, 0, 1734680686, 0, 1949132132, 0, 7368563, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng17[] = {85U, 0U};
static int ng18[] = {2, 0};
static int ng19[] = {1869374579, 0, 1026564200, 0, 30565, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng20[] = {5U, 0U};
static int ng21[] = {1702061428, 0, 1852055666, 0, 1936024431, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static const char *ng22 = "tb_s8_regfile: PASSED (%0d checks, 0 errors)";
static const char *ng23 = "tb_s8_regfile: FAILED (%0d checks, %0d errors)";



static int sp_check2(char *t1, char *t2)
{
    char t9[8];
    char t11[8];
    char t28[8];
    char t31[8];
    char t39[8];
    char t77[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t10;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t29;
    char *t30;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    char *t38;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    char *t43;
    char *t44;
    char *t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    char *t53;
    char *t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    char *t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    char *t73;
    char *t74;
    char *t75;
    char *t76;
    char *t78;

LAB0:    t0 = 1;
    t3 = (t2 + 48U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 848);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);
    xsi_set_current_line(52, ng0);

LAB5:    xsi_set_current_line(53, ng0);
    t5 = (t1 + 3320);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = ((char*)((ng1)));
    memset(t9, 0, 8);
    xsi_vlog_signed_add(t9, 32, t7, 32, t8, 32);
    t10 = (t1 + 3320);
    xsi_vlogvar_assign_value(t10, t9, 0, 0, 32);
    xsi_set_current_line(54, ng0);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 1000LL);
    *((char **)t3) = &&LAB6;
    t0 = 1;

LAB1:    return t0;
LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 48U);
    *((char **)t4) = &&LAB2;
    t0 = 0;
    goto LAB1;

LAB6:    xsi_set_current_line(55, ng0);
    t4 = (t1 + 1480U);
    t5 = *((char **)t4);
    t4 = (t1 + 3640);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    memset(t9, 0, 8);
    if (*((unsigned int *)t5) != *((unsigned int *)t7))
        goto LAB8;

LAB7:    t8 = (t5 + 4);
    t10 = (t7 + 4);
    if (*((unsigned int *)t8) != *((unsigned int *)t10))
        goto LAB8;

LAB9:    memset(t11, 0, 8);
    t12 = (t9 + 4);
    t13 = *((unsigned int *)t12);
    t14 = (~(t13));
    t15 = *((unsigned int *)t9);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t12) != 0)
        goto LAB12;

LAB13:    t19 = (t11 + 4);
    t20 = *((unsigned int *)t11);
    t21 = (!(t20));
    t22 = *((unsigned int *)t19);
    t23 = (t21 || t22);
    if (t23 > 0)
        goto LAB14;

LAB15:    memcpy(t39, t11, 8);

LAB16:    t67 = (t39 + 4);
    t68 = *((unsigned int *)t67);
    t69 = (~(t68));
    t70 = *((unsigned int *)t39);
    t71 = (t70 & t69);
    t72 = (t71 != 0);
    if (t72 > 0)
        goto LAB27;

LAB28:
LAB29:    goto LAB4;

LAB8:    *((unsigned int *)t9) = 1;
    goto LAB9;

LAB10:    *((unsigned int *)t11) = 1;
    goto LAB13;

LAB12:    t18 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t18) = 1;
    goto LAB13;

LAB14:    t24 = (t1 + 1640U);
    t25 = *((char **)t24);
    t24 = (t1 + 3800);
    t26 = (t24 + 56U);
    t27 = *((char **)t26);
    memset(t28, 0, 8);
    if (*((unsigned int *)t25) != *((unsigned int *)t27))
        goto LAB18;

LAB17:    t29 = (t25 + 4);
    t30 = (t27 + 4);
    if (*((unsigned int *)t29) != *((unsigned int *)t30))
        goto LAB18;

LAB19:    memset(t31, 0, 8);
    t32 = (t28 + 4);
    t33 = *((unsigned int *)t32);
    t34 = (~(t33));
    t35 = *((unsigned int *)t28);
    t36 = (t35 & t34);
    t37 = (t36 & 1U);
    if (t37 != 0)
        goto LAB20;

LAB21:    if (*((unsigned int *)t32) != 0)
        goto LAB22;

LAB23:    t40 = *((unsigned int *)t11);
    t41 = *((unsigned int *)t31);
    t42 = (t40 | t41);
    *((unsigned int *)t39) = t42;
    t43 = (t11 + 4);
    t44 = (t31 + 4);
    t45 = (t39 + 4);
    t46 = *((unsigned int *)t43);
    t47 = *((unsigned int *)t44);
    t48 = (t46 | t47);
    *((unsigned int *)t45) = t48;
    t49 = *((unsigned int *)t45);
    t50 = (t49 != 0);
    if (t50 == 1)
        goto LAB24;

LAB25:
LAB26:    goto LAB16;

LAB18:    *((unsigned int *)t28) = 1;
    goto LAB19;

LAB20:    *((unsigned int *)t31) = 1;
    goto LAB23;

LAB22:    t38 = (t31 + 4);
    *((unsigned int *)t31) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB23;

LAB24:    t51 = *((unsigned int *)t39);
    t52 = *((unsigned int *)t45);
    *((unsigned int *)t39) = (t51 | t52);
    t53 = (t11 + 4);
    t54 = (t31 + 4);
    t55 = *((unsigned int *)t53);
    t56 = (~(t55));
    t57 = *((unsigned int *)t11);
    t58 = (t57 & t56);
    t59 = *((unsigned int *)t54);
    t60 = (~(t59));
    t61 = *((unsigned int *)t31);
    t62 = (t61 & t60);
    t63 = (~(t58));
    t64 = (~(t62));
    t65 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t65 & t63);
    t66 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t66 & t64);
    goto LAB26;

LAB27:    xsi_set_current_line(55, ng0);

LAB30:    xsi_set_current_line(56, ng0);
    t73 = (t1 + 3480);
    t74 = (t73 + 56U);
    t75 = *((char **)t74);
    t76 = ((char*)((ng1)));
    memset(t77, 0, 8);
    xsi_vlog_signed_add(t77, 32, t75, 32, t76, 32);
    t78 = (t1 + 3480);
    xsi_vlogvar_assign_value(t78, t77, 0, 0, 32);
    xsi_set_current_line(57, ng0);
    t4 = (t1 + 3960);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 2360);
    t8 = (t7 + 56U);
    t10 = *((char **)t8);
    t12 = (t1 + 2520);
    t18 = (t12 + 56U);
    t19 = *((char **)t18);
    t24 = (t1 + 1480U);
    t25 = *((char **)t24);
    t24 = (t1 + 1640U);
    t26 = *((char **)t24);
    t24 = (t1 + 3640);
    t27 = (t24 + 56U);
    t29 = *((char **)t27);
    t30 = (t1 + 3800);
    t32 = (t30 + 56U);
    t38 = *((char **)t32);
    t43 = (t1 + 848);
    xsi_vlogfile_write(1, 0, 0, ng2, 8, t43, (char)118, t6, 256, (char)118, t10, 3, (char)118, t19, 3, (char)118, t25, 8, (char)118, t26, 8, (char)118, t29, 8, (char)118, t38, 8);
    goto LAB29;

}

static void Initial_46_0(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(46, ng0);
    t1 = ((char*)((ng3)));
    t2 = (t0 + 2040);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);

LAB1:    return;
}

static void Always_47_1(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;

LAB0:    t1 = (t0 + 5128U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(47, ng0);
    t2 = (t0 + 4936);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(47, ng0);
    t4 = (t0 + 2040);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB8;

LAB6:    if (*((unsigned int *)t7) == 0)
        goto LAB5;

LAB7:    t13 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t13) = 1;

LAB8:    t14 = (t3 + 4);
    t15 = (t6 + 4);
    t16 = *((unsigned int *)t6);
    t17 = (~(t16));
    *((unsigned int *)t3) = t17;
    *((unsigned int *)t14) = 0;
    if (*((unsigned int *)t15) != 0)
        goto LAB10;

LAB9:    t22 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t22 & 1U);
    t23 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t23 & 1U);
    t24 = (t0 + 2040);
    xsi_vlogvar_assign_value(t24, t3, 0, 0, 1);
    goto LAB2;

LAB5:    *((unsigned int *)t3) = 1;
    goto LAB8;

LAB10:    t18 = *((unsigned int *)t3);
    t19 = *((unsigned int *)t15);
    *((unsigned int *)t3) = (t18 | t19);
    t20 = *((unsigned int *)t14);
    t21 = *((unsigned int *)t15);
    *((unsigned int *)t14) = (t20 | t21);
    goto LAB9;

}

static void Initial_63_2(char *t0)
{
    char t27[8];
    char t30[8];
    char t31[8];
    char t43[8];
    char t49[8];
    char t76[8];
    char *t1;
    char *t2;
    char *t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    int t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    unsigned int t28;
    unsigned int t29;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;

LAB0:    t1 = (t0 + 5376U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(63, ng0);

LAB4:    xsi_set_current_line(64, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3320);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(65, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3480);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(66, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2200);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(66, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3000);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(67, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2360);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(67, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2520);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(67, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2680);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(67, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2840);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(70, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t2 + 4);
    t4 = *((unsigned int *)t3);
    t5 = (~(t4));
    t6 = *((unsigned int *)t2);
    t7 = (t6 & t5);
    t8 = (t0 + 7748);
    *((int *)t8) = t7;

LAB5:    t9 = (t0 + 7748);
    if (*((int *)t9) > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(71, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 2360);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(71, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 2520);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(72, ng0);
    t2 = ((char*)((ng5)));
    t3 = ((char*)((ng5)));
    t8 = ((char*)((ng7)));
    t9 = (t0 + 5184);
    t10 = (t0 + 848);
    t11 = xsi_create_subprogram_invocation(t9, 0, t0, t10, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t10, t11);
    t12 = (t0 + 3640);
    xsi_vlogvar_assign_value(t12, t2, 0, 0, 8);
    t13 = (t0 + 3800);
    xsi_vlogvar_assign_value(t13, t3, 0, 0, 8);
    t14 = (t0 + 3960);
    xsi_vlogvar_assign_value(t14, t8, 0, 0, 256);

LAB11:    t15 = (t0 + 5280);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t7 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB13:    if (t7 != 0)
        goto LAB14;

LAB9:    t16 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t16);

LAB10:    t23 = (t0 + 5280);
    t24 = *((char **)t23);
    t23 = (t0 + 848);
    t25 = (t0 + 5184);
    t26 = 0;
    xsi_delete_subprogram_invocation(t23, t24, t0, t25, t26);
    xsi_set_current_line(73, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2200);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(74, ng0);
    t2 = (t0 + 5712);
    *((int *)t2) = 1;
    t3 = (t0 + 5408);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB15;

LAB1:    return;
LAB6:    xsi_set_current_line(70, ng0);
    t10 = (t0 + 5696);
    *((int *)t10) = 1;
    t11 = (t0 + 5408);
    *((char **)t11) = t10;
    *((char **)t1) = &&LAB8;
    goto LAB1;

LAB8:    t2 = (t0 + 7748);
    t7 = *((int *)t2);
    *((int *)t2) = (t7 - 1);
    goto LAB5;

LAB12:;
LAB14:    t15 = (t0 + 5376U);
    *((char **)t15) = &&LAB11;
    goto LAB1;

LAB15:    xsi_set_current_line(77, ng0);
    xsi_set_current_line(77, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3160);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB16:    t2 = (t0 + 3160);
    t3 = (t2 + 56U);
    t8 = *((char **)t3);
    t9 = ((char*)((ng8)));
    memset(t27, 0, 8);
    xsi_vlog_signed_less(t27, 32, t8, 32, t9, 32);
    t10 = (t27 + 4);
    t4 = *((unsigned int *)t10);
    t5 = (~(t4));
    t6 = *((unsigned int *)t27);
    t28 = (t6 & t5);
    t29 = (t28 != 0);
    if (t29 > 0)
        goto LAB17;

LAB18:    xsi_set_current_line(81, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3000);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(82, ng0);
    t2 = (t0 + 5744);
    *((int *)t2) = 1;
    t3 = (t0 + 5408);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB21;
    goto LAB1;

LAB17:    xsi_set_current_line(77, ng0);

LAB19:    xsi_set_current_line(78, ng0);
    t11 = (t0 + 3160);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t0 + 2680);
    xsi_vlogvar_assign_value(t14, t13, 0, 0, 3);
    xsi_set_current_line(78, ng0);
    t2 = ((char*)((ng9)));
    t3 = (t0 + 3160);
    t8 = (t3 + 56U);
    t9 = *((char **)t8);
    memset(t27, 0, 8);
    xsi_vlog_unsigned_add(t27, 32, t2, 32, t9, 32);
    t10 = (t0 + 2840);
    xsi_vlogvar_assign_value(t10, t27, 0, 0, 8);
    xsi_set_current_line(78, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3000);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(79, ng0);
    t2 = (t0 + 5728);
    *((int *)t2) = 1;
    t3 = (t0 + 5408);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB20;
    goto LAB1;

LAB20:    xsi_set_current_line(77, ng0);
    t2 = (t0 + 3160);
    t3 = (t2 + 56U);
    t8 = *((char **)t3);
    t9 = ((char*)((ng1)));
    memset(t27, 0, 8);
    xsi_vlog_signed_add(t27, 32, t8, 32, t9, 32);
    t10 = (t0 + 3160);
    xsi_vlogvar_assign_value(t10, t27, 0, 0, 32);
    goto LAB16;

LAB21:    xsi_set_current_line(83, ng0);
    xsi_set_current_line(83, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3160);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB22:    t2 = (t0 + 3160);
    t3 = (t2 + 56U);
    t8 = *((char **)t3);
    t9 = ((char*)((ng8)));
    memset(t27, 0, 8);
    xsi_vlog_signed_less(t27, 32, t8, 32, t9, 32);
    t10 = (t27 + 4);
    t4 = *((unsigned int *)t10);
    t5 = (~(t4));
    t6 = *((unsigned int *)t27);
    t28 = (t6 & t5);
    t29 = (t28 != 0);
    if (t29 > 0)
        goto LAB23;

LAB24:    xsi_set_current_line(89, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 2360);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(89, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 2520);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(90, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 2680);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(90, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 2840);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(90, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3000);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(91, ng0);
    t2 = (t0 + 5184);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB32;
    goto LAB1;

LAB23:    xsi_set_current_line(83, ng0);

LAB25:    xsi_set_current_line(84, ng0);
    t11 = (t0 + 3160);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t0 + 2360);
    xsi_vlogvar_assign_value(t14, t13, 0, 0, 3);
    xsi_set_current_line(84, ng0);
    t2 = ((char*)((ng10)));
    t3 = (t0 + 3160);
    t8 = (t3 + 56U);
    t9 = *((char **)t8);
    memset(t27, 0, 8);
    xsi_vlog_signed_minus(t27, 32, t2, 32, t9, 32);
    t10 = (t0 + 2520);
    xsi_vlogvar_assign_value(t10, t27, 0, 0, 3);
    xsi_set_current_line(85, ng0);
    t2 = ((char*)((ng9)));
    t3 = (t0 + 3160);
    t8 = (t3 + 56U);
    t9 = *((char **)t8);
    memset(t27, 0, 8);
    xsi_vlog_unsigned_add(t27, 32, t2, 32, t9, 32);
    t10 = ((char*)((ng9)));
    t11 = ((char*)((ng10)));
    t12 = (t0 + 3160);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    memset(t30, 0, 8);
    xsi_vlog_unsigned_minus(t30, 32, t11, 32, t14, 32);
    memset(t31, 0, 8);
    xsi_vlog_unsigned_add(t31, 32, t10, 32, t30, 32);
    t15 = ((char*)((ng11)));
    t16 = (t0 + 5184);
    t17 = (t0 + 848);
    t18 = xsi_create_subprogram_invocation(t16, 0, t0, t17, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t17, t18);
    t19 = (t0 + 3640);
    xsi_vlogvar_assign_value(t19, t27, 0, 0, 8);
    t20 = (t0 + 3800);
    xsi_vlogvar_assign_value(t20, t31, 0, 0, 8);
    t21 = (t0 + 3960);
    xsi_vlogvar_assign_value(t21, t15, 0, 0, 256);

LAB28:    t22 = (t0 + 5280);
    t23 = *((char **)t22);
    t24 = (t23 + 80U);
    t25 = *((char **)t24);
    t26 = (t25 + 272U);
    t32 = *((char **)t26);
    t33 = (t32 + 0U);
    t34 = *((char **)t33);
    t7 = ((int  (*)(char *, char *))t34)(t0, t23);

LAB30:    if (t7 != 0)
        goto LAB31;

LAB26:    t23 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t23);

LAB27:    t35 = (t0 + 5280);
    t36 = *((char **)t35);
    t35 = (t0 + 848);
    t37 = (t0 + 5184);
    t38 = 0;
    xsi_delete_subprogram_invocation(t35, t36, t0, t37, t38);
    xsi_set_current_line(83, ng0);
    t2 = (t0 + 3160);
    t3 = (t2 + 56U);
    t8 = *((char **)t3);
    t9 = ((char*)((ng1)));
    memset(t27, 0, 8);
    xsi_vlog_signed_add(t27, 32, t8, 32, t9, 32);
    t10 = (t0 + 3160);
    xsi_vlogvar_assign_value(t10, t27, 0, 0, 32);
    goto LAB22;

LAB29:;
LAB31:    t22 = (t0 + 5376U);
    *((char **)t22) = &&LAB28;
    goto LAB1;

LAB32:    xsi_set_current_line(92, ng0);
    t2 = (t0 + 3320);
    t3 = (t2 + 56U);
    t8 = *((char **)t3);
    t9 = ((char*)((ng1)));
    memset(t27, 0, 8);
    xsi_vlog_signed_add(t27, 32, t8, 32, t9, 32);
    t10 = (t0 + 3320);
    xsi_vlogvar_assign_value(t10, t27, 0, 0, 32);
    xsi_set_current_line(93, ng0);
    t2 = (t0 + 1480U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng14)));
    memset(t27, 0, 8);
    if (*((unsigned int *)t3) != *((unsigned int *)t2))
        goto LAB34;

LAB33:    t8 = (t3 + 4);
    t9 = (t2 + 4);
    if (*((unsigned int *)t8) != *((unsigned int *)t9))
        goto LAB34;

LAB35:    memset(t30, 0, 8);
    t10 = (t27 + 4);
    t4 = *((unsigned int *)t10);
    t5 = (~(t4));
    t6 = *((unsigned int *)t27);
    t28 = (t6 & t5);
    t29 = (t28 & 1U);
    if (t29 != 0)
        goto LAB36;

LAB37:    if (*((unsigned int *)t10) != 0)
        goto LAB38;

LAB39:    t12 = (t30 + 4);
    t39 = *((unsigned int *)t30);
    t40 = (!(t39));
    t41 = *((unsigned int *)t12);
    t42 = (t40 || t41);
    if (t42 > 0)
        goto LAB40;

LAB41:    memcpy(t49, t30, 8);

LAB42:    t24 = (t49 + 4);
    t71 = *((unsigned int *)t24);
    t72 = (~(t71));
    t73 = *((unsigned int *)t49);
    t74 = (t73 & t72);
    t75 = (t74 != 0);
    if (t75 > 0)
        goto LAB53;

LAB54:
LAB55:    xsi_set_current_line(98, ng0);
    t2 = (t0 + 5760);
    *((int *)t2) = 1;
    t3 = (t0 + 5408);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB57;
    goto LAB1;

LAB34:    *((unsigned int *)t27) = 1;
    goto LAB35;

LAB36:    *((unsigned int *)t30) = 1;
    goto LAB39;

LAB38:    t11 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB39;

LAB40:    t13 = (t0 + 1640U);
    t14 = *((char **)t13);
    t13 = ((char*)((ng14)));
    memset(t31, 0, 8);
    if (*((unsigned int *)t14) != *((unsigned int *)t13))
        goto LAB44;

LAB43:    t15 = (t14 + 4);
    t16 = (t13 + 4);
    if (*((unsigned int *)t15) != *((unsigned int *)t16))
        goto LAB44;

LAB45:    memset(t43, 0, 8);
    t17 = (t31 + 4);
    t44 = *((unsigned int *)t17);
    t45 = (~(t44));
    t46 = *((unsigned int *)t31);
    t47 = (t46 & t45);
    t48 = (t47 & 1U);
    if (t48 != 0)
        goto LAB46;

LAB47:    if (*((unsigned int *)t17) != 0)
        goto LAB48;

LAB49:    t50 = *((unsigned int *)t30);
    t51 = *((unsigned int *)t43);
    t52 = (t50 | t51);
    *((unsigned int *)t49) = t52;
    t19 = (t30 + 4);
    t20 = (t43 + 4);
    t21 = (t49 + 4);
    t53 = *((unsigned int *)t19);
    t54 = *((unsigned int *)t20);
    t55 = (t53 | t54);
    *((unsigned int *)t21) = t55;
    t56 = *((unsigned int *)t21);
    t57 = (t56 != 0);
    if (t57 == 1)
        goto LAB50;

LAB51:
LAB52:    goto LAB42;

LAB44:    *((unsigned int *)t31) = 1;
    goto LAB45;

LAB46:    *((unsigned int *)t43) = 1;
    goto LAB49;

LAB48:    t18 = (t43 + 4);
    *((unsigned int *)t43) = 1;
    *((unsigned int *)t18) = 1;
    goto LAB49;

LAB50:    t58 = *((unsigned int *)t49);
    t59 = *((unsigned int *)t21);
    *((unsigned int *)t49) = (t58 | t59);
    t22 = (t30 + 4);
    t23 = (t43 + 4);
    t60 = *((unsigned int *)t22);
    t61 = (~(t60));
    t62 = *((unsigned int *)t30);
    t7 = (t62 & t61);
    t63 = *((unsigned int *)t23);
    t64 = (~(t63));
    t65 = *((unsigned int *)t43);
    t66 = (t65 & t64);
    t67 = (~(t7));
    t68 = (~(t66));
    t69 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t69 & t67);
    t70 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t70 & t68);
    goto LAB52;

LAB53:    xsi_set_current_line(93, ng0);

LAB56:    xsi_set_current_line(94, ng0);
    t25 = (t0 + 3480);
    t26 = (t25 + 56U);
    t32 = *((char **)t26);
    t33 = ((char*)((ng1)));
    memset(t76, 0, 8);
    xsi_vlog_signed_add(t76, 32, t32, 32, t33, 32);
    t34 = (t0 + 3480);
    xsi_vlogvar_assign_value(t34, t76, 0, 0, 32);
    xsi_set_current_line(95, ng0);
    t2 = (t0 + 1480U);
    t3 = *((char **)t2);
    t2 = (t0 + 1640U);
    t8 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng15, 3, t0, (char)118, t3, 8, (char)118, t8, 8);
    goto LAB55;

LAB57:    xsi_set_current_line(99, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3000);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(100, ng0);
    t2 = ((char*)((ng13)));
    t3 = ((char*)((ng13)));
    t8 = ((char*)((ng16)));
    t9 = (t0 + 5184);
    t10 = (t0 + 848);
    t11 = xsi_create_subprogram_invocation(t9, 0, t0, t10, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t10, t11);
    t12 = (t0 + 3640);
    xsi_vlogvar_assign_value(t12, t2, 0, 0, 8);
    t13 = (t0 + 3800);
    xsi_vlogvar_assign_value(t13, t3, 0, 0, 8);
    t14 = (t0 + 3960);
    xsi_vlogvar_assign_value(t14, t8, 0, 0, 256);

LAB60:    t15 = (t0 + 5280);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t7 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB62:    if (t7 != 0)
        goto LAB63;

LAB58:    t16 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t16);

LAB59:    t23 = (t0 + 5280);
    t24 = *((char **)t23);
    t23 = (t0 + 848);
    t25 = (t0 + 5184);
    t26 = 0;
    xsi_delete_subprogram_invocation(t23, t24, t0, t25, t26);
    xsi_set_current_line(103, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 2680);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(103, ng0);
    t2 = ((char*)((ng17)));
    t3 = (t0 + 2840);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(103, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3000);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(104, ng0);
    t2 = ((char*)((ng18)));
    t3 = (t2 + 4);
    t4 = *((unsigned int *)t3);
    t5 = (~(t4));
    t6 = *((unsigned int *)t2);
    t7 = (t6 & t5);
    t8 = (t0 + 7752);
    *((int *)t8) = t7;

LAB64:    t9 = (t0 + 7752);
    if (*((int *)t9) > 0)
        goto LAB65;

LAB66:    xsi_set_current_line(105, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 2360);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(105, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 2520);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(106, ng0);
    t2 = ((char*)((ng13)));
    t3 = ((char*)((ng13)));
    t8 = ((char*)((ng19)));
    t9 = (t0 + 5184);
    t10 = (t0 + 848);
    t11 = xsi_create_subprogram_invocation(t9, 0, t0, t10, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t10, t11);
    t12 = (t0 + 3640);
    xsi_vlogvar_assign_value(t12, t2, 0, 0, 8);
    t13 = (t0 + 3800);
    xsi_vlogvar_assign_value(t13, t3, 0, 0, 8);
    t14 = (t0 + 3960);
    xsi_vlogvar_assign_value(t14, t8, 0, 0, 256);

LAB70:    t15 = (t0 + 5280);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t7 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB72:    if (t7 != 0)
        goto LAB73;

LAB68:    t16 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t16);

LAB69:    t23 = (t0 + 5280);
    t24 = *((char **)t23);
    t23 = (t0 + 848);
    t25 = (t0 + 5184);
    t26 = 0;
    xsi_delete_subprogram_invocation(t23, t24, t0, t25, t26);
    xsi_set_current_line(109, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2200);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(110, ng0);
    t2 = ((char*)((ng18)));
    t3 = (t2 + 4);
    t4 = *((unsigned int *)t3);
    t5 = (~(t4));
    t6 = *((unsigned int *)t2);
    t7 = (t6 & t5);
    t8 = (t0 + 7756);
    *((int *)t8) = t7;

LAB74:    t9 = (t0 + 7756);
    if (*((int *)t9) > 0)
        goto LAB75;

LAB76:    xsi_set_current_line(111, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2200);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(112, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 2360);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(112, ng0);
    t2 = ((char*)((ng20)));
    t3 = (t0 + 2520);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(113, ng0);
    t2 = ((char*)((ng5)));
    t3 = ((char*)((ng5)));
    t8 = ((char*)((ng21)));
    t9 = (t0 + 5184);
    t10 = (t0 + 848);
    t11 = xsi_create_subprogram_invocation(t9, 0, t0, t10, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t10, t11);
    t12 = (t0 + 3640);
    xsi_vlogvar_assign_value(t12, t2, 0, 0, 8);
    t13 = (t0 + 3800);
    xsi_vlogvar_assign_value(t13, t3, 0, 0, 8);
    t14 = (t0 + 3960);
    xsi_vlogvar_assign_value(t14, t8, 0, 0, 256);

LAB80:    t15 = (t0 + 5280);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t7 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB82:    if (t7 != 0)
        goto LAB83;

LAB78:    t16 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t16);

LAB79:    t23 = (t0 + 5280);
    t24 = *((char **)t23);
    t23 = (t0 + 848);
    t25 = (t0 + 5184);
    t26 = 0;
    xsi_delete_subprogram_invocation(t23, t24, t0, t25, t26);
    xsi_set_current_line(116, ng0);
    t2 = (t0 + 3480);
    t3 = (t2 + 56U);
    t8 = *((char **)t3);
    t9 = ((char*)((ng3)));
    memset(t27, 0, 8);
    xsi_vlog_signed_equal(t27, 32, t8, 32, t9, 32);
    t10 = (t27 + 4);
    t4 = *((unsigned int *)t10);
    t5 = (~(t4));
    t6 = *((unsigned int *)t27);
    t28 = (t6 & t5);
    t29 = (t28 != 0);
    if (t29 > 0)
        goto LAB84;

LAB85:    xsi_set_current_line(119, ng0);
    t2 = (t0 + 3320);
    t3 = (t2 + 56U);
    t8 = *((char **)t3);
    t9 = (t0 + 3480);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    xsi_vlogfile_write(1, 0, 0, ng23, 3, t0, (char)119, t8, 32, (char)119, t11, 32);

LAB86:    xsi_set_current_line(120, ng0);
    xsi_vlog_finish(1);
    goto LAB1;

LAB61:;
LAB63:    t15 = (t0 + 5376U);
    *((char **)t15) = &&LAB60;
    goto LAB1;

LAB65:    xsi_set_current_line(104, ng0);
    t10 = (t0 + 5776);
    *((int *)t10) = 1;
    t11 = (t0 + 5408);
    *((char **)t11) = t10;
    *((char **)t1) = &&LAB67;
    goto LAB1;

LAB67:    t2 = (t0 + 7752);
    t7 = *((int *)t2);
    *((int *)t2) = (t7 - 1);
    goto LAB64;

LAB71:;
LAB73:    t15 = (t0 + 5376U);
    *((char **)t15) = &&LAB70;
    goto LAB1;

LAB75:    xsi_set_current_line(110, ng0);
    t10 = (t0 + 5792);
    *((int *)t10) = 1;
    t11 = (t0 + 5408);
    *((char **)t11) = t10;
    *((char **)t1) = &&LAB77;
    goto LAB1;

LAB77:    t2 = (t0 + 7756);
    t7 = *((int *)t2);
    *((int *)t2) = (t7 - 1);
    goto LAB74;

LAB81:;
LAB83:    t15 = (t0 + 5376U);
    *((char **)t15) = &&LAB80;
    goto LAB1;

LAB84:    xsi_set_current_line(117, ng0);
    t11 = (t0 + 3320);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    xsi_vlogfile_write(1, 0, 0, ng22, 2, t0, (char)119, t13, 32);
    goto LAB86;

}


extern void work_m_00000000000733225558_3017280920_init()
{
	static char *pe[] = {(void *)Initial_46_0,(void *)Always_47_1,(void *)Initial_63_2};
	static char *se[] = {(void *)sp_check2};
	xsi_register_didat("work_m_00000000000733225558_3017280920", "isim/tb_s8_regfile_isim_beh.exe.sim/work/m_00000000000733225558_3017280920.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
