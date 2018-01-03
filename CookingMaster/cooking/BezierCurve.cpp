#include "Usingheaders.h"

POS BezierCurve::MoveBezier2(Note& note) {
	bez.x = (1 - note.move.time)*(1 - note.move.time)*note.move.start.x + 2 * (1 - note.move.time)*note.move.time*note.move.dir.x + note.move.time*note.move.time*note.move.end.x;
	bez.y = (1 - note.move.time)*(1 - note.move.time)*note.move.start.y + 2 * (1 - note.move.time)*note.move.time*note.move.dir.y + note.move.time*note.move.time*note.move.end.y;

	return bez;
	//	note->pos.x = bez.x;
	//	note->pos.y = bez.y;
	//	note->time += 1 / note->speed;


}

//void BezierCurve2(Note::Note* note, Note::POS start, Note::POS dir, Note::POS end) {  //音符のポインタ、開始点、方向点、終点(2次限定)
//	Note::POS bez;  //ある時点での曲線上の点の座標
//
//	bez.x = (1 - note->time)*(1 - note->time)*start.x + 2 * (1 - note->time)*note->time*dir.x + note->time*note->time*end.x;
//	bez.y = (1 - note->time)*(1 - note->time)*start.y + 2 * (1 - note->time)*note->time*dir.y + note->time*note->time*end.y;
//	
//	note->pos.x = bez.x;
//	note->pos.y = bez.y;
//	note->time += 1 / note->speed;
//
//	if (note->time >= 1){
//		Note::Initialize();
//	}
//}