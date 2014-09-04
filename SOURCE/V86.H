/*
 *    v86.h  ( List 11-2 )
 *    Copyright (C) Teruhisa Kamachi and ASCII Corp. 1994
 *    All rights reserved.
 *
 *    ���̃t�@�C���́w�͂��߂ēǂ�486�x�i�A�X�L�[�o�ŋǁj�Ɍf�ڂ���
 *    �v���O�����̈ꕔ�ł��B�v���O�������e�◘�p���@�ɂ��Ă͖{����
 *    �L�q���Q�Ƃ��Ă��������B
 */

/*
 *    List 11-2  �w�b�_�t�@�C��
 *               [v86.h  1/1] (page 394)
 */

typedef struct _TSS_IO {
    TSS tss;
    unsigned char iomap[8193];
} TSS_IO;

extern TSS_IO  v86tss;

void SetV86(void (*f)());
void RealToV86(void);
IntFunc v86int;
