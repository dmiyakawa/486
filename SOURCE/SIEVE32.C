/*
 *    sieve32.c  ( List 5-29 )
 *    Copyright (C) Teruhisa Kamachi and ASCII Corp. 1994
 *    All rights reserved.
 *
 *    ���̃t�@�C���́w�͂��߂ēǂ�486�x�i�A�X�L�[�o�ŋǁj�Ɍf�ڂ���
 *    �v���O�����̈ꕔ�ł��B�v���O�������e�◘�p���@�ɂ��Ă͖{����
 *    �L�q���Q�Ƃ��Ă��������B
 */

/*
 *    List 5-29  sieve32�̃��C���v���O����
 *               [sieve32.c  1/1] (page 186)
 */

#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include "proto.h"

#define NUM 100000
#define TBLADR 0x100000

void __far sieve(unsigned short sel, unsigned long num);
int __far isprime(unsigned short sel, unsigned long num);

void main(int argc, char *argv[])
{
    unsigned long i,m,snum;
    unsigned short sel;
    void (__far *sieveFunc)();
    int  (__far *isprimeFunc)();

    if (argc>1)
        m = atol(argv[1]);
    else
        m = NUM;

    SetUpGDT();
    EnableA20();

    sel = AllocSel();
    SetSegDesc(sel, SegToLinier(seg.cs, 0),
                                0xffff, TypeCode, Code386, 0);
    sieveFunc = (void (__far *)() )
          (((unsigned long)sel<<16) + (unsigned short) sieve);
    isprimeFunc = (int (__far *)() )
        (((unsigned long)sel<<16) + (unsigned short) isprime);

    sel = AllocSel();
    SetSegDesc(sel, TBLADR, (m>>12)+1, TypeData, BigSeg, 0);

    RealToProto();

    sieveFunc(sel, m);
    snum=0;
    for (i=2;i<=m;i++) {
        if (isprimeFunc(sel, i)) {
            snum++;
            ProtoToReal();
            printf("%lu ", i);
            RealToProto();
        }
    }

    ProtoToReal();

    putchar('\n');
    printf("%lu prime numbers in 2..%lu\n",snum,m);
}
