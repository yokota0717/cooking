#include "BezierCurve.h"
#include "Note.h"


void BezierCurve2(Note::Note* note, Note::POS start, Note::POS dir, Note::POS end) {  //�����̃|�C���^�A�J�n�_�A�����_�A�I�_(2������)
	Note::POS bez;  //���鎞�_�ł̋Ȑ���̓_�̍��W

	bez.x = (1 - note->time)*(1 - note->time)*start.x + 2 * (1 - note->time)*note->time*dir.x + note->time*note->time*end.x;
	bez.y = (1 - note->time)*(1 - note->time)*start.y + 2 * (1 - note->time)*note->time*dir.y + note->time*note->time*end.y;
	
	note->pos.x = bez.x;
	note->pos.y = bez.y;
	note->time += 1 / note->speed;

	if (note->time >= 1) {
		Note::Initialize();
	}
}