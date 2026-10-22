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
static const char *ng0 = "C:/Users/vboxuser/Documents/ThinyCpu/Thiny_Alu/ThinySpu_tb.v";
static int ng1[] = {1, 0};
static const char *ng2 = "FAIL %0s: a=%02h b=%02h op=%0d -> got %02h Z%C%N%O, exp %02h Z%C%N%O";
static unsigned int ng3[] = {255U, 0U};
static unsigned int ng4[] = {0U, 0U};
static int ng5[] = {0, 0};
static unsigned int ng6[] = {127U, 0U};
static unsigned int ng7[] = {1U, 0U};
static unsigned int ng8[] = {128U, 0U};
static int ng9[] = {1177235505, 0, 1145315383, 0, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng10[] = {1177235505, 0, 1145315398, 0, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng11[] = {808138800, 0, 1145315384, 0, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng12[] = {808267825, 0, 1430396976, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng13[] = {808267825, 0, 1430396984, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng14[] = {5U, 0U};
static int ng15[] = {892153909, 0, 1430396976, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng16[] = {1177372230, 0, 1430396983, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng17[] = {165U, 0U};
static unsigned int ng18[] = {15U, 0U};
static int ng19[] = {2, 0};
static int ng20[] = {891695174, 0, 1313087553, 0, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng21[] = {160U, 0U};
static int ng22[] = {3, 0};
static int ng23[] = {813445173, 0, 1330782273, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng24[] = {4, 0};
static int ng25[] = {1180583494, 0, 1330782278, 0, 88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng26[] = {18U, 0U};
static unsigned int ng27[] = {52U, 0U};
static int ng28[] = {6, 0};
static int ng29[] = {5066582, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng30[] = {7, 0};
static unsigned int ng31[] = {203U, 0U};
static int ng32[] = {1411415650, 0, 20047, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng33[] = {3U, 0U};
static int ng34[] = {5, 0};
static unsigned int ng35[] = {2U, 0U};
static int ng36[] = {892088371, 0, 1297096752, 0, 67, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng37[] = {129U, 0U};
static int ng38[] = {8, 0};
static int ng39[] = {826031153, 0, 1212948536, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng40[] = {1652105264, 0, 1397247008, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng41[] = {7U, 0U};
static int ng42[] = {1178352695, 0, 1212948550, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng43[] = {9, 0};
static int ng44[] = {859717170, 0, 1213341744, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng45[] = {64U, 0U};
static int ng46[] = {826162737, 0, 1213341752, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng47[] = {10, 0};
static int ng48[] = {942746673, 0, 1380928544, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng49[] = {11, 0};
static unsigned int ng50[] = {192U, 0U};
static int ng51[] = {942746673, 0, 1380930080, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng52[] = {1179003955, 0, 1380928544, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng53[] = {256, 0};
static int ng54[] = {543520872, 0, 4277316, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng55[] = {543520872, 0, 5461314, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng56[] = {543520872, 0, 4410704, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng57[] = {543520872, 0, 4279876, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng58[] = {543520872, 0, 20306, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng59[] = {543520872, 0, 5787474, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng60[] = {543520872, 0, 5066582, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng61[] = {543520872, 0, 5132116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng62[] = {543520872, 0, 5457996, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng63[] = {248U, 0U};
static int ng64[] = {1835103083, 0, 1277192297, 0, 21320, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng65[] = {543520872, 0, 5458002, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng66[] = {543520872, 0, 5394252, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng67[] = {1835103083, 0, 1377855593, 0, 21071, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng68[] = {12, 0};
static int ng69[] = {16, 0};
static unsigned int ng70[] = {90U, 0U};
static int ng71[] = {1142976368, 0, 1314214725, 0, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static const char *ng72 = "tb_s8_alu: PASSED (%0d checks, 0 errors)";
static const char *ng73 = "tb_s8_alu: FAILED (%0d checks, %0d errors)";



static int sp_check(char *t1, char *t2)
{
    char t9[8];
    char t11[8];
    char t28[8];
    char t31[8];
    char t39[8];
    char t67[8];
    char t84[8];
    char t87[8];
    char t95[8];
    char t123[8];
    char t140[8];
    char t143[8];
    char t151[8];
    char t179[8];
    char t196[8];
    char t199[8];
    char t207[8];
    char t245[8];
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
    char *t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    char *t74;
    char *t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    char *t80;
    char *t81;
    char *t82;
    char *t83;
    char *t85;
    char *t86;
    char *t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    char *t94;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    char *t99;
    char *t100;
    char *t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    char *t109;
    char *t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    int t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    int t118;
    unsigned int t119;
    unsigned int t120;
    unsigned int t121;
    unsigned int t122;
    char *t124;
    unsigned int t125;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    unsigned int t129;
    char *t130;
    char *t131;
    unsigned int t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    char *t136;
    char *t137;
    char *t138;
    char *t139;
    char *t141;
    char *t142;
    char *t144;
    unsigned int t145;
    unsigned int t146;
    unsigned int t147;
    unsigned int t148;
    unsigned int t149;
    char *t150;
    unsigned int t152;
    unsigned int t153;
    unsigned int t154;
    char *t155;
    char *t156;
    char *t157;
    unsigned int t158;
    unsigned int t159;
    unsigned int t160;
    unsigned int t161;
    unsigned int t162;
    unsigned int t163;
    unsigned int t164;
    char *t165;
    char *t166;
    unsigned int t167;
    unsigned int t168;
    unsigned int t169;
    int t170;
    unsigned int t171;
    unsigned int t172;
    unsigned int t173;
    int t174;
    unsigned int t175;
    unsigned int t176;
    unsigned int t177;
    unsigned int t178;
    char *t180;
    unsigned int t181;
    unsigned int t182;
    unsigned int t183;
    unsigned int t184;
    unsigned int t185;
    char *t186;
    char *t187;
    unsigned int t188;
    unsigned int t189;
    unsigned int t190;
    unsigned int t191;
    char *t192;
    char *t193;
    char *t194;
    char *t195;
    char *t197;
    char *t198;
    char *t200;
    unsigned int t201;
    unsigned int t202;
    unsigned int t203;
    unsigned int t204;
    unsigned int t205;
    char *t206;
    unsigned int t208;
    unsigned int t209;
    unsigned int t210;
    char *t211;
    char *t212;
    char *t213;
    unsigned int t214;
    unsigned int t215;
    unsigned int t216;
    unsigned int t217;
    unsigned int t218;
    unsigned int t219;
    unsigned int t220;
    char *t221;
    char *t222;
    unsigned int t223;
    unsigned int t224;
    unsigned int t225;
    int t226;
    unsigned int t227;
    unsigned int t228;
    unsigned int t229;
    int t230;
    unsigned int t231;
    unsigned int t232;
    unsigned int t233;
    unsigned int t234;
    char *t235;
    unsigned int t236;
    unsigned int t237;
    unsigned int t238;
    unsigned int t239;
    unsigned int t240;
    char *t241;
    char *t242;
    char *t243;
    char *t244;
    char *t246;

LAB0:    t0 = 1;
    t3 = (t2 + 48U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 848);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);
    xsi_set_current_line(60, ng0);

LAB5:    xsi_set_current_line(61, ng0);
    t5 = (t1 + 4344);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = ((char*)((ng1)));
    memset(t9, 0, 8);
    xsi_vlog_signed_add(t9, 32, t7, 32, t8, 32);
    t10 = (t1 + 4344);
    xsi_vlogvar_assign_value(t10, t9, 0, 0, 32);
    xsi_set_current_line(62, ng0);
    t4 = (t1 + 2344U);
    t5 = *((char **)t4);
    t4 = (t1 + 5784);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    memset(t9, 0, 8);
    if (*((unsigned int *)t5) != *((unsigned int *)t7))
        goto LAB7;

LAB6:    t8 = (t5 + 4);
    t10 = (t7 + 4);
    if (*((unsigned int *)t8) != *((unsigned int *)t10))
        goto LAB7;

LAB8:    memset(t11, 0, 8);
    t12 = (t9 + 4);
    t13 = *((unsigned int *)t12);
    t14 = (~(t13));
    t15 = *((unsigned int *)t9);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB9;

LAB10:    if (*((unsigned int *)t12) != 0)
        goto LAB11;

LAB12:    t19 = (t11 + 4);
    t20 = *((unsigned int *)t11);
    t21 = (!(t20));
    t22 = *((unsigned int *)t19);
    t23 = (t21 || t22);
    if (t23 > 0)
        goto LAB13;

LAB14:    memcpy(t39, t11, 8);

LAB15:    memset(t67, 0, 8);
    t68 = (t39 + 4);
    t69 = *((unsigned int *)t68);
    t70 = (~(t69));
    t71 = *((unsigned int *)t39);
    t72 = (t71 & t70);
    t73 = (t72 & 1U);
    if (t73 != 0)
        goto LAB26;

LAB27:    if (*((unsigned int *)t68) != 0)
        goto LAB28;

LAB29:    t75 = (t67 + 4);
    t76 = *((unsigned int *)t67);
    t77 = (!(t76));
    t78 = *((unsigned int *)t75);
    t79 = (t77 || t78);
    if (t79 > 0)
        goto LAB30;

LAB31:    memcpy(t95, t67, 8);

LAB32:    memset(t123, 0, 8);
    t124 = (t95 + 4);
    t125 = *((unsigned int *)t124);
    t126 = (~(t125));
    t127 = *((unsigned int *)t95);
    t128 = (t127 & t126);
    t129 = (t128 & 1U);
    if (t129 != 0)
        goto LAB43;

LAB44:    if (*((unsigned int *)t124) != 0)
        goto LAB45;

LAB46:    t131 = (t123 + 4);
    t132 = *((unsigned int *)t123);
    t133 = (!(t132));
    t134 = *((unsigned int *)t131);
    t135 = (t133 || t134);
    if (t135 > 0)
        goto LAB47;

LAB48:    memcpy(t151, t123, 8);

LAB49:    memset(t179, 0, 8);
    t180 = (t151 + 4);
    t181 = *((unsigned int *)t180);
    t182 = (~(t181));
    t183 = *((unsigned int *)t151);
    t184 = (t183 & t182);
    t185 = (t184 & 1U);
    if (t185 != 0)
        goto LAB60;

LAB61:    if (*((unsigned int *)t180) != 0)
        goto LAB62;

LAB63:    t187 = (t179 + 4);
    t188 = *((unsigned int *)t179);
    t189 = (!(t188));
    t190 = *((unsigned int *)t187);
    t191 = (t189 || t190);
    if (t191 > 0)
        goto LAB64;

LAB65:    memcpy(t207, t179, 8);

LAB66:    t235 = (t207 + 4);
    t236 = *((unsigned int *)t235);
    t237 = (~(t236));
    t238 = *((unsigned int *)t207);
    t239 = (t238 & t237);
    t240 = (t239 != 0);
    if (t240 > 0)
        goto LAB77;

LAB78:
LAB79:
LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 48U);
    *((char **)t4) = &&LAB2;
    t0 = 0;

LAB1:    return t0;
LAB7:    *((unsigned int *)t9) = 1;
    goto LAB8;

LAB9:    *((unsigned int *)t11) = 1;
    goto LAB12;

LAB11:    t18 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t18) = 1;
    goto LAB12;

LAB13:    t24 = (t1 + 2504U);
    t25 = *((char **)t24);
    t24 = (t1 + 5944);
    t26 = (t24 + 56U);
    t27 = *((char **)t26);
    memset(t28, 0, 8);
    if (*((unsigned int *)t25) != *((unsigned int *)t27))
        goto LAB17;

LAB16:    t29 = (t25 + 4);
    t30 = (t27 + 4);
    if (*((unsigned int *)t29) != *((unsigned int *)t30))
        goto LAB17;

LAB18:    memset(t31, 0, 8);
    t32 = (t28 + 4);
    t33 = *((unsigned int *)t32);
    t34 = (~(t33));
    t35 = *((unsigned int *)t28);
    t36 = (t35 & t34);
    t37 = (t36 & 1U);
    if (t37 != 0)
        goto LAB19;

LAB20:    if (*((unsigned int *)t32) != 0)
        goto LAB21;

LAB22:    t40 = *((unsigned int *)t11);
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
        goto LAB23;

LAB24:
LAB25:    goto LAB15;

LAB17:    *((unsigned int *)t28) = 1;
    goto LAB18;

LAB19:    *((unsigned int *)t31) = 1;
    goto LAB22;

LAB21:    t38 = (t31 + 4);
    *((unsigned int *)t31) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB22;

LAB23:    t51 = *((unsigned int *)t39);
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
    goto LAB25;

LAB26:    *((unsigned int *)t67) = 1;
    goto LAB29;

LAB28:    t74 = (t67 + 4);
    *((unsigned int *)t67) = 1;
    *((unsigned int *)t74) = 1;
    goto LAB29;

LAB30:    t80 = (t1 + 2664U);
    t81 = *((char **)t80);
    t80 = (t1 + 6104);
    t82 = (t80 + 56U);
    t83 = *((char **)t82);
    memset(t84, 0, 8);
    if (*((unsigned int *)t81) != *((unsigned int *)t83))
        goto LAB34;

LAB33:    t85 = (t81 + 4);
    t86 = (t83 + 4);
    if (*((unsigned int *)t85) != *((unsigned int *)t86))
        goto LAB34;

LAB35:    memset(t87, 0, 8);
    t88 = (t84 + 4);
    t89 = *((unsigned int *)t88);
    t90 = (~(t89));
    t91 = *((unsigned int *)t84);
    t92 = (t91 & t90);
    t93 = (t92 & 1U);
    if (t93 != 0)
        goto LAB36;

LAB37:    if (*((unsigned int *)t88) != 0)
        goto LAB38;

LAB39:    t96 = *((unsigned int *)t67);
    t97 = *((unsigned int *)t87);
    t98 = (t96 | t97);
    *((unsigned int *)t95) = t98;
    t99 = (t67 + 4);
    t100 = (t87 + 4);
    t101 = (t95 + 4);
    t102 = *((unsigned int *)t99);
    t103 = *((unsigned int *)t100);
    t104 = (t102 | t103);
    *((unsigned int *)t101) = t104;
    t105 = *((unsigned int *)t101);
    t106 = (t105 != 0);
    if (t106 == 1)
        goto LAB40;

LAB41:
LAB42:    goto LAB32;

LAB34:    *((unsigned int *)t84) = 1;
    goto LAB35;

LAB36:    *((unsigned int *)t87) = 1;
    goto LAB39;

LAB38:    t94 = (t87 + 4);
    *((unsigned int *)t87) = 1;
    *((unsigned int *)t94) = 1;
    goto LAB39;

LAB40:    t107 = *((unsigned int *)t95);
    t108 = *((unsigned int *)t101);
    *((unsigned int *)t95) = (t107 | t108);
    t109 = (t67 + 4);
    t110 = (t87 + 4);
    t111 = *((unsigned int *)t109);
    t112 = (~(t111));
    t113 = *((unsigned int *)t67);
    t114 = (t113 & t112);
    t115 = *((unsigned int *)t110);
    t116 = (~(t115));
    t117 = *((unsigned int *)t87);
    t118 = (t117 & t116);
    t119 = (~(t114));
    t120 = (~(t118));
    t121 = *((unsigned int *)t101);
    *((unsigned int *)t101) = (t121 & t119);
    t122 = *((unsigned int *)t101);
    *((unsigned int *)t101) = (t122 & t120);
    goto LAB42;

LAB43:    *((unsigned int *)t123) = 1;
    goto LAB46;

LAB45:    t130 = (t123 + 4);
    *((unsigned int *)t123) = 1;
    *((unsigned int *)t130) = 1;
    goto LAB46;

LAB47:    t136 = (t1 + 2824U);
    t137 = *((char **)t136);
    t136 = (t1 + 6264);
    t138 = (t136 + 56U);
    t139 = *((char **)t138);
    memset(t140, 0, 8);
    if (*((unsigned int *)t137) != *((unsigned int *)t139))
        goto LAB51;

LAB50:    t141 = (t137 + 4);
    t142 = (t139 + 4);
    if (*((unsigned int *)t141) != *((unsigned int *)t142))
        goto LAB51;

LAB52:    memset(t143, 0, 8);
    t144 = (t140 + 4);
    t145 = *((unsigned int *)t144);
    t146 = (~(t145));
    t147 = *((unsigned int *)t140);
    t148 = (t147 & t146);
    t149 = (t148 & 1U);
    if (t149 != 0)
        goto LAB53;

LAB54:    if (*((unsigned int *)t144) != 0)
        goto LAB55;

LAB56:    t152 = *((unsigned int *)t123);
    t153 = *((unsigned int *)t143);
    t154 = (t152 | t153);
    *((unsigned int *)t151) = t154;
    t155 = (t123 + 4);
    t156 = (t143 + 4);
    t157 = (t151 + 4);
    t158 = *((unsigned int *)t155);
    t159 = *((unsigned int *)t156);
    t160 = (t158 | t159);
    *((unsigned int *)t157) = t160;
    t161 = *((unsigned int *)t157);
    t162 = (t161 != 0);
    if (t162 == 1)
        goto LAB57;

LAB58:
LAB59:    goto LAB49;

LAB51:    *((unsigned int *)t140) = 1;
    goto LAB52;

LAB53:    *((unsigned int *)t143) = 1;
    goto LAB56;

LAB55:    t150 = (t143 + 4);
    *((unsigned int *)t143) = 1;
    *((unsigned int *)t150) = 1;
    goto LAB56;

LAB57:    t163 = *((unsigned int *)t151);
    t164 = *((unsigned int *)t157);
    *((unsigned int *)t151) = (t163 | t164);
    t165 = (t123 + 4);
    t166 = (t143 + 4);
    t167 = *((unsigned int *)t165);
    t168 = (~(t167));
    t169 = *((unsigned int *)t123);
    t170 = (t169 & t168);
    t171 = *((unsigned int *)t166);
    t172 = (~(t171));
    t173 = *((unsigned int *)t143);
    t174 = (t173 & t172);
    t175 = (~(t170));
    t176 = (~(t174));
    t177 = *((unsigned int *)t157);
    *((unsigned int *)t157) = (t177 & t175);
    t178 = *((unsigned int *)t157);
    *((unsigned int *)t157) = (t178 & t176);
    goto LAB59;

LAB60:    *((unsigned int *)t179) = 1;
    goto LAB63;

LAB62:    t186 = (t179 + 4);
    *((unsigned int *)t179) = 1;
    *((unsigned int *)t186) = 1;
    goto LAB63;

LAB64:    t192 = (t1 + 2984U);
    t193 = *((char **)t192);
    t192 = (t1 + 6424);
    t194 = (t192 + 56U);
    t195 = *((char **)t194);
    memset(t196, 0, 8);
    if (*((unsigned int *)t193) != *((unsigned int *)t195))
        goto LAB68;

LAB67:    t197 = (t193 + 4);
    t198 = (t195 + 4);
    if (*((unsigned int *)t197) != *((unsigned int *)t198))
        goto LAB68;

LAB69:    memset(t199, 0, 8);
    t200 = (t196 + 4);
    t201 = *((unsigned int *)t200);
    t202 = (~(t201));
    t203 = *((unsigned int *)t196);
    t204 = (t203 & t202);
    t205 = (t204 & 1U);
    if (t205 != 0)
        goto LAB70;

LAB71:    if (*((unsigned int *)t200) != 0)
        goto LAB72;

LAB73:    t208 = *((unsigned int *)t179);
    t209 = *((unsigned int *)t199);
    t210 = (t208 | t209);
    *((unsigned int *)t207) = t210;
    t211 = (t179 + 4);
    t212 = (t199 + 4);
    t213 = (t207 + 4);
    t214 = *((unsigned int *)t211);
    t215 = *((unsigned int *)t212);
    t216 = (t214 | t215);
    *((unsigned int *)t213) = t216;
    t217 = *((unsigned int *)t213);
    t218 = (t217 != 0);
    if (t218 == 1)
        goto LAB74;

LAB75:
LAB76:    goto LAB66;

LAB68:    *((unsigned int *)t196) = 1;
    goto LAB69;

LAB70:    *((unsigned int *)t199) = 1;
    goto LAB73;

LAB72:    t206 = (t199 + 4);
    *((unsigned int *)t199) = 1;
    *((unsigned int *)t206) = 1;
    goto LAB73;

LAB74:    t219 = *((unsigned int *)t207);
    t220 = *((unsigned int *)t213);
    *((unsigned int *)t207) = (t219 | t220);
    t221 = (t179 + 4);
    t222 = (t199 + 4);
    t223 = *((unsigned int *)t221);
    t224 = (~(t223));
    t225 = *((unsigned int *)t179);
    t226 = (t225 & t224);
    t227 = *((unsigned int *)t222);
    t228 = (~(t227));
    t229 = *((unsigned int *)t199);
    t230 = (t229 & t228);
    t231 = (~(t226));
    t232 = (~(t230));
    t233 = *((unsigned int *)t213);
    *((unsigned int *)t213) = (t233 & t231);
    t234 = *((unsigned int *)t213);
    *((unsigned int *)t213) = (t234 & t232);
    goto LAB76;

LAB77:    xsi_set_current_line(63, ng0);

LAB80:    xsi_set_current_line(64, ng0);
    t241 = (t1 + 4504);
    t242 = (t241 + 56U);
    t243 = *((char **)t242);
    t244 = ((char*)((ng1)));
    memset(t245, 0, 8);
    xsi_vlog_signed_add(t245, 32, t243, 32, t244, 32);
    t246 = (t1 + 4504);
    xsi_vlogvar_assign_value(t246, t245, 0, 0, 32);
    xsi_set_current_line(65, ng0);
    t4 = (t1 + 6584);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 3384);
    t8 = (t7 + 56U);
    t10 = *((char **)t8);
    t12 = (t1 + 3544);
    t18 = (t12 + 56U);
    t19 = *((char **)t18);
    t24 = (t1 + 3704);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    t27 = (t1 + 2344U);
    t29 = *((char **)t27);
    t27 = (t1 + 2504U);
    t30 = *((char **)t27);
    t27 = (t1 + 2664U);
    t32 = *((char **)t27);
    t27 = (t1 + 2824U);
    t38 = *((char **)t27);
    t27 = (t1 + 2984U);
    t43 = *((char **)t27);
    t27 = (t1 + 5784);
    t44 = (t27 + 56U);
    t45 = *((char **)t44);
    t53 = (t1 + 5944);
    t54 = (t53 + 56U);
    t68 = *((char **)t54);
    t74 = (t1 + 6104);
    t75 = (t74 + 56U);
    t80 = *((char **)t75);
    t81 = (t1 + 6264);
    t82 = (t81 + 56U);
    t83 = *((char **)t82);
    t85 = (t1 + 6424);
    t86 = (t85 + 56U);
    t88 = *((char **)t86);
    t94 = (t1 + 848);
    xsi_vlogfile_write(1, 0, 0, ng2, 15, t94, (char)118, t6, 256, (char)118, t10, 8, (char)118, t19, 8, (char)118, t26, 4, (char)118, t29, 8, (char)118, t30, 1, (char)118, t32, 1, (char)118, t38, 1, (char)118, t43, 1, (char)118, t45, 8, (char)118, t68, 1, (char)118, t80, 1, (char)118, t83, 1, (char)118, t88, 1);
    goto LAB79;

}

static int sp_ref_add(char *t1, char *t2)
{
    char t11[8];
    char t41[8];
    char t42[8];
    char t46[8];
    char t61[8];
    char t73[8];
    char t82[8];
    char t98[8];
    char t106[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    int t32;
    int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;
    char *t43;
    char *t44;
    char *t45;
    char *t47;
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
    char *t58;
    char *t59;
    char *t60;
    char *t62;
    char *t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    char *t70;
    char *t71;
    char *t72;
    char *t74;
    char *t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    char *t83;
    char *t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    char *t97;
    char *t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    char *t105;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    char *t110;
    char *t111;
    char *t112;
    unsigned int t113;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    unsigned int t119;
    char *t120;
    char *t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t125;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    unsigned int t129;
    unsigned int t130;
    unsigned int t131;
    unsigned int t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    char *t136;

LAB0:    t0 = 1;
    t3 = (t2 + 48U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 1280);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);
    xsi_set_current_line(74, ng0);

LAB5:    xsi_set_current_line(75, ng0);
    t5 = (t1 + 3384);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t1 + 3544);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memset(t11, 0, 8);
    xsi_vlog_unsigned_add(t11, 32, t7, 8, t10, 8);
    t12 = (t1 + 4664);
    xsi_vlogvar_assign_value(t12, t11, 0, 0, 32);
    xsi_set_current_line(76, ng0);
    t4 = (t1 + 4664);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng3)));
    t13 = *((unsigned int *)t6);
    t14 = *((unsigned int *)t7);
    t15 = (t13 & t14);
    *((unsigned int *)t11) = t15;
    t8 = (t6 + 4);
    t9 = (t7 + 4);
    t10 = (t11 + 4);
    t16 = *((unsigned int *)t8);
    t17 = *((unsigned int *)t9);
    t18 = (t16 | t17);
    *((unsigned int *)t10) = t18;
    t19 = *((unsigned int *)t10);
    t20 = (t19 != 0);
    if (t20 == 1)
        goto LAB6;

LAB7:
LAB8:    t40 = (t1 + 4984);
    xsi_vlogvar_assign_value(t40, t11, 0, 0, 8);
    xsi_set_current_line(77, ng0);
    t4 = (t1 + 4664);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng3)));
    memset(t11, 0, 8);
    t8 = (t6 + 4);
    if (*((unsigned int *)t8) != 0)
        goto LAB10;

LAB9:    t9 = (t7 + 4);
    if (*((unsigned int *)t9) != 0)
        goto LAB10;

LAB13:    if (*((unsigned int *)t6) > *((unsigned int *)t7))
        goto LAB11;

LAB12:    t12 = (t1 + 5304);
    xsi_vlogvar_assign_value(t12, t11, 0, 0, 1);
    xsi_set_current_line(78, ng0);
    t4 = (t1 + 4984);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng4)));
    memset(t11, 0, 8);
    t8 = (t6 + 4);
    t9 = (t7 + 4);
    t13 = *((unsigned int *)t6);
    t14 = *((unsigned int *)t7);
    t15 = (t13 ^ t14);
    t16 = *((unsigned int *)t8);
    t17 = *((unsigned int *)t9);
    t18 = (t16 ^ t17);
    t19 = (t15 | t18);
    t20 = *((unsigned int *)t8);
    t21 = *((unsigned int *)t9);
    t22 = (t20 | t21);
    t24 = (~(t22));
    t25 = (t19 & t24);
    if (t25 != 0)
        goto LAB17;

LAB14:    if (t22 != 0)
        goto LAB16;

LAB15:    *((unsigned int *)t11) = 1;

LAB17:    t12 = (t1 + 5144);
    xsi_vlogvar_assign_value(t12, t11, 0, 0, 1);
    xsi_set_current_line(79, ng0);
    t4 = (t1 + 4984);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t11, 0, 8);
    t7 = (t11 + 4);
    t8 = (t6 + 4);
    t13 = *((unsigned int *)t6);
    t14 = (t13 >> 7);
    t15 = (t14 & 1);
    *((unsigned int *)t11) = t15;
    t16 = *((unsigned int *)t8);
    t17 = (t16 >> 7);
    t18 = (t17 & 1);
    *((unsigned int *)t7) = t18;
    t9 = (t1 + 5464);
    xsi_vlogvar_assign_value(t9, t11, 0, 0, 1);
    xsi_set_current_line(80, ng0);
    t4 = (t1 + 3384);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t11, 0, 8);
    t7 = (t11 + 4);
    t8 = (t6 + 4);
    t13 = *((unsigned int *)t6);
    t14 = (t13 >> 7);
    t15 = (t14 & 1);
    *((unsigned int *)t11) = t15;
    t16 = *((unsigned int *)t8);
    t17 = (t16 >> 7);
    t18 = (t17 & 1);
    *((unsigned int *)t7) = t18;
    t9 = (t1 + 3544);
    t10 = (t9 + 56U);
    t12 = *((char **)t10);
    memset(t41, 0, 8);
    t23 = (t41 + 4);
    t40 = (t12 + 4);
    t19 = *((unsigned int *)t12);
    t20 = (t19 >> 7);
    t21 = (t20 & 1);
    *((unsigned int *)t41) = t21;
    t22 = *((unsigned int *)t40);
    t24 = (t22 >> 7);
    t25 = (t24 & 1);
    *((unsigned int *)t23) = t25;
    memset(t42, 0, 8);
    t43 = (t11 + 4);
    t44 = (t41 + 4);
    t26 = *((unsigned int *)t11);
    t27 = *((unsigned int *)t41);
    t28 = (t26 ^ t27);
    t29 = *((unsigned int *)t43);
    t30 = *((unsigned int *)t44);
    t31 = (t29 ^ t30);
    t34 = (t28 | t31);
    t35 = *((unsigned int *)t43);
    t36 = *((unsigned int *)t44);
    t37 = (t35 | t36);
    t38 = (~(t37));
    t39 = (t34 & t38);
    if (t39 != 0)
        goto LAB21;

LAB18:    if (t37 != 0)
        goto LAB20;

LAB19:    *((unsigned int *)t42) = 1;

LAB21:    memset(t46, 0, 8);
    t47 = (t42 + 4);
    t48 = *((unsigned int *)t47);
    t49 = (~(t48));
    t50 = *((unsigned int *)t42);
    t51 = (t50 & t49);
    t52 = (t51 & 1U);
    if (t52 != 0)
        goto LAB22;

LAB23:    if (*((unsigned int *)t47) != 0)
        goto LAB24;

LAB25:    t54 = (t46 + 4);
    t55 = *((unsigned int *)t46);
    t56 = *((unsigned int *)t54);
    t57 = (t55 || t56);
    if (t57 > 0)
        goto LAB26;

LAB27:    memcpy(t106, t46, 8);

LAB28:    t136 = (t1 + 5624);
    xsi_vlogvar_assign_value(t136, t106, 0, 0, 1);

LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 48U);
    *((char **)t4) = &&LAB2;
    t0 = 0;

LAB1:    return t0;
LAB6:    t21 = *((unsigned int *)t11);
    t22 = *((unsigned int *)t10);
    *((unsigned int *)t11) = (t21 | t22);
    t12 = (t6 + 4);
    t23 = (t7 + 4);
    t24 = *((unsigned int *)t6);
    t25 = (~(t24));
    t26 = *((unsigned int *)t12);
    t27 = (~(t26));
    t28 = *((unsigned int *)t7);
    t29 = (~(t28));
    t30 = *((unsigned int *)t23);
    t31 = (~(t30));
    t32 = (t25 & t27);
    t33 = (t29 & t31);
    t34 = (~(t32));
    t35 = (~(t33));
    t36 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t36 & t34);
    t37 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t37 & t35);
    t38 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t38 & t34);
    t39 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t39 & t35);
    goto LAB8;

LAB10:    t10 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB12;

LAB11:    *((unsigned int *)t11) = 1;
    goto LAB12;

LAB16:    t10 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB17;

LAB20:    t45 = (t42 + 4);
    *((unsigned int *)t42) = 1;
    *((unsigned int *)t45) = 1;
    goto LAB21;

LAB22:    *((unsigned int *)t46) = 1;
    goto LAB25;

LAB24:    t53 = (t46 + 4);
    *((unsigned int *)t46) = 1;
    *((unsigned int *)t53) = 1;
    goto LAB25;

LAB26:    t58 = (t1 + 4984);
    t59 = (t58 + 56U);
    t60 = *((char **)t59);
    memset(t61, 0, 8);
    t62 = (t61 + 4);
    t63 = (t60 + 4);
    t64 = *((unsigned int *)t60);
    t65 = (t64 >> 7);
    t66 = (t65 & 1);
    *((unsigned int *)t61) = t66;
    t67 = *((unsigned int *)t63);
    t68 = (t67 >> 7);
    t69 = (t68 & 1);
    *((unsigned int *)t62) = t69;
    t70 = (t1 + 3384);
    t71 = (t70 + 56U);
    t72 = *((char **)t71);
    memset(t73, 0, 8);
    t74 = (t73 + 4);
    t75 = (t72 + 4);
    t76 = *((unsigned int *)t72);
    t77 = (t76 >> 7);
    t78 = (t77 & 1);
    *((unsigned int *)t73) = t78;
    t79 = *((unsigned int *)t75);
    t80 = (t79 >> 7);
    t81 = (t80 & 1);
    *((unsigned int *)t74) = t81;
    memset(t82, 0, 8);
    t83 = (t61 + 4);
    t84 = (t73 + 4);
    t85 = *((unsigned int *)t61);
    t86 = *((unsigned int *)t73);
    t87 = (t85 ^ t86);
    t88 = *((unsigned int *)t83);
    t89 = *((unsigned int *)t84);
    t90 = (t88 ^ t89);
    t91 = (t87 | t90);
    t92 = *((unsigned int *)t83);
    t93 = *((unsigned int *)t84);
    t94 = (t92 | t93);
    t95 = (~(t94));
    t96 = (t91 & t95);
    if (t96 != 0)
        goto LAB30;

LAB29:    if (t94 != 0)
        goto LAB31;

LAB32:    memset(t98, 0, 8);
    t99 = (t82 + 4);
    t100 = *((unsigned int *)t99);
    t101 = (~(t100));
    t102 = *((unsigned int *)t82);
    t103 = (t102 & t101);
    t104 = (t103 & 1U);
    if (t104 != 0)
        goto LAB33;

LAB34:    if (*((unsigned int *)t99) != 0)
        goto LAB35;

LAB36:    t107 = *((unsigned int *)t46);
    t108 = *((unsigned int *)t98);
    t109 = (t107 & t108);
    *((unsigned int *)t106) = t109;
    t110 = (t46 + 4);
    t111 = (t98 + 4);
    t112 = (t106 + 4);
    t113 = *((unsigned int *)t110);
    t114 = *((unsigned int *)t111);
    t115 = (t113 | t114);
    *((unsigned int *)t112) = t115;
    t116 = *((unsigned int *)t112);
    t117 = (t116 != 0);
    if (t117 == 1)
        goto LAB37;

LAB38:
LAB39:    goto LAB28;

LAB30:    *((unsigned int *)t82) = 1;
    goto LAB32;

LAB31:    t97 = (t82 + 4);
    *((unsigned int *)t82) = 1;
    *((unsigned int *)t97) = 1;
    goto LAB32;

LAB33:    *((unsigned int *)t98) = 1;
    goto LAB36;

LAB35:    t105 = (t98 + 4);
    *((unsigned int *)t98) = 1;
    *((unsigned int *)t105) = 1;
    goto LAB36;

LAB37:    t118 = *((unsigned int *)t106);
    t119 = *((unsigned int *)t112);
    *((unsigned int *)t106) = (t118 | t119);
    t120 = (t46 + 4);
    t121 = (t98 + 4);
    t122 = *((unsigned int *)t46);
    t123 = (~(t122));
    t124 = *((unsigned int *)t120);
    t125 = (~(t124));
    t126 = *((unsigned int *)t98);
    t127 = (~(t126));
    t128 = *((unsigned int *)t121);
    t129 = (~(t128));
    t32 = (t123 & t125);
    t33 = (t127 & t129);
    t130 = (~(t32));
    t131 = (~(t33));
    t132 = *((unsigned int *)t112);
    *((unsigned int *)t112) = (t132 & t130);
    t133 = *((unsigned int *)t112);
    *((unsigned int *)t112) = (t133 & t131);
    t134 = *((unsigned int *)t106);
    *((unsigned int *)t106) = (t134 & t130);
    t135 = *((unsigned int *)t106);
    *((unsigned int *)t106) = (t135 & t131);
    goto LAB39;

}

static int sp_ref_sub(char *t1, char *t2)
{
    char t11[8];
    char t41[8];
    char t42[8];
    char t46[8];
    char t61[8];
    char t73[8];
    char t82[8];
    char t98[8];
    char t106[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    int t32;
    int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;
    char *t43;
    char *t44;
    char *t45;
    char *t47;
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
    char *t58;
    char *t59;
    char *t60;
    char *t62;
    char *t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    char *t70;
    char *t71;
    char *t72;
    char *t74;
    char *t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    char *t83;
    char *t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    char *t97;
    char *t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    char *t105;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    char *t110;
    char *t111;
    char *t112;
    unsigned int t113;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    unsigned int t119;
    char *t120;
    char *t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t125;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    unsigned int t129;
    unsigned int t130;
    unsigned int t131;
    unsigned int t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    char *t136;

LAB0:    t0 = 1;
    t3 = (t2 + 48U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 1712);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);
    xsi_set_current_line(85, ng0);

LAB5:    xsi_set_current_line(86, ng0);
    t5 = (t1 + 3384);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t1 + 3544);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memset(t11, 0, 8);
    xsi_vlog_unsigned_minus(t11, 32, t7, 8, t10, 8);
    t12 = (t1 + 4824);
    xsi_vlogvar_assign_value(t12, t11, 0, 0, 32);
    xsi_set_current_line(87, ng0);
    t4 = (t1 + 4824);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng3)));
    t13 = *((unsigned int *)t6);
    t14 = *((unsigned int *)t7);
    t15 = (t13 & t14);
    *((unsigned int *)t11) = t15;
    t8 = (t6 + 4);
    t9 = (t7 + 4);
    t10 = (t11 + 4);
    t16 = *((unsigned int *)t8);
    t17 = *((unsigned int *)t9);
    t18 = (t16 | t17);
    *((unsigned int *)t10) = t18;
    t19 = *((unsigned int *)t10);
    t20 = (t19 != 0);
    if (t20 == 1)
        goto LAB6;

LAB7:
LAB8:    t40 = (t1 + 4984);
    xsi_vlogvar_assign_value(t40, t11, 0, 0, 8);
    xsi_set_current_line(88, ng0);
    t4 = (t1 + 3384);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 3544);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t11, 0, 8);
    t10 = (t6 + 4);
    if (*((unsigned int *)t10) != 0)
        goto LAB10;

LAB9:    t12 = (t9 + 4);
    if (*((unsigned int *)t12) != 0)
        goto LAB10;

LAB13:    if (*((unsigned int *)t6) < *((unsigned int *)t9))
        goto LAB12;

LAB11:    *((unsigned int *)t11) = 1;

LAB12:    t40 = (t1 + 5304);
    xsi_vlogvar_assign_value(t40, t11, 0, 0, 1);
    xsi_set_current_line(89, ng0);
    t4 = (t1 + 4984);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng4)));
    memset(t11, 0, 8);
    t8 = (t6 + 4);
    t9 = (t7 + 4);
    t13 = *((unsigned int *)t6);
    t14 = *((unsigned int *)t7);
    t15 = (t13 ^ t14);
    t16 = *((unsigned int *)t8);
    t17 = *((unsigned int *)t9);
    t18 = (t16 ^ t17);
    t19 = (t15 | t18);
    t20 = *((unsigned int *)t8);
    t21 = *((unsigned int *)t9);
    t22 = (t20 | t21);
    t24 = (~(t22));
    t25 = (t19 & t24);
    if (t25 != 0)
        goto LAB17;

LAB14:    if (t22 != 0)
        goto LAB16;

LAB15:    *((unsigned int *)t11) = 1;

LAB17:    t12 = (t1 + 5144);
    xsi_vlogvar_assign_value(t12, t11, 0, 0, 1);
    xsi_set_current_line(90, ng0);
    t4 = (t1 + 4984);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t11, 0, 8);
    t7 = (t11 + 4);
    t8 = (t6 + 4);
    t13 = *((unsigned int *)t6);
    t14 = (t13 >> 7);
    t15 = (t14 & 1);
    *((unsigned int *)t11) = t15;
    t16 = *((unsigned int *)t8);
    t17 = (t16 >> 7);
    t18 = (t17 & 1);
    *((unsigned int *)t7) = t18;
    t9 = (t1 + 5464);
    xsi_vlogvar_assign_value(t9, t11, 0, 0, 1);
    xsi_set_current_line(91, ng0);
    t4 = (t1 + 3384);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t11, 0, 8);
    t7 = (t11 + 4);
    t8 = (t6 + 4);
    t13 = *((unsigned int *)t6);
    t14 = (t13 >> 7);
    t15 = (t14 & 1);
    *((unsigned int *)t11) = t15;
    t16 = *((unsigned int *)t8);
    t17 = (t16 >> 7);
    t18 = (t17 & 1);
    *((unsigned int *)t7) = t18;
    t9 = (t1 + 3544);
    t10 = (t9 + 56U);
    t12 = *((char **)t10);
    memset(t41, 0, 8);
    t23 = (t41 + 4);
    t40 = (t12 + 4);
    t19 = *((unsigned int *)t12);
    t20 = (t19 >> 7);
    t21 = (t20 & 1);
    *((unsigned int *)t41) = t21;
    t22 = *((unsigned int *)t40);
    t24 = (t22 >> 7);
    t25 = (t24 & 1);
    *((unsigned int *)t23) = t25;
    memset(t42, 0, 8);
    t43 = (t11 + 4);
    t44 = (t41 + 4);
    t26 = *((unsigned int *)t11);
    t27 = *((unsigned int *)t41);
    t28 = (t26 ^ t27);
    t29 = *((unsigned int *)t43);
    t30 = *((unsigned int *)t44);
    t31 = (t29 ^ t30);
    t34 = (t28 | t31);
    t35 = *((unsigned int *)t43);
    t36 = *((unsigned int *)t44);
    t37 = (t35 | t36);
    t38 = (~(t37));
    t39 = (t34 & t38);
    if (t39 != 0)
        goto LAB19;

LAB18:    if (t37 != 0)
        goto LAB20;

LAB21:    memset(t46, 0, 8);
    t47 = (t42 + 4);
    t48 = *((unsigned int *)t47);
    t49 = (~(t48));
    t50 = *((unsigned int *)t42);
    t51 = (t50 & t49);
    t52 = (t51 & 1U);
    if (t52 != 0)
        goto LAB22;

LAB23:    if (*((unsigned int *)t47) != 0)
        goto LAB24;

LAB25:    t54 = (t46 + 4);
    t55 = *((unsigned int *)t46);
    t56 = *((unsigned int *)t54);
    t57 = (t55 || t56);
    if (t57 > 0)
        goto LAB26;

LAB27:    memcpy(t106, t46, 8);

LAB28:    t136 = (t1 + 5624);
    xsi_vlogvar_assign_value(t136, t106, 0, 0, 1);

LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 48U);
    *((char **)t4) = &&LAB2;
    t0 = 0;

LAB1:    return t0;
LAB6:    t21 = *((unsigned int *)t11);
    t22 = *((unsigned int *)t10);
    *((unsigned int *)t11) = (t21 | t22);
    t12 = (t6 + 4);
    t23 = (t7 + 4);
    t24 = *((unsigned int *)t6);
    t25 = (~(t24));
    t26 = *((unsigned int *)t12);
    t27 = (~(t26));
    t28 = *((unsigned int *)t7);
    t29 = (~(t28));
    t30 = *((unsigned int *)t23);
    t31 = (~(t30));
    t32 = (t25 & t27);
    t33 = (t29 & t31);
    t34 = (~(t32));
    t35 = (~(t33));
    t36 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t36 & t34);
    t37 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t37 & t35);
    t38 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t38 & t34);
    t39 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t39 & t35);
    goto LAB8;

LAB10:    t23 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB12;

LAB16:    t10 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB17;

LAB19:    *((unsigned int *)t42) = 1;
    goto LAB21;

LAB20:    t45 = (t42 + 4);
    *((unsigned int *)t42) = 1;
    *((unsigned int *)t45) = 1;
    goto LAB21;

LAB22:    *((unsigned int *)t46) = 1;
    goto LAB25;

LAB24:    t53 = (t46 + 4);
    *((unsigned int *)t46) = 1;
    *((unsigned int *)t53) = 1;
    goto LAB25;

LAB26:    t58 = (t1 + 4984);
    t59 = (t58 + 56U);
    t60 = *((char **)t59);
    memset(t61, 0, 8);
    t62 = (t61 + 4);
    t63 = (t60 + 4);
    t64 = *((unsigned int *)t60);
    t65 = (t64 >> 7);
    t66 = (t65 & 1);
    *((unsigned int *)t61) = t66;
    t67 = *((unsigned int *)t63);
    t68 = (t67 >> 7);
    t69 = (t68 & 1);
    *((unsigned int *)t62) = t69;
    t70 = (t1 + 3384);
    t71 = (t70 + 56U);
    t72 = *((char **)t71);
    memset(t73, 0, 8);
    t74 = (t73 + 4);
    t75 = (t72 + 4);
    t76 = *((unsigned int *)t72);
    t77 = (t76 >> 7);
    t78 = (t77 & 1);
    *((unsigned int *)t73) = t78;
    t79 = *((unsigned int *)t75);
    t80 = (t79 >> 7);
    t81 = (t80 & 1);
    *((unsigned int *)t74) = t81;
    memset(t82, 0, 8);
    t83 = (t61 + 4);
    t84 = (t73 + 4);
    t85 = *((unsigned int *)t61);
    t86 = *((unsigned int *)t73);
    t87 = (t85 ^ t86);
    t88 = *((unsigned int *)t83);
    t89 = *((unsigned int *)t84);
    t90 = (t88 ^ t89);
    t91 = (t87 | t90);
    t92 = *((unsigned int *)t83);
    t93 = *((unsigned int *)t84);
    t94 = (t92 | t93);
    t95 = (~(t94));
    t96 = (t91 & t95);
    if (t96 != 0)
        goto LAB30;

LAB29:    if (t94 != 0)
        goto LAB31;

LAB32:    memset(t98, 0, 8);
    t99 = (t82 + 4);
    t100 = *((unsigned int *)t99);
    t101 = (~(t100));
    t102 = *((unsigned int *)t82);
    t103 = (t102 & t101);
    t104 = (t103 & 1U);
    if (t104 != 0)
        goto LAB33;

LAB34:    if (*((unsigned int *)t99) != 0)
        goto LAB35;

LAB36:    t107 = *((unsigned int *)t46);
    t108 = *((unsigned int *)t98);
    t109 = (t107 & t108);
    *((unsigned int *)t106) = t109;
    t110 = (t46 + 4);
    t111 = (t98 + 4);
    t112 = (t106 + 4);
    t113 = *((unsigned int *)t110);
    t114 = *((unsigned int *)t111);
    t115 = (t113 | t114);
    *((unsigned int *)t112) = t115;
    t116 = *((unsigned int *)t112);
    t117 = (t116 != 0);
    if (t117 == 1)
        goto LAB37;

LAB38:
LAB39:    goto LAB28;

LAB30:    *((unsigned int *)t82) = 1;
    goto LAB32;

LAB31:    t97 = (t82 + 4);
    *((unsigned int *)t82) = 1;
    *((unsigned int *)t97) = 1;
    goto LAB32;

LAB33:    *((unsigned int *)t98) = 1;
    goto LAB36;

LAB35:    t105 = (t98 + 4);
    *((unsigned int *)t98) = 1;
    *((unsigned int *)t105) = 1;
    goto LAB36;

LAB37:    t118 = *((unsigned int *)t106);
    t119 = *((unsigned int *)t112);
    *((unsigned int *)t106) = (t118 | t119);
    t120 = (t46 + 4);
    t121 = (t98 + 4);
    t122 = *((unsigned int *)t46);
    t123 = (~(t122));
    t124 = *((unsigned int *)t120);
    t125 = (~(t124));
    t126 = *((unsigned int *)t98);
    t127 = (~(t126));
    t128 = *((unsigned int *)t121);
    t129 = (~(t128));
    t32 = (t123 & t125);
    t33 = (t127 & t129);
    t130 = (~(t32));
    t131 = (~(t33));
    t132 = *((unsigned int *)t112);
    *((unsigned int *)t112) = (t132 & t130);
    t133 = *((unsigned int *)t112);
    *((unsigned int *)t112) = (t133 & t131);
    t134 = *((unsigned int *)t106);
    *((unsigned int *)t106) = (t134 & t130);
    t135 = *((unsigned int *)t106);
    *((unsigned int *)t106) = (t135 & t131);
    goto LAB39;

}

static void Initial_95_0(char *t0)
{
    char t30[8];
    char t66[8];
    char t69[8];
    char t70[8];
    char t71[8];
    char t72[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
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
    int t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    char *t36;
    char *t37;
    char *t38;
    char *t39;
    char *t40;
    char *t41;
    char *t42;
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
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    char *t67;
    char *t68;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    char *t85;
    char *t86;
    unsigned int t87;
    unsigned int t88;
    int t89;
    int t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;

LAB0:    t1 = (t0 + 7504U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(95, ng0);

LAB4:    xsi_set_current_line(96, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 4344);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(97, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 4504);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(98, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 3384);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(98, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 3544);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(98, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(99, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(103, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 3384);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(103, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 3544);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(103, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(103, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB6;
    goto LAB1;

LAB6:    xsi_set_current_line(104, ng0);
    t2 = ((char*)((ng8)));
    t3 = ((char*)((ng4)));
    t4 = ((char*)((ng4)));
    t5 = ((char*)((ng7)));
    t6 = ((char*)((ng7)));
    t7 = ((char*)((ng9)));
    t8 = (t0 + 7312);
    t9 = (t0 + 848);
    t10 = xsi_create_subprogram_invocation(t8, 0, t0, t9, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t9, t10);
    t11 = (t0 + 5784);
    xsi_vlogvar_assign_value(t11, t2, 0, 0, 8);
    t12 = (t0 + 5944);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 1);
    t13 = (t0 + 6104);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 1);
    t14 = (t0 + 6264);
    xsi_vlogvar_assign_value(t14, t5, 0, 0, 1);
    t15 = (t0 + 6424);
    xsi_vlogvar_assign_value(t15, t6, 0, 0, 1);
    t16 = (t0 + 6584);
    xsi_vlogvar_assign_value(t16, t7, 0, 0, 256);

LAB9:    t17 = (t0 + 7408);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = ((int  (*)(char *, char *))t24)(t0, t18);

LAB11:    if (t25 != 0)
        goto LAB12;

LAB7:    t18 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t18);

LAB8:    t26 = (t0 + 7408);
    t27 = *((char **)t26);
    t26 = (t0 + 848);
    t28 = (t0 + 7312);
    t29 = 0;
    xsi_delete_subprogram_invocation(t26, t27, t0, t28, t29);
    xsi_set_current_line(106, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3384);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(106, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 3544);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(106, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(106, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB13;
    goto LAB1;

LAB10:;
LAB12:    t17 = (t0 + 7504U);
    *((char **)t17) = &&LAB9;
    goto LAB1;

LAB13:    xsi_set_current_line(107, ng0);
    t2 = ((char*)((ng4)));
    t3 = ((char*)((ng7)));
    t4 = ((char*)((ng7)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng4)));
    t7 = ((char*)((ng10)));
    t8 = (t0 + 7312);
    t9 = (t0 + 848);
    t10 = xsi_create_subprogram_invocation(t8, 0, t0, t9, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t9, t10);
    t11 = (t0 + 5784);
    xsi_vlogvar_assign_value(t11, t2, 0, 0, 8);
    t12 = (t0 + 5944);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 1);
    t13 = (t0 + 6104);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 1);
    t14 = (t0 + 6264);
    xsi_vlogvar_assign_value(t14, t5, 0, 0, 1);
    t15 = (t0 + 6424);
    xsi_vlogvar_assign_value(t15, t6, 0, 0, 1);
    t16 = (t0 + 6584);
    xsi_vlogvar_assign_value(t16, t7, 0, 0, 256);

LAB16:    t17 = (t0 + 7408);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = ((int  (*)(char *, char *))t24)(t0, t18);

LAB18:    if (t25 != 0)
        goto LAB19;

LAB14:    t18 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t18);

LAB15:    t26 = (t0 + 7408);
    t27 = *((char **)t26);
    t26 = (t0 + 848);
    t28 = (t0 + 7312);
    t29 = 0;
    xsi_delete_subprogram_invocation(t26, t27, t0, t28, t29);
    xsi_set_current_line(109, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 3384);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(109, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 3544);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(109, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(109, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB20;
    goto LAB1;

LAB17:;
LAB19:    t17 = (t0 + 7504U);
    *((char **)t17) = &&LAB16;
    goto LAB1;

LAB20:    xsi_set_current_line(110, ng0);
    t2 = ((char*)((ng4)));
    t3 = ((char*)((ng7)));
    t4 = ((char*)((ng7)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng7)));
    t7 = ((char*)((ng11)));
    t8 = (t0 + 7312);
    t9 = (t0 + 848);
    t10 = xsi_create_subprogram_invocation(t8, 0, t0, t9, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t9, t10);
    t11 = (t0 + 5784);
    xsi_vlogvar_assign_value(t11, t2, 0, 0, 8);
    t12 = (t0 + 5944);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 1);
    t13 = (t0 + 6104);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 1);
    t14 = (t0 + 6264);
    xsi_vlogvar_assign_value(t14, t5, 0, 0, 1);
    t15 = (t0 + 6424);
    xsi_vlogvar_assign_value(t15, t6, 0, 0, 1);
    t16 = (t0 + 6584);
    xsi_vlogvar_assign_value(t16, t7, 0, 0, 256);

LAB23:    t17 = (t0 + 7408);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = ((int  (*)(char *, char *))t24)(t0, t18);

LAB25:    if (t25 != 0)
        goto LAB26;

LAB21:    t18 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t18);

LAB22:    t26 = (t0 + 7408);
    t27 = *((char **)t26);
    t26 = (t0 + 848);
    t28 = (t0 + 7312);
    t29 = 0;
    xsi_delete_subprogram_invocation(t26, t27, t0, t28, t29);
    xsi_set_current_line(112, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 3384);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(112, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 3544);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(112, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(112, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB27;
    goto LAB1;

LAB24:;
LAB26:    t17 = (t0 + 7504U);
    *((char **)t17) = &&LAB23;
    goto LAB1;

LAB27:    xsi_set_current_line(113, ng0);
    t2 = ((char*)((ng3)));
    t3 = ((char*)((ng4)));
    t4 = ((char*)((ng4)));
    t5 = ((char*)((ng7)));
    t6 = ((char*)((ng4)));
    t7 = ((char*)((ng12)));
    t8 = (t0 + 7312);
    t9 = (t0 + 848);
    t10 = xsi_create_subprogram_invocation(t8, 0, t0, t9, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t9, t10);
    t11 = (t0 + 5784);
    xsi_vlogvar_assign_value(t11, t2, 0, 0, 8);
    t12 = (t0 + 5944);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 1);
    t13 = (t0 + 6104);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 1);
    t14 = (t0 + 6264);
    xsi_vlogvar_assign_value(t14, t5, 0, 0, 1);
    t15 = (t0 + 6424);
    xsi_vlogvar_assign_value(t15, t6, 0, 0, 1);
    t16 = (t0 + 6584);
    xsi_vlogvar_assign_value(t16, t7, 0, 0, 256);

LAB30:    t17 = (t0 + 7408);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = ((int  (*)(char *, char *))t24)(t0, t18);

LAB32:    if (t25 != 0)
        goto LAB33;

LAB28:    t18 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t18);

LAB29:    t26 = (t0 + 7408);
    t27 = *((char **)t26);
    t26 = (t0 + 848);
    t28 = (t0 + 7312);
    t29 = 0;
    xsi_delete_subprogram_invocation(t26, t27, t0, t28, t29);
    xsi_set_current_line(115, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 3384);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(115, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 3544);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(115, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(115, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB34;
    goto LAB1;

LAB31:;
LAB33:    t17 = (t0 + 7504U);
    *((char **)t17) = &&LAB30;
    goto LAB1;

LAB34:    xsi_set_current_line(116, ng0);
    t2 = ((char*)((ng6)));
    t3 = ((char*)((ng4)));
    t4 = ((char*)((ng7)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng7)));
    t7 = ((char*)((ng13)));
    t8 = (t0 + 7312);
    t9 = (t0 + 848);
    t10 = xsi_create_subprogram_invocation(t8, 0, t0, t9, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t9, t10);
    t11 = (t0 + 5784);
    xsi_vlogvar_assign_value(t11, t2, 0, 0, 8);
    t12 = (t0 + 5944);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 1);
    t13 = (t0 + 6104);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 1);
    t14 = (t0 + 6264);
    xsi_vlogvar_assign_value(t14, t5, 0, 0, 1);
    t15 = (t0 + 6424);
    xsi_vlogvar_assign_value(t15, t6, 0, 0, 1);
    t16 = (t0 + 6584);
    xsi_vlogvar_assign_value(t16, t7, 0, 0, 256);

LAB37:    t17 = (t0 + 7408);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = ((int  (*)(char *, char *))t24)(t0, t18);

LAB39:    if (t25 != 0)
        goto LAB40;

LAB35:    t18 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t18);

LAB36:    t26 = (t0 + 7408);
    t27 = *((char **)t26);
    t26 = (t0 + 848);
    t28 = (t0 + 7312);
    t29 = 0;
    xsi_delete_subprogram_invocation(t26, t27, t0, t28, t29);
    xsi_set_current_line(118, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 3384);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(118, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 3544);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(118, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(118, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB41;
    goto LAB1;

LAB38:;
LAB40:    t17 = (t0 + 7504U);
    *((char **)t17) = &&LAB37;
    goto LAB1;

LAB41:    xsi_set_current_line(119, ng0);
    t2 = ((char*)((ng4)));
    t3 = ((char*)((ng7)));
    t4 = ((char*)((ng7)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng4)));
    t7 = ((char*)((ng15)));
    t8 = (t0 + 7312);
    t9 = (t0 + 848);
    t10 = xsi_create_subprogram_invocation(t8, 0, t0, t9, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t9, t10);
    t11 = (t0 + 5784);
    xsi_vlogvar_assign_value(t11, t2, 0, 0, 8);
    t12 = (t0 + 5944);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 1);
    t13 = (t0 + 6104);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 1);
    t14 = (t0 + 6264);
    xsi_vlogvar_assign_value(t14, t5, 0, 0, 1);
    t15 = (t0 + 6424);
    xsi_vlogvar_assign_value(t15, t6, 0, 0, 1);
    t16 = (t0 + 6584);
    xsi_vlogvar_assign_value(t16, t7, 0, 0, 256);

LAB44:    t17 = (t0 + 7408);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = ((int  (*)(char *, char *))t24)(t0, t18);

LAB46:    if (t25 != 0)
        goto LAB47;

LAB42:    t18 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t18);

LAB43:    t26 = (t0 + 7408);
    t27 = *((char **)t26);
    t26 = (t0 + 848);
    t28 = (t0 + 7312);
    t29 = 0;
    xsi_delete_subprogram_invocation(t26, t27, t0, t28, t29);
    xsi_set_current_line(121, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 3384);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(121, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3544);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(121, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(121, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB48;
    goto LAB1;

LAB45:;
LAB47:    t17 = (t0 + 7504U);
    *((char **)t17) = &&LAB44;
    goto LAB1;

LAB48:    xsi_set_current_line(122, ng0);
    t2 = ((char*)((ng8)));
    t3 = ((char*)((ng4)));
    t4 = ((char*)((ng4)));
    t5 = ((char*)((ng7)));
    t6 = ((char*)((ng7)));
    t7 = ((char*)((ng16)));
    t8 = (t0 + 7312);
    t9 = (t0 + 848);
    t10 = xsi_create_subprogram_invocation(t8, 0, t0, t9, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t9, t10);
    t11 = (t0 + 5784);
    xsi_vlogvar_assign_value(t11, t2, 0, 0, 8);
    t12 = (t0 + 5944);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 1);
    t13 = (t0 + 6104);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 1);
    t14 = (t0 + 6264);
    xsi_vlogvar_assign_value(t14, t5, 0, 0, 1);
    t15 = (t0 + 6424);
    xsi_vlogvar_assign_value(t15, t6, 0, 0, 1);
    t16 = (t0 + 6584);
    xsi_vlogvar_assign_value(t16, t7, 0, 0, 256);

LAB51:    t17 = (t0 + 7408);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = ((int  (*)(char *, char *))t24)(t0, t18);

LAB53:    if (t25 != 0)
        goto LAB54;

LAB49:    t18 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t18);

LAB50:    t26 = (t0 + 7408);
    t27 = *((char **)t26);
    t26 = (t0 + 848);
    t28 = (t0 + 7312);
    t29 = 0;
    xsi_delete_subprogram_invocation(t26, t27, t0, t28, t29);
    xsi_set_current_line(124, ng0);
    t2 = ((char*)((ng17)));
    t3 = (t0 + 3384);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(124, ng0);
    t2 = ((char*)((ng18)));
    t3 = (t0 + 3544);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(124, ng0);
    t2 = ((char*)((ng19)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(124, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB55;
    goto LAB1;

LAB52:;
LAB54:    t17 = (t0 + 7504U);
    *((char **)t17) = &&LAB51;
    goto LAB1;

LAB55:    xsi_set_current_line(125, ng0);
    t2 = ((char*)((ng14)));
    t3 = ((char*)((ng4)));
    t4 = ((char*)((ng4)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng4)));
    t7 = ((char*)((ng20)));
    t8 = (t0 + 7312);
    t9 = (t0 + 848);
    t10 = xsi_create_subprogram_invocation(t8, 0, t0, t9, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t9, t10);
    t11 = (t0 + 5784);
    xsi_vlogvar_assign_value(t11, t2, 0, 0, 8);
    t12 = (t0 + 5944);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 1);
    t13 = (t0 + 6104);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 1);
    t14 = (t0 + 6264);
    xsi_vlogvar_assign_value(t14, t5, 0, 0, 1);
    t15 = (t0 + 6424);
    xsi_vlogvar_assign_value(t15, t6, 0, 0, 1);
    t16 = (t0 + 6584);
    xsi_vlogvar_assign_value(t16, t7, 0, 0, 256);

LAB58:    t17 = (t0 + 7408);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = ((int  (*)(char *, char *))t24)(t0, t18);

LAB60:    if (t25 != 0)
        goto LAB61;

LAB56:    t18 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t18);

LAB57:    t26 = (t0 + 7408);
    t27 = *((char **)t26);
    t26 = (t0 + 848);
    t28 = (t0 + 7312);
    t29 = 0;
    xsi_delete_subprogram_invocation(t26, t27, t0, t28, t29);
    xsi_set_current_line(126, ng0);
    t2 = ((char*)((ng21)));
    t3 = (t0 + 3384);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(126, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 3544);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(126, ng0);
    t2 = ((char*)((ng22)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(126, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB62;
    goto LAB1;

LAB59:;
LAB61:    t17 = (t0 + 7504U);
    *((char **)t17) = &&LAB58;
    goto LAB1;

LAB62:    xsi_set_current_line(127, ng0);
    t2 = ((char*)((ng17)));
    t3 = ((char*)((ng4)));
    t4 = ((char*)((ng4)));
    t5 = ((char*)((ng7)));
    t6 = ((char*)((ng4)));
    t7 = ((char*)((ng23)));
    t8 = (t0 + 7312);
    t9 = (t0 + 848);
    t10 = xsi_create_subprogram_invocation(t8, 0, t0, t9, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t9, t10);
    t11 = (t0 + 5784);
    xsi_vlogvar_assign_value(t11, t2, 0, 0, 8);
    t12 = (t0 + 5944);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 1);
    t13 = (t0 + 6104);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 1);
    t14 = (t0 + 6264);
    xsi_vlogvar_assign_value(t14, t5, 0, 0, 1);
    t15 = (t0 + 6424);
    xsi_vlogvar_assign_value(t15, t6, 0, 0, 1);
    t16 = (t0 + 6584);
    xsi_vlogvar_assign_value(t16, t7, 0, 0, 256);

LAB65:    t17 = (t0 + 7408);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = ((int  (*)(char *, char *))t24)(t0, t18);

LAB67:    if (t25 != 0)
        goto LAB68;

LAB63:    t18 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t18);

LAB64:    t26 = (t0 + 7408);
    t27 = *((char **)t26);
    t26 = (t0 + 848);
    t28 = (t0 + 7312);
    t29 = 0;
    xsi_delete_subprogram_invocation(t26, t27, t0, t28, t29);
    xsi_set_current_line(128, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3384);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(128, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3544);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(128, ng0);
    t2 = ((char*)((ng24)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(128, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB69;
    goto LAB1;

LAB66:;
LAB68:    t17 = (t0 + 7504U);
    *((char **)t17) = &&LAB65;
    goto LAB1;

LAB69:    xsi_set_current_line(129, ng0);
    t2 = ((char*)((ng4)));
    t3 = ((char*)((ng7)));
    t4 = ((char*)((ng4)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng4)));
    t7 = ((char*)((ng25)));
    t8 = (t0 + 7312);
    t9 = (t0 + 848);
    t10 = xsi_create_subprogram_invocation(t8, 0, t0, t9, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t9, t10);
    t11 = (t0 + 5784);
    xsi_vlogvar_assign_value(t11, t2, 0, 0, 8);
    t12 = (t0 + 5944);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 1);
    t13 = (t0 + 6104);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 1);
    t14 = (t0 + 6264);
    xsi_vlogvar_assign_value(t14, t5, 0, 0, 1);
    t15 = (t0 + 6424);
    xsi_vlogvar_assign_value(t15, t6, 0, 0, 1);
    t16 = (t0 + 6584);
    xsi_vlogvar_assign_value(t16, t7, 0, 0, 256);

LAB72:    t17 = (t0 + 7408);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = ((int  (*)(char *, char *))t24)(t0, t18);

LAB74:    if (t25 != 0)
        goto LAB75;

LAB70:    t18 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t18);

LAB71:    t26 = (t0 + 7408);
    t27 = *((char **)t26);
    t26 = (t0 + 848);
    t28 = (t0 + 7312);
    t29 = 0;
    xsi_delete_subprogram_invocation(t26, t27, t0, t28, t29);
    xsi_set_current_line(131, ng0);
    t2 = ((char*)((ng26)));
    t3 = (t0 + 3384);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(131, ng0);
    t2 = ((char*)((ng27)));
    t3 = (t0 + 3544);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(131, ng0);
    t2 = ((char*)((ng28)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(131, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB76;
    goto LAB1;

LAB73:;
LAB75:    t17 = (t0 + 7504U);
    *((char **)t17) = &&LAB72;
    goto LAB1;

LAB76:    xsi_set_current_line(132, ng0);
    t2 = ((char*)((ng27)));
    t3 = ((char*)((ng4)));
    t4 = ((char*)((ng4)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng4)));
    t7 = ((char*)((ng29)));
    t8 = (t0 + 7312);
    t9 = (t0 + 848);
    t10 = xsi_create_subprogram_invocation(t8, 0, t0, t9, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t9, t10);
    t11 = (t0 + 5784);
    xsi_vlogvar_assign_value(t11, t2, 0, 0, 8);
    t12 = (t0 + 5944);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 1);
    t13 = (t0 + 6104);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 1);
    t14 = (t0 + 6264);
    xsi_vlogvar_assign_value(t14, t5, 0, 0, 1);
    t15 = (t0 + 6424);
    xsi_vlogvar_assign_value(t15, t6, 0, 0, 1);
    t16 = (t0 + 6584);
    xsi_vlogvar_assign_value(t16, t7, 0, 0, 256);

LAB79:    t17 = (t0 + 7408);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = ((int  (*)(char *, char *))t24)(t0, t18);

LAB81:    if (t25 != 0)
        goto LAB82;

LAB77:    t18 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t18);

LAB78:    t26 = (t0 + 7408);
    t27 = *((char **)t26);
    t26 = (t0 + 848);
    t28 = (t0 + 7312);
    t29 = 0;
    xsi_delete_subprogram_invocation(t26, t27, t0, t28, t29);
    xsi_set_current_line(133, ng0);
    t2 = ((char*)((ng26)));
    t3 = (t0 + 3384);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(133, ng0);
    t2 = ((char*)((ng27)));
    t3 = (t0 + 3544);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(133, ng0);
    t2 = ((char*)((ng30)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(133, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB83;
    goto LAB1;

LAB80:;
LAB82:    t17 = (t0 + 7504U);
    *((char **)t17) = &&LAB79;
    goto LAB1;

LAB83:    xsi_set_current_line(134, ng0);
    t2 = ((char*)((ng31)));
    t3 = ((char*)((ng4)));
    t4 = ((char*)((ng4)));
    t5 = ((char*)((ng7)));
    t6 = ((char*)((ng4)));
    t7 = ((char*)((ng32)));
    t8 = (t0 + 7312);
    t9 = (t0 + 848);
    t10 = xsi_create_subprogram_invocation(t8, 0, t0, t9, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t9, t10);
    t11 = (t0 + 5784);
    xsi_vlogvar_assign_value(t11, t2, 0, 0, 8);
    t12 = (t0 + 5944);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 1);
    t13 = (t0 + 6104);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 1);
    t14 = (t0 + 6264);
    xsi_vlogvar_assign_value(t14, t5, 0, 0, 1);
    t15 = (t0 + 6424);
    xsi_vlogvar_assign_value(t15, t6, 0, 0, 1);
    t16 = (t0 + 6584);
    xsi_vlogvar_assign_value(t16, t7, 0, 0, 256);

LAB86:    t17 = (t0 + 7408);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = ((int  (*)(char *, char *))t24)(t0, t18);

LAB88:    if (t25 != 0)
        goto LAB89;

LAB84:    t18 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t18);

LAB85:    t26 = (t0 + 7408);
    t27 = *((char **)t26);
    t26 = (t0 + 848);
    t28 = (t0 + 7312);
    t29 = 0;
    xsi_delete_subprogram_invocation(t26, t27, t0, t28, t29);
    xsi_set_current_line(136, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 3384);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(136, ng0);
    t2 = ((char*)((ng33)));
    t3 = (t0 + 3544);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(136, ng0);
    t2 = ((char*)((ng34)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(136, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB90;
    goto LAB1;

LAB87:;
LAB89:    t17 = (t0 + 7504U);
    *((char **)t17) = &&LAB86;
    goto LAB1;

LAB90:    xsi_set_current_line(137, ng0);
    t2 = ((char*)((ng35)));
    t3 = ((char*)((ng4)));
    t4 = ((char*)((ng7)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng4)));
    t7 = ((char*)((ng36)));
    t8 = (t0 + 7312);
    t9 = (t0 + 848);
    t10 = xsi_create_subprogram_invocation(t8, 0, t0, t9, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t9, t10);
    t11 = (t0 + 5784);
    xsi_vlogvar_assign_value(t11, t2, 0, 0, 8);
    t12 = (t0 + 5944);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 1);
    t13 = (t0 + 6104);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 1);
    t14 = (t0 + 6264);
    xsi_vlogvar_assign_value(t14, t5, 0, 0, 1);
    t15 = (t0 + 6424);
    xsi_vlogvar_assign_value(t15, t6, 0, 0, 1);
    t16 = (t0 + 6584);
    xsi_vlogvar_assign_value(t16, t7, 0, 0, 256);

LAB93:    t17 = (t0 + 7408);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = ((int  (*)(char *, char *))t24)(t0, t18);

LAB95:    if (t25 != 0)
        goto LAB96;

LAB91:    t18 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t18);

LAB92:    t26 = (t0 + 7408);
    t27 = *((char **)t26);
    t26 = (t0 + 848);
    t28 = (t0 + 7312);
    t29 = 0;
    xsi_delete_subprogram_invocation(t26, t27, t0, t28, t29);
    xsi_set_current_line(139, ng0);
    t2 = ((char*)((ng37)));
    t3 = (t0 + 3384);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(139, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 3544);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(139, ng0);
    t2 = ((char*)((ng38)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(139, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB97;
    goto LAB1;

LAB94:;
LAB96:    t17 = (t0 + 7504U);
    *((char **)t17) = &&LAB93;
    goto LAB1;

LAB97:    xsi_set_current_line(140, ng0);
    t2 = ((char*)((ng35)));
    t3 = ((char*)((ng4)));
    t4 = ((char*)((ng7)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng4)));
    t7 = ((char*)((ng39)));
    t8 = (t0 + 7312);
    t9 = (t0 + 848);
    t10 = xsi_create_subprogram_invocation(t8, 0, t0, t9, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t9, t10);
    t11 = (t0 + 5784);
    xsi_vlogvar_assign_value(t11, t2, 0, 0, 8);
    t12 = (t0 + 5944);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 1);
    t13 = (t0 + 6104);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 1);
    t14 = (t0 + 6264);
    xsi_vlogvar_assign_value(t14, t5, 0, 0, 1);
    t15 = (t0 + 6424);
    xsi_vlogvar_assign_value(t15, t6, 0, 0, 1);
    t16 = (t0 + 6584);
    xsi_vlogvar_assign_value(t16, t7, 0, 0, 256);

LAB100:    t17 = (t0 + 7408);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = ((int  (*)(char *, char *))t24)(t0, t18);

LAB102:    if (t25 != 0)
        goto LAB103;

LAB98:    t18 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t18);

LAB99:    t26 = (t0 + 7408);
    t27 = *((char **)t26);
    t26 = (t0 + 848);
    t28 = (t0 + 7312);
    t29 = 0;
    xsi_delete_subprogram_invocation(t26, t27, t0, t28, t29);
    xsi_set_current_line(141, ng0);
    t2 = ((char*)((ng37)));
    t3 = (t0 + 3384);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(141, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 3544);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(141, ng0);
    t2 = ((char*)((ng38)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(141, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB104;
    goto LAB1;

LAB101:;
LAB103:    t17 = (t0 + 7504U);
    *((char **)t17) = &&LAB100;
    goto LAB1;

LAB104:    xsi_set_current_line(142, ng0);
    t2 = ((char*)((ng37)));
    t3 = ((char*)((ng4)));
    t4 = ((char*)((ng4)));
    t5 = ((char*)((ng7)));
    t6 = ((char*)((ng4)));
    t7 = ((char*)((ng40)));
    t8 = (t0 + 7312);
    t9 = (t0 + 848);
    t10 = xsi_create_subprogram_invocation(t8, 0, t0, t9, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t9, t10);
    t11 = (t0 + 5784);
    xsi_vlogvar_assign_value(t11, t2, 0, 0, 8);
    t12 = (t0 + 5944);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 1);
    t13 = (t0 + 6104);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 1);
    t14 = (t0 + 6264);
    xsi_vlogvar_assign_value(t14, t5, 0, 0, 1);
    t15 = (t0 + 6424);
    xsi_vlogvar_assign_value(t15, t6, 0, 0, 1);
    t16 = (t0 + 6584);
    xsi_vlogvar_assign_value(t16, t7, 0, 0, 256);

LAB107:    t17 = (t0 + 7408);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = ((int  (*)(char *, char *))t24)(t0, t18);

LAB109:    if (t25 != 0)
        goto LAB110;

LAB105:    t18 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t18);

LAB106:    t26 = (t0 + 7408);
    t27 = *((char **)t26);
    t26 = (t0 + 848);
    t28 = (t0 + 7312);
    t29 = 0;
    xsi_delete_subprogram_invocation(t26, t27, t0, t28, t29);
    xsi_set_current_line(143, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3384);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(143, ng0);
    t2 = ((char*)((ng41)));
    t3 = (t0 + 3544);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(143, ng0);
    t2 = ((char*)((ng38)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(143, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB111;
    goto LAB1;

LAB108:;
LAB110:    t17 = (t0 + 7504U);
    *((char **)t17) = &&LAB107;
    goto LAB1;

LAB111:    xsi_set_current_line(144, ng0);
    t2 = ((char*)((ng8)));
    t3 = ((char*)((ng4)));
    t4 = ((char*)((ng7)));
    t5 = ((char*)((ng7)));
    t6 = ((char*)((ng4)));
    t7 = ((char*)((ng42)));
    t8 = (t0 + 7312);
    t9 = (t0 + 848);
    t10 = xsi_create_subprogram_invocation(t8, 0, t0, t9, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t9, t10);
    t11 = (t0 + 5784);
    xsi_vlogvar_assign_value(t11, t2, 0, 0, 8);
    t12 = (t0 + 5944);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 1);
    t13 = (t0 + 6104);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 1);
    t14 = (t0 + 6264);
    xsi_vlogvar_assign_value(t14, t5, 0, 0, 1);
    t15 = (t0 + 6424);
    xsi_vlogvar_assign_value(t15, t6, 0, 0, 1);
    t16 = (t0 + 6584);
    xsi_vlogvar_assign_value(t16, t7, 0, 0, 256);

LAB114:    t17 = (t0 + 7408);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = ((int  (*)(char *, char *))t24)(t0, t18);

LAB116:    if (t25 != 0)
        goto LAB117;

LAB112:    t18 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t18);

LAB113:    t26 = (t0 + 7408);
    t27 = *((char **)t26);
    t26 = (t0 + 848);
    t28 = (t0 + 7312);
    t29 = 0;
    xsi_delete_subprogram_invocation(t26, t27, t0, t28, t29);
    xsi_set_current_line(145, ng0);
    t2 = ((char*)((ng33)));
    t3 = (t0 + 3384);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(145, ng0);
    t2 = ((char*)((ng35)));
    t3 = (t0 + 3544);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(145, ng0);
    t2 = ((char*)((ng43)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(145, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB118;
    goto LAB1;

LAB115:;
LAB117:    t17 = (t0 + 7504U);
    *((char **)t17) = &&LAB114;
    goto LAB1;

LAB118:    xsi_set_current_line(146, ng0);
    t2 = ((char*)((ng4)));
    t3 = ((char*)((ng7)));
    t4 = ((char*)((ng7)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng4)));
    t7 = ((char*)((ng44)));
    t8 = (t0 + 7312);
    t9 = (t0 + 848);
    t10 = xsi_create_subprogram_invocation(t8, 0, t0, t9, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t9, t10);
    t11 = (t0 + 5784);
    xsi_vlogvar_assign_value(t11, t2, 0, 0, 8);
    t12 = (t0 + 5944);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 1);
    t13 = (t0 + 6104);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 1);
    t14 = (t0 + 6264);
    xsi_vlogvar_assign_value(t14, t5, 0, 0, 1);
    t15 = (t0 + 6424);
    xsi_vlogvar_assign_value(t15, t6, 0, 0, 1);
    t16 = (t0 + 6584);
    xsi_vlogvar_assign_value(t16, t7, 0, 0, 256);

LAB121:    t17 = (t0 + 7408);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = ((int  (*)(char *, char *))t24)(t0, t18);

LAB123:    if (t25 != 0)
        goto LAB124;

LAB119:    t18 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t18);

LAB120:    t26 = (t0 + 7408);
    t27 = *((char **)t26);
    t26 = (t0 + 848);
    t28 = (t0 + 7312);
    t29 = 0;
    xsi_delete_subprogram_invocation(t26, t27, t0, t28, t29);
    xsi_set_current_line(147, ng0);
    t2 = ((char*)((ng37)));
    t3 = (t0 + 3384);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(147, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 3544);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(147, ng0);
    t2 = ((char*)((ng43)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(147, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB125;
    goto LAB1;

LAB122:;
LAB124:    t17 = (t0 + 7504U);
    *((char **)t17) = &&LAB121;
    goto LAB1;

LAB125:    xsi_set_current_line(148, ng0);
    t2 = ((char*)((ng45)));
    t3 = ((char*)((ng4)));
    t4 = ((char*)((ng7)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng4)));
    t7 = ((char*)((ng46)));
    t8 = (t0 + 7312);
    t9 = (t0 + 848);
    t10 = xsi_create_subprogram_invocation(t8, 0, t0, t9, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t9, t10);
    t11 = (t0 + 5784);
    xsi_vlogvar_assign_value(t11, t2, 0, 0, 8);
    t12 = (t0 + 5944);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 1);
    t13 = (t0 + 6104);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 1);
    t14 = (t0 + 6264);
    xsi_vlogvar_assign_value(t14, t5, 0, 0, 1);
    t15 = (t0 + 6424);
    xsi_vlogvar_assign_value(t15, t6, 0, 0, 1);
    t16 = (t0 + 6584);
    xsi_vlogvar_assign_value(t16, t7, 0, 0, 256);

LAB128:    t17 = (t0 + 7408);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = ((int  (*)(char *, char *))t24)(t0, t18);

LAB130:    if (t25 != 0)
        goto LAB131;

LAB126:    t18 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t18);

LAB127:    t26 = (t0 + 7408);
    t27 = *((char **)t26);
    t26 = (t0 + 848);
    t28 = (t0 + 7312);
    t29 = 0;
    xsi_delete_subprogram_invocation(t26, t27, t0, t28, t29);
    xsi_set_current_line(149, ng0);
    t2 = ((char*)((ng37)));
    t3 = (t0 + 3384);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(149, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 3544);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(149, ng0);
    t2 = ((char*)((ng47)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(149, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB132;
    goto LAB1;

LAB129:;
LAB131:    t17 = (t0 + 7504U);
    *((char **)t17) = &&LAB128;
    goto LAB1;

LAB132:    xsi_set_current_line(150, ng0);
    t2 = ((char*)((ng33)));
    t3 = ((char*)((ng4)));
    t4 = ((char*)((ng4)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng4)));
    t7 = ((char*)((ng48)));
    t8 = (t0 + 7312);
    t9 = (t0 + 848);
    t10 = xsi_create_subprogram_invocation(t8, 0, t0, t9, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t9, t10);
    t11 = (t0 + 5784);
    xsi_vlogvar_assign_value(t11, t2, 0, 0, 8);
    t12 = (t0 + 5944);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 1);
    t13 = (t0 + 6104);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 1);
    t14 = (t0 + 6264);
    xsi_vlogvar_assign_value(t14, t5, 0, 0, 1);
    t15 = (t0 + 6424);
    xsi_vlogvar_assign_value(t15, t6, 0, 0, 1);
    t16 = (t0 + 6584);
    xsi_vlogvar_assign_value(t16, t7, 0, 0, 256);

LAB135:    t17 = (t0 + 7408);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = ((int  (*)(char *, char *))t24)(t0, t18);

LAB137:    if (t25 != 0)
        goto LAB138;

LAB133:    t18 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t18);

LAB134:    t26 = (t0 + 7408);
    t27 = *((char **)t26);
    t26 = (t0 + 848);
    t28 = (t0 + 7312);
    t29 = 0;
    xsi_delete_subprogram_invocation(t26, t27, t0, t28, t29);
    xsi_set_current_line(151, ng0);
    t2 = ((char*)((ng37)));
    t3 = (t0 + 3384);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(151, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 3544);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(151, ng0);
    t2 = ((char*)((ng49)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(151, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB139;
    goto LAB1;

LAB136:;
LAB138:    t17 = (t0 + 7504U);
    *((char **)t17) = &&LAB135;
    goto LAB1;

LAB139:    xsi_set_current_line(152, ng0);
    t2 = ((char*)((ng50)));
    t3 = ((char*)((ng4)));
    t4 = ((char*)((ng4)));
    t5 = ((char*)((ng7)));
    t6 = ((char*)((ng4)));
    t7 = ((char*)((ng51)));
    t8 = (t0 + 7312);
    t9 = (t0 + 848);
    t10 = xsi_create_subprogram_invocation(t8, 0, t0, t9, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t9, t10);
    t11 = (t0 + 5784);
    xsi_vlogvar_assign_value(t11, t2, 0, 0, 8);
    t12 = (t0 + 5944);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 1);
    t13 = (t0 + 6104);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 1);
    t14 = (t0 + 6264);
    xsi_vlogvar_assign_value(t14, t5, 0, 0, 1);
    t15 = (t0 + 6424);
    xsi_vlogvar_assign_value(t15, t6, 0, 0, 1);
    t16 = (t0 + 6584);
    xsi_vlogvar_assign_value(t16, t7, 0, 0, 256);

LAB142:    t17 = (t0 + 7408);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = ((int  (*)(char *, char *))t24)(t0, t18);

LAB144:    if (t25 != 0)
        goto LAB145;

LAB140:    t18 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t18);

LAB141:    t26 = (t0 + 7408);
    t27 = *((char **)t26);
    t26 = (t0 + 848);
    t28 = (t0 + 7312);
    t29 = 0;
    xsi_delete_subprogram_invocation(t26, t27, t0, t28, t29);
    xsi_set_current_line(153, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3384);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(153, ng0);
    t2 = ((char*)((ng33)));
    t3 = (t0 + 3544);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(153, ng0);
    t2 = ((char*)((ng47)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(153, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB146;
    goto LAB1;

LAB143:;
LAB145:    t17 = (t0 + 7504U);
    *((char **)t17) = &&LAB142;
    goto LAB1;

LAB146:    xsi_set_current_line(154, ng0);
    t2 = ((char*)((ng3)));
    t3 = ((char*)((ng4)));
    t4 = ((char*)((ng4)));
    t5 = ((char*)((ng7)));
    t6 = ((char*)((ng4)));
    t7 = ((char*)((ng52)));
    t8 = (t0 + 7312);
    t9 = (t0 + 848);
    t10 = xsi_create_subprogram_invocation(t8, 0, t0, t9, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t9, t10);
    t11 = (t0 + 5784);
    xsi_vlogvar_assign_value(t11, t2, 0, 0, 8);
    t12 = (t0 + 5944);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 1);
    t13 = (t0 + 6104);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 1);
    t14 = (t0 + 6264);
    xsi_vlogvar_assign_value(t14, t5, 0, 0, 1);
    t15 = (t0 + 6424);
    xsi_vlogvar_assign_value(t15, t6, 0, 0, 1);
    t16 = (t0 + 6584);
    xsi_vlogvar_assign_value(t16, t7, 0, 0, 256);

LAB149:    t17 = (t0 + 7408);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = ((int  (*)(char *, char *))t24)(t0, t18);

LAB151:    if (t25 != 0)
        goto LAB152;

LAB147:    t18 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t18);

LAB148:    t26 = (t0 + 7408);
    t27 = *((char **)t26);
    t26 = (t0 + 848);
    t28 = (t0 + 7312);
    t29 = 0;
    xsi_delete_subprogram_invocation(t26, t27, t0, t28, t29);
    xsi_set_current_line(157, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(158, ng0);
    xsi_set_current_line(158, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 3864);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB153:    t2 = (t0 + 3864);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng53)));
    memset(t30, 0, 8);
    xsi_vlog_signed_less(t30, 32, t4, 32, t5, 32);
    t6 = (t30 + 4);
    t31 = *((unsigned int *)t6);
    t32 = (~(t31));
    t33 = *((unsigned int *)t30);
    t34 = (t33 & t32);
    t35 = (t34 != 0);
    if (t35 > 0)
        goto LAB154;

LAB155:    xsi_set_current_line(165, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(166, ng0);
    xsi_set_current_line(166, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 3864);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB174:    t2 = (t0 + 3864);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng53)));
    memset(t30, 0, 8);
    xsi_vlog_signed_less(t30, 32, t4, 32, t5, 32);
    t6 = (t30 + 4);
    t31 = *((unsigned int *)t6);
    t32 = (~(t31));
    t33 = *((unsigned int *)t30);
    t34 = (t33 & t32);
    t35 = (t34 != 0);
    if (t35 > 0)
        goto LAB175;

LAB176:    xsi_set_current_line(173, ng0);
    t2 = ((char*)((ng34)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(174, ng0);
    xsi_set_current_line(174, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 3864);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB195:    t2 = (t0 + 3864);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng53)));
    memset(t30, 0, 8);
    xsi_vlog_signed_less(t30, 32, t4, 32, t5, 32);
    t6 = (t30 + 4);
    t31 = *((unsigned int *)t6);
    t32 = (~(t31));
    t33 = *((unsigned int *)t30);
    t34 = (t33 & t32);
    t35 = (t34 != 0);
    if (t35 > 0)
        goto LAB196;

LAB197:    xsi_set_current_line(183, ng0);
    xsi_set_current_line(183, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 3864);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB216:    t2 = (t0 + 3864);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng53)));
    memset(t30, 0, 8);
    xsi_vlog_signed_less(t30, 32, t4, 32, t5, 32);
    t6 = (t30 + 4);
    t31 = *((unsigned int *)t6);
    t32 = (~(t31));
    t33 = *((unsigned int *)t30);
    t34 = (t33 & t32);
    t35 = (t34 != 0);
    if (t35 > 0)
        goto LAB217;

LAB218:    xsi_set_current_line(205, ng0);
    xsi_set_current_line(205, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 3864);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB295:    t2 = (t0 + 3864);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng53)));
    memset(t30, 0, 8);
    xsi_vlog_signed_less(t30, 32, t4, 32, t5, 32);
    t6 = (t30 + 4);
    t31 = *((unsigned int *)t6);
    t32 = (~(t31));
    t33 = *((unsigned int *)t30);
    t34 = (t33 & t32);
    t35 = (t34 != 0);
    if (t35 > 0)
        goto LAB296;

LAB297:    xsi_set_current_line(247, ng0);
    xsi_set_current_line(247, ng0);
    t2 = ((char*)((ng68)));
    t3 = (t0 + 4184);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB444:    t2 = (t0 + 4184);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng69)));
    memset(t30, 0, 8);
    xsi_vlog_signed_less(t30, 32, t4, 32, t5, 32);
    t6 = (t30 + 4);
    t31 = *((unsigned int *)t6);
    t32 = (~(t31));
    t33 = *((unsigned int *)t30);
    t34 = (t33 & t32);
    t35 = (t34 != 0);
    if (t35 > 0)
        goto LAB445;

LAB446:    xsi_set_current_line(253, ng0);
    t2 = (t0 + 4504);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng5)));
    memset(t30, 0, 8);
    xsi_vlog_signed_equal(t30, 32, t4, 32, t5, 32);
    t6 = (t30 + 4);
    t31 = *((unsigned int *)t6);
    t32 = (~(t31));
    t33 = *((unsigned int *)t30);
    t34 = (t33 & t32);
    t35 = (t34 != 0);
    if (t35 > 0)
        goto LAB455;

LAB456:    xsi_set_current_line(256, ng0);
    t2 = (t0 + 4344);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4504);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    xsi_vlogfile_write(1, 0, 0, ng73, 3, t0, (char)119, t4, 32, (char)119, t7, 32);

LAB457:    xsi_set_current_line(257, ng0);
    xsi_vlog_finish(1);
    goto LAB1;

LAB150:;
LAB152:    t17 = (t0 + 7504U);
    *((char **)t17) = &&LAB149;
    goto LAB1;

LAB154:    xsi_set_current_line(158, ng0);

LAB156:    xsi_set_current_line(159, ng0);
    xsi_set_current_line(159, ng0);
    t7 = ((char*)((ng5)));
    t8 = (t0 + 4024);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 32);

LAB157:    t2 = (t0 + 4024);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng53)));
    memset(t30, 0, 8);
    xsi_vlog_signed_less(t30, 32, t4, 32, t5, 32);
    t6 = (t30 + 4);
    t31 = *((unsigned int *)t6);
    t32 = (~(t31));
    t33 = *((unsigned int *)t30);
    t34 = (t33 & t32);
    t35 = (t34 != 0);
    if (t35 > 0)
        goto LAB158;

LAB159:    xsi_set_current_line(158, ng0);
    t2 = (t0 + 3864);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t30, 0, 8);
    xsi_vlog_signed_add(t30, 32, t4, 32, t5, 32);
    t6 = (t0 + 3864);
    xsi_vlogvar_assign_value(t6, t30, 0, 0, 32);
    goto LAB153;

LAB158:    xsi_set_current_line(159, ng0);

LAB160:    xsi_set_current_line(160, ng0);
    t7 = (t0 + 3864);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t0 + 3384);
    xsi_vlogvar_assign_value(t10, t9, 0, 0, 8);
    xsi_set_current_line(160, ng0);
    t2 = (t0 + 4024);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3544);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 8);
    xsi_set_current_line(160, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB161;
    goto LAB1;

LAB161:    xsi_set_current_line(161, ng0);
    t2 = (t0 + 7312);
    t3 = (t0 + 1280);
    t4 = xsi_create_subprogram_invocation(t2, 0, t0, t3, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t3, t4);

LAB164:    t5 = (t0 + 7408);
    t6 = *((char **)t5);
    t7 = (t6 + 80U);
    t8 = *((char **)t7);
    t9 = (t8 + 272U);
    t10 = *((char **)t9);
    t11 = (t10 + 0U);
    t12 = *((char **)t11);
    t25 = ((int  (*)(char *, char *))t12)(t0, t6);

LAB166:    if (t25 != 0)
        goto LAB167;

LAB162:    t6 = (t0 + 1280);
    xsi_vlog_subprogram_popinvocation(t6);

LAB163:    t13 = (t0 + 7408);
    t14 = *((char **)t13);
    t13 = (t0 + 1280);
    t15 = (t0 + 7312);
    t16 = 0;
    xsi_delete_subprogram_invocation(t13, t14, t0, t15, t16);
    xsi_set_current_line(162, ng0);
    t2 = (t0 + 4984);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5144);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 5304);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t0 + 5464);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t0 + 5624);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = ((char*)((ng54)));
    t18 = (t0 + 7312);
    t19 = (t0 + 848);
    t20 = xsi_create_subprogram_invocation(t18, 0, t0, t19, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t19, t20);
    t21 = (t0 + 5784);
    xsi_vlogvar_assign_value(t21, t4, 0, 0, 8);
    t22 = (t0 + 5944);
    xsi_vlogvar_assign_value(t22, t7, 0, 0, 1);
    t23 = (t0 + 6104);
    xsi_vlogvar_assign_value(t23, t10, 0, 0, 1);
    t24 = (t0 + 6264);
    xsi_vlogvar_assign_value(t24, t13, 0, 0, 1);
    t26 = (t0 + 6424);
    xsi_vlogvar_assign_value(t26, t16, 0, 0, 1);
    t27 = (t0 + 6584);
    xsi_vlogvar_assign_value(t27, t17, 0, 0, 256);

LAB170:    t28 = (t0 + 7408);
    t29 = *((char **)t28);
    t36 = (t29 + 80U);
    t37 = *((char **)t36);
    t38 = (t37 + 272U);
    t39 = *((char **)t38);
    t40 = (t39 + 0U);
    t41 = *((char **)t40);
    t25 = ((int  (*)(char *, char *))t41)(t0, t29);

LAB172:    if (t25 != 0)
        goto LAB173;

LAB168:    t29 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t29);

LAB169:    t42 = (t0 + 7408);
    t43 = *((char **)t42);
    t42 = (t0 + 848);
    t44 = (t0 + 7312);
    t45 = 0;
    xsi_delete_subprogram_invocation(t42, t43, t0, t44, t45);
    xsi_set_current_line(159, ng0);
    t2 = (t0 + 4024);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t30, 0, 8);
    xsi_vlog_signed_add(t30, 32, t4, 32, t5, 32);
    t6 = (t0 + 4024);
    xsi_vlogvar_assign_value(t6, t30, 0, 0, 32);
    goto LAB157;

LAB165:;
LAB167:    t5 = (t0 + 7504U);
    *((char **)t5) = &&LAB164;
    goto LAB1;

LAB171:;
LAB173:    t28 = (t0 + 7504U);
    *((char **)t28) = &&LAB170;
    goto LAB1;

LAB175:    xsi_set_current_line(166, ng0);

LAB177:    xsi_set_current_line(167, ng0);
    xsi_set_current_line(167, ng0);
    t7 = ((char*)((ng5)));
    t8 = (t0 + 4024);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 32);

LAB178:    t2 = (t0 + 4024);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng53)));
    memset(t30, 0, 8);
    xsi_vlog_signed_less(t30, 32, t4, 32, t5, 32);
    t6 = (t30 + 4);
    t31 = *((unsigned int *)t6);
    t32 = (~(t31));
    t33 = *((unsigned int *)t30);
    t34 = (t33 & t32);
    t35 = (t34 != 0);
    if (t35 > 0)
        goto LAB179;

LAB180:    xsi_set_current_line(166, ng0);
    t2 = (t0 + 3864);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t30, 0, 8);
    xsi_vlog_signed_add(t30, 32, t4, 32, t5, 32);
    t6 = (t0 + 3864);
    xsi_vlogvar_assign_value(t6, t30, 0, 0, 32);
    goto LAB174;

LAB179:    xsi_set_current_line(167, ng0);

LAB181:    xsi_set_current_line(168, ng0);
    t7 = (t0 + 3864);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t0 + 3384);
    xsi_vlogvar_assign_value(t10, t9, 0, 0, 8);
    xsi_set_current_line(168, ng0);
    t2 = (t0 + 4024);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3544);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 8);
    xsi_set_current_line(168, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB182;
    goto LAB1;

LAB182:    xsi_set_current_line(169, ng0);
    t2 = (t0 + 7312);
    t3 = (t0 + 1712);
    t4 = xsi_create_subprogram_invocation(t2, 0, t0, t3, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t3, t4);

LAB185:    t5 = (t0 + 7408);
    t6 = *((char **)t5);
    t7 = (t6 + 80U);
    t8 = *((char **)t7);
    t9 = (t8 + 272U);
    t10 = *((char **)t9);
    t11 = (t10 + 0U);
    t12 = *((char **)t11);
    t25 = ((int  (*)(char *, char *))t12)(t0, t6);

LAB187:    if (t25 != 0)
        goto LAB188;

LAB183:    t6 = (t0 + 1712);
    xsi_vlog_subprogram_popinvocation(t6);

LAB184:    t13 = (t0 + 7408);
    t14 = *((char **)t13);
    t13 = (t0 + 1712);
    t15 = (t0 + 7312);
    t16 = 0;
    xsi_delete_subprogram_invocation(t13, t14, t0, t15, t16);
    xsi_set_current_line(170, ng0);
    t2 = (t0 + 4984);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5144);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 5304);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t0 + 5464);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t0 + 5624);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = ((char*)((ng55)));
    t18 = (t0 + 7312);
    t19 = (t0 + 848);
    t20 = xsi_create_subprogram_invocation(t18, 0, t0, t19, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t19, t20);
    t21 = (t0 + 5784);
    xsi_vlogvar_assign_value(t21, t4, 0, 0, 8);
    t22 = (t0 + 5944);
    xsi_vlogvar_assign_value(t22, t7, 0, 0, 1);
    t23 = (t0 + 6104);
    xsi_vlogvar_assign_value(t23, t10, 0, 0, 1);
    t24 = (t0 + 6264);
    xsi_vlogvar_assign_value(t24, t13, 0, 0, 1);
    t26 = (t0 + 6424);
    xsi_vlogvar_assign_value(t26, t16, 0, 0, 1);
    t27 = (t0 + 6584);
    xsi_vlogvar_assign_value(t27, t17, 0, 0, 256);

LAB191:    t28 = (t0 + 7408);
    t29 = *((char **)t28);
    t36 = (t29 + 80U);
    t37 = *((char **)t36);
    t38 = (t37 + 272U);
    t39 = *((char **)t38);
    t40 = (t39 + 0U);
    t41 = *((char **)t40);
    t25 = ((int  (*)(char *, char *))t41)(t0, t29);

LAB193:    if (t25 != 0)
        goto LAB194;

LAB189:    t29 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t29);

LAB190:    t42 = (t0 + 7408);
    t43 = *((char **)t42);
    t42 = (t0 + 848);
    t44 = (t0 + 7312);
    t45 = 0;
    xsi_delete_subprogram_invocation(t42, t43, t0, t44, t45);
    xsi_set_current_line(167, ng0);
    t2 = (t0 + 4024);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t30, 0, 8);
    xsi_vlog_signed_add(t30, 32, t4, 32, t5, 32);
    t6 = (t0 + 4024);
    xsi_vlogvar_assign_value(t6, t30, 0, 0, 32);
    goto LAB178;

LAB186:;
LAB188:    t5 = (t0 + 7504U);
    *((char **)t5) = &&LAB185;
    goto LAB1;

LAB192:;
LAB194:    t28 = (t0 + 7504U);
    *((char **)t28) = &&LAB191;
    goto LAB1;

LAB196:    xsi_set_current_line(174, ng0);

LAB198:    xsi_set_current_line(175, ng0);
    xsi_set_current_line(175, ng0);
    t7 = ((char*)((ng5)));
    t8 = (t0 + 4024);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 32);

LAB199:    t2 = (t0 + 4024);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng53)));
    memset(t30, 0, 8);
    xsi_vlog_signed_less(t30, 32, t4, 32, t5, 32);
    t6 = (t30 + 4);
    t31 = *((unsigned int *)t6);
    t32 = (~(t31));
    t33 = *((unsigned int *)t30);
    t34 = (t33 & t32);
    t35 = (t34 != 0);
    if (t35 > 0)
        goto LAB200;

LAB201:    xsi_set_current_line(174, ng0);
    t2 = (t0 + 3864);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t30, 0, 8);
    xsi_vlog_signed_add(t30, 32, t4, 32, t5, 32);
    t6 = (t0 + 3864);
    xsi_vlogvar_assign_value(t6, t30, 0, 0, 32);
    goto LAB195;

LAB200:    xsi_set_current_line(175, ng0);

LAB202:    xsi_set_current_line(176, ng0);
    t7 = (t0 + 3864);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t0 + 3384);
    xsi_vlogvar_assign_value(t10, t9, 0, 0, 8);
    xsi_set_current_line(176, ng0);
    t2 = (t0 + 4024);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3544);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 8);
    xsi_set_current_line(176, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB203;
    goto LAB1;

LAB203:    xsi_set_current_line(177, ng0);
    t2 = (t0 + 7312);
    t3 = (t0 + 1712);
    t4 = xsi_create_subprogram_invocation(t2, 0, t0, t3, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t3, t4);

LAB206:    t5 = (t0 + 7408);
    t6 = *((char **)t5);
    t7 = (t6 + 80U);
    t8 = *((char **)t7);
    t9 = (t8 + 272U);
    t10 = *((char **)t9);
    t11 = (t10 + 0U);
    t12 = *((char **)t11);
    t25 = ((int  (*)(char *, char *))t12)(t0, t6);

LAB208:    if (t25 != 0)
        goto LAB209;

LAB204:    t6 = (t0 + 1712);
    xsi_vlog_subprogram_popinvocation(t6);

LAB205:    t13 = (t0 + 7408);
    t14 = *((char **)t13);
    t13 = (t0 + 1712);
    t15 = (t0 + 7312);
    t16 = 0;
    xsi_delete_subprogram_invocation(t13, t14, t0, t15, t16);
    xsi_set_current_line(178, ng0);
    t2 = (t0 + 4984);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5144);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 5304);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t0 + 5464);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t0 + 5624);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = ((char*)((ng56)));
    t18 = (t0 + 7312);
    t19 = (t0 + 848);
    t20 = xsi_create_subprogram_invocation(t18, 0, t0, t19, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t19, t20);
    t21 = (t0 + 5784);
    xsi_vlogvar_assign_value(t21, t4, 0, 0, 8);
    t22 = (t0 + 5944);
    xsi_vlogvar_assign_value(t22, t7, 0, 0, 1);
    t23 = (t0 + 6104);
    xsi_vlogvar_assign_value(t23, t10, 0, 0, 1);
    t24 = (t0 + 6264);
    xsi_vlogvar_assign_value(t24, t13, 0, 0, 1);
    t26 = (t0 + 6424);
    xsi_vlogvar_assign_value(t26, t16, 0, 0, 1);
    t27 = (t0 + 6584);
    xsi_vlogvar_assign_value(t27, t17, 0, 0, 256);

LAB212:    t28 = (t0 + 7408);
    t29 = *((char **)t28);
    t36 = (t29 + 80U);
    t37 = *((char **)t36);
    t38 = (t37 + 272U);
    t39 = *((char **)t38);
    t40 = (t39 + 0U);
    t41 = *((char **)t40);
    t25 = ((int  (*)(char *, char *))t41)(t0, t29);

LAB214:    if (t25 != 0)
        goto LAB215;

LAB210:    t29 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t29);

LAB211:    t42 = (t0 + 7408);
    t43 = *((char **)t42);
    t42 = (t0 + 848);
    t44 = (t0 + 7312);
    t45 = 0;
    xsi_delete_subprogram_invocation(t42, t43, t0, t44, t45);
    xsi_set_current_line(175, ng0);
    t2 = (t0 + 4024);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t30, 0, 8);
    xsi_vlog_signed_add(t30, 32, t4, 32, t5, 32);
    t6 = (t0 + 4024);
    xsi_vlogvar_assign_value(t6, t30, 0, 0, 32);
    goto LAB199;

LAB207:;
LAB209:    t5 = (t0 + 7504U);
    *((char **)t5) = &&LAB206;
    goto LAB1;

LAB213:;
LAB215:    t28 = (t0 + 7504U);
    *((char **)t28) = &&LAB212;
    goto LAB1;

LAB217:    xsi_set_current_line(183, ng0);

LAB219:    xsi_set_current_line(184, ng0);
    xsi_set_current_line(184, ng0);
    t7 = ((char*)((ng5)));
    t8 = (t0 + 4024);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 32);

LAB220:    t2 = (t0 + 4024);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng53)));
    memset(t30, 0, 8);
    xsi_vlog_signed_less(t30, 32, t4, 32, t5, 32);
    t6 = (t30 + 4);
    t31 = *((unsigned int *)t6);
    t32 = (~(t31));
    t33 = *((unsigned int *)t30);
    t34 = (t33 & t32);
    t35 = (t34 != 0);
    if (t35 > 0)
        goto LAB221;

LAB222:    xsi_set_current_line(183, ng0);
    t2 = (t0 + 3864);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t30, 0, 8);
    xsi_vlog_signed_add(t30, 32, t4, 32, t5, 32);
    t6 = (t0 + 3864);
    xsi_vlogvar_assign_value(t6, t30, 0, 0, 32);
    goto LAB216;

LAB221:    xsi_set_current_line(184, ng0);

LAB223:    xsi_set_current_line(185, ng0);
    t7 = (t0 + 3864);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t0 + 3384);
    xsi_vlogvar_assign_value(t10, t9, 0, 0, 8);
    xsi_set_current_line(185, ng0);
    t2 = (t0 + 4024);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3544);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 8);
    xsi_set_current_line(186, ng0);
    t2 = ((char*)((ng19)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(186, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB224;
    goto LAB1;

LAB224:    xsi_set_current_line(187, ng0);

LAB225:    xsi_set_current_line(187, ng0);
    t2 = (t0 + 3384);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3544);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t31 = *((unsigned int *)t4);
    t32 = *((unsigned int *)t7);
    t33 = (t31 & t32);
    *((unsigned int *)t30) = t33;
    t8 = (t4 + 4);
    t9 = (t7 + 4);
    t10 = (t30 + 4);
    t34 = *((unsigned int *)t8);
    t35 = *((unsigned int *)t9);
    t46 = (t34 | t35);
    *((unsigned int *)t10) = t46;
    t47 = *((unsigned int *)t10);
    t48 = (t47 != 0);
    if (t48 == 1)
        goto LAB226;

LAB227:
LAB228:    t13 = (t0 + 4984);
    xsi_vlogvar_assign_value(t13, t30, 0, 0, 8);
    xsi_set_current_line(188, ng0);
    t2 = (t0 + 4984);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4984);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = ((char*)((ng5)));
    memset(t30, 0, 8);
    t9 = (t7 + 4);
    t10 = (t8 + 4);
    t31 = *((unsigned int *)t7);
    t32 = *((unsigned int *)t8);
    t33 = (t31 ^ t32);
    t34 = *((unsigned int *)t9);
    t35 = *((unsigned int *)t10);
    t46 = (t34 ^ t35);
    t47 = (t33 | t46);
    t48 = *((unsigned int *)t9);
    t49 = *((unsigned int *)t10);
    t50 = (t48 | t49);
    t51 = (~(t50));
    t52 = (t47 & t51);
    if (t52 != 0)
        goto LAB232;

LAB229:    if (t50 != 0)
        goto LAB231;

LAB230:    *((unsigned int *)t30) = 1;

LAB232:    t12 = ((char*)((ng4)));
    t13 = (t0 + 4984);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    memset(t66, 0, 8);
    t16 = (t66 + 4);
    t17 = (t15 + 4);
    t53 = *((unsigned int *)t15);
    t54 = (t53 >> 7);
    t55 = (t54 & 1);
    *((unsigned int *)t66) = t55;
    t56 = *((unsigned int *)t17);
    t57 = (t56 >> 7);
    t58 = (t57 & 1);
    *((unsigned int *)t16) = t58;
    t18 = ((char*)((ng4)));
    t19 = ((char*)((ng57)));
    t20 = (t0 + 7312);
    t21 = (t0 + 848);
    t22 = xsi_create_subprogram_invocation(t20, 0, t0, t21, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t21, t22);
    t23 = (t0 + 5784);
    xsi_vlogvar_assign_value(t23, t4, 0, 0, 8);
    t24 = (t0 + 5944);
    xsi_vlogvar_assign_value(t24, t30, 0, 0, 1);
    t26 = (t0 + 6104);
    xsi_vlogvar_assign_value(t26, t12, 0, 0, 1);
    t27 = (t0 + 6264);
    xsi_vlogvar_assign_value(t27, t66, 0, 0, 1);
    t28 = (t0 + 6424);
    xsi_vlogvar_assign_value(t28, t18, 0, 0, 1);
    t29 = (t0 + 6584);
    xsi_vlogvar_assign_value(t29, t19, 0, 0, 256);

LAB235:    t36 = (t0 + 7408);
    t37 = *((char **)t36);
    t38 = (t37 + 80U);
    t39 = *((char **)t38);
    t40 = (t39 + 272U);
    t41 = *((char **)t40);
    t42 = (t41 + 0U);
    t43 = *((char **)t42);
    t25 = ((int  (*)(char *, char *))t43)(t0, t37);

LAB237:    if (t25 != 0)
        goto LAB238;

LAB233:    t37 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t37);

LAB234:    t44 = (t0 + 7408);
    t45 = *((char **)t44);
    t44 = (t0 + 848);
    t67 = (t0 + 7312);
    t68 = 0;
    xsi_delete_subprogram_invocation(t44, t45, t0, t67, t68);
    xsi_set_current_line(189, ng0);
    t2 = ((char*)((ng22)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(189, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB239;
    goto LAB1;

LAB226:    t49 = *((unsigned int *)t30);
    t50 = *((unsigned int *)t10);
    *((unsigned int *)t30) = (t49 | t50);
    t11 = (t4 + 4);
    t12 = (t7 + 4);
    t51 = *((unsigned int *)t4);
    t52 = (~(t51));
    t53 = *((unsigned int *)t11);
    t54 = (~(t53));
    t55 = *((unsigned int *)t7);
    t56 = (~(t55));
    t57 = *((unsigned int *)t12);
    t58 = (~(t57));
    t25 = (t52 & t54);
    t59 = (t56 & t58);
    t60 = (~(t25));
    t61 = (~(t59));
    t62 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t62 & t60);
    t63 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t63 & t61);
    t64 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t64 & t60);
    t65 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t65 & t61);
    goto LAB228;

LAB231:    t11 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB232;

LAB236:;
LAB238:    t36 = (t0 + 7504U);
    *((char **)t36) = &&LAB235;
    goto LAB1;

LAB239:    xsi_set_current_line(190, ng0);

LAB240:    xsi_set_current_line(190, ng0);
    t2 = (t0 + 3384);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3544);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t31 = *((unsigned int *)t4);
    t32 = *((unsigned int *)t7);
    t33 = (t31 | t32);
    *((unsigned int *)t30) = t33;
    t8 = (t4 + 4);
    t9 = (t7 + 4);
    t10 = (t30 + 4);
    t34 = *((unsigned int *)t8);
    t35 = *((unsigned int *)t9);
    t46 = (t34 | t35);
    *((unsigned int *)t10) = t46;
    t47 = *((unsigned int *)t10);
    t48 = (t47 != 0);
    if (t48 == 1)
        goto LAB241;

LAB242:
LAB243:    t13 = (t0 + 4984);
    xsi_vlogvar_assign_value(t13, t30, 0, 0, 8);
    xsi_set_current_line(191, ng0);
    t2 = (t0 + 4984);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4984);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = ((char*)((ng5)));
    memset(t30, 0, 8);
    t9 = (t7 + 4);
    t10 = (t8 + 4);
    t31 = *((unsigned int *)t7);
    t32 = *((unsigned int *)t8);
    t33 = (t31 ^ t32);
    t34 = *((unsigned int *)t9);
    t35 = *((unsigned int *)t10);
    t46 = (t34 ^ t35);
    t47 = (t33 | t46);
    t48 = *((unsigned int *)t9);
    t49 = *((unsigned int *)t10);
    t50 = (t48 | t49);
    t51 = (~(t50));
    t52 = (t47 & t51);
    if (t52 != 0)
        goto LAB247;

LAB244:    if (t50 != 0)
        goto LAB246;

LAB245:    *((unsigned int *)t30) = 1;

LAB247:    t12 = ((char*)((ng4)));
    t13 = (t0 + 4984);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    memset(t66, 0, 8);
    t16 = (t66 + 4);
    t17 = (t15 + 4);
    t53 = *((unsigned int *)t15);
    t54 = (t53 >> 7);
    t55 = (t54 & 1);
    *((unsigned int *)t66) = t55;
    t56 = *((unsigned int *)t17);
    t57 = (t56 >> 7);
    t58 = (t57 & 1);
    *((unsigned int *)t16) = t58;
    t18 = ((char*)((ng4)));
    t19 = ((char*)((ng58)));
    t20 = (t0 + 7312);
    t21 = (t0 + 848);
    t22 = xsi_create_subprogram_invocation(t20, 0, t0, t21, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t21, t22);
    t23 = (t0 + 5784);
    xsi_vlogvar_assign_value(t23, t4, 0, 0, 8);
    t24 = (t0 + 5944);
    xsi_vlogvar_assign_value(t24, t30, 0, 0, 1);
    t26 = (t0 + 6104);
    xsi_vlogvar_assign_value(t26, t12, 0, 0, 1);
    t27 = (t0 + 6264);
    xsi_vlogvar_assign_value(t27, t66, 0, 0, 1);
    t28 = (t0 + 6424);
    xsi_vlogvar_assign_value(t28, t18, 0, 0, 1);
    t29 = (t0 + 6584);
    xsi_vlogvar_assign_value(t29, t19, 0, 0, 256);

LAB250:    t36 = (t0 + 7408);
    t37 = *((char **)t36);
    t38 = (t37 + 80U);
    t39 = *((char **)t38);
    t40 = (t39 + 272U);
    t41 = *((char **)t40);
    t42 = (t41 + 0U);
    t43 = *((char **)t42);
    t25 = ((int  (*)(char *, char *))t43)(t0, t37);

LAB252:    if (t25 != 0)
        goto LAB253;

LAB248:    t37 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t37);

LAB249:    t44 = (t0 + 7408);
    t45 = *((char **)t44);
    t44 = (t0 + 848);
    t67 = (t0 + 7312);
    t68 = 0;
    xsi_delete_subprogram_invocation(t44, t45, t0, t67, t68);
    xsi_set_current_line(192, ng0);
    t2 = ((char*)((ng24)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(192, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB254;
    goto LAB1;

LAB241:    t49 = *((unsigned int *)t30);
    t50 = *((unsigned int *)t10);
    *((unsigned int *)t30) = (t49 | t50);
    t11 = (t4 + 4);
    t12 = (t7 + 4);
    t51 = *((unsigned int *)t11);
    t52 = (~(t51));
    t53 = *((unsigned int *)t4);
    t25 = (t53 & t52);
    t54 = *((unsigned int *)t12);
    t55 = (~(t54));
    t56 = *((unsigned int *)t7);
    t59 = (t56 & t55);
    t57 = (~(t25));
    t58 = (~(t59));
    t60 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t60 & t57);
    t61 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t61 & t58);
    goto LAB243;

LAB246:    t11 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB247;

LAB251:;
LAB253:    t36 = (t0 + 7504U);
    *((char **)t36) = &&LAB250;
    goto LAB1;

LAB254:    xsi_set_current_line(193, ng0);

LAB255:    xsi_set_current_line(193, ng0);
    t2 = (t0 + 3384);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3544);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t31 = *((unsigned int *)t4);
    t32 = *((unsigned int *)t7);
    t33 = (t31 ^ t32);
    *((unsigned int *)t30) = t33;
    t8 = (t4 + 4);
    t9 = (t7 + 4);
    t10 = (t30 + 4);
    t34 = *((unsigned int *)t8);
    t35 = *((unsigned int *)t9);
    t46 = (t34 | t35);
    *((unsigned int *)t10) = t46;
    t47 = *((unsigned int *)t10);
    t48 = (t47 != 0);
    if (t48 == 1)
        goto LAB256;

LAB257:
LAB258:    t11 = (t0 + 4984);
    xsi_vlogvar_assign_value(t11, t30, 0, 0, 8);
    xsi_set_current_line(194, ng0);
    t2 = (t0 + 4984);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4984);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = ((char*)((ng5)));
    memset(t30, 0, 8);
    t9 = (t7 + 4);
    t10 = (t8 + 4);
    t31 = *((unsigned int *)t7);
    t32 = *((unsigned int *)t8);
    t33 = (t31 ^ t32);
    t34 = *((unsigned int *)t9);
    t35 = *((unsigned int *)t10);
    t46 = (t34 ^ t35);
    t47 = (t33 | t46);
    t48 = *((unsigned int *)t9);
    t49 = *((unsigned int *)t10);
    t50 = (t48 | t49);
    t51 = (~(t50));
    t52 = (t47 & t51);
    if (t52 != 0)
        goto LAB262;

LAB259:    if (t50 != 0)
        goto LAB261;

LAB260:    *((unsigned int *)t30) = 1;

LAB262:    t12 = ((char*)((ng4)));
    t13 = (t0 + 4984);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    memset(t66, 0, 8);
    t16 = (t66 + 4);
    t17 = (t15 + 4);
    t53 = *((unsigned int *)t15);
    t54 = (t53 >> 7);
    t55 = (t54 & 1);
    *((unsigned int *)t66) = t55;
    t56 = *((unsigned int *)t17);
    t57 = (t56 >> 7);
    t58 = (t57 & 1);
    *((unsigned int *)t16) = t58;
    t18 = ((char*)((ng4)));
    t19 = ((char*)((ng59)));
    t20 = (t0 + 7312);
    t21 = (t0 + 848);
    t22 = xsi_create_subprogram_invocation(t20, 0, t0, t21, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t21, t22);
    t23 = (t0 + 5784);
    xsi_vlogvar_assign_value(t23, t4, 0, 0, 8);
    t24 = (t0 + 5944);
    xsi_vlogvar_assign_value(t24, t30, 0, 0, 1);
    t26 = (t0 + 6104);
    xsi_vlogvar_assign_value(t26, t12, 0, 0, 1);
    t27 = (t0 + 6264);
    xsi_vlogvar_assign_value(t27, t66, 0, 0, 1);
    t28 = (t0 + 6424);
    xsi_vlogvar_assign_value(t28, t18, 0, 0, 1);
    t29 = (t0 + 6584);
    xsi_vlogvar_assign_value(t29, t19, 0, 0, 256);

LAB265:    t36 = (t0 + 7408);
    t37 = *((char **)t36);
    t38 = (t37 + 80U);
    t39 = *((char **)t38);
    t40 = (t39 + 272U);
    t41 = *((char **)t40);
    t42 = (t41 + 0U);
    t43 = *((char **)t42);
    t25 = ((int  (*)(char *, char *))t43)(t0, t37);

LAB267:    if (t25 != 0)
        goto LAB268;

LAB263:    t37 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t37);

LAB264:    t44 = (t0 + 7408);
    t45 = *((char **)t44);
    t44 = (t0 + 848);
    t67 = (t0 + 7312);
    t68 = 0;
    xsi_delete_subprogram_invocation(t44, t45, t0, t67, t68);
    xsi_set_current_line(195, ng0);
    t2 = ((char*)((ng28)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(195, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB269;
    goto LAB1;

LAB256:    t49 = *((unsigned int *)t30);
    t50 = *((unsigned int *)t10);
    *((unsigned int *)t30) = (t49 | t50);
    goto LAB258;

LAB261:    t11 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB262;

LAB266:;
LAB268:    t36 = (t0 + 7504U);
    *((char **)t36) = &&LAB265;
    goto LAB1;

LAB269:    xsi_set_current_line(196, ng0);

LAB270:    xsi_set_current_line(196, ng0);
    t2 = (t0 + 3544);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4984);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 8);
    xsi_set_current_line(197, ng0);
    t2 = (t0 + 4984);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4984);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = ((char*)((ng5)));
    memset(t30, 0, 8);
    t9 = (t7 + 4);
    t10 = (t8 + 4);
    t31 = *((unsigned int *)t7);
    t32 = *((unsigned int *)t8);
    t33 = (t31 ^ t32);
    t34 = *((unsigned int *)t9);
    t35 = *((unsigned int *)t10);
    t46 = (t34 ^ t35);
    t47 = (t33 | t46);
    t48 = *((unsigned int *)t9);
    t49 = *((unsigned int *)t10);
    t50 = (t48 | t49);
    t51 = (~(t50));
    t52 = (t47 & t51);
    if (t52 != 0)
        goto LAB274;

LAB271:    if (t50 != 0)
        goto LAB273;

LAB272:    *((unsigned int *)t30) = 1;

LAB274:    t12 = ((char*)((ng4)));
    t13 = (t0 + 4984);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    memset(t66, 0, 8);
    t16 = (t66 + 4);
    t17 = (t15 + 4);
    t53 = *((unsigned int *)t15);
    t54 = (t53 >> 7);
    t55 = (t54 & 1);
    *((unsigned int *)t66) = t55;
    t56 = *((unsigned int *)t17);
    t57 = (t56 >> 7);
    t58 = (t57 & 1);
    *((unsigned int *)t16) = t58;
    t18 = ((char*)((ng4)));
    t19 = ((char*)((ng60)));
    t20 = (t0 + 7312);
    t21 = (t0 + 848);
    t22 = xsi_create_subprogram_invocation(t20, 0, t0, t21, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t21, t22);
    t23 = (t0 + 5784);
    xsi_vlogvar_assign_value(t23, t4, 0, 0, 8);
    t24 = (t0 + 5944);
    xsi_vlogvar_assign_value(t24, t30, 0, 0, 1);
    t26 = (t0 + 6104);
    xsi_vlogvar_assign_value(t26, t12, 0, 0, 1);
    t27 = (t0 + 6264);
    xsi_vlogvar_assign_value(t27, t66, 0, 0, 1);
    t28 = (t0 + 6424);
    xsi_vlogvar_assign_value(t28, t18, 0, 0, 1);
    t29 = (t0 + 6584);
    xsi_vlogvar_assign_value(t29, t19, 0, 0, 256);

LAB277:    t36 = (t0 + 7408);
    t37 = *((char **)t36);
    t38 = (t37 + 80U);
    t39 = *((char **)t38);
    t40 = (t39 + 272U);
    t41 = *((char **)t40);
    t42 = (t41 + 0U);
    t43 = *((char **)t42);
    t25 = ((int  (*)(char *, char *))t43)(t0, t37);

LAB279:    if (t25 != 0)
        goto LAB280;

LAB275:    t37 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t37);

LAB276:    t44 = (t0 + 7408);
    t45 = *((char **)t44);
    t44 = (t0 + 848);
    t67 = (t0 + 7312);
    t68 = 0;
    xsi_delete_subprogram_invocation(t44, t45, t0, t67, t68);
    xsi_set_current_line(198, ng0);
    t2 = ((char*)((ng30)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(198, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB281;
    goto LAB1;

LAB273:    t11 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB274;

LAB278:;
LAB280:    t36 = (t0 + 7504U);
    *((char **)t36) = &&LAB277;
    goto LAB1;

LAB281:    xsi_set_current_line(199, ng0);

LAB282:    xsi_set_current_line(199, ng0);
    t2 = (t0 + 3544);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t30, 0, 8);
    t5 = (t30 + 4);
    t6 = (t4 + 4);
    t31 = *((unsigned int *)t4);
    t32 = (~(t31));
    *((unsigned int *)t30) = t32;
    *((unsigned int *)t5) = 0;
    if (*((unsigned int *)t6) != 0)
        goto LAB284;

LAB283:    t47 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t47 & 255U);
    t48 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t48 & 255U);
    t7 = (t0 + 4984);
    xsi_vlogvar_assign_value(t7, t30, 0, 0, 8);
    xsi_set_current_line(200, ng0);
    t2 = (t0 + 4984);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4984);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = ((char*)((ng5)));
    memset(t30, 0, 8);
    t9 = (t7 + 4);
    t10 = (t8 + 4);
    t31 = *((unsigned int *)t7);
    t32 = *((unsigned int *)t8);
    t33 = (t31 ^ t32);
    t34 = *((unsigned int *)t9);
    t35 = *((unsigned int *)t10);
    t46 = (t34 ^ t35);
    t47 = (t33 | t46);
    t48 = *((unsigned int *)t9);
    t49 = *((unsigned int *)t10);
    t50 = (t48 | t49);
    t51 = (~(t50));
    t52 = (t47 & t51);
    if (t52 != 0)
        goto LAB288;

LAB285:    if (t50 != 0)
        goto LAB287;

LAB286:    *((unsigned int *)t30) = 1;

LAB288:    t12 = ((char*)((ng4)));
    t13 = (t0 + 4984);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    memset(t66, 0, 8);
    t16 = (t66 + 4);
    t17 = (t15 + 4);
    t53 = *((unsigned int *)t15);
    t54 = (t53 >> 7);
    t55 = (t54 & 1);
    *((unsigned int *)t66) = t55;
    t56 = *((unsigned int *)t17);
    t57 = (t56 >> 7);
    t58 = (t57 & 1);
    *((unsigned int *)t16) = t58;
    t18 = ((char*)((ng4)));
    t19 = ((char*)((ng61)));
    t20 = (t0 + 7312);
    t21 = (t0 + 848);
    t22 = xsi_create_subprogram_invocation(t20, 0, t0, t21, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t21, t22);
    t23 = (t0 + 5784);
    xsi_vlogvar_assign_value(t23, t4, 0, 0, 8);
    t24 = (t0 + 5944);
    xsi_vlogvar_assign_value(t24, t30, 0, 0, 1);
    t26 = (t0 + 6104);
    xsi_vlogvar_assign_value(t26, t12, 0, 0, 1);
    t27 = (t0 + 6264);
    xsi_vlogvar_assign_value(t27, t66, 0, 0, 1);
    t28 = (t0 + 6424);
    xsi_vlogvar_assign_value(t28, t18, 0, 0, 1);
    t29 = (t0 + 6584);
    xsi_vlogvar_assign_value(t29, t19, 0, 0, 256);

LAB291:    t36 = (t0 + 7408);
    t37 = *((char **)t36);
    t38 = (t37 + 80U);
    t39 = *((char **)t38);
    t40 = (t39 + 272U);
    t41 = *((char **)t40);
    t42 = (t41 + 0U);
    t43 = *((char **)t42);
    t25 = ((int  (*)(char *, char *))t43)(t0, t37);

LAB293:    if (t25 != 0)
        goto LAB294;

LAB289:    t37 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t37);

LAB290:    t44 = (t0 + 7408);
    t45 = *((char **)t44);
    t44 = (t0 + 848);
    t67 = (t0 + 7312);
    t68 = 0;
    xsi_delete_subprogram_invocation(t44, t45, t0, t67, t68);
    xsi_set_current_line(184, ng0);
    t2 = (t0 + 4024);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t30, 0, 8);
    xsi_vlog_signed_add(t30, 32, t4, 32, t5, 32);
    t6 = (t0 + 4024);
    xsi_vlogvar_assign_value(t6, t30, 0, 0, 32);
    goto LAB220;

LAB284:    t33 = *((unsigned int *)t30);
    t34 = *((unsigned int *)t6);
    *((unsigned int *)t30) = (t33 | t34);
    t35 = *((unsigned int *)t5);
    t46 = *((unsigned int *)t6);
    *((unsigned int *)t5) = (t35 | t46);
    goto LAB283;

LAB287:    t11 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB288;

LAB292:;
LAB294:    t36 = (t0 + 7504U);
    *((char **)t36) = &&LAB291;
    goto LAB1;

LAB296:    xsi_set_current_line(205, ng0);

LAB298:    xsi_set_current_line(206, ng0);
    xsi_set_current_line(206, ng0);
    t7 = ((char*)((ng5)));
    t8 = (t0 + 4184);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 32);

LAB299:    t2 = (t0 + 4184);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng38)));
    memset(t30, 0, 8);
    xsi_vlog_signed_less(t30, 32, t4, 32, t5, 32);
    t6 = (t30 + 4);
    t31 = *((unsigned int *)t6);
    t32 = (~(t31));
    t33 = *((unsigned int *)t30);
    t34 = (t33 & t32);
    t35 = (t34 != 0);
    if (t35 > 0)
        goto LAB300;

LAB301:    xsi_set_current_line(205, ng0);
    t2 = (t0 + 3864);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t30, 0, 8);
    xsi_vlog_signed_add(t30, 32, t4, 32, t5, 32);
    t6 = (t0 + 3864);
    xsi_vlogvar_assign_value(t6, t30, 0, 0, 32);
    goto LAB295;

LAB300:    xsi_set_current_line(206, ng0);

LAB302:    xsi_set_current_line(207, ng0);
    t7 = (t0 + 3864);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t0 + 3384);
    xsi_vlogvar_assign_value(t10, t9, 0, 0, 8);
    xsi_set_current_line(209, ng0);
    t2 = (t0 + 4184);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3544);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 8);
    xsi_set_current_line(209, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB303;
    goto LAB1;

LAB303:    xsi_set_current_line(210, ng0);

LAB304:    xsi_set_current_line(211, ng0);
    t2 = (t0 + 3384);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4184);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t30, 0, 8);
    xsi_vlog_unsigned_lshift(t30, 8, t4, 8, t7, 32);
    t8 = ((char*)((ng3)));
    t31 = *((unsigned int *)t30);
    t32 = *((unsigned int *)t8);
    t33 = (t31 & t32);
    *((unsigned int *)t66) = t33;
    t9 = (t30 + 4);
    t10 = (t8 + 4);
    t11 = (t66 + 4);
    t34 = *((unsigned int *)t9);
    t35 = *((unsigned int *)t10);
    t46 = (t34 | t35);
    *((unsigned int *)t11) = t46;
    t47 = *((unsigned int *)t11);
    t48 = (t47 != 0);
    if (t48 == 1)
        goto LAB305;

LAB306:
LAB307:    t14 = (t0 + 4984);
    xsi_vlogvar_assign_value(t14, t66, 0, 0, 8);
    xsi_set_current_line(212, ng0);
    t2 = (t0 + 4184);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng5)));
    memset(t69, 0, 8);
    xsi_vlog_signed_equal(t69, 32, t4, 32, t5, 32);
    memset(t66, 0, 8);
    t6 = (t69 + 4);
    t31 = *((unsigned int *)t6);
    t32 = (~(t31));
    t33 = *((unsigned int *)t69);
    t34 = (t33 & t32);
    t35 = (t34 & 1U);
    if (t35 != 0)
        goto LAB308;

LAB309:    if (*((unsigned int *)t6) != 0)
        goto LAB310;

LAB311:    t8 = (t66 + 4);
    t46 = *((unsigned int *)t66);
    t47 = *((unsigned int *)t8);
    t48 = (t46 || t47);
    if (t48 > 0)
        goto LAB312;

LAB313:    t49 = *((unsigned int *)t66);
    t50 = (~(t49));
    t51 = *((unsigned int *)t8);
    t52 = (t50 || t51);
    if (t52 > 0)
        goto LAB314;

LAB315:    if (*((unsigned int *)t8) > 0)
        goto LAB316;

LAB317:    if (*((unsigned int *)t66) > 0)
        goto LAB318;

LAB319:    memcpy(t30, t72, 8);

LAB320:    t23 = (t0 + 5304);
    xsi_vlogvar_assign_value(t23, t30, 0, 0, 1);
    xsi_set_current_line(213, ng0);
    t2 = ((char*)((ng38)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(214, ng0);
    t2 = (t0 + 4984);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4984);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = ((char*)((ng5)));
    memset(t30, 0, 8);
    t9 = (t7 + 4);
    t10 = (t8 + 4);
    t31 = *((unsigned int *)t7);
    t32 = *((unsigned int *)t8);
    t33 = (t31 ^ t32);
    t34 = *((unsigned int *)t9);
    t35 = *((unsigned int *)t10);
    t46 = (t34 ^ t35);
    t47 = (t33 | t46);
    t48 = *((unsigned int *)t9);
    t49 = *((unsigned int *)t10);
    t50 = (t48 | t49);
    t51 = (~(t50));
    t52 = (t47 & t51);
    if (t52 != 0)
        goto LAB327;

LAB324:    if (t50 != 0)
        goto LAB326;

LAB325:    *((unsigned int *)t30) = 1;

LAB327:    t12 = (t0 + 5304);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    t15 = (t0 + 4984);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    memset(t66, 0, 8);
    t18 = (t66 + 4);
    t19 = (t17 + 4);
    t53 = *((unsigned int *)t17);
    t54 = (t53 >> 7);
    t55 = (t54 & 1);
    *((unsigned int *)t66) = t55;
    t56 = *((unsigned int *)t19);
    t57 = (t56 >> 7);
    t58 = (t57 & 1);
    *((unsigned int *)t18) = t58;
    t20 = ((char*)((ng4)));
    t21 = ((char*)((ng62)));
    t22 = (t0 + 7312);
    t23 = (t0 + 848);
    t24 = xsi_create_subprogram_invocation(t22, 0, t0, t23, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t23, t24);
    t26 = (t0 + 5784);
    xsi_vlogvar_assign_value(t26, t4, 0, 0, 8);
    t27 = (t0 + 5944);
    xsi_vlogvar_assign_value(t27, t30, 0, 0, 1);
    t28 = (t0 + 6104);
    xsi_vlogvar_assign_value(t28, t14, 0, 0, 1);
    t29 = (t0 + 6264);
    xsi_vlogvar_assign_value(t29, t66, 0, 0, 1);
    t36 = (t0 + 6424);
    xsi_vlogvar_assign_value(t36, t20, 0, 0, 1);
    t37 = (t0 + 6584);
    xsi_vlogvar_assign_value(t37, t21, 0, 0, 256);

LAB330:    t38 = (t0 + 7408);
    t39 = *((char **)t38);
    t40 = (t39 + 80U);
    t41 = *((char **)t40);
    t42 = (t41 + 272U);
    t43 = *((char **)t42);
    t44 = (t43 + 0U);
    t45 = *((char **)t44);
    t25 = ((int  (*)(char *, char *))t45)(t0, t39);

LAB332:    if (t25 != 0)
        goto LAB333;

LAB328:    t39 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t39);

LAB329:    t67 = (t0 + 7408);
    t68 = *((char **)t67);
    t67 = (t0 + 848);
    t85 = (t0 + 7312);
    t86 = 0;
    xsi_delete_subprogram_invocation(t67, t68, t0, t85, t86);
    xsi_set_current_line(216, ng0);
    t2 = (t0 + 4184);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng63)));
    t31 = *((unsigned int *)t4);
    t32 = *((unsigned int *)t5);
    t33 = (t31 | t32);
    *((unsigned int *)t30) = t33;
    t6 = (t4 + 4);
    t7 = (t5 + 4);
    t8 = (t30 + 4);
    t34 = *((unsigned int *)t6);
    t35 = *((unsigned int *)t7);
    t46 = (t34 | t35);
    *((unsigned int *)t8) = t46;
    t47 = *((unsigned int *)t8);
    t48 = (t47 != 0);
    if (t48 == 1)
        goto LAB334;

LAB335:
LAB336:    t11 = (t0 + 3544);
    xsi_vlogvar_assign_value(t11, t30, 0, 0, 8);
    xsi_set_current_line(216, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB337;
    goto LAB1;

LAB305:    t49 = *((unsigned int *)t66);
    t50 = *((unsigned int *)t11);
    *((unsigned int *)t66) = (t49 | t50);
    t12 = (t30 + 4);
    t13 = (t8 + 4);
    t51 = *((unsigned int *)t30);
    t52 = (~(t51));
    t53 = *((unsigned int *)t12);
    t54 = (~(t53));
    t55 = *((unsigned int *)t8);
    t56 = (~(t55));
    t57 = *((unsigned int *)t13);
    t58 = (~(t57));
    t25 = (t52 & t54);
    t59 = (t56 & t58);
    t60 = (~(t25));
    t61 = (~(t59));
    t62 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t62 & t60);
    t63 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t63 & t61);
    t64 = *((unsigned int *)t66);
    *((unsigned int *)t66) = (t64 & t60);
    t65 = *((unsigned int *)t66);
    *((unsigned int *)t66) = (t65 & t61);
    goto LAB307;

LAB308:    *((unsigned int *)t66) = 1;
    goto LAB311;

LAB310:    t7 = (t66 + 4);
    *((unsigned int *)t66) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB311;

LAB312:    t9 = ((char*)((ng4)));
    goto LAB313;

LAB314:    t10 = (t0 + 3384);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t13 = ((char*)((ng38)));
    t14 = (t0 + 4184);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    memset(t70, 0, 8);
    xsi_vlog_signed_minus(t70, 32, t13, 32, t16, 32);
    memset(t71, 0, 8);
    xsi_vlog_unsigned_rshift(t71, 8, t12, 8, t70, 32);
    t17 = ((char*)((ng7)));
    t53 = *((unsigned int *)t71);
    t54 = *((unsigned int *)t17);
    t55 = (t53 & t54);
    *((unsigned int *)t72) = t55;
    t18 = (t71 + 4);
    t19 = (t17 + 4);
    t20 = (t72 + 4);
    t56 = *((unsigned int *)t18);
    t57 = *((unsigned int *)t19);
    t58 = (t56 | t57);
    *((unsigned int *)t20) = t58;
    t60 = *((unsigned int *)t20);
    t61 = (t60 != 0);
    if (t61 == 1)
        goto LAB321;

LAB322:
LAB323:    goto LAB315;

LAB316:    xsi_vlog_unsigned_bit_combine(t30, 8, t9, 8, t72, 8);
    goto LAB320;

LAB318:    memcpy(t30, t9, 8);
    goto LAB320;

LAB321:    t62 = *((unsigned int *)t72);
    t63 = *((unsigned int *)t20);
    *((unsigned int *)t72) = (t62 | t63);
    t21 = (t71 + 4);
    t22 = (t17 + 4);
    t64 = *((unsigned int *)t71);
    t65 = (~(t64));
    t73 = *((unsigned int *)t21);
    t74 = (~(t73));
    t75 = *((unsigned int *)t17);
    t76 = (~(t75));
    t77 = *((unsigned int *)t22);
    t78 = (~(t77));
    t25 = (t65 & t74);
    t59 = (t76 & t78);
    t79 = (~(t25));
    t80 = (~(t59));
    t81 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t81 & t79);
    t82 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t82 & t80);
    t83 = *((unsigned int *)t72);
    *((unsigned int *)t72) = (t83 & t79);
    t84 = *((unsigned int *)t72);
    *((unsigned int *)t72) = (t84 & t80);
    goto LAB323;

LAB326:    t11 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB327;

LAB331:;
LAB333:    t38 = (t0 + 7504U);
    *((char **)t38) = &&LAB330;
    goto LAB1;

LAB334:    t49 = *((unsigned int *)t30);
    t50 = *((unsigned int *)t8);
    *((unsigned int *)t30) = (t49 | t50);
    t9 = (t4 + 4);
    t10 = (t5 + 4);
    t51 = *((unsigned int *)t9);
    t52 = (~(t51));
    t53 = *((unsigned int *)t4);
    t25 = (t53 & t52);
    t54 = *((unsigned int *)t10);
    t55 = (~(t54));
    t56 = *((unsigned int *)t5);
    t59 = (t56 & t55);
    t57 = (~(t25));
    t58 = (~(t59));
    t60 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t60 & t57);
    t61 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t61 & t58);
    goto LAB336;

LAB337:    xsi_set_current_line(217, ng0);

LAB338:    xsi_set_current_line(218, ng0);
    t2 = (t0 + 3384);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4184);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t30, 0, 8);
    xsi_vlog_unsigned_lshift(t30, 8, t4, 8, t7, 32);
    t8 = ((char*)((ng3)));
    t31 = *((unsigned int *)t30);
    t32 = *((unsigned int *)t8);
    t33 = (t31 & t32);
    *((unsigned int *)t66) = t33;
    t9 = (t30 + 4);
    t10 = (t8 + 4);
    t11 = (t66 + 4);
    t34 = *((unsigned int *)t9);
    t35 = *((unsigned int *)t10);
    t46 = (t34 | t35);
    *((unsigned int *)t11) = t46;
    t47 = *((unsigned int *)t11);
    t48 = (t47 != 0);
    if (t48 == 1)
        goto LAB339;

LAB340:
LAB341:    t14 = (t0 + 4984);
    xsi_vlogvar_assign_value(t14, t66, 0, 0, 8);
    xsi_set_current_line(219, ng0);
    t2 = (t0 + 4184);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng5)));
    memset(t69, 0, 8);
    xsi_vlog_signed_equal(t69, 32, t4, 32, t5, 32);
    memset(t66, 0, 8);
    t6 = (t69 + 4);
    t31 = *((unsigned int *)t6);
    t32 = (~(t31));
    t33 = *((unsigned int *)t69);
    t34 = (t33 & t32);
    t35 = (t34 & 1U);
    if (t35 != 0)
        goto LAB342;

LAB343:    if (*((unsigned int *)t6) != 0)
        goto LAB344;

LAB345:    t8 = (t66 + 4);
    t46 = *((unsigned int *)t66);
    t47 = *((unsigned int *)t8);
    t48 = (t46 || t47);
    if (t48 > 0)
        goto LAB346;

LAB347:    t49 = *((unsigned int *)t66);
    t50 = (~(t49));
    t51 = *((unsigned int *)t8);
    t52 = (t50 || t51);
    if (t52 > 0)
        goto LAB348;

LAB349:    if (*((unsigned int *)t8) > 0)
        goto LAB350;

LAB351:    if (*((unsigned int *)t66) > 0)
        goto LAB352;

LAB353:    memcpy(t30, t72, 8);

LAB354:    t23 = (t0 + 5304);
    xsi_vlogvar_assign_value(t23, t30, 0, 0, 1);
    xsi_set_current_line(220, ng0);
    t2 = (t0 + 4984);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4984);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = ((char*)((ng5)));
    memset(t30, 0, 8);
    t9 = (t7 + 4);
    t10 = (t8 + 4);
    t31 = *((unsigned int *)t7);
    t32 = *((unsigned int *)t8);
    t33 = (t31 ^ t32);
    t34 = *((unsigned int *)t9);
    t35 = *((unsigned int *)t10);
    t46 = (t34 ^ t35);
    t47 = (t33 | t46);
    t48 = *((unsigned int *)t9);
    t49 = *((unsigned int *)t10);
    t50 = (t48 | t49);
    t51 = (~(t50));
    t52 = (t47 & t51);
    if (t52 != 0)
        goto LAB361;

LAB358:    if (t50 != 0)
        goto LAB360;

LAB359:    *((unsigned int *)t30) = 1;

LAB361:    t12 = (t0 + 5304);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    t15 = (t0 + 4984);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    memset(t66, 0, 8);
    t18 = (t66 + 4);
    t19 = (t17 + 4);
    t53 = *((unsigned int *)t17);
    t54 = (t53 >> 7);
    t55 = (t54 & 1);
    *((unsigned int *)t66) = t55;
    t56 = *((unsigned int *)t19);
    t57 = (t56 >> 7);
    t58 = (t57 & 1);
    *((unsigned int *)t18) = t58;
    t20 = ((char*)((ng4)));
    t21 = ((char*)((ng64)));
    t22 = (t0 + 7312);
    t23 = (t0 + 848);
    t24 = xsi_create_subprogram_invocation(t22, 0, t0, t23, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t23, t24);
    t26 = (t0 + 5784);
    xsi_vlogvar_assign_value(t26, t4, 0, 0, 8);
    t27 = (t0 + 5944);
    xsi_vlogvar_assign_value(t27, t30, 0, 0, 1);
    t28 = (t0 + 6104);
    xsi_vlogvar_assign_value(t28, t14, 0, 0, 1);
    t29 = (t0 + 6264);
    xsi_vlogvar_assign_value(t29, t66, 0, 0, 1);
    t36 = (t0 + 6424);
    xsi_vlogvar_assign_value(t36, t20, 0, 0, 1);
    t37 = (t0 + 6584);
    xsi_vlogvar_assign_value(t37, t21, 0, 0, 256);

LAB364:    t38 = (t0 + 7408);
    t39 = *((char **)t38);
    t40 = (t39 + 80U);
    t41 = *((char **)t40);
    t42 = (t41 + 272U);
    t43 = *((char **)t42);
    t44 = (t43 + 0U);
    t45 = *((char **)t44);
    t25 = ((int  (*)(char *, char *))t45)(t0, t39);

LAB366:    if (t25 != 0)
        goto LAB367;

LAB362:    t39 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t39);

LAB363:    t67 = (t0 + 7408);
    t68 = *((char **)t67);
    t67 = (t0 + 848);
    t85 = (t0 + 7312);
    t86 = 0;
    xsi_delete_subprogram_invocation(t67, t68, t0, t85, t86);
    xsi_set_current_line(222, ng0);
    t2 = (t0 + 4184);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3544);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 8);
    xsi_set_current_line(222, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB368;
    goto LAB1;

LAB339:    t49 = *((unsigned int *)t66);
    t50 = *((unsigned int *)t11);
    *((unsigned int *)t66) = (t49 | t50);
    t12 = (t30 + 4);
    t13 = (t8 + 4);
    t51 = *((unsigned int *)t30);
    t52 = (~(t51));
    t53 = *((unsigned int *)t12);
    t54 = (~(t53));
    t55 = *((unsigned int *)t8);
    t56 = (~(t55));
    t57 = *((unsigned int *)t13);
    t58 = (~(t57));
    t25 = (t52 & t54);
    t59 = (t56 & t58);
    t60 = (~(t25));
    t61 = (~(t59));
    t62 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t62 & t60);
    t63 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t63 & t61);
    t64 = *((unsigned int *)t66);
    *((unsigned int *)t66) = (t64 & t60);
    t65 = *((unsigned int *)t66);
    *((unsigned int *)t66) = (t65 & t61);
    goto LAB341;

LAB342:    *((unsigned int *)t66) = 1;
    goto LAB345;

LAB344:    t7 = (t66 + 4);
    *((unsigned int *)t66) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB345;

LAB346:    t9 = ((char*)((ng4)));
    goto LAB347;

LAB348:    t10 = (t0 + 3384);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t13 = ((char*)((ng38)));
    t14 = (t0 + 4184);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    memset(t70, 0, 8);
    xsi_vlog_signed_minus(t70, 32, t13, 32, t16, 32);
    memset(t71, 0, 8);
    xsi_vlog_unsigned_rshift(t71, 8, t12, 8, t70, 32);
    t17 = ((char*)((ng7)));
    t53 = *((unsigned int *)t71);
    t54 = *((unsigned int *)t17);
    t55 = (t53 & t54);
    *((unsigned int *)t72) = t55;
    t18 = (t71 + 4);
    t19 = (t17 + 4);
    t20 = (t72 + 4);
    t56 = *((unsigned int *)t18);
    t57 = *((unsigned int *)t19);
    t58 = (t56 | t57);
    *((unsigned int *)t20) = t58;
    t60 = *((unsigned int *)t20);
    t61 = (t60 != 0);
    if (t61 == 1)
        goto LAB355;

LAB356:
LAB357:    goto LAB349;

LAB350:    xsi_vlog_unsigned_bit_combine(t30, 8, t9, 8, t72, 8);
    goto LAB354;

LAB352:    memcpy(t30, t9, 8);
    goto LAB354;

LAB355:    t62 = *((unsigned int *)t72);
    t63 = *((unsigned int *)t20);
    *((unsigned int *)t72) = (t62 | t63);
    t21 = (t71 + 4);
    t22 = (t17 + 4);
    t64 = *((unsigned int *)t71);
    t65 = (~(t64));
    t73 = *((unsigned int *)t21);
    t74 = (~(t73));
    t75 = *((unsigned int *)t17);
    t76 = (~(t75));
    t77 = *((unsigned int *)t22);
    t78 = (~(t77));
    t25 = (t65 & t74);
    t59 = (t76 & t78);
    t79 = (~(t25));
    t80 = (~(t59));
    t81 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t81 & t79);
    t82 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t82 & t80);
    t83 = *((unsigned int *)t72);
    *((unsigned int *)t72) = (t83 & t79);
    t84 = *((unsigned int *)t72);
    *((unsigned int *)t72) = (t84 & t80);
    goto LAB357;

LAB360:    t11 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB361;

LAB365:;
LAB367:    t38 = (t0 + 7504U);
    *((char **)t38) = &&LAB364;
    goto LAB1;

LAB368:    xsi_set_current_line(223, ng0);

LAB369:    xsi_set_current_line(224, ng0);
    t2 = (t0 + 3384);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4184);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t30, 0, 8);
    xsi_vlog_unsigned_rshift(t30, 8, t4, 8, t7, 32);
    t8 = ((char*)((ng3)));
    t31 = *((unsigned int *)t30);
    t32 = *((unsigned int *)t8);
    t33 = (t31 & t32);
    *((unsigned int *)t66) = t33;
    t9 = (t30 + 4);
    t10 = (t8 + 4);
    t11 = (t66 + 4);
    t34 = *((unsigned int *)t9);
    t35 = *((unsigned int *)t10);
    t46 = (t34 | t35);
    *((unsigned int *)t11) = t46;
    t47 = *((unsigned int *)t11);
    t48 = (t47 != 0);
    if (t48 == 1)
        goto LAB370;

LAB371:
LAB372:    t14 = (t0 + 4984);
    xsi_vlogvar_assign_value(t14, t66, 0, 0, 8);
    xsi_set_current_line(225, ng0);
    t2 = (t0 + 4184);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng5)));
    memset(t69, 0, 8);
    xsi_vlog_signed_equal(t69, 32, t4, 32, t5, 32);
    memset(t66, 0, 8);
    t6 = (t69 + 4);
    t31 = *((unsigned int *)t6);
    t32 = (~(t31));
    t33 = *((unsigned int *)t69);
    t34 = (t33 & t32);
    t35 = (t34 & 1U);
    if (t35 != 0)
        goto LAB373;

LAB374:    if (*((unsigned int *)t6) != 0)
        goto LAB375;

LAB376:    t8 = (t66 + 4);
    t46 = *((unsigned int *)t66);
    t47 = *((unsigned int *)t8);
    t48 = (t46 || t47);
    if (t48 > 0)
        goto LAB377;

LAB378:    t49 = *((unsigned int *)t66);
    t50 = (~(t49));
    t51 = *((unsigned int *)t8);
    t52 = (t50 || t51);
    if (t52 > 0)
        goto LAB379;

LAB380:    if (*((unsigned int *)t8) > 0)
        goto LAB381;

LAB382:    if (*((unsigned int *)t66) > 0)
        goto LAB383;

LAB384:    memcpy(t30, t72, 8);

LAB385:    t23 = (t0 + 5304);
    xsi_vlogvar_assign_value(t23, t30, 0, 0, 1);
    xsi_set_current_line(226, ng0);
    t2 = ((char*)((ng43)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(227, ng0);
    t2 = (t0 + 4984);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4984);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = ((char*)((ng5)));
    memset(t30, 0, 8);
    t9 = (t7 + 4);
    t10 = (t8 + 4);
    t31 = *((unsigned int *)t7);
    t32 = *((unsigned int *)t8);
    t33 = (t31 ^ t32);
    t34 = *((unsigned int *)t9);
    t35 = *((unsigned int *)t10);
    t46 = (t34 ^ t35);
    t47 = (t33 | t46);
    t48 = *((unsigned int *)t9);
    t49 = *((unsigned int *)t10);
    t50 = (t48 | t49);
    t51 = (~(t50));
    t52 = (t47 & t51);
    if (t52 != 0)
        goto LAB392;

LAB389:    if (t50 != 0)
        goto LAB391;

LAB390:    *((unsigned int *)t30) = 1;

LAB392:    t12 = (t0 + 5304);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    t15 = (t0 + 4984);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    memset(t66, 0, 8);
    t18 = (t66 + 4);
    t19 = (t17 + 4);
    t53 = *((unsigned int *)t17);
    t54 = (t53 >> 7);
    t55 = (t54 & 1);
    *((unsigned int *)t66) = t55;
    t56 = *((unsigned int *)t19);
    t57 = (t56 >> 7);
    t58 = (t57 & 1);
    *((unsigned int *)t18) = t58;
    t20 = ((char*)((ng4)));
    t21 = ((char*)((ng65)));
    t22 = (t0 + 7312);
    t23 = (t0 + 848);
    t24 = xsi_create_subprogram_invocation(t22, 0, t0, t23, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t23, t24);
    t26 = (t0 + 5784);
    xsi_vlogvar_assign_value(t26, t4, 0, 0, 8);
    t27 = (t0 + 5944);
    xsi_vlogvar_assign_value(t27, t30, 0, 0, 1);
    t28 = (t0 + 6104);
    xsi_vlogvar_assign_value(t28, t14, 0, 0, 1);
    t29 = (t0 + 6264);
    xsi_vlogvar_assign_value(t29, t66, 0, 0, 1);
    t36 = (t0 + 6424);
    xsi_vlogvar_assign_value(t36, t20, 0, 0, 1);
    t37 = (t0 + 6584);
    xsi_vlogvar_assign_value(t37, t21, 0, 0, 256);

LAB395:    t38 = (t0 + 7408);
    t39 = *((char **)t38);
    t40 = (t39 + 80U);
    t41 = *((char **)t40);
    t42 = (t41 + 272U);
    t43 = *((char **)t42);
    t44 = (t43 + 0U);
    t45 = *((char **)t44);
    t25 = ((int  (*)(char *, char *))t45)(t0, t39);

LAB397:    if (t25 != 0)
        goto LAB398;

LAB393:    t39 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t39);

LAB394:    t67 = (t0 + 7408);
    t68 = *((char **)t67);
    t67 = (t0 + 848);
    t85 = (t0 + 7312);
    t86 = 0;
    xsi_delete_subprogram_invocation(t67, t68, t0, t85, t86);
    xsi_set_current_line(229, ng0);
    t2 = (t0 + 4184);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3544);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 8);
    xsi_set_current_line(229, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB399;
    goto LAB1;

LAB370:    t49 = *((unsigned int *)t66);
    t50 = *((unsigned int *)t11);
    *((unsigned int *)t66) = (t49 | t50);
    t12 = (t30 + 4);
    t13 = (t8 + 4);
    t51 = *((unsigned int *)t30);
    t52 = (~(t51));
    t53 = *((unsigned int *)t12);
    t54 = (~(t53));
    t55 = *((unsigned int *)t8);
    t56 = (~(t55));
    t57 = *((unsigned int *)t13);
    t58 = (~(t57));
    t25 = (t52 & t54);
    t59 = (t56 & t58);
    t60 = (~(t25));
    t61 = (~(t59));
    t62 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t62 & t60);
    t63 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t63 & t61);
    t64 = *((unsigned int *)t66);
    *((unsigned int *)t66) = (t64 & t60);
    t65 = *((unsigned int *)t66);
    *((unsigned int *)t66) = (t65 & t61);
    goto LAB372;

LAB373:    *((unsigned int *)t66) = 1;
    goto LAB376;

LAB375:    t7 = (t66 + 4);
    *((unsigned int *)t66) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB376;

LAB377:    t9 = ((char*)((ng4)));
    goto LAB378;

LAB379:    t10 = (t0 + 3384);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t13 = (t0 + 4184);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    t16 = ((char*)((ng1)));
    memset(t70, 0, 8);
    xsi_vlog_signed_minus(t70, 32, t15, 32, t16, 32);
    memset(t71, 0, 8);
    xsi_vlog_unsigned_rshift(t71, 8, t12, 8, t70, 32);
    t17 = ((char*)((ng7)));
    t53 = *((unsigned int *)t71);
    t54 = *((unsigned int *)t17);
    t55 = (t53 & t54);
    *((unsigned int *)t72) = t55;
    t18 = (t71 + 4);
    t19 = (t17 + 4);
    t20 = (t72 + 4);
    t56 = *((unsigned int *)t18);
    t57 = *((unsigned int *)t19);
    t58 = (t56 | t57);
    *((unsigned int *)t20) = t58;
    t60 = *((unsigned int *)t20);
    t61 = (t60 != 0);
    if (t61 == 1)
        goto LAB386;

LAB387:
LAB388:    goto LAB380;

LAB381:    xsi_vlog_unsigned_bit_combine(t30, 8, t9, 8, t72, 8);
    goto LAB385;

LAB383:    memcpy(t30, t9, 8);
    goto LAB385;

LAB386:    t62 = *((unsigned int *)t72);
    t63 = *((unsigned int *)t20);
    *((unsigned int *)t72) = (t62 | t63);
    t21 = (t71 + 4);
    t22 = (t17 + 4);
    t64 = *((unsigned int *)t71);
    t65 = (~(t64));
    t73 = *((unsigned int *)t21);
    t74 = (~(t73));
    t75 = *((unsigned int *)t17);
    t76 = (~(t75));
    t77 = *((unsigned int *)t22);
    t78 = (~(t77));
    t25 = (t65 & t74);
    t59 = (t76 & t78);
    t79 = (~(t25));
    t80 = (~(t59));
    t81 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t81 & t79);
    t82 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t82 & t80);
    t83 = *((unsigned int *)t72);
    *((unsigned int *)t72) = (t83 & t79);
    t84 = *((unsigned int *)t72);
    *((unsigned int *)t72) = (t84 & t80);
    goto LAB388;

LAB391:    t11 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB392;

LAB396:;
LAB398:    t38 = (t0 + 7504U);
    *((char **)t38) = &&LAB395;
    goto LAB1;

LAB399:    xsi_set_current_line(230, ng0);

LAB400:    xsi_set_current_line(231, ng0);
    t2 = (t0 + 4184);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng5)));
    memset(t30, 0, 8);
    xsi_vlog_signed_equal(t30, 32, t4, 32, t5, 32);
    t6 = (t30 + 4);
    t31 = *((unsigned int *)t6);
    t32 = (~(t31));
    t33 = *((unsigned int *)t30);
    t34 = (t33 & t32);
    t35 = (t34 != 0);
    if (t35 > 0)
        goto LAB401;

LAB402:    xsi_set_current_line(232, ng0);
    t2 = (t0 + 3384);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4184);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t30, 0, 8);
    xsi_vlog_unsigned_lshift(t30, 8, t4, 8, t7, 32);
    t8 = (t0 + 3384);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = ((char*)((ng38)));
    t12 = (t0 + 4184);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    memset(t66, 0, 8);
    xsi_vlog_signed_minus(t66, 32, t11, 32, t14, 32);
    memset(t69, 0, 8);
    xsi_vlog_unsigned_rshift(t69, 8, t10, 8, t66, 32);
    t31 = *((unsigned int *)t30);
    t32 = *((unsigned int *)t69);
    t33 = (t31 | t32);
    *((unsigned int *)t70) = t33;
    t15 = (t30 + 4);
    t16 = (t69 + 4);
    t17 = (t70 + 4);
    t34 = *((unsigned int *)t15);
    t35 = *((unsigned int *)t16);
    t46 = (t34 | t35);
    *((unsigned int *)t17) = t46;
    t47 = *((unsigned int *)t17);
    t48 = (t47 != 0);
    if (t48 == 1)
        goto LAB404;

LAB405:
LAB406:    t20 = ((char*)((ng3)));
    t62 = *((unsigned int *)t70);
    t63 = *((unsigned int *)t20);
    t64 = (t62 & t63);
    *((unsigned int *)t71) = t64;
    t21 = (t70 + 4);
    t22 = (t20 + 4);
    t23 = (t71 + 4);
    t65 = *((unsigned int *)t21);
    t73 = *((unsigned int *)t22);
    t74 = (t65 | t73);
    *((unsigned int *)t23) = t74;
    t75 = *((unsigned int *)t23);
    t76 = (t75 != 0);
    if (t76 == 1)
        goto LAB407;

LAB408:
LAB409:    t27 = (t0 + 4984);
    xsi_vlogvar_assign_value(t27, t71, 0, 0, 8);

LAB403:    xsi_set_current_line(233, ng0);
    t2 = ((char*)((ng47)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(234, ng0);
    t2 = (t0 + 4984);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4984);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = ((char*)((ng5)));
    memset(t30, 0, 8);
    t9 = (t7 + 4);
    t10 = (t8 + 4);
    t31 = *((unsigned int *)t7);
    t32 = *((unsigned int *)t8);
    t33 = (t31 ^ t32);
    t34 = *((unsigned int *)t9);
    t35 = *((unsigned int *)t10);
    t46 = (t34 ^ t35);
    t47 = (t33 | t46);
    t48 = *((unsigned int *)t9);
    t49 = *((unsigned int *)t10);
    t50 = (t48 | t49);
    t51 = (~(t50));
    t52 = (t47 & t51);
    if (t52 != 0)
        goto LAB413;

LAB410:    if (t50 != 0)
        goto LAB412;

LAB411:    *((unsigned int *)t30) = 1;

LAB413:    t12 = ((char*)((ng4)));
    t13 = (t0 + 4984);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    memset(t66, 0, 8);
    t16 = (t66 + 4);
    t17 = (t15 + 4);
    t53 = *((unsigned int *)t15);
    t54 = (t53 >> 7);
    t55 = (t54 & 1);
    *((unsigned int *)t66) = t55;
    t56 = *((unsigned int *)t17);
    t57 = (t56 >> 7);
    t58 = (t57 & 1);
    *((unsigned int *)t16) = t58;
    t18 = ((char*)((ng4)));
    t19 = ((char*)((ng66)));
    t20 = (t0 + 7312);
    t21 = (t0 + 848);
    t22 = xsi_create_subprogram_invocation(t20, 0, t0, t21, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t21, t22);
    t23 = (t0 + 5784);
    xsi_vlogvar_assign_value(t23, t4, 0, 0, 8);
    t24 = (t0 + 5944);
    xsi_vlogvar_assign_value(t24, t30, 0, 0, 1);
    t26 = (t0 + 6104);
    xsi_vlogvar_assign_value(t26, t12, 0, 0, 1);
    t27 = (t0 + 6264);
    xsi_vlogvar_assign_value(t27, t66, 0, 0, 1);
    t28 = (t0 + 6424);
    xsi_vlogvar_assign_value(t28, t18, 0, 0, 1);
    t29 = (t0 + 6584);
    xsi_vlogvar_assign_value(t29, t19, 0, 0, 256);

LAB416:    t36 = (t0 + 7408);
    t37 = *((char **)t36);
    t38 = (t37 + 80U);
    t39 = *((char **)t38);
    t40 = (t39 + 272U);
    t41 = *((char **)t40);
    t42 = (t41 + 0U);
    t43 = *((char **)t42);
    t25 = ((int  (*)(char *, char *))t43)(t0, t37);

LAB418:    if (t25 != 0)
        goto LAB419;

LAB414:    t37 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t37);

LAB415:    t44 = (t0 + 7408);
    t45 = *((char **)t44);
    t44 = (t0 + 848);
    t67 = (t0 + 7312);
    t68 = 0;
    xsi_delete_subprogram_invocation(t44, t45, t0, t67, t68);
    xsi_set_current_line(236, ng0);
    t2 = (t0 + 4184);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng63)));
    t31 = *((unsigned int *)t4);
    t32 = *((unsigned int *)t5);
    t33 = (t31 | t32);
    *((unsigned int *)t30) = t33;
    t6 = (t4 + 4);
    t7 = (t5 + 4);
    t8 = (t30 + 4);
    t34 = *((unsigned int *)t6);
    t35 = *((unsigned int *)t7);
    t46 = (t34 | t35);
    *((unsigned int *)t8) = t46;
    t47 = *((unsigned int *)t8);
    t48 = (t47 != 0);
    if (t48 == 1)
        goto LAB420;

LAB421:
LAB422:    t11 = (t0 + 3544);
    xsi_vlogvar_assign_value(t11, t30, 0, 0, 8);
    xsi_set_current_line(236, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB423;
    goto LAB1;

LAB401:    xsi_set_current_line(231, ng0);
    t7 = (t0 + 3384);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t0 + 4984);
    xsi_vlogvar_assign_value(t10, t9, 0, 0, 8);
    goto LAB403;

LAB404:    t49 = *((unsigned int *)t70);
    t50 = *((unsigned int *)t17);
    *((unsigned int *)t70) = (t49 | t50);
    t18 = (t30 + 4);
    t19 = (t69 + 4);
    t51 = *((unsigned int *)t18);
    t52 = (~(t51));
    t53 = *((unsigned int *)t30);
    t25 = (t53 & t52);
    t54 = *((unsigned int *)t19);
    t55 = (~(t54));
    t56 = *((unsigned int *)t69);
    t59 = (t56 & t55);
    t57 = (~(t25));
    t58 = (~(t59));
    t60 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t60 & t57);
    t61 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t61 & t58);
    goto LAB406;

LAB407:    t77 = *((unsigned int *)t71);
    t78 = *((unsigned int *)t23);
    *((unsigned int *)t71) = (t77 | t78);
    t24 = (t70 + 4);
    t26 = (t20 + 4);
    t79 = *((unsigned int *)t70);
    t80 = (~(t79));
    t81 = *((unsigned int *)t24);
    t82 = (~(t81));
    t83 = *((unsigned int *)t20);
    t84 = (~(t83));
    t87 = *((unsigned int *)t26);
    t88 = (~(t87));
    t89 = (t80 & t82);
    t90 = (t84 & t88);
    t91 = (~(t89));
    t92 = (~(t90));
    t93 = *((unsigned int *)t23);
    *((unsigned int *)t23) = (t93 & t91);
    t94 = *((unsigned int *)t23);
    *((unsigned int *)t23) = (t94 & t92);
    t95 = *((unsigned int *)t71);
    *((unsigned int *)t71) = (t95 & t91);
    t96 = *((unsigned int *)t71);
    *((unsigned int *)t71) = (t96 & t92);
    goto LAB409;

LAB412:    t11 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB413;

LAB417:;
LAB419:    t36 = (t0 + 7504U);
    *((char **)t36) = &&LAB416;
    goto LAB1;

LAB420:    t49 = *((unsigned int *)t30);
    t50 = *((unsigned int *)t8);
    *((unsigned int *)t30) = (t49 | t50);
    t9 = (t4 + 4);
    t10 = (t5 + 4);
    t51 = *((unsigned int *)t9);
    t52 = (~(t51));
    t53 = *((unsigned int *)t4);
    t25 = (t53 & t52);
    t54 = *((unsigned int *)t10);
    t55 = (~(t54));
    t56 = *((unsigned int *)t5);
    t59 = (t56 & t55);
    t57 = (~(t25));
    t58 = (~(t59));
    t60 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t60 & t57);
    t61 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t61 & t58);
    goto LAB422;

LAB423:    xsi_set_current_line(237, ng0);

LAB424:    xsi_set_current_line(238, ng0);
    t2 = (t0 + 4184);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng5)));
    memset(t30, 0, 8);
    xsi_vlog_signed_equal(t30, 32, t4, 32, t5, 32);
    t6 = (t30 + 4);
    t31 = *((unsigned int *)t6);
    t32 = (~(t31));
    t33 = *((unsigned int *)t30);
    t34 = (t33 & t32);
    t35 = (t34 != 0);
    if (t35 > 0)
        goto LAB425;

LAB426:    xsi_set_current_line(239, ng0);
    t2 = (t0 + 3384);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4184);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t30, 0, 8);
    xsi_vlog_unsigned_rshift(t30, 8, t4, 8, t7, 32);
    t8 = (t0 + 3384);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = ((char*)((ng38)));
    t12 = (t0 + 4184);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    memset(t66, 0, 8);
    xsi_vlog_signed_minus(t66, 32, t11, 32, t14, 32);
    memset(t69, 0, 8);
    xsi_vlog_unsigned_lshift(t69, 8, t10, 8, t66, 32);
    t31 = *((unsigned int *)t30);
    t32 = *((unsigned int *)t69);
    t33 = (t31 | t32);
    *((unsigned int *)t70) = t33;
    t15 = (t30 + 4);
    t16 = (t69 + 4);
    t17 = (t70 + 4);
    t34 = *((unsigned int *)t15);
    t35 = *((unsigned int *)t16);
    t46 = (t34 | t35);
    *((unsigned int *)t17) = t46;
    t47 = *((unsigned int *)t17);
    t48 = (t47 != 0);
    if (t48 == 1)
        goto LAB428;

LAB429:
LAB430:    t20 = ((char*)((ng3)));
    t62 = *((unsigned int *)t70);
    t63 = *((unsigned int *)t20);
    t64 = (t62 & t63);
    *((unsigned int *)t71) = t64;
    t21 = (t70 + 4);
    t22 = (t20 + 4);
    t23 = (t71 + 4);
    t65 = *((unsigned int *)t21);
    t73 = *((unsigned int *)t22);
    t74 = (t65 | t73);
    *((unsigned int *)t23) = t74;
    t75 = *((unsigned int *)t23);
    t76 = (t75 != 0);
    if (t76 == 1)
        goto LAB431;

LAB432:
LAB433:    t27 = (t0 + 4984);
    xsi_vlogvar_assign_value(t27, t71, 0, 0, 8);

LAB427:    xsi_set_current_line(240, ng0);
    t2 = ((char*)((ng49)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(241, ng0);
    t2 = (t0 + 4984);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4984);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = ((char*)((ng5)));
    memset(t30, 0, 8);
    t9 = (t7 + 4);
    t10 = (t8 + 4);
    t31 = *((unsigned int *)t7);
    t32 = *((unsigned int *)t8);
    t33 = (t31 ^ t32);
    t34 = *((unsigned int *)t9);
    t35 = *((unsigned int *)t10);
    t46 = (t34 ^ t35);
    t47 = (t33 | t46);
    t48 = *((unsigned int *)t9);
    t49 = *((unsigned int *)t10);
    t50 = (t48 | t49);
    t51 = (~(t50));
    t52 = (t47 & t51);
    if (t52 != 0)
        goto LAB437;

LAB434:    if (t50 != 0)
        goto LAB436;

LAB435:    *((unsigned int *)t30) = 1;

LAB437:    t12 = ((char*)((ng4)));
    t13 = (t0 + 4984);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    memset(t66, 0, 8);
    t16 = (t66 + 4);
    t17 = (t15 + 4);
    t53 = *((unsigned int *)t15);
    t54 = (t53 >> 7);
    t55 = (t54 & 1);
    *((unsigned int *)t66) = t55;
    t56 = *((unsigned int *)t17);
    t57 = (t56 >> 7);
    t58 = (t57 & 1);
    *((unsigned int *)t16) = t58;
    t18 = ((char*)((ng4)));
    t19 = ((char*)((ng67)));
    t20 = (t0 + 7312);
    t21 = (t0 + 848);
    t22 = xsi_create_subprogram_invocation(t20, 0, t0, t21, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t21, t22);
    t23 = (t0 + 5784);
    xsi_vlogvar_assign_value(t23, t4, 0, 0, 8);
    t24 = (t0 + 5944);
    xsi_vlogvar_assign_value(t24, t30, 0, 0, 1);
    t26 = (t0 + 6104);
    xsi_vlogvar_assign_value(t26, t12, 0, 0, 1);
    t27 = (t0 + 6264);
    xsi_vlogvar_assign_value(t27, t66, 0, 0, 1);
    t28 = (t0 + 6424);
    xsi_vlogvar_assign_value(t28, t18, 0, 0, 1);
    t29 = (t0 + 6584);
    xsi_vlogvar_assign_value(t29, t19, 0, 0, 256);

LAB440:    t36 = (t0 + 7408);
    t37 = *((char **)t36);
    t38 = (t37 + 80U);
    t39 = *((char **)t38);
    t40 = (t39 + 272U);
    t41 = *((char **)t40);
    t42 = (t41 + 0U);
    t43 = *((char **)t42);
    t25 = ((int  (*)(char *, char *))t43)(t0, t37);

LAB442:    if (t25 != 0)
        goto LAB443;

LAB438:    t37 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t37);

LAB439:    t44 = (t0 + 7408);
    t45 = *((char **)t44);
    t44 = (t0 + 848);
    t67 = (t0 + 7312);
    t68 = 0;
    xsi_delete_subprogram_invocation(t44, t45, t0, t67, t68);
    xsi_set_current_line(206, ng0);
    t2 = (t0 + 4184);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t30, 0, 8);
    xsi_vlog_signed_add(t30, 32, t4, 32, t5, 32);
    t6 = (t0 + 4184);
    xsi_vlogvar_assign_value(t6, t30, 0, 0, 32);
    goto LAB299;

LAB425:    xsi_set_current_line(238, ng0);
    t7 = (t0 + 3384);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t0 + 4984);
    xsi_vlogvar_assign_value(t10, t9, 0, 0, 8);
    goto LAB427;

LAB428:    t49 = *((unsigned int *)t70);
    t50 = *((unsigned int *)t17);
    *((unsigned int *)t70) = (t49 | t50);
    t18 = (t30 + 4);
    t19 = (t69 + 4);
    t51 = *((unsigned int *)t18);
    t52 = (~(t51));
    t53 = *((unsigned int *)t30);
    t25 = (t53 & t52);
    t54 = *((unsigned int *)t19);
    t55 = (~(t54));
    t56 = *((unsigned int *)t69);
    t59 = (t56 & t55);
    t57 = (~(t25));
    t58 = (~(t59));
    t60 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t60 & t57);
    t61 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t61 & t58);
    goto LAB430;

LAB431:    t77 = *((unsigned int *)t71);
    t78 = *((unsigned int *)t23);
    *((unsigned int *)t71) = (t77 | t78);
    t24 = (t70 + 4);
    t26 = (t20 + 4);
    t79 = *((unsigned int *)t70);
    t80 = (~(t79));
    t81 = *((unsigned int *)t24);
    t82 = (~(t81));
    t83 = *((unsigned int *)t20);
    t84 = (~(t83));
    t87 = *((unsigned int *)t26);
    t88 = (~(t87));
    t89 = (t80 & t82);
    t90 = (t84 & t88);
    t91 = (~(t89));
    t92 = (~(t90));
    t93 = *((unsigned int *)t23);
    *((unsigned int *)t23) = (t93 & t91);
    t94 = *((unsigned int *)t23);
    *((unsigned int *)t23) = (t94 & t92);
    t95 = *((unsigned int *)t71);
    *((unsigned int *)t71) = (t95 & t91);
    t96 = *((unsigned int *)t71);
    *((unsigned int *)t71) = (t96 & t92);
    goto LAB433;

LAB436:    t11 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB437;

LAB441:;
LAB443:    t36 = (t0 + 7504U);
    *((char **)t36) = &&LAB440;
    goto LAB1;

LAB445:    xsi_set_current_line(247, ng0);

LAB447:    xsi_set_current_line(248, ng0);
    t7 = ((char*)((ng17)));
    t8 = (t0 + 3384);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 8);
    xsi_set_current_line(248, ng0);
    t2 = ((char*)((ng70)));
    t3 = (t0 + 3544);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(248, ng0);
    t2 = (t0 + 4184);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3704);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 4);
    xsi_set_current_line(248, ng0);
    t2 = (t0 + 7312);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB448;
    goto LAB1;

LAB448:    xsi_set_current_line(249, ng0);
    t2 = ((char*)((ng4)));
    t3 = ((char*)((ng4)));
    t4 = ((char*)((ng4)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng4)));
    t7 = ((char*)((ng71)));
    t8 = (t0 + 7312);
    t9 = (t0 + 848);
    t10 = xsi_create_subprogram_invocation(t8, 0, t0, t9, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t9, t10);
    t11 = (t0 + 5784);
    xsi_vlogvar_assign_value(t11, t2, 0, 0, 8);
    t12 = (t0 + 5944);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 1);
    t13 = (t0 + 6104);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 1);
    t14 = (t0 + 6264);
    xsi_vlogvar_assign_value(t14, t5, 0, 0, 1);
    t15 = (t0 + 6424);
    xsi_vlogvar_assign_value(t15, t6, 0, 0, 1);
    t16 = (t0 + 6584);
    xsi_vlogvar_assign_value(t16, t7, 0, 0, 256);

LAB451:    t17 = (t0 + 7408);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = ((int  (*)(char *, char *))t24)(t0, t18);

LAB453:    if (t25 != 0)
        goto LAB454;

LAB449:    t18 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t18);

LAB450:    t26 = (t0 + 7408);
    t27 = *((char **)t26);
    t26 = (t0 + 848);
    t28 = (t0 + 7312);
    t29 = 0;
    xsi_delete_subprogram_invocation(t26, t27, t0, t28, t29);
    xsi_set_current_line(247, ng0);
    t2 = (t0 + 4184);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t30, 0, 8);
    xsi_vlog_signed_add(t30, 32, t4, 32, t5, 32);
    t6 = (t0 + 4184);
    xsi_vlogvar_assign_value(t6, t30, 0, 0, 32);
    goto LAB444;

LAB452:;
LAB454:    t17 = (t0 + 7504U);
    *((char **)t17) = &&LAB451;
    goto LAB1;

LAB455:    xsi_set_current_line(254, ng0);
    t7 = (t0 + 4344);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    xsi_vlogfile_write(1, 0, 0, ng72, 2, t0, (char)119, t9, 32);
    goto LAB457;

}


extern void work_m_00000000003685501527_1761905097_init()
{
	static char *pe[] = {(void *)Initial_95_0};
	static char *se[] = {(void *)sp_check,(void *)sp_ref_add,(void *)sp_ref_sub};
	xsi_register_didat("work_m_00000000003685501527_1761905097", "isim/tb_s8_alu_isim_beh.exe.sim/work/m_00000000003685501527_1761905097.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
