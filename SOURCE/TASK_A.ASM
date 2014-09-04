;;
;;    task_a.asm  ( List 8-3, 8-4 )
;;    Copyright (C) Teruhisa Kamachi and ASCII Corp. 1994
;;    All rights reserved.
;;
;;    ���̃t�@�C���́w�͂��߂ēǂ�486�x�i�A�X�L�[�o�ŋǁj�Ɍf�ڂ���
;;    �v���O�����̈ꕔ�ł��B�v���O�������e�◘�p���@�ɂ��Ă͖{����
;;    �L�q���Q�Ƃ��Ă��������B
;;

;;
;;   List 8-3  �Z�O�����g�ԃW�����v���߂ɂ����
;;                     �^�X�N��؂�ւ���SwitchTask()�֐�
;;             [task_a.asm  1/2] (page 276)
;;

.386p
_TEXT   segment byte public use16 'CODE'
        assume  cs:_TEXT

;;************************************************************
;; void SwitchTask(unsigned short sel);
public   _SwitchTask
_SwitchTask     proc near
                push    bp
                mov     bp,sp
                jmp     dword ptr [bp+2]
                ;
                pop     bp
                ret
_SwitchTask     endp

;;
;;   List 8-4  TR���W�X�^�ɃZ���N�^�l��ݒ肷��ltr()�֐�
;;             [task_a.asm  2/2] (page 279)
;;
;;************************************************************
;; void ltr(unsigned short sel);

public          _ltr
_ltr            proc    near
                push    bp
                mov     bp,sp
                ltr     word ptr [bp+4]
                pop     bp
                ret
_ltr            endp

_TEXT           ends
                end
