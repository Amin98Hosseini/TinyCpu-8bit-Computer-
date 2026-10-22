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

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    work_m_00000000002419405455_3065262152_init();
    work_m_00000000000667220840_4192366798_init();
    work_m_00000000003389586295_0470940157_init();
    work_m_00000000003153171484_1231655528_init();
    work_m_00000000004183545097_1414652718_init();
    work_m_00000000001821712436_2311570106_init();
    work_m_00000000001483178833_0040532021_init();
    work_m_00000000003659861854_0562528781_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000003659861854_0562528781");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
