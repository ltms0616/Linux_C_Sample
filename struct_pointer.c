#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct infoA{
   unsigned char flagA;
   unsigned int valA;
};

struct infoB{
   unsigned char flagB;
   unsigned int valB;
};

struct infoALL{
   struct infoA *info_a;
   struct infoB info_b;
};

int change_infoB(struct infoB *info_b)
{
    info_b->flagB=50;
    info_b->valB=100;
    return 0;
}

int reset_infoB(struct infoALL *m_info)
{
    memset(&m_info->info_b, '\0', sizeof(struct infoB));
    return 0;
}

int change_info(struct infoALL *m_info)
{
   /*struct infoA *info_a = c_info->info_a;
   struct infoB *info_b = c_info->info_b;*/
   m_info->info_a->flagA = 5;
   m_info->info_a->valA = 10;
   change_infoB(&m_info->info_b);
   return 0;
}

int main(int argc, char **argv)
{
    struct infoALL *m_info;
    struct infoALL n_info;    
    m_info = (struct infoALL *)malloc(sizeof(struct infoALL));
    m_info->info_a = (struct infoA *)malloc(sizeof(struct infoA));
    n_info.info_a = (struct infoA *)malloc(sizeof(struct infoA));
    m_info->info_a->flagA=1;
    m_info->info_a->valA=2;
    m_info->info_b.flagB=3;
    m_info->info_b.valB=4;
    printf("m_info infoA %d %d\n", m_info->info_a->flagA, m_info->info_a->valA);
    printf("m_info infoB %d %d\n", m_info->info_b.flagB, m_info->info_b.valB);
    change_info(m_info);
    printf("after change, m_info infoA %d %d\n", m_info->info_a->flagA, m_info->info_a->valA);
    printf("after change, m_info infoB %d %d\n", m_info->info_b.flagB, m_info->info_b.valB);
    
    n_info.info_a->flagA=6;
    n_info.info_a->valA=7;
    n_info.info_b.flagB=8;
    n_info.info_b.valB=9;

    printf("n_info infoA %d %d\n", n_info.info_a->flagA, n_info.info_a->valA);
    printf("n_info infoB %d %d\n", n_info.info_b.flagB, n_info.info_b.valB);
    change_info(&n_info);   
    printf("after change, n_info infoA %d %d\n", n_info.info_a->flagA, n_info.info_a->valA);
    printf("after change, n_info infoB %d %d\n", n_info.info_b.flagB, n_info.info_b.valB);
 
    change_infoB(&n_info.info_b);
    printf("after change_infoB, infoB %d %d\n", n_info.info_b.flagB, n_info.info_b.valB);
    
    reset_infoB(&n_info);  
    printf("after reset_infoB, infoB %d %d\n", n_info.info_b.flagB, n_info.info_b.valB);

    return 0;

}

