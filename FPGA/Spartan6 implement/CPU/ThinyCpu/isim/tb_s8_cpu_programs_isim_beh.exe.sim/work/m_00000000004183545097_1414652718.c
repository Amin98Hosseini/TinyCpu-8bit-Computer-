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
static const char *ng0 = "C:/Users/vboxuser/Desktop/Files/s8_data_ram.v";
static unsigned int ng1[] = {239U, 0U};
static const char *ng2 = "ERROR @%0t: s8_data_ram: address %02h outside 0x00-0xEF";



static void Always_29_0(char *t0)
{
    char t13[8];
    char t14[8];
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
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    unsigned int t23;
    int t24;
    char *t25;
    unsigned int t26;
    int t27;
    int t28;
    unsigned int t29;
    unsigned int t30;
    int t31;
    int t32;

LAB0:    t1 = (t0 + 3168U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(29, ng0);
    t2 = (t0 + 3736);
    *((int *)t2) = 1;
    t3 = (t0 + 3200);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(29, ng0);

LAB5:    xsi_set_current_line(30, ng0);
    t4 = (t0 + 1528U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:
LAB8:    xsi_set_current_line(32, ng0);
    t2 = (t0 + 1368U);
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
LAB13:    goto LAB2;

LAB6:    xsi_set_current_line(31, ng0);
    t11 = (t0 + 1688U);
    t12 = *((char **)t11);
    t11 = (t0 + 2248);
    t15 = (t0 + 2248);
    t16 = (t15 + 72U);
    t17 = *((char **)t16);
    t18 = (t0 + 2248);
    t19 = (t18 + 64U);
    t20 = *((char **)t19);
    t21 = (t0 + 1208U);
    t22 = *((char **)t21);
    xsi_vlog_generic_convert_array_indices(t13, t14, t17, t20, 2, 1, t22, 8, 2);
    t21 = (t13 + 4);
    t23 = *((unsigned int *)t21);
    t24 = (!(t23));
    t25 = (t14 + 4);
    t26 = *((unsigned int *)t25);
    t27 = (!(t26));
    t28 = (t24 && t27);
    if (t28 == 1)
        goto LAB9;

LAB10:    goto LAB8;

LAB9:    t29 = *((unsigned int *)t13);
    t30 = *((unsigned int *)t14);
    t31 = (t29 - t30);
    t32 = (t31 + 1);
    xsi_vlogvar_wait_assign_value(t11, t12, 0, *((unsigned int *)t14), t32, 0LL);
    goto LAB10;

LAB11:    xsi_set_current_line(33, ng0);
    t4 = (t0 + 2248);
    t5 = (t4 + 56U);
    t11 = *((char **)t5);
    t12 = (t0 + 2248);
    t15 = (t12 + 72U);
    t16 = *((char **)t15);
    t17 = (t0 + 2248);
    t18 = (t17 + 64U);
    t19 = *((char **)t18);
    t20 = (t0 + 1208U);
    t21 = *((char **)t20);
    xsi_vlog_generic_get_array_select_value(t13, 8, t11, t16, t19, 2, 1, t21, 8, 2);
    t20 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t20, t13, 0, 0, 8, 0LL);
    goto LAB13;

}

static void Always_39_1(char *t0)
{
    char t6[8];
    char t20[8];
    char t27[8];
    char t55[8];
    char t69[8];
    char t73[8];
    char t81[8];
    char t119[16];
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
    char *t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    char *t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    char *t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    char *t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    char *t62;
    char *t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    char *t67;
    char *t68;
    char *t70;
    char *t71;
    char *t72;
    char *t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    char *t80;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    char *t85;
    char *t86;
    char *t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    char *t95;
    char *t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    int t105;
    int t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    char *t113;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    char *t120;
    char *t121;
    char *t122;

LAB0:    t1 = (t0 + 3416U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(39, ng0);
    t2 = (t0 + 3752);
    *((int *)t2) = 1;
    t3 = (t0 + 3448);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(39, ng0);

LAB5:    xsi_set_current_line(40, ng0);
    t4 = (t0 + 1368U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t5 + 4);
    t7 = *((unsigned int *)t4);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB6;

LAB7:    if (*((unsigned int *)t4) != 0)
        goto LAB8;

LAB9:    t13 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    t15 = (!(t14));
    t16 = *((unsigned int *)t13);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB10;

LAB11:    memcpy(t27, t6, 8);

LAB12:    memset(t55, 0, 8);
    t56 = (t27 + 4);
    t57 = *((unsigned int *)t56);
    t58 = (~(t57));
    t59 = *((unsigned int *)t27);
    t60 = (t59 & t58);
    t61 = (t60 & 1U);
    if (t61 != 0)
        goto LAB20;

LAB21:    if (*((unsigned int *)t56) != 0)
        goto LAB22;

LAB23:    t63 = (t55 + 4);
    t64 = *((unsigned int *)t55);
    t65 = *((unsigned int *)t63);
    t66 = (t64 || t65);
    if (t66 > 0)
        goto LAB24;

LAB25:    memcpy(t81, t55, 8);

LAB26:    t113 = (t81 + 4);
    t114 = *((unsigned int *)t113);
    t115 = (~(t114));
    t116 = *((unsigned int *)t81);
    t117 = (t116 & t115);
    t118 = (t117 != 0);
    if (t118 > 0)
        goto LAB39;

LAB40:
LAB41:    goto LAB2;

LAB6:    *((unsigned int *)t6) = 1;
    goto LAB9;

LAB8:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB9;

LAB10:    t18 = (t0 + 1528U);
    t19 = *((char **)t18);
    memset(t20, 0, 8);
    t18 = (t19 + 4);
    t21 = *((unsigned int *)t18);
    t22 = (~(t21));
    t23 = *((unsigned int *)t19);
    t24 = (t23 & t22);
    t25 = (t24 & 1U);
    if (t25 != 0)
        goto LAB13;

LAB14:    if (*((unsigned int *)t18) != 0)
        goto LAB15;

LAB16:    t28 = *((unsigned int *)t6);
    t29 = *((unsigned int *)t20);
    t30 = (t28 | t29);
    *((unsigned int *)t27) = t30;
    t31 = (t6 + 4);
    t32 = (t20 + 4);
    t33 = (t27 + 4);
    t34 = *((unsigned int *)t31);
    t35 = *((unsigned int *)t32);
    t36 = (t34 | t35);
    *((unsigned int *)t33) = t36;
    t37 = *((unsigned int *)t33);
    t38 = (t37 != 0);
    if (t38 == 1)
        goto LAB17;

LAB18:
LAB19:    goto LAB12;

LAB13:    *((unsigned int *)t20) = 1;
    goto LAB16;

LAB15:    t26 = (t20 + 4);
    *((unsigned int *)t20) = 1;
    *((unsigned int *)t26) = 1;
    goto LAB16;

LAB17:    t39 = *((unsigned int *)t27);
    t40 = *((unsigned int *)t33);
    *((unsigned int *)t27) = (t39 | t40);
    t41 = (t6 + 4);
    t42 = (t20 + 4);
    t43 = *((unsigned int *)t41);
    t44 = (~(t43));
    t45 = *((unsigned int *)t6);
    t46 = (t45 & t44);
    t47 = *((unsigned int *)t42);
    t48 = (~(t47));
    t49 = *((unsigned int *)t20);
    t50 = (t49 & t48);
    t51 = (~(t46));
    t52 = (~(t50));
    t53 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t53 & t51);
    t54 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t54 & t52);
    goto LAB19;

LAB20:    *((unsigned int *)t55) = 1;
    goto LAB23;

LAB22:    t62 = (t55 + 4);
    *((unsigned int *)t55) = 1;
    *((unsigned int *)t62) = 1;
    goto LAB23;

LAB24:    t67 = (t0 + 1208U);
    t68 = *((char **)t67);
    t67 = ((char*)((ng1)));
    memset(t69, 0, 8);
    t70 = (t68 + 4);
    if (*((unsigned int *)t70) != 0)
        goto LAB28;

LAB27:    t71 = (t67 + 4);
    if (*((unsigned int *)t71) != 0)
        goto LAB28;

LAB31:    if (*((unsigned int *)t68) > *((unsigned int *)t67))
        goto LAB29;

LAB30:    memset(t73, 0, 8);
    t74 = (t69 + 4);
    t75 = *((unsigned int *)t74);
    t76 = (~(t75));
    t77 = *((unsigned int *)t69);
    t78 = (t77 & t76);
    t79 = (t78 & 1U);
    if (t79 != 0)
        goto LAB32;

LAB33:    if (*((unsigned int *)t74) != 0)
        goto LAB34;

LAB35:    t82 = *((unsigned int *)t55);
    t83 = *((unsigned int *)t73);
    t84 = (t82 & t83);
    *((unsigned int *)t81) = t84;
    t85 = (t55 + 4);
    t86 = (t73 + 4);
    t87 = (t81 + 4);
    t88 = *((unsigned int *)t85);
    t89 = *((unsigned int *)t86);
    t90 = (t88 | t89);
    *((unsigned int *)t87) = t90;
    t91 = *((unsigned int *)t87);
    t92 = (t91 != 0);
    if (t92 == 1)
        goto LAB36;

LAB37:
LAB38:    goto LAB26;

LAB28:    t72 = (t69 + 4);
    *((unsigned int *)t69) = 1;
    *((unsigned int *)t72) = 1;
    goto LAB30;

LAB29:    *((unsigned int *)t69) = 1;
    goto LAB30;

LAB32:    *((unsigned int *)t73) = 1;
    goto LAB35;

LAB34:    t80 = (t73 + 4);
    *((unsigned int *)t73) = 1;
    *((unsigned int *)t80) = 1;
    goto LAB35;

LAB36:    t93 = *((unsigned int *)t81);
    t94 = *((unsigned int *)t87);
    *((unsigned int *)t81) = (t93 | t94);
    t95 = (t55 + 4);
    t96 = (t73 + 4);
    t97 = *((unsigned int *)t55);
    t98 = (~(t97));
    t99 = *((unsigned int *)t95);
    t100 = (~(t99));
    t101 = *((unsigned int *)t73);
    t102 = (~(t101));
    t103 = *((unsigned int *)t96);
    t104 = (~(t103));
    t105 = (t98 & t100);
    t106 = (t102 & t104);
    t107 = (~(t105));
    t108 = (~(t106));
    t109 = *((unsigned int *)t87);
    *((unsigned int *)t87) = (t109 & t107);
    t110 = *((unsigned int *)t87);
    *((unsigned int *)t87) = (t110 & t108);
    t111 = *((unsigned int *)t81);
    *((unsigned int *)t81) = (t111 & t107);
    t112 = *((unsigned int *)t81);
    *((unsigned int *)t81) = (t112 & t108);
    goto LAB38;

LAB39:    xsi_set_current_line(40, ng0);

LAB42:    xsi_set_current_line(41, ng0);
    t120 = xsi_vlog_time(t119, 1000.0000000000000, 1000.0000000000000);
    t121 = (t0 + 1208U);
    t122 = *((char **)t121);
    xsi_vlogfile_write(1, 0, 0, ng2, 3, t0, (char)118, t119, 64, (char)118, t122, 8);
    xsi_set_current_line(43, ng0);
    xsi_vlog_finish(1);
    goto LAB41;

}


extern void work_m_00000000004183545097_1414652718_init()
{
	static char *pe[] = {(void *)Always_29_0,(void *)Always_39_1};
	xsi_register_didat("work_m_00000000004183545097_1414652718", "isim/tb_s8_cpu_programs_isim_beh.exe.sim/work/m_00000000004183545097_1414652718.didat");
	xsi_register_executes(pe);
}
