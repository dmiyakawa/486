/*
 *    pmseg.c  ( List 5-19 )
 *    Copyright (C) Teruhisa Kamachi and ASCII Corp. 1994
 *    All rights reserved.
 *
 *    ���̃t�@�C���́w�͂��߂ēǂ�486�x�i�A�X�L�[�o�ŋǁj�Ɍf�ڂ���
 *    �v���O�����̈ꕔ�ł��B�v���O�������e�◘�p���@�ɂ��Ă͖{����
 *    �L�q���Q�Ƃ��Ă��������B
 */

/*
 *    List 5-19  �v���e�N�g���[�h�Ɉڍs������v���O����pmseg
 *               [pmseg.c  1/1] (page 160)
 */

#include <stdio.h>
#include <dos.h>
#include "proto.h"
#include "printseg.h"

void main()
{
    int i, val;

    SetUpGDT();

    printf("Before ***********\n");
    for (i=8;i<=0x30;i+=8)
        PrintGDTSegDesc(i);

    val = 0;
    printf("val:%d\n",val);

    RealToProto();
    val = 1;
    ProtoToReal();

    printf("After  ***********\n");
    printf("val:%d\n",val);

    for (i=8;i<=0x30;i+=8)
        PrintGDTSegDesc(i);
}
